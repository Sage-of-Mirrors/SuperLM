#ifdef __linux__
	#include "SuperLM/include/Scenegraph.h"
#endif
#ifdef _WIN32
	#include "SuperLM\include\Scenegraph.h"
#endif

namespace SuperLM {

	SceneNode::SceneNode(bStream& reader) {
		m_origParentIndex = reader.readInt16();
		int firstChildIndex = reader.readInt16();
		m_origNextSiblingIndex = reader.readInt16();
		m_origPreviousSiblingIndex = reader.readInt16();
		char* discard = reader.readBytes(0x84); // skip the rest of the data for now
	}

	void SceneNode::SetNodeHierarchy(std::vector<SceneNode*>& flatList) {
		if (m_origParentIndex != -1)
		{
			m_parent = flatList[m_origParentIndex];
			m_parent->AddChild(this);
		}

		if (m_origNextSiblingIndex != -1)
			m_nextSibling = flatList[m_origNextSiblingIndex];
		if (m_origPreviousSiblingIndex != -1)
			m_previousSibling = flatList[m_origPreviousSiblingIndex];
	}

	void SceneNode::AddChild(SceneNode* child) {
		m_children.push_back(child);
	}

	void SceneNode::OutputHierarchyRecursive(int tabNo) {
		for (int i = 0; i < tabNo; i++)
			std::cout << "\t";
		std::cout << m_origParentIndex << "\n";

		for (int i = 0; i < m_children.size(); i++)
		{
			m_children[i]->OutputHierarchyRecursive(tabNo + 1);
		}

		//if (m_nextSibling)
			//m_nextSibling->OutputHierarchyRecursive(tabNo);
	}

	Scenegraph::Scenegraph(bStream& reader) {
		std::fstream& baseStream = reader.getStream();
		long startPos = baseStream.tellg();

		// The first node in the list doesn't usually have geometry associated with it, but its ShapeIndexOffset field is still
		// set anyway. It's set to the beginning of the ShapeIndex section, so we can skip ahead, read the first node's ShapeIndexOffset,
		// and divide it by the node size in bytes (0x8C, or 140 in decimal) to get the number of nodes to read.
		reader.seek(startPos + 0x50); // Jump to first node's ShapeIndexOffset field
		int shapeIndicesOffset = reader.readInt32();
		m_nodeCount = shapeIndicesOffset / 0x8C; // Divide by 0x8C, or 140 dec, to get the number of nodes to read
		reader.seek(startPos); // Return to the first node's beginning

		for (int i = 0; i < m_nodeCount; i++)
		{
			m_flatHierarchy.push_back(new SceneNode(reader));
		}

		for (int i = 0; i < m_nodeCount; i++)
		{
			m_flatHierarchy[i]->SetNodeHierarchy(m_flatHierarchy);
		}

		m_rootNode = m_flatHierarchy[0];
		m_rootNode->OutputHierarchyRecursive(0);
	}
}