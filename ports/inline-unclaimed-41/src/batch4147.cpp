// batch4147.cpp - unclaimed-41 batch 47 (core-todo residue-19): 0x515b70 ZVehicle::Save(ZSaveGame*) (thiscall, one stack argument s, ret 4;
// returns al). The base save 0x513ff0(s) (thiscall, one argument, returns al) must be true; then fourteen calls on s: vt[0x10](&F216, 4),
// vt[0x68](&F21b), vt[0x68](&F227), vt[0x4c](float F233), vt[0x70](&F237), vt[0x68](&F25b), vt[0x4c](float F267), vt[0x70](&F26b),
// vt[0x68](&F28f), vt[0x68](&F29b), vt[0x3c](dword F2ab), vt[0x64](dword F2af), vt[0x68](&F2b3), vt[0x4c](float F2bf); returns 1.
#include "ff.h"

extern "C" u32 THISCALL ext_513ff0(u8 *self, u8 *s);     // base save, one stack argument, returns al (stub, GUESS)

typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
typedef u32(THISCALL * ff_t)(u8 *, float);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static u8 THISCALL fn515b70(u8 *self, u8 *s) {
  if ((ext_513ff0(self, s) & 0xff) == 0)
    return 0;
  ((f2_t)vslot(s, 0x10))(s, (u32)(self + 0x216), 4u);
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x21b));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x227));
  ((ff_t)vslot(s, 0x4c))(s, *(float *)(self + 0x233));
  ((f1_t)vslot(s, 0x70))(s, (u32)(self + 0x237));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x25b));
  ((ff_t)vslot(s, 0x4c))(s, *(float *)(self + 0x267));
  ((f1_t)vslot(s, 0x70))(s, (u32)(self + 0x26b));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x28f));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x29b));
  ((f1_t)vslot(s, 0x3c))(s, *(u32 *)(self + 0x2ab));
  ((f1_t)vslot(s, 0x64))(s, *(u32 *)(self + 0x2af));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x2b3));
  ((ff_t)vslot(s, 0x4c))(s, *(float *)(self + 0x2bf));
  return 1;
}
PCREG(515b70, fn515b70);
