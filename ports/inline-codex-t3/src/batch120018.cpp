#include "ff.h"
static inline s32 Cvtt(float f) {
  s32 r;
  asm("cvttss2si %1, %0" : "=r"(r) : "x"(f));
  return r;
}
static void THISCALL SetSewerInfo(u8 *self, const char *name, u32 kind, u32 *pos, float *dir) {
  float x = dir[6], z = dir[8], a;
  if (x == 0.0f) {
    a = z > 0.0f ? G(float, 0x683770) : G(float, 0x6970d8);
  } else {
    a = (float)crt::atan((double)(z / x));
    if (0.0f > dir[6]) a += G(float, 0x67da18);
    else if (0.0f > dir[8]) a += G(float, 0x68aef8);
  }
  for (int i = 0; i < 19; i++) {
    u8 *e = self + 8 + 0x12 * i;
    const u8 *p = (const u8 *)name, *q = *(const u8 **)e;
    while (*p == *q && *p) p++, q++;
    if (*p != *q) continue;
    e[4] = (u8)kind;
    e[0x11] = (u8)Cvtt(a * G(float, 0x68af18) / G(float, 0x68aef8));
    *(u32 *)(e + 5) = pos[0];
    *(u32 *)(e + 9) = pos[1];
    *(u32 *)(e + 0xd) = pos[2];
  }
}
PCREG(5b1760, SetSewerInfo);
