#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V4)(void *, u32, u32, u32, u32);

static inline u32 rd32(const u8 *p) { return *(const u32 *)p; }
static inline float rdf(const u8 *p) { return *(const float *)p; }
static inline void wrf(u8 *p, float v) { *(float *)p = v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

static inline double fmodx(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// 0x464760: thiscall(X, flags) ret 8 returning bool. X is a timed-effect record (X[0x70] = Y, the timeline: Y+0x5c/0x6c/0x60/0x64/0x7c). Calls this slot 0x268(Y, Y[0x7c]); builds the
// effective flag word FL from the argument and Y[0x7c]; fills X[0xc] (duration), X[0x2c], the rate fields X[0x20] / X[4] / X[8] / X[0x1c] / X[0x18] and copies Y[0x70..0x78] to
// X[0x38..0x40]; the rate R is zero unless the template W = [[this+0x1c]+0x14] provides a phase offset (fmod through the _CIfmod import). Then asks the table [this+0x5c]
// (slot 0x24 = count; per index slot 0x2c / 0x3c) and this slots 0x2b4 / 0x350 to add entries, counting the successes in X[0x44]. Returns X[0x44] != 0.
extern "C" u32 THISCALL fn_464760(u8 *self, u8 *X, u32 a2) {
  u8 *Y = (u8 *)rd32(X + 0x70);
  *(u32 *)(self + 0x122) = 1;
  (*(V2 *)(vt(self) + 0x268))(self, (u32)Y, rd32(Y + 0x7c));
  float xmm1 = 0.0f;
  u32 f = rd32(Y + 0x7c);
  if (!(a2 & 2) && (int)f < 0) xmm1 = (float)(int)rd32(Y + 0x5c) / (float)(int)rd32(Y + 0x6c);
  u32 edx = a2;
  if ((a2 & 0x10) && (f & 1)) edx |= 4;
  u32 ecx = edx;
  if (f & 2) ecx = edx | 8;
  u32 e2 = ecx;
  if (f & 8) e2 = ecx | 0x200;
  u32 FL = e2;
  if (f & 0x10) FL = e2 | 0x800;
  if (rdf(X + 0x2c) == 0.0f) wrf(X + 0x2c, xmm1);
  float c = G(float, 0x678620);
  float R = 0.0f;
  *(int *)(X + 0xc) = (int)rd32(Y + 0x64) - (int)rd32(Y + 0x60);
  u8 *Z = (u8 *)rd32(self + 0x1c);
  u8 *W = (u8 *)rd32(Z + 0x14);
  if (W != 0 && ((rd32(W + 0x14) & FL) & 8) != 0) {
    Z = (u8 *)rd32(self + 0x1c);
    if (Z[4] & 1) {
      u8 *V = (u8 *)rd32(W + 0x70);
      int esi = (int)rd32(W + 0xc);
      int engt = (int)rd32(G(u8 *, 0x70039c) + 0x40);
      float t0 = (float)(int)rd32(V + 0x6c);
      t0 = t0 * rdf(W + 0x28);
      t0 = t0 * c;
      int eax = (int)t0;
      float t1 = rdf(W + 0x1c);
      t1 = t1 * c;
      int edx2 = (int)t1;
      int ec = engt - edx2;
      long long prod = (long long)ec * (long long)eax;
      int sh = (int)(prod >> 10);
      float sf = (float)sh * G(float, 0x6785e4);
      double A = (double)sf;
      double B = (double)(float)esi;
      double r = fmodx(A, B);
      R = (float)(r / (double)esi);
    }
  }
  u8 *Q = (u8 *)rd32(self + 0x5c);
  u32 n = (*(V1 *)(vt(Q) + 0x24))(Q, (u32)Y);
  float x2 = (float)(int)rd32(X + 0xc);
  wrf(X + 0x20, G(float, 0x678858) / x2);
  if (R == 0.0f) *(u32 *)(X + 4) = rd32(X + 0x30);
  else wrf(X + 4, x2 * R);
  float x4 = rdf(X + 4);
  wrf(X + 8, x4);
  float d = (float)(int)rd32(Y + 0x6c);
  int engt2 = (int)rd32(G(u8 *, 0x70039c) + 0x40);
  d = d * rdf(X + 0x28);
  float q = x4 / d;
  q = q * c;
  int tr = (int)q;
  int diff = engt2 - tr;
  wrf(X + 0x1c, (float)diff * G(float, 0x6785e4));
  float x34 = rdf(X + 0x34);
  if (x34 == G(float, 0x67af2c)) {
    if (FL & 4) *(u32 *)(X + 0x18) = 0x7e967699;
    else wrf(X + 0x18, x2);
  } else {
    wrf(X + 0x18, x34);
  }
  *(u32 *)(X + 0x14) = FL;
  *(u32 *)(X + 0x38) = rd32(Y + 0x70);
  *(u32 *)(X + 0x3c) = rd32(Y + 0x74);
  *(u32 *)(X + 0x40) = rd32(Y + 0x78);
  u32 flv = FL;
  if (n != 0) {
    u32 j = 0;
    do {
      Q = (u8 *)rd32(self + 0x5c);
      u32 rr = (*(V2 *)(vt(Q) + 0x2c))(Q, (u32)Y, j);
      Q = (u8 *)rd32(self + 0x5c);
      u32 al = (u8)(*(V1 *)(vt(Q) + 0x3c))(Q, rr);
      flv = (flv & 0xffffff00u) | al;
      u32 k = (*(V1 *)(vt(self) + 0x2b4))(self, flv);
      if (k != 0xffffffffu) {
        u8 ok = (u8)(*(V4 *)(vt(self) + 0x350))(self, (u32)Y, rr, k, (u32)X);
        if (ok) *(u32 *)(X + 0x44) = rd32(X + 0x44) + 1;
      }
      j++;
    } while (j != n);
  }
  return rd32(X + 0x44) != 0;
}
PCREG(464760, fn_464760);
