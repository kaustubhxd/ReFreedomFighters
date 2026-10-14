// batch36069.cpp - cascade s4 batch 36069: 0x63b850, 0x64b2f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void *ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy thunk
extern "C" u8 *STDCALL ext_64c7e0(u32 id);                         // ret 4

// 0x63b850, thiscall(a, v) ret 8 (this = d): w = u16 a[0x5a]; w == 0 -> return. rec = d[0x68][w & 0xfff]; v += [0x70039c][0x1aa3][0x20]; sz = rec[0x3d] * 8; sz == 0 -> return.
// old = rec[0x40]; new = d->slot 8 (0x20)(sz + 8); rec[0x40] = new; memcpy(new, old, sz); d->slot 9 (0x24)(old, sz); k = rec[0x3d]; rec[0x3d] = k + 1; new[k * 8 + 4] = v; new[k * 8] = 0.
// d[0xec] children at d + 0xf0: child[0x10071][w & 0xfff] != 0 -> 0x64c7e0(w)[0x14] |= 0x80.
static void THISCALL fn63b850(u8 *d, u8 *a, u32 v) {
  u32 w = *(u16 *)(a + 0x5a);
  if (w == 0) return;
  u32 idx = w & 0xfff;
  u8 *rec = *(u8 **)(*(u8 **)(d + 0x68) + idx * 4);
  v += rd(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x20);
  u32 sz = (u32)rec[0x3d] * 8;
  if (sz == 0) return;
  u8 *old = *(u8 **)(rec + 0x40);
  u8 *nw = (*(v1o_t **)d)[0x20 / 4](d, sz + 8);
  wr(rec + 0x40, (u32)nw);
  ext_634d22(nw, old, sz);
  (*(v2_t **)d)[0x24 / 4](d, (u32)old, sz);
  u8 k = rec[0x3d];
  u8 *base = *(u8 **)(rec + 0x40);
  rec[0x3d] = k + 1;
  wr(base + k * 8 + 4, v);
  wr(base + k * 8, 0);
  u32 n = rd(d + 0xec);
  if (n != 0) {
    u8 *p = d + 0xf0;
    u32 i = 0;
    do {
      u8 *c = *(u8 **)p;
      u8 *arr = *(u8 **)(c + 0x10071);
      if (rd(arr + idx * 4) != 0) {
        u8 *x = ext_64c7e0(w);
        x[0x14] |= 0x80;
      }
      i++;
      p += 4;
    } while (i != rd(d + 0xec));
  }
}
PCREG(63b850, fn63b850);

extern "C" u32 THISCALL ext_658f10(void *self, u32 a);          // ret 4
extern "C" u8 *THISCALL ext_64b170(void *self, u32 a, u32 b);   // ret 8

// 0x64b2f0, thiscall(a, b, c) ret 0xc returns eax (this = s): M = [0x70039c][0x1aa3]; t = M[0x20] + a; e = s[0x10071][u16 t[6] & 0xfff]. e: r = M->slot 0x20 (0x80)(u16 t[4]); q = 0x658f10(e[8], 0); x = e[0x10]:
// x and r == q -> e[0x10] = x[0x18], x[0x18] = 0, res = x. x and r != q, or no x and r != q: s->slot 0x14 (0x50)(e); !(u8)s->slot 0x13 (0x4c)(e) -> assert hook (int3 when none). no x and r == q (or no e): res = 0x64b170(s, a, c).
// res == 0 -> 0; res[5] |= 0x80; res[0x10] = (u8)b; return res.
static u8 *THISCALL fn64b2f0(u8 *s, u32 a, u32 b, u32 c) {
  u8 *M = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *t = *(u8 **)(M + 0x20);
  u8 *e = *(u8 **)(*(u8 **)(s + 0x10071) + (*(u16 *)(t + a + 6) & 0xfff) * 4);
  u8 *res;
  bool build = true;
  if (e) {
    u32 r = (*(v1r_t **)M)[0x80 / 4](M, *(u16 *)(t + a + 4));
    u32 q = ext_658f10(*(u8 **)(e + 8), 0);
    u8 *x = *(u8 **)(e + 0x10);
    bool go_c;
    if (x) {
      if (r == q) {
        wr(e + 0x10, rd(x + 0x18));
        wr(x + 0x18, 0);
        res = x;
        build = false;
        go_c = false;
      } else {
        go_c = true;
      }
    } else {
      go_c = (r != q);
    }
    if (go_c) {
      (*(v1_t **)s)[0x50 / 4](s, (u32)e);
      if (!(u8)(*(v1r_t **)s)[0x4c / 4](s, (u32)e)) {
        hook_t h = G(hook_t, 0x7003b0);
        if (!h) __asm__ volatile("int3");
        h();
      }
    }
  }
  if (build) res = ext_64b170(s, a, c);
  if (!res) return 0;
  res[5] |= 0x80;
  res[0x10] = (u8)b;
  return res;
}
PCREG(64b2f0, fn64b2f0);
