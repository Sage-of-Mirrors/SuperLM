#pragma once

#ifdef __linux__
	#include "SuperLM/include/Scenegraph.h"
#endif
#ifdef _WIN32
	#include "Scenegraph.h"
#endif

namespace SuperLM {
	class Model {
	private:
		Scenegraph* m_scenegraph;
	public:
		Model() { }
		int Load(bStream& reader);
	};
}