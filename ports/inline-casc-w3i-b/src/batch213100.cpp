#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_5122f0(void *self, u32 code, void *p);
extern "C" void THISCALL ext_523ec0(void *obj, float f);
extern "C" void THISCALL ext_523180(void *obj);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u16 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *table() { return (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b); }
static inline bool absgt(float v, float lim) {
  double x = (double)v;
  u64 b;
  __builtin_memcpy(&b, &x, 8);
  b &= G(u64, 0x67cd50);
  __builtin_memcpy(&x, &b, 8);
  return x > (double)lim;
}

// 0x5153e0: thiscall(code, p) ret 8, message handler. Compares the low word of code with the u16 fields this+0x2ca / 0x2cc / 0x207 / 0x2d0:
//  0x2ca: with this[0x5c] (byte +0x46 set) it converts the float at +0x47 to engine ticks (x1024), and when the engine tick [eng+0x40] is more than 7 s (>7.0 after
//         x2^-10) ahead of it sets this[0x2c4] = tick + 0x800, clears this[0x233] and returns 0. Otherwise (unless this[0x2c4] > tick, or the table slot 0x58 object of p[0] is
//         missing) asks that object (slot 0x84) and this (slot 0x8c) for a vector; if any |component| exceeds the limits at this+0x21b / 0x22b / 0x223 it calls 0x523ec0(this[0x5c],
//         p[1]) and stores p[2] to this[0x233] (the constant 0x7e967699 when p[2] == -1.0f). Then returns 0 unless this[0x2c3] is set, which falls through to the default.
//  0x2cc: clears this[0x233], calls 0x523180(this[0x5c]) and takes the default.   0x207: returns 0 after this slot 0x368(p).
//  0x2d0: returns 0 when this equals the table slot 0x58 object of p[0], else the default.   Default and fall-through: return 0x5122f0(this, code, p).
extern "C" u32 THISCALL fn_5153e0(u8 *self, u32 code, u8 *p) {
  u32 r;
  u16 c = (u16)code;
  if (c == rd16u(self + 0x2ca)) {
    u8 *obj = (u8 *)rd32u(self + 0x5c);
    if (obj[0x46] != 0) {
      float f = rdf(obj + 0x47) * G(float, 0x678620);
      int t = (int)rd32u(G(u8 *, 0x70039c) + 0x40);
      int i = (int)f;
      float d = (float)(int)((u32)t - (u32)i) * G(float, 0x6785e4);
      if (d > G(float, 0x681dc8)) {
        wr32u(self + 0x2c4, (u32)t + 0x800);
        wr32u(self + 0x233, 0);
        ext_633654(G(u32, 0x6f5630));
        return 0;
      }
    }
    u8 *eng = G(u8 *, 0x70039c);
    if ((int)rd32u(self + 0x2c4) > (int)rd32u(eng + 0x40)) {
      ext_633654(G(u32, 0x6f5630));
      return 0;
    }
    u8 *T = table();
    u8 *X = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(p));
    if (X == nullptr) {
      ext_633654(G(u32, 0x6f5630));
      return 0;
    }
    float V[3] = {0.0f, 0.0f, 0.0f};
    (*(V1 *)(vt(X) + 0x84))(X, (u32)V);
    (*(V1 *)(vt(self) + 0x8c))(self, (u32)V);
    if (absgt(V[0], rdf(self + 0x21b)) || absgt(V[1], rdf(self + 0x22b)) || absgt(V[2], rdf(self + 0x223))) {
      ext_523ec0((void *)rd32u(self + 0x5c), rdf(p + 4));
      float z = rdf(p + 8);
      wr32u(self + 0x233, rd32u(p + 8));
      if (z == G(float, 0x67af2c)) wr32u(self + 0x233, 0x7e967699);
    }
    if (self[0x2c3] == 0) {
      ext_633654(G(u32, 0x6f5630));
      return 0;
    }
  } else if (c == rd16u(self + 0x2cc)) {
    void *obj = (void *)rd32u(self + 0x5c);
    wr32u(self + 0x233, 0);
    ext_523180(obj);
  } else if (c == rd16u(self + 0x207)) {
    (*(V1 *)(vt(self) + 0x368))(self, (u32)p);
    ext_633654(G(u32, 0x6f5630));
    return 0;
  } else if (c == rd16u(self + 0x2d0)) {
    u8 *T = table();
    u8 *X = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(p));
    if ((u8 *)self == X) {
      ext_633654(G(u32, 0x6f5630));
      return 0;
    }
  }
  r = ext_5122f0(self, code, p);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(5153e0, fn_5153e0);
