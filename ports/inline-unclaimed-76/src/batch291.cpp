// batch291.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 logger-using function 0x438eb0 (ret 4).
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot2_438eb0)(u8 *, u32, u32);
typedef void (__attribute__((cdecl)) *Log2_438eb0)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *Slot0_438eb0)(u8 *);

// Exe helpers (run as original code): 0x439670 (thiscall, no arguments, returns al), 0x438e30 (thiscall, no arguments, returns al).
extern "C" u8 THISCALL ext_439670(u8 *self);
extern "C" u8 THISCALL ext_438e30(u8 *self);

// 0x438eb0(a) (ret 4; ECX unused). If a is null: obj = logger.vtbl[0x20](0x67a850, 0x6d2) with the logger at 0x700390
// (thiscall, two arguments), then obj.vtbl[0x2c](obj, 0x67a8f8) as a cdecl call; returns 0. Else bl = byte [a+0xc]:
// return 0 if bl is zero; edi = [a]; if edi != 3, bl &= ext_439670([a+8]); return 0 if bl is zero; if edi == 0 return
// byte [a+0x2d]; if edi == 1 return ext_438e30(a); else return 0. GUESS: a status query that logs when given null.
static u8 THISCALL statusOf_438eb0(u8 *unusedEcx, u32 a) {
    (void)unusedEcx;
    if (a == 0u) {
        u8 *lg = G(u8 *, 0x700390);
        u8 *obj = (u8 *)((Slot2_438eb0)(*(void ***)lg)[0x20 / 4])(lg, 0x67a850u, 0x6d2u);
        ((Log2_438eb0)(*(void ***)obj)[0x2c / 4])(obj, 0x67a8f8u);
        return 0;
    }
    u8 *o = (u8 *)a;
    u8 bl = o[0xc];
    if (bl == 0) return 0;
    u32 edi = *(u32 *)o;
    if (edi != 3u) {
        bl &= ext_439670(*(u8 **)(o + 8));
    }
    if (bl == 0) return 0;
    if (edi == 0u) return o[0x2d];
    if (edi == 1u) return ext_438e30(o);
    return 0;
}
PCREG(438eb0, statusOf_438eb0);
