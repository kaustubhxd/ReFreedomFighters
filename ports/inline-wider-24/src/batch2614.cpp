// batch2614.cpp - wider batch 2614: fourteen small unclaimed functions (GUESS names; callees hooked in the spec, arities from their `ret` immediates).
#include "ff.h"

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])
typedef u32(THISCALL *vf0_t)(void *);
typedef u32(THISCALL *vf1_t)(void *, u32);
typedef u32(THISCALL *vf2_t)(void *, u32, u32);
static inline u8 *sysp() { return *(u8 **)0x70039c; }
typedef u32 (*hook0_t)();

extern "C" u32 THISCALL ext_6014a0(void *self, u32 n);
extern "C" void THISCALL ext_4dc600(void *self, u32 *p);
extern "C" u32 THISCALL ext_4dd060(void *self, u32 *p);
extern "C" void THISCALL ext_4dce50(void *self, u32 a);
extern "C" void THISCALL ext_4e6810(void *self);
extern "C" void THISCALL ext_4958e0(void *self);
extern "C" void ext_634273(void *p, u32 n);
extern "C" u32 ext_41e290(u32 n);
extern "C" void THISCALL ext_4e6b40(void *self);
extern "C" u32 THISCALL ext_4e6bc0(void *self);
extern "C" void THISCALL ext_4a44d0(void *self);

// 0x42b290, thiscall(unused) ret 4, returns this: this[0..2] = 0, then a block from 0x6014a0(this, 8): this[0] = this[1] = block, this[2] = block + 8, block[0] = 0 (written
// before the null test, as in the exe).
static u8 *THISCALL fn42b290(u8 *self, u32) {
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  u8 *b = (u8 *)ext_6014a0(self, 8);
  *(u8 **)self = b;
  *(u8 **)(self + 4) = b;
  *(u8 **)(self + 8) = b + 8;
  b[0] = 0;
  if (b) b[0] = 0;
  return self;
}
PCREG(42b290, fn42b290);

// 0x452ad0, thiscall no args, stack cookie (not reproduced): loc = {0,0,0}; 0x4dc600(obj, &loc); 0x4dd060(obj, &loc); 0x4dce50(obj, 0), obj = [this+8].
static void THISCALL fn452ad0(u8 *self) {
  u32 loc[3] = {0, 0, 0};
  ext_4dc600(*(void **)(self + 8), loc);
  ext_4dd060(*(void **)(self + 8), loc);
  ext_4dce50(*(void **)(self + 8), 0);
}
PCREG(452ad0, fn452ad0);

// 0x483570, thiscall(unused) ret 4: obj = [this+0x104]; vt = [obj]; r = word of (engine table +0x9b slot 0x114 (0x68c71c, 0, 0x68bcbc, 0x8cd, 0, 0)); vt[0x128](obj, r).
typedef u32(THISCALL *vf6_t)(void *, u32, u32, u32, u32, u32, u32);
static u32 THISCALL fn483570(u8 *self, u32) {
  void *obj = *(void **)(self + 0x104);
  u32 *vt = *(u32 **)obj;
  void *t = *(void **)(sysp() + 0x9b);
  u32 r = VT(t, vf6_t, 0x114)(t, 0x68c71c, 0, 0x68bcbc, 0x8cd, 0, 0) & 0xffff;
  return ((vf1_t)vt[0x128 / 4])(*(void **)(self + 0x104), r);
}
PCREG(483570, fn483570);

// 0x48ab00, thiscall(flags) ret 4, returns this: vtable 0x68d9bc; free([this+0x18], 8); base body 0x4e6810; free(this, 0x20) when bit 0 of flags.
static u8 *THISCALL fn48ab00(u8 *self, u32 flags) {
  *(u32 *)self = 0x68d9bc;
  ext_634273(*(void **)(self + 0x18), 8);
  ext_4e6810(self);
  if (flags & 1) ext_634273(self, 0x20);
  return self;
}
PCREG(48ab00, fn48ab00);

// 0x48f480, thiscall no args: release the object at +0xadc (slot 0x210 with 1) and clear it; then the object at +8: 0x4958e0, free(.., 0x69), clear.
static void THISCALL fn48f480(u8 *self) {
  void *o = *(void **)(self + 0xadc);
  if (o) {
    VT(o, vf1_t, 0x210)(o, 1);
    *(u32 *)(self + 0xadc) = 0;
  }
  void *p = *(void **)(self + 8);
  if (p) {
    ext_4958e0(p);
    ext_634273(p, 0x69);
    *(u32 *)(self + 8) = 0;
  }
}
PCREG(48f480, fn48f480);

// 0x48fa10, thiscall no args: for the 0x402 dwords at +0xc4d: non-zero -> engine slot 0xfc(ptr), cleared; then the object at +0x1c55 (slot 4 with 1, cleared to 0); +0x1c59 = 0.
static void THISCALL fn48fa10(u8 *self) {
  u32 *a = (u32 *)(self + 0xc4d);
  for (int i = 0; i < 0x402; i++) {
    u32 v = *(u32 *)((u8 *)a + 4 * i);
    if (v) {
      void *s = sysp();
      VT(s, vf1_t, 0xfc)(s, v);
      *(u32 *)((u8 *)a + 4 * i) = 0;
    }
  }
  void *o = *(void **)(self + 0x1c55);
  if (o) {
    VT(o, vf1_t, 4)(o, 1);
    *(u32 *)(self + 0x1c55) = 0;
  }
  *(u32 *)(self + 0x1c59) = 0;
}
PCREG(48fa10, fn48fa10);

// 0x4927c0, thiscall no args: lazily fills +0xaf0 from slot 0x210 (0 or -1 clears it and returns); then +0xaf4 = alloc(+0xaf0) and slot 0x214(this, block, +0xaf0).
static void THISCALL fn4927c0(u8 *self) {
  if (*(u32 *)(self + 0xaf0) == 0) {
    u32 v = VT(self, vf0_t, 0x210)(self);
    *(u32 *)(self + 0xaf0) = v;
    if (v == 0 || v == (u32)-1) {
      *(u32 *)(self + 0xaf0) = 0;
      return;
    }
  }
  if (*(u32 *)(self + 0xaf4) == 0) {
    u32 b = ext_41e290(*(u32 *)(self + 0xaf0));
    *(u32 *)(self + 0xaf4) = b;
    VT(self, vf2_t, 0x214)(self, b, *(u32 *)(self + 0xaf0));
  }
}
PCREG(4927c0, fn4927c0);

// 0x497930, thiscall no args: +0x59 = 0; +0x51 = alloc(0x3fc0); +0x55 = alloc(0x3fc); the second block gets the words 0..0x1fd; then [0x70038c] slot 0x24 (0x68e7d4, 0x3fc0).
static void THISCALL fn497930(u8 *self) {
  *(u32 *)(self + 0x59) = 0;
  *(u32 *)(self + 0x51) = ext_41e290(0x3fc0);
  *(u32 *)(self + 0x55) = ext_41e290(0x3fc);
  u16 *w = *(u16 **)(self + 0x55);
  for (u32 i = 0; i < 0x1fe; i++) w[i] = (u16)i;
  void *o = *(void **)0x70038c;
  if (o) VT(o, vf2_t, 0x24)(o, 0x68e7d4, 0x3fc0);
}
PCREG(497930, fn497930);

// 0x49b680, thiscall no args: vtable 0x68ece4; when [this+0x35] is set: free it (4), the object at +0x2d (0x4e6b40, free 0x15), free([this+0x1d], 4); then tail call 0x4e6b40(this+4).
static void THISCALL fn49b680(u8 *self) {
  *(u32 *)self = 0x68ece4;
  u32 a = *(u32 *)(self + 0x35);
  if (a) {
    ext_634273((void *)a, 4);
    void *e = *(void **)(self + 0x2d);
    if (e) {
      ext_4e6b40(e);
      ext_634273(e, 0x15);
    }
    ext_634273(*(void **)(self + 0x1d), 4);
  }
  ext_4e6b40(self + 4);
}
PCREG(49b680, fn49b680);

// 0x49b6d0, thiscall(unused) ret 4: p = 0x4e6bc0([this+0x2d]); null -> log via [0x700390] (slot 0x20 (0x68ed40, 0x397), then slot 0x30 cdecl (obj, 0x68ee30)) and 0;
// else p[0] = 0, p[1] = 1 and (p - [this+0x1d]) >> 2.
typedef u32(THISCALL *vlg_t)(void *, u32, u32);
typedef void(__attribute__((cdecl)) * vlog_t)(void *, u32);
static u32 THISCALL fn49b6d0(u8 *self, u32) {
  u32 *p = (u32 *)ext_4e6bc0(*(void **)(self + 0x2d));
  if (!p) {
    void *lg = *(void **)0x700390;
    void *o = (void *)VT(lg, vlg_t, 0x20)(lg, 0x68ed40, 0x397);
    ((vlog_t)(*(u32 **)o)[0x30 / 4])(o, 0x68ee30);
    return 0;
  }
  p[0] = 0;
  p[1] = 1;
  return ((u32)p - *(u32 *)(self + 0x1d)) >> 2;
}
PCREG(49b6d0, fn49b6d0);

// 0x4a3600, thiscall(str) ret 4, returns 0: copy the string (with its NUL) to this+0x58; +0x54 clamped to >= 0 (signed); slot 0x3c of this.
static u32 THISCALL fn4a3600(u8 *self, const u8 *s) {
  u8 *d = self + 0x58;
  u8 c;
  do {
    c = *s++;
    *d++ = c;
  } while (c);
  if (*(s32 *)(self + 0x54) < 0) *(u32 *)(self + 0x54) = 0;
  VT(self, vf0_t, 0x3c)(self);
  return 0;
}
PCREG(4a3600, fn4a3600);

// 0x4a4380, thiscall no args: base 0x4a44d0; four lookups through slot 0x104 of the object at +0x44 (names 0x68fc78 / 84 / 9c / b0) stored at +0x48 / +0x4c / +0x50 / +0x54;
// then, for the object at ([this+0x44]+0x18): when its +8 != 1 clear bit 2 of +0x40.
static void THISCALL fn4a4380(u8 *self) {
  ext_4a44d0(self);
  void *o = *(void **)(self + 0x44);
  *(u32 *)(self + 0x48) = VT(o, vf1_t, 0x104)(o, 0x68fc78);
  o = *(void **)(self + 0x44);
  *(u32 *)(self + 0x4c) = VT(o, vf1_t, 0x104)(o, 0x68fc84);
  o = *(void **)(self + 0x44);
  *(u32 *)(self + 0x50) = VT(o, vf1_t, 0x104)(o, 0x68fc9c);
  o = *(void **)(self + 0x44);
  *(u32 *)(self + 0x54) = VT(o, vf1_t, 0x104)(o, 0x68fcb0);
  u8 *g = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  if (*(u32 *)(g + 8) != 1) *(u32 *)(g + 0x40) &= 0xfffffffbu;
}
PCREG(4a4380, fn4a4380);

// 0x4aff50, thiscall(a, p) ret 8, returns 0: r = word of engine table slot 0x114 (0x692114, 0, 0x691edc, 0x961); when (word)a == r and *p == [this+0x48]: *p = [this+0x4c].
typedef u32(THISCALL *vf4_t)(void *, u32, u32, u32, u32);
static u32 THISCALL fn4aff50(u8 *self, u32 a, u32 *p) {
  void *t = *(void **)(sysp() + 0x9b);
  u32 r = VT(t, vf4_t, 0x114)(t, 0x692114, 0, 0x691edc, 0x961) & 0xffff;
  if ((a & 0xffff) == r && *p == *(u32 *)(self + 0x48)) *p = *(u32 *)(self + 0x4c);
  return 0;
}
PCREG(4aff50, fn4aff50);

// 0x4b0590, thiscall(p) ret 4, returns true (AL): clear bit 6 of +4; the assert hook 0x7003b0 (int3 when null; result unused); slot 0x98(this, 0); p slot 0x48(p, this+0x48).
static u8 THISCALL fn4b0590(u8 *self, u8 *p) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  hook0_t h = *(hook0_t *)0x7003b0;
  if (!h) __asm__ volatile("int3");
  h();
  VT(self, vf1_t, 0x98)(self, 0);
  VT(p, vf1_t, 0x48)(p, (u32)(self + 0x48));
  return 1;
}
PCREG(4b0590, fn4b0590);
