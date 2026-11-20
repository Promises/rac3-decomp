#include "common.h"

/* localdecomp:start func_L04_004BAD40 */
typedef struct {
    u8 used;
    s8 b1;
    s8 b2;
    s8 b3;
    u16 id;
    s16 pad6;
    s32 w8;
    s32 wC;
    u32 w10;
    s32 w14;
    s32 w18;
    u8 rest[0x44];
} Slot_L04_004BAD40;

extern Slot_L04_004BAD40 D_L04_00239370[];
extern u16 D_L04_001D96B6;

static inline void func_L04_004BAD40_init(Slot_L04_004BAD40 *s) {
    s->b1 = -1;
    s->b2 = -1;
    s->b3 = -1;
    s->id = 0xFFFF;
    s->w10 = 0xFFFFFFFF;
    s->wC = 0;
    s->w8 = 0;
    s->w14 = 0;
    s->w18 = -1;
}

Slot_L04_004BAD40 *func_L04_004BAD40(void) {
    u16 i;
    Slot_L04_004BAD40 *s;

    i = 0;
    while (D_L04_00239370[i].used != 0 && i < 12) {
        i++;
    }
    if (i == 12) {
        return 0;
    }
    func_L04_004BAD40_init(&D_L04_00239370[i]);
    s = &D_L04_00239370[i];
    s->id = D_L04_001D96B6++;
    s->used = 1;
    return s;
}
/* localdecomp:end func_L04_004BAD40 */
