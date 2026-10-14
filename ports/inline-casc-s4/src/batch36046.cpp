// batch36046.cpp - cascade s4 batch 36046: 0x5fccb0, 0x422ed0, 0x444380, 0x48dbd0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v5_t)(void *, u32, u32, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 FASTCALL ext_4cc4b0(u32 a, u32 b);   // case-insensitive char equality, al

// 0x5fccb0, thiscall() plain ret (this = s, a string [s[0], s[4])): repeat: empty -> return; find the first char equal (case-insensitive, via 0x4cc4b0) to '/'; none -> return; replace it with the byte at 0x67856c ('\\') and start again.
// (The original's other branches, memmove / 0x430d10, are unreachable: the replaced range is always exactly one char.)
static void THISCALL fn5fccb0(u8 *s) {
  for (;;) {
    u8 *end = *(u8 **)(s + 4);
    u8 *p = *(u8 **)s;
    if (end == p) return;
    while (p != end) {
      if ((u8)ext_4cc4b0(*p, 0x2f)) break;
      p++;
    }
    if (p == *(u8 **)(s + 4)) return;
    *p = G(u8, 0x67856c);
  }
}
PCREG(5fccb0, fn5fccb0);

// 0x422ed0, thiscall(a, b) ret 8 (this = s): x = [0x70039c]->slot 0x1c8(0x677fb4, 0xb4f, a, b); s->slot 0x1b8(x); then s->slot 0x1fc(s + off, size, kind, a, b) for (0xa07, 0x500, 1), (0xf07, 0xa00, 2), (0x9e3, 4, 3), (0x9e7, 0xc, 4), (0x9f3, 0xc, 5).
static void THISCALL fn422ed0(u8 *s, u32 a, u32 b) {
  void **vt = *(void ***)s;
  u8 *g = G(u8 *, 0x70039c);
  u32 x = (u32)(*(v4r_t **)g)[0x1c8 / 4](g, 0x677fb4u, 0xb4fu, a, b);
  ((v1_t)vt[0x1b8 / 4])(s, x);
  ((v5_t)(*(void ***)s)[0x1fc / 4])(s, (u32)(s + 0xa07), 0x500, 1, a, b);
  ((v5_t)(*(void ***)s)[0x1fc / 4])(s, (u32)(s + 0xf07), 0xa00, 2, a, b);
  ((v5_t)(*(void ***)s)[0x1fc / 4])(s, (u32)(s + 0x9e3), 4, 3, a, b);
  ((v5_t)(*(void ***)s)[0x1fc / 4])(s, (u32)(s + 0x9e7), 0xc, 4, a, b);
  ((v5_t)(*(void ***)s)[0x1fc / 4])(s, (u32)(s + 0x9f3), 0xc, 5, a, b);
}
PCREG(422ed0, fn422ed0);

extern "C" void THISCALL ext_442c30(void *self, void *a);          // ret 4
extern "C" u32 THISCALL ext_4e1600(void *a);                       // plain ret, low byte = kind
extern "C" void THISCALL ext_4e12e0(void *a, u32 *p, u32 f);       // ret 8 (jmp 0x4e11e0)
extern "C" void THISCALL ext_4e1b30(void *a);                      // plain ret

// 0x444380, thiscall(a) ret 4 (this = d): 0x442c30(d, a); kind(a) == 2 -> assert hook (int3 when none). kind != 0xff -> 0x4e12e0(a, d + 0x98, 1); kind != 0xff -> 0x4e12e0(a, d + 0x94, 1).
// kind == 3 -> t = 0, 0x4e12e0(a, &t, 1), t != 0 -> d->slot 0x378(4, 0); kind == 3 -> 0x4e12e0(a, &u, 1), u != 0 -> d[0x30] |= 0x80. d[0x30] &= 0xfcffffff; 0x4e1b30(a).
static void THISCALL fn444380(u8 *d, u8 *a) {
  ext_442c30(d, a);
  if ((u8)ext_4e1600(a) == 2) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  if ((u8)ext_4e1600(a) != 0xff) {
    ext_4e12e0(a, (u32 *)(d + 0x98), 1);
    if ((u8)ext_4e1600(a) != 0xff) ext_4e12e0(a, (u32 *)(d + 0x94), 1);
  }
  if ((u8)ext_4e1600(a) == 3) {
    u32 t = 0;
    ext_4e12e0(a, &t, 1);
    if (t != 0) (*(v2_t **)d)[0x378 / 4](d, 4, 0);
    if ((u8)ext_4e1600(a) == 3) {
      u32 u = 0;
      ext_4e12e0(a, &u, 1);
      if (u != 0) wr(d + 0x30, rd(d + 0x30) | 0x80);
    }
  }
  wr(d + 0x30, rd(d + 0x30) & 0xfcffffffu);
  ext_4e1b30(a);
}
PCREG(444380, fn444380);

// 0x48dbd0, thiscall(A, B, arr, n) ret 0x10 (this = s): s[0xadc] == 0 -> A[0]++, B[0] += 0x60. For each of n triples (id, x, y) in arr: A[0] += x; o = tab->slot 0x158(id); size = o ? o[0x18] : 0x18 (logger(0x68d798, 0x804) prints (cdecl 3 args) 0x68d8c8, id when missing);
// size = (size + 15) & ~15; B[0] += x * size; s->slot 0xcc() (low byte) zero -> B[0] -= y * size. Finally B[0] += 0x7800, A[0] += 0x112.
static void THISCALL fn48dbd0(u8 *s, u32 *A, u32 *B, u32 *arr, u32 n) {
  if (rd(s + 0xadc) == 0) {
    A[0]++;
    B[0] += 0x60;
  }
  if (n) {
    u32 *e = arr;
    do {
      A[0] += e[1];
      u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *o = (*(v1o_t **)tab)[0x158 / 4](tab, e[0]);
      u32 size;
      if (o) {
        size = rd(o + 0x18);
      } else {
        u8 *db = G(u8 *, 0x700390);
        u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x68d798u, 0x804u);
        void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
        ((void (*)(u8 *, u32, u32))fn)(lo, 0x68d8c8u, e[0]);
        size = 0x18;
      }
      size = (size + 0xf) & 0xfffffff0u;
      B[0] += e[1] * size;
      if (!(u8)(*(v0r_t **)s)[0xcc / 4](s)) B[0] -= e[2] * size;
      e += 3;
      n--;
    } while (n != 0);
  }
  B[0] += 0x7800;
  A[0] += 0x112;
}
PCREG(48dbd0, fn48dbd0);
