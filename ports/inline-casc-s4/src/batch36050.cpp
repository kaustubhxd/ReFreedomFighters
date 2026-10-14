// batch36050.cpp - cascade s4 batch 36050: 0x5524a0, 0x5eedb0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v6_t)(void *, u32, u32, u32, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x5524a0, stdcall(p) ret 4: logger(0x6a57fc, 0x52f) prints 0x6a5d70; obj = sys[0x9b]->slot 0x58(*0x5003d0(p[4], 0)); obj->slot 0x80(&A, &B) (A: 9 dwords, B: 3 dwords); C = {200.0f x3};
// mgr = sys[0x9b][0xadc]; G[0x713f08] == 0: G = mgr->slot 0x238(&A, &B, &C, 0xff00, 0); else mgr->slot 0x23c(G, &A, &B, &C, 0xff00, 0). Finally sys[0x9b]->slot 0xb4(1).
static void STDCALL fn5524a0(u8 *p) {
  u32 A[9], B[3], C[3];
  u8 *db = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a57fcu, 0x52fu);
  void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
  ((void (*)(u8 *, u32))fn)(lo, 0x6a5d70u);
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = (*(v1o_t **)tab)[0x58 / 4](tab, rd(r));
  (*(v2_t **)obj)[0x80 / 4](obj, (u32)A, (u32)B);
  C[0] = C[1] = C[2] = 0x43480000;
  u8 *mgr = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  u32 g = G(u32, 0x713f08);
  if (g == 0) {
    G(u32, 0x713f08) = (*(v5r_t **)mgr)[0x238 / 4](mgr, (u32)A, (u32)B, (u32)C, 0xff00, 0);
  } else {
    (*(v6_t **)mgr)[0x23c / 4](mgr, g, (u32)A, (u32)B, (u32)C, 0xff00, 0);
  }
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  (*(v1_t **)tab)[0xb4 / 4](tab, 1);
}
PCREG(5524a0, fn5524a0);

extern "C" void THISCALL ext_5edbe0(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_5ed340(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_5edc20(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_5ed3d0(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" u32 THISCALL ext_5ed9c0(void *self);                         // plain ret
extern "C" u32 THISCALL ext_5ed9b0(void *self);                         // plain ret
extern "C" void THISCALL ext_5ac620(void *self, u32 a, u32 b);          // ret 8
extern "C" void THISCALL ext_5ac640(void *self, u32 a, u32 b);          // ret 8

// 0x5eedb0, thiscall(a, b) ret 8 (this = s): s[0x10] == 0 -> return. s[0x11] == 2: 0x5edbe0(s[8], 2, s[0x19], -1); 0x5ed340(s[4], 2, s[0x19], -1); 0x5ac620(s[0xc], 2, 0x5ed9c0(s[8]) + s[0x19] - 8).
// s[0x15] == 1: 0x5edc20(s[8], 1, s[0x1d], -1); 0x5ed3d0(s[4], 1, s[0x1d], -1); 0x5ac640(s[0xc], 1, 0x5ed9b0(s[8]) + s[0x1d] - 0xf). Then s[4]->slot 4(a, b); s[8]->slot 4(a, b); s[0xc]->slot 4(a, b).
static void THISCALL fn5eedb0(u8 *s, u32 a, u32 b) {
  if (s[0x10] == 0) return;
  if (rd(s + 0x11) == 2) {
    ext_5edbe0(*(u8 **)(s + 8), 2, rd(s + 0x19), 0xffffffffu);
    ext_5ed340(*(u8 **)(s + 4), 2, rd(s + 0x19), 0xffffffffu);
    u32 r = ext_5ed9c0(*(u8 **)(s + 8));
    ext_5ac620(*(u8 **)(s + 0xc), 2, r + (rd(s + 0x19) - 8));
  }
  if (rd(s + 0x15) == 1) {
    ext_5edc20(*(u8 **)(s + 8), 1, rd(s + 0x1d), 0xffffffffu);
    ext_5ed3d0(*(u8 **)(s + 4), 1, rd(s + 0x1d), 0xffffffffu);
    u32 r = ext_5ed9b0(*(u8 **)(s + 8));
    ext_5ac640(*(u8 **)(s + 0xc), 1, r + (rd(s + 0x1d) - 0xf));
  }
  u8 *o = *(u8 **)(s + 4);
  (*(v2_t **)o)[4 / 4](o, a, b);
  o = *(u8 **)(s + 8);
  (*(v2_t **)o)[4 / 4](o, a, b);
  o = *(u8 **)(s + 0xc);
  (*(v2_t **)o)[4 / 4](o, a, b);
}
PCREG(5eedb0, fn5eedb0);
