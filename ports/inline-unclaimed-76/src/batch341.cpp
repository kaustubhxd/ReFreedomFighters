// batch341.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x60cdf0 (stdcall, one byte argument, ret 4, returns bool; GUESS).
// old = [0x724940]; b = (old == 0). arg == 0: if old == 0 and [0x724930] != 0: [0x724930] = 0; obj = [0x724a00]; obj.vtbl[0xc8](obj, 0x1c, 0)
//   (ECX = the vtable pointer; the callee pops). Then [0x724940] = 1. arg != 0: [0x724940] = 0; if [0x724930] != 1: [0x724930] = 1 and the
//   call with (obj, 0x1c, 1). Returns b.
#include "ff.h"

typedef u32(THISCALL * slotc8_t)(u32 vt, u32 obj, u32 a, u32 b);

// The two paths differ: flag 0 loads ECX = the object and pushes the object again as the first stack word (the callee's obj, 0x1c, 0);
// flag 1 loads ECX = the vtable pointer, with the stack words (obj, 0x1c, 1).
static void callC8_arg0_60cdf0(void) {
    u32 obj = G(u32, 0x724a00u);
    u32 vt = *(u32 *)obj;
    ((slotc8_t)*(u32 *)(vt + 0xc8u))(obj, obj, 0x1cu, 0u);
}

static void callC8_arg1_60cdf0(void) {
    u32 obj = G(u32, 0x724a00u);
    u32 vt = *(u32 *)obj;
    ((slotc8_t)*(u32 *)(vt + 0xc8u))(vt, obj, 0x1cu, 1u);
}

static u8 STDCALL flag_60cdf0(u32 argWord) {
    u8 arg = (u8)argWord;
    u32 old = G(u32, 0x724940u);
    u8 b = old == 0u ? 1u : 0u;
    if (arg == 0u) {
        if (old == 0u && G(u32, 0x724930u) != 0u) {
            G(u32, 0x724930u) = 0u;
            callC8_arg0_60cdf0();
        }
        G(u32, 0x724940u) = 1u;
        return b;
    }
    G(u32, 0x724940u) = 0u;
    if (G(u32, 0x724930u) != 1u) {
        G(u32, 0x724930u) = 1u;
        callC8_arg1_60cdf0();
    }
    return b;
}
PCREG(60cdf0, flag_60cdf0);
