#pragma once
#include <vector>
#ifdef __linux__
	#include "SuperLM/include/model.h"
#endif
#ifdef _WIN32
	#include "SuperLM\include\model.h"
#endif

namespace SuperLM {
	int Model::Load(bStream& reader) {
		reader.seek(0x11300);
		m_scenegraph = new Scenegraph(reader);
		return 0;
	}
}