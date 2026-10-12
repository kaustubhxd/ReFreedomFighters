// batch280.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 leaves from the full list.
#include "ff.h"

// 0x438c30 (no arguments, plain ret): p = [this+8]. If p is null return 0. t = [p]: if t is 3 keep p; if t is not 1
// return 0; else p = [p+8]. Returns (p != 0) ? p - 4 : 0. GUESS: a tagged-list head accessor.
static u32 THISCALL headAddr_438c30(u8 *self) {
    u32 p = *(u32 *)(self + 8);
    if (p == 0u) return 0u;
    u32 t = *(u32 *)p;
    if (t != 3u) {
        if (t != 1u) return 0u;
        p = *(u32 *)(p + 8);
    }
    return (p != 0u) ? p - 4u : 0u;
}
PCREG(438c30, headAddr_438c30);
