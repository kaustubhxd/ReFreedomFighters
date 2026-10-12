#include "ff.h"
// batch953.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): sixteen more trivial thiscall leaves. Field reads and constant stores
// from the PC bytes; 0x432620 returns a float in st0 (fld); 0x459c00 and 0x44a6f0 are tail jumps through a vtable slot (modelled as a
// call that returns the target's eax; the spec's targets take no stack arguments, so the stack effect is the same).

typedef u32(THISCALL *tc0)(u8 *);

static u32 THISCALL zg432550(u8 *self) { return *(u8 *)(self + 0xfe); }        // mov al,[ecx+0xfe]
static u32 THISCALL zg4325e0(u8 *self) { return *(u32 *)(self + 0xf8); }      // mov eax,[ecx+0xf8]
static u32 THISCALL zg4325f0(u8 *self) { return *(u32 *)(self + 0xec); }      // mov eax,[ecx+0xec]
static u32 THISCALL zg432600(u8 *self) { return *(u32 *)(self + 0xe8); }      // mov eax,[ecx+0xe8]
static u32 THISCALL zg432610(u8 *self) { return *(u32 *)(self + 0xf0); }      // mov eax,[ecx+0xf0]
static float THISCALL zg432620(u8 *self) { return *(float *)(self + 0xe4); }  // fld dword ptr [ecx+0xe4]
static u32 THISCALL zg432640(u8 *self) { return *(u8 *)(self + 0x100); }      // mov al,[ecx+0x100]
static void THISCALL zg43cfb0(u8 *self) { *(u32 *)self = 0x67c15c; }          // mov [ecx],0x67c15c
static void THISCALL zg441bf0(u8 *self) { *(u32 *)self = 0x67d108; }          // mov [ecx],0x67d108
static u32 THISCALL zg444af0(u8 *self) { return *(u32 *)(self + 0xb0); }      // mov eax,[ecx+0xb0]
static u32 THISCALL zg4450a0(u8 *self) { return *(u32 *)(self + 0xac); }      // mov eax,[ecx+0xac]
static void THISCALL zg460c30(u8 *self) { *(u32 *)self = 0x685294; }          // mov [ecx],0x685294
static void THISCALL zg42d950(u8 *self) { *(u8 *)(self + 0x9b7) = 1; }        // mov byte [ecx+0x9b7],1
static void THISCALL zg42fdf0(u8 *self) { *(u8 *)(self + 0x9b7) = 0; }        // mov byte [ecx+0x9b7],0
static u32 THISCALL zg459c00(u8 *self) {                                       // mov eax,[ecx]; jmp [eax+0x154]
  return ((tc0)(*(u32 *)(*(u32 *)self + 0x154)))(self);
}
static u32 THISCALL zg44a6f0(u8 *self) {                                       // mov ecx,[ecx+0x18]; mov eax,[ecx]; jmp [eax+0x14]
  u8 *o = *(u8 **)(self + 0x18);
  return ((tc0)(*(u32 *)(*(u32 *)o + 0x14)))(o);
}

PCREG(432550, zg432550);
PCREG(4325e0, zg4325e0);
PCREG(4325f0, zg4325f0);
PCREG(432600, zg432600);
PCREG(432610, zg432610);
PCREG(432620, zg432620);
PCREG(432640, zg432640);
PCREG(43cfb0, zg43cfb0);
PCREG(441bf0, zg441bf0);
PCREG(444af0, zg444af0);
PCREG(4450a0, zg4450a0);
PCREG(460c30, zg460c30);
PCREG(42d950, zg42d950);
PCREG(42fdf0, zg42fdf0);
PCREG(459c00, zg459c00);
PCREG(44a6f0, zg44a6f0);
