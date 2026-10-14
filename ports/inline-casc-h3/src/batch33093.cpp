// batch33093.cpp - h3 () batch 33093: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" void FASTCALL ext_4e0130(u8 *a, u8 *e, u8 *p, u32 f);       // ecx=a, edx=e, stack (p, float), ret 8
extern "C" float FASTCALL ext_44e630(u8 *out, float *in);              // ecx=out, edx=in, float in st0, plain ret

// 0x5273e0: thiscall(a) ret 4, returns al: r = [this+0x28]->slot 8(&local float); 0x4e0130(a, this+4, this+0x10, local); return r
static u8 THISCALL fn5273e0(u8 *self, u8 *a) {
  float loc = 0.0f;
  u8 r = vcall<u8>(self + 0x28, 8, (u32)&loc);
  ext_4e0130(a, self + 4, self + 0x10, fbits(loc));
  return r;
}
PCREG(5273e0, fn5273e0);

// 0x4e0a10: thiscall no args: three floats from sys slot 0x1c4(0x69709c, 0x13d); t = 0x44e630(this, floats); t < 0.0001220703125: this = (1.0, 0, 0)
static void THISCALL fn4e0a10(u8 *self) {
  float l[3];
  l[0] = vcall<float>(SYS, 0x1c4, 0x69709cu, 0x13du);
  l[1] = vcall<float>(SYS, 0x1c4, 0x69709cu, 0x13du);
  l[2] = vcall<float>(SYS, 0x1c4, 0x69709cu, 0x13du);
  float t = ext_44e630(self, l);
  if (0.0001220703125f > t) {
    *(u32 *)(self + 0) = 0x3f800000;
    *(u32 *)(self + 4) = 0;
    *(u32 *)(self + 8) = 0;
  }
}
PCREG(4e0a10, fn4e0a10);
