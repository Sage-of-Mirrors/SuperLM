#include "SuperLM\include\model.h"

namespace SuperLM {
	int Model::Load(bStream& reader) {
		reader.seek(0x11300);
		m_scenegraph = new Scenegraph(reader);
		return 0;
	}
}