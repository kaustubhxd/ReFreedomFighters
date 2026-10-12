// batch200.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Leaf thiscall
// getters and a field copy, all plain ret, no calls.
#include "ff.h"

// 0x4681f0, thiscall: return the dword at +0x1d6.
static u32 THISCALL getDword1d6_4681f0(u8 *self) { return *(u32 *)(self + 0x1d6); }
PCREG(4681f0, getDword1d6_4681f0);

// 0x483ef0, thiscall: eax = dword at +0x417 shifted right by 1, then al &= 1 (upper bits of eax are kept).
static u32 THISCALL getBit1_483ef0(u8 *self) { return (*(u32 *)(self + 0x417) >> 1) & 0xffffff01u; }
PCREG(483ef0, getBit1_483ef0);

// 0x5fa630, cdecl-free no-arg read of the global dword at 0x724270.
static u32 cdeclGlobal_5fa630(void) { return *(u32 *)0x724270u; }
PCREG(5fa630, cdeclGlobal_5fa630);

// 0x5b7d30, thiscall: [this+4] = [this+8].
static void THISCALL copyField8to4_5b7d30(u8 *self) { *(u32 *)(self + 4) = *(u32 *)(self + 8); }
PCREG(5b7d30, copyField8to4_5b7d30);
