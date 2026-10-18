#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef double(THISCALL *VD0)(void *);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void FASTCALL ext_441940(void *a, void *b);
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);
extern "C" void THISCALL ext_4e0d00(void *a, float f);
extern "C" u32 THISCALL ext_4a8d20(void *self);
extern "C" void THISCALL ext_4a9330(void *self, u32 v);
extern "C" void THISCALL ext_4a93b0(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x4a8a60: thiscall(), void, /GS protected. Needs this[0x4a] and this[0x56] nonzero. P = 0x4a8d20(this); with P, P slot 0x128(u16 this[0xc7], &id, 0) fills id; table slot 0x58(id) gives X; when
// X slot 0x1e0(0x200073) is set, the value v = this[0xbf] (or, via X slot 0x504() -> slot 0x2e8() -> slot 0x2d0() when those exist) goes to 0x4a9330(this, v). Then by mode this[0x75]:
// 1: this[0x8b], [0x8f] = 0; 2: this[0x8b], [0x8f], [0x93] = this[0x7d], [0x81], [0x85]; both copy [eng+0x9e7..0x9ef] to this[0x97..0x9f]; other modes: V = 0x43e920(eng+0x9e7, this+0x97)
// (out V), and a nonzero (or NaN) V is scaled by 0x4e0d00(&V, (float)(eng slot 0xbc() slot 0xa8() * 0.002f)) and either added to this[0x8b] / subtracted from this[0x8f] (when
// eng slot 0xbc() slot 0xb8() returns nonzero) or applied through 0x441940(this+0x8b, &V); then this[0x97..0x9f] = eng[0x9e7..0x9ef]. Finally this[0x8b], this[0x8f] are clamped to
// [-0.5, 0.5] (strict compares against [0x67a6b0] / [0x67a6ac]) and 0x4a93b0(this) runs.
extern "C" void THISCALL fn_4a8a60(u8 *self) {
  float V[3];
  if (rd32u(self + 0x4a) == 0) goto done;
  if (rd32u(self + 0x56) == 0) goto done;
  {
    u8 *P = (u8 *)ext_4a8d20(self);
    if (P != nullptr) {
      u32 id = 0;
      (*(V3 *)(vt(P) + 0x128))(P, (u32)*(u16 *)(self + 0xc7), (u32)&id, 0);
      if (id != 0) {
        u8 *T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
        u8 *X = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, id);
        if (X != nullptr) {
          if ((u8)(*(V1 *)(vt(X) + 0x1e0))(X, 0x200073) != 0) {
            u32 v = rd32u(self + 0xbf);
            u8 *Y = (u8 *)(*(V0 *)(vt(X) + 0x504))(X);
            if (Y) {
              u8 *Z = (u8 *)(*(V0 *)(vt(Y) + 0x2e8))(Y);
              if (Z) v = (*(V0 *)(vt(Z) + 0x2d0))(Z);
            }
            ext_4a9330(self, v);
          }
        }
      }
    }
    u32 mode = rd32u(self + 0x75);
    if (mode == 1 || mode == 2) {
      if (mode == 1) {
        wr32u(self + 0x8b, 0);
        wr32u(self + 0x8f, 0);
      } else {
        wr32u(self + 0x8b, rd32u(self + 0x7d));
        wr32u(self + 0x8f, rd32u(self + 0x81));
        wr32u(self + 0x93, rd32u(self + 0x85));
      }
      V[0] = V[1] = V[2] = 0.0f;
      u8 *eng = G(u8 *, 0x70039c);
      wr32u(self + 0x97, rd32u(eng + 0x9e7));
      wr32u(self + 0x9b, rd32u(eng + 0x9eb));
      wr32u(self + 0x9f, rd32u(eng + 0x9ef));
    } else {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *edi = self + 0x97;
      ext_43e920(V, eng + 0x9e7, edi);
      if (V[0] != 0.0f || V[1] != 0.0f || V[2] != 0.0f) {
        eng = G(u8 *, 0x70039c);
        u8 *Q = (u8 *)(*(V0 *)(vt(eng) + 0xbc))(eng);
        double r = (*(VD0 *)(vt(Q) + 0xa8))(Q);
        float s = (float)(r * (double)G(float, 0x68e2c0));
        ext_4e0d00(V, s);
        eng = G(u8 *, 0x70039c);
        Q = (u8 *)(*(V0 *)(vt(eng) + 0xbc))(eng);
        u8 al = (u8)(*(V0 *)(vt(Q) + 0xb8))(Q);
        if (al == 0) {
          ext_441940(self + 0x8b, V);
        } else {
          wrf(self + 0x8b, rdf(self + 0x8b) + V[0]);
          wrf(self + 0x8f, rdf(self + 0x8f) - V[1]);
        }
        eng = G(u8 *, 0x70039c);
        wr32u(edi, rd32u(eng + 0x9e7));
        wr32u(edi + 4, rd32u(eng + 0x9eb));
        wr32u(edi + 8, rd32u(eng + 0x9ef));
      }
    }
    if (rdf(self + 0x8b) > G(float, 0x67a6ac)) wr32u(self + 0x8b, 0x3f000000);
    if (G(float, 0x67a6b0) > rdf(self + 0x8b)) wr32u(self + 0x8b, 0xbf000000);
    if (rdf(self + 0x8f) > G(float, 0x67a6ac)) wr32u(self + 0x8f, 0x3f000000);
    if (G(float, 0x67a6b0) > rdf(self + 0x8f)) wr32u(self + 0x8f, 0xbf000000);
    ext_4a93b0(self);
  }
done:
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4a8a60, fn_4a8a60);
