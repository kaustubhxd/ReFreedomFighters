// batch6371.cpp - unclaimed-63 batch 71: 0x4a6060 ZRequireMatPosSpeed::Init(ZGEOM*, DBREAD&) (core list name), thiscall, two stack
//   arguments g and r, ret 8. Reads five floats into this+0x48, +0x54, +0x60, +0x6c, +0x78 with 0x4e6180(r, ptr) (thiscall with the reader
//   in ECX, one argument, callee pops 4; other area's code, stubbed). Then 0x4e0d00 (thiscall, one float argument: the constant 0x3c8efa35)
//   on this+0x60 and then on this+0x48.
#include "ff.h"

extern "C" void THISCALL ext_4e6180(void *reader, u32 ptr);   // thiscall, one argument, stubbed
extern "C" void THISCALL ext_4e0d00(void *self, float v);     // thiscall, one float argument, stubbed

static float const_3c8efa35() {
  u32 b = 0x3c8efa35u;
  float f;
  __builtin_memcpy(&f, &b, 4);
  return f;
}

// 0x4a6060.
static void THISCALL unnamed4a6060(u8 *self, u32 g, u8 *r) {
  (void)g;
  ext_4e6180((void *)r, (u32)(self + 0x48));
  ext_4e6180((void *)r, (u32)(self + 0x54));
  ext_4e6180((void *)r, (u32)(self + 0x60));
  ext_4e6180((void *)r, (u32)(self + 0x6c));
  ext_4e6180((void *)r, (u32)(self + 0x78));
  ext_4e0d00((void *)(self + 0x60), const_3c8efa35());
  ext_4e0d00((void *)(self + 0x48), const_3c8efa35());
}
PCREG(4a6060, unnamed4a6060);
