/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 5; /* border pixel of windows */
static const unsigned int gappx = 5;    /* gaps between windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const char *fonts[] = {"monospace:size=10"};
static const char dmenufont[] = "monospace:size=10";
static const char col_gray1[] = "#1D2330";
static const char col_gray2[] = "#4B5665";
static const char col_gray3[] = "#AD69AF";
static const char col_gray4[] = "#d1d7e1";
static const char col_cyan[] = "#84598D";
static const char col_border[] = "#D37";
static const unsigned int baralpha = 0xef;
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_border},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;   /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod1Mask
#define ALTMOD Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},    \
      {ALTMOD, KEY, focusnthmon, {.i = TAG}},                                  \
      {ALTMOD | ShiftMask, KEY, tagnthmon, {.i = TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"rofi", "-show", "run", NULL};
static const char *termcmd[] = {"alacritty", NULL};
static const char *browser[] = {"qutebrowser", NULL};
static const char *spotify[] = {"spotify", NULL};
static const char *fileman[] = {"pcmanfm", NULL};
static const char *stk[] = {"supertuxkart", NULL};
static const char *webcam[] = {"webcamoid", NULL};

static const char *screenshot[] = {"/usr/bin/scrot", NULL};

// volume
static const char *upvol[] = {"/usr/bin/pactl", "set-sink-volume",
                              "@DEFAULT_SINK@", "+5%", NULL};
static const char *downvol[] = {"/usr/bin/pactl", "set-sink-volume",
                                "@DEFAULT_SINK@", "-5%", NULL};
static const char *mutevol[] = {"/usr/bin/pactl", "set-sink-mute",
                                "@DEFAULT_SINK@", "toggle", NULL};

// media control
static const char *next[] = {"/usr/bin/playerctl", "next", "toggle", NULL};
static const char *previous[] = {"/usr/bin/playerctl", "previous", "toggle",
                                 NULL};
static const char *play3pause[] = {"/usr/bin/playerctl", "play3pause", "toggle",
                                   NULL};

// brightness control
static const char *upbright[] = {"/usr/bin/brightnessctl", "set", "+5%", NULL};
static const char *downbright[] = {"/usr/bin/brightnessctl", "set", "5%-",
                                   NULL};

// sleep mode
static const char *suspend[] = {"/usr/bin/systemctl", "suspend", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_space, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_e, spawn, {.v = fileman}},
    {MODKEY, XK_b, spawn, {.v = browser}},
    {MODKEY | ShiftMask, XK_s, spawn, {.v = stk}},
    {MODKEY, XK_m, spawn, {.v = spotify}},
    {MODKEY, XK_F6, spawn, {.v = webcam}},

    {MODKEY, XK_F7, spawn, {.v = screenshot}},

    {MODKEY, XK_F1, spawn, {.v = downvol}},
    {MODKEY, XK_Escape, spawn, {.v = mutevol}},
    {MODKEY, XK_F2, spawn, {.v = upvol}},
    {MODKEY, XK_F12, spawn, {.v = next}},
    {MODKEY, XK_F10, spawn, {.v = previous}},
    {MODKEY, XK_F11, spawn, {.v = play3pause}},

    {MODKEY, XK_F9, spawn, {.v = upbright}},
    {MODKEY, XK_F8, spawn, {.v = downbright}},
    {MODKEY, XK_F4, spawn, {.v = suspend}},
    {MODKEY, XK_o, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_u, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_f, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY, XK_d, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_p, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_s, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_j, focusmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_k, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_h, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_l, tagmon, {.i = +1}},
    {MODKEY, XK_minus, setgaps, {.i = -1}},
    {MODKEY, XK_plus, setgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_plus, setgaps, {.i = 0}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_Escape, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
