// batch34027.cpp - cascade tier E, batch 34027: 0x5f1610 (create an entry and tag it), 0x458300 (copy a settings block from a matching object),
// 0x45dcd0 (create a child with defaults and attach it).
#include "ff.h"

extern "C" u32 THISCALL ext_5fb530(void *self, u32 a, u32 b, u32 c, u32 d);   // thiscall ret 0x10
extern "C" void THISCALL ext_5f2b90(void *self);                               // thiscall, plain ret

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5f1610, thiscall(a, b, c) ret 0xc: e = 0x5fb530([[this+0xc]+4], a, b, 0, 0); 0x5f2b90(this); when c and e: [e+0x24] = c and return e; otherwise log through the
// object at 0x700390 (slot 0x20(0x6b8738, 0x163), then its slot 0x2c with (r, 0x6b8814, a), caller-popped) and return e.
static u32 THISCALL fn5f1610(u8 *self, u32 a, u32 b, u32 c) {
  u8 *p = *(u8 **)(self + 0xc);
  u32 e = ext_5fb530(*(u8 **)(p + 4), a, b, 0, 0);
  ext_5f2b90(self);
  if (c && e) {
    *(u32 *)(e + 0x24) = c;
    return e;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x6b8738u, 0x163u);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  u32 av[2] = {0x6b8814, a};
  asm volatile("push 4(%[av])\n\tpush 0(%[av])\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [av] "r"(av), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  return e;
}
PCREG(5f1610, fn5f1610);

// 0x458300, thiscall(s) ret 4: when s->slot0x1e0(0x2000fa) is true copies byte +0xbc, dwords +0xa0, +0xa4, +0xa8, +0xb8, +0xbd (unaligned), +0x88, +0x8c, +0x90, +0x94,
// +0x98, +0x9c and +0x80 from s to this.
static void THISCALL fn458300(u8 *self, u8 *s) {
  if (!vcall<bool>(s, 0x1e0, 0x2000fau)) return;
  self[0xbc] = s[0xbc];
  *(u32 *)(self + 0xa0) = *(u32 *)(s + 0xa0);
  *(u32 *)(self + 0xa4) = *(u32 *)(s + 0xa4);
  *(u32 *)(self + 0xa8) = *(u32 *)(s + 0xa8);
  *(u32 *)(self + 0xb8) = *(u32 *)(s + 0xb8);
  wr32u(self + 0xbd, rd32u(s + 0xbd));
  *(u32 *)(self + 0x88) = *(u32 *)(s + 0x88);
  *(u32 *)(self + 0x8c) = *(u32 *)(s + 0x8c);
  *(u32 *)(self + 0x90) = *(u32 *)(s + 0x90);
  *(u32 *)(self + 0x94) = *(u32 *)(s + 0x94);
  *(u32 *)(self + 0x98) = *(u32 *)(s + 0x98);
  *(u32 *)(self + 0x9c) = *(u32 *)(s + 0x9c);
  *(u32 *)(self + 0x80) = *(u32 *)(s + 0x80);
}
PCREG(458300, fn458300);

// 0x45dcd0, thiscall(a, b, c, d, e) ret 0x14: 0 when this->slot0x20() is 0; else x = c ? c : [this+4]; y = d ? d : [[this+0xc]] (the fifth argument is unused); r = a->slot0x294(x, y, 0, 1);
// returns r, or 0 when this->slot0x1b4(r, b) returns true.
static u32 THISCALL fn45dcd0(u8 *self, u8 *a, u32 b, u32 c, u32 d, u32 e) {
  (void)e;
  if (!vcall<u32>(self, 0x20)) return 0;
  u32 x = c ? c : *(u32 *)(self + 4);
  u32 y = d ? d : **(u32 **)(self + 0xc);
  u32 r = vcall<u32>(a, 0x294, x, y, 0u, 1u);
  if (vcall<bool>(self, 0x1b4, r, b)) return 0;
  return r;
}
PCREG(45dcd0, fn45dcd0);
