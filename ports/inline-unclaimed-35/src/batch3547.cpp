#include "ff.h"
// batch3547.cpp - slice 14, batch 47: 0x6563e0, 0x4c31e0, 0x565b20 (GUESS names).
// Stubbed in the harness: 0x564fd0, 0x564600 (thiscall, no args and one arg, logged); mgr at 0x70039c;
// [mgr+0x190f] vtable (slot +0x20 no-arg, +0x18 two-arg); [mgr+0x9b] vtable (slot +0x4c one-arg);
// arg0 vtable (slot +0x3c no-arg); this vtable (slot +0xd8 no-arg).

extern "C" void THISCALL ext_564fd0(u8 *self);
extern "C" void THISCALL ext_564600(u8 *self, u32 a0);

struct Obj {
  u32 vt;
};

u32 gap6563e0(u32 a0, u32 a1) {
  u32 esi = (a0 + a0*4) << 3;
  if (esi == 0)
    return 0;
  Obj *mgr = *(Obj **)0x70039c;
  Obj *obj_190f = (Obj *)*(u32 *)((u8 *)mgr + 0x190f);
  u32 (*vf1)(Obj *) = (u32 (*)(Obj *))(*(u32 *)obj_190f + 0x20);
  u32 r = vf1(obj_190f);
  Obj *result = (Obj *)r;
  void (*vf2)(Obj *, u32, u32) = (void (*)(Obj *, u32, u32))(*(u32 *)result + 0x18);
  vf2(result, a1, esi);
  return 0;
}
PCREG(6563e0, gap6563e0);

u32 THISCALL gap4c31e0(u8 *self, u32 a0) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  Obj *mgr = *(Obj **)0x70039c;
  Obj *vt_obj = (Obj *)*(u32 *)((u8 *)mgr + 0x9b);
  void (*vf1)(Obj *, u8 *) = (void (*)(Obj *, u8 *))(*(u32 *)vt_obj + 0x4c);
  vf1(vt_obj, self + 0x48);
  Obj *arg_obj = (Obj *)(u32)a0;
  void (*vf2)(Obj *, u8 *) = (void (*)(Obj *, u8 *))(*(u32 *)arg_obj + 0x3c);
  vf2(arg_obj, self);
  return 1;
}
PCREG(4c31e0, gap4c31e0);

u32 THISCALL gap565b20(u8 *self, u32 a0) {
  ext_564fd0(self);
  Obj *obj = (Obj *)self;
  u8 (*vf)(Obj *) = (u8 (*)(Obj *))(*(u32 *)obj + 0xd8);
  u8 r = vf(obj);
  if (r != 0 && a0 == 1) {
    ext_564600(self, 7);
  }
  return 0;
}
PCREG(565b20, gap565b20);
