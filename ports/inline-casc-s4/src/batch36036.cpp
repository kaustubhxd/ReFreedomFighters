// batch36036.cpp - cascade s4 batch 36036: 0x63f9f0, 0x64d9e0, 0x65c730, 0x40b6f0, 0x470920 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x63f9f0, thiscall(p) ret 4: pool slot release like 0x616000 with record size 0x18 (E[0xc]--; b = E->slot 0x2c(p); p[5] &= 0xfd; p[0..1] = u16 b[2]; b[0]--; b[2..3] = (u16)((p - b - 0x10) / 0x18); then the same ring unlink / relink).
static void THISCALL fn63f9f0(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  p[5] &= 0xfd;
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x18);
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(63f9f0, fn63f9f0);

// 0x64d9e0, thiscall(p) ret 4: the same with record size 0x14.
static void THISCALL fn64d9e0(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  p[5] &= 0xfd;
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x14);
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(64d9e0, fn64d9e0);

extern "C" u8 *THISCALL ext_659000(u32 self);   // plain ret, returns a record pointer or 0

// 0x65c730, thiscall() (this = s): X = s[0x10051]; X[0x48] += s[0x20]; X[0x40] += (s+0x10171)->slot 4(); X[0x54] += (s+0x10199)->slot 4();
// then for i < s[0x20] over p = s + 0x28 and prev = -1: f = p[0]; f != prev: if (f & 0x78000000) == 0x78000000 or (f & 0xf) == 6: p += 8 (prev unchanged);
// else when (f ^ prev) & 0x7ff0 and q = p[1][8] != 0 and r = 0x659000(q) != 0: X[0x4c]++, X[0x50] += r[0xc][8]; then prev = p[0] (also when the bits were equal).
static void THISCALL fn65c730(u8 *s) {
  u8 *X = *(u8 **)(s + 0x10051);
  wr(X + 0x48, rd(X + 0x48) + rd(s + 0x20));
  u8 *o1 = s + 0x10171;
  u8 *Xa = *(u8 **)(s + 0x10051);
  u32 r1 = (*(v0r_t **)o1)[4 / 4](o1);
  wr(Xa + 0x40, rd(Xa + 0x40) + r1);
  u8 *o2 = s + 0x10199;
  u8 *Xb = *(u8 **)(s + 0x10051);
  u32 r2 = (*(v0r_t **)o2)[4 / 4](o2);
  wr(Xb + 0x54, rd(Xb + 0x54) + r2);
  u8 *p = s + 0x28;
  u32 prev = 0xffffffffu;
  u32 i = 0;
  if (rd(s + 0x20) == 0) return;
  do {
    u32 f = rd(p);
    if (prev != f) {
      if ((f & 0x78000000u) == 0x78000000u) {
        p += 8;
      } else if ((u8)(f & 0xf) == 6) {
        p += 8;
      } else {
        if ((f ^ prev) & 0x7ff0u) {
          u8 *q = *(u8 **)(*(u8 **)(p + 4) + 8);
          if (q) {
            u8 *r = ext_659000((u32)q);
            if (r) {
              u8 *X2 = *(u8 **)(s + 0x10051);
              wr(X2 + 0x4c, rd(X2 + 0x4c) + 1);
              u8 *X3 = *(u8 **)(s + 0x10051);
              wr(X3 + 0x50, rd(X3 + 0x50) + rd(*(u8 **)(r + 0xc) + 8));
            }
          }
        }
        prev = rd(p);
      }
    }
    i++;
  } while (i != rd(s + 0x20));
}
PCREG(65c730, fn65c730);

// 0x40b6f0, cdecl(a0, a1, a2, a3, dst): D = a1 - a0; q = (a3 - a2) / D (signed); step = a3 >= a2 ? q + 1 : q - 1; rem = |a3 - a2| - |q * D|; t = (u32 *)0x6f1f58;
// dst[a0] = t[a2]; for the other a1 - a0 - 1 slots (when a0 + 1 < a1): Bresenham step: acc += rem; if acc < D addr += q * 4 else acc -= D, addr += step * 4; dst[i] = *addr.
static void fn40b6f0(s32 a0, s32 a1, s32 a2, s32 a3, u32 *dst) {
  s32 diff = a3 - a2;
  s32 D = a1 - a0;
  s32 ad = diff < 0 ? -diff : diff;
  s32 q = diff / D;
  s32 step = diff >= 0 ? q + 1 : q - 1;
  s32 qd = q * D;
  s32 aq = qd < 0 ? -qd : qd;
  s32 rem = ad - aq;
  u32 *t = (u32 *)0x6f1f58;
  u32 addr = (u32)(t + a2);
  dst[a0] = t[a2];
  s32 i = a0 + 1;
  if (i < a1) {
    s32 cnt = a1 - i;
    u32 *p = dst + i;
    s32 acc = 0;
    do {
      acc += rem;
      if (acc < D) {
        addr += (u32)q * 4u;
      } else {
        acc -= D;
        addr += (u32)step * 4u;
      }
      *p = *(u32 *)addr;
      p++;
      cnt--;
    } while (cnt != 0);
  }
}
PCREG(40b6f0, fn40b6f0);

// 0x470920, thiscall() (this = s): w = s->slot 0x350(); !w->slot 0x32c() -> return. x = s->slot 0x2f4(): none -> return. y = s->slot 0x2f4(); when y->slot 0x1e0(0x200074) (low byte) and s->slot 0x2f4()->slot 0x420() == 1 -> return.
// o = sys[0x9b]->slot 0x138(); o->slot 0x88(0x688d74, &id) (id = 0); flag = 1; ax = sys[0x9b]->slot 0x114(0x688d80, 0, 0x6887c4, 0xc9e, &flag); s->slot 0x12c(id, (u16)ax).
static void THISCALL fn470920(u8 *s) {
  u8 *w = (*(v0o_t **)s)[0x350 / 4](s);
  if (!(u8)(*(v0r_t **)w)[0x32c / 4](w)) return;
  if (!(*(v0r_t **)s)[0x2f4 / 4](s)) return;
  u8 *y = (*(v0o_t **)s)[0x2f4 / 4](s);
  if ((u8)(*(v1r_t **)y)[0x1e0 / 4](y, 0x200074u)) {
    u8 *z = (*(v0o_t **)s)[0x2f4 / 4](s);
    if ((*(v0r_t **)z)[0x420 / 4](z) == 1) return;
  }
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  u32 id = 0;
  (*(v2_t **)o)[0x88 / 4](o, 0x688d74u, (u32)&id);
  void **vt = *(void ***)s;
  u8 flag = 1;
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, 0x688d80u, 0, 0x6887c4u, 0xc9eu, (u32)&flag);
  ((v2_t)vt[0x12c / 4])(s, id, ax);
}
PCREG(470920, fn470920);
