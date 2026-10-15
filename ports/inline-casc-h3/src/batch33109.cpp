// batch33109.cpp - h3 (Sonnet) batch 33109: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u8 THISCALL ext_4fa630(u8 *self, u8 *s);                                      // ret 4, bool
extern "C" void THISCALL ext_467410(u8 *self, u32 p, u32 f, u32 a, u32 b, u32 c, u32 d); // ret 0x18
extern "C" u32 THISCALL ext_591f00(u8 *self);                                           // plain ret
extern "C" void THISCALL ext_58bc60(u8 *self, u8 *a);                                   // ret 4

// 0x4f7410: thiscall(s) ret 4, bool: !0x4fa630(this, s) -> false; s->slot 0x3c(table slot 0x4c([this+0x8f])); s->slot 0x3c(table slot 0x4c([this+0x93])); s->slot 0x3c([+0x97]); s->slot 0x10(this+0x9b, 8); s->slot 0x4c([+0xa3]); s->slot 0x60(byte [+0xa7]); true
static u8 THISCALL fn4f7410(u8 *self, u8 *s) {
  if (!ext_4fa630(self, s)) return 0;
  u8 *vt = *(u8 **)s;
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u32 a = vcall<u32>(tab, 0x4c, R32(self + 0x8f));
  typedef u32(THISCALL * fn_t)(u8 *, u32);
  (*(fn_t *)(vt + 0x3c))(s, a);
  vt = *(u8 **)s;
  tab = *(u8 **)(SYS + 0x9b);
  u32 b = vcall<u32>(tab, 0x4c, R32(self + 0x93));
  (*(fn_t *)(vt + 0x3c))(s, b);
  vcall<u32>(s, 0x3c, R32(self + 0x97));
  vcall<u32>(s, 0x10, (u32)(self + 0x9b), 8u);
  vcall<u32>(s, 0x4c, R32(self + 0xa3));
  vcall<u32>(s, 0x60, (u32)self[0xa7]);
  return 1;
}
PCREG(4f7410, fn4f7410);

// 0x5df9f0: thiscall no args, returns false: s=[this+0xc]->slot 0x10(); table slot 0x4c(s); 0x467410([this+0xc]+4, [this+8], 0, 0,0,0,-1); [this+0xc]->slot 8([this+8], 0); 0x591f00([this+8]) != 0: s->slot 0x2d0(1, 0) else 0x58bc60([this+8], s)
static u8 THISCALL fn5df9f0(u8 *self) {
  u8 *s = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  u8 *tab = *(u8 **)(SYS + 0x9b);
  (void)vcall<u32>(tab, 0x4c, (u32)s);
  ext_467410(*(u8 **)(self + 0xc) + 4, *(u32 *)(self + 8), 0, 0, 0, 0, 0xffffffffu);
  vcall<u32>(*(u8 **)(self + 0xc), 8, *(u32 *)(self + 8), 0u);
  u32 x = ext_591f00(*(u8 **)(self + 8));
  if (x) {
    vcall<u32>(s, 0x2d0, 1u, 0u);
    return 0;
  }
  ext_58bc60(*(u8 **)(self + 8), s);
  return 0;
}
PCREG(5df9f0, fn5df9f0);
