// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// ---------------------------------------------------------------------------
// Clipboard: Mac by default, runtime toggle to the generic variant
// ---------------------------------------------------------------------------
//
// The clipboard keys (undo/cut/copy/paste/redo on Nav and Button) compile to
// the macOS chords. A "Clip" flag layer, toggled from the Media layer (top row,
// inner column, where RGB toggle sits on boards with underglow), switches them
// to Miryoku's generic variant (Shift-Ins / Ctrl-Ins / Shift-Del / Undo / Again)
// via conditional layers: Nav + Clip -> NavClip, Button + Clip -> BtnClip.
// The flag resets to Mac on power cycle.

#define MIRYOKU_CLIPBOARD_MAC

#define U_G_RDO &kp K_AGAIN
#define U_G_PST &kp LS(INS)
#define U_G_CPY &kp LC(INS)
#define U_G_CUT &kp LS(DEL)
#define U_G_UND &kp K_UNDO

// ---------------------------------------------------------------------------
// Window layer (replaces Mouse; hold Tab)
// ---------------------------------------------------------------------------
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

// ---------------------------------------------------------------------------
// Media layer: RGB toggle slot becomes the clipboard toggle
// ---------------------------------------------------------------------------

#define MIRYOKU_LAYER_MEDIA \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              &tog U_CLIP,       U_RGB_EFF,         U_RGB_HUI,         U_RGB_SAI,         U_RGB_BRI,         \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              U_EP_TOG,          &kp C_PREV,        &kp C_VOL_DN,      &kp C_VOL_UP,      &kp C_NEXT,        \
U_NA,              &kp RALT,          &u_to_U_FUN,       &u_to_U_MEDIA,     U_NA,              &u_out_tog,        &u_bt_sel_0,       &u_bt_sel_1,       &u_bt_sel_2,       &u_bt_sel_3,       \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp C_STOP,        &kp C_PP,          &kp C_MUTE,        U_NP,              U_NP

// ---------------------------------------------------------------------------
// Clipboard flag + overlay layers
// ---------------------------------------------------------------------------

// Flag only; fully transparent.
#define MIRYOKU_LAYER_CLIP \
&trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            \
&trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            \
&trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            \
U_NP,              U_NP,              &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            U_NP,              U_NP
#define MIRYOKU_LAYERMAPPING_CLIP MIRYOKU_MAPPING

// Generic clipboard over the Nav layer's top-right row.
#define MIRYOKU_LAYER_NAV_CLIP \
&trans,            &trans,            &trans,            &trans,            &trans,            U_G_RDO,           U_G_PST,           U_G_CPY,           U_G_CUT,           U_G_UND,           \
&trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            \
&trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            \
U_NP,              U_NP,              &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            U_NP,              U_NP
#define MIRYOKU_LAYERMAPPING_NAV_CLIP MIRYOKU_MAPPING

// Generic clipboard over the Button layer's top and bottom rows, both hands.
#define MIRYOKU_LAYER_BUTTON_CLIP \
U_G_UND,           U_G_CUT,           U_G_CPY,           U_G_PST,           U_G_RDO,           U_G_RDO,           U_G_PST,           U_G_CPY,           U_G_CUT,           U_G_UND,           \
&trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            \
U_G_UND,           U_G_CUT,           U_G_CPY,           U_G_PST,           U_G_RDO,           U_G_RDO,           U_G_PST,           U_G_CPY,           U_G_CUT,           U_G_UND,           \
U_NP,              U_NP,              &trans,            &trans,            &trans,            &trans,            &trans,            &trans,            U_NP,              U_NP
#define MIRYOKU_LAYERMAPPING_BUTTON_CLIP MIRYOKU_MAPPING

// ---------------------------------------------------------------------------
// Layer list: standard ids kept (so &u_to_U_MOUSE etc. still work), Mouse
// relabelled "Window", three clipboard layers appended above everything.
// ---------------------------------------------------------------------------

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,        "Base") \
MIRYOKU_X(EXTRA,       "Extra") \
MIRYOKU_X(TAP,         "Tap") \
MIRYOKU_X(BUTTON,      "Button") \
MIRYOKU_X(NAV,         "Nav") \
MIRYOKU_X(MOUSE,       "Window") \
MIRYOKU_X(MEDIA,       "Media") \
MIRYOKU_X(NUM,         "Num") \
MIRYOKU_X(SYM,         "Sym") \
MIRYOKU_X(FUN,         "Fun") \
MIRYOKU_X(CLIP,        "Clip") \
MIRYOKU_X(NAV_CLIP,    "NavClip") \
MIRYOKU_X(BUTTON_CLIP, "BtnClip")

#define U_BASE        0
#define U_EXTRA       1
#define U_TAP         2
#define U_BUTTON      3
#define U_NAV         4
#define U_MOUSE       5
#define U_MEDIA       6
#define U_NUM         7
#define U_SYM         8
#define U_FUN         9
#define U_CLIP        10
#define U_NAV_CLIP    11
#define U_BUTTON_CLIP 12

/ {
  conditional_layers {
    compatible = "zmk,conditional-layers";
    nav_clip {
      if-layers = <U_NAV U_CLIP>;
      then-layer = <U_NAV_CLIP>;
    };
    button_clip {
      if-layers = <U_BUTTON U_CLIP>;
      then-layer = <U_BUTTON_CLIP>;
    };
  };
};
