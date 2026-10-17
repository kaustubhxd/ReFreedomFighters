// batch752.cpp - area 72, skipped tail-jump forwarders (2026-10-12). Virtual tail jumps are modelled as zero-arity forwards
// (GUESS: the real arity is the slot target's; a tail jump forwards the caller's own args and these thunks have no pushes).
#include "ff.h"

extern "C" void THISCALL ext_5390b0(void *self);     // ZFFSomething method (ret 0; virtual 0xa8 and 0x1bc inside)
extern "C" void THISCALL ext_43ea20(void *self);     // target of 0x4f3c30 (no visible ret; forwarded with 0 args, GUESS)

// 0x533ba0 - call 0x5390b0; mov al, 1; ret
static bool THISCALL fwd_533ba0(u8 *self) { ext_5390b0(self); return true; }
PCREG(533ba0, fwd_533ba0);
// 0x4f3c30 - mov dword ptr [ecx], 0x69909c; jmp 0x43ea20
static void THISCALL fwd_4f3c30(u8 *self) { *(u32 *)self = 0x69909c; ext_43ea20(self); }
PCREG(4f3c30, fwd_4f3c30);
// 0x4d1630 - mov eax, [ecx]; jmp [eax+8]   (GUESS arity 0)
static u32 THISCALL fwd_4d1630(u8 *self) { return vcall<u32>(self, 0x8); }
PCREG(4d1630, fwd_4d1630);
// 0x4d1e30 - mov eax, [ecx]; jmp [eax+0x3c] (GUESS arity 0)
static u32 THISCALL fwd_4d1e30(u8 *self) { return vcall<u32>(self, 0x3c); }
PCREG(4d1e30, fwd_4d1e30);
// 0x4f04d0 - mov eax, [ecx]; jmp [eax+0x158] (GUESS arity 0)
static u32 THISCALL fwd_4f04d0(u8 *self) { return vcall<u32>(self, 0x158); }
PCREG(4f04d0, fwd_4f04d0);
// 0x536640 - mov eax, [ecx]; jmp [eax+0x18c] (GUESS arity 0)
static u32 THISCALL fwd_536640(u8 *self) { return vcall<u32>(self, 0x18c); }
PCREG(536640, fwd_536640);
