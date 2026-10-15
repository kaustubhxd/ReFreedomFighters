// batch47007.cpp - cascade t8 batch 47007: 0x5c17c0, 0x604570 (tier F rows).
#include "ff.h"

typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v2r_t)(void *, u32, u32);
typedef u32(THISCALL *v6r_t)(void *, u32, u32, u32, u32, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);

extern "C" void THISCALL ext_5c21e0(void *self, u32 a);          // ret 4
extern "C" u32 FASTCALL ext_4cc4b0(u32 a, u32 b);               // case-insensitive char compare (al)

static inline u8 *tbl_() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *lookup(u32 id) {
  u8 *t = tbl_();
  return (u8 *)(*(v1r_t **)t)[0x58 / 4](t, id);
}
static inline u32 read_named(u32 name) {
  u8 *t = tbl_();
  u8 *o = (u8 *)(*(v0r_t **)t)[0x138 / 4](t);
  u32 loc = 0;
  (*(v2r_t **)o)[0x88 / 4](o, name, (u32)&loc);
  return loc;
}

// 0x5c17c0, thiscall(), plain ret. o = engine[0x9b][0xadc]->slot 0x25c(0x685f44, 0); when set: this[0xec] = o->slot 0x100(0x6a5cf0); this[0xf4..0xfc] = 0; this[0x44]->slot 0x84(this+0xf4);
// this[0x50] = lookup(named 0x6a6700); b = lookup(named 0x6a5c48); when set: loc, ax = (u16) tbl->slot 0x114(0x6a5c68, 0, 0x6b3a74, 0xf9, &loc, 0); b->slot 0x128(ax); loc != 0: 0x5c21e0(this, 0).
static void THISCALL fn5c17c0(u8 *self) {
  u8 *t = tbl_();
  u8 *h = *(u8 **)(t + 0xadc);
  u8 *o = (u8 *)(*(v2r_t **)h)[0x25c / 4](h, 0x685f44, 0);
  if (!o) return;
  *(u32 *)(self + 0xec) = (*(v1r_t **)o)[0x100 / 4](o, 0x6a5cf0);
  *(u32 *)(self + 0xf4) = 0;
  *(u32 *)(self + 0xf8) = 0;
  *(u32 *)(self + 0xfc) = 0;
  u8 *c = *(u8 **)(self + 0x44);
  (*(v1_t **)c)[0x84 / 4](c, (u32)(self + 0xf4));
  *(u32 *)(self + 0x50) = (u32)lookup(read_named(0x6a6700));
  u8 *b = lookup(read_named(0x6a5c48));
  if (!b) return;
  void **bvt = *(void ***)b;
  u32 loc;
  t = tbl_();
  u32 ax = (u16)(*(v6r_t **)t)[0x114 / 4](t, 0x6a5c68, 0, 0x6b3a74, 0xf9, (u32)&loc, 0);
  ((v1_t)bvt[0x128 / 4])(b, ax);
  if (loc) ext_5c21e0(self, 0);
}
PCREG(5c17c0, fn5c17c0);

// 0x604570, fastcall(first1, last1, first2, last2, extra) ret 0xc: a std::search of [first2,last2) in [first1,last1) with the case-insensitive byte compare 0x4cc4b0(hay, needle).
// Empty ranges return first1; a one-element needle is a linear scan. Otherwise the first candidate is compared twice (original does), then the rest.
static u8 *FASTCALL fn604570(u8 *first1, u8 *last1, u8 *first2, u8 *last2, u32 extra) {
  u8 *esi = first1;
  if (esi == last1 || first2 == last2) return esi;
  if (first2 + 1 == last2) {
    do {
      if (ext_4cc4b0(*esi, *first2) & 0xff) return esi;
      esi++;
    } while (esi != last1);
    return esi;
  }
  for (;;) {
    while (!(ext_4cc4b0(*esi, *first2) & 0xff)) {
      esi++;
      if (esi == last1) return last1;
    }
    while (!(ext_4cc4b0(*esi, *first2) & 0xff)) {
      esi++;
      if (esi == last1) return last1;
    }
    u8 *p2 = first2 + 1;
    u8 *nxt = esi + 1;
    u8 *p1 = nxt;
    if (p1 == last1) return last1;
    if (ext_4cc4b0(*p1, *p2) & 0xff) {
      for (;;) {
        p2++;
        if (p2 == last2) return esi;
        p1++;
        if (p1 == last1) return last1;
        if (!(ext_4cc4b0(*p1, *p2) & 0xff)) break;
      }
    }
    esi = nxt;
    if (esi == last1) return esi;
  }
}
PCREG(604570, fn604570);
