// batch272.cpp - unclaimed area 67, gap band 0x5e1000-0x601000 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f2110, thiscall, plain ret: returns 0x6b8498.
static u32 THISCALL constPtr6b8498(u8 *self) { (void)self; return 0x6b8498u; }
PCREG(5f2110, constPtr6b8498);

// 0x5f0370, thiscall, plain ret: stores 0x6b823c at [this].
static void THISCALL setVtable6b823c(u8 *self) { *(u32 *)self = 0x6b823cu; }
PCREG(5f0370, setVtable6b823c);

// 0x5f1420, thiscall, plain ret: stores 0x6b84a8 at [this].
static void THISCALL setVtable6b84a8(u8 *self) { *(u32 *)self = 0x6b84a8u; }
PCREG(5f1420, setVtable6b84a8);

// 0x5f49d0, thiscall, plain ret: returns the dword at [this+0x82].
static u32 THISCALL readAt82(u8 *selfP) { return rdw((u32)(unsigned long)selfP, 0x82); }
PCREG(5f49d0, readAt82);
