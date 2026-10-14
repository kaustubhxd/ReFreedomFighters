// batch36068.cpp - cascade s4 batch 36068: 0x56df60, 0x521830 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_563a50(void *self);                      // plain ret
extern "C" void THISCALL ext_563110(void *self, u32 a, u32 b);        // ret 8
extern "C" void THISCALL ext_4f2f60(void *self, u32 a);               // ret 4
extern "C" u8 *STDCALL ext_589c20(u32 i);                             // ret 4
extern "C" void THISCALL ext_56e050(void *self);                      // plain ret

// 0x56df60, thiscall(a, flag) ret 8 returns al = 0 (this = d): flag (low byte): 0x563a50(d). 0x563110(d, a, flag). r = d->slot 0x84(); 0x4f2f60(r, 5) (the original pushes 5 before the slot call; the slot leaves it for 0x4f2f60).
// for i in 0..3: b = *(u32 *)([0x7003b8] + i * 4 + 0x2c3d); b: ax = (u16)tab->slot 0x114(0x6a6610, 0, 0x6a82f4, 0x89, 0); d[0x44]->slot 0x130(b, ax). o = 0x589c20(i); o -> o->slot 0x88(0).
// d[0x94]: [0x13299] = 1, d[0x94][0x1043] = 0. flag: 0x56e050(d).
static u8 THISCALL fn56df60(u8 *d, u32 a, u32 flag) {
  if ((u8)flag) ext_563a50(d);
  ext_563110(d, a, flag);
  u8 *r = (*(v0o_t **)d)[0x84 / 4](d);
  ext_4f2f60(r, 5);
  for (s32 i = 0; i < 4; i++) {
    u8 *M = G(u8 *, 0x7003b8);
    u32 b = rd(M + i * 4 + 0x2c3d);
    if (b) {
      u8 *w = *(u8 **)(d + 0x44);
      void **vt = *(void ***)w;
      u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, 0x6a6610u, 0, 0x6a82f4u, 0x89u, 0);
      w = *(u8 **)(d + 0x44);
      ((v2_t)vt[0x130 / 4])(w, b, ax);
    }
    u8 *o = ext_589c20((u32)i);
    if (o) (*(v1_t **)o)[0x88 / 4](o, 0);
  }
  u8 *x = *(u8 **)(d + 0x94);
  if (x) {
    x[0x13299] = 1;
    (*(u8 **)(d + 0x94))[0x1043] = 0;
  }
  if ((u8)flag) ext_56e050(d);
  return 0;
}
PCREG(56df60, fn56df60);

extern "C" void THISCALL ext_515c70(void *self);                                             // plain ret
extern "C" void THISCALL ext_527d10(void *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);   // ret 0x1c
extern "C" void THISCALL ext_522520(void *self);
extern "C" void THISCALL ext_521db0(void *self);
extern "C" void THISCALL ext_521ab0(void *self);
extern "C" void THISCALL ext_522250(void *self);
extern "C" void THISCALL ext_523330(void *self, u32 *p);                                     // ret 4

// 0x521830, thiscall() plain ret (this = d): 0x515c70(d). d[0x133] != 0: d[0x123] != 0 -> d->slot 0x20 (0x80)(d + 0x6c, d + 0x60); 0x527d10(d + 0x2fd, d + 0x6c, d + 0x60, d + 0x60, d + 0x6c, 0, 0, 0); d[0x133] == 0: d->slot 0x36c().
// d[0x215] == 0: 0x522520, 0x521db0, 0x521ab0, 0x522250 (all on d). Else: x = d[0x26fa] -> d->slot 0xbb(0x2ec)(x); y = d[0x26ea]; d[0x26fa] = 0; y -> d->slot 0x2ec(y); d[0x26ea] = 0. Finally 0x523330(d[0x5c], &tmp).
static void THISCALL fn521830(u8 *d) {
  u32 tmp[4];
  ext_515c70(d);
  if (d[0x133] != 0) {
    if (rd(d + 0x123) != 0) {
      u8 *esi = d + 0x60;
      u8 *edi = d + 0x6c;
      (*(v2_t **)d)[0x80 / 4](d, (u32)edi, (u32)esi);
      ext_527d10(d + 0x2fd, (u32)edi, (u32)esi, (u32)esi, (u32)edi, 0, 0, 0);
    }
  } else {
    (*(v0_t **)d)[0x36c / 4](d);
  }
  if (d[0x215] == 0) {
    ext_522520(d);
    ext_521db0(d);
    ext_521ab0(d);
    ext_522250(d);
  } else {
    u32 x = rd(d + 0x26fa);
    if (x) (*(v1_t **)d)[0x2ec / 4](d, x);
    u32 y = rd(d + 0x26ea);
    wr(d + 0x26fa, 0);
    if (y) (*(v1_t **)d)[0x2ec / 4](d, y);
    wr(d + 0x26ea, 0);
  }
  ext_523330(*(u8 **)(d + 0x5c), tmp);
}
PCREG(521830, fn521830);
