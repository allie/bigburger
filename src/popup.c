#include "popup.h"
#include "img.h"
#include "graphics.h"
#include "assets.h"

static Popup popup;

void popup_init() {
  popup.visible = FALSE;
  popup.popup_type = 0;
  popup.timer = 0;
  popup.opacity = 0;
}

void popup_show(int popup_type, float y, double anim_duration, double visible_duration) {
  popup.popup_type = popup_type;
  popup.visible = TRUE;
  popup.timer = visible_duration;
  popup.y = y;
  easing_init(popup.anim.y, &popup.y, anim_duration, popup.y + 5, popup.y, easing_linear_f);
  easing_init(popup.anim.opacity, &popup.opacity, anim_duration, 0, 255, easing_linear_i);
  easing_play(popup.anim.y);
  easing_play(popup.anim.opacity);
}

void popup_update(double dt) {
  if (!popup.visible) {
    return;
  }

  if (popup.timer != POPUP_VISIBLE_FOREVER) {
    popup.timer -= dt;
  }

  if (popup.timer <= 0 && popup.timer != POPUP_VISIBLE_FOREVER) {
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
  if (!popup.visible && popup.popup_type != POPUP_TITLE) {
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

    case POPUP_TITLE:
      img_draw(
        title_screen_logo_img,
        SCREEN_W / 2 - title_screen_logo_img.width / 2 + 5,
        popup.y
      );
      break;

    default:
      break;
  }
}
