Lights1 lettuce_Material_f3d_lights = gdSPDefLights1(
	0x12, 0x73, 0x1B,
	0x25, 0xE7, 0x37, 0x28, 0x28, 0x28);

Vtx lettuce_Cube_mesh_vtx_0[20] = {
	{{{-200, 2, 60},0, {-16, 1008},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{-120, 42, 160},0, {1008, 1008},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{-120, 42, -160},0, {1008, -16},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{-200, 2, -60},0, {-16, -16},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{-120, 42, -160},0, {1008, -16},{0x39, 0x72, 0x0, 0xFF}}},
	{{{-120, 42, 160},0, {1008, 1008},{0x39, 0x72, 0x0, 0xFF}}},
	{{{-40, 2, 200},0, {1008, 1008},{0x39, 0x72, 0x0, 0xFF}}},
	{{{-40, 2, -200},0, {1008, -16},{0x39, 0x72, 0x0, 0xFF}}},
	{{{-40, 2, -200},0, {1008, -16},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{-40, 2, 200},0, {1008, 1008},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{40, 42, 200},0, {1008, 1008},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{40, 42, -200},0, {1008, -16},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{40, 42, -200},0, {1008, -16},{0x39, 0x72, 0x0, 0xFF}}},
	{{{40, 42, 200},0, {1008, 1008},{0x39, 0x72, 0x0, 0xFF}}},
	{{{120, 2, 160},0, {1008, 1008},{0x39, 0x72, 0x0, 0xFF}}},
	{{{120, 2, -160},0, {1008, -16},{0x39, 0x72, 0x0, 0xFF}}},
	{{{120, 2, -160},0, {1008, -16},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{120, 2, 160},0, {1008, 1008},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{200, 42, 60},0, {1008, 1008},{0xC7, 0x72, 0x0, 0xFF}}},
	{{{200, 42, -80},0, {1008, -16},{0xC7, 0x72, 0x0, 0xFF}}},
};

Gfx lettuce_Cube_mesh_tri_0[] = {
	gsSPVertex(lettuce_Cube_mesh_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(lettuce_Cube_mesh_vtx_0 + 16, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_lettuce_Material_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(lettuce_Material_f3d_lights),
	gsSPEndDisplayList(),
};


Gfx lettuce_Cube_mesh[] = {
	gsSPDisplayList(mat_lettuce_Material_f3d),
	gsSPDisplayList(lettuce_Cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



