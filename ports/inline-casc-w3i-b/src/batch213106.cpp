#include "ff.h"

typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef double(THISCALL *VD0)(void *);
typedef double(THISCALL *VD1)(void *, float);
typedef void(THISCALL *VF1)(void *, float);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" double VECTORCALL ext_634d7c(double x);  // sqrt
extern "C" void THISCALL ext_515930(void *self, float a, u32 b);
extern "C" void THISCALL ext_523330(void *obj, void *out);
extern "C" void FASTCALL ext_443ef0(void *out, void *p, void *s, float a);
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// cdecl log call M.vtable[0x2c](M, fmt, name) with ecx = the vtable pointer, caller cleans 12 bytes
static inline void logcall1(u8 *M, u32 name) {
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  asm volatile(
      "pushl %[n]\n\t"
      "pushl %[f]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $12, %%esp"
      : "+a"(ra), "+c"(rc)
      : [n] "r"(name), [f] "r"(0x69f03c), [m] "r"(M)
      : "edx", "memory", "cc");
}
// cdecl log call M.vtable[0x2c](M, fmt, name, (double)v) with ecx = name, caller cleans 20 bytes
static inline void logcall2(u8 *M, u32 name, double v) {
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = name;
  asm volatile(
      "subl $8, %%esp\n\t"
      "movsd %[d], (%%esp)\n\t"
      "pushl %%ecx\n\t"
      "pushl %[f]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $20, %%esp"
      : "+a"(ra), "+c"(rc)
      : [d] "x"(v), [f] "r"(0x69f078), [m] "r"(M)
      : "edx", "memory", "cc");
}

// 0x5179c0: thiscall(float a, u32 b) ret 8, /GS protected (aligned frame), no useful return value. 0x515930(this, a, b) and 0x523330(this[0x5c], &V) first. If dot(this+0x15df, V) < 0
// the log manager [0x700390] slot 0x20(0x69eff8, 0x176) gets a cdecl line (name this[4] or "" 0x67c8e8), the point P = this[0x5c]->[8..0x10] is drawn through
// [[0x70039c]+0x9b]->[0xadc] slot 0x218(&P, this[8] + 0x24, 0xff0000). If this[0x1650] == 1: Q = 0x443ef0(this[8]+0x24, this+0x15df, this[0x378]); the this[0x5c] object's
// slot 0x14() (x87) times (this[0x378] + this[0x37c]) goes to its slot 4 and the result of that to its slot 0x20; D = this+0x15eb is set by 0x43e920(D, Q, P), its [4], [0xc] cleared, [0x10] = 1.0f,
// this[0x1650] = 0; a length |D| over [0x67cd40] gets logged (slot 0x20(0x69eff8, 0x190), cdecl line with the double length).
extern "C" void THISCALL fn_5179c0(u8 *self, float a, u32 b) {
  float V[3], P[3], Q[3];
  ext_515930(self, a, b);
  ext_523330((void *)rd32u(self + 0x5c), V);
  const u8 *s = self + 0x15df;
  float t0 = rdf(s) * V[0];
  float t1 = rdf(s + 4) * V[1];
  t1 = t1 + t0;
  float t2 = rdf(s + 8) * V[2];
  t1 = t1 + t2;
  if (0.0f > t1) {
    void *Lg = G(void *, 0x700390);
    u8 *M = (u8 *)(*(V2 *)(vt(Lg) + 0x20))(Lg, 0x69eff8, 0x176);
    u32 name = rd32u(self + 4);
    if (name == 0) name = 0x67c8e8;
    logcall1(M, name);
    u8 *O = (u8 *)rd32u(self + 0x5c);
    P[0] = rdf(O + 8);
    P[1] = rdf(O + 0xc);
    P[2] = rdf(O + 0x10);
    u8 *eng = G(u8 *, 0x70039c);
    u8 *K = (u8 *)rd32u((u8 *)rd32u(eng + 0x9b) + 0xadc);
    (*(V3 *)(vt(K) + 0x218))(K, (u32)P, rd32u(self + 8) + 0x24, 0xff0000);
  }
  if (rd32u(self + 0x1650) == 1) {
    float a2 = rdf(self + 0x378);
    ext_443ef0(Q, (void *)(rd32u(self + 8) + 0x24), (void *)s, a2);
    float T2 = rdf(self + 0x378);
    float T1 = rdf(self + 0x37c);
    u8 *O = (u8 *)rd32u(self + 0x5c);
    double r1 = (*(VD0 *)(vt(O) + 0x14))(O);
    float sum = T2 + T1;
    u8 *O2 = (u8 *)rd32u(self + 0x5c);
    u8 *vt2 = vt(O2);
    double pr = r1 * (double)sum;
    float tf = (float)pr;
    double r2 = (*(VD1 *)(vt2 + 4))(O2, tf);
    (*(VF1 *)(vt2 + 0x20))(O2, (float)r2);
    u8 *O3 = (u8 *)rd32u(self + 0x5c);
    u8 *Dp = self + 0x15eb;
    P[0] = rdf(O3 + 8);
    P[1] = rdf(O3 + 0xc);
    P[2] = rdf(O3 + 0x10);
    ext_43e920(Dp, Q, P);
    wr32u(self + 0x15ef, 0);
    wr32u(self + 0x15f7, 0);
    wr32u(self + 0x15fb, 0x3f800000);
    wr32u(self + 0x1650, 0);
    float d1 = rdf(Dp + 4), d0 = rdf(Dp), d2 = rdf(Dp + 8);
    float q0 = d0 * d0;
    float q1 = d1 * d1;
    float q2 = d2 * d2;
    q0 = q0 + q1;
    q0 = q0 + q2;
    float len = (float)ext_634d7c((double)q0);
    if (len > G(float, 0x67cd40)) {
      void *Lg = G(void *, 0x700390);
      u8 *M = (u8 *)(*(V2 *)(vt(Lg) + 0x20))(Lg, 0x69eff8, 0x190);
      float e1 = rdf(Dp + 4), e0 = rdf(Dp), e2 = rdf(Dp + 8);
      float r0 = e0 * e0;
      float rr1 = e1 * e1;
      float rr2 = e2 * e2;
      r0 = r0 + rr1;
      r0 = r0 + rr2;
      float len2 = (float)ext_634d7c((double)r0);
      u32 name = rd32u(self + 4);
      if (name == 0) name = 0x67c8e8;
      logcall2(M, name, (double)len2);
    }
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5179c0, fn_5179c0);
