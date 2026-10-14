// u18_06.cpp - area 18, group 6 (unclaimed-18 thread): forwarding wrappers over vtable slots.
#include "ff.h"

// 0x4f5850, ZFRAME::Load3() (GC map high). thiscall, no args. The exe tail-jumps to vtable slot 0x27c of this; the
// slot's result is returned unchanged (EAX).
static u32 THISCALL frameLoad3(u8 *self) { return vcall<u32>(self, 0x27c); }
PCREG(4f5850, frameLoad3);

// 0x5f3310, SaveSerialInfo_t::saveuint32(unsigned int) (GC map medium). thiscall, one stack arg (ret 4). The exe
// tail-jumps to slot 0x3c of the object at +0x15 with the same argument (the callee pops it).
static u32 THISCALL saveSerialInfoSaveUint32(u8 *self, u32 value) {
  return vcall<u32>(*(void **)(self + 0x15), 0x3c, value);
}
PCREG(5f3310, saveSerialInfoSaveUint32);

// 0x4f6390, ZTTFONT::ContainsChar(unsigned int) const (GC map high). thiscall, one stack arg (ret 4); returns
// (the slot 0x280 result != 0) in AL.
static bool THISCALL ttfontContainsChar(u8 *self, u32 ch) { return vcall<u32>(self, 0x280, ch) != 0; }
PCREG(4f6390, ttfontContainsChar);

// 0x4c7310, CRootGroup::End() (GC map medium). thiscall, void. The engine object at sys+0x1907, when set, gets slot 0x14
// with the name "RootControl" (a string from the exe). `this` is not used.
static void THISCALL rootGroupEnd(u8 *self) {
  (void)self;
  u8 *sys = G(u8 *, 0x70039c);
  void *obj = *(void **)(sys + 0x1907);
  if (obj)
    vcall<void>(obj, 0x14, (const char *)0x694c38);
}
PCREG(4c7310, rootGroupEnd);
