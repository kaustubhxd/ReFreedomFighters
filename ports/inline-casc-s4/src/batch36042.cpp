// batch36042.cpp - cascade s4 batch 36042: 0x513510, 0x62d2b0, 0x54ef60, 0x597b50, 0x630ce0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void (*cbx_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x513510, thiscall(s) ret 4 returns al = 1 (this = d, s = stream): s->slot 0x40(d); id = s->slot 0x40; d[4] = sys[0x9b]->slot 0x58(id); id = slot 0x40; d[8] = slot 0x58(id);
// slot 0x50 -> d + 0xc, d + 0x10, d + 0x14; slot 0x6c -> d + 0x18, d + 0x24; slot 0x50 -> d + 0x30, d + 0x34.
static u8 THISCALL fn513510(u8 *d, u8 *s) {
  void **vt = *(void ***)s;
  ((v1_t)vt[0x40 / 4])(s, (u32)d);
  u32 id = 0;
  ((v1_t)vt[0x40 / 4])(s, (u32)&id);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(d + 4, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id));
  ((v1_t)vt[0x40 / 4])(s, (u32)&id);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(d + 8, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id));
  ((v1_t)vt[0x50 / 4])(s, (u32)(d + 0xc));
  ((v1_t)vt[0x50 / 4])(s, (u32)(d + 0x10));
  ((v1_t)vt[0x50 / 4])(s, (u32)(d + 0x14));
  ((v1_t)vt[0x6c / 4])(s, (u32)(d + 0x18));
  ((v1_t)vt[0x6c / 4])(s, (u32)(d + 0x24));
  ((v1_t)vt[0x50 / 4])(s, (u32)(d + 0x30));
  ((v1_t)vt[0x50 / 4])(s, (u32)(d + 0x34));
  return 1;
}
PCREG(513510, fn513510);

typedef u32 (*cb4_t)(u8 *, u32, u32, u32);

// 0x62d2b0, cdecl(p, code, a, b, obj) returns eax: code 0xf -> 0. code 0x12: cb = obj[0x1c]; cb(obj, a, b, 0x6c0174) -> *p = 0x62cf90, return 0x25; cb(obj, a, b, 0x6c0150) -> *p = 0x62cf90, return 0x24.
// code 0x17: *p = 0x62d360, p[1] = 1, return 0x27. Otherwise (and after failed 0x12 probes): p[3] == 0 and code == 0x1c -> 0x34; else *p = 0x51f230, return -1.
static s32 fn62d2b0(u8 *p, u32 code, u32 a, u32 b, u8 *obj) {
  if (code == 0xf) return 0;
  if (code == 0x12) {
    cb4_t cb = *(cb4_t *)(obj + 0x1c);
    if (cb(obj, a, b, 0x6c0174u)) {
      wr(p, 0x62cf90);
      return 0x25;
    }
    cb = *(cb4_t *)(obj + 0x1c);
    if (cb(obj, a, b, 0x6c0150u)) {
      wr(p, 0x62cf90);
      return 0x24;
    }
  } else if (code == 0x17) {
    wr(p, 0x62d360);
    wr(p + 4, 1);
    return (s32)code + 0x10;
  }
  if (rd(p + 0xc) == 0 && code == 0x1c) return (s32)code + 0x18;
  wr(p, 0x51f230);
  return -1;
}
PCREG(62d2b0, fn62d2b0);

typedef s32(STDCALL *c14_t)(u8 *, u32, u32, u32 *);
typedef s32(STDCALL *c10_t)(u8 *, u32, u32, u32, u32, u32 *, u32);

// 0x54ef60, thiscall() plain ret returns al (this = s): s == 0 -> 0. r = s->slot 0x14(s, 0x6bdf60, 1, &v): r < 0 or (v & 3) != 3 -> 0; the same with 0x6bdf70. Then v = 0xffffd8f0, ok = 1; r = s->slot 0x10(s, 0x6bdf60, 5, 0, 0, &v, 4):
// r < 0: logger(0x6a4168, 0x53) prints (cdecl) 0x6a41a4, ok = 0. Returns ok.
static u8 THISCALL fn54ef60(u8 *s) {
  u8 ok = 0;
  if (!s) return 0;
  u32 v;
  void **vt = *(void ***)s;
  if (((c14_t)vt[0x14 / 4])(s, 0x6bdf60u, 1, &v) < 0) return 0;
  if ((u8)(v & 3) != 3) return 0;
  vt = *(void ***)s;
  if (((c14_t)vt[0x14 / 4])(s, 0x6bdf70u, 1, &v) < 0) return 0;
  if ((u8)(v & 3) != 3) return 0;
  vt = *(void ***)s;
  u32 w = 0xffffd8f0u;
  ok = 1;
  if (((c10_t)vt[0x10 / 4])(s, 0x6bdf60u, 5, 0, 0, &w, 4) < 0) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a4168u, 0x53u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x6a41a4u);
    ok = 0;
  }
  return ok;
}
PCREG(54ef60, fn54ef60);

extern "C" u32 THISCALL ext_59ffc0(void *self);          // plain ret
extern "C" void THISCALL ext_597e00(void *self, u32 a);  // ret 4
extern "C" void THISCALL ext_594460(void *self, u32 a);  // ret 4
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32 *, u32);

// 0x597b50, thiscall() plain ret (this = d): n = d[0x1fae] (signed); n < d[0x1fba] or n <= 0 -> return. For i < n (ids at d + 0x1dae): o = sys[0x9b]->slot 0x58(id[i]); 0x59ffc0(o) == 5 -> found, otherwise next.
// Found: c = sys[0x9b]->slot 0x4c(d[0x1d0b]); ax = (u16)sys[0x9b]->slot 0x114(0x6a5354, 0, 0x6ad250, 0x413); 0x597e00(d, id[i]); o->slot 0x128(ax, &c, 0); 0x594460(d[0x1d0b], o); return.
static void THISCALL fn597b50(u8 *d) {
  s32 n = (s32)rd(d + 0x1fae);
  if (n < (s32)rd(d + 0x1fba)) return;
  if (n <= 0) return;
  s32 i = 0;
  u8 *p = d + 0x1dae;
  for (;;) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(p));
    if (ext_59ffc0(o) == 5) {
      tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u32 c = (u32)(*(v1o_t **)tab)[0x4c / 4](tab, rd(d + 0x1d0b));
      tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u32 ax = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, 0x6a5354u, 0, 0x6ad250u, 0x413u);
      ext_597e00(d, rd(d + 0x1dae + (u32)i * 4));
      (*(v3_t **)o)[0x128 / 4](o, ax, &c, 0);
      ext_594460((void *)rd(d + 0x1d0b), (u32)o);
      return;
    }
    i++;
    p += 4;
    if (!(i < (s32)rd(d + 0x1fae))) return;
  }
}
PCREG(597b50, fn597b50);

// 0x630ce0, cdecl(s, tree, k) (deflate pqdownheap): v = heap[k] (heap = s + 0xb54, heap_len = s[0x1448] signed, depth bytes at s + 0x1450, tree freq = u16 at tree + 4 * n).
// sift v down: j = 2k; while j <= heap_len: j < heap_len and smaller(heap[j + 1], heap[j]) -> j++; smaller(v, heap[j]) -> break; heap[k] = heap[j]; k = j; j *= 2. Then heap[k] = v.
// smaller(a, b) = freq[a] < freq[b] or (equal and depth[a] <= depth[b]).
static inline bool smaller(u8 *s, u8 *tree, u32 a, u32 b) {
  u16 fa = *(u16 *)(tree + a * 4), fb = *(u16 *)(tree + b * 4);
  return fa < fb || (fa == fb && s[0x1450 + a] <= s[0x1450 + b]);
}
static void fn630ce0(u8 *s, u8 *tree, s32 k) {
  s32 *heap = (s32 *)(s + 0xb54);
  s32 v = heap[k];
  s32 j = k * 2;
  while (j <= (s32)rd(s + 0x1448)) {
    if (j < (s32)rd(s + 0x1448) && smaller(s, tree, (u32)heap[j + 1], (u32)heap[j])) j++;
    if (smaller(s, tree, (u32)v, (u32)heap[j])) break;
    heap[k] = heap[j];
    k = j;
    j *= 2;
  }
  heap[k] = v;
}
PCREG(630ce0, fn630ce0);
