Lights1 cheese_Material_f3d_lights = gdSPDefLights1(
	0x73, 0x5F, 0x0,
	0xE7, 0xBF, 0x0, 0x28, 0x28, 0x28);

Vtx cheese_Cube_mesh_vtx_0[20] = {
	{{{-160, 0, 160},0, {368, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-160, 20, 160},0, {624, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-160, 20, -160},0, {624, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-160, 0, -160},0, {368, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-160, 0, -160},0, {368, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-160, 20, -160},0, {624, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{160, 20, -160},0, {624, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{160, 0, -160},0, {368, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{160, 0, -160},0, {368, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{160, 20, -160},0, {624, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{160, 20, 160},0, {624, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{160, 0, 160},0, {368, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{160, 0, 160},0, {368, 240},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{160, 20, 160},0, {624, 240},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-160, 20, 160},0, {624, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-160, 0, 160},0, {368, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{160, 20, -160},0, {624, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-160, 20, -160},0, {880, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-160, 20, 160},0, {880, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{160, 20, 160},0, {624, 240},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx cheese_Cube_mesh_tri_0[] = {
	gsSPVertex(cheese_Cube_mesh_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(cheese_Cube_mesh_vtx_0 + 16, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_cheese_Material_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(cheese_Material_f3d_lights),
	gsSPEndDisplayList(),
};


Gfx cheese_Cube_mesh[] = {
	gsSPDisplayList(mat_cheese_Material_f3d),
	gsSPDisplayList(cheese_Cube_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



