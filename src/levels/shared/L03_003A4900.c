#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_003A4900);

/* localdecomp:start func_L03_003A4FC8 */
typedef struct Vars_3A4FC8 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} Vars_3A4FC8;
typedef struct Rec_3A4FC8 {
    u8 pad0[0x10];
    f32 e10[4];
    f32 e20[4];
    vu0_q pos;
    u8 pad40[0x40];
} Rec_3A4FC8;
extern u8 *D_L03_001DFA80;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[];
extern void func_0038CC88(void *, void *, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern void func_003C2880(void *);
extern void func_L01_003F5E88(void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_003A4FC8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3A4FC8 *vars = *(Vars_3A4FC8 **)(obj + 0x68);
    f32 a;
    f32 b;
    u8 *dir;
    Rec_3A4FC8 *tbl;

    vars->f4 = 1.0f;
    vars->w14 = -1;
    vars->w8 = 0;
    vars->w10 = 0;
    if (vars->w18 < 10) {
        vars->w18 = (s32)((f32)vars->w18 * 50.0f);
    } else {
        vars->w18 = (vars->w18 * 5 + 2) / 6;
    }
    dir = obj + 0xC0;
    tbl = (Rec_3A4FC8 *)D_L03_001DFA80;
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x145;
    *(vu0_q *)(obj + 0x10) = tbl[vars->w0].pos;
    func_0038CC88(dir, &((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0], 0x30);
    a = func_0038CEA8(((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0].e10);
    b = func_0038CEA8(((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0].e20);
    if (b < a) {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * a;
        func_0038CE20(obj + 0xD0, obj + 0xD0, b / a);
    } else {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * b;
        func_0038CE20(obj + 0xD0, obj + 0xD0, a / b);
    }
    func_003C7C38(obj);
    if (D_001BBC40[obj[0xB0] + (D_001D545C << 4)] & 0x80) {
        func_003C2880(obj);
        return;
    }
    func_L01_003F5E88(obj);
    if (vars->wC != 0) {
        vars->f4 = 0.0f;
        func_L01_004450F0(obj, 1, 1);
    } else {
        vars->f4 = 1.0f;
        func_L01_004450F0(obj, 2, 1);
    }
}
/* localdecomp:end func_L03_003A4FC8 */

/* localdecomp:start func_L03_003A51E0 */
extern s32 func_00382498(s32, s32);
extern void func_0038D570(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern vu0_v4 D_L03_002BA370[][4];
extern u8 *D_L03_001DFA80;

void func_L03_003A51E0(vu0_v4 *out, s32 idx) {
    vu0_v4 s[2];
    vu0_v4 m[4];
    vu0_v4 e;
    vu0_v4 r;
    vu0_v4 t;
    s32 n;
    s32 k;

    n = func_00382498(0, 5);
    k = func_00382498(0, 3);
    switch (k) {
    case 0:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][1];
        break;
    case 1:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][2];
        break;
    case 2:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][2];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    case 3:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][1];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    }
    func_0038D570(m, D_L03_001DFA80 + idx * 0x80);
    *(vu0_q *)&m[3] = *(vu0_q *)(D_L03_001DFA80 + idx * 0x80 + 0x30);
    m[3].w = 1.0f;
    vec_sub_ba(&r, &s[1], &s[0]);
    e = r;
    func_0038CE20(&e, &e, func_003824E0(0.0f, 1.0f));
    vec_add_ab(&t, &s[0], &e);
    r = t;
    *out = r;
    func_0038D028(out, out, m);
}
/* localdecomp:end func_L03_003A51E0 */

/* localdecomp:start func_L03_003A5388 */
typedef struct {
    vu0_v4 v[4];
} V4x4_003A5388;

typedef struct {
    V4x4_003A5388 v;
    u32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_003A5388;

typedef struct {
    s32 i0;
    f32 f4;
    u8 pad8[0x8];
    f32 f10;
    u8 pad14[0x8];
    u8 b1C;
    u8 b1D;
    u8 b1E;
} S_003A5388;

typedef struct {
    u8 pad0[0x68];
    S_003A5388 *p68;
} A_003A5388;

extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L03_003A5388(void *arg) {
    A_003A5388 *a = arg;
    S_003A5388 *s = a->p68;
    u8 *e = D_L03_001DFA80 + (s->i0 << 7);
    Q_003A5388 q;
    vu0_v4 m[4];
    f32 scale;
    f32 h;
    f32 sn;
    f32 cs;
    f32 lo;
    f32 hi;
    u32 color;
    s32 i;

    func_0038D570(m, e);
    *(vu0_q *)&m[3] = *(vu0_q *)(e + 0x30);
    m[3].w = 1.0f;
    scale = s->f4;
    color = ((s32)(scale * 20.0f) << 24) | (s->b1E << 16) | (s->b1D << 8) | s->b1C;
    h = scale * scale * 0.2f;
    sn = func_0038D098(s->f10) * 0.08f;
    cs = func_0038D0B0(s->f10) * 0.08f;
    q.x78 = func_00389598(0x1E);
    q.x80 = 0xFF9000000260L;
    q.x70 = 4;
    q.x88 = 0x8000000048L;
    lo = 0.5f - h;
    hi = h + 0.5f;
    q.uv[0][0] = lo + sn;
    q.uv[0][1] = hi + cs;
    q.uv[1][0] = hi - cs;
    q.uv[1][1] = hi + sn;
    q.uv[2][0] = lo - sn;
    q.uv[2][1] = lo - cs;
    q.uv[3][0] = hi + cs;
    q.uv[3][1] = lo - sn;
    q.color[3] = color;
    q.color[2] = color;
    q.color[1] = color;
    q.color[0] = color;
    for (i = 0; i < 6; i++) {
        q.v = *(V4x4_003A5388 *)D_L03_002BA370[i];
        func_003D2DA0(&q, m, 0);
    }
}
/* localdecomp:end func_L03_003A5388 */
