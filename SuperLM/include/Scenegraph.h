#pragma once
#include <vector>
#include "bstream.h"

namespace SuperLM {
	class SceneNode {
	private:
		SceneNode* m_parent;
		SceneNode* m_previousSibling;
		SceneNode* m_nextSibling;

		std::vector<SceneNode> m_children;

		//Vector3 m_scale;
		//Quaternion m_rotation;
		//Vector3 m_translation;
		//AABB m_boundingBox;

		int shapeCount;
		int* m_materialList;
		int* m_shapeList;

	public:
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
		Scenegraph(bStream* reader);
		//Scenegraph(aiScene* scene);

		void WriteToStream(bStream* writer);
		//void WriteToScene(aiScene* scene);

		int GetNodeCount() { return m_nodeCount; }
		SceneNode* GetRootNode() { return m_rootNode; }
		std::vector<SceneNode*> GetFlatHierarchy() { return m_flatHierarchy; }
	};
}