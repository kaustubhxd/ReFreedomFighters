// batch36033.cpp - cascade s4 batch 36033: 0x55fbd0, 0x575160, 0x561200 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4
extern "C" u8 *THISCALL ext_5a45c0(void *self, u32 a);   // ret 4
extern "C" u8 *THISCALL ext_5a4610(void *self, u32 a);   // ret 4

// 0x55fbd0, stdcall(p) ret 4: a, b, c, d = *ext_5003d0(p[4], 0..3). a == 0: nothing. x = sys[0x9b]->slot 0x58(a); q = 0x5a45c0(G[0x7003b8][0x2c21], x): q[8] += c, q[0xc] += d, q[4] += b (when q).
// r = 0x5a4610(G[0x7003b8][0x2c21], a): r[6] += d + c, r[0xa] += b (unaligned dwords); no r: logger(0x6a622c, 0x15b) slot 0x30 prints 0x6a6268.
static void STDCALL fn55fbd0(u8 *p) {
  u8 *src = *(u8 **)(p + 4);
  u32 a = rd(ext_5003d0(src, 0));
  u32 b = rd(ext_5003d0(src, 1));
  u32 c = rd(ext_5003d0(src, 2));
  u32 d = rd(ext_5003d0(src, 3));
  if (a == 0) return;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v1o_t **)tab)[0x58 / 4](tab, a);
  u8 *q = ext_5a45c0((void *)rd(G(u8 *, 0x7003b8) + 0x2c21), (u32)x);
  if (q) {
    wr(q + 8, rd(q + 8) + c);
    wr(q + 0xc, rd(q + 0xc) + d);
    wr(q + 4, rd(q + 4) + b);
  }
  u8 *r = ext_5a4610((void *)rd(G(u8 *, 0x7003b8) + 0x2c21), a);
  if (r) {
    wr(r + 6, rd(r + 6) + (d + c));
    wr(r + 0xa, rd(r + 0xa) + b);
    return;
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x6a622cu, 0x15bu);
  void *fn = *(void **)((u8 *)*(void ***)o + 0x30);
  ((void (*)(u8 *, u32))fn)(o, 0x6a6268u);
}
PCREG(55fbd0, fn55fbd0);

extern "C" void THISCALL ext_562440(void *self);

static bool same_str(const u8 *x, const u8 *y) {
  for (;;) {
    if (*x != *y) return false;
    if (*x == 0) return true;
    x++;
    y++;
  }
}

// 0x575160, thiscall() (this = b): 0x562440(b); e = b[0x94]; name = e + 0x48.
// name == str 0x6a6e5c and e[0x1040] == 0: return. name == str 0x6a8558: return. Else o = sys[0x9b]->slot 0x138(); x = sys[0x9b]->slot 0x4c(b[0x44], 0x10); o->slot 0x60(0x6a6db0, x).
static void THISCALL fn575160(u8 *b) {
  ext_562440(b);
  u8 *e = *(u8 **)(b + 0x94);
  u8 *name = e + 0x48;
  if (same_str(name, (const u8 *)0x6a6e5c) && e[0x1040] == 0) return;
  if (same_str(name, (const u8 *)0x6a8558)) return;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v2o_t **)tab)[0x4c / 4](tab, rd(b + 0x44), 0x10);
  (*(v2_t **)o)[0x60 / 4](o, 0x6a6db0u, (u32)x);
}
PCREG(575160, fn575160);

// 0x561200, thiscall(dest) ret 4 (this = s): mode = 0; when s[0xf4]: slot 0x1e0(0x80100032) (low byte) -> mode = slot 0x354(). mode 1 -> 0x6a67d4, 2 -> 0x6a67f8, 3 -> 0x6a680c, else return.
// src = sys[0x9b][0xae4]->slot 0(0x6a67e8, chosen) (stdcall 2 args). Append the 2 bytes at 0x679e6c to dest, then append src (with its NUL) after the first NUL found from dest.
static void THISCALL fn561200(u8 *s, u8 *dest) {
  u32 mode = 0;
  u8 *w = *(u8 **)(s + 0xf4);
  if (w) {
    if ((u8)(*(v1r_t **)w)[0x1e0 / 4](w, 0x80100032u)) {
      w = *(u8 **)(s + 0xf4);
      mode = (*(v0r_t **)w)[0x354 / 4](w);
    }
  }
  u32 chosen;
  if (mode == 1) chosen = 0x6a67d4;
  else if (mode == 2) chosen = 0x6a67f8;
  else if (mode == 3) chosen = 0x6a680c;
  else return;
  u8 *o = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xae4);
  u8 *src = (*(v2o_t **)o)[0](o, 0x6a67e8u, chosen);
  u8 *end = dest;
  while (*end) end++;
  end[0] = ((u8 *)0x679e6c)[0];
  end[1] = ((u8 *)0x679e6c)[1];
  u32 n = 0;
  while (src[n++]) {}
  u8 *d = dest;
  while (*d) d++;
  for (u32 i = 0; i < n; i++) d[i] = src[i];
}
PCREG(561200, fn561200);
