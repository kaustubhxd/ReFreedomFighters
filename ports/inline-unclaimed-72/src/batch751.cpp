// batch751.cpp - area 72, tail-jump forwarders with known arity (2026-10-12).
#include "ff.h"

extern "C" u32 THISCALL ext_4d9230(void *self, u32 a);      // CFastLookup2::RemoveLowerCase (ret 4)
extern "C" void THISCALL ext_4cd0e0(void *self);            // STRREFTAB::~STRREFTAB (ret 0)
extern "C" void THISCALL ext_4e66a0(void *self);            // target of 0x534cf0 (ret 0)
extern "C" void THISCALL ext_54cd00(void *self);            // vtable-store function (ret 0), target of 0x549370

// 0x4d6e70 - add ecx,4; jmp 0x4d9230
static u32 THISCALL fwd_4d6e70(u8 *self, u32 a) { return ext_4d9230(self + 4, a); }
PCREG(4d6e70, fwd_4d6e70);
// 0x59ad30 - add ecx,0x1218c; jmp 0x4cd0e0
static void THISCALL fwd_59ad30(u8 *self) { ext_4cd0e0(self + 0x1218c); }
PCREG(59ad30, fwd_59ad30);
// 0x534cf0 - mov dword ptr [ecx], 0x6a1a60; jmp 0x4e66a0
static void THISCALL fwd_534cf0(u8 *self) { *(u32 *)self = 0x6a1a60; ext_4e66a0(self); }
PCREG(534cf0, fwd_534cf0);
// 0x549370 - mov dword ptr [ecx], 0x6a3338; jmp 0x54cd00
static void THISCALL fwd_549370(u8 *self) { *(u32 *)self = 0x6a3338; ext_54cd00(self); }
PCREG(549370, fwd_549370);
