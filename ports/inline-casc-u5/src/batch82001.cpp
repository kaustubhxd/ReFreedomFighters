// batch82001.cpp - 0x501290, tier H.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *container, u32 index);
extern "C" u8 *THISCALL ext_500360(u8 *item, float value);
extern "C" void THISCALL ext_4db670(u8 *self, float *out);
extern "C" void FASTCALL ext_633654(u32 cookie);

static u32 THISCALL fn501290(u8 *self, u8 *arg) {
  u32 cookie = *(u32 *)0x6f5630;
  u32 stack_cookie = cookie ^ (u32)&arg;

  u8 *item_a = ext_5003d0(*(u8 **)(arg + 8), 0);
  u8 flags = item_a[4];
  if (flags != 0 && flags != 2) {
    u8 *log = G(u8 *, 0x700390);
    u8 *entry = vcall<u8 *>(log, 0x20, 0x69c8e0u, 0x104u);
    vcall<void>(entry, 0x2c, 0x69c6b0u, 0x69c938u);
    vcall<void>(G(u8 *, 0x7003b0), 0);
  }
  item_a[4] = 2;
  *(u32 *)item_a = 0;

  u8 *item_b = ext_5003d0(*(u8 **)(arg + 4), 0);
  s32 id = *(s32 *)item_b;
  float result = 0.0f;
  if (id != -1) {
    u8 *table = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *record = vcall<u8 *>(table, 0x54, (u32)id);
    if (record) {
      float xyz[3] = {0.0f, 0.0f, 0.0f};
      ext_4db670(record, xyz);
      vcall<void>(*(u8 **)(self + 0xc), 0x8c, xyz);
      float sum = xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2];
      result = (float)crt::sqrt((double)sum);
    }
  }

  u8 *item_end = ext_5003d0(*(u8 **)(arg + 8), 0);
  ext_500360(item_end, result);
  ext_633654(stack_cookie);
  u32 bits = fbits(result);
  asm volatile("movd %0, %%xmm0" : : "r"(bits) : "xmm0");
  return bits;
}
PCREG(501290, fn501290);
