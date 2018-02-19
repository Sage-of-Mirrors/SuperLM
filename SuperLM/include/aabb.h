#pragma once
#include <vector>
#include "glm\vec3.hpp"
#include "bstream.h"

namespace SuperLM {
	class AABB {
	private:
		glm::vec3* m_minimum;
		glm::vec3* m_maximum;
		float m_sphereRadius;
	public:
		AABB() {}
		~AABB();
		glm::vec3* GetMaximumBounds();
		glm::vec3* GetMinimumBounds();
		float GetSphereRadius();

		int CalculateBoundsFromGeometry(std::vector<glm::vec3*>& geom);
		int LoadBoundsFromBinSceneNode(bStream& reader);
	};
}