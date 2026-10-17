// batch242020.cpp - Sonnet-w4b, hand port of 0x4b73f0 (the lifter mis-tracks the pushes that straddle the call to 0x4dc130).
#include "ff.h"

#define R32(a) (*(u32 *)(u32)(a))
#define R8(a) (*(u8 *)(u32)(a))
#define W32(a, v) (*(u32 *)(u32)(a) = (u32)(v))
static inline float F_at(u32 a) { float f; __builtin_memcpy(&f, (void *)a, 4); return f; }
static inline void F_set(u32 a, float f) { __builtin_memcpy((void *)a, &f, 4); }
static inline s32 cvtt(float f) { s32 r; __asm__("cvttss2si %1, %0" : "=r"(r) : "x"(f)); return r; }

typedef u32 (THISCALL *ThisFn0)(u32);
typedef u32 (THISCALL *ThisFn1)(u32, u32);
typedef u32 (THISCALL *ThisFn2)(u32, u32, u32);
typedef u32 (THISCALL *ThisFn3)(u32, u32, u32, u32);

extern "C" u32 THISCALL ext_445c50_thiscall1(u32) __asm__("ext_445c50");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4dc130_thiscall1(u32) __asm__("ext_4dc130");
extern "C" u32 THISCALL ext_43eb80_thiscall2(u32, u32) __asm__("ext_43eb80");
extern "C" u32 THISCALL ext_43ec00_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_43ec00");

// 0x4b73f0: thiscall(this, a0, a1) ret 8, void. Attach/refresh the sound/effect object this[0x8d] chosen by this[0x7c]:
// find or create it (slots 0x94 / 0x90 or the helpers 0x43eb80 / 0x43ec00 on the engine registry), then set its flags,
// gain and timing from this[0x54..0x78].
extern "C" void THISCALL port_4b73f0(u32 self, u32 a0, u32 a1) {
  u32 G = R32(0x70039c);
  u32 W = R32(G + 0x1a9f);
  if (W == 0) return;
  u32 ro = ((ThisFn0)R32(R32(W) + 0xc0))(W);
  u32 h = ext_445c50_thiscall1(ro);
  u32 tab = R32(G + 0x9b);
  u32 Q = R32(tab + 0xadc);
  u32 flag = (h == Q) ? 1 : 0;
  float *dummy = 0; (void)dummy;
  if (self + 0x50 != G + 0x40) W32(self + 0x50, R32(G + 0x40));
  u32 edx = 0, c = 0, eax = 0, x = 0, x2 = 0, t = 0, u = 0, e = 0;
  x = R32(self + 0x91);
  if (x == 0) goto L7554;
  t = ((ThisFn2)R32(R32(self) + 0x94))(self, a0, x);
  u = R32(t + 0x54);
  if (u == 0) goto L7554;
  if ((((ThisFn1)R32(R32(u) + 0x1e0))(u, 0x200027) & 0xff) != 0) goto L7554;
  x2 = R32(self + 0x91);
  if (x2) c = ((ThisFn2)R32(R32(self) + 0x94))(self, a0, x2);
  else {
    if (ext_4cc5f0_thiscall1(self + 0x95) == 0) goto L7548;
    u32 v = ext_4cc1d0_thiscall1(self + 0x95);
    c = ((ThisFn3)R32(R32(self) + 0x90))(self, a0, a1, v);
  }
  if (c == 0) goto L7548;
  edx = R32(self + 0x85);
  if (edx == 0) { edx = R32(self + 0x89); if (edx == 0) goto L758b; }
  e = R32(self + 0x7c) - 1;
  if (e == 0) {
    u32 r;
    if (flag) r = ext_43ec00_thiscall7(Q, c, c + 0x24, edx, 0, 0, 0);
    else r = ext_43ec00_thiscall7(ext_4dc130_thiscall1(c), c, c + 0x24, edx, 0, 0, 0);
    W32(self + 0x8d, r);
    goto L758b;
  }
  if (e - 3 != 0) goto L758b;
  eax = edx;
  goto L756f;
L7548:
  eax = R32(self + 0x85);
  if (eax == 0) goto L755e;
  goto L7568;
L7554:
  eax = R32(self + 0x85);
  if (eax != 0) goto L7568;
L755e:
  eax = R32(self + 0x89);
  if (eax == 0) goto L758b;
L7568:
  if (R32(self + 0x7c) != 4) goto L758b;
L756f:
  W32(self + 0x8d, ext_43eb80_thiscall2(R32(R32(R32(0x70039c) + 0x9b) + 0xadc), eax));
L758b:
  {
    u32 d = R32(self + 0x8d);
    if (d == 0) return;
    u32 tt = R32(G + 0x9b);
    u32 k = ((ThisFn1)R32(R32(tt) + 0x60))(tt, d);
    if (k != 0) {
      W32(k + 0x2c, R32(self + 0x80));
      u32 fl = (R32(k + 0x40) & 0xfffffffb) | 0x80;
      W32(k + 0x40, fl);
      if (R32(self + 0x80) == 2) {
        ((ThisFn0)R32(R32(self) + 0x9c))(self);
        W32(k + 0x40, R32(k + 0x40) & 0xfffffff7);
      }
      if (flag & 0xff) W32(k + 0x40, R32(k + 0x40) | 0x20);
      u32 W2 = R32(G + 0x1a9f);
      u32 al = ((ThisFn1)R32(R32(W2) + 0x70))(W2, R32(self + 0x89));
      if ((al & 0xff) && R32(self + 0x7c) == 3) F_set(self + 0x54, F_at(self + 0x54) * F_at(0x67a6ac));
      u32 m = R32(self + 0x78);
      if (m != 0 && R32(self + 0x70) == 0) { W32(k + 0x60, m - R32(k + 0x64)); W32(k + 0x64, m); }
      float f = F_at(self + 0x54);
      if (f != 0.0f || f != f) F_set(k + 0x88, f);
      u32 a = R32(self + 0x68);
      if (a != 0) { F_set(self + 0x58, F_at(0x678858) / (float)(s32)a); W32(k + 0x84, 0); }
      u32 b = R32(self + 0x6c);
      if (b != 0) F_set(self + 0x5c, F_at(0x678858) / (float)(s32)b);
    }
    ((ThisFn1)R32(R32(self) + 0x64))(self, 0x10);
  }
}
PCREG(4b73f0, port_4b73f0);

// ---------------------------------------------------------------------------------------------------------------
// 0x4bf890: thiscall(this), void (hand port: the lifter lost the 6 pushes of 0x43ec00 behind the 0-arg slot 0x20 call)
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 THISCALL ext_44b850_thiscall2(u32, u32) __asm__("ext_44b850");
extern "C" u32 THISCALL ext_44b880_thiscall2(u32, u32) __asm__("ext_44b880");

typedef float (THISCALL *FloatArgFn)(u32, u32);

// advance the animation frame state this[0x1b0..0x1d0] (frame counter 0x1c8 of 0x1c4, limit 0x1c0) every
// (this[0x1b8] seconds), then re-spawn the attached effect: 0x43ec00 at the owner's position, hand its node list to 0x44b850 / 0x44b880
extern "C" void THISCALL port_4bf890(u32 self) {
  u32 G = R32(0x70039c);
  if (R32(G + 0x1a9f) == 0) return;
  s32 T = (s32)R32(G + 0x40);
  s32 a = cvtt(F_at(self + 0x1bc) * F_at(0x678620));
  s32 b = cvtt(F_at(self + 0x1b8) * F_at(0x678620));
  if (T - a <= b) return;
  u32 flag = R32(self + 0x1cc);
  F_set(self + 0x1bc, (float)T * F_at(0x6785e4));
  if (flag != 0) {
    if (R32(self + 0x1c8) == R32(self + 0x1c4)) ((ThisFn1)R32(R32(self) + 0x60))(self, R32(self + 0x1b4));
    W32(self + 0x1c8, R32(self + 0x1c8) - 1);
    if ((s32)R32(self + 0x1c4) > (s32)R32(self + 0x1c0)) { W32(self + 0x1c4, 1); W32(self + 0x1c8, 0); }
    if (R32(self + 0x1c8) == 0) {
      W32(self + 0x1c4, R32(self + 0x1c4) + 1);
      W32(self + 0x1c8, R32(self + 0x1c4));
      W32(self + 0x1b8, R32(self + 0x1b0));
    }
  } else {
    u32 d = R32(self + 0x1c8), c4 = R32(self + 0x1c4);
    if (d == c4) W32(self + 0x1b8, R32(self + 0x1b4));
    W32(self + 0x1c8, d - 1);
    if (d - 1 == 0) { W32(self + 0x1c8, c4); W32(self + 0x1b8, R32(self + 0x1b0)); }
  }
  if (R32(self + 0x1d0) == 0) { W32(self + 0x1d0, 1); return; }
  u32 P = R32(self + 0x44);
  u32 Q = R32(P + 8);
  float v[3];
  v[0] = F_at(Q + 0x30); v[1] = F_at(Q + 0x34); v[2] = F_at(Q + 0x38);
  ext_441a60_fastcall2((u32)v, Q);
  ext_441940_fastcall2((u32)v, R32(P + 8) + 0x24);
  u32 e = R32(self + 0x1a8);
  if (e != 0) {
    u32 tab = R32(G + 0x9b);
    u32 O = ((ThisFn1)R32(R32(tab) + 0x58))(tab, e);
    if (O != 0) ((ThisFn1)R32(R32(O) + 0x210))(O, 1);
    W32(self + 0x1a8, 0);
  }
  u32 res;
  u32 h = R32(self + 0x1a0);
  if (h == 0) h = R32(self + 0x1a4);
  if (h == 0) return;
  P = R32(self + 0x44);
  u32 X = ((ThisFn0)R32(R32(P) + 0x20))(P);
  res = ext_43ec00_thiscall7(X, R32(P + 8), (u32)v, h, 0, 0, 0);
  if (res == 0) return;
  u32 tab = R32(R32(0x70039c) + 0x9b);
  u32 k = ((ThisFn1)R32(R32(tab) + 0x60))(tab, res);
  u32 c1 = self + 0x48;
  u32 cnt = ((ThisFn0)R32(R32(self + 0x48) + 0x14))(c1);
  if (cnt != 0) {
    u32 st;
    ((ThisFn1)R32(R32(c1) + 0x4c))(c1, (u32)&st);
    u32 el = ((ThisFn1)R32(R32(c1) + 0x5c))(c1, (u32)&st);
    if (st != 0) {
      do {
        ext_44b850_thiscall2(k, el);
        el = ((ThisFn1)R32(R32(c1) + 0x5c))(c1, (u32)&st);
      } while (st != 0);
    }
  }
  u32 c2 = self + 0xf4;
  cnt = ((ThisFn0)R32(R32(self + 0xf4) + 0x14))(c2);
  if (cnt != 0) {
    u32 st;
    ((ThisFn1)R32(R32(c2) + 0x4c))(c2, (u32)&st);
    u32 el = ((ThisFn1)R32(R32(c2) + 0x5c))(c2, (u32)&st);
    if (st != 0) {
      do {
        ext_44b880_thiscall2(k, el);
        el = ((ThisFn1)R32(R32(c2) + 0x5c))(c2, (u32)&st);
      } while (st != 0);
    }
  }
  W32(self + 0x1a8, res);
}
PCREG(4bf890, port_4bf890);

// ---------------------------------------------------------------------------------------------------------------
// 0x581c10: thiscall(this), void. Five-slot collision/ground probe (hand port: the lifter cannot match the float slot pushed
// before the branch with the 2-argument ret-8 callee 0x4e71b0).
extern "C" u32 THISCALL ext_4e71b0_thiscall3(u32, u32, u32) __asm__("ext_4e71b0");
extern "C" u32 THISCALL ext_4e73b0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4e73b0");
extern "C" u32 THISCALL ext_581b60_thiscall2(u32, u32) __asm__("ext_581b60");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_4e0900_fastcall2(u32, u32) __asm__("ext_4e0900");
extern "C" u32 FASTCALL ext_4e08d0_fastcall2(u32, u32) __asm__("ext_4e08d0");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");

typedef u32 (THISCALL *ThisFn8)(u32, u32, u32, u32, u32, u32, u32, u32, u32);
static inline u32 F2UB(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

extern "C" void THISCALL port_581c10(u32 self) {
  u32 G = R32(0x70039c);
  float z0[3] = {0, 0, 0}, lo[3], hi[3], v[3], v1[3], v2[3], d[3], d2[3];
  u32 S[16];
  { u32 b = 0x7e967699; __builtin_memcpy(lo, &b, 4); __builtin_memcpy(lo + 1, &b, 4); __builtin_memcpy(lo + 2, &b, 4);
    u32 c = 0xfe967699; __builtin_memcpy(hi, &c, 4); __builtin_memcpy(hi + 1, &c, 4); __builtin_memcpy(hi + 2, &c, 4); }
  float tY = (float)(s32)R32(G + 0x44) * F_at(0x6785e4);
  float tX = (float)(s32)R32(G + 0x40) * F_at(0x6785e4);
  u32 pflag = self + 0x1c9, chunk = self + 0x9d, arr = self + 0x179, vec = self + 0x18d, rec = self + 0x212;
  for (int it = 5; it != 0; it--, pflag++, arr += 4, vec += 0xc, chunk += 0x2c, rec += 0x44) {
    if (R8(pflag) == 0) {
      ext_4e71b0_thiscall3(chunk, (u32)v, F2UB(0.0f));
    } else {
      ext_4e71b0_thiscall3(chunk, (u32)v1, F2UB(tY));
      ext_4e71b0_thiscall3(chunk, (u32)v2, F2UB(tX));
      S[0] = 0x3f800000;
      ext_43e920_fastcall3((u32)d, (u32)v2, (u32)v1);
      u32 R1 = R32(G + 0x1aa3);
      u32 ecx = R32(R1 + 0x1c);
      u32 al = ((ThisFn8)R32(R32(ecx) + 0x30))(ecx, (u32)S, 0, (u32)v1, (u32)d, 0, (u32)-1, 1, 1) & 0xff;
      if (al == 0) { v[0] = v2[0]; v[1] = v2[1]; v[2] = v2[2]; }
      else {
        u32 H = S[4];
        u32 hn = R32(H + 0x54);
        if ((((ThisFn1)R32(R32(hn) + 0x1e0))(hn, 0x2003e8) & 0xff) != 0 && (((ThisFn0)R32(R32(hn) + 0x438))(hn) & 0xff) != 0) continue;
        u32 f = R32(R32(hn + 8) + 0x3c);
        if ((f & 0x40040000) == 0) {
          W32(arr, 0);
        } else {
          if ((((ThisFn1)R32(R32(hn) + 0x1e0))(hn, 0x200074) & 0xff) != 0) W32(hn + 0x1de, self);
          u32 tb = R32(G + 0x9b);
          u32 id = ((ThisFn1)R32(R32(tb) + 0x4c))(tb, hn);
          W32(arr, id);
          W32(vec, 0); W32(vec + 4, 0); W32(vec + 8, 0);
          ((ThisFn1)R32(R32(hn) + 0x84))(hn, vec);
        }
        ext_4e73b0_thiscall6(chunk, (u32)&S[1], (u32)z0, (u32)z0, F2UB(0.0f), F2UB(0.0f));
        *(u8 *)pflag = 0;
        ext_581b60_thiscall2((u32)S, vec + 0x41);
        ((ThisFn1)R32(R32(hn) + 0x88))(hn, vec + 0x41);
        __builtin_memcpy(v, &S[1], 12);
      }
    }
    ext_4e0900_fastcall2((u32)lo, (u32)v);
    ext_4e08d0_fastcall2((u32)hi, (u32)v);
    F_set(rec - 8, v[0]); F_set(rec - 4, v[1]); F_set(rec, v[2]);
    W32(rec + 4, 0x42f00000); W32(rec + 8, 0x43480000); W32(rec + 0xc, 0x42f00000);
    ext_4de7a0_thiscall1(rec + 0x10);
  }
  u32 tb = R32(G + 0x9b);
  u32 Nn = ((ThisFn1)R32(R32(tb) + 0x58))(tb, R32(self + 0x362));
  if (Nn == 0) return;
  ext_43e8e0_fastcall3((u32)d2, (u32)lo, (u32)hi);
  ext_4e0d00_thiscall2((u32)d2, F2UB(0.5f));
  const float *src = (const float *)(self + 0x74);
  if (src[0] == 0.0f && src[1] == 0.0f && src[2] == 0.0f) { v[0] = v[1] = v[2] = 0.0f; }
  else {
    long double s = (long double)src[0] * (long double)src[0];
    s += (long double)src[1] * (long double)src[1];
    s += (long double)src[2] * (long double)src[2];
    long double len = fsqrt_x87(s);
    long double inv = (long double)1.0f / len;
    v[0] = (float)((long double)src[0] * inv);
    v[1] = (float)((long double)src[1] * inv);
    v[2] = (float)((long double)src[2] * inv);
  }
  ext_451890_fastcall3((u32)d2, (u32)v, F2UB(-200.0f));
  ((ThisFn1)R32(R32(Nn) + 0x78))(Nn, (u32)d2);
}
PCREG(581c10, port_581c10);

// ---------------------------------------------------------------------------------------------------------------
// 0x582e20: thiscall(this), void. Particle emitter: spawns the particles whose emission times (this[0x60] < 0) have passed.
// The exe frame is reproduced as F[]: byte offset k of F is [esp0 + k] where esp0 is the stack pointer after `sub esp, 0x88`
// (all offsets below were decoded with the pushes in flight at each site).
extern "C" u32 THISCALL ext_456b70_thiscall3(u32, u32, u32) __asm__("ext_456b70");
typedef float (THISCALL *RandFn3)(u32, u32, u32);
typedef u32 (THISCALL *ThisFn4)(u32, u32, u32, u32, u32);
static inline double D_at2(u32 a) { double d; __builtin_memcpy(&d, (void *)a, 8); return d; }

static void norm3_inplace(float *v) {
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f) return;
  long double s = (long double)v[0] * (long double)v[0];
  s += (long double)v[1] * (long double)v[1];
  s += (long double)v[2] * (long double)v[2];
  long double len = fsqrt_x87(s);
  long double inv = (long double)1.0f / len;
  v[0] = (float)((long double)v[0] * inv);
  v[1] = (float)((long double)v[1] * inv);
  v[2] = (float)((long double)v[2] * inv);
}

extern "C" void THISCALL port_582e20(u32 self) {
  u8 Fb[0x90] __attribute__((aligned(8)));
  for (int i = 0; i < 0x90; i++) Fb[i] = 0xcc;
  #define L(off) ((u32)(Fb + (off)))
  #define LF(off) (*(float *)(Fb + (off)))
  #define LU(off) (*(u32 *)(Fb + (off)))
  u32 G = R32(0x70039c);
  float Kc = F_at(0x679544), one = F_at(0x678858);
  float tNow = (float)(s32)R32(G + 0x40) * F_at(0x6785e4);
  F_set(self + 0x60, F_at(self + 0x60) - F_at(G + 0x48));
  LF(0x14) = tNow;
  float x0 = F_at(self + 0x5c) + Kc - tNow;
  if (one > x0) {
    float r2 = (one - x0);
    float x3 = F_at(self + 0x50) * F_at(0x680a70);
    r2 = r2 / Kc;
    float x0b = one - r2;
    x3 = x3 * r2;
    x0b = x0b * F_at(self + 0x50);
    x3 = x3 + x0b;
    LF(0x08) = x3;
  } else LF(0x08) = F_at(self + 0x50);
  u32 tab = R32(G + 0x9b);
  u32 A = ((ThisFn1)R32(R32(tab) + 0x58))(tab, R32(self + 0x4c));
  if (A == 0) return;
  ext_456b70_thiscall3(A, L(0x10), L(0x28));
  tab = R32(R32(0x70039c) + 0x9b);
  u32 edi = ((ThisFn1)R32(R32(tab) + 0x58))(tab, LU(0x10));
  float a = F_at(self + 0x60);
  float s = LF(0x08);
  LF(0x04) = a;
  LF(0x2c) = s / Kc;
  if (0.0f > a) {
    do {
      u32 i = R32(self + 0x64);
      float t = LF(0x04) + LF(0x14);
      LU(0x6c) = 0; LU(0x70) = 0x43160000; LU(0x74) = 0;
      u8 flag = R8(self + i + 0x1c9);
      LF(0x24) = t;
      u32 chunk = self + 0x9d + i * 0x2c;
      u32 edx2;
      if (flag != 0) {
        ext_4e71b0_thiscall3(chunk, L(0x54), F2UB(t));
        for (int j = 0; j < 3; j++) {
          u32 G2 = R32(0x70039c);
          float r = ((RandFn3)R32(R32(G2) + 0x1c4))(G2, 0x6ab6d4, 0x45e);
          LF(0x30 + 4 * j) = (float)((long double)r * (long double)F_at(0x67da20));
        }
        edx2 = L(0x30);
      } else {
        ext_4e71b0_thiscall3(chunk, L(0x54), F2UB(0.0f));
        u32 G2 = R32(0x70039c);
        u32 tb = R32(G2 + 0x9b);
        u32 N = ((ThisFn1)R32(R32(tb) + 0x58))(tb, R32(self + R32(self + 0x64) * 4 + 0x179));
        if (N != 0) {
          LU(0x48) = 0; LU(0x4c) = 0; LU(0x50) = 0;
          ((ThisFn1)R32(R32(N) + 0x84))(N, L(0x48));
          u32 idx = R32(self + 0x64);
          ext_43e920_fastcall3(L(0x78), L(0x48), self + 0x18d + idx * 12);
          ext_441940_fastcall2(L(0x54), L(0x78));
          LU(0x68) = 0; LU(0x64) = 0; LU(0x60) = 0;
          ext_4e73b0_thiscall6(self + 0x9d + R32(self + 0x64) * 0x2c, L(0x54), L(0x60), L(0x60), F2UB(0.0f), F2UB(0.0f));
          G2 = R32(0x70039c);
          ext_4e0d00_thiscall2(L(0x78), F2UB(one / F_at(G2 + 0x48)));
          ext_441940_fastcall2(L(0x6c), L(0x78));
          idx = R32(self + 0x64);
          F_set(self + idx * 12 + 0x18d, LF(0x48));
          F_set(self + idx * 12 + 0x191, LF(0x4c));
          F_set(self + idx * 12 + 0x195, LF(0x50));
        }
        for (int j = 0; j < 3; j++) {
          u32 G3 = R32(0x70039c);
          float r = ((RandFn3)R32(R32(G3) + 0x1c4))(G3, 0x6ab6d4, 0x478);
          LF(0x3c + 4 * j) = r;
        }
        u32 idx = R32(self + 0x64);
        u32 Dv = self + 0x1ce + idx * 12;
        float d1 = F_at(Dv + 4) * LF(0x40);
        float d0 = F_at(Dv) * LF(0x3c);
        d1 = d1 + d0;
        float d2 = F_at(Dv + 8) * LF(0x44);
        d1 = d1 + d2;
        d1 = -d1;
        ext_451890_fastcall3(L(0x3c), Dv, F2UB(d1));
        norm3_inplace((float *)L(0x3c));
        u32 G4 = R32(0x70039c);
        float r = ((RandFn3)R32(R32(G4) + 0x1c0))(G4, 0x6ab6d4, 0x47c);
        double dr = (double)r;
        float f = (float)(crt::sqrt(dr) * D_at2(0x693d60));
        ext_4e0d00_thiscall2(L(0x3c), F2UB(f));
        idx = R32(self + 0x64);
        ext_451890_fastcall3(L(0x54), self + 0x1ce + idx * 12, F2UB(10.0f));
        edx2 = L(0x3c);
      }
      ext_441940_fastcall2(L(0x54), edx2);
      float tt = LF(0x24) + LF(0x04);
      s32 ti = cvtt(tt * F_at(0x678620));
      ((ThisFn4)R32(R32(edi) + 0x218))(edi, LU(0x28), L(0x54), L(0x6c), (u32)ti);
      W32(self + 0x64, R32(self + 0x64) + 1);
      if (R32(self + 0x64) == 5) W32(self + 0x64, 0);
      float x1 = LF(0x04) + LF(0x2c);
      LF(0x04) = x1;
      if (!(0.0f > x1)) break;
    } while (true);
    s = LF(0x08);
  }
  if (0.0f > F_at(self + 0x60)) {
    float v;
    do {
      v = F_at(self + 0x60) + s;
      F_set(self + 0x60, v);
    } while (0.0f > v);
  }
  #undef L
  #undef LF
  #undef LU
}
PCREG(582e20, port_582e20);

// ---------------------------------------------------------------------------------------------------------------
// 0x40c780: cdecl(float *A, u32 b, int *T) void. Envelope fill: T[0] points (index list T[3], values A[i]) are max-merged into a
// zeroed array L of T[1] floats (dynamic stack array), the gaps between consecutive indices are linearly interpolated,
// the tail repeats the last value; A is shifted by -K and back around two debug prints; finally 0x4078d0(L, b, T + 0x14).
extern "C" void ext_40ce50_cdecl6(u32, u32, u32, u32, u32, u32) __asm__("ext_40ce50");
extern "C" void ext_4078d0_cdecl3(u32, u32, u32) __asm__("ext_4078d0");

extern "C" void port_40c780(u32 Ap, u32 b, u32 T) {
  float *A = (float *)Ap;
  u32 m = R32(T + 4);
  float *L = (float *)__builtin_alloca((m * 4 + 3) & ~3u);
  for (u32 j = 0; j < m; j++) L[j] = 0.0f;
  s32 prev = 0;
  s32 edx = 0;
  const s32 *idxs;
  for (s32 i = 0; (s32)R32(T) > 0 && i < (s32)R32(T); i++) {
    idxs = (const s32 *)R32(T + 0xc);
    edx = idxs[i];
    if ((long double)L[edx] < (long double)A[i]) L[edx] = A[i];
    if (edx > prev + 1) {
      s32 cnt = edx - prev;
      if (cnt > 1) {
        for (s32 k = 1; k < cnt; k++) {
          long double frac = (long double)k / (long double)cnt;
          long double w = (long double)F_at(0x6be05c) - frac;
          w = w * (long double)L[prev];
          long double u = frac * (long double)L[edx];
          L[prev + k] = (float)(u + w);
        }
      }
    }
    prev = edx;
  }
  for (s32 j = edx + 1; j < (s32)m; j++) L[j] = L[j - 1];
  for (s32 k = 0; k < (s32)R32(T); k++) A[k] = (float)((long double)A[k] - (long double)F_at(0x6be0f8));
  ext_40ce50_cdecl6(0x6f23b0, R32(0x725484), (u32)L, (u32)edx, 0, 0);
  u32 cnt = R32(0x725484);
  W32(0x725484, cnt + 1);
  ext_40ce50_cdecl6(0x6f23a4, cnt, (u32)A, R32(T), 1, 0);
  for (s32 k = 0; k < (s32)R32(T); k++) A[k] = (float)((long double)A[k] + (long double)F_at(0x6be0f8));
  ext_4078d0_cdecl3((u32)L, b, T + 0x14);
}
PCREG(40c780, port_40c780);

// ---------------------------------------------------------------------------------------------------------------
// 0x403fe0: cdecl(O, a1, a2, a3, a4, float f5, float f6), void. Per-bin clamp/merge of two float curves around the helpers 0x404700 / 0x4042c0 / 0x404460.
extern "C" void ext_404700_cdecl6(u32, u32, u32, u32, u32, u32) __asm__("ext_404700");
extern "C" void ext_4042c0_cdecl6(u32, u32, u32, u32, u32, u32) __asm__("ext_4042c0");
extern "C" void ext_404460_cdecl3(u32, u32, u32) __asm__("ext_404460");
static inline float BF(u32 b) { float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline s32 ftol_st0_plus(const float *p, u32 k) {      // fld dword [p]; fadd qword [k]; call _ftol (st0 -> eax)
  s32 r;
  __asm__ volatile("flds %1; faddl %2; call ext_634dfa" : "=a"(r) : "m"(*p), "m"(*(const double *)k) : "edx", "ecx", "st", "memory", "cc");
  return r;
}

extern "C" void port_403fe0(u32 O, u32 a1, u32 a2, u32 a3, u32 a4, u32 f5b, u32 f6b) {
  float f5 = BF(f5b), f6 = BF(f6b);
  s32 n = (s32)R32(O + 0x2c);
  s32 cnt = (s32)R32(O);
  float *L = (float *)__builtin_alloca(((u32)n * 4 + 3) & ~3u);
  float *A1 = (float *)a1, *A2 = (float *)a2, *A3 = (float *)a3;
  if (n > 0) {
    s32 i = 0;
    do { W32((u32)(L + i), 0xc61c3c00); i++; } while (i < (s32)R32(O + 0x2c));
  }
  u32 Q = R32(O + 4);
  if (R32(Q + 0x660) != 0) {
    float *L2 = (float *)__builtin_alloca(((u32)cnt * 4 + 3) & ~3u);
    ext_404700_cdecl6((u32)cnt, R32(O + 0x1c), a2, a3, 0x430c0000, (u32)-1);
    for (s32 j = 0; j < cnt; j++) L2[j] = (float)((long double)A2[j] - (long double)A3[j]);
    ext_404700_cdecl6((u32)cnt, R32(O + 0x1c), (u32)L2, a3, 0, R32(Q + 0x678));
    for (s32 j = 0; j < cnt; j++) L2[j] = (float)((long double)A2[j] - (long double)L2[j]);
    ext_40ce50_cdecl6(0x6f1db4, R32(0x725478), (u32)L2, (u32)cnt, 1, 0);
    for (s32 j = 0; j < cnt; j++) A3[j] = (float)((long double)L2[j] + (long double)A3[j]);
    ext_40ce50_cdecl6(0x6f1da4, R32(0x725478), a3, (u32)cnt, 1, 0);
    for (s32 j = 0; j < cnt; j++) A3[j] = (float)((long double)A3[j] - (long double)L2[j]);
    for (s32 i = 0; i < cnt; i++) {
      s32 e = ftol_st0_plus(&A3[i], 0x6be020);
      if (e >= 0x28) e = 0x27;
      u32 Qn = R32(O + 4);
      long double sum = (long double)F_at(Qn + 0x6c0 + e * 4);
      sum += (long double)F_at(R32(O + 0x10) + i * 4);
      sum += (long double)L2[i];
      sum += (long double)f6;
      A3[i] = (float)sum;
      if (sum > (long double)F_at(Qn + 0x664)) W32((u32)&A3[i], R32(Qn + 0x664));
    }
    ext_40ce50_cdecl6(0x6f1d9c, R32(0x725478), a3, (u32)cnt, 1, 0);
  } else {
    for (s32 j = 0; j < cnt; j++) W32((u32)&A3[j], 0xc61c3c00);
  }
  Q = R32(O + 4);
  if (Q != 0) {
    long double t = (long double)f5 + (long double)F_at(Q + 0x6c);
    if (!(t >= (long double)F_at(Q + 0x70))) t = (long double)F_at(Q + 0x70);
    for (s32 i = 0; i < cnt; i++) {
      long double u = t + (long double)F_at(R32(O + 0x14) + i * 4);
      if (u > (long double)A3[i]) A3[i] = (float)u;
    }
  }
  ext_4042c0_cdecl6(O, R32(O + 8), a1, a3, (u32)L, a4);
  ext_404460_cdecl3(O, (u32)L, a3);
  s32 k = 0;
  if (cnt > 0) {
    while (true) {
      if (!((long double)A2[k] < (long double)A3[k])) break;
      k++;
      if (!(k < cnt)) break;
    }
  }
  if (k == cnt) {
    for (s32 j = 0; j < cnt; j++) W32((u32)&A3[j], 0xc61c3c00);
  } else if (cnt > 0) {
    for (s32 i = 0; i < cnt; i++) {
      if (!((long double)A1[i] >= (long double)A2[i])) A1[i] = A2[i];
    }
  }
  W32(0x725478, R32(0x725478) + 1);
}
PCREG(403fe0, port_403fe0);

// ---------------------------------------------------------------------------------------------------------------
// 0x4b34d0: thiscall(this, u16 id, u32 val) ret 8, SEH (handler 0x668ac6). Input-event handler of a UI/trigger object (hand port:
// the lifter cannot read the aligned-alloca helper 0x633c90).
extern "C" u32 THISCALL ext_4b3270_thiscall1(u32) __asm__("ext_4b3270");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1b(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4dc630_thiscall3b(u32, u32, u32) __asm__("ext_4dc630");
typedef u32 (__attribute__((cdecl)) *CdeclFn3b)(u32, u32, u32);
typedef u32 (__attribute__((cdecl)) *CdeclFn2b)(u32, u32);
typedef u32 (THISCALL *ThisFn4b)(u32, u32, u32, u32, u32);

typedef u32 (THISCALL *ThisFn4c)(u32, u32, u32, u32, u32);
extern "C" u32 THISCALL port_4b34d0(u32 self, u32 a0, u32 val) {
  volatile SehRecord reg; reg.next = seh_head(); reg.handler = (0x668ac6); reg.state = -1; seh_set_head(&reg);
  u32 id = a0 & 0xffff;
  u32 G, tab, C, o, v, L, X, P, N, esi, edi, h, id3, r;
  u32 strobj[8];
  if (id == (R32(self + 0x4e) & 0xffff)) {
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    v = 0;
    ((ThisFn2)R32(R32(C) + 0x88))(C, 0x692430, (u32)&v);
    edi = v;
    X = R32(self + 0x44);
    esi = R32(X);
    G = R32(0x70039c); tab = R32(G + 0x9b);
    h = ((ThisFn4c)R32(R32(tab) + 0x114))(tab, 0x692424, 0, 0x691edc, 0x7d4);
    X = R32(self + 0x44);
    ((ThisFn3)R32(esi + 0x12c))(X, edi, h & 0xffff, (u32)-1);
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    v = 0;
    ((ThisFn2)R32(R32(C) + 0x88))(C, 0x681320, (u32)&v);
    G = R32(0x70039c); tab = R32(G + 0x9b);
    N = ((ThisFn1)R32(R32(tab) + 0x58))(tab, v);
    if (N != 0 && (((ThisFn1)R32(R32(N) + 0x1e0))(N, 0x80200014) & 0xff) != 0) ((ThisFn1)R32(R32(N) + 0x594))(N, 0);
    W32(self + 0x88, val);
    if (R8(self + 0x9e) != 0) goto L39d8;
    *(u8 *)(self + 0x4d) = 1;
    G = R32(0x70039c); tab = R32(G + 0x9b);
    {
      u32 W = ((ThisFn0)R32(R32(tab) + 0x134))(tab);
      if (W != 0) ((ThisFn2)R32(R32(W) + 0x20))(W, 0x692440, 0x679e54);
    }
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    v = 0;
    ((ThisFn2)R32(R32(C) + 0x88))(C, 0x692314, (u32)&v);
    G = R32(0x70039c);
    if (v != 0) goto L388b;
    if (R8(self + 0x98) != 0 && R32(R32(G + 0x190f) + 0xfd) != 0) goto L388b;
    W32(self + 0xda, R32(G + 0x40));
    {
      bool f9a = R8(self + 0x9a) != 0;
      W32(self + 0xd6, 0); W32(self + 0xe6, 0);
      *(u8 *)(self + 0x9e) = 1; *(u8 *)(self + 0x9f) = 0;
      W32(self + 0xa6, 0);
      if (!f9a && R32(self + 0x80) == 0) goto L3808;
    }
    G = R32(0x70039c); tab = R32(G + 0x9b);
    esi = ((ThisFn1)R32(R32(tab) + 0x58))(tab, R32(self + 0x74));
    if (esi != 0) goto L37f4;
    G = R32(0x70039c);
    {
      u32 Q = R32(R32(G + 0x9b) + 0xadc);
      esi = ((ThisFn2)R32(R32(Q) + 0x25c))(Q, 0x6924a4, esi);
    }
    if (esi != 0) goto L37f4;
    L = R32(0x700390);
    o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x691edc, 0x81e);
    ((CdeclFn2b)R32(R32(o) + 0x2c))(o, 0x6924b4);
    G = R32(0x70039c);
    {
      u32 Q = R32(R32(G + 0x9b) + 0xadc);
      esi = ((ThisFn4c)R32(R32(Q) + 0x294))(Q, 0x6924a4, 0x67c8e0, esi, 1);
    }
    if (R32(self + 0x80) != 0) {
      *(u8 *)(self + 0x9a) = 1;
      L = R32(0x700390);
      o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x691edc, 0x828);
      ((CdeclFn2b)R32(R32(o) + 0x2c))(o, 0x6924d0);
      G = R32(0x70039c); tab = R32(G + 0x9b);
      u32 T = ((ThisFn1)R32(R32(tab) + 0x54))(tab, R32(self + 0x80));
      u32 va[3], vb[3];
      ext_4db6c0_thiscall3(T, (u32)va, (u32)vb);
      ((ThisFn2)R32(R32(esi) + 0x7c))(esi, (u32)va, (u32)vb);
    }
    ext_4dc630_thiscall3b(R32(esi + 8), 0x800000, 0);
    *(u8 *)(self + 0xa0) = 1;
L37f4:
    G = R32(0x70039c); tab = R32(G + 0x9b);
    W32(self + 0x74, ((ThisFn1)R32(R32(tab) + 0x4c))(tab, esi));
L3808:
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    esi = C;
    {
      u32 n = ((ThisFn1)R32(R32(esi) + 0xa8))(esi, 0x6923e4);
      u32 e = n >> 2;
      u32 *bufp = (u32 *)__builtin_alloca(e * 4 + 4);
      if (e != 0) ((ThisFn2)R32(R32(esi) + 0x88))(esi, 0x6923e4, (u32)bufp);
      G = R32(0x70039c); tab = R32(G + 0x9b);
      bufp[e] = ((ThisFn1)R32(R32(tab) + 0x4c))(tab, R32(self + 0x44));
      ((ThisFn3)R32(R32(esi) + 0x28))(esi, 0x6923e4, (u32)bufp, e + 1);
    }
    goto L39d8;
L388b:
    G = R32(0x70039c); tab = R32(G + 0x9b);
    id3 = ((ThisFn1)R32(R32(tab) + 0x4c))(tab, R32(self + 0x44));
    P = R32(0x700334);
    r = ((ThisFn1)R32(R32(P) + 0x2c))(P, id3);
    L = R32(0x700390);
    if (r == 0) {
      o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x691edc, 0x7f5);
      X = R32(self + 0x44);
      u32 s = ((ThisFn2)R32(R32(X) + 0x1d8))(X, (u32)strobj, 0);
      reg.state = 0;
      h = ext_4cc1d0_thiscall1b(s);
      ((CdeclFn3b)R32(R32(o) + 0x2c))(o, 0x69245c, h);
      reg.state = -1;
      ext_4cbec0_thiscall1((u32)strobj);
      P = R32(0x700334);
      u32 rec = ((ThisFn1)R32(R32(P) + 4))(P, id3);
      W32(rec, R32(self + 0x88));
      W32(rec + 4, R32(self + 0x4e) & 0xffff);
      goto L39d8;
    }
    o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x691edc, 0x7fb);
    X = R32(self + 0x44);
    {
      u32 s = ((ThisFn2)R32(R32(X) + 0x1d8))(X, (u32)strobj, 0);
      reg.state = 1;
      h = ext_4cc1d0_thiscall1b(s);
      ((CdeclFn3b)R32(R32(o) + 0x2c))(o, 0x692474, h);
      ext_4cbec0_thiscall1((u32)strobj);
    }
    goto L39d8;
  }
  if (id == (R32(self + 0x64) & 0xffff)) { W32(self + 0x80, val); goto L39d8; }
  {
    u32 line;
    if (id == (R32(self + 0x60) & 0xffff)) line = 0x84b;
    else if (id == (R32(self + 0x62) & 0xffff)) line = 0x851;
    else {
      if (id == (R32(self + 0x50) & 0xffff) && R8(self + 0x9e) != 0) ext_4b3270_thiscall1(self);
      goto L39d8;
    }
    L = R32(0x700390);
    o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x691edc, line);
    ((CdeclFn2b)R32(R32(o) + 0x2c))(o, 0x691f24);
  }
L39d8:
  seh_set_head(reg.next);
  return 0;
}
PCREG(4b34d0, port_4b34d0);

// ---------------------------------------------------------------------------------------------------------------
// 0x4b3a70: thiscall(this), SEH (handler 0x668afb), void: the release / teardown counterpart of 0x4b34d0 (hand port).
extern "C" u32 THISCALL ext_4da2f0_thiscall3(u32, u32, u32) __asm__("ext_4da2f0");

extern "C" void THISCALL port_4b3a70(u32 self) {
  volatile SehRecord reg; reg.next = seh_head(); reg.handler = (0x668afb); reg.state = -1; seh_set_head(&reg);
  u32 G, tab, C, v, X, N, K, esi, edi, J;
  u32 strobj[8];
  u32 st;
  if (R32(self + 0x84) == 0) goto Lexit;
  if (R8(self + 0x9f) == 0) {
    static const u32 names[4] = {0x6914e0, 0x6914f0, 0x691504, 0x69152c};
    for (int i = 0; i < 4; i++) {
      G = R32(0x70039c); J = R32(G + 0x1907);
      ((ThisFn2)R32(R32(J) + 0x90))(J, names[i], 0);
    }
  }
  G = R32(0x70039c); tab = R32(G + 0x9b);
  C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
  v = 0;
  ((ThisFn2)R32(R32(C) + 0x88))(C, 0x685a0c, (u32)&v);
  esi = v;
  if (R8(self + 0x98) != 0 && esi != 0) {
    G = R32(0x70039c); K = R32(G + 0x190f);
    if (R32(K + 0xfd) != 0) {
      W32(K + 0xfd, R32(K + 0xfd) - 1);
      G = R32(0x70039c); K = R32(G + 0x190f);
      *(u8 *)(K + 0x101) = 0;
      G = R32(0x70039c);
    }
    tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    v = 0;
    ((ThisFn2)R32(R32(C) + 0x88))(C, 0x6922f8, (u32)&v);
    X = R32(self + 0x44);
    ((ThisFn3)R32(R32(X) + 0x12c))(X, v, R32(self + 0x66) & 0xffff, 1);
    X = R32(self + 0x44);
    ((ThisFn3)R32(R32(X) + 0x12c))(X, esi, R32(self + 0x72) & 0xffff, R32(self + 0x84));
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    v = 0;
    ((ThisFn2)R32(R32(C) + 0x88))(C, 0x68be98, (u32)&v);
    if (v != 0) {
      G = R32(0x70039c); tab = R32(G + 0x9b);
      X = R32(self + 0x44);
      u32 vt = R32(X);
      u32 h = ((ThisFn4c)R32(R32(tab) + 0x114))(tab, 0x6923d8, 0, 0x691edc, 0x5aa);
      ((ThisFn3)R32(vt + 0x12c))(X, v, h & 0xffff, 0);
    }
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    v = 0;
    ((ThisFn2)R32(R32(C) + 0x88))(C, 0x681320, (u32)&v);
    G = R32(0x70039c); tab = R32(G + 0x9b);
    N = ((ThisFn1)R32(R32(tab) + 0x58))(tab, v);
    if (N != 0) {
      ((ThisFn0)R32(R32(N) + 0x36c))(N);
      G = R32(0x70039c); tab = R32(G + 0x9b);
      u32 N2 = ((ThisFn1)R32(R32(tab) + 0x58))(tab, R32(self + 0x78));
      if (N2 != 0) ((ThisFn1)R32(R32(N2) + 0xbc))(N2, 0);
      G = R32(0x70039c); tab = R32(G + 0x9b);
      u32 N3 = ((ThisFn1)R32(R32(tab) + 0x58))(tab, R32(self + 0x7c));
      if (N3 != 0) ((ThisFn1)R32(R32(N3) + 0xbc))(N3, 0);
    }
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    v = 0;
    ((ThisFn2)R32(R32(C) + 0x88))(C, 0x692314, (u32)&v);
    esi = v - 1;
    G = R32(0x70039c); tab = R32(G + 0x9b);
    C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
    ((ThisFn3)R32(R32(C) + 0x5c))(C, 0x692314, esi, 2);
  } else {
    G = R32(0x70039c); tab = R32(G + 0x9b);
    N = ((ThisFn1)R32(R32(tab) + 0x58))(tab, R32(self + 0x84));
    if (N != 0) {
      u32 fh = R32(N + 0xc);
      if ((R32(fh + 0x23) & 0x400000) != 0) {
        G = R32(0x70039c); K = R32(G + 0x190f);
        ((ThisFn1)R32(R32(K) + 0xb8))(K, N);
      }
    }
    if (R8(self + 0x98) != 0) {
      G = R32(0x70039c); K = R32(G + 0x190f);
      W32(K + 0xfd, R32(K + 0xfd) - 1);
      G = R32(0x70039c); K = R32(G + 0x190f);
      *(u8 *)(K + 0x101) = 0;
      G = R32(0x70039c); K = R32(G + 0x190f);
      esi = ((ThisFn0)R32(R32(K) + 0x98))(K);
      if (esi != 0) {
        ((ThisFn1)R32(R32(esi) + 0x4c))(esi, (u32)&st);
        u32 el = ((ThisFn1)R32(R32(esi) + 0x5c))(esi, (u32)&st);
        if (st != 0) {
          do {
            G = R32(0x70039c); tab = R32(G + 0x9b);
            ((ThisFn1)R32(R32(tab) + 0x58))(tab, el);
            el = ((ThisFn1)R32(R32(esi) + 0x5c))(esi, (u32)&st);
          } while (st != 0);
        }
      }
    }
  }
  G = R32(0x70039c); tab = R32(G + 0x9b);
  esi = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
  {
    u32 C2 = esi;
    u32 cnt = ((ThisFn1)R32(R32(C2) + 0xa8))(C2, 0x6923e4) >> 2;
    if (cnt != 0) {
      u32 *buf = (u32 *)__builtin_alloca(cnt * 4);
      ((ThisFn2)R32(R32(C2) + 0x88))(C2, 0x6923e4, (u32)buf);
      G = R32(0x70039c); tab = R32(G + 0x9b);
      u32 id = ((ThisFn1)R32(R32(tab) + 0x4c))(tab, R32(self + 0x44));
      u32 m = 0;
      for (u32 i = 0; i < cnt; i++) {
        u32 x = buf[i];
        if (x != id) buf[m++] = x;
      }
      if (m != 0) ((ThisFn3)R32(R32(C2) + 0x28))(C2, 0x6923e4, (u32)buf, m);
      else ((ThisFn2)R32(R32(C2) + 0xa0))(C2, 0x6923e4, 0);
    }
  }
  G = R32(0x70039c); tab = R32(G + 0x9b);
  C = ((ThisFn0)R32(R32(tab) + 0x138))(tab);
  v = 0;
  ((ThisFn2)R32(R32(C) + 0x88))(C, 0x692048, (u32)&v);
  edi = v;
  if (((ThisFn0)R32(R32(edi) + 0x14))(edi) != 0) {
    u32 Eo = ((ThisFn1)R32(R32(edi) + 0x34))(edi, 0);
    u32 b = R32(Eo + 4);
    u32 e0 = R32(Eo);
    u32 a = R32(Eo + 8) & 0xffff;
    ((ThisFn1)R32(R32(edi) + 0x3c))(edi, e0);
    G = R32(0x70039c); tab = R32(G + 0x9b);
    u32 T = ((ThisFn1)R32(R32(tab) + 0x54))(tab, e0);
    if (T != 0) {
      u32 L = R32(0x700390);
      u32 o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x691edc, 0x5f0);
      u32 s = ext_4da2f0_thiscall3(T, (u32)strobj, 0);
      reg.state = 0;
      u32 h = ext_4cc1d0_thiscall1b(s);
      ((CdeclFn3b)R32(R32(o) + 0x2c))(o, 0x6923f8, h);
      reg.state = -1;
      ext_4cbec0_thiscall1((u32)strobj);
      u32 Tn = R32(T + 0x54);
      if (Tn != 0) ((ThisFn3)R32(R32(Tn) + 0x128))(Tn, a, b, 0);
    }
  }
  W32(self + 0x84, 0);
Lexit:
  seh_set_head(reg.next);
}
PCREG(4b3a70, port_4b3a70);
