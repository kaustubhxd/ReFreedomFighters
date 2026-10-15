// batch33087.cpp - h3 (Sonnet) batch 33087: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)
#define LOGOBJ (*(u8 **)0x700390)

typedef void (*log3_t)(u8 *, u32, u32);

extern "C" u8 THISCALL ext_467770(u8 *self, u8 *s);              // ret 4, bool in al

// 0x5d91a0: thiscall no args: [this+0x4c] == 1 and (float)([sys+0x40]-[this+0x48]-0x200)/1024 > 0: [this+0x4c]=0; [this+0x44]->slot 0x254(); p = sys table slot 0x58([this+0x54]); p -> slot 0x254()
static void THISCALL fn5d91a0(u8 *self) {
  u32 st = *(u32 *)(self + 0x4c);
  if (st == 0 || st != 1) return;
  s32 t = (s32)(*(u32 *)(SYS + 0x40) - *(u32 *)(self + 0x48) - 0x200u);
  float f = (float)t * 0.0009765625f;
  if (!(f > 0.0f)) return;
  u8 *o = *(u8 **)(self + 0x44);
  *(u32 *)(self + 0x4c) = 0;
  vcall<u32>(o, 0x254);
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u8 *p = vcall<u8 *>(tab, 0x58, *(u32 *)(self + 0x54));
  if (p) vcall<u32>(p, 0x254);
}
PCREG(5d91a0, fn5d91a0);

// 0x645420: thiscall(a, b, c, d, e) ret 0x14: n=[this+0x65]; n == 4: log chain (0x6c2904,0x65) / (r, 0x6c2934, 4), return; else [this+0x65]=n+1; entry at this+0x15+20n: +0 b, +4 a, +8 c, +12 d, +16 e
static void THISCALL fn645420(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u32 n = *(u32 *)(self + 0x65);
  if (n == 4) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x6c2904u, 0x65u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x6c2934, 4);
    return;
  }
  *(u32 *)(self + 0x65) = n + 1;
  u8 *q = self + n * 20u;
  __builtin_memcpy(q + 0x19, &a, 4);
  __builtin_memcpy(q + 0x1d, &c, 4);
  __builtin_memcpy(q + 0x15, &b, 4);
  __builtin_memcpy(q + 0x21, &d, 4);
  __builtin_memcpy(q + 0x25, &e, 4);
}
PCREG(645420, fn645420);

// 0x468270: thiscall(s) ret 4, bool: 0x467770(this, s) false -> false; s->slot 0x10(this+0x1d2, 4); s->slot 0x3c([this+0x1d6]); s->slot 0x4c(float [this+0x1da]); true
static u8 THISCALL fn468270(u8 *self, u8 *s) {
  if (!ext_467770(self, s)) return 0;
  vcall<u32>(s, 0x10, (u32)(self + 0x1d2), 4u);
  u32 a;
  __builtin_memcpy(&a, self + 0x1d6, 4);
  vcall<u32>(s, 0x3c, a);
  u32 b;
  __builtin_memcpy(&b, self + 0x1da, 4);
  vcall<u32>(s, 0x4c, b);
  return 1;
}
PCREG(468270, fn468270);
