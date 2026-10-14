// batch36037.cpp - cascade s4 batch 36037: 0x427250, 0x4d7170, 0x502a00, 0x5c4c00, 0x5db910 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v2r_t)(void *, u32, u32);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);
typedef u32(STDCALL *gft_t)(u32, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x427250, thiscall(a, b, c) ret 0xc returns al (this = s): when (u8)c == 0: v = s->slot 0x130(a); o = s->slot 0x70(v); o && (u8)o->slot 0x18(v, b) -> return 1.
// h = s->slot 8(a); h == 0 -> return 0. ok = GetFileTime(h, &t1, &t2, b) != 0; s->slot 0x1c(h); return ok.
static u8 THISCALL fn427250(u8 *s, u32 a, u32 b, u32 c) {
  if ((u8)c == 0) {
    u32 v = (*(v1r_t **)s)[0x130 / 4](s, a);
    u8 *o = (*(v1o_t **)s)[0x70 / 4](s, v);
    if (o) {
      if ((u8)(*(v2r_t **)o)[0x18 / 4](o, v, b)) return 1;
    }
  }
  u32 h = (*(v1r_t **)s)[8 / 4](s, a);
  if (h == 0) return 0;
  u32 t1[2], t2[2];
  u32 ok = G(gft_t, 0x676090)(h, (u32)t1, (u32)t2, b);
  (*(v1_t **)s)[0x1c / 4](s, h);
  return ok != 0;
}
PCREG(427250, fn427250);

// 0x4d7170, thiscall(a) ret 4 returns al (this = t): lexicographic "t < a" on the packed fields: u16 at +8 (>> 9, then (>> 5) & 0xf, then & 0x1f), then u16 at +6 (>> 11, then (>> 5) & 0x3f, then & 0x1f).
static u8 THISCALL fn4d7170(u8 *t, u8 *a) {
  u32 ax = *(u16 *)(a + 8), dx = *(u16 *)(t + 8);
  u16 si = (u16)ax >> 9, di = (u16)dx >> 9;
  if (di < si) return 1;
  if (di > si) return 0;
  u16 cx = (ax >> 5) & 0xf, s2 = (dx >> 5) & 0xf;
  if (s2 < cx) return 1;
  if (s2 > cx) return 0;
  u16 a1 = ax & 0x1f, d1 = dx & 0x1f;
  if (d1 < a1) return 1;
  if (d1 > a1) return 0;
  u32 bx = *(u16 *)(t + 6), dx2 = *(u16 *)(a + 6);
  u16 c1 = (u16)bx >> 11, a2 = (u16)dx2 >> 11;
  if (c1 < a2) return 1;
  if (c1 > a2) return 0;
  u16 c2 = (bx >> 5) & 0x3f, a3 = (dx2 >> 5) & 0x3f;
  if (c2 < a3) return 1;
  if (c2 > a3) return 0;
  return (u8)(bx & 0x1f) < (u8)(dx2 & 0x1f);
}
PCREG(4d7170, fn4d7170);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x502a00, thiscall(p) ret 4 (this = s): r = 0x5003d0(p[4], 1); t = (u8)r[4]: 3 -> id = r[0]; 4 -> id = (*(r[0]))->slot 0x34() on the object r[0]; else logger(0x69c8e0, 0x111) prints (cdecl, 3 args) 0x69c6b0, 0x69c9b0, assert hook, id = 0.
// q = 0x5003d0(p[4], 0); n = 0; ax = tab->slot 0x114(id, 0, 0x69ca10, 0xb7, &n) (low 16 bits); s[0xc]->slot 0x12c(q[0], ax).
static void THISCALL fn502a00(u8 *s, u8 *p) {
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 id;
  u32 t = r[4];
  if (t == 3) {
    id = rd(r);
  } else if (t == 4) {
    u8 *o = *(u8 **)r;
    id = (*(v0r_t **)o)[0x34 / 4](o);
  } else {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0x111u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c9b0u);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    id = 0;
  }
  u8 *q = ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *w = *(u8 **)(s + 0xc);
  void **vt = *(void ***)w;
  u32 n = 0;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, id, 0, 0x69ca10u, 0xb7u, (u32)&n);
  w = *(u8 **)(s + 0xc);
  ((v2_t)vt[0x12c / 4])(w, rd(q), ax);
}
PCREG(502a00, fn502a00);

extern "C" u32 THISCALL ext_4e5e60(void *self);                  // plain ret
extern "C" void THISCALL ext_4e6180(void *self, void *out);     // ret 4
extern "C" void *ext_41e290(u32 n);                              // cdecl

// 0x5c4c00, thiscall(x, r) ret 8 (this = s): s[0x48] = read(r); s[0x50] = read(r); 0x4e6180(r, s + 0x64); 0x4e6180(r, s + 0x70); s[0x50] = min(s[0x50], 5) (signed);
// p = malloc(n * 0x19, saturating to -1 on overflow); each of the n entries gets its first dword cleared; s[0x4c] = p (0 on failure); for i < s[0x50]: entry[i][0x18] = 1, entry[i][4] = 0 (dword);
// s[0x58] = s[0x44][0x18]->slot 0x14().
static void THISCALL fn5c4c00(u8 *s, u32 x, u8 *r) {
  (void)x;
  wr(s + 0x48, ext_4e5e60(r));
  wr(s + 0x50, ext_4e5e60(r));
  ext_4e6180(r, s + 0x64);
  ext_4e6180(r, s + 0x70);
  if ((s32)rd(s + 0x50) > 5) wr(s + 0x50, 5);
  u32 n = rd(s + 0x50);
  u64 prod = (u64)n * 0x19u;
  u32 size = (prod >> 32) ? 0xffffffffu : (u32)prod;
  u8 *p = (u8 *)ext_41e290(size);
  if (p) {
    u8 *e = p;
    for (u32 k = n; k != 0; k--) {
      wr(e, 0);
      e += 0x19;
    }
  }
  wr(s + 0x4c, (u32)p);
  s32 i = 0;
  if ((s32)rd(s + 0x50) > 0) {
    u32 off = 0;
    do {
      u8 *base = *(u8 **)(s + 0x4c);
      off += 0x19;
      i++;
      base[off - 1] = 1;
      wr(base + off - 0x15, 0);
    } while (i < (s32)rd(s + 0x50));
  }
  u8 *l = *(u8 **)(*(u8 **)(s + 0x44) + 0x18);
  wr(s + 0x58, (*(v0r_t **)l)[0x14 / 4](l));
}
PCREG(5c4c00, fn5c4c00);

// 0x5db910, thiscall(src) ret 4 (this = d): when src[0x48]: iterate it (slot 0x4c(&it), v = slot 0x5c(&it) while it[0]): d[0x48]->slot 4(v).
// Copy: d[0x4c] = src[0x4c], d[0x50], byte d[0x54], u16 d[0x55], dwords at 0x87, 0x8b, 0x8f, 0x93, 0x97, 0x9b. Then d[0x4c] == 0 -> d[0x63] = 1; d[0x4c] == 1 -> d[0x63] = 0.
static void THISCALL fn5db910(u8 *d, u8 *src) {
  u8 *l = *(u8 **)(src + 0x48);
  if (l) {
    u32 it[3];
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    u8 *l2 = *(u8 **)(src + 0x48);
    u32 v = (*(v1r_t **)l2)[0x5c / 4](l2, (u32)it);
    if (it[0] != 0) {
      do {
        u8 *o = *(u8 **)(d + 0x48);
        (*(v1_t **)o)[4 / 4](o, v);
        u8 *l3 = *(u8 **)(src + 0x48);
        v = (*(v1r_t **)l3)[0x5c / 4](l3, (u32)it);
      } while (it[0] != 0);
    }
  }
  wr(d + 0x4c, rd(src + 0x4c));
  wr(d + 0x50, rd(src + 0x50));
  d[0x54] = src[0x54];
  *(u16 *)(d + 0x55) = *(u16 *)(src + 0x55);
  wr(d + 0x87, rd(src + 0x87));
  wr(d + 0x8b, rd(src + 0x8b));
  wr(d + 0x8f, rd(src + 0x8f));
  wr(d + 0x93, rd(src + 0x93));
  wr(d + 0x97, rd(src + 0x97));
  wr(d + 0x9b, rd(src + 0x9b));
  u32 m = rd(d + 0x4c);
  if (m == 0) wr(d + 0x63, 1);
  else if (m == 1) wr(d + 0x63, 0);
}
PCREG(5db910, fn5db910);
