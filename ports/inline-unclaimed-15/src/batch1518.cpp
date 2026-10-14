#include "ff.h"
// batch1518.cpp - unclaimed-15 claim 18 (docs/20-unclaimed-15.md): ZFFHERO::Load2() (0x592c60). Name from the vtable map
// (core-todo residue-14). Thiscall, no arguments, ret 0. The exe's SEH frame is not used here.
// Stubbed in the harness: 0x474710, 0x592580 and 0x595100 (thiscall, no args). The render sub-object's slot +0x114 is a
// logged code stub that writes a table value through its fifth argument (the local's address).

typedef u32(THISCALL *SlotA)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);
typedef u32(THISCALL *Slot4)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32(THISCALL *Slot3)(u8 *self, u32 a0, u32 a1, u32 a2);

extern "C" void THISCALL ext_474710(u8 *self);   // stubbed
extern "C" void THISCALL ext_592580(u8 *self);   // stubbed
extern "C" void THISCALL ext_595100(u8 *self);   // stubbed

// 0x592c60, ZFFHERO::Load2() (vtable map).
static void THISCALL zffHeroLoad2(u8 *self) {
  ext_474710(self);
  u8 *vt = *(u8 **)self;
  *(u32 *)(self + 0x688) = 0;
  u8 *rm = *(u8 **)0x70039c;
  u8 *sub = *(u8 **)(rm + 0x9b);
  u32 local = 0;
  // RegisterZMsg (slot +0x114) takes four arguments (ret 0x10). The two values pushed before it (&local and 0) stay on the
  // stack and are taken by the next call, slot +0x128 (three arguments: r16, &local, 0; ret 0xc), which writes &local.
  u32 r16 = (u16)((Slot4)*(u32 *)(*(u32 *)sub + 0x114))(sub, 0x6acfa4, 0, 0x6ac6d0, 0x1204);
  ((Slot3)*(u32 *)(vt + 0x128))(self, r16, (u32)&local, 0);
  u8 *g = *(u8 **)0x70038c;
  u32 rv = ((Slot1)*(u32 *)(*(u32 *)g + 0xcc))(g, local);
  *(u32 *)(self + 0x85a) = rv;
  *(u32 *)(self + 0x85e) = 0;
  ext_592580(self);   // ecx is reloaded with this (mov ecx, edi) before this call
  ext_595100(self);
  rm = *(u8 **)0x70039c;
  sub = *(u8 **)(rm + 0x9b);
  u8 *o2 = *(u8 **)(sub + 0xadc);
  u32 x2 = ((Slot2)*(u32 *)(*(u32 *)o2 + 0x25c))(o2, 0x685f44, 0);
  if (x2) {
    u32 f = ((Slot1)*(u32 *)(*(u32 *)x2 + 0x100))((u8 *)x2, 0x6a5cf0);
    *(u32 *)(self + 0x9e8) = f;
  }
}
PCREG(592c60, zffHeroLoad2);
