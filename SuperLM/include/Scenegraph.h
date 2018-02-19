#pragma once
#include <vector>

#ifdef __linux__
	#include "SuperLM/include/bstream.h"
#endif
#ifdef _WIN32
	#include "bstream.h"
    #include "aabb.h"
	#include "glm\vec3.hpp"
	#include "glm\gtc\quaternion.hpp"
#endif

namespace SuperLM {
	class SceneNode {
	private:
		int m_origParentIndex;
		int m_origPreviousSiblingIndex;
		int m_origNextSiblingIndex;

		SceneNode* m_parent;
		SceneNode* m_previousSibling;
		SceneNode* m_nextSibling;

		std::vector<SceneNode*> m_children;

		glm::vec3* m_scale;
		glm::quat* m_rotation;
		glm::vec3* m_translation;
		AABB* m_boundingBox;

		int m_shapeCount;

		// These are initialized to 32 slots just to make sure there's enough room
		// Only the first m_shapeCount entries will ever be used
		int m_materialList[32];
		int m_shapeList[32];

	public:
		SceneNode(bStream& reader, long listStartOffset);
		void SetNodeHierarchy(std::vector<SceneNode*>& flatList);
		void AddChild(SceneNode* child);
		void OutputHierarchyRecursive(int tabNo);

		void RenderRecursive();
		void WriteToStream(bStream* writer);
		//void SerializeToSceneRecursive(aiNode* parent);
	};

	class Scenegraph {
	private:
		int m_nodeCount;
		SceneNode* m_rootNode;
		std::vector<SceneNode*> m_flatHierarchy;

	public:
		Scenegraph(bStream& reader);
		//Scenegraph(aiScene* scene);

		void WriteToStream(bStream* writer);
		//void WriteToScene(aiScene* scene);

		int GetNodeCount() { return m_nodeCount; }
		SceneNode* GetRootNode() { return m_rootNode; }
		std::vector<SceneNode*> GetFlatHierarchy() { return m_flatHierarchy; }
	};
}