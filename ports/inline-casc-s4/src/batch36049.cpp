// batch36049.cpp - cascade s4 batch 36049: 0x424ee0, 0x52a600, 0x52dfc0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(STDCALL *atom_t)(u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void ext_42abee(u8 *buf, u32 fmt, u32 *va);   // cdecl

// 0x424ee0, cdecl(p, fmt, ...) plain ret: p[0x24] == 0 -> return. buf = format(fmt, args); buf[0] == 0: logger(0x6786c4, 0x1b9) prints 0x678738, return. ax = (u16)GlobalAddAtomA(buf): nonzero -> p->slot 0x18(0xc, ax, 0), return.
// else logger(0x6786c4, 0x1c0) prints 0x678770, buf.
static void fn424ee0(u8 *p, u32 fmt, u32 a1, u32 a2) {
  u8 buf[0x400];
  (void)a2;
  if (rd(p + 0x24) == 0) return;
  ext_42abee(buf, fmt, &a1);
  if (buf[0] == 0) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6786c4u, 0x1b9u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x678738u);
    return;
  }
  u32 ax = (u16)G(atom_t, 0x6760f4)((u32)buf);
  if (ax) {
    (*(v3_t **)p)[0x18 / 4](p, 0xc, ax, 0);
    return;
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6786c4u, 0x1c0u);
  void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
  ((void (*)(u8 *, u32, u8 *))fn)(lo, 0x678770u, buf);
}
PCREG(424ee0, fn424ee0);

extern "C" void ext_634273(u32 a, u32 b);              // cdecl
extern "C" void ext_41e2c0(u32 a);                     // cdecl
extern "C" void THISCALL ext_43de70(void *self);       // tail target: sets the vtable and chains

// 0x52a600, thiscall() (this = s): s[0] = 0x6a0c7c; free (634273(ptr, size)) s[0x3a] (0x34), delete s[0x65] (slot 0 with 1), free s[0x1c] (0x231), s[0x18] (0x11); e = s[0x79]: free *e (0x32), free e (0x14);
// delete s[0x2d] and s[0x32] (slot 0, 1); free s[0x42] (0x34); s[0x7d] -> 0x41e2c0(s[0x7d]); then tail 0x43de70(s).
static void THISCALL fn52a600(u8 *s) {
  wr(s, 0x6a0c7c);
  u32 a = rd(s + 0x3a);
  if (a) ext_634273(a, 0x34);
  u8 *o = *(u8 **)(s + 0x65);
  if (o) (*(v1_t **)o)[0](o, 1);
  a = rd(s + 0x1c);
  if (a) ext_634273(a, 0x231);
  a = rd(s + 0x18);
  if (a) ext_634273(a, 0x11);
  u8 *e = *(u8 **)(s + 0x79);
  if (e) {
    u32 x = rd(e);
    if (x) ext_634273(x, 0x32);
    ext_634273((u32)e, 0x14);
  }
  o = *(u8 **)(s + 0x2d);
  if (o) (*(v1_t **)o)[0](o, 1);
  o = *(u8 **)(s + 0x32);
  if (o) (*(v1_t **)o)[0](o, 1);
  a = rd(s + 0x42);
  if (a) ext_634273(a, 0x34);
  a = rd(s + 0x7d);
  if (a) ext_41e2c0(a);
  ext_43de70(s);
}
PCREG(52a600, fn52a600);

extern "C" void THISCALL ext_531740(void *self, u8 *a, u32 b);         // ret 8
extern "C" u32 THISCALL ext_52dbb0(void *self, u8 *p, u8 *q, u32 z);   // ret 0xc

// 0x52dfc0, thiscall(a, b) ret 8 returns al (this = s): a[0..2] == b[0..2] (u16) -> 1. Else C = {s, s + 0x96, 0x40}; 0x531740(&C, a, s[0x38]); dx = u16 at C + 0x16;
// A = {dx, _, a[0], a[1], a[2]} (u16 at +0, +4, +6, +8), B = {dx, _, b[0], b[1], b[2]}; return 0x52dbb0(s, &A, &B, 0) != 0.
static u8 THISCALL fn52dfc0(u8 *s, u16 *a, u16 *b) {
  if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) return 1;
  u32 C[6];
  u16 A[12];
  u16 B[12];
  C[0] = (u32)s;
  C[1] = (u32)(s + 0x96);
  C[2] = 0x40;
  ext_531740(C, (u8 *)a, rd(s + 0x38));
  u16 dx = *(u16 *)((u8 *)C + 0x16);
  A[2] = a[0];
  A[3] = a[1];
  A[4] = a[2];
  B[2] = b[0];
  B[3] = b[1];
  B[4] = b[2];
  A[0] = dx;
  B[0] = dx;
  return ext_52dbb0(s, (u8 *)A, (u8 *)B, 0) != 0;
}
PCREG(52dfc0, fn52dfc0);
