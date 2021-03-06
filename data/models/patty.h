Lights1 patty_Material_001_f3d_lights = gdSPDefLights1(
	0x33, 0x20, 0x10,
	0x66, 0x41, 0x21, 0x28, 0x28, 0x28);

Vtx patty_Cube_mesh_vtx_0[40] = {
	{{{140, 0, 140},0, {368, 240},{0x32, 0x0, 0x75, 0xFF}}},
	{{{140, 40, 140},0, {624, 240},{0x32, 0x0, 0x75, 0xFF}}},
	{{{0, 40, 200},0, {624, 112},{0x32, 0x0, 0x75, 0xFF}}},
	{{{0, 0, 200},0, {368, 112},{0x32, 0x0, 0x75, 0xFF}}},
	{{{140, 0, -140},0, {368, 496},{0x75, 0x0, 0xCE, 0xFF}}},
	{{{140, 40, -140},0, {624, 496},{0x75, 0x0, 0xCE, 0xFF}}},
	{{{200, 40, 0},0, {624, 368},{0x75, 0x0, 0xCE, 0xFF}}},
	{{{200, 0, 0},0, {368, 368},{0x75, 0x0, 0xCE, 0xFF}}},
	{{{0, 0, -200},0, {368, 624},{0x32, 0x0, 0x8B, 0xFF}}},
	{{{0, 40, -200},0, {624, 624},{0x32, 0x0, 0x8B, 0xFF}}},
	{{{140, 40, -140},0, {624, 496},{0x32, 0x0, 0x8B, 0xFF}}},
	{{{140, 0, -140},0, {368, 496},{0x32, 0x0, 0x8B, 0xFF}}},
	{{{-140, 0, -140},0, {368, 752},{0xCE, 0x0, 0x8B, 0xFF}}},
	{{{-140, 40, -140},0, {624, 752},{0xCE, 0x0, 0x8B, 0xFF}}},
	{{{0, 40, -200},0, {624, 624},{0xCE, 0x0, 0x8B, 0xFF}}},
	{{{0, 0, -200},0, {368, 624},{0xCE, 0x0, 0x8B, 0xFF}}},
	{{{140, 40, -140},0, {624, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 40, -200},0, {752, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-140, 40, -140},0, {880, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-140, 40, 140},0, {880, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-200, 40, 0},0, {880, 368},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{140, 40, 140},0, {624, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 40, 200},0, {752, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{200, 40, 0},0, {624, 368},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 200},0, {368, 112},{0xCE, 0x0, 0x75, 0xFF}}},
	{{{0, 40, 200},0, {624, 112},{0xCE, 0x0, 0x75, 0xFF}}},
	{{{-140, 40, 140},0, {624, -16},{0xCE, 0x0, 0x75, 0xFF}}},
	{{{-140, 0, 140},0, {368, -16},{0xCE, 0x0, 0x75, 0xFF}}},
	{{{200, 0, 0},0, {368, 368},{0x75, 0x0, 0x32, 0xFF}}},
	{{{200, 40, 0},0, {624, 368},{0x75, 0x0, 0x32, 0xFF}}},
	{{{140, 40, 140},0, {624, 240},{0x75, 0x0, 0x32, 0xFF}}},
	{{{140, 0, 140},0, {368, 240},{0x75, 0x0, 0x32, 0xFF}}},
	{{{-200, 0, 0},0, {368, 880},{0x8B, 0x0, 0xCE, 0xFF}}},
	{{{-200, 40, 0},0, {624, 880},{0x8B, 0x0, 0xCE, 0xFF}}},
	{{{-140, 40, -140},0, {624, 752},{0x8B, 0x0, 0xCE, 0xFF}}},
	{{{-140, 0, -140},0, {368, 752},{0x8B, 0x0, 0xCE, 0xFF}}},
	{{{-140, 40, 140},0, {624, 1008},{0x8B, 0x0, 0x32, 0xFF}}},
	{{{-200, 40, 0},0, {624, 880},{0x8B, 0x0, 0x32, 0xFF}}},
	{{{-200, 0, 0},0, {368, 880},{0x8B, 0x0, 0x32, 0xFF}}},
	{{{-140, 0, 140},0, {368, 1008},{0x8B, 0x0, 0x32, 0xFF}}},
};

Gfx patty_Cube_mesh_tri_0[] = {
	gsSPVertex(patty_Cube_mesh_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(patty_Cube_mesh_vtx_0 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(3, 5, 0, 0),
	gsSP1Triangle(3, 6, 5, 0),
	gsSP1Triangle(5, 7, 0, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(patty_Cube_mesh_vtx_0 + 32, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};


Gfx mat_patty_Material_001_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(patty_Material_001_f3d_lights),
	gsSPEndDisplayList(),
};


Gfx patty_Cube_mesh[] = {
	gsSPDisplayList(mat_patty_Material_001_f3d),
	gsSPDisplayList(patty_Cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



