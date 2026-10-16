#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef double(THISCALL *VD2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);
extern "C" float FASTCALL ext_4e0830(void *a, void *b);
extern "C" void THISCALL ext_5c4940(void *self, void *a, void *b);
extern "C" u32 THISCALL ext_5c5010(void *self, void *a, void *b);
extern "C" void THISCALL ext_5c4a00(void *self, void *y, void *out);
extern "C" void THISCALL ext_5c4cc0(void *self, void *v, u32 idx, u32 slot);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x5c4700: thiscall(no args), void, /GS protected (cookie via 0x633654). Fills a direction pair p28[6] / point p34[3] (0x5c4940 when this[0x60] != 0, then
// 0x5c5010 which returns an index or -1 = stop). If the engine random slot 0x1c0(0x6b410c, 0xf2) (a double on the x87 stack) is below [0x70039c]+0x48 * [0x6b4140]
// it advances the ring cursor this[0x5c] (modulo this[0x58]) up to twice: the object this[0x44]->[0x18] slot 0x30(cursor), the table slot 0x58 object, 0x5c4a00 gives a
// point v10 and 0x4e0830(v10, p34) a squared distance fl. A candidate fails (-> 0x5c4cc0(v10, index, cursor) and return) when [0x6b414c] > fl, or when fl < [0x6b4148] / [0x6b4150]

// the failure needs the B dot product to be above zero). Otherwise the loop continues; a plain finish returns normally.
extern "C" void THISCALL fn_5c4700(u8 *self) {
  float p34[3], p28[6], v10[3], w[3];
  if (rd32u(self + 0x60)) ext_5c4940(self, p34, p28);
  u32 idx = ext_5c5010(self, p34, p28);
  if (idx == 0xffffffffu) {
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  u8 *eng = G(u8 *, 0x70039c);
  double d = (*(VD2 *)(vt(eng) + 0x1c0))(eng, 0x6b410c, 0xf2);
  eng = G(u8 *, 0x70039c);
  double thr = (double)*(float *)(eng + 0x48) * G(double, 0x6b4140);
  if (!(thr > d)) {
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  u32 n = 0;
  do {
    wr32u(self + 0x5c, rd32u(self + 0x5c) + 1);
    if (!(rd32u(self + 0x5c) < rd32u(self + 0x58))) wr32u(self + 0x5c, 0);
    u8 *o = (u8 *)rd32u(self + 0x44);
    u8 *q = (u8 *)rd32u(o + 0x18);
    u32 r = (*(V1 *)(vt(q) + 0x30))(q, rd32u(self + 0x5c));
    u8 *T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    u8 *y = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, r);
    ext_5c4a00(self, y, v10);
    float fl = ext_4e0830(v10, p34);
    if (G(float, 0x6b4148) > fl) {
      if (rd32u(self + 0x60) == 0) goto fail;
      ext_43e920(w, v10, p34);
      {
        float s = p28[0] * w[0];
        float t = w[1] * p28[1];
        s = s + t;
        float u = w[2] * p28[2];
        s = s + u;
        if (!(s > 0.0f)) goto fail;
      }
      {
        float s = p28[3] * w[0];
        float t = p28[4] * w[1];
        s = s + t;
        float u = p28[5] * w[2];
        s = s + u;
        if (!(s > 0.0f)) goto fail;
      }
    }
    if (G(float, 0x6b414c) > fl) goto fail;
    if (G(float, 0x6b4150) > fl) {
      if (rd32u(self + 0x60) == 0) goto fail;
      ext_43e920(w, v10, p34);
      {
        float s = p28[0] * w[0];
        float t = w[1] * p28[1];
        s = s + t;
        float u = w[2] * p28[2];
        s = s + u;
        if (!(s > 0.0f)) goto next;
      }
      {
        float a = p28[3] * w[0];
        float b = w[1] * p28[4];
        float c = w[2] * p28[5];
        a = a + b;
        a = a + c;
        if (a > 0.0f) goto fail;
      }
    }
  next:;
  } while (++n < 2);
  ext_633654(G(u32, 0x6f5630));
  return;
fail:
  ext_5c4cc0(self, v10, idx, rd32u(self + 0x5c));
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5c4700, fn_5c4700);
