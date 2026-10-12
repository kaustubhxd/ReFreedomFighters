// batch618.cpp - band 0x421000-0x441000, batch 618: five functions.
//   0x435ba0 (thiscall, no args): [this] = vtable 0x67a5d8; dword [0x7003a0] = 0.
//   0x435e30 (thiscall, one dword arg idx, returns float in st0): if (s32)idx <= (s32)[this+0x5d] return float [this+0xd+4*idx];
//     else return 0.0f.
//   0x435e50 (same, with [this+0x15+4*idx]).
//   0x436130 (thiscall, one arg, ret 4): o = [this+0x65]; vslot 8 of o with (arg, 0, 1.0f) (three arguments, callee pops).
//   0x42cb70 (ZSysInterfaceGC::TimeStampCounter(char*, int), thiscall, ret 8, float in st0): r = vslot 0x1bc of this
//     with (first argument, second argument); returns (float)r / float [0x678628].
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vThree)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *vTwo)(void *self, u32 a, u32 b);

static void THISCALL setVtable67a5d8(u8 *self) {
  *(u32 *)self = 0x67a5d8;
  G(u32, 0x7003a0) = 0;
}
PCREG(435ba0, setVtable67a5d8);

static float THISCALL floatAt0d(u8 *self, u32 idx) {
  if ((s32)idx <= *(s32 *)(self + 0x5d))
    return *(float *)(self + 0xd + idx * 4);
  return 0.0f;
}
PCREG(435e30, floatAt0d);

static float THISCALL floatAt15(u8 *self, u32 idx) {
  if ((s32)idx <= *(s32 *)(self + 0x5d))
    return *(float *)(self + 0x15 + idx * 4);
  return 0.0f;
}
PCREG(435e50, floatAt15);

static void THISCALL callSlot8(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 0x65);
  ((vThree)VT(o, 8))(o, a, 0u, 0x3f800000u);
}
PCREG(436130, callSlot8);

static float THISCALL timeStampCounter(u8 *self, u32 a, u32 b) {
  s32 r = (s32)((vTwo)VT(self, 0x1bc))(self, a, b);
  return (float)r / *(float *)0x678628;
}
PCREG(42cb70, timeStampCounter);
