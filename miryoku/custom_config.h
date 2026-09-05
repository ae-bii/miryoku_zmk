// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Replace the Mouse layer (hold Tab) with an AeroSpace window-management layer.
//
// AeroSpace (nix-config: modules/darwin/aerospace.nix) binds everything to
// ctrl-alt (macOS Control+Option) plus arrows, digits and punctuation, so every
// key here sends that chord directly. The left hand keeps Miryoku's home-row
// mods, so holding Shift there turns the same key into the shifted variant:
//
//   Shift + focus      -> move window            (ctrl-alt-shift-arrow)
//   Shift + workspace  -> move window to ws      (ctrl-alt-shift-N)
//   Shift + resize     -> resize opposite axis   (ctrl-alt-shift-minus/equal)
//   Shift + layout     -> flatten workspace tree (ctrl-alt-shift-slash)
//
// Right hand, inner column to pinky:
//   top:    workspace 1  2  3  4  5
//   home:   fullscreen | focus left  down  up  right   (arrows match Nav layer)
//   bottom: floating   | shrink  grow  orientation  tiles/accordion
//   thumbs: -  balance-sizes  -

#define U_WM(key) &kp LC(LA(key))

#define MIRYOKU_LAYER_MOUSE \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_WM(N1),          U_WM(N2),          U_WM(N3),          U_WM(N4),          U_WM(N5),          \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              U_WM(RET),         U_WM(LEFT),        U_WM(DOWN),        U_WM(UP),          U_WM(RIGHT),       \
U_NA,              &kp RALT,          &u_to_U_SYM,       &u_to_U_MOUSE,     U_NA,              U_WM(DOT),         U_WM(MINUS),       U_WM(EQUAL),       U_WM(COMMA),       U_WM(SLASH),       \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_NU,              U_WM(N0),          U_NU,              U_NP,              U_NP

// Keep the layer id (U_MOUSE / &u_to_U_MOUSE) so the other layers still work;
// only the display label changes.
#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Window") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#define U_BASE   0
#define U_EXTRA  1
#define U_TAP    2
#define U_BUTTON 3
#define U_NAV    4
#define U_MOUSE  5
#define U_MEDIA  6
#define U_NUM    7
#define U_SYM    8
#define U_FUN    9
