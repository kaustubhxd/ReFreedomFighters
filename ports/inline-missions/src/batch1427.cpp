// batch1427.cpp - missions thread, batch 1427: ZObjectives (the objectives window): Init2, OnKeyPress, OnWindowClose.
// Layout from the code: +0x44 event sender, +0xf8 map icon object, +0x1cc +0x1d0 +0x1d4 +0x1d8 +0x1e4 window objects
// (closed by slot 0xbc with a bool), the window base class is ZBaseMap (its methods are real exe code here).
#include "missions.h"

extern "C" void THISCALL ext_562440(u8 *self);                         // CBaseWindow::Init()
extern "C" u8 THISCALL ext_574250(u8 *self, u32 key);                  // ZBaseMap::OnKeyPress(unsigned int)
extern "C" void THISCALL ext_574280(u8 *self, u32 key, u32 flag);      // ZBaseMap::OnWindowClose(unsigned int, bool)
extern "C" void THISCALL ext_5aa6e0(u8 *osd);                          // ZOnScreenDisplay::MapIconClear()

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }

// 0x577d00 ZObjectives::Init2(): CBaseWindow::Init(), then the window registers as the object named 0x6a8fe8
// (manager slot 0x4c(sender, 0x10) -> handle; registry slot 0x60(name, handle)).
static void THISCALL zobjInit2(u8 *self) {
  ext_562440(self);
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 t = vcall<u32, u32, u32>(mgr(), 0x4c, *(u32 *)(self + 0x44), 0x10);
  vcall<void, const char *, u32>(reg, 0x60, (const char *)0x6a8fe8, t);
}
PCREG(577d00, zobjInit2);

// 0x577e20 ZObjectives::OnKeyPress(unsigned int key): keys 0x102 and 0x103 go to the object from vtable slot 0x84
// (its slot 0x300, no arguments) and return 0; other keys are passed to ZBaseMap::OnKeyPress.
static u8 THISCALL zobjOnKeyPress(u8 *self, u32 key) {
  if (key == 0x102 || key == 0x103) {
    u8 *o = vcall<u8 *>(self, 0x84);
    vcall<void>(o, 0x300);
    return 0;
  }
  return ext_574250(self, key);
}
PCREG(577e20, zobjOnKeyPress);

// 0x577e60 ZObjectives::OnWindowClose(unsigned int key, bool flag): ZBaseMap::OnWindowClose(key, flag), the map icon
// is cleared (ZOnScreenDisplay::MapIconClear on [self+0xf8]), then the five window objects are told with slot 0xbc:
// [0x1e4] false, [0x1d4] false, [0x1d8] true, [0x1cc] false, [0x1d0] true. Returns 0.
static u8 THISCALL zobjOnWindowClose(u8 *self, u32 key, u32 flag) {
  ext_574280(self, key, flag);
  ext_5aa6e0(*(u8 **)(self + 0xf8));
  vcall<void, u32>(*(u8 **)(self + 0x1e4), 0xbc, 0);
  vcall<void, u32>(*(u8 **)(self + 0x1d4), 0xbc, 0);
  vcall<void, u32>(*(u8 **)(self + 0x1d8), 0xbc, 1);
  vcall<void, u32>(*(u8 **)(self + 0x1cc), 0xbc, 0);
  vcall<void, u32>(*(u8 **)(self + 0x1d0), 0xbc, 1);
  return 0;
}
PCREG(577e60, zobjOnWindowClose);
