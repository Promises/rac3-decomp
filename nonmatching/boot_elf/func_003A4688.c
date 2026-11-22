/* func_003A4688 (PAL boot_elf, src/boot_elf/text/3A2FC0.c, flags -mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division @ps2as): the sound manager's per-frame update. Plain-C
   draft written 2026-11-22 from the assembly, starting from Flavius's functional draft
   (nonmatching/functional/func_003A4688.c, 781 differences with the same line). Near miss: 583
   differences (tools/check.py --target boot_elf), also 583 with --no-context (726 at #2942); the instruction
   sequence now lines up with retail's (difflib opcode ratio 0.90 against the functional draft's
   0.69), so the count is mostly register allocation and one-word shifts. NTSC-U: config/us/map.tsv
   says its copy differs (not carried).
   What changed from the functional draft: the manager at 0x1A30B0 as one struct (channels at +0xC0
   = D_1A3170); the VU0 code through include/vu0.h's helpers (vec_sub_ab/ba, vec_add_ab/ba,
   qzero) where retail's lqc2/sqc2 order is theirs; ONE j-form block (marked PROVISIONAL, r3-34):
   the relative-velocity / listener-direction sequence, where retail's 0x2C0 and 0x2F0 stack words
   are reload spills of VU0 values (only vf1/vf2 exist), not locals; with that, the frame is
   0x370 as retail. The ring loop as `if (b != a) do { } while`, the volume ramp's cases in
   retail's order (3, 1, 2) with the 16-bit counter sign-extended at each use, the channel handle
   as u32 (retail builds -1 as lui/ori 0xFFFF), and the two `||` tests split so fold does not turn
   them into range checks. func_003A41C8 is declared void in the file but retail uses the s32 it
   leaves in $v0, so this draft uses an s32 per-function alias (r3-55 1); D_1A30B0 and D_00222400
   have per-function aliases because the file declares them with other types (r3-39).
   Blockers: register allocation in both channel passes (retail spills the three array pointers
   to 0x2D0-0x2D8 and keeps separate induction pointers for &ch->timer and &ch->pos; this draft
   keeps the act[] pointer in $fp); the prologue's `lui` of D_2228D0 before the frame allocation;
   retail's first reads of the manager through D_1A3170 - 0xC0 (writing that cast gives 728, not
   kept); `D_1A3170[i].field` throughout pass 1 gives 728 (ratio 0.87), not kept. */
#include "vu0.h"

typedef int u128_3A4688 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A4688;
typedef struct {
    u8 p0[0x18]; u8 b18; u8 b19; s16 h1A; s32 i1C;
} Def_3A4688;
typedef struct {
    u8 p0[0x10]; V4_3A4688 pos; u8 b20; u8 p21[0xC0 - 0x21]; u8 mtx[0x40];
} Obj_3A4688;
typedef struct {
    u32 handle;            /* 0x00 */
    Def_3A4688 *def;       /* 0x04 */
    u8 p8[4];
    s16 vol;               /* 0x0C */
    u8 pE[2];
    u8 state;              /* 0x10 */
    u8 p11[2];
    u8 b13;                /* 0x13 */
    s32 i14;               /* 0x14 */
    s32 pitch;             /* 0x18 */
    Obj_3A4688 *obj;       /* 0x1C */
    V4_3A4688 pos;         /* 0x20 */
    V4_3A4688 offset;      /* 0x30 */
    s32 i40;               /* 0x40 */
    u8 p44[8];
    s32 i4C;               /* 0x4C */
    u8 p50[4];
    u8 timer[4];           /* 0x54 */
    s32 flags;             /* 0x58 */
    u8 p5C[0x80 - 0x5C];
} Ch_3A4688;
typedef struct {
    s32 i0, i4, i8, iC, i10, i14;  /* 0x00: bus volumes */
    u8 p18[0x40 - 0x18];
    u8 b40, b41, b42, b43;         /* 0x40 */
    s32 i44;                       /* 0x44 */
    s32 i48;                       /* 0x48: ring index */
    u8 p4C[4];
    V4_3A4688 ring[4];             /* 0x50 */
    s32 snd[7];                    /* 0x90 */
    s16 hAC;                       /* 0xAC */
    s16 hAE;                       /* 0xAE */
    u8 pB0[4];
    s32 iB4;                       /* 0xB4 */
    u8 pB8[8];
    Ch_3A4688 ch[52];              /* 0xC0 */
    u8 p1AC0[0x1B20 - 0x1AC0];
    s32 i1B20;                     /* 0x1B20 */
} Mgr_3A4688;

extern Mgr_3A4688 D_1A30B0_003A4688;
extern Ch_3A4688 D_1A3170[];
extern s32 D_2228D0[];
extern f32 D_1A4F30[];
extern u8 D_001D5BDC;
extern s32 D_001D5B70;
extern s32 D_001D5B94;
extern s16 D_16C5A0;
extern V4_3A4688 D_1A4D30;
extern V4_3A4688 D_00222400_003A4688;
extern void func_0013B620(void);
extern void func_003A43E0(void);
extern void func_003A4030(void *, void *);
extern void func_0013CF80(s32, s32, s32, s32, s32);
extern void func_0013CFF8(s32, s32, s32, s32);
extern s32 func_0013BF30(s32, s32);
extern void func_0013C118(s32);
extern void func_0013C200(s32, void *, void *);
extern void func_0013C2C0(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_0013C0B8(s32, s32, s32, s32, s32, s32, void *, void *);
extern s32 func_0013D1E8(s32);
extern void func_0013CA28(void);
extern void func_0013CA20(void);
extern void func_003A2330(void);
extern void func_003A5950();
extern void func_003A5908();
extern s32 func_0038CEB0(void *);
extern void func_0038CF58(void *, s32, s32);
extern void func_0038D3E0(void *, void *, void *);
extern void func_0038D348(void *, void *, f32);
extern f32 func_0038D248(void *, void *);
extern f32 func_0038D288(void *);
extern void func_0038D200(f32 *, void *, f32);
/* func_003A41C8's C is void, but retail uses the s32 it leaves in $v0 (func_003A40F0's). */
extern s32 func_003A41C8_003A4688(void *, void *, void *, void *);
extern s32 func_003A4228(void *, void *);

s32 func_003A4688(void) {
    V4_3A4688 lis;
    V4_3A4688 acc;
    V4_3A4688 vel;
    s32 act[52];
    s32 vol[52];
    f32 dop[52];
    V4_3A4688 tmp;
    s32 has_x;
    vu0_q qa, qb, qc, qd;
    Ch_3A4688 *ch;
    Obj_3A4688 *obj;
    s32 a, b, n, cnt, i, r, v, flags, pan, pitch, h, i14, dead;
    s32 s, m, st, k;
    f32 cut, speed, f, div;

    has_x = D_2228D0[0];
    cut = 0.0f;
    if (has_x != 0) {
        cut = D_1A4F30[0];
    }
    func_0013B620();
    func_003A43E0();
    m = D_1A30B0_003A4688.b43;
    if (m & 8) {
        func_0013CF80(2, 0, 0, 0, 0);
    } else if (m & 0x13) {
        func_0013CF80(2, D_1A30B0_003A4688.b40, D_1A30B0_003A4688.iB4, D_1A30B0_003A4688.b41, D_1A30B0_003A4688.b42);
    } else if (m & 4) {
        func_0013CFF8(2, D_1A30B0_003A4688.iB4, 0xC, 3);
    }
    D_1A30B0_003A4688.b43 = 0;
    if ((D_001D5B94 == 0 || D_001D5B94 == 2) && D_001D5BDC == 0) {
        func_003A4030(&lis, 0);
    }

    n = (D_1A30B0_003A4688.i48 + 1) % 4;
    qzero(&acc);
    D_1A30B0_003A4688.i48 = n;
    *(u128_3A4688 *)&D_1A30B0_003A4688.ring[n] = *(u128_3A4688 *)&D_00222400_003A4688;
    speed = func_0038D288(&D_1A4D30);
    a = D_1A30B0_003A4688.i48;
    b = (a + 3) % 4;
    cnt = 0;
    if (b != a) {
        do {
            vec_sub_ab(&vel, &D_1A30B0_003A4688.ring[a], &D_1A30B0_003A4688.ring[b]);
            if (!(func_0038D288(&vel) < speed + 1.2f)) {
                break;
            }
            a = b;
            vec_add_ab(&acc, &acc, &vel);
            b = (b + 3) % 4;
            cnt++;
        } while (b != D_1A30B0_003A4688.i48);
    }
    if (cnt >= 2) {
        func_0038D200((f32 *)&acc, &acc, 1.0f / (f32)cnt);
    }

    if (D_001D5B70 != 0 || D_1A30B0_003A4688.hAC > 0) {
        div = 1.0f;
        f = (f32)D_1A30B0_003A4688.i0;
        if (D_001D5B70 == 0) {
            if (D_1A30B0_003A4688.hAC == 2) {
                D_1A30B0_003A4688.hAC = 3;
                D_1A30B0_003A4688.hAE = 25;
            }
        } else if (D_1A30B0_003A4688.hAC == 0) {
            if (D_001D5B70 == 2) {
                D_1A30B0_003A4688.hAC = 2;
            } else {
                D_1A30B0_003A4688.hAC = 1;
                D_1A30B0_003A4688.hAE = 25;
            }
        }
        s = (u16)D_1A30B0_003A4688.hAE - 1;
        D_1A30B0_003A4688.hAE = s;
        switch (D_1A30B0_003A4688.hAC) {
        case 3:
            div = (f32)(s16)s / 25.0f * 3.0f + 1.0f;
            if ((s16)s <= 0) {
                D_1A30B0_003A4688.hAC = 0;
            }
            break;
        case 1:
            div = (1.0f - (f32)(s16)s / 25.0f) * 3.0f + 1.0f;
            if ((s16)s <= 0) {
                D_1A30B0_003A4688.hAC = 2;
            }
            break;
        case 2:
            div = 4.0f;
            break;
        }
        f /= div;
        v = (s32)f;
        func_0013BF30(0, v);
        func_0013BF30(3, v);
    } else if (D_001D5B94 == 2 || (D_001D5B94 == 6 && (D_16C5A0 == 3 || D_16C5A0 == 0))) {
        D_1A30B0_003A4688.i4 = 0;
        func_0013BF30(1, 0);
        D_1A30B0_003A4688.i0 >>= 1;
        func_0013BF30(0, D_1A30B0_003A4688.i0);
        D_1A30B0_003A4688.iC >>= 1;
        func_0013BF30(3, D_1A30B0_003A4688.iC);
    } else {
        if (D_1A30B0_003A4688.i1B20 & 2) {
            s32 w = D_1A30B0_003A4688.i4;
            if (has_x != 0) {
                w = w * 3 / 5;
            }
            D_1A30B0_003A4688.i4 = w;
            func_0013BF30(1, w);
        }
        if (D_1A30B0_003A4688.i1B20 & 1) {
            func_0013BF30(0, D_1A30B0_003A4688.i0);
        }
        if (D_1A30B0_003A4688.i1B20 & 8) {
            func_0013BF30(3, D_1A30B0_003A4688.iC);
        }
    }
    if (D_1A30B0_003A4688.i1B20 & 0x10) {
        func_0013BF30(4, D_1A30B0_003A4688.i10);
    }
    if (D_1A30B0_003A4688.i1B20 & 4) {
        func_0013BF30(2, D_1A30B0_003A4688.i8);
        func_0013BF30(6, D_1A30B0_003A4688.i8);
    }
    if (D_1A30B0_003A4688.i1B20 & 0x20) {
        func_0013BF30(5, D_1A30B0_003A4688.i14);
    }

    func_0038CF58(act, 0, 0xD0);
    func_0038CF58(vol, 0, 0xD0);
    func_0038CF58(dop, 0, 0xD0);

    for (i = 0; i < 52; i++) {
        ch = &D_1A3170[i];
        if (ch->state != 7) {
            if (ch->handle == 0) {
                continue;
            }
            if (ch->handle == -1) {
                continue;
            }
        }
        obj = ch->obj;
        dead = 0;
        if (obj != 0) {
            if (obj->b20 == 0xFE || ch->obj->b20 == 0xFD) {
                dead = 1;
            }
        }
        if (dead) {
            ch->obj = 0;
        }
        if (!func_0038CEB0(ch->timer)) {
            continue;
        }
        st = ch->state;
        if (st == 4) {
            act[i] = 0x20;
            continue;
        }
        if (st != 6 && dead && ch->def->b18 != 0) {
            act[i] = 0x20;
            continue;
        }
        if (D_001D5B94 != 0 && D_001D5B94 != 2 && D_001D5B94 != 6 && ch->state != 7) {
            act[i] = 0x10;
            continue;
        }
        if (ch->flags & 0x100) {
            *(u128_3A4688 *)&ch->pos = *(u128_3A4688 *)&D_00222400_003A4688;
        }
        if (ch->obj != 0 && !(ch->flags & 8)) {
            if (ch->flags & 0x40) {
                func_0038D3E0(&tmp, &ch->offset, obj->mtx);
                vec_add_ba(&tmp, &tmp, &obj->pos);
                vec_sub_ba(&vel, &tmp, &ch->pos);
                *(u128_3A4688 *)&ch->pos = *(u128_3A4688 *)&tmp;
            } else {
                ch->pos.z -= 1.0f;
                vec_sub_ab(&vel, &ch->obj->pos, &ch->pos);
                *(u128_3A4688 *)&ch->pos = *(u128_3A4688 *)&ch->obj->pos;
                ch->pos.z += 1.0f;
            }
        } else {
            qzero(&vel);
        }
        /* PROVISIONAL, VU0 j-constraint form */
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(vel));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(acc));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(D_00222400_003A4688));
        __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(ch->pos));
        __asm__("sqc2 %1, %0" : "=m"(vel) : "j"(qa));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qc) : "j"(qc), "j"(qd));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(qc));
        func_0038D348(&tmp, &tmp, 1.0f);
        dop[i] = func_0038D248(&tmp, &vel);
        if (!(ch->flags & 0x10)) {
            r = func_003A41C8_003A4688(ch, &ch->pos, 0, 0);
            vol[i] = ch->vol * r / 1024;
            if (!(ch->def->b19 & 2)) {
                act[i] |= 8;
            }
        } else {
            r = 0x400;
            vol[i] = ch->vol;
            if (ch->flags & 0x200) {
                act[i] |= 8;
            }
        }
        if (has_x != 0 && !(ch->def->b19 & 4) && cut < ch->pos.z) {
            vol[i] /= 2;
        }
        act[i] |= 1;
        if (r < 0x20 && vol[i] < 0x20 && (ch->flags & 4)) {
            act[i] = 0x20;
            continue;
        }
        if (*(u8 *)&ch->flags & 1) {
            continue;
        }
        {
            s32 t = act[i];
            act[i] = t | 2;
            if (ch->flags & 0x20) {
                continue;
            }
            if (ch->def->b19 & 0x10) {
                continue;
            }
            act[i] = t | 6;
        }
    }

    for (i = 0; i < 52; i++) {
        ch = &D_1A3170[i];
        k = act[i];
        if (k == 0) {
            continue;
        }
        h = ch->handle;
        ch->handle = -1;
        if (k & 0x20) {
            if (ch->state == 7) {
                ch->obj = 0;
                ch->i40 = 0;
                ch->state = 0;
                continue;
            }
            func_0013C118(h);
            ch->state = 6;
            func_0013C200(h, func_003A5950, &D_1A3170[i]);
            D_1A30B0_003A4688.ch[i].i4C = D_1A30B0_003A4688.ch[i].b13;
            continue;
        }
        if (k & 0x10) {
            func_0013C200(h, func_003A5950, &D_1A3170[i]);
            D_1A30B0_003A4688.ch[i].i4C = D_1A30B0_003A4688.ch[i].b13;
            continue;
        }
        pan = 0;
        pitch = 0;
        i14 = ch->i14;
        flags = 1;
        if ((k & 2) && !(ch->flags & 0x100)) {
            pan = func_003A4228(ch, &ch->pos);
            flags = 7;
        }
        if (act[i] & 4) {
            flags |= 8;
            pitch = func_0013D1E8((s32)(dop[i] * ((ch->flags & 2) ? 500.0f : 300.0f)));
        }
        if (i14 != 0) {
            flags |= 0x10;
        }
        if (ch->pitch != 0) {
            pitch += ch->pitch;
            flags |= 8;
        }
        if (has_x != 0 && !(ch->def->b19 & 8)) {
            flags |= 8;
            pitch -= 0x5F4;
        }
        if (ch->state != 7) {
            v = vol[i];
            if (v > 0x400) {
                v = 0x400;
            }
            func_0013C2C0(h, flags, v, pan, pitch, i14, func_003A5950, &D_1A3170[i]);
            D_1A30B0_003A4688.ch[i].i4C = D_1A30B0_003A4688.ch[i].b13;
            continue;
        }
        if (ch->def == 0 || D_1A30B0_003A4688.snd[ch->def->i1C] == -1 || D_1A30B0_003A4688.snd[ch->def->i1C] == 0) {
            ch->obj = 0;
            ch->i40 = 0;
            ch->state = 0;
            continue;
        }
        ch->state = 1;
        v = vol[i];
        if (v > 0x400) {
            v = 0x400;
        }
        func_0013C0B8(D_1A30B0_003A4688.snd[ch->def->i1C], ch->def->h1A, v, pan, pitch, i14, func_003A5908, &D_1A3170[i]);
    }
    func_003A2330();
    func_0013CA28();
    func_0013B620();
    func_0013CA20();
    D_1A30B0_003A4688.i1B20 = 0;
    D_1A30B0_003A4688.i44 = 0;
    return 0;
}
