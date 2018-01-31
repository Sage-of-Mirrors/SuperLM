#pragma once
#include "Scenegraph.h"

namespace SuperLM {
	class Model {
	private:
		Scenegraph* m_scenegraph;
	public:
		Model() { }
		int Load(bStream& reader);
	};
}