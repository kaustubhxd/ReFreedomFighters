// batch42001.cpp - tier H, float-return callee.
#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);  // thiscall, ret 4
extern "C" float THISCALL ext_4e5e80(u32 *self);           // float in st0
extern "C" u32 THISCALL ext_4e5e40(u32 *self);             // value in ax
extern "C" u32 THISCALL ext_4e5e60(u32 *self);             // eax
typedef void(THISCALL *v1p_t)(void *, void *);

// 0x476390, thiscall(src) ret 4, returns true: clear bit 6 of [+4]; local = 0, 0x6352f0(this, &local); +0x48 = float(0x4e5e80), word +0x4c = 0x4e5e40,
// +0x4e (unaligned dword) = 0x4e5e60; slot 0x58 of src with this+0x52, slot 0x68 with this+0x56.
static bool THISCALL fn476390(u8 *self, u8 *src) {
  u32 local = 0;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &local);
  float f = ext_4e5e80(&local);
  u32 w = ext_4e5e40(&local);
  u32 d = ext_4e5e60(&local);
  *(float *)(self + 0x48) = f;
  *(u16 *)(self + 0x4c) = (u16)w;
  u8 *p = self + 0x4e;
  p[0] = d; p[1] = d >> 8; p[2] = d >> 16; p[3] = d >> 24;
  (*(v1p_t **)src)[0x58 / 4](src, self + 0x52);
  (*(v1p_t **)src)[0x68 / 4](src, self + 0x56);
  return true;
}
PCREG(476390, fn476390);
