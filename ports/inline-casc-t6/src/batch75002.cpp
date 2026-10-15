// batch75002.cpp - tier H slice 5 (t6, Haiku): 0x45bb10 (50 insns, thiscall with 5 stack args).
#include "ff.h"

extern "C" void THISCALL ext_vt_0x20(void *);
extern "C" void THISCALL ext_vt_0x38(void *, void *, void *);
extern "C" void THISCALL ext_vt_0x3c(void *, void *, void *, float, float, u32);
extern "C" u32 THISCALL ext_45b620(void *);

// 0x45bb10 thiscall(p0, f1, f2, p1): Check if this[0x44]==-1, if so initialize via engine lookup.
// Call engine object's vtable slots [0x20] and [0x3c] with float args, call 0x45b620, store result.
static void THISCALL fn_45bb10(void *self, void *p0, u32 p1, float f1, float f2, u32 p2) {
  u8 *self_b = (u8 *)self;
  u32 v44 = *(u32 *)(self_b + 0x44);

  if (v44 == 0xffffffff) {
    u8 *eng = *(u8 **)0x70039c;
    u8 *obj = *(u8 **)(eng + 0x190f);

    void *result1 = vcall<void *>(obj, 0x20);
    u32 temp = *(u32 *)(self_b + 0x1c);
    u8 *obj_addr = (u8 *)self_b + 0x48;
    v44 = vcall<u32>(result1, 0x38, temp, obj_addr);

    v44 = *(u32 *)(self_b + 0x44);
  }

  u8 *eng = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(eng + 0x190f);
  void *result2 = vcall<void *>(obj, 0x20);

  u8 *ptr1 = (u8 *)p0 + 0xc;
  u8 *ptr2 = (u8 *)p0 + 0x28;
  u32 res = vcall<u32>(result2, 0x3c, ptr1, ptr2, f1, f2, p2, v44);

  if (res) {
    u32 idx = ext_45b620(self);
    u32 *store_ptr = (u32 *)(self_b + 0x40);
    *(store_ptr + idx) = res;
  }
}
PCREG(45bb10, fn_45bb10);
