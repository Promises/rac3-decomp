#include "common.h"
#include "vu0.h"

typedef struct {
    s32 w0;
    s32 w4;
} S_34A460b;
typedef struct {
    u8 pad0[0x68];
    S_34A460b *p68;
} S_34A460;

/* localdecomp:start func_L04_00355740 */
/* PROVISIONAL, VU0 j-constraint form (docs/wiki/Matching-Patterns.md, "VU0 j-form") */
typedef struct { f32 u, v; } UV_355740;
typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    UV_355740 uv[4];
    long x70, x78, x80, x88;
} Q_355740;

extern void func_L01_0034D840(void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern vu0_v4 D_L04_001E27C0;

void func_L04_00355740(void *unused, u32 c0, u32 c1, u8 *o) {
    Q_355740 q;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 f;
    vu0_v4 e;
    vu0_v4 g;
    u8 *t;
    s32 i;

    t = *(u8 **)(o + 0x68);
    func_L01_0034D840(&q);
    func_003D93B0(&q, 0x2F, 0, 0x80);
    q.col[1] = -1;
    q.col[3] = 0x40FFFFFF;
    q.col[2] = 0x40FFFFFF;
    q.col[0] = -1;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= *(f32 *)(t + 0x28);
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    *(f32 *)(t + 0x28) += 0.1f;
    if (4.0f <= *(f32 *)(t + 0x28)) {
        *(f32 *)(t + 0x28) -= 4.0f;
    }
    func_0038CF68(&a, t, -0.17f);
    {
        vu0_q x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_L04_001E27C0));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(y));
        __asm__("lqc2 %0, %2\n\tsqc2 %3, %1" : "=&j"(y), "=m"(a) : "m"(*(vu0_v4 *)(o + 0x10)), "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(y));
    }
    if (t[0x34] != 0 && *(f32 *)(t + 0x38) < 4.0f) {
        func_0038CF68(&c, t, -*(f32 *)(t + 0x38));
    } else {
        func_0038CF68(&c, t, -4.0f);
    }
    vec_add_ba(&d, &a, &c);
    func_0038CE90(&f, &b, &c);
    func_0038CF68(&f, &f, 0.1f);
    vec_add_ba(&q.v[0], o + 0x10, &f);
    vec_sub_ab(&q.v[1], o + 0x10, &f);
    vec_add_ba(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    q.col[0] = q.col[2];
    q.col[1] = q.col[3];
    q.col[3] = 0x801010;
    q.col[2] = 0x801010;
    *(vu0_q *)&q.v[0] = *(vu0_q *)&q.v[2];
    *(vu0_q *)&q.v[1] = *(vu0_q *)&q.v[3];
    vec_add_ba(&q.v[2], &q.v[2], &c);
    vec_add_ab(&q.v[3], &q.v[3], &c);
    func_003D2DA0(&q, 0, 0);
    func_003D93B0(&q, 0x29, 1, 0x80);
    q.col[1] = c0;
    q.col[0] = c0;
    q.col[3] = c1;
    q.col[2] = c1;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    func_0038CF68(&f, &f, 0.2f);
    {
        vu0_q x, y, r, s, u;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(s) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("sqc2 %1, %0" : "=m"(q.v[0]) : "j"(r));
        __asm__("lqc2 %0, %1" : "=j"(r) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("sqc2 %1, %0" : "=m"(g) : "j"(r));
        __asm__("lqc2 %0, %1" : "=j"(u) : "m"(f));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(s) : "j"(s), "j"(u));
        __asm__("sqc2 %1, %0" : "=m"(q.v[1]) : "j"(s));
        __asm__("lqc2 %0, %1" : "=j"(s) : "m"(g));
        __asm__("lqc2 %0, %1" : "=j"(u) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(u) : "j"(s), "j"(u));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(u));
    }
    vec_add_ba(&d, &d, &c);
    vec_add_ab(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    q.col[1] = c0;
    q.col[3] = c1;
    q.col[0] = c0;
    q.col[2] = c1;
    func_0038CF68(&f, &f, 0.4f);
    func_0038CF68(&a, t, -0.1f);
    {
        vu0_q x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(r) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(r));
        __asm__("sqc2 %1, %0" : "=m"(q.v[0]) : "j"(y));
    }
    vec_sub_ba(&q.v[1], &a, &f);
    vec_add_ab(&d, &a, &c);
    vec_add_ba(&d, &d, &c);
    vec_add_ab(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    func_003D9508(o + 0x10, 0x13, 0x60804020, 1, 0.3f, 0.08f, func_00382538());
}
/* localdecomp:end func_L04_00355740 */

/* localdecomp:start func_L04_00355BF8 */


extern s32 func_0038CB00(s32 *a0);
extern void func_L01_00404A10_00355BF8(void (*a0)(u8 *), S_34A460 *a1);
extern void func_L04_00355C60(u8 *o);
extern void func_003C2880(S_34A460 *a0);

void func_L04_00355BF8(S_34A460 *a0) {
    S_34A460b *t = a0->p68;
    if (func_0038CB00(&t->w0) == 0) {
        func_0038CB00(&t->w4);
        func_L01_00404A10_00355BF8(func_L04_00355C60, a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L04_00355BF8 */

/* localdecomp:start func_L04_00355C60 */
typedef struct {
    s16 h0, h2, h4;
    u8 pad6[2];
    f32 f8;
    f32 fC;
    u8 pad10[8];
    s32 w18;
    s32 w1C;
} S_355C60;
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern void func_L04_00355DE0(void *, s32, f32, f32, f32, f32, f32, s32);
extern s16 D_L04_001CFEC0[];

void func_L04_00355C60(u8 *o) {
    S_355C60 *s = *(S_355C60 **)(o + 0x68);
    if (s->h2 - s->h0 < 2 && s->h4 != 0 && s->w1C != 0) {
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_L04_001CFEC0[0xA9], 0, D_L04_001CFEC0[0xA8], (s32)0x80808080);
    }
    if (s->w18 != 0) {
        if (s->h2 - s->h0 < 10) {
            func_L04_00355DE0(o + 0x10, 0x3B, s->f8 + (s->fC - s->f8) * ((f32)(s->h2 - s->h0) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f, 0);
        } else if ((u16)(s->h0 - 0x2E) < 4) {
            func_L04_00355DE0(o + 0x10, 0x3B, s->f8 + (s->fC - s->f8) * ((f32)(s->h0 - 0x2D) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f, 0);
        }
    }
}
/* localdecomp:end func_L04_00355C60 */

/* localdecomp:start func_L04_00355DE0 */
typedef struct { f32 u, v; } UV_355DE0;
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    UV_355DE0 uv[4];
    long x70, x78, x80, x88;
} Q_355DE0;
typedef struct { vu0_v4 pos; u8 p10[0x1C0]; vu0_v4 up; u8 p1E0[0x460 - 0x1E0]; } Cam_355DE0;

extern s32 D_001D52F0;
extern Cam_355DE0 D_L04_001E2840[];
extern vu0_v4 D_L04_001D7AD0[4];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);

void func_L04_00355DE0(void *pos, s32 tex, f32 size, f32 lift, f32 roll, f32 unused, f32 jitter, s32 shrink) {
    Q_355DE0 q;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 p;
    vu0_v4 z;
    vu0_v4 c;
    vu0_v4 t;
    vu0_v4 w;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    Cam_355DE0 *cam;

    func_003D93B0(&q, tex, 1, 0x80);
    q.x88 = 0x800000004A;
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    p = *(vu0_v4 *)pos;
    vec_sub_ba(&d, &D_L04_001E2840[D_001D52F0], &p);
    func_0038CF68(&d, &d, 1.0f);
    cam = &D_L04_001E2840[D_001D52F0];
    func_0038CE90(&e, &d, &cam->up);
    func_0038CF68(&e, &e, 1.0f);
    func_0038CE90(&f, &e, &d);
    if (roll != 0.0f) {
        *(vu0_q *)&z = 0;
        z.x = roll;
        func_0038D308(&c, &z);
        func_0038D5F0(&d, &d, &c);
    }
    func_0038CE20(&z, &d, lift);
    vec_add_ab(&p, &p, &z);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L04_001D7AD0[i], size);
        func_0038D028(&q.v[i], &q.v[i], &d);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    if (shrink != 0) {
        c = q.v[0];
        for (k = 1; k < 4; k++) {
            vec_add_ba(&c, &c, &q.v[k]);
        }
        func_0038CE20(&c, &c, 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ba(&t, &q.v[j], &c);
            func_0038CE20(&t, &t, 0.8f);
            vec_add_ab(&t, &c, &t);
            func_00389478(&t, &q.uv[j].u, &q.uv[j].v);
            if (func_00382468(1) == 0) {
                q.uv[j].u += func_003824E0(-jitter, jitter);
                q.uv[j].v += func_003824E0(-jitter, jitter);
            }
            if (1.0f < q.uv[j].u) {
                q.uv[j].u = 1.0f;
            } else if (q.uv[j].u < 0.0f) {
                q.uv[j].u = 0.0f;
            }
            if (1.0f < q.uv[j].v) {
                q.uv[j].v = 1.0f;
            } else if (q.uv[j].v < 0.0f) {
                q.uv[j].v = 0.0f;
            }
        }
    } else {
        for (n = 0; n < 4; n++) {
            func_00389478(&q.v[n], &q.uv[n].u, &q.uv[n].v);
            if (func_00382468(1) == 0) {
                q.uv[n].u += func_003824E0(-jitter, jitter);
                q.uv[n].v += func_003824E0(-jitter, jitter);
            }
            if (1.0f < q.uv[n].u) {
                q.uv[n].u = 1.0f;
            } else if (q.uv[n].u < 0.0f) {
                q.uv[n].u = 0.0f;
            }
            if (1.0f < q.uv[n].v) {
                q.uv[n].v = 1.0f;
            } else if (q.uv[n].v < 0.0f) {
                q.uv[n].v = 0.0f;
            }
        }
    }
    func_003D93B0(&q, -1, 1, 0x80);
    q.x88 = 0x8000000054;
    func_003A9440(0x47, 0x33001);
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L04_00355DE0 */
