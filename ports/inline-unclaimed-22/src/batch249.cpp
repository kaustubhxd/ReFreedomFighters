// batch249.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch249"): ZMoveOnSpline::Save.
// Name from the GameCube name map (high); behaviour from the PC bytes. The straight-line body was generated from the
// disassembly listing (scratch script) and checked call by call against it (42 calls).
#include "ff.h"

extern "C" u32 THISCALL ext_441790(u8 *self, u8 *s);            // original base Save (ret 4); al = success
extern "C" void THISCALL ext_523990(u8 *self, u8 *s);           // original (ret 4): saves the path object at +0x5c
extern "C" void THISCALL ext_4e7be0(u8 *self, u8 *s);           // original (ret 4): saves the block at +0x144
extern "C" void FASTCALL ext_511c20(u8 *s, u8 *p);              // original, fastcall (ecx = stream, edx = this + 0xda), ret

// 0x513ff0 ZMoveOnSpline::Save(ZSaveGame*) ret 4, returns al. Base save 0x441790 first (false: its eax is returned), then
// the fields below in exe order; true. Slot 0x10 takes (pointer, 4).
static u32 THISCALL moveOnSplineSave_513ff0(u8 *self, u8 *s) {
  u32 ok = ext_441790(self, s);
  if (!(u8)ok) return ok;
  ext_523990(*(u8 **)(self + 0x5c), s);
  vcall<void>(s, 0x68, (u32)(self + 0x60));
  vcall<void>(s, 0x70, (u32)(self + 0x6c));
  vcall<void>(s, 0x68, (u32)(self + 0x90));
  vcall<void>(s, 0x70, (u32)(self + 0x9c));
  vcall<void>(s, 0x4c, *(u32 *)(self + 0xc0));   // float bits
  vcall<void>(s, 0x10, (u32)(self + 0xc4), 4u);
  vcall<void>(s, 0x4c, *(u32 *)(self + 0xc8));   // float bits
  vcall<void>(s, 0x60, (u32)self[0xcc]);
  vcall<void>(s, 0x60, (u32)self[0xcd]);
  vcall<void>(s, 0x3c, *(u32 *)(self + 0xce));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0xd2));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0xd6));
  vcall<void>(s, 0x60, (u32)self[0x11e]);
  vcall<void>(s, 0x44, *(u32 *)(self + 0x11f));
  ext_511c20(s, self + 0xda);
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x123));
  vcall<void>(s, 0x6c, *(u32 *)(self + 0x127));
  vcall<void>(s, 0x6c, *(u32 *)(self + 0x12b));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x12f));
  vcall<void>(s, 0x60, (u32)self[0x133]);
  ext_4e7be0(self + 0x144, s);
  vcall<void>(s, 0x64, *(u32 *)(self + 0x159));
  vcall<void>(s, 0x68, (u32)(self + 0x15d));
  vcall<void>(s, 0x70, (u32)(self + 0x169));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x18d));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x191));
  vcall<void>(s, 0x4c, *(u32 *)(self + 0x195));   // float bits
  vcall<void>(s, 0x4c, *(u32 *)(self + 0x199));   // float bits
  vcall<void>(s, 0x70, (u32)(self + 0x19d));
  vcall<void>(s, 0x64, *(u32 *)(self + 0x1c1));
  vcall<void>(s, 0x64, *(u32 *)(self + 0x1c5));
  vcall<void>(s, 0x4c, *(u32 *)(self + 0x1c9));   // float bits
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x1d1));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x1d9));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x1dd));
  vcall<void>(s, 0x4c, *(u32 *)(self + 0x1e1));   // float bits
  vcall<void>(s, 0x44, *(u32 *)(self + 0x1e5));
  vcall<void>(s, 0x4c, *(u32 *)(self + 0x1e9));   // float bits
  vcall<void>(s, 0x6c, *(u32 *)(self + 0x1ed));
  vcall<void>(s, 0x60, (u32)self[0x215]);
  return 1;
}
PCREG(513ff0, moveOnSplineSave_513ff0);
