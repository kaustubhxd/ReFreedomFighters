// batch294.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: two leaves that call exe table helper 0x5003d0.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot1_294)(u8 *, u32);

// Exe helper 0x5003d0 (thiscall, one stack argument, ret 4): table lookup, returns a pointer to a dword. Runs as original code.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// 0x508070(this, a) (ret 4): p = ext_5003d0([a+4], 0); obj = [this+0x18]; obj.vtbl[0x610]([p]). GUESS.
static void THISCALL forwardTable_508070(u8 *self, u32 a) {
    u8 *table = *(u8 **)(a + 4);
    u32 *p = (u32 *)ext_5003d0(table, 0u);
    u8 *obj = *(u8 **)(self + 0x18);
    ((Slot1_294)(*(void ***)obj)[0x610 / 4])(obj, *p);
}
PCREG(508070, forwardTable_508070);

// 0x519d70(this, a) (ret 4): p = ext_5003d0([a+4], 0); [[this+0x14] + 0x11f] = ([p] != 0) as a dword. GUESS.
static void THISCALL flagTable_519d70(u8 *self, u32 a) {
    u8 *table = *(u8 **)(a + 4);
    u32 *p = (u32 *)ext_5003d0(table, 0u);
    u32 nz = (*p != 0u) ? 1u : 0u;
    u8 *obj = *(u8 **)(self + 0x14);
    *(u32 *)(obj + 0x11f) = nz;
}
PCREG(519d70, flagTable_519d70);
