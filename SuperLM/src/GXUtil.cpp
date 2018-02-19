#include <cstdint>
#ifdef __linux__
	#include "SuperLM/include/GXUtil.h"
#endif
#ifdef _WIN32
	#include "SuperLM\include\GXUtil.h"
#endif

namespace GX {
	bool isValidPrimitive(uint8_t t){
		switch(t){
			case GXPrimitiveType::Triangles:
				return true;
			case GXPrimitiveType::TriangleStrip:
				return true;
			case GXPrimitiveType::TriangleFan:
				return true;
			case GXPrimitiveType::Quads:
				return true;
		}
	}
}