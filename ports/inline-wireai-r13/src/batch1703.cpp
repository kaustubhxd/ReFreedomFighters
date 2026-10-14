// batch1703.cpp - 0x47fea0 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, no stack arguments, plain ret. Builds a zero
// vector and a 3-float copy of this+0x1c (all three components), calls ZBaseGeom 0x4dd060(obj, &copy) (thiscall, one argument,
// hooked), ZBaseGeom::SetRadius 0x4dce50(obj, this+0x1c) (thiscall, one float argument, hooked) and ZBaseGeom::SetCen
// 0x4dc600(obj, &zero) (thiscall, one argument, hooked), where obj = this+8. The exe's stack cookie check is not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4dd060[], ext_4dce50[], ext_4dc600[];
typedef void(THISCALL *Ptr1)(void *self, u32 a);
typedef void(THISCALL *Float1)(void *self, float a);

void THISCALL GUESS_47fea0(u8 *self) {
  u32 zero[3] = {0, 0, 0};
  float r = AT(float, self, 0x1c);
  float copy[3] = {r, r, r};
  void *obj = AT(void *, self, 8);
  ((Ptr1)(void *)ext_4dd060)(obj, (u32)copy);
  ((Float1)(void *)ext_4dce50)(obj, r);
  ((Ptr1)(void *)ext_4dc600)(obj, (u32)zero);
}
PCREG(47fea0, GUESS_47fea0);
