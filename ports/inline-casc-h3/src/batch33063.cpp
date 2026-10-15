// batch33063.cpp - h3 (Sonnet) batch 33063: dtor dispatchers (vtable first), list teardown, small wrappers
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" void THISCALL ext_46b440(u8 *self, u32 a, u32 b);       // ret 8
extern "C" void THISCALL ext_63ef00(u8 *self, u32 a);              // ret 4
extern "C" u32 THISCALL ext_4dd8d0(u8 *self);                      // bool in al
extern "C" void THISCALL ext_45c3e0(u8 *self);
extern "C" void THISCALL ext_46a4f0(u8 *self);
extern "C" void THISCALL ext_445330(u8 *self);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x445340: thiscall(a) ret 4: vtable 0x67d748; 0x45c3e0(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x197) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn445340(u8 *self, u32 a) {
  *(u32 *)self = 0x67d748;
  ext_45c3e0(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x197);
  }
  return self;
}
PCREG(445340, fn445340);

// 0x46a7c0: thiscall(a) ret 4: vtable 0x687648; 0x46a4f0(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x94) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn46a7c0(u8 *self, u32 a) {
  *(u32 *)self = 0x687648;
  ext_46a4f0(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x94);
  }
  return self;
}
PCREG(46a7c0, fn46a7c0);

// 0x5b21b0: thiscall(a) ret 4: vtable 0x6b1650; 0x445330(this); a&1: (a&4 ? cdecl 0x4690b0(this,0x1cc) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn5b21b0(u8 *self, u32 a) {
  *(u32 *)self = 0x6b1650;
  ext_445330(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0x1cc);
  }
  return self;
}
PCREG(5b21b0, fn5b21b0);

// 0x470250: thiscall: if [this+0x96]: p=[this+0x9a] (unaligned); p && o=table->slot 0x60(p) && 0x46b440(o, 0, 0.3f); [this+0x9a]=slot 0x304([this+0x96])
static void THISCALL fn470250(u8 *self) {
  if (*(u32 *)(self + 0x96) == 0) return;
  u32 p = *(u32 *)(self + 0x9a);
  if (p) {
    u8 *o = vcall<u8 *>(SYS_TABLE, 0x60, p);
    if (o) ext_46b440(o, 0, 0x3e99999a);
  }
  u32 r = vcall<u32>(self, 0x304, *(u32 *)(self + 0x96));
  *(u32 *)(self + 0x9a) = r;
}
PCREG(470250, fn470250);

// 0x4cdbd0: thiscall: release [this+0x1c]; flag bit 31 in [this+0xc]; walk list at [this+4] (next at +4) calling vtable[0x7c](node) with the vtable re-read each iteration; clear [this+4],[this+0x14]
static void THISCALL fn4cdbd0(u8 *self) {
  u8 *c = *(u8 **)(self + 0x1c);
  if (c) {
    vcall<u32>(c, 0, 1u);
    *(u32 *)(self + 0x1c) = 0;
  }
  *(u32 *)(self + 0xc) |= 0x80000000u;
  u8 *node = *(u8 **)(self + 4);
  if (node) {
    do {
      u8 *edx = *(u8 **)self;
      u8 *nxt = *(u8 **)(node + 4);
      ((u32(THISCALL *)(u8 *, u8 *)) * (u32 *)(edx + 0x7c))(self, node);
      node = nxt;
    } while (node);
  }
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(4cdbd0, fn4cdbd0);

// 0x534510: thiscall: delete [this+8]; c=[this]: c->slot 0(1), delete([this+4],4), clear both; clear [this+0x100c],[this+0x1010]
static void THISCALL fn534510(u8 *self) {
  u8 *p = *(u8 **)(self + 8);
  if (p) ext_634273(p, 1);
  u8 *c = *(u8 **)self;
  *(u32 *)(self + 8) = 0;
  if (c) {
    vcall<u32>(c, 0, 1u);
    ext_634273(*(u8 **)(self + 4), 4);
    *(u32 *)self = 0;
    *(u32 *)(self + 4) = 0;
  }
  *(u32 *)(self + 0x100c) = 0;
  *(u32 *)(self + 0x1010) = 0;
}
PCREG(534510, fn534510);

// 0x5ef000: thiscall(a,b,c,d) ret 0x10: if (a,b,c,d) differs from the four dwords at this+0x11: store them and call slot 8()
static void THISCALL fn5ef000(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  if (*(u32 *)(self + 0x11) == a && *(u32 *)(self + 0x15) == b && *(u32 *)(self + 0x19) == c && *(u32 *)(self + 0x1d) == d) return;
  u8 *vt = *(u8 **)self;
  *(u32 *)(self + 0x1d) = d;
  *(u32 *)(self + 0x11) = a;
  *(u32 *)(self + 0x15) = b;
  *(u32 *)(self + 0x19) = c;
  ((u32(THISCALL *)(u8 *)) * (u32 *)(vt + 8))(self);
}
PCREG(5ef000, fn5ef000);

// 0x63ea00: thiscall(a) ret 4: 0x63ef00(this,a); n=[a+0x38]: flag clear; 0x4dd8d0(n) ? c=[n+0x54]; c->slot 0x130(c, 0x400, 0)
static void THISCALL fn63ea00(u8 *self, u8 *a) {
  ext_63ef00(self, (u32)a);
  u8 *eax = *(u8 **)(a + 0x38);
  if (!eax) return;
  *(u32 *)(eax + 0x3c) &= 0xffffefffu;
  u8 *n = *(u8 **)(a + 0x38);
  if (!(u8)ext_4dd8d0(n)) return;
  u8 *c = *(u8 **)(n + 0x54);
  if (!c) return;
  vcall<u32>(c, 0x130, (u32)c, 0x400u, 0u);
}
PCREG(63ea00, fn63ea00);
