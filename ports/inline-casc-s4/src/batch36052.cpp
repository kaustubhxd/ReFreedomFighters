// batch36052.cpp - cascade s4 batch 36052: 0x606dc0, 0x49c980, 0x4ace80 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v2r_t)(void *, u32, u32);
typedef void(THISCALL *v8_t)(void *, u32, u32, u32, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_607200(void *self, u32 *out, u32 *key);   // ret 8: out = {node, self}
extern "C" u8 *THISCALL ext_607260(void *self, u8 *rec);               // ret 4: inserts, returns the new node's key area
extern "C" void THISCALL ext_4301c0(void *self, u32 pos, u32 *val);    // ret 8
extern "C" void THISCALL ext_6070b0(void *self, u32 pos, u32 *val);    // ret 8

// 0x606dc0, thiscall(key) ret 4 returns ax (this = s): 0x607200(s + 4, &out, &key); out.node: return node[8] (u16). Otherwise s[0x2f]++; rec = {key, (u16)0}; r = 0x607260(s + 4, &rec); *(u16 *)(r + 4) = (u16)s[0x2f];
// vec1 = s + 0x17: vec1[4] != vec1[8]: *vec1[4] = key, vec1[4] += 4; else 0x4301c0(vec1, vec1[4], &key). key = 0; vec2 = s + 0x23: vec2[4] != vec2[8]: *(u16 *)vec2[4] = 0, vec2[4] += 2; else 0x6070b0(vec2, vec2[4], &key). return (u16)s[0x2f].
static u16 THISCALL fn606dc0(u8 *s, u32 key) {
  u32 out[2];
  ext_607200(s + 4, out, &key);
  if (out[0]) return *(u16 *)(*(u8 **)out + 8);
  wr(s + 0x2f, rd(s + 0x2f) + 1);
  struct {
    u32 k;
    u16 z;
  } __attribute__((packed)) rec;
  rec.k = key;
  rec.z = 0;
  u32 saved = key;
  u8 *r = ext_607260(s + 4, (u8 *)&rec);
  *(u16 *)(r + 4) = (u16)rd(s + 0x2f);
  u8 *v1 = s + 0x17;
  u8 *p1 = *(u8 **)(v1 + 4);
  if (p1 != *(u8 **)(v1 + 8)) {
    if (p1) wr(p1, saved);
    wr(v1 + 4, rd(v1 + 4) + 4);
  } else {
    ext_4301c0(v1, (u32)p1, &key);
  }
  u8 *v2 = s + 0x23;
  u8 *p2 = *(u8 **)(s + 0x27);
  key = 0;
  if (p2 != *(u8 **)(v2 + 8)) {
    if (p2) *(u16 *)p2 = 0;
    wr(v2 + 4, rd(v2 + 4) + 2);
  } else {
    ext_6070b0(v2, (u32)p2, &key);
  }
  return (u16)rd(s + 0x2f);
}
PCREG(606dc0, fn606dc0);

// 0x49c980, thiscall(out, idx) ret 8 returns eax (this = t): A = t[0x1d] (u32 array); head = A[idx]; q = &A[idx + 1]; n = 0; do { w = *q++; v = w & ~7; out[n++] = v; if (w & 2) { v += 0x70; while (v < (*q & ~7)) { out[n++] = v; v += 0x70; } } } while (!(w & 1));
// base = out[0] ? n : 0; k = base; for each node of the list at head (3 dwords, next at +0xc): out[k..k+2] = node[0..2], k += 3. If the last stored out[k-1] == 0: k--, and if out[k-2 + 1].. (the previous word) is also 0: k--. Return ((k - base) << 16) | base.
static u32 THISCALL fn49c980(u8 *t, u32 *out, u32 idx) {
  u32 *A = *(u32 **)(t + 0x1d);
  u32 *head = (u32 *)A[idx];
  u32 *q = A + idx + 1;
  u32 n = 0;
  u32 w;
  do {
    w = *q++;
    u32 v = w & 0xfffffff8u;
    out[n++] = v;
    if (w & 2) {
      v += 0x70;
      while (v < (*q & 0xfffffff8u)) {
        out[n++] = v;
        v += 0x70;
      }
    }
  } while (!(w & 1));
  u32 base = out[0] != 0 ? n : 0;
  u32 k = base;
  u32 *dst = out + base;
  u32 *node = head;
  if (node) {
    do {
      dst[0] = node[0];
      dst[1] = node[1];
      dst[2] = node[2];
      dst += 3;
      k += 3;
      node = (u32 *)node[3];
    } while (node);
    if (dst[-1] == 0) {
      k--;
      if (dst[-2] == 0) k--;
    }
  }
  return ((k - base) << 16) | base;
}
PCREG(49c980, fn49c980);

typedef u32 (*cb0_t)(void *);

// 0x4ace80, fastcall(this = ecx, b = edx, a1..a6 on the stack) ret 0x18 returns eax: o = this->slot 0x10c(0x6889cc, 0); o == 0 -> 0. o->slot 0x5c(1, this, 0); o->slot 0xb0(b, a1..a6, 0); o->slot 0x5c(2, 0, 0).
// g = [0x70038c]; g->slot 0x20(o) nonzero -> 0. h = g[8]; h and g[0xc] <= o < g[0x10]: return h(o) (thiscall, ecx = o). Otherwise o[-1] == 0 -> g->slot 0xac(o); return o[-1].
static u32 FASTCALL fn4ace80(u8 *t, u32 b, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  u8 *o = (*(v2o_t **)t)[0x10c / 4](t, 0x6889ccu, 0);
  if (!o) return 0;
  (*(v3_t **)o)[0x5c / 4](o, 1, (u32)t, 0);
  ((v8_t)(*(void ***)o)[0xb0 / 4])(o, b, a1, a2, a3, a4, a5, a6, 0);
  (*(v3_t **)o)[0x5c / 4](o, 2, 0, 0);
  u8 *g = G(u8 *, 0x70038c);
  if ((*(v1r_t **)g)[0x20 / 4](g, (u32)o)) return 0;
  g = G(u8 *, 0x70038c);
  u8 *h = *(u8 **)(g + 8);
  if (h && !(rd(g + 0xc) > (u32)o) && (u32)o < rd(g + 0x10)) {
    return ((u32(THISCALL *)(void *))h)(o);
  }
  if (rd(o - 4) == 0) (*(v1_t **)g)[0xac / 4](g, (u32)o);
  return rd(o - 4);
}
PCREG(4ace80, fn4ace80);
