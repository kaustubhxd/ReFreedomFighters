// batch226.cpp - small leaves, slices 0/1. Names GUESS. Callees are stubs in the harness.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);          // original, thiscall, one stack word (stubbed)
extern "C" void THISCALL ext_5a2df0(u8 *self, u32 w);            // original, thiscall, one stack word (stubbed)
extern "C" void STDCALL ext_4d2700(u32 a, u32 b, u32 c, u32 d, u32 e);   // original, stdcall five words (stubbed)

typedef void(THISCALL *SlotFloat)(u8 *, float);                  // vtable slot, one float stack word

static u32 vslot9(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x4d3a00, stdcall(a, b, c) (ret 0xc): ext_4d2700(a, 2, c, b, 0).
static void STDCALL wrapCall_4d3a00(u32 a, u32 b, u32 c) { ext_4d2700(a, 2, c, b, 0); }
PCREG(4d3a00, wrapCall_4d3a00);

// 0x55c940, thiscall(a) (ret 4): p = 0x5003d0(a->[4], 0); ext_5a2df0(this->[0x1c], (u16)*p).
static void THISCALL wordCall_55c940(u8 *self, u8 *a) {
  u8 *p = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *obj = *(u8 **)(self + 0x1c);
  ext_5a2df0(obj, (u32)*(u16 *)p);
}
PCREG(55c940, wordCall_55c940);

// 0x55ca80, thiscall(a) (ret 4): r = 0x5003d0(a->[4], 0); this->[0x1c]->[0x8fa] = (*(u32 *)r != 0).
static void THISCALL flagStore_55ca80(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *obj = *(u8 **)(self + 0x1c);
  *(u8 *)(obj + 0x8fa) = (*(u32 *)r != 0);
}
PCREG(55ca80, flagStore_55ca80);

// 0x519b40, thiscall(a) (ret 4): v = *(float *)0x5003d0(a->[4], 0); obj = this->[0x14]; obj->vt[0x318](obj, v).
static void THISCALL floatSlot_519b40(u8 *self, u8 *a) {
  float v = *(float *)ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *obj = *(u8 **)(self + 0x14);
  ((SlotFloat)vslot9(obj, 0x318))(obj, v);
}
PCREG(519b40, floatSlot_519b40);
