#include "ff.h"

extern "C" void THISCALL ext_44ef80(void *self, u32 p, u32 b, u32 z, u32 fbits);
extern "C" void THISCALL ext_44f0f0(void *self, u32 p, u32 fbits);
extern "C" void THISCALL ext_44f550(void *self);

static inline u32 rd32(const u8 *p) { return *(const u32 *)p; }
static inline float rdf(const u8 *p) { return *(const float *)p; }
static inline void wrf(u8 *p, float v) { *(float *)p = v; }
static inline void copy3(u8 *dst, const u8 *src) {
  u32 a = rd32(src), b = rd32(src + 4), c = rd32(src + 8);
  *(u32 *)dst = a;
  *(u32 *)(dst + 4) = b;
  *(u32 *)(dst + 8) = c;
}

// 0x450fc0: thiscall(row, arg) ret 8, void. Cloth / rope relaxation on the vertex array P = [this+0x5c] + 16 * row (2n vertices, n = this[0x44]): P[0..n) and P[n..2n) are initialised
// from the rest positions B = [this+0x58], then 20 iterations of: 0x44ef80 (forces), 0x44f0f0, this[0x18] passes of the distance constraints in this[0x4c] (this[0x48] records
// {u16 a, u16 b, w, c, d}: a spring correction scaled by this[0x34]) followed by re-pinning the vertices whose weight this[0x64][i] is zero to B[i], 0x44f550, and copies
// P[a] -> P[b] for the index pairs in this[0x50] (this[0x54] u16 entries).
extern "C" void THISCALL fn_450fc0(u8 *self, u32 row, u32 arg) {
  u8 *P = *(u8 **)(*(u32 *)(self + 0x5c) + row * 2 * 8);
  u32 n = rd32(self + 0x44);
  if (n != 0) {
    u32 i = 0;
    do {
      u8 *B = (u8 *)rd32(self + 0x58);
      copy3(P + 12 * i, B + 12 * i);
      copy3(P + 12 * (rd32(self + 0x44) + i), (u8 *)rd32(self + 0x58) + 12 * i);
      i++;
    } while (i < rd32(self + 0x44));
  }
  for (u32 iter = 0; iter < 20; iter++) {
    ext_44ef80(self, (u32)P, arg, 0, 0x3c888889);
    ext_44f0f0(self, (u32)P, 0x3c888889);
    u32 j = 0;
    if (rd32(self + 0x18) != 0) do {
      u8 *c = (u8 *)rd32(self + 0x4c);
      u32 cnt = rd32(self + 0x48);
      for (u32 s = 0; s < cnt;) {
        u32 ia = 3 * *(u16 *)c;
        u32 ib = 3 * *(u16 *)(c + 2);
        u8 *pa = P + ia * 4;
        u8 *pb = P + ib * 4;
        float dx = rdf(pb) - rdf(pa);
        float dy = rdf(pb + 4) - rdf(pa + 4);
        float dz = rdf(pb + 8) - rdf(pa + 8);
        float l = dy * dy;
        l = l + dx * dx;
        l = l + dz * dz;
        float w = rdf(c + 4);
        float den = l + rdf(c + 8);
        float q = rdf(c + 0xc) / den;
        float t = G(float, 0x678858) - q;
        t = t * rdf(self + 0x34);
        float sc = w * t;
        wrf(pa, dx * sc + rdf(pa));
        wrf(pa + 4, dy * sc + rdf(pa + 4));
        wrf(pa + 8, dz * sc + rdf(pa + 8));
        float u = sc - t;
        float by = dy * u + rdf(pb + 4);
        float bz = dz * u + rdf(pb + 8);
        float bx = dx * u + rdf(pb);
        wrf(pb + 4, by);
        wrf(pb + 8, bz);
        wrf(pb, bx);
        c += 0x10;
        s++;
        cnt = rd32(self + 0x48);
      }
      if (rd32(self + 0x44) != 0) {
        for (u32 i = 0; i < rd32(self + 0x44); i++) {
          const float *W = (const float *)rd32(self + 0x64);
          if (W[i] == 0.0f) copy3(P + 12 * i, (u8 *)rd32(self + 0x58) + 12 * i);
        }
      }
      j++;
    } while (j < rd32(self + 0x18));
    ext_44f550(self);
    u32 pc = rd32(self + 0x54);
    for (u32 k = 0; k < pc;) {
      const u16 *ix = (const u16 *)rd32(self + 0x50);
      u32 a = ix[k], b = ix[k + 1];
      k += 2;
      copy3(P + 12 * b, P + 12 * a);
      pc = rd32(self + 0x54);
    }
  }
}
PCREG(450fc0, fn_450fc0);
