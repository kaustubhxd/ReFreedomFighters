// batch628.cpp - band 0x421000-0x441000, batch 628: two functions.
//   0x436200 ZSysInput::StartGCEffect-shaped (thiscall, two args i, y; ret 8, returns bool): if i < [this+0x60] and the
//     device at [this+0x20+4*i] is set, call its slot 0x3c with y; returns true; else false.
//   0x43cfc0 (thiscall, no args): n = dword [this+0x80]; [this+0x8c] = 0 and [this+0x88] = 0; if n > 0, for each element at
//     this+0x1c + 0x18*k: a = float [elem-4]; if a > float [this+0x88] store it there; b = float [elem]; if b > float
//     [this+0x8c] store it there. (Comparisons are ordered: a NaN never stores.)
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);

static bool THISCALL devicePresentCall3c(u8 *self, u32 i, u32 y) {
  if (i >= *(u32 *)(self + 0x60))
    return false;
  u8 *d = *(u8 **)(self + 0x20 + i * 4);
  if (!d)
    return false;
  ((vOne)VT(d, 0x3c))(d, y);
  return true;
}
PCREG(436200, devicePresentCall3c);

static void THISCALL maxMinScan(u8 *self) {
  s32 n = *(s32 *)(self + 0x80);
  *(float *)(self + 0x8c) = 0.0f;
  *(float *)(self + 0x88) = 0.0f;
  if (n > 0) {
    u8 *e = self + 0x1c;
    do {
      float a = *(float *)(e - 4);
      if (a > *(float *)(self + 0x88))
        *(float *)(self + 0x88) = a;
      float b = *(float *)e;
      if (b > *(float *)(self + 0x8c))
        *(float *)(self + 0x8c) = b;
      e += 0x18;
      n--;
    } while (n != 0);
  }
}
PCREG(43cfc0, maxMinScan);
