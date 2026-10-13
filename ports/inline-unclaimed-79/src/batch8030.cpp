#include "ff.h"
// batch8030.cpp - residue 18 unported list (docs/20-unclaimed-79.md). Names GUESS (no GC name).

extern "C" u32 ext_61f590(u32 a);   // cdecl helper, stubbed in spec

// 0x638ce0 (GUESS): thiscall, returns the dword at this+0x20.
static u32 THISCALL f_638ce0(u8 *self) { return *(u32 *)(self + 0x20); }
PCREG(638ce0, f_638ce0);

// 0x64b160 (GUESS): returns 0x20.
static u32 THISCALL f_64b160(u8 *self) { (void)self; return 0x20; }
PCREG(64b160, f_64b160);

// 0x64fc60 (GUESS): thiscall, returns the dword at this+0x88.
static u32 THISCALL f_64fc60(u8 *self) { return *(u32 *)(self + 0x88); }
PCREG(64fc60, f_64fc60);

// 0x446d60 (GUESS): thiscall (ret 4), stores its argument at this+0x1c.
static void THISCALL f_446d60(u8 *self, u32 a) { *(u32 *)(self + 0x1c) = a; }
PCREG(446d60, f_446d60);

// 0x5f3fa0 (GUESS): stdcall (ret 4), calls slot +0x28 of its argument.
static void STDCALL f_5f3fa0(u32 p) { vcall<void>((u8 *)(unsigned long)p, 0x28); }
PCREG(5f3fa0, f_5f3fa0);

// 0x61bbe0 (GUESS): thiscall, returns the eax of the cdecl call 0x61f590 with the dword at this+4.
static u32 THISCALL f_61bbe0(u8 *self) { return ext_61f590(*(u32 *)(self + 0x4)); }
PCREG(61bbe0, f_61bbe0);

// 0x594fa0 (GUESS): thiscall (ret 4), stores its byte argument at this+0x828.
static void THISCALL f_594fa0(u8 *self, u32 a) { *(u8 *)(self + 0x828) = (u8)a; }
PCREG(594fa0, f_594fa0);
