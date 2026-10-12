#include "ff.h"
// batch8008.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x48db50 (GUESS): stdcall, returns its second stack argument (ret 8).
static u32 STDCALL f_48db50(u32 a0, u32 a1) { (void)a0; return a1; }
PCREG(48db50, f_48db50);

// 0x493130 (GUESS): returns 1 if the dword at this+0xbc9 is greater than 0 (cmp; setg al).
static u8 THISCALL f_493130(u8 *self) { return *(s32 *)(self + 0xbc9) > 0; }
PCREG(493130, f_493130);

// 0x49d6a0 (GUESS): stdcall, returns the dword at (stack argument)+0x8 (ret 4).
static u32 STDCALL f_49d6a0(u32 p) { return *(u32 *)(p + 0x8); }
PCREG(49d6a0, f_49d6a0);

// 0x499800 (GUESS): stdcall, stores its stack argument to the global 0x6ffa9c (ret 4).
static void STDCALL f_499800(u32 a) { G(u32, 0x6ffa9c) = a; }
PCREG(499800, f_499800);

// 0x49b380 (GUESS): stores its stack argument at (this+0xc)+0xc (ret 4).
static void THISCALL f_49b380(u8 *self, u32 a) { u8 *c = *(u8 **)(self + 0xc); *(u32 *)(c + 0xc) = a; }
PCREG(49b380, f_49b380);

// 0x49b390 (GUESS): stores its stack argument at (this+0xc)+0x8 (ret 4).
static void THISCALL f_49b390(u8 *self, u32 a) { u8 *c = *(u8 **)(self + 0xc); *(u32 *)(c + 0x8) = a; }
PCREG(49b390, f_49b390);
