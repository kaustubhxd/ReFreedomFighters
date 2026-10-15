#include "ff.h"
static inline float addss(float a,float b) {asm("addss %1, %0":"+x"(a):"x"(b));return a;}
static inline float mulss(float a,float b) {asm("mulss %1, %0":"+x"(a):"x"(b));return a;}
static u8 THISCALL primCheckPointInside(u8 *self, u32 id, const float *p, float r) {
  u32 nr = __builtin_bit_cast(u32, r) ^ 0x80000000u;
  float mr = __builtin_bit_cast(float, nr);
  while (id) {
    u8 *n = vcall<u8 *>(self, 0xc, id);
    u32 ps = *(u32 *)(n + 0x24);
    if (ps) {
      u32 *pl = vcall<u32 *>(self, 0xc, ps);
      u32 cnt = pl[0];
      const float *q = (const float *)(pl + 1);
      for (u32 i = 0; i != cnt; ++i, q += 4) {
        float d = addss(addss(addss(mulss(q[1], p[1]), mulss(p[0], q[0])), mulss(q[2], p[2])), q[3]);
        if (d > mr) return 0;
      }
    }
    id = *(u32 *)(n + 8);
  }
  return 1;
}
PCREG(655fa0, primCheckPointInside);
