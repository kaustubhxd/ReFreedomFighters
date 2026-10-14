// batch36009.cpp - cascade s4 batch 36009: 0x49dfd0, 0x4a4e80, 0x4c96f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline void sl(u8 *s, u32 off, u8 *dst) { (*(v1_t **)s)[off / 4](s, (u32)dst); }

// 0x49dfd0, thiscall(a, b) ret 8 (this = E): path join into a 0xcc stack buffer: a, then '/' when both non-empty, then b; r = E->slot 4(buf); returns r ? r : b.
static u32 THISCALL fn49dfd0(u8 *E, const u8 *a, const u8 *b) {
  u8 buf[0xcc];
  u32 n = 0;
  while (a[n]) n++;
  if (n != 0) {
    u32 i = 0;
    do { buf[i] = a[i]; } while (a[i++] != 0);
    u32 m = 0;
    while (b[m]) m++;
    if (m != 0) buf[n++] = '/';
  }
  u32 j = 0;
  do { buf[n + j] = b[j]; } while (b[j++] != 0);
  u32 r = (*(v1r_t **)E)[4 / 4](E, (u32)buf);
  return r ? r : (u32)b;
}
PCREG(49dfd0, fn49dfd0);

// 0x4a4e80, thiscall(s) ret 4, returns 1: this[4] &= ~0x40; reads from the stream s: slot 0x44 -> +0x48, slot 0x68 -> +0x5f, +0x60, +0x61, +0x62, slot 0x58 -> +0x56,
// slot 0x50 -> +0x5a, slot 0x68 -> +0x63, slot 0x50 -> +0x4a, slot 0x68 -> +0x64.
static u8 THISCALL fn4a4e80(u8 *E, u8 *s) {
  *(u32 *)(E + 4) &= 0xffffffbfu;
  sl(s, 0x44, E + 0x48);
  sl(s, 0x68, E + 0x5f);
  sl(s, 0x68, E + 0x60);
  sl(s, 0x68, E + 0x61);
  sl(s, 0x68, E + 0x62);
  sl(s, 0x58, E + 0x56);
  sl(s, 0x50, E + 0x5a);
  sl(s, 0x68, E + 0x63);
  sl(s, 0x50, E + 0x4a);
  sl(s, 0x68, E + 0x64);
  return 1;
}
PCREG(4a4e80, fn4a4e80);

// 0x4c96f0, thiscall(s) ret 4, returns 1: this[4] &= ~0x40; slot 0x6c -> +0x4c; slot 0x68 -> +0x58, +0x59, +0x5a; slot 0x44 -> +0x48, +0x4a; slot 0x58 -> +0x5b;
// slot 0x6c -> +0x5f, +0x6b, +0x77.
static u8 THISCALL fn4c96f0(u8 *E, u8 *s) {
  *(u32 *)(E + 4) &= 0xffffffbfu;
  sl(s, 0x6c, E + 0x4c);
  sl(s, 0x68, E + 0x58);
  sl(s, 0x68, E + 0x59);
  sl(s, 0x68, E + 0x5a);
  sl(s, 0x44, E + 0x48);
  sl(s, 0x44, E + 0x4a);
  sl(s, 0x58, E + 0x5b);
  sl(s, 0x6c, E + 0x5f);
  sl(s, 0x6c, E + 0x6b);
  sl(s, 0x6c, E + 0x77);
  return 1;
}
PCREG(4c96f0, fn4c96f0);

typedef u32(THISCALL *v1u_t)(void *, u32);
typedef void(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);

// 0x4f2b30, thiscall(a, flag) ret 8 (this = E): returns unless E[0x64] == a. flag byte set and p->slot 0x1e0(0x80100032) and q = p->slot 0x318(0): E->slot 0x2ec(q), return.
// Otherwise E->slot 0x2dc(0x40, 0, 0, p); E[0x64] = 0; r = [[0x70039c]+0x9b]->slot 0x4c(0); E->slot 0x2dc(0x100000, r, 0, 0).
static void THISCALL fn4f2b30(u8 *E, u8 *a, u32 flag) {
  u8 *p = *(u8 **)(E + 0x64);
  if (p != a) return;
  if ((u8)flag) {
    if ((*(v1b_t **)p)[0x1e0 / 4](p, 0x80100032u)) {
      u8 *pp = *(u8 **)(E + 0x64);
      u32 q = (*(v1u_t **)pp)[0x318 / 4](pp, 0);
      if (q) {
        (*(v1u_t **)E)[0x2ec / 4](E, q);
        return;
      }
    }
  }
  (*(v4_t **)E)[0x2dc / 4](E, 0x40, 0, 0, (u32)p);
  *(u32 *)(E + 0x64) = 0;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = (*(v1u_t **)tab)[0x4c / 4](tab, *(u32 *)(E + 0x64));
  (*(v4_t **)E)[0x2dc / 4](E, 0x100000, r, 0, 0);
}
PCREG(4f2b30, fn4f2b30);

extern "C" void THISCALL ext_4fa350(void *self, u32 a);  // ret 4
typedef u8 *(THISCALL *v0o_t)(void *);
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v5_t)(void *, u32, u32, u32, u32, u32);

// 0x4f8ff0, thiscall(a) ret 4, returns bool (this = E): 0x4fa350(E, a); E->slot 0x110(0x10, 0); (E[0x1bf])->slot 0xbc(0); E->slot 0x2c4()->slot 0x328();
// E[0x1db] = 0; p = E[0x1bb]: null returns 0. len = strlen(p[0x97]) (0 when null); E->slot 0x364(len); E->slot 0x2c4()->slot 0x34c(0x1c, 0, E, 0, 0); returns 1.
static u8 THISCALL fn4f8ff0(u8 *E, u32 a) {
  ext_4fa350(E, a);
  (*(v2_t **)E)[0x110 / 4](E, 0x10, 0);
  u8 *o = *(u8 **)(E + 0x1bf);
  (*(v1u_t **)o)[0xbc / 4](o, 0);
  u8 *y = (*(v0o_t **)E)[0x2c4 / 4](E);
  (*(v0_t **)y)[0x328 / 4](y);
  *(u32 *)(E + 0x1db) = 0;
  u8 *p = *(u8 **)(E + 0x1bb);
  if (!p) return 0;
  const u8 *q = *(const u8 **)(p + 0x97);
  u32 len = 0;
  if (q) while (q[len]) len++;
  (*(v1u_t **)E)[0x364 / 4](E, len);
  y = (*(v0o_t **)E)[0x2c4 / 4](E);
  (*(v5_t **)y)[0x34c / 4](y, 0x1c, 0, (u32)E, 0, 0);
  return 1;
}
PCREG(4f8ff0, fn4f8ff0);
