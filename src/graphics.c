#include <nusys.h>
#include "graphics.h"
#include "object.h"

MVP mvp[MAX_TASKS];
Gfx glist[MAX_TASKS][GLIST_LENGTH];
Gfx* glistp;
u32 task_num = 0;

static Vp viewport = {
  SCREEN_W * 2, SCREEN_H * 2, G_MAXZ / 2, 0,
  SCREEN_W * 2, SCREEN_H * 2, G_MAXZ / 2, 0
};

static Gfx rsp_init_dl[] = {
  gsSPViewport(&viewport),
  gsSPClearGeometryMode(0xFFFFFFFF),
  gsSPTexture(0, 0, 0, 0, G_OFF),
  gsSPEndDisplayList(),
};

static Gfx rdp_init_dl[] = {
  gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_W, SCREEN_H),
  gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
  gsDPSetColorDither(G_CD_DISABLE),
  gsDPSetAlphaDither(G_AD_DISABLE),
  gsDPSetTextureFilter(G_TF_AVERAGE),
  gsDPSetTextureConvert(G_TC_FILT),
  gsDPSetTexturePersp(G_TP_PERSP),
  gsDPPipeSync(),
  gsSPEndDisplayList(),
};

// Initialize RCP
void graphics_init_RCP() {
  gSPSegment(glistp++, 0, 0);
  gSPDisplayList(glistp++, rsp_init_dl);
  gSPDisplayList(glistp++, rdp_init_dl);
}

void graphics_clear(u8 r, u8 g, u8 b) {
  // Clear Z buffer
  gDPPipeSync(glistp++);
  gDPSetCycleType(glistp++, G_CYC_FILL);
  gDPSetDepthImage(glistp++, nuGfxZBuffer);
  gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_W, nuGfxZBuffer);
  gDPSetFillColor(glistp++, (GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0)));
  gDPFillRectangle(glistp++, 0, 0, SCREEN_W - 1, SCREEN_H - 1);

  // Clear frame buffer
  gDPPipeSync(glistp++);
  gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_W, nuGfxCfb_ptr);
  gDPSetFillColor(glistp++, (GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1)));
  gDPFillRectangle(glistp++, 0, 0, SCREEN_W - 1, SCREEN_H - 1);
  gDPPipeSync(glistp++);
}

void graphics_start_object(Object* object, bool xlu) {
  gDPSetCycleType(glistp++, G_CYC_1CYCLE);
  gSPSetGeometryMode(glistp++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING | G_CULL_BACK | G_ZBUFFER);
  gDPSetCombineMode(glistp++, G_CC_SHADE, G_CC_SHADE);
  gDPSetRenderMode(
    glistp++,
    xlu ? G_RM_AA_ZB_XLU_SURF : G_RM_AA_ZB_OPA_SURF,
    xlu ? G_RM_AA_ZB_XLU_SURF2 : G_RM_AA_ZB_OPA_SURF2
  );
  guPosition(
    &object->transform,
    vec3f_unpack(object->rot),
    object->scale,
    vec3f_unpack(object->pos)
  );
  gSPMatrix(glistp++, &object->transform, G_MTX_MODELVIEW | G_MTX_PUSH | G_MTX_MUL);
}

void graphics_start_textured_object(Object* object, bool xlu) {
  gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
  gSPTexture(glistp++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
  gDPSetTextureLOD (glistp++, G_TL_TILE);
  gDPSetCycleType(glistp++, G_CYC_1CYCLE);
  gSPSetGeometryMode(glistp++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING | G_CULL_BACK | G_ZBUFFER);
  gDPSetRenderMode(
    glistp++,
    xlu ? G_RM_AA_ZB_XLU_DECAL : G_RM_AA_ZB_OPA_SURF,
    xlu ? G_RM_AA_ZB_XLU_DECAL2 : G_RM_AA_ZB_OPA_SURF2
  );
  guPosition(
    &object->transform,
    vec3f_unpack(object->rot),
    object->scale,
    vec3f_unpack(object->pos)
  );
  gSPMatrix(glistp++, &object->transform, G_MTX_MODELVIEW | G_MTX_PUSH | G_MTX_MUL);
}

void graphics_end_object() {
  gDPPipeSync(glistp++);
  gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
}
