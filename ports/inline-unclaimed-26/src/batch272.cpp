// batch272.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice 5 (claimed here).
#include "ff.h"

typedef void (__attribute__((thiscall)) *Slot1_45fc90)(u8 *, u32);

// Exe allocator 0x41e290 (cdecl, one argument, returns the block). Runs as original code (the spec stubs it).
extern "C" u8 *ext_41e290(u32 size);

// 0x45fc90: engine = [0x70039c]; o = engine+0x9b; o.vtbl[0x130](o, this+4). v = dword at o+0x1c5d. If arg is at or above v,
// v is non-null, and arg is below v + (dword at v-8 & 0x1fffffff), this+4 = arg. Otherwise copies the NUL-terminated
// string at arg into a new block (ext_41e290(len + 1)) and stores that block at this+4. ret 4. GUESS: an intern helper
// that keeps strings in the pool or copies them out.
static void THISCALL internStr_45fc90(u8 *self, u32 arg) {
    u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    ((Slot1_45fc90)(*(void ***)o)[0x130 / 4])(o, *(u32 *)(self + 4));
    u32 v = *(u32 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0x1c5d);
    if (arg >= v && v != 0u) {
        u32 limit = (*(u32 *)(v - 8u) & 0x1fffffffu) + v;
        if (arg < limit) {
            *(u32 *)(self + 4) = arg;
            return;
        }
    }
    const u8 *s = (const u8 *)arg;
    u32 len = 0;
    while (s[len] != 0) len++;
    u8 *buf = ext_41e290(len + 1u);
    *(u8 **)(self + 4) = buf;
    for (u32 i = 0; i <= len; i++) buf[i] = s[i];
}
PCREG(45fc90, internStr_45fc90);
