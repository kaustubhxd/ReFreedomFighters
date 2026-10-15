#include "ff.h"
// batch1517.cpp - unclaimed-15 claim 17 (docs/20-unclaimed-15.md): ZFFHERO::~ZFFHERO() (0x58b5a0). Name from the GC name map
// (medium). Thiscall, no arguments. The exe's SEH frame (fs:[0]) is stack state and is not ported.
// Stubbed in the harness: 0x634273 (cdecl, (p, size)), 0x45fa70 (thiscall, two args), 0x4cbec0 and 0x480ff0 (thiscall, none).

typedef u32(THISCALL *SlotA)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);
typedef u32(THISCALL *Slot4)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32(THISCALL *Slot2b)(u8 *self, u32 a0, u32 a1);

extern "C" void ext_634273(u8 *p, u32 size);                    // cdecl delete, stubbed
extern "C" void THISCALL ext_45fa70(u8 *self, u32 a0, u32 a1, u32 a2);  // stubbed, three arguments (ret 0xc)
extern "C" void THISCALL ext_4cbec0(u8 *self);                  // stubbed
extern "C" void THISCALL ext_480ff0(u8 *self);                  // stubbed

// 0x58b5a0, ZFFHERO::~ZFFHERO() (medium).
static void THISCALL zffHeroDtor(u8 *self) {
  u32 p54 = *(u32 *)(self + 0x54);
  *(u32 *)self = 0x6ac060;
  if (p54)
    ext_634273((u8 *)p54, 0x18);
  u8 *rm = *(u8 **)0x70039c;
  u8 *sub = *(u8 **)(rm + 0x9b);
  u32 x = ((SlotA)*(u32 *)(*(u32 *)sub + 0x138))(sub);
  u32 local = 0;
  ((Slot2)*(u32 *)(*(u32 *)x + 0x88))((u8 *)x, 0x68f75c, (u32)&local);
  u32 edi = local;
  u32 r4c = ((SlotA)*(u32 *)(*(u32 *)sub + 0x4c))(sub);
  // RegisterZMsg (slot +0x114) takes four arguments (ret 0x10). The exe pushes two more values first (ebx and r4c); they
  // stay on the stack and are taken by the next calls: 0x45fa70 (three arguments: edi, r16, r4c) and then slot +0x1a8
  // (two arguments: the dword at +0xee4, ebx).
  u32 r16 = (u16)((Slot4)*(u32 *)(*(u32 *)sub + 0x114))(sub, 0x68f788, 0, 0x6ac6d0, 0x107);
  ext_45fa70(self, edi, r16, r4c);
  ((Slot2b)*(u32 *)(*(u32 *)rm + 0x1a8))(rm, *(u32 *)(self + 0xee4), (u32)self);
  u8 *o = *(u8 **)(self + 0xee4);
  if (o)
    ((Slot1)*(u32 *)(*(u32 *)o + 0))(o, 1);
  ext_4cbec0(self + 0x698);
  ext_480ff0(self);
}
PCREG(58b5a0, zffHeroDtor);
