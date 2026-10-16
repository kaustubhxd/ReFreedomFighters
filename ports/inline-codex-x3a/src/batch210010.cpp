// batch210010.cpp - Sonnet-w3a: small BLOCKED rows (loops over member pointers, dtors with flags, engine-table slot chains, list walk)
#include "ff.h"

extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_6363a0(u8 *self);
extern "C" u32 FASTCALL ext_4daf20(u32 ecx, u32 edx);
extern "C" u32 THISCALL ext_496ce0(u8 *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_45c3e0(u8 *self);
extern "C" u32 ext_45c510(u8 *self);
extern "C" u32 ext_4690b0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_52e0a0(u8 *self, u32 a, u32 b, u32 c);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn5ac5d0(u8 *self, u32 a) {
  u32 i = 0;
  if (ld32(self + 0x7f) > i) {
    u8 *p = self + 0x1a;
    do {
      u8 *o = *(u8 **)p;
      vcall<u32, u32>(o, 0x248, a);  // @5ac5d0_a
      i++;
      p += 4;
    } while (i < ld32(self + 0x7f));  // @5ac5d0_b
  }
}
PCREG(5ac5d0, fn5ac5d0);

static u8 *THISCALL fn616a60(u8 *self, u32 flags) {
  u32 p = *(u32 *)(self + 0xc);
  *(u32 *)self = 0x6bdd68;  // @616a60_v1
  if (p) ext_634273(p, 0x40);  // @616a60_a
  *(u32 *)self = 0x6bdc40;  // @616a60_v2
  if (flags & 1) ext_634273((u32)self, 0x10);  // @616a60_b
  return self;
}
PCREG(616a60, fn616a60);

static u8 *THISCALL fn6364a0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6c1fec;  // @6364a0_v
  if (self[0x31]) ext_634273(ld32(self + 0x2d), 4);  // @6364a0_a
  ext_6363a0(self);  // @6364a0_b
  if (flags & 1) ext_634273((u32)self, 0x36);  // @6364a0_c
  return self;
}
PCREG(6364a0, fn6364a0);

static u32 THISCALL fn496d70(u8 *self, u32 a, u8 *b) {
  u32 ecx;
  u8 *m = *(u8 **)(b + 0x54);
  if (m) ecx = ld32(*(u8 **)(m + 0xc) + 0x23);  // @496d70_a
  else ecx = 0x200002;  // @496d70_b
  u32 r = ext_4daf20(ecx, *(u32 *)(b + 0x3c));  // @496d70_c
  return ext_496ce0(*(u8 **)(self + 0x1c), a, (u32)b, r);  // @496d70_d
}
PCREG(496d70, fn496d70);

static u32 THISCALL fn5b22a0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *m = (u8 *)ld32(eng + 0x9b);
  u8 *s = (u8 *)vcall<u32>(m, 0x138);  // @5b22a0_a
  u8 *m2 = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u8 *, u32>(m2, 0x4c, self, 0x10);  // @5b22a0_b
  return vcall<u32, u32, u32>(s, 0x60, 0x6b007c, r);  // @5b22a0_c
}
PCREG(5b22a0, fn5b22a0);

static u32 fn48d010() {
  u8 *eng = G(u8 *, 0x70039c);
  u32 local = *(u32 *)(*(u8 **)(ld32(eng + 0x9b) + 0xadc) + 8);
  if (local) {
    do {
      *(u32 *)(local + 0x3c) &= 0xffefffffu;  // @48d010_a
      u8 *list = *(u8 **)(ld32(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
      vcall<u32, u32 *>(list, 0x50, &local);  // @48d010_b
    } while (local);
  }
  return 0;
}
PCREG(48d010, fn48d010);

static u8 *THISCALL fn43de80(u8 *self, u32 flags) {
  *(u32 *)self = 0x67c3a4;  // @43de80_v
  ext_45c3e0(self);  // @43de80_a
  if (flags & 1) {
    if (!(flags & 4)) {
      ext_45c510(self);  // @43de80_b
      return self;
    }
    ext_4690b0(self, 0x18);  // @43de80_c
  }
  return self;
}
PCREG(43de80, fn43de80);

typedef u32 (*HookU)();
static u32 THISCALL fn52a800(u8 *self, u32 a, u32 b, u32 c) {
  if (self[0x31]) return ext_52e0a0((u8 *)ld32(self + 0x65), a, b, c);  // @52a800_a
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x6a0f54, 0x26a9);  // @52a800_b
  typedef u32 (*F)(u8 *, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x6a10a4);  // @52a800_c
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h() & ~0xffu;  // @52a800_d
}
PCREG(52a800, fn52a800);
