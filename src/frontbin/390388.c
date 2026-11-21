#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00392260(s32, long, long);
extern void func_00392290(void);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0038E548_00390388(u8 *, s32, f32);
extern void func_0038E7E8_00390388(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
/* localdecomp:start func_00390388 */
extern s32 D_001D5B94;
extern u8 D_001D5B41;
__asm__(".extern D_001D5B41, 1");
extern s32 D_001D5B48[2];
__asm__(".extern D_001D5B48, 8");
extern s32 D_001D5B5C[];
extern s32 *D_001D55C4[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0038E0A8(u8 *p, s32 off, s32 *out);
extern s32 func_0038E548_00390388(u8 *, s32, f32);
extern void func_0038E7E8_00390388(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_00390388(B_38BB50 *b, long ca, u8 **strs, s32 n, s16 sel, long cb, s32 *outx, s32 *outy, f32 scale) {
    s16 starts[80];
    s16 ends[80];
    s16 colors[80];
    u8 *lines[80];
    s32 c1, c2;
    s32 lim;
    s32 first;
    s32 nlines;
    s32 j;
    f32 quarter, width;

    if (D_001D5B94 != 1 && !(b->h12 & 0x10)) {
        func_003A9500(b->h4, b->h6 - 1, b->h0, b->h2 - 1);
    }
    first = 1;
    D_001D5B41 = 1;
    lim = -1;
    quarter = scale * 0.25f;
    if (((u8)b->h12 ^ 1) & 1) {
        width = (f32)(b->h6 - b->h8);
    } else {
        s32 r = b->h6 - b->h8;
        s32 l = b->h8 - b->h4;
        if (r < l) l = r;
        width = (f32)l;
        width *= 2.0f;
    }
    j = 0;
    do {
        nlines = 0;
        for (; j < n; j++) {
            u8 *s = strs[j];
            s32 pos = 0;
            while (s[pos] != 0 && nlines < 0x4F) {
                s32 k = nlines;
                s32 brk;
                f32 w;
                lines[k] = s;
                starts[k] = pos;
                {
                    s16 *cp = colors + k;
                    if (sel < 0 || sel != j) *cp = 0;
                    else *cp = 5;
                }
                w = 0.0f;
                brk = pos;
                while (w < width) {
                    u8 c = s[pos];
                    if (c == 0x20 || c < 0x10 || c == 0x2F) brk = pos;
                    if (s[pos] < 2) break;
                    pos += func_0038E0A8(s, pos, &c1);
                    {
                        G_38BB50 *g = (G_38BB50 *)(c1 * 8 + (u32)D_001D55C4[0]);
                        if (g->w1 & 0x1F800000) {
                            f32 f = (f32)(s32)(((g->w0 >> 25) + 2) & 0xFC) * quarter;
                            if (first) first = 0;
                            else w -= f;
                            w += (f32)((((G_38BB50 *)D_001D55C4[0])[c1].w1 >> 23) & 0x3F) * scale;
                            func_0038E0A8(s, pos + 1, &c2);
                            if (c2 >= 0x10) {
                                w += (f32)(((((G_38BB50 *)D_001D55C4[0])[c1].w1 >> 29) + 2) & 0xFC) * 0.25f * scale;
                            }
                        }
                    }
                    pos++;
                }
                ends[k] = brk;
                if ((s16)brk == starts[k]) ends[k] = pos;
                pos = ends[k];
                if (s[pos] == 0x20 || s[pos] < 0x10) ends[k]--;
                nlines++;
                if (s[pos] == 0) break;
                pos++;
                if (pos == lim) break;
            }
        }
    } while (0);
    {
        s32 y, i;
        {
            s32 t = nlines * b->h10;
            b->hC = 0;
            b->hE = t;
            y = b->hA;
            if (b->h12 & 2) y -= t >> 1;
        }
        for (i = 0; i < nlines; i++) {
            if (y + b->h10 >= b->h0 && b->h2 >= y) {
                s32 len = ends[i] - starts[i] + 1;
                s32 wpx;
                if (lim > 0 && lim < len) len = lim;
                wpx = func_0038E548_00390388(lines[i] + starts[i], len, 1.0f);
                if (b->hC < wpx) b->hC = wpx;
                if (!(b->h12 & 4)) {
                    u16 fl;
                    D_001D5B48[0] = ca;
                    D_001D5B5C[0] = cb;
                    fl = b->h12;
                    if (fl & 8) {
                        f32 x, yy;
                        u16 hx;
                        if (fl & 1) {
                            x = (f32)(b->h8 - (wpx >> 1)) + (f32)b->h14 * 0.0625f;
                            hx = b->h8;
                        } else {
                            x = (f32)b->h8 + (f32)b->h14 * 0.0625f;
                            hx = b->h8;
                        }
                        yy = (f32)y + (f32)b->h16 * 0.0625f;
                        if (colors[i] == 5) {
                            *outx = (s16)hx;
                            *outy = (s32)yy + (s32)((f32)b->h10 * 0.5f - 0.5f);
                        }
                        func_0038E7E8_00390388(x, yy, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                    } else {
                        if (fl & 1) {
                            func_0038E7E8_00390388((f32)(b->h8 - (wpx >> 1)), (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        } else {
                            func_0038E7E8_00390388((f32)b->h8, (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        }
                        if (colors[i] == 5) {
                            *outx = b->h8;
                            *outy = y + (s32)((f32)b->h10 * 0.5f - 0.5f);
                        }
                    }
                }
                if (lim > 0) {
                    lim -= len;
                    if (lim <= 0) break;
                }
            }
            y += b->h10;
        }
    }
    D_001D5B41 = 0;
    if (D_001D5B94 != 1 && !(b->h12 & 0x10)) {
        func_003A9500(0, D_001D4BC0[0] - 1, 0, D_001D4BC4[0] - 1);
    }
}
/* localdecomp:end func_00390388 */

/* localdecomp:start func_00390BF8 */
extern void func_0038E548_00390BF8();
f32 func_00390BF8(s32 a, s32 unused, s32 c, f32 f) {
    f32 r = 1.0f;
    s32 t;
    if (a) t = ((s32 (*)(f32))func_0038E548_00390BF8)(1.0f); else t = 0;
    if (c < t) {
        r = (f32)c / (f32)t;
        if (r < f) r = f;
    }
    return r;
}
/* localdecomp:end func_00390BF8 */

/* localdecomp:start func_00390C88 */
extern void func_0038E1E8(void);

void func_00390C88(void) {
    func_0038E1E8();
}
/* localdecomp:end func_00390C88 */

/* localdecomp:start func_00390CA8 */
extern void func_0038E3C0();

void func_00390CA8(void) {
    func_0038E3C0(1);
}
/* localdecomp:end func_00390CA8 */

/* localdecomp:start func_00390CC8 */
extern void func_0038E3C0();
 
void func_00390CC8(void) {
    func_0038E3C0(0);
}
/* localdecomp:end func_00390CC8 */

LINKER_REMNANT("asm/remnants", func_00390CE8);

/* localdecomp:start func_00390D20 */
extern void func_0038E548_00390D20();

void func_00390D20(void) {
    func_0038E548_00390D20();
}
/* localdecomp:end func_00390D20 */

LINKER_REMNANT("asm/remnants", func_00390D40);

/* localdecomp:start func_00390D48 */
extern void func_0038E548_00390D48();
 
void func_00390D48(void) {
    func_0038E548_00390D48();
}
/* localdecomp:end func_00390D48 */

LINKER_REMNANT("asm/remnants", func_00390D68);

/* localdecomp:start func_00390D70 */
extern void func_0038E548_00390D70();
 
void func_00390D70(s32 a, s32 b, s32 c, f32 d) {
    func_0038E548_00390D70();
}
/* localdecomp:end func_00390D70 */

LINKER_REMNANT("asm/remnants", func_00390D90);

/* localdecomp:start func_00390DB8 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern void func_0038E548_00390DB8();
s32 func_00390DB8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    ((void (*)(float, float, float, float, float, float, s32, s32, s32, s32, s32, unsigned long))func_0038E7E8)((float)a0, (float)a1, 1.0f, 1.0f, 0.0f, 0.0f, a2, a3, a4, 1, 0, 0x80000000UL);
    return a0 - (((s32 (*)(s32, s32, float))func_0038E548_00390DB8)(a3, a4, 1.0f) >> 1);
}
/* localdecomp:end func_00390DB8 */

/* localdecomp:start func_00390E60 */
extern s32 D_001D55E8;
extern void func_0038E150(s32);
extern void func_0038E7E8_00390E60(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_0038E548_00390E60(s32, s32, f32);
s32 func_00390E60(s32 x, s32 y, s32 a, s32 b, s32 c) {
    s32 saved;
    saved = D_001D55E8;
    func_0038E150(1);
    func_0038E7E8_00390E60(a, b, c, 1, 0, 0x80000000UL, (f32)x, (f32)y, 1.0f, 1.0f, 0.0f, 0.0f);
    x -= func_0038E548_00390E60(b, c, 1.0f) >> 1;
    func_0038E150(saved);
    return x;
}
/* localdecomp:end func_00390E60 */

LINKER_REMNANT("asm/remnants", func_00390F40);

/* localdecomp:start func_00390F50 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00390F50(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 p) {
    func_0038E7E8((f32)a0, (f32)a1, p, p, a2, a3, a4, 1, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00390F50 */

/* localdecomp:start func_00390FB0 */
__asm__(".extern D_001D55E8, 4");
extern s32 D_001D55E8;
extern void func_0038E150(s32);
void func_00390FB0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_001D55E8;
    func_0038E150(1);
    ((void (*)(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32))func_0038E7E8)(c, d, e, 0, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_0038E150(save);
}
/* localdecomp:end func_00390FB0 */

LINKER_REMNANT("asm/remnants", func_00391068);

/* localdecomp:start func_00391078 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00391078(s32 a0, s32 a1, s32 a2, f32 x, f32 y, f32 z) {
    func_0038E7E8(x, y, z, z, a0, a1, a2, 0, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00391078 */

LINKER_REMNANT("asm/remnants", func_003910B0);

/* localdecomp:start func_003910C0 */
void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    func_0038F9E0(p, a, b, c, d, e, f, g, h);
}
/* localdecomp:end func_003910C0 */

/* PAL candidate for func_003910E0 (US draft of func_0038C8A8).
   The called helper is PAL's func_0038FA18 (the US func_0038B1E8), which lives in
   this same source file (src/frontbin/38DED0.c). */


/* localdecomp:start func_003910E0 */
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_003910E0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FA18(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_003910E0 */

LINKER_REMNANT("asm/remnants", func_00391110);

/* Candidate for func_00391130 (frontbin, PAL).
   US draft of rac3-uya-decomp func_0038C8F8; the US callee func_0038B1E8 is
   func_0038FA18 in PAL (same file, still INCLUDE_ASM there), so the call
   target changes with the symbol. */

/* localdecomp:start func_00391130 */
extern s32 D_001D55E8;
extern void func_0038E150(s32);
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_00391130(s32 a, s32 b, s32 c, s32 d) {
    s32 old = D_001D55E8;
    func_0038E150(1);
    ((void (*)(s32, s32, s32, s32, f32, f32, unsigned long))func_0038FA18)(a, b, c, d, 1.0f, 1.0f, 0x80000000UL);
    func_0038E150(old);
}
/* localdecomp:end func_00391130 */

/* PAL version of the US draft of func_003911B8 (rac3-uya-decomp func_0038C980).
   The US callee func_0038B1E8 is func_0038FA18 in PAL. */

/* localdecomp:start func_003911B8 */
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_003911B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FA18(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_003911B8 */

LINKER_REMNANT("asm/remnants", func_003911E8);

/* US draft of func_003911F0 (rac3-uya-decomp func_0038C9B8, commit 13cf5c5), names moved to PAL addresses
   where known. The callee is the PAL func_0038FA18 (US func_0038B1E8). */


/* localdecomp:start func_003911F0 */
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_003911F0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g, s32 h, f32 x) {
    func_0038FA18(a, b, c, d, h, g, x, x);
}
/* localdecomp:end func_003911F0 */

/* localdecomp:start func_00391210 */
extern void func_00390388();
void func_00391210(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s16 g, long h, s32 x, s32 y) {
    func_00390388(a, b, c, d, g, h, x, y);
}
/* localdecomp:end func_00391210 */

/* localdecomp:start func_00391240 */
extern f32 func_00390BF8(s32, s32, s32, f32);
extern void func_0038E7E8_00391240(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
void func_00391240(s32 x, s32 y, s32 a, s32 b, s32 c, s32 d, f32 p) {
    f32 r = func_00390BF8(b, c, d, p);
    func_0038E7E8_00391240(a, b, c, (f32)x, (f32)y, r, r, 0.0f, 1, 0, 0x80000000UL, 0.0f);
}
/* localdecomp:end func_00391240 */

/* localdecomp:start func_003912E8 */
extern void func_0038DED0();
 
void func_003912E8(void) {
    func_0038DED0();
}
/* localdecomp:end func_003912E8 */

/* localdecomp:start func_00391308 */
extern f32 func_00390BF8();
 
void func_00391308(void) {
    func_00390BF8();
}
/* localdecomp:end func_00391308 */

extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00391328);

/* localdecomp:start func_00391398 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_00391398(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_00391398 */

LINKER_REMNANT("asm/remnants", func_00391400);

extern s32 D_001D4D08_00391408;
extern s32 D_001D4D0C_00391408;
/* localdecomp:start func_00391408 */
extern void func_00391398(void);
void func_00391408(s32 dx, s32 dy, s32 clamp) {
    D_001D4D08_00391408 += dx; D_001D4D0C_00391408 += dy; if (clamp) { s32 x = D_001D4D08_00391408 >= 0 ? D_001D4D08_00391408 : 0; s32 y = D_001D4D0C_00391408 >= 0 ? D_001D4D0C_00391408 : 0; D_001D4D08_00391408 = x <= 3000 ? x : 3000; D_001D4D0C_00391408 = y <= 450 ? y : 450; }
    func_00391398();
}
/* localdecomp:end func_00391408 */

LINKER_REMNANT("asm/remnants", func_00391490);

typedef struct {
    u8 p0[0x150];
    s16 h150, h152, h154, h156, h158, h15A;
} E_38CC68;
extern unsigned long D_001D0560[];
extern E_38CC68 *D_001D4CF8_003914A0;
extern u8 D_001439FD[];
extern s32 D_001D5520;
INCLUDE_ASM("asm/nonmatchings/text", func_003914A0);

typedef int Q_38CE40 __attribute__((mode(TI)));
typedef struct { unsigned long v : 9; unsigned long r : 55; } FB_38CE40;
typedef struct {
    unsigned long dx : 12;
    unsigned long dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long p0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long p1 : 9;
} DI_38CE40;
typedef struct {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long p0 : 16;
    unsigned long id : 14;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs0 : 4;
    unsigned long regs : 60;
} GT_38CE40;
typedef struct {
    u8 p0[0x10];
    FB_38CE40 q10;
    DI_38CE40 q18;
    u8 p20[0x10];
    GT_38CE40 t30;
    FB_38CE40 q40;
    unsigned long q48;
    unsigned long q50;
    u8 p58[0x68];
    GT_38CE40 tC0;
    FB_38CE40 qD0;
    unsigned long qD8;
    unsigned long qE0;
    u8 pE8[0x68];
    s16 h150, h152, h154, h156, h158, h15A, h15C, h15E;
    s16 h160, h162, h164, h166, h168, h16A, h16C, h16E;
    s32 w170;
} E_38CE40;
extern E_38CE40 D_001CFEC0_00391678[];
extern E_38CE40 *D_001D4CF8_00391678;
extern s32 D_001A1ED0_00391678[];
extern s32 D_001D5520;
extern u8 D_001D551D;
extern s32 D_001D4D08_00391678;
extern s32 D_001D4D0C_00391678;
extern s32 D_001D4D10_00391678;
extern s32 D_001D4D14_00391678;
extern s32 D_001D4D18_00391678;
extern s32 D_001D4D1C_00391678;
extern s32 D_001D4D20_00391678;
extern s32 D_001D4D24_00391678;
extern s32 D_001D4D28_00391678;
extern s32 D_001D4D2C_00391678;
extern s32 D_001D4D30_00391678;
extern s32 D_001D4D34_00391678;
extern unsigned long D_001D02D0_00391678[];
extern unsigned long D_001D0070_00391678[];
extern unsigned long D_001D07B0_00391678[];
extern unsigned long D_001D0900_00391678[];
extern unsigned long D_00141850_00391678[];
extern unsigned long D_00141990_00391678[];
extern unsigned long D_00141AD0_00391678[];
extern unsigned long D_00141DC0_00391678[];
extern unsigned long D_001420B0_00391678[];
extern void func_0012C138(void *, s32, s16, s16, s16, s16);
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
extern void func_003914A0(s32, s32);
extern void func_0038CC88();
extern void func_11F0A0(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00391678);

extern unsigned long D_001D07E8[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392260);

LINKER_REMNANT("asm/remnants", func_00392288);

/* localdecomp:start func_00392290 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_00392290(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_00392290 */
