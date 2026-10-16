#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef long double(THISCALL *VL)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" double VECTORCALL ext_634d70(double x);  // cos
extern "C" double VECTORCALL ext_634d76(double x);  // sin
extern "C" void THISCALL ext_4e0d80(void *v, float f);
extern "C" void FASTCALL ext_43e8e0(void *out, void *b, void *c);
extern "C" void THISCALL ext_4de7a0(void *p);
extern "C" void THISCALL ext_5ceed0(void *self, void *a0, void *a1, void *a2, u32 a3, u32 a4, u32 a5);
extern "C" void THISCALL ext_5cefc0(void *self, void *a0, void *a1, float f, u32 a3);
extern "C" void THISCALL ext_5cf300(void *self, void *a0, void *a1);
extern "C" void THISCALL ext_5a7500(void *self, float x, float y);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x5d2280: thiscall() with no defined return value, /GS protected: aims a camera-like object. d = this[0xa54] (plus [0x68aef8] when it is below this[0xae9]) - this[0xae9] is logged
// through the [0x700390] manager (line 0x8f, format 0x6b4db8 with d as a double) when it falls below [0x67af28]. this slot 0x88(&vec); the direction at this+0xa72 is
// (cos(yaw) * cos(pitch), sin(pitch), sin(yaw) * cos(pitch)) with yaw = this[0xa54], pitch = this[0xa5c] (CRT wrappers cos 0x634d70 / sin 0x634d76, results rounded to float),
// scaled by 0x4e0d80(dir, this[0xdfd]), combined with vec into this+0xd15 (0x43e8e0), scaled to 10000.0f and combined into this+0xa7e; then (after a stack object built by 0x4de7a0) it
// re-scales dir by this[0xb54]'s slot 0xac() (x87) + this[0xdfd], calls 0x5ceed0 / 0x5cefc0 with the points, 0x5cf300(&xy, this+0xa7e) giving the screen offsets x / y (initially the two
// halves of the pitch double, as left on the original's stack), zeroes x / y when [0x67da04] >= this[0xaf9] / this[0xafd] and hands them to 0x5a7500 of this[0xe18] when it exists.
extern "C" void THISCALL fn_5d2280(u8 *self) {
  u8 tmp[24];
  u32 vec[3];
  u32 xy[2];
  float f1 = rdf(self + 0xa54), f0 = rdf(self + 0xae9);
  if (f0 > f1) f1 = f1 + G(float, 0x68aef8);
  float d = f1 - f0;
  if (G(float, 0x67af28) > d) {
    void *L = G(void *, 0x700390);
    u8 *M = (u8 *)(*(V2 *)(vt(L) + 0x20))(L, 0x6b4d68, 0x8f);
    double dd = (double)d;
    u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
    asm volatile(
        "subl $8, %%esp\n\t"
        "movsd %[d], (%%esp)\n\t"
        "pushl %[f]\n\t"
        "pushl %[m]\n\t"
        "call *%%eax\n\t"
        "addl $16, %%esp"
        : "+a"(ra), "+c"(rc)
        : [d] "x"(dd), [f] "r"(0x6b4db8), [m] "r"(M)
        : "edx", "memory", "cc");
  }
  (*(V1 *)(vt(self) + 0x88))(self, (u32)vec);
  u8 *edi = self + 0xa72;
  double a = (double)rdf(self + 0xa5c);
  {
    u64 ab;
    __builtin_memcpy(&ab, &a, 8);
    xy[0] = (u32)ab;
    xy[1] = (u32)(ab >> 32);
  }
  double b = (double)rdf(self + 0xa54);
  double c1 = ext_634d70(b);
  double c2 = ext_634d70(a);
  wrf(edi, (float)(c1 * c2));
  double s1 = ext_634d76(a);
  wrf(edi + 4, (float)s1);
  double s2 = ext_634d76(b);
  double c3 = ext_634d70(a);
  wrf(edi + 8, (float)(s2 * c3));
  ext_4e0d80(edi, rdf(self + 0xdfd));
  ext_43e8e0(self + 0xd15, vec, edi);
  ext_4e0d80(edi, bitsf(0x461c4000));
  u8 *esi = self + 0xa7e;
  ext_43e8e0(esi, vec, edi);
  self[0xd33] = 0;
  self[0xd34] = 0;
  ext_4de7a0(tmp);
  void *W = (void *)rd32u(self + 0xb54);
  long double r = (*(VL *)(vt(W) + 0xac))(W);
  r += (long double)rdf(self + 0xdfd);
  ext_4e0d80(edi, (float)r);
  ext_5ceed0(self, esi, self + 0xcad, edi, 0x10, 1, 0);
  u8 *a8a = self + 0xa8a;
  wr32u(a8a, rd32u(esi));
  wr32u(a8a + 4, rd32u(esi + 4));
  u32 e8 = rd32u(esi + 8);
  wr32u(a8a + 8, e8);
  ext_5cefc0(self, a8a, edi, bitsf(0x42480000), 2);
  ext_5cf300(self, xy, esi);
  float c = G(float, 0x67da04);
  float x, y;
  if (c < rdf(self + 0xaf9) || !(c >= rdf(self + 0xaf9))) {
    __builtin_memcpy(&x, &xy[0], 4);
  } else {
    x = 0.0f;
  }
  if (c < rdf(self + 0xafd) || !(c >= rdf(self + 0xafd))) {
    __builtin_memcpy(&y, &xy[1], 4);
  } else {
    y = 0.0f;
  }
  u8 *P = (u8 *)rd32u(self + 0xe18);
  if (P) ext_5a7500(P, x, y);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5d2280, fn_5d2280);
