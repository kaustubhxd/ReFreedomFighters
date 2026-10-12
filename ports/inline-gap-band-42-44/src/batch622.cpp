// batch622.cpp - band 0x421000-0x441000, batch 622: two thiscall functions with one float argument (ret 4).
//   0x433580 (thiscall, float v): calls slot 0xac of this with the float as its one argument (the callee pops).
//   0x436170 RumbleStartEffect(float v) (thiscall, ret 4): float [this+0x69] = v; float [this+0x6d] = c / (c - v), with c =
//     float [0x678858] (the division is in single precision, as the exe does it).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vFloat)(void *self, float v);

static void THISCALL callSlotAc(u8 *self, float v) {
  ((vFloat)VT(self, 0xac))(self, v);
}
PCREG(433580, callSlotAc);

static void THISCALL rumbleStart(u8 *self, float v) {
  float c = *(float *)0x678858;
  *(float *)(self + 0x69) = v;
  float d = c - v;
  *(float *)(self + 0x6d) = c / d;
}
PCREG(436170, rumbleStart);
