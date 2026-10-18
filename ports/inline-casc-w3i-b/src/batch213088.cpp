#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_523330(void *self, void *out);
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);
extern "C" void FASTCALL ext_43e8e0(void *out, void *b, void *c);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x51c560: thiscall() with no defined return value, /GS protected: refreshes the motion state of an actor. this+0x60 = this[0x5c]'s vector (+8..+0x10); 0x523330(this[0x5c], this+0x216)
// fills the direction at this+0x216; when this[0x34a] is a table id the object's slot 0x84(&C) (C preset to 0) gives a point and the direction becomes C - this+0x60 (0x43e920). A nonzero
// direction is normalized in place (x87, 53-bit); then this[0x21a] = 0 (which overwrites the direction's y), this+0x222 = the direction, this+0x90 = this+0x60, a block of fields is reset
// (0x23e / 0x242 / 0x246 / 0x22e..0x23a / 0x262 / 0x26a / 0x3f1 / 0x3f9 = 0, 0x266 / 0x3f5 = 1.0f), the embedded object at this+0x34e gets slot 4(this+0x216, this+0x222), this slot 0x36c(),
// C = this+0x276 (3 floats) goes through this slot 0x88(&C), its y is clamped to [0, [0x67cd44]] and D = this+0x60 - C (0x43e8e0) is passed to this slot 0x7c(this+0x6c, &D).
extern "C" void THISCALL fn_51c560(u8 *self) {
  float C[3], D[3];
  u8 *ebx = self + 0x60;
  u8 *edi = self + 0x216;
  u8 *P = (u8 *)rd32u(self + 0x5c);
  wr32u(ebx, rd32u(P + 8));
  wr32u(ebx + 4, rd32u(P + 0xc));
  wr32u(ebx + 8, rd32u(P + 0x10));
  ext_523330((void *)rd32u(self + 0x5c), edi);
  u32 id = rd32u(self + 0x34a);
  if (id) {
    u8 *eng = G(u8 *, 0x70039c);
    void *T = (void *)rd32u(eng + 0x9b);
    void *Y = (void *)(*(V1 *)(vt(T) + 0x58))(T, id);
    C[0] = C[1] = C[2] = 0.0f;
    (*(V1 *)(vt(Y) + 0x84))(Y, (u32)C);
    ext_43e920(edi, C, ebx);
  }
  if (rdf(edi) != 0.0f || rdf(edi + 4) != 0.0f || rdf(edi + 8) != 0.0f) {
    long double x = rdf(edi), y = rdf(edi + 4), z = rdf(edi + 8);
    long double s = x * x;
    s += y * y;
    s += z * z;
    long double len = fsqrt_x87(s);
    long double inv = 1.0L / len;
    wrf(edi, (float)(x * inv));
    wrf(edi + 4, (float)(y * inv));
    wrf(edi + 8, (float)(z * inv));
  }
  wr32u(self + 0x21a, 0);
  u8 *edx = self + 0x222;
  wr32u(edx, rd32u(edi));
  wr32u(edx + 4, rd32u(edi + 4));
  wr32u(edx + 8, rd32u(edi + 8));
  wr32u(self + 0x90, rd32u(ebx));
  wr32u(self + 0x94, rd32u(ebx + 4));
  wr32u(self + 0x98, rd32u(ebx + 8));
  wr32u(self + 0x246, 0);
  wr32u(self + 0x242, 0);
  wr32u(self + 0x23e, 0);
  wr32u(self + 0x262, 0);
  wr32u(self + 0x266, 0x3f800000);
  wr32u(self + 0x26a, 0);
  wr32u(self + 0x22e, 0);
  wr32u(self + 0x232, 0);
  wr32u(self + 0x236, 0);
  wr32u(self + 0x23a, 0);
  wr32u(self + 0x3f1, 0);
  wr32u(self + 0x3f5, 0x3f800000);
  wr32u(self + 0x3f9, 0);
  {
    u8 *z = self + 0x34e;
    (*(V2 *)(vt(z) + 4))(z, (u32)edi, (u32)edx);
  }
  (*(V0 *)(vt(self) + 0x36c))(self);
  wrf((u8 *)&C[0], rdf(self + 0x276));
  wrf((u8 *)&C[1], rdf(self + 0x27a));
  wrf((u8 *)&C[2], rdf(self + 0x27e));
  (*(V1 *)(vt(self) + 0x88))(self, (u32)C);
  float y = C[1];
  float r;
  if (0.0f > y) {
    r = 0.0f;
  } else {
    float c = G(float, 0x67cd44);
    r = (c < y) ? c : y;
  }
  C[1] = r;
  ext_43e8e0(D, ebx, C);
  (*(V2 *)(vt(self) + 0x7c))(self, (u32)(self + 0x6c), (u32)D);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(51c560, fn_51c560);
