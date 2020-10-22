#include "popup.h"
#include "img.h"
#include "graphics.h"

#include "textures/great.h"
#include "textures/good.h"
#include "textures/miss.h"

static Popup popup;

void popup_init() {
  popup.visible = FALSE;
  popup.popup_type = 0;
  popup.timer = 0;
  popup.y = POPUP_START_Y;
  popup.opacity = 0;
  easing_init(popup.anim.y, &popup.y, POPUP_Y_ANIM_DURATION, POPUP_START_Y, POPUP_END_Y, easing_linear_f);
  easing_init(popup.anim.opacity, &popup.opacity, POPUP_FADE_ANIM_DURATION, 0, 255, easing_linear_i);
}

void popup_show(int popup_type) {
  popup.popup_type = popup_type;
  popup.visible = TRUE;
  popup.timer = POPUP_DURATION;
  easing_play(popup.anim.y);
  easing_play(popup.anim.opacity);
}

void popup_update(double dt) {
  if (!popup.visible) {
    return;
  }

  popup.timer -= dt;

  if (popup.timer <= 0) {
    popup.visible = FALSE;
  }

  if (popup.anim.y.playing) {
    easing_update(popup.anim.y, dt);
  }

  if (popup.anim.opacity.playing) {
    easing_update(popup.anim.opacity, dt);
  }
}

void popup_draw() {
  if (!popup.visible) {
    return;
  }

  img_set_colour(255, 255, 255, (u8)popup.opacity);

  switch (popup.popup_type) {
    case POPUP_GREAT:
      img_draw(great_img, SCREEN_W / 2 - great_img.width / 2, popup.y);
      break;

    case POPUP_GOOD:
      img_draw(good_img, SCREEN_W / 2 - good_img.width / 2, popup.y);
      break;

    case POPUP_MISS:
      img_draw(miss_img, SCREEN_W / 2 - miss_img.width / 2, popup.y);
      break;

    default:
      break;
  }
}