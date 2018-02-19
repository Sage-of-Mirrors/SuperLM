#include "SuperLM\include\aabb.h"

namespace SuperLM {
	glm::vec3* AABB::GetMinimumBounds() {
		return m_minimum;
	}

	glm::vec3* AABB::GetMaximumBounds() {
		return m_maximum;
	}

	float AABB::GetSphereRadius() {
		return m_sphereRadius;
	}

	int AABB::LoadBoundsFromBinSceneNode(bStream& reader) {
		m_sphereRadius = reader.readFloat();
		m_minimum = new glm::vec3(reader.readFloat(), reader.readFloat(), reader.readFloat());
		m_maximum = new glm::vec3(reader.readFloat(), reader.readFloat(), reader.readFloat());

		return 0;
	}

	AABB::~AABB() {
		delete m_minimum;
		delete m_maximum;
	}
}