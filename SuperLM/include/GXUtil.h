namespace GX {
	enum class GXAttributes : int {
		PositionMatrixIndex,
		Tex0MatrixIndex,
		Tex1MatrixIndex,
		Tex2MatrixIndex,
		Tex3MatrixIndex,
		Tex4MatrixIndex,
		Tex5MatrixIndex,
		Tex6MatrixIndex,
		Tex7MatrixIndex,
		Position,
		Normal,
		Color0,
		Color1,
		Tex0,
		Tex1,
		Tex2,
		Tex3,
		Tex4,
		Tex5,
		Tex6,
		Tex7,
		PositionMatrixArray,
		NormalMatrixArray,
		TextureMatrixArray,
		LitMatrixArray,
		NormalBinormalTangent,
		NullAttr = 0xFF
	};

	enum GXPrimitiveType {
		Points = 0xB8,
		Lines = 0xA8,
		LineStrip = 0xB0,
		Triangles = 0x90,
		TriangleStrip = 0x98,
		TriangleFan = 0xA0,
		Quads = 0x80,
		None = 0x00
	};

	bool isValidPrimitive(uint8_t t);
}