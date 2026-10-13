// batch69.cpp - unclaimed-68 batch 69 (slice floor(addr/16) mod 20 = 7): trivial leaves (names GUESS, FUN_addr).
#include "ff.h"

// 0x4f0030: lea eax,[ecx+0x3e]; ret
static u32 THISCALL g4f0030(u8 *self) { return (u32)(self + 0x3e); }
PCREG(4f0030, g4f0030);

// 0x54bbb0: lea eax,[ecx+0x14]; ret
static u32 THISCALL g54bbb0(u8 *self) { return (u32)(self + 0x14); }
PCREG(54bbb0, g54bbb0);

// 0x5acff0: lea eax,[ecx+0x48]; ret
static u32 THISCALL g5acff0(u8 *self) { return (u32)(self + 0x48); }
PCREG(5acff0, g5acff0);

// 0x4c8df0: mov byte ptr [ecx+0x58],0; ret
static void THISCALL g4c8df0(u8 *self) { self[0x58] = 0; }
PCREG(4c8df0, g4c8df0);

// 0x4e3330: xor eax,eax; ret 0x10 (four stack arguments, ignored)
static u32 THISCALL g4e3330(u8 *self, u32 a, u32 b, u32 c, u32 d) { (void)self; (void)a; (void)b; (void)c; (void)d; return 0; }
PCREG(4e3330, g4e3330);

// 0x65c9f0: mov eax,[ecx]; mov eax,[eax]; ret  (the first dword of the object's vtable)
static u32 THISCALL g65c9f0(u8 *self) { return *(u32 *)(*(u8 **)self); }
PCREG(65c9f0, g65c9f0);

// Constant returns (ecx ignored): 0x50a430, 0x50b5b0, 0x51b5f0, 0x615eb0, 0x63daf0, 0x63ec70, 0x64c730
static u32 THISCALL g50a430(u8 *self) { (void)self; return 0x69c768u; }
PCREG(50a430, g50a430);
static u32 THISCALL g50b5b0(u8 *self) { (void)self; return 0x69c770u; }
PCREG(50b5b0, g50b5b0);
static u32 THISCALL g51b5f0(u8 *self) { (void)self; return 0x69f484u; }
PCREG(51b5f0, g51b5f0);
static u32 THISCALL g615eb0(u8 *self) { (void)self; return 0x138u; }
PCREG(615eb0, g615eb0);
static u32 THISCALL g63daf0(u8 *self) { (void)self; return 0x40u; }
PCREG(63daf0, g63daf0);
static u32 THISCALL g63ec70(u8 *self) { (void)self; return 0x3fu; }
PCREG(63ec70, g63ec70);
static u32 THISCALL g64c730(u8 *self) { (void)self; return 0x22u; }
PCREG(64c730, g64c730);
