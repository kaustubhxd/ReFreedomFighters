// batch33104.cpp - h3 (Sonnet) batch 33104: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_467c40(u8 *self);                       // plain ret
extern "C" u32 THISCALL ext_466f60(u8 *self, u32 a);                 // ret 4

// 0x5ebca0: thiscall no args: p=[this+0x3a]; [p]=[this+0x42]; for i in 0..[this+0x3e]-1 (unsigned): e=[p+4]+0x28*i: e[0..0x10)=0; e[0x10]=e[0x14]=1.0; e[0x18]=0; e[0x24]=-1; e[0x1c]=(float)(u32)[this+0x52]; e[0x20]=(float)(u32)[this+0x56]
static void THISCALL fn5ebca0(u8 *self) {
  u8 *p = (u8 *)R32(self + 0x3a);
  W32(p, R32(self + 0x42));
  u32 n = R32(self + 0x3e);
  u32 off = 0;
  for (u32 i = 0; i < n; i++, off += 0x28) {
    u8 *e = (u8 *)R32((u8 *)R32(self + 0x3a) + 4) + off;
    W32(e, 0);
    W32(e + 4, 0);
    W32(e + 8, 0);
    e = (u8 *)R32((u8 *)R32(self + 0x3a) + 4) + off;
    W32(e + 0xc, 0);
    W32(e + 0x10, 0x3f800000);
    W32(e + 0x14, 0x3f800000);
    W32(e + 0x18, 0);
    W32(e + 0x24, 0xffffffffu);
    float w = (float)(double)R32(self + 0x52);
    W32(e + 0x1c, fbits(w));
    float h = (float)(double)R32(self + 0x56);
    W32(e + 0x20, fbits(h));
  }
}
PCREG(5ebca0, fn5ebca0);

// 0x466290: thiscall(a, b) ret 8: byte [this+0x13a]==0 -> 0; p=table slot 0x60([this+0x13b]); k=0; p and p[0x70] != 0.0 (or NaN): (u8)b == 0 -> return [this+0x13b]; k=100; 0x467c40(this); then id=0x466f60(this, a); [0x13b]=id; [0x13f]=a; q=table slot 0x60(id); q: [q+0x78]=(float)k/1000; return [this+0x13b]
static u32 THISCALL fn466290(u8 *self, u32 a, u32 b) {
  if (self[0x13a] == 0) return 0;
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u8 *p = vcall<u8 *>(tab, 0x60, R32(self + 0x13b));
  s32 k = 0;
  if (p && !(*(float *)(p + 0x70) == 0.0f)) {
    if ((u8)b == 0) return R32(self + 0x13b);
    k = 0x64;
    ext_467c40(self);
  }
  u32 id = ext_466f60(self, a);
  W32(self + 0x13b, id);
  W32(self + 0x13f, a);
  tab = *(u8 **)(SYS + 0x9b);
  u8 *q = vcall<u8 *>(tab, 0x60, id);
  if (q) {
    float f = (float)k * 0.0010000000474974513f;
    *(float *)(q + 0x78) = f;
  }
  return R32(self + 0x13b);
}
PCREG(466290, fn466290);

// 0x49a5d0: thiscall(o) ret 4: o->slot 0xc(); this->slot 0x14(&n); while n != 0: loop n times: this->slot 0x40(&a); slot 0x50(&b); slot 0x50(&c); o->slot 0x98(a, c, b)
static void THISCALL fn49a5d0(u8 *self, u8 *o) {
  vcall<u32>(o, 0xc);
  u32 n = 0;
  vcall<u32>(self, 0x14, (u32)&n);
  if (n == 0) return;
  u32 i = 0;
  do {
    u32 a = 0, b = 0, c = 0;
    vcall<u32>(self, 0x40, (u32)&a);
    vcall<u32>(self, 0x50, (u32)&b);
    vcall<u32>(self, 0x50, (u32)&c);
    vcall<u32>(o, 0x98, a, c, b);
    i++;
  } while (i != n);
}
PCREG(49a5d0, fn49a5d0);
