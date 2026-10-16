// batch210011.cpp - Sonnet-w3a: small BLOCKED rows (engine-table chain family, global refcount release, out-param call)
#include "ff.h"

extern "C" u32 THISCALL ext_5fa590(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_50a600(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_506220(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_55fb90(u8 *self, u32 a, u32 b);
extern "C" u32 ext_61dba0(u8 *a, u32 b, u32 *pc, u32 c, u32 d);
extern "C" u32 ext_620bc0(u8 *a, u32 b, u32 c, u32 d);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn50a600(u8 *self, u8 *a, u32 b) {
  ext_5fa590(self, (u32)a, b);  // @50a600_a
  u8 *s = (u8 *)ld32(a + 0x15);
  u8 *vt = *(u8 **)s;
  u32 v = *(u32 *)(self + 0xc);  // @50a600_b
  u8 *m = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u32>(m, 0x4c, v);  // @50a600_c
  typedef u32 (THISCALL *F)(u8 *, u32);
  return (*(F *)(vt + 0x3c))(s, r);  // @50a600_d
}
PCREG(50a600, fn50a600);

static u32 THISCALL fn506220(u8 *self, u8 *a, u32 b) {
  ext_50a600(self, (u32)a, b);  // @506220_a
  u8 *s = (u8 *)ld32(a + 0x15);
  u8 *vt = *(u8 **)s;
  u32 v = *(u32 *)(self + 0x14);  // @506220_b
  u8 *m = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u32>(m, 0x4c, v);  // @506220_c
  typedef u32 (THISCALL *F)(u8 *, u32);
  return (*(F *)(vt + 0x3c))(s, r);  // @506220_d
}
PCREG(506220, fn506220);

static u32 THISCALL fn55fb90(u8 *self, u8 *a, u32 b) {
  ext_506220(self, (u32)a, b);  // @55fb90_a
  u8 *s = (u8 *)ld32(a + 0x15);
  u8 *vt = *(u8 **)s;
  u32 v = *(u32 *)(self + 0x18);  // @55fb90_b
  u8 *m = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u32>(m, 0x4c, v);  // @55fb90_c
  typedef u32 (THISCALL *F)(u8 *, u32);
  return (*(F *)(vt + 0x3c))(s, r);  // @55fb90_d
}
PCREG(55fb90, fn55fb90);

static u32 THISCALL fn55edc0(u8 *self, u8 *a, u32 b) {
  ext_55fb90(self, (u32)a, b);  // @55edc0_a
  u8 *s = (u8 *)ld32(a + 0x15);
  u8 *vt = *(u8 **)s;
  u32 v = *(u32 *)(self + 0x1c);  // @55edc0_b
  u8 *m = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u32>(m, 0x4c, v);  // @55edc0_c
  typedef u32 (THISCALL *F)(u8 *, u32);
  return (*(F *)(vt + 0x3c))(s, r);  // @55edc0_d
}
PCREG(55edc0, fn55edc0);

static u32 fn61fd10(u8 *a, u32 b, u32 c, u32 d) {
  u32 r = ext_61dba0(a, *(u32 *)(a + 0x8c), &b, c, d);  // @61fd10_a
  if (b) {
    *(u32 *)(a + 0x110) = 0x620bc0;  // @61fd10_b
    r = ext_620bc0(a, b, c, d);  // @61fd10_c
  }
  return r;
}
PCREG(61fd10, fn61fd10);

static void fn545350() {
  u32 n = G(u32, 0x711b8c) - 1;
  G(u32, 0x711b8c) = n;
  if (n != 0) return;
  u8 *eng = G(u8 *, 0x70039c);
  vcall<u32, u32>(eng, 0x1a8, G(u32, 0x711b84));  // @545350_a
  u8 *o = G(u8 *, 0x711b84);
  if (o) vcall<u32, u32>(o, 0, 1);  // @545350_b
  eng = G(u8 *, 0x70039c);
  u32 p2 = G(u32, 0x711b88);
  G(u32, 0x711b84) = 0;  // @545350_c
  vcall<u32, u32>(eng, 0x1a8, p2);  // @545350_d
  o = G(u8 *, 0x711b88);
  if (o) vcall<u32, u32>(o, 0, 1);  // @545350_e
  G(u32, 0x711b88) = 0;  // @545350_f
}
PCREG(545350, fn545350);
