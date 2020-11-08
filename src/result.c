#include <nusys.h>
#include "result.h"
#include "part.h"
#include "img.h"
#include "camera.h"
#include "graphics.h"
#include "gamestate.h"
#include "number.h"
#include "popup.h"
#include "colour.h"
#include "easing.h"
#include "assets.h"

#define MAX_PARTS 1001

#define MIN_X -700
#define MAX_X 700

#define STACK_CENTRE 276
#define STACK_X_RANGE 30
#define STACK_MAX_ON_SCREEN 100

#define BLINK_PERIOD 1.5

extern NUContData controller[1];

// Nasty global variables from game.c
extern Part parts[MAX_PARTS];
extern u32 part_count;
extern u64 score;
extern Rgb bg_rgb;

double elapsed;
double blink_timer;
bool press_start_shown;

int current_part;

enum {
  STEP_GAME_OVER = 0,
  STEP_STACK,
  STEP_FADE,
  STEP_PRESS_START
};

int current_step;

float current_speed;
int current_opacity;
float current_x;

struct {
  EasingF x;
  EasingI opacity;
  EasingF speed;
} current_part_anim;

struct {
  EasingI opacity_anim;
  int opacity;
} hud_fade;

static float world_to_stack_x(float x) {
  return ((x + MAX_X) / (MAX_X * 2)) * STACK_X_RANGE - (STACK_X_RANGE / 2) + STACK_CENTRE;
}

// Initialize animations for the current part in the stack
static void animate_current_part() {
  float target_x = world_to_stack_x(parts[current_part].obj.pos.x);
  float init_x = parts[current_part].obj.pos.x <= 0 ? STACK_CENTRE - STACK_X_RANGE : STACK_CENTRE + STACK_X_RANGE;

  // Init and start x animation
  easing_init(current_part_anim.x, &current_x, 0.025, init_x, target_x, easing_linear_f);
  easing_play(current_part_anim.x);

  // Init and start opacity animation
  easing_init(current_part_anim.opacity, &current_opacity, 0.025, 0, 255, easing_linear_i);
  easing_play(current_part_anim.opacity);
}

static void draw_stack() {
  float x, y;
  int i;

  for (i = 0; i <= current_part - 1; i++) {
    if (i == current_part - 1) {
      img_set_colour(255, 255, 255, current_opacity);
      x = current_x;
    } else {
      img_set_colour(255, 255, 255, 255);
      x = world_to_stack_x(parts[i].obj.pos.x);
    }

    x -= 12;
    y = current_part < STACK_MAX_ON_SCREEN ?
      (SCREEN_H - SAFE_AREA_V - 12) - (i * 2) :
      (SCREEN_H - SAFE_AREA_V - 12) - (i * 2) + ((current_part - STACK_MAX_ON_SCREEN) * 2);

    if (y >= SCREEN_H) {
      continue;
    }

    switch (parts[i].ingredient) {
      case MEAT:
        img_draw(meat_small_img, x, y);
        break;
      case CHEESE:
        img_draw(cheese_small_img, x, y);
        break;
      case LETTUCE:
        img_draw(lettuce_small_img, x, y);
        break;
      case TOMATO:
        img_draw(tomato_small_img, x, y);
        break;
      case ONION:
        img_draw(onion_small_img, x, y);
        break;
      default:
        break;
    }
  }
}

void result_init() {
  int i;

  elapsed = 0;
  current_part = 0;
  current_step = STEP_GAME_OVER;
  blink_timer = 0;
  press_start_shown = FALSE;

  current_speed = 0.2;
  current_opacity = 0;
  current_x = STACK_CENTRE;

  current_part_anim.x.playing = FALSE;
  current_part_anim.opacity.playing = FALSE;
  current_part_anim.speed.playing = FALSE;

  hud_fade.opacity = 0;
  hud_fade.opacity_anim.playing = FALSE;

  popup_init();
  popup_show(POPUP_GAMEOVER, SAFE_AREA_V, POPUP_GAMEOVER_ANIM_DURATION, POPUP_VISIBLE_FOREVER);
}

void result_update(double dt) {
  if (controller[0].trigger & START_BUTTON) {
    gamestate_replace(GAMESTATE_GAME, TRUE, TRUE);
  }

  elapsed += dt;

  popup_update(dt);

  if (current_step == STEP_GAME_OVER && elapsed > POPUP_GAMEOVER_ANIM_DURATION) {
    if (part_count > 0) {
      // If there are any parts, stack them on the side of the screen
      current_step = STEP_STACK;
      animate_current_part();
    } else {
      // Otherwise, idk, make fun of the player or something
      current_step = STEP_FADE;
      easing_init(hud_fade.opacity_anim, &hud_fade.opacity, 0.5, 0, 255, easing_linear_i);
      easing_play(hud_fade.opacity_anim);
    }
  }

  if (current_step == STEP_STACK) {
    if (current_part_anim.opacity.playing) {
      easing_update(current_part_anim.opacity, dt);
    }
    if (current_part_anim.x.playing) {
      easing_update(current_part_anim.x, dt);

      // If the x animation ends on this update, advance to the next part
      if (!current_part_anim.x.playing) {    
        current_part++;
    
        // If the last part has been placed, move on to the next step
        if (current_part >= part_count) {
          current_step = STEP_FADE;
          easing_init(hud_fade.opacity_anim, &hud_fade.opacity, 0.5, 0, 255, easing_linear_i);
          easing_play(hud_fade.opacity_anim);
        } else {
          // Otherwise, animate in the next part
          animate_current_part();
        }
      }
    }
  }

  if (current_step == STEP_FADE && hud_fade.opacity_anim.playing) {
    easing_update(hud_fade.opacity_anim, dt);

    if (!hud_fade.opacity_anim.playing) {
      current_step = STEP_PRESS_START;
      press_start_shown = TRUE;
      blink_timer = BLINK_PERIOD;
    }
  }

  if (current_step == STEP_PRESS_START) {
    if (press_start_shown) {
      blink_timer -= dt;
      if (blink_timer <= 0) {
        press_start_shown = FALSE;
      }
    } else {
      blink_timer += dt;
      if (blink_timer >= BLINK_PERIOD) {
        press_start_shown = TRUE;
      }
    }
  }
}

void result_draw() {
  int i;

  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(bg_rgb.r, bg_rgb.g, bg_rgb.b);

  // TODO: don't do this
  camera_look(mvpp);

  // Draw 2d stuff
  img_start();
  img_set_colour(255, 255, 255, 255);

  // Draw "GAME OVER!" text
  if (current_step > STEP_GAME_OVER) {
    img_draw(game_over_img, SAFE_AREA_H, SAFE_AREA_V);
  }

  if (current_step > STEP_GAME_OVER) {
    draw_stack();
  }

  if (current_step == STEP_PRESS_START && press_start_shown) {
    img_draw(try_again_img, SAFE_AREA_H, SCREEN_H - SAFE_AREA_V - try_again_img.height);
  }

  if (current_step > STEP_STACK) {
    img_set_colour(255, 255, 255, hud_fade.opacity);

    img_draw(score_img, SAFE_AREA_H, 82);
    // Draw score value
    number_draw_0_padded(score, 1, SAFE_AREA_H, 94);

    // Draw "RANK" text
    img_draw(rank_img, SAFE_AREA_H, 128);
    // Draw rank value
    img_draw(rank_sss_img, SAFE_AREA_H, 140);

    // Draw "INGREDIENTS" text
    img_draw(ingredients_img, 157, 163);
    // Draw part count value
    number_draw_0_padded(part_count, 1, 157, 142);
  }

  // Draw popup images
  popup_draw();

  img_end();

  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  nuGfxTaskStart(
    &glist[task_num][0],
    (s32)(glistp - glist[task_num]) * sizeof(Gfx),
    NU_GFX_UCODE_F3DEX,
    NU_SC_SWAPBUFFER
  );

  task_num++;
  task_num %= MAX_TASKS;
}

void result_destroy() {

}
