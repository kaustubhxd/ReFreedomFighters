// batch2615.cpp - wider batch 2615: twelve unclaimed functions (GUESS names). SEH frames/cookie checks are not reproduced (they restore ESI; no observable effect).
#include "ff.h"

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])
typedef u32(THISCALL *vf1_t)(void *, u32);
typedef u32(THISCALL *vf4_t)(void *, u32, u32, u32, u32);
static inline u8 *U8(void *p) { return (u8 *)p; }

extern "C" u32 ext_41e290(u32 n);                       // allocator, cdecl
extern "C" u32 THISCALL ext_433d20(void *self);
extern "C" u32 THISCALL ext_4cc5f0(void *self);
extern "C" u32 THISCALL ext_4cc1d0(void *self);
extern "C" void ext_634273(void *p, u32 n);
extern "C" void THISCALL ext_436260(void *self);
extern "C" void THISCALL ext_435ba0(void *self);
extern "C" void THISCALL ext_4cbe80(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_4cbee0(void *self, void *a); // ret 4
extern "C" void THISCALL ext_4cbec0(void *self);
extern "C" void THISCALL ext_434fb0(void *self);
extern "C" void THISCALL ext_43cfb0(void *self);
extern "C" void THISCALL ext_441b90(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void *ext_634d10(void *, int, unsigned);   // memset thunk (IAT), cdecl
extern "C" void THISCALL ext_448a30(void *self, void *obj);   // ret 4
extern "C" u8 THISCALL ext_4e1600(void *self);
extern "C" void THISCALL ext_4e12f0(void *self, void *p, u32 n);   // ret 8
extern "C" void THISCALL ext_4e1b30(void *self);
extern "C" void THISCALL ext_4e0fd0(void *self, u32 a);   // ret 4

// 0x421600, thiscall no args, SEH frame: p = alloc(0x107); with a block the constructor 0x433d20(p) (returns the object) goes to +0x1b4d, else +0x1b4d = 0; returns that value.
static u32 THISCALL fn421600(u8 *self) {
  u32 p = ext_41e290(0x107);
  if (p) {
    u32 r = ext_433d20((void *)p);
    *(u32 *)(self + 0x1b4d) = r;
    return r;
  }
  *(u32 *)(self + 0x1b4d) = 0;
  return 0;
}
PCREG(421600, fn421600);

// 0x423e60, thiscall no args: when 0x4cc5f0(this+0x23db): the object [0x700394] slot 0x64 gets (0x4cc1d0(this+0x23db), [+0x25dc], [+0x25e0] - [+0x25dc], 0);
// then free([+0x25dc], 1) when set, and clear +0x25dc, +0x25e0, +0x25e4.
static void THISCALL fn423e60(u8 *self) {
  if (ext_4cc5f0(self + 0x23db)) {
    u32 *vt = **(u32 ***)0x700394;                       // the vtable is read before the other calls (ESI)
    u32 a = *(u32 *)(self + 0x25dc);
    u32 len = *(u32 *)(self + 0x25e0) - a;
    u32 s = ext_4cc1d0(self + 0x23db);
    ((vf4_t)vt[0x64 / 4])(*(void **)0x700394, s, a, len, 0);
  }
  u32 q = *(u32 *)(self + 0x25dc);
  if (q) ext_634273((void *)q, 1);
  *(u32 *)(self + 0x25dc) = 0;
  *(u32 *)(self + 0x25e0) = 0;
  *(u32 *)(self + 0x25e4) = 0;
}
PCREG(423e60, fn423e60);

// 0x428770, thiscall(flags) ret 4, returns this, SEH frame: vtable 0x678d2c; [0x7003a0] = 0; 0x436260(this); the object at +0x7c: slot 8 with itself, cleared; base 0x435ba0; free(this, 0x8f) on bit 0.
typedef u32(THISCALL *vself_t)(void *, void *);
static u8 *THISCALL fn428770(u8 *self, u32 flags) {
  *(u32 *)self = 0x678d2c;
  *(u32 *)0x7003a0 = 0;
  ext_436260(self);
  void *o = *(void **)(self + 0x7c);
  if (o) {
    VT(o, vself_t, 8)(o, o);
    *(u32 *)(self + 0x7c) = 0;
  }
  ext_435ba0(self);
  if (flags & 1) ext_634273(self, 0x8f);
  return self;
}
PCREG(428770, fn428770);

// 0x42cba0, thiscall no args, returns true (AL), SEH + cookie: tmp string = 0x4cbe80(&tmp, 0x679e38); 0x4cbee0(this + 0x1a17, &tmp); 0x4cbec0(&tmp).
static u8 THISCALL fn42cba0(u8 *self) {
  u8 tmp[0x84];
  ext_4cbe80(tmp, 0x679e38);
  ext_4cbee0(self + 0x1a17, tmp);
  ext_4cbec0(tmp);
  return 1;
}
PCREG(42cba0, fn42cba0);

// 0x42fac0, thiscall(a) ret 4, SEH + cookie: tmp string = 0x4cbe80(&tmp, a); 0x4cbee0(this + 0x1997, &tmp); 0x4cbec0(&tmp).
static void THISCALL fn42fac0(u8 *self, u32 a) {
  u8 tmp[0x84];
  ext_4cbe80(tmp, a);
  ext_4cbee0(self + 0x1997, tmp);
  ext_4cbec0(tmp);
}
PCREG(42fac0, fn42fac0);

// 0x433f90, thiscall(flags) ret 4, returns this, SEH frame: vtable 0x67a3b0; base 0x434fb0; the object at +8 gets slot 0 with 1; destructors 0x4cbec0 on +0x8c and +0xc; free(this, 0x10c) on bit 0.
static u8 *THISCALL fn433f90(u8 *self, u32 flags) {
  *(u32 *)self = 0x67a3b0;
  ext_434fb0(self);
  void *o = *(void **)(self + 8);
  if (o) VT(o, vf1_t, 0)(o, 1);
  ext_4cbec0(self + 0x8c);
  ext_4cbec0(self + 0xc);
  if (flags & 1) ext_634273(self, 0x10c);
  return self;
}
PCREG(433f90, fn433f90);

// 0x435c00, thiscall(flags) ret 4, returns this: vtable 0x67a65c; the object at +0x65: 0x43cfb0 then free(.., 0x34a); vtable 0x67a630; the block at +8: free(.., 1); free(this, 0x71) on bit 0.
static u8 *THISCALL fn435c00(u8 *self, u32 flags) {
  void *e = *(void **)(self + 0x65);
  *(u32 *)self = 0x67a65c;
  if (e) {
    ext_43cfb0(e);
    ext_634273(e, 0x34a);
  }
  void *b = *(void **)(self + 8);
  *(u32 *)self = 0x67a630;
  if (b) ext_634273(b, 1);
  if (flags & 1) ext_634273(self, 0x71);
  return self;
}
PCREG(435c00, fn435c00);

// 0x43cf00, thiscall(a) ret 4, returns this: vtable 0x67c15c; clear dwords at +0xc, +0x24, +0x3c, +0x54, +0x6c and +0x84; twelve records of 0x3a bytes from +0xca clear the bytes at -0x1d and 0;
// memset(this + 8, 0, 0x78); +4 = a; +0x80 = 0; +0x8c = +0x88 = 0; byte +0x349 = 0; byte +0x90 = 1.
static u8 *THISCALL fn43cf00(u8 *self, u32 a) {
  *(u32 *)self = 0x67c15c;
  u8 *e = self + 8;
  *(u32 *)(e + 4) = 0;
  *(u32 *)(e + 0x1c) = 0;
  *(u32 *)(e + 0x34) = 0;
  *(u32 *)(e + 0x4c) = 0;
  *(u32 *)(e + 0x64) = 0;
  *(u32 *)(self + 0x84) = 0;
  u8 *q = self + 0xca;
  for (int i = 0; i < 12; i++) {
    q[-0x1d] = 0;
    q[0] = 0;
    q += 0x3a;
  }
  ext_634d10(e, 0, 0x78);
  *(u32 *)(self + 4) = a;
  *(u32 *)(self + 0x80) = 0;
  *(u32 *)(self + 0x8c) = 0;
  *(u32 *)(self + 0x88) = 0;
  self[0x349] = 0;
  self[0x90] = 1;
  return self;
}
PCREG(43cf00, fn43cf00);

// 0x443f40, thiscall(a, b, c) ret 0xc, returns this: base 0x441b90(this, a, b, c); +0x30 &= 0xfcffffff; vtable 0x67d1d0; a run of field resets.
static u8 *THISCALL fn443f40(u8 *s, u32 a, u32 b, u32 c) {
  ext_441b90(s, a, b, c);
  *(u32 *)(s + 0x30) &= 0xfcffffffu;
  *(u32 *)s = 0x67d1d0;
  s[0x87] = 0;
  *(u32 *)(s + 0x88) = 0;
  *(u32 *)(s + 0x90) = 0;
  *(u32 *)(s + 0x8c) = 0;
  *(u32 *)(s + 0xc0) = 0;
  *(u32 *)(s + 0x83) = 0;
  *(u32 *)(s + 0x98) = 0;
  *(u32 *)(s + 0xa4) = 0;
  *(u32 *)(s + 0x94) = 0xffffffffu;
  *(u32 *)(s + 0xa8) = 0;
  *(u32 *)(s + 0xac) = 0;
  *(u32 *)(s + 0xb0) = 0;
  *(u32 *)(s + 0x9c) = 0;
  *(u32 *)(s + 0xb4) = 0;
  *(u32 *)(s + 0xb8) = 0;
  *(u32 *)(s + 0xbc) = 0;
  *(u32 *)(s + 0xa0) = 0;
  return s;
}
PCREG(443f40, fn443f40);

// 0x445e10, thiscall(out) ret 4, returns the count at +4: out[4i..4i+3] = this[idx*16 + 0x38 / 0x3c / 0x40 / 0x44] for each index at +8...
static u32 THISCALL fn445e10(u8 *self, u32 *out) {
  if (*(u32 *)(self + 4)) {
    for (u32 i = 0; i != *(u32 *)(self + 4); i++) {
      u32 idx = *(u32 *)(self + 8 + 4 * i);
      out[4 * i + 0] = *(u32 *)(self + idx * 16 + 0x38);
      out[4 * i + 1] = *(u32 *)(self + idx * 16 + 0x3c);
      out[4 * i + 2] = *(u32 *)(self + idx * 16 + 0x40);
      out[4 * i + 3] = *(u32 *)(self + idx * 16 + 0x44);
    }
  }
  return *(u32 *)(self + 4);
}
PCREG(445e10, fn445e10);

// 0x448950, thiscall(obj) ret 4: 0x448a30(this, obj); when 0x4e1600(obj) == 1: three calls 0x4e12f0(obj, &x, 1); 0x4e1b30(obj); 0x4e0fd0(obj, [this+0x1c]); 0x4e1b30(obj).
static void THISCALL fn448950(u8 *self, u8 *obj) {
  u32 slot = (u32)obj, l1, l2;
  ext_448a30(self, obj);
  if (ext_4e1600(obj) == 1) {
    ext_4e12f0(obj, &slot, 1);
    ext_4e12f0(obj, &l1, 1);
    ext_4e12f0(obj, &l2, 1);
  }
  ext_4e1b30(obj);
  ext_4e0fd0(obj, *(u32 *)(self + 0x1c));
  ext_4e1b30(obj);
}
PCREG(448950, fn448950);

// 0x448c00, thiscall(obj) ret 4: as 0x448950 without the 0x4e0fd0 / second 0x4e1b30 tail.
static void THISCALL fn448c00(u8 *self, u8 *obj) {
  u32 slot = (u32)obj, l1, l2;
  ext_448a30(self, obj);
  if (ext_4e1600(obj) == 1) {
    ext_4e12f0(obj, &slot, 1);
    ext_4e12f0(obj, &l1, 1);
    ext_4e12f0(obj, &l2, 1);
  }
  ext_4e1b30(obj);
}
PCREG(448c00, fn448c00);
