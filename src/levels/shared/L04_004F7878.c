#include "common.h"

/* localdecomp:start func_L04_004F7878 */
typedef struct {
    u8 pad0[0x88];
    f32 f88;
    u8 pad8C[0x8C];
    f32 f118;
    u8 pad11C[0xC0];
    s16 f1DC;
    s16 f1DE;
    u8 pad1E0[0x158];
    f32 f338;
    f32 f33C;
    u8 pad340[0x10];
    f32 f350;
    f32 f354;
    u8 pad358[0x8];
    s32 f360;
    u8 pad364[0x4];
    s16 f368;
    u8 pad36A[0x2];
    s16 f36C;
    u8 pad36E[0x100];
    u8 f46E;
    u8 pad46F[0x1001];
    s16 f1470;
    u8 pad1472[0x4];
    u8 f1476;
    u8 pad1477[0x1];
    u8 f1478;
    u8 f1479;
    u8 pad147A[0x2];
    u8 f147C;
    u8 f147D;
    u8 pad147E[0x1];
    u8 f147F;
    u8 pad1480[0x1144];
    s32 f25C4;
    u8 pad25C8[0x4];
    s32 f25CC;
    u8 pad25D0[0x14];
    u8 f25E4;
    u8 pad25E5[0x5];
    u8 f25EA;
    u8 pad25EB[0x3];
    u8 f25EE;
    u8 pad25EF[0x259];
    f32 f2848;
    u8 pad284C[0x4];
    s32 f2850;
} Hero_L04_004F7878;

__asm__(".extern D_001A4BE0, 16");
extern Hero_L04_004F7878 D_001A4BE0;
extern s32 D_00142668[];
extern u8 D_00142CAD[];
extern void func_0038CBA0(void *, s32);
extern void func_L01_004DFEA0(s32);
extern void func_L04_0050CB28(s32, s32);
extern void func_L01_004E7C88(void);

void func_L04_004F7878(void) {
    s16 st;
    u8 keep;
    f32 d;

    st = D_001A4BE0.f1470;
    keep = D_001A4BE0.f147F;
    func_0038CBA0(&D_001A4BE0.f1470, 0x10);
    D_001A4BE0.f147F = keep;
    D_001A4BE0.f1470 = st;
    D_001A4BE0.f25EA = 0;
    D_001A4BE0.f368 = 0;
    if (D_001A4BE0.f25EE != 0) {
        return;
    }
    if (D_001A4BE0.f360 != 0) {
        if (st == -1) {
            return;
        }
    } else {
        if (st == -1) {
            return;
        }
    }
    if ((st == 2 || st == 0x11 || st == 0x12) && D_001A4BE0.f1DE == 0) {
        if (D_001A4BE0.f36C == 0 || D_001A4BE0.f33C < 2.5f) {
            D_001A4BE0.f1479 = 1;
            if (D_001A4BE0.f25E4 == 0 && D_00142CAD[0] != 0) {
                D_001A4BE0.f368 = 1;
            }
        }
    }
    if (st == 0x11 && D_001A4BE0.f1DC == 0 && D_001A4BE0.f36C == 0 &&
        D_001A4BE0.f25CC != 7) {
        func_L01_004DFEA0(D_00142668[0] / 8);
        D_001A4BE0.f1DC = 0x4B;
        func_L04_0050CB28(0xB1, 1);
    }
    if (st == 0xE) {
        D_001A4BE0.f1476 = 1;
        D_001A4BE0.f2848 = 0.2f;
        D_001A4BE0.f350 = D_001A4BE0.f338 + 0.2f;
    }
    if (st == 0) {
        d = D_001A4BE0.f350 - D_001A4BE0.f338;
        D_001A4BE0.f2848 = d;
        if (d < 0.85f && 0.25f < d) {
            D_001A4BE0.f25EA = 1;
        }
        D_001A4BE0.f1476 = 1;
    }
    if (st == 3) {
        D_001A4BE0.f1478 = 1;
    }
    if (st == 0xB) {
        D_001A4BE0.f147D = 1;
    }
    if (st == 8 || st == 0x12) {
        D_001A4BE0.f147C = 1;
    }
    if (st == 0xC) {
        D_001A4BE0.f147C = 1;
    }
    if (D_001A4BE0.f1478 != 0 && D_001A4BE0.f25C4 != 0x6A &&
        D_001A4BE0.f25C4 != 0x7D) {
        if (fabsf(D_001A4BE0.f354 - (D_001A4BE0.f88 + 0.25f)) < 1.0f &&
            0.0f < D_001A4BE0.f354 - D_001A4BE0.f88 &&
            (D_001A4BE0.f25C4 != 0x6B || D_001A4BE0.f46E != 0) &&
            (D_001A4BE0.f118 < 0.0f || D_001A4BE0.f25C4 == 0x80)) {
            func_L01_004E7C88();
            if (D_001A4BE0.f2850 == 0) {
                func_L04_0050CB28(0x7D, 1);
            } else {
                func_L04_0050CB28(0x6A, 1);
            }
            return;
        }
    }
    if (D_001A4BE0.f147D != 0 && D_001A4BE0.f25C4 != 0x7D &&
        D_001A4BE0.f25C4 != 0x79) {
        if (fabsf(D_001A4BE0.f354 - (D_001A4BE0.f88 + 0.25f)) < 1.0f &&
            0.0f < D_001A4BE0.f354 - D_001A4BE0.f88 &&
            (D_001A4BE0.f118 < 0.0f || D_001A4BE0.f25C4 == 0x80)) {
            func_L01_004E7C88();
            func_L04_0050CB28(0x7D, 1);
        }
    }
}
/* localdecomp:end func_L04_004F7878 */
