// batch1058.cpp - CCameraBox::Init (0x5c7db0, high confidence in the class map). Camera thread, 2026-10-11.
#include "cam.h"

#define CDECL __attribute__((cdecl))

typedef u32(THISCALL *fn_thiscall0)(void *self);

extern "C" CDECL void *ext_41e290(u32 size);                              // operator new
extern "C" THISCALL u32 ext_4dc630(void *self, u32 a1, u32 a2);          // flag update (original code)

// 0x5c7db0 CCameraBox::Init(void) (thiscall): an 8-byte block is made for +0x4c (its word at +4 is +0x48 and its
// word at +0 is the manager's handle for +0x44). An object from the manager's +0xadc is looked up (slot 0x25c);
// when there is none, a second lookup (slot 0x294) is made, its slot 0x154 runs, flags are set (0x4dc630), and its
// slot 0x124 runs. Then the block is handed to the object's slot 0x21c: the event manager at 0x70038c resolves it
// (slot 0x20 says it is known; else its function at +8 for a block in its range; else slot 0xac registers it and the
// word before the block is used).
static THISCALL void CCameraBox_Init(u8 *self) {
  u8 *p = (u8 *)ext_41e290(8);
  at<u32>(self, 0x4c) = (u32)p;
  at<u32>(p, 4) = at<u32>(self, 0x48);
  at<u32>(p, 0) = vcall<u32>(SYS9B, 0x4c, at<u32>(self, 0x44));
  u8 *obj = (u8 *)(unsigned long)vcall<u32>(at<u8 *>(SYS9B, 0xadc), 0x25c, (u32)0x6b48dc, (u32)0);
  if (!obj) {
    obj = (u8 *)(unsigned long)vcall<u32>(at<u8 *>(SYS9B, 0xadc), 0x294, (u32)0x6b48dc, (u32)0x67f610, (u32)0, (u32)1);
    vcall<void>(obj, 0x154);
    ext_4dc630(at<u8 *>(obj, 8), 0x800000u, 0u);
    vcall<void>(obj, 0x124, (u32)1, (u32)0, (u32)0, (u32)0);
  }
  p = at<u8 *>(self, 0x4c);
  if (!p) {
    vcall<void>(obj, 0x21c, (u32)0);
    return;
  }
  u8 *ev = G(u8 *, 0x70038c);
  if (vcall<u32>(ev, 0x20, p)) {
    vcall<void>(obj, 0x21c, (u32)0);
    return;
  }
  u8 *f = at<u8 *>(ev, 8);
  if (f && !(at<u32>(ev, 0xc) > (u32)(unsigned long)p) && !((u32)(unsigned long)p >= at<u32>(ev, 0x10))) {
    u32 r = ((fn_thiscall0)(unsigned long)f)(p);
    vcall<void>(obj, 0x21c, r);
    return;
  }
  if (at<u32>(p, -4) == 0) vcall<void>(ev, 0xac, p);
  vcall<void>(obj, 0x21c, at<u32>(p, -4));
}
PCREG(5c7db0, CCameraBox_Init);
