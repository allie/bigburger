Lights1 tomato_Material_001_f3d_lights = gdSPDefLights1(
	0x77, 0x16, 0x13,
	0xEE, 0x2D, 0x27, 0x28, 0x28, 0x28);

Vtx tomato_Cube_mesh_vtx_0[32] = {
	{{{-123, 0, -123},0, {112, 496},{0xBA, 0xB0, 0xBA, 0xFF}}},
	{{{0, 0, -176},0, {240, 496},{0x0, 0xB1, 0x9D, 0xFF}}},
	{{{123, 0, -123},0, {368, 496},{0x46, 0xB0, 0xBA, 0xFF}}},
	{{{123, 0, 123},0, {368, 240},{0x46, 0xB0, 0x46, 0xFF}}},
	{{{176, 0, 0},0, {368, 368},{0x63, 0xB1, 0x0, 0xFF}}},
	{{{176, 18, 0},0, {624, 368},{0x63, 0x4F, 0x0, 0xFF}}},
	{{{123, 18, -123},0, {624, 496},{0x46, 0x50, 0xBA, 0xFF}}},
	{{{0, 0, -176},0, {368, 624},{0x0, 0xB1, 0x9D, 0xFF}}},
	{{{0, 18, -176},0, {624, 624},{0x0, 0x4F, 0x9D, 0xFF}}},
	{{{-123, 0, -123},0, {368, 752},{0xBA, 0xB0, 0xBA, 0xFF}}},
	{{{-123, 18, -123},0, {624, 752},{0xBA, 0x50, 0xBA, 0xFF}}},
	{{{-176, 0, 0},0, {368, 880},{0x9D, 0xB1, 0x0, 0xFF}}},
	{{{-176, 18, 0},0, {624, 880},{0x9D, 0x4F, 0x0, 0xFF}}},
	{{{-123, 18, 123},0, {624, 1008},{0xBA, 0x50, 0x46, 0xFF}}},
	{{{-123, 0, 123},0, {368, 1008},{0xBA, 0xB0, 0x46, 0xFF}}},
	{{{123, 18, 123},0, {624, 240},{0x46, 0x50, 0x46, 0xFF}}},
	{{{123, 0, 123},0, {368, 240},{0x46, 0xB0, 0x46, 0xFF}}},
	{{{123, 18, 123},0, {624, 240},{0x46, 0x50, 0x46, 0xFF}}},
	{{{0, 18, 176},0, {624, 112},{0x0, 0x4F, 0x63, 0xFF}}},
	{{{0, 0, 176},0, {368, 112},{0x0, 0xB1, 0x63, 0xFF}}},
	{{{-123, 18, 123},0, {624, -16},{0xBA, 0x50, 0x46, 0xFF}}},
	{{{-123, 0, 123},0, {368, -16},{0xBA, 0xB0, 0x46, 0xFF}}},
	{{{-123, 18, 123},0, {880, 240},{0xBA, 0x50, 0x46, 0xFF}}},
	{{{123, 18, -123},0, {624, 496},{0x46, 0x50, 0xBA, 0xFF}}},
	{{{0, 18, 176},0, {752, 240},{0x0, 0x4F, 0x63, 0xFF}}},
	{{{-123, 18, -123},0, {880, 496},{0xBA, 0x50, 0xBA, 0xFF}}},
	{{{0, 18, -176},0, {752, 496},{0x0, 0x4F, 0x9D, 0xFF}}},
	{{{-176, 18, 0},0, {880, 368},{0x9D, 0x4F, 0x0, 0xFF}}},
	{{{0, 0, 176},0, {240, 240},{0x0, 0xB1, 0x63, 0xFF}}},
	{{{-123, 0, 123},0, {112, 240},{0xBA, 0xB0, 0x46, 0xFF}}},
	{{{-123, 0, -123},0, {112, 496},{0xBA, 0xB0, 0xBA, 0xFF}}},
	{{{-176, 0, 0},0, {112, 368},{0x9D, 0xB1, 0x0, 0xFF}}},
};

Gfx tomato_Cube_mesh_tri_0[] = {
	gsSPVertex(tomato_Cube_mesh_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(2, 5, 4, 0),
	gsSP1Triangle(2, 6, 5, 0),
	gsSP1Triangle(7, 6, 2, 0),
	gsSP1Triangle(7, 8, 6, 0),
	gsSP1Triangle(9, 8, 7, 0),
	gsSP1Triangle(9, 10, 8, 0),
	gsSP1Triangle(11, 10, 9, 0),
	gsSP1Triangle(11, 12, 10, 0),
	gsSP1Triangle(13, 12, 11, 0),
	gsSP1Triangle(13, 11, 14, 0),
	gsSP1Triangle(15, 5, 6, 0),
	gsSP1Triangle(4, 5, 15, 0),
	gsSP1Triangle(4, 15, 3, 0),
	gsSPVertex(tomato_Cube_mesh_vtx_0 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(3, 2, 4, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 1, 7, 0),
	gsSP1Triangle(6, 8, 1, 0),
	gsSP1Triangle(7, 9, 6, 0),
	gsSP1Triangle(7, 10, 9, 0),
	gsSP1Triangle(9, 11, 6, 0),
	gsSP1Triangle(0, 12, 13, 0),
	gsSP1Triangle(0, 13, 14, 0),
	gsSP1Triangle(13, 15, 14, 0),
	gsSPEndDisplayList(),
};


Gfx mat_tomato_Material_001_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(tomato_Material_001_f3d_lights),
	gsSPEndDisplayList(),
};


Gfx tomato_Cube_mesh[] = {
	gsSPDisplayList(mat_tomato_Material_001_f3d),
	gsSPDisplayList(tomato_Cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



