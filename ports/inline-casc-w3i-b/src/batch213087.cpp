#include "ff.h"

typedef u32(THISCALL *V2)(void *, void *, void *);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void FASTCALL ext_451890(void *a, void *b, float f);
extern "C" void THISCALL ext_518380(void *self, void *a, void *c, void *b, void *p);
extern "C" void THISCALL ext_518190(void *self, void *a, void *c, void *b, void *p);
extern "C" void THISCALL ext_5251c0(void *self, void *e, void *d, void *c, void *p, float f24, float f28, float x, float s);
extern "C" void FASTCALL ext_4de040(void *e, void *p, u32 z);
extern "C" void THISCALL ext_5172e0(void *self, void *a, void *b, void *e, void *d);
extern "C" void FASTCALL ext_4de420(void *a, void *e);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x518960: thiscall() with no defined return value, /GS protected: moves an object toward a target. A = this[0x5c]'s vector (+8..+0x10), moved by 0x451890(A, this+0x15eb, this[0x15fb]) when
// the float this[0x15fb] > 0. When this[0x5c]'s dword +0x39 is zero the result vector C is this[0x60..0x68]; otherwise mode this[0x1650] 0 / 1 runs 0x518380 / 0x518190(A, C, B, this+0x15ff),
// the speed this[0x15ff] is clamped (c0 = [0x69f1a0] upper, c1 = [0x69f1a8] lower), this[0x15fb] decays by [0x67da00] while positive and A / B are stored at this+0x15d3 / 0x15df.
// Then E / D come from 0x5251c0 (when the byte this[0x1614] is set: with this[0x5c]'s floats +0x24 / +0x28, this[0x15ff] and -1.0f (mode 1) or 1.0f) or from 0x4de040 with D = C;
// 0x5172e0(this+0x6c, this+0x60, E, D), this slot 0x7c(E, D), 0x4de420(this+0x6c, E) and the vector this+0x60 = D.
extern "C" void THISCALL fn_518960(u8 *self) {
  float A[3], B[3], C[3], D[3];
  u8 E[24];
  u8 *P = (u8 *)rd32u(self + 0x5c);
  A[0] = rdf(P + 8);
  A[1] = rdf(P + 0xc);
  A[2] = rdf(P + 0x10);
  float f = rdf(self + 0x15fb);
  if (f > 0.0f) ext_451890(A, self + 0x15eb, f);
  P = (u8 *)rd32u(self + 0x5c);
  if (rd32u(P + 0x39) == 0) {
    C[0] = rdf(self + 0x60);
    C[1] = rdf(self + 0x64);
    C[2] = rdf(self + 0x68);
  } else {
    u32 m = rd32u(self + 0x1650);
    if (m == 0) ext_518380(self, A, C, B, self + 0x15ff);
    else if (m == 1) ext_518190(self, A, C, B, self + 0x15ff);
    float x = rdf(self + 0x15ff);
    float r;
    if (G(float, 0x69f1a8) > x) {
      r = G(float, 0x69f1a8);
    } else {
      float c0 = G(float, 0x69f1a0);
      r = (c0 < x) ? c0 : x;
    }
    wrf(self + 0x15ff, r);
    float f2 = rdf(self + 0x15fb);
    if (f2 > 0.0f) wrf(self + 0x15fb, f2 - G(float, 0x67da00));
    wrf(self + 0x15d3, A[0]);
    wrf(self + 0x15d7, A[1]);
    wrf(self + 0x15db, A[2]);
    wrf(self + 0x15df, B[0]);
    wrf(self + 0x15e3, B[1]);
    wrf(self + 0x15e7, B[2]);
  }
  float s = rd32u(self + 0x1650) == 1 ? G(float, 0x67af2c) : G(float, 0x678858);
  if (self[0x1614]) {
    P = (u8 *)rd32u(self + 0x5c);
    ext_5251c0(self + 0x2d8, E, D, C, self + 0x15df, rdf(P + 0x24), rdf(P + 0x28), rdf(self + 0x15ff), s);
  } else {
    ext_4de040(E, self + 0x15df, 0);
    D[0] = C[0];
    D[1] = C[1];
    D[2] = C[2];
  }
  u8 *edi = self + 0x60, *esi = self + 0x6c;
  ext_5172e0(self, esi, edi, E, D);
  (*(V2 *)(vt(self) + 0x7c))(self, E, D);
  ext_4de420(esi, E);
  wrf(edi, D[0]);
  wrf(edi + 4, D[1]);
  wrf(edi + 8, D[2]);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(518960, fn_518960);
