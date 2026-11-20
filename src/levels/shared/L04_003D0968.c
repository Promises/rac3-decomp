#include "common.h"

/* localdecomp:start func_L04_003D0968 */
typedef void (*Fn_003D0968)(u8 *);

__asm__(".extern D_L04_001DEAE0, 4");
__asm__(".extern D_L04_001DEAE4, 4");
__asm__(".extern D_L04_001DEAE8, 4");
__asm__(".extern D_L04_001DEAEC, 4");
__asm__(".extern D_L04_001DEAF0, 4");
__asm__(".extern D_L04_001DEAF4, 4");
__asm__(".extern D_L04_001DEAF8, 4");
__asm__(".extern D_L04_001DEAFC, 4");
__asm__(".extern D_L04_001DEB00, 4");
extern s32 D_L04_001DEAE0;
extern s32 D_L04_001DEAE4;
extern s32 D_L04_001DEAE8;
extern s32 D_L04_001DEAEC;
extern s32 D_L04_001DEAF0;
extern s32 D_L04_001DEAF4;
extern s32 D_L04_001DEAF8;
extern s32 D_L04_001DEAFC;
extern s32 D_L04_001DEB00;
extern s32 D_L04_001DF940;
extern s32 func_L04_003D0C40(u8 *, u8 *);
extern void func_L04_003D1420();
extern s32 func_L01_004561B8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern Fn_003D0968 *func_L01_0043B548(s32, s32);
extern void func_L03_003B1DD0(void *);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00404A10(void *, void *);

void func_L04_003D0968(u8 *moby) {
    u8 *v = *(u8 **)(moby + 0x68);
    u8 *o;
    s32 r;

    if (moby[0x20] == 0) {
        if (func_L04_003D0C40(moby, v) == 0) {
            return;
        }
    }
    switch (moby[0x20]) {
    case 1:
        if (func_L01_004561B8(moby) == 0) {
            return;
        }
        *(s32 *)(moby + 0x78) = D_L04_001DEAE0;
        if (*(s32 *)(v + 0x90) != -1) {
            return;
        }
        func_L01_004450F0(moby, 3, -1);
        break;
    case 2:
        if (func_L01_004561B8(moby) != 0) {
            if (*(s32 *)(v + 0x90) == -2) {
                func_L01_004450F0(moby, 3, -1);
            }
            if (*(u8 **)(v + 0x9C) != 0) {
                (*(u8 **)(v + 0x9C))[0x20] = 7;
            }
        }
        if (D_L04_001DF940 % D_L04_001DEAEC != 0) {
            return;
        }
        if (*(u8 **)(v + 0x9C) == 0) {
            return;
        }
        *(s32 *)(moby + 0x78) = func_0038DBD8(D_L04_001DEAE4, D_L04_001DEAE8, func_003824E0(0.0f, 1.0f));
        v = *(u8 **)(*(u8 **)(v + 0x9C) + 0x68);
        if (!(0.0f < *(f32 *)(v + 0x40))) {
            return;
        }
        r = func_0038DBD8(D_L04_001DEAF0, D_L04_001DEAF4, func_003824E0(0.0f, 1.0f));
        *(s32 *)(moby + 0x78) = func_0038DBD8(*(s32 *)(moby + 0x78), r, *(f32 *)(v + 0x40));
        if (*(f32 *)(v + 0x40) != 1.0f) {
            return;
        }
        func_L01_004450F0(moby, 3, -1);
        break;
    case 3:
        if (func_L01_004561B8(moby) != 0) {
            if (*(s32 *)(v + 0x70) != 0) {
                ((void (*)(u8 *, s32))func_L01_0043B548(0x19E1, 0x6C)[2])(moby, 1);
            } else {
                func_L01_00456230(moby, 1);
            }
            if (*(void **)(v + 0xA0) != 0) {
                func_L03_003B1DD0(*(void **)(v + 0xA0));
            }
            o = *(u8 **)(v + 0x94);
            if (o != 0) {
                if (*(s32 *)(o + 0x90) == -2) {
                    func_L01_004450F0(o, 3, -1);
                } else {
                    func_L01_004450F0(o, 2, -1);
                }
            }
        }
        if (func_L01_004AA710(moby, *(s32 *)(v + 0xA4)) == 0) {
            *(s32 *)(v + 0xA4) = func_003A52A0(0, 4, moby);
        }
        if (D_L04_001DF940 % D_L04_001DEB00 == 0) {
            *(s32 *)(moby + 0x78) = func_0038DBD8(D_L04_001DEAF8, D_L04_001DEAFC, func_003824E0(0.0f, 1.0f));
        }
        if (*(void **)(v + 0x94) != 0) {
            func_L01_00404A10(func_L04_003D1420, moby);
        }
        break;
    }
}
/* localdecomp:end func_L04_003D0968 */

INCLUDE_ASM("asm/levels", func_L04_003D0C40);

/* localdecomp:start func_L04_003D10D0 */
void func_L04_003D10D0(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 104);
    u8 *d = *(u8 **)(a0 + 104);
    *(s32 *)(d + 128) = *(s32 *)(s + 0);
    if (*(f32 *)(s + 4) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 4);
    }
    *(s32 *)(d + 136) = *(s32 *)(s + 8);
    if (*(f32 *)(s + 12) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 12);
    }
    *(s32 *)(d + 144) = *(s32 *)(s + 88);
    *(s32 *)(d + 152) = *(s32 *)(s + 32);
}
/* localdecomp:end func_L04_003D10D0 */

/* localdecomp:start func_L04_003D1128 */
typedef void (*Fn_003CF2A0)(u8 *);

extern u8 D_001A30B0[];
extern void func_003C2880(s32);
extern void func_003A4F28(s32);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);

void func_L04_003D1128(u8 *self) {
    u8 *v = *(u8 **)(self + 104);
    s32 idx;
    u8 *e;

    if (*(s32 *)(v + 156) != 0) {
        func_003C2880(*(s32 *)(v + 156));
        *(s32 *)(v + 156) = 0;
    }
    if (*(s32 *)(v + 160) != 0) {
        func_003C2880(*(s32 *)(v + 160));
        *(s32 *)(v + 160) = 0;
    }
    idx = *(s32 *)(v + 164);
    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 220) == self && e[208] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 164) = -1;
    (*func_L01_0043B548(6625, 108))(self);
}
/* localdecomp:end func_L04_003D1128 */

/* localdecomp:start func_L04_003D11E0 */
int func_L04_003D11E0(u8 *a) {
    int r = 3;
    if (a[32] != 2) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L04_003D11E0 */

/* localdecomp:start func_L04_003D11F8 */
#include "vu0.h"

extern f32 func_00382538(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L04_003D11F8(vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[10][4] __attribute__((aligned(16)));
    s32 i;

    vec_sub_ab(&step, b, a);
    func_0038CE20(&step, &step, 0.111111112f);
    cur = *a;
    for (i = 0; i < 10; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 9) {
            func_003C4C18(pts[i], 0.3f);
        }
        pts[i][3] = 0.075f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.075f, 4.0f, 0.0f, 0x17, 0x17, 0xB, -1, 0x80802020, 0);
    func_003D9508(a, 0x31, -1, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(a, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
    func_003D9508(b, 0x31, -1, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(b, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
}
/* localdecomp:end func_L04_003D11F8 */

/* localdecomp:start func_L04_003D1420 */
#include "vu0.h"

typedef struct O_3D1420_003D1420 O_3D1420_003D1420;
typedef struct {
    u8 pad0[0x90];
    s32 i90;
    O_3D1420_003D1420 *p94;
} M_3D1420_003D1420;
struct O_3D1420_003D1420 {
    u8 pad0[0x10];
    vu0_q q10;
    u8 pad20[0x68 - 0x20];
    M_3D1420_003D1420 *p68;
    u8 pad6C[0x90 - 0x6C];
    s32 i90;
    u8 pad94[0xD0 - 0x94];
    vu0_q qD0;
    vu0_q qE0;
};
extern f32 D_L04_001DEB30_003D1420; __asm__(".extern D_L04_001DEB30_003D1420, 4");
extern f32 D_L04_001DEB34_003D1420; __asm__(".extern D_L04_001DEB34_003D1420, 4");
extern void func_0038CE20(void *, void *, f32);
extern void func_L04_003D11F8_003D1420(vu0_q *, vu0_q *);

void func_L04_003D1420(O_3D1420_003D1420 *o) {
    vu0_q a[2];
    vu0_q t;
    vu0_q u;
    vu0_q qa, qb;
    M_3D1420_003D1420 *m;
    O_3D1420_003D1420 *other;

    m = o->p68;
    other = m->p94;
    if (m->i90 < 0) {
        a[0] = o->q10;
    } else {
        func_0038CE20(&a[0], &o->qE0, D_L04_001DEB30_003D1420);
        func_0038CE20(&t, &o->qD0, D_L04_001DEB34_003D1420);
        __asm__("lqc2 %0, %4\n"
                "\tlqc2 %1, %5\n"
                "\tvadd.xyz %1, %1, %0\n"
                "\tlqc2 %0, %6\n"
                "\tsqc2 %0, %3\n"
                "\tsqc2 %1, %2"
                : "=&j"(qa), "=&j"(qb), "=m"(a[0]), "=m"(u)
                : "m"(a[0]), "m"(t), "m"(o->q10));
        vec_add_ab(&a[0], &a[0], &u);
    }
    if (other->i90 < 0) {
        a[1] = m->p94->q10;
    } else {
        func_0038CE20(&a[1], &m->p94->qE0, D_L04_001DEB30_003D1420);
        func_0038CE20(&t, &m->p94->qD0, -D_L04_001DEB34_003D1420);
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(a[1]));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(a[1]) : "j"(qa));
        vec_add_ab(&a[1], &a[1], &m->p94->q10);
    }
    func_L04_003D11F8_003D1420(&a[0], &a[1]);
}
/* localdecomp:end func_L04_003D1420 */

/* localdecomp:start func_L04_003D1530 */
__asm__(".extern D_L04_001DEBC0, 4");
extern s32 D_L04_001DEBC0;
s32 *func_L04_003D1530(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 1) {
        *a2 = 28;
        return &D_L04_001DEBC0;
    }
    return 0;
}
/* localdecomp:end func_L04_003D1530 */

INCLUDE_ASM("asm/levels", func_L04_003D1550);

/* localdecomp:start func_L04_003D3018 */
extern s32 D_001A30F4[];
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern f32 D_L04_001DA8B8; __asm__(".extern D_L04_001DA8B8, 4");
extern f32 D_L04_001DA8B0; __asm__(".extern D_L04_001DA8B0, 4");
extern f32 D_L04_002F1F70[];
extern f32 D_L04_002F1D90[];
extern f32 func_00382538(void);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);

void func_L04_003D3018(u8 *moby, u8 *v) {
    s32 n;
    Fn_003CF2A0 *fn;

    moby[0xBC] = 0;
    *(f32 *)(v + 0xB8) = *(f32 *)(moby + 0x18);
    *(s32 *)(v + 0xC8) = -1;
    *(f32 *)(v + 0x8C) = 1.0f;
    *(s32 *)(v + 0xA0) = 0;
    *(s32 *)(v + 0x94) = 0;
    *(s32 *)(v + 0x98) = 0;
    *(s32 *)(v + 0xA4) = 0;
    *(s32 *)(v + 0xA8) = 0;
    *(s32 *)(v + 0x88) = 0;
    *(s32 *)(v + 0xD4) = 0;
    D_001A30F4[0] = (s32)moby;
    *(f32 *)(v + 0x9C) = func_00382538();
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 50;
        if (func_L01_0041A4F0()) {
            *(s16 *)(v + 0x34) = (f32)*(s16 *)(v + 0x34) *
                ((D_001D545C == 7 && D_0014275B[0]) ? D_L04_001DA8B8 : D_L04_002F1F70[D_001D545C]);
        }
    }
    *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
    if (v[0x44] == 0) {
        v[0x44] = 9;
        if (func_L01_0041A4F0()) {
            n = (f32)v[0x44] *
                ((D_001D545C == 7 && D_0014275B[0]) ? D_L04_001DA8B0 : D_L04_002F1D90[D_001D545C]);
            if (n > 0xFF) {
                n = 0xFF;
            }
            v[0x44] = n;
        }
    }
    *(s32 *)(v + 0x84) = 0;
    *(s32 *)(v + 0x90) = 0;
    func_L01_004450F0(moby, 1, -1);
    func_L01_00456230(moby, 0);
    if (*(s32 *)(v + 0x70) > 0) {
        fn = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(v + 0x70) = -1;
        v[0x7E] = 4;
        (*fn)(moby);
    } else if (v[0x80] != 0) {
        func_L01_004450F0(moby, 5, -1);
    } else if (*(s32 *)(v + 0xD0) != -1) {
        func_L01_004450F0(moby, 3, -1);
    }
}
/* localdecomp:end func_L04_003D3018 */
