// batch242011.cpp - Sonnet-w4b, hand ports of two small tier-3 rows the lifter rejects (push/pop-only prologues, cdq/idiv, tail jump).
#include "ff.h"

#define R32(a) (*(u32 *)(u32)(a))
#define W32(a, v) (*(u32 *)(u32)(a) = (u32)(v))
#define R8(a) (*(u8 *)(u32)(a))

typedef u32 (__attribute__((cdecl)) *CdeclFn3)(u32, u32, u32);
typedef u32 (THISCALL *ThisFn0)(u32);
typedef u32 (THISCALL *ThisFn1)(u32, u32);
typedef u32 (THISCALL *ThisFn2)(u32, u32, u32);
typedef u32 (THISCALL *ThisFn5)(u32, u32, u32, u32, u32, u32);

// 0x5c5910: countdown on this[0x4c] against this[0x50]; when it expires reroll this[0x50] = engine.rand(0x6b42a0, 0x20) % this[0x48],
// log the engine value through the [0x700390] logger and push the string id into this[0x44]
extern "C" u32 THISCALL port_5c5910(u32 self) {
  s32 edx = (s32)R32(self + 0x4c);
  u32 eax = (u32)(edx + 1);
  W32(self + 0x4c, eax);
  if (edx <= (s32)R32(self + 0x50)) return eax;
  W32(self + 0x4c, 0);
  u32 G = R32(0x70039c);
  s32 v = (s32)((ThisFn2)R32(R32(G) + 0x1bc))(G, 0x6b42a0, 0x20);
  W32(self + 0x50, (u32)(v % (s32)R32(self + 0x48)));
  u32 L = R32(0x700390);
  u32 o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x6b42a0, 0x21);
  G = R32(0x70039c);
  u32 vtG = R32(G);
  u32 vo = R32(o);
  u32 w = ((ThisFn2)R32(vtG + 0x1bc))(G, 0x6b42a0, 0x21);
  ((CdeclFn3)R32(vo + 0x2c))(o, 0x6b42d4, w);
  u32 P = R32(self + 0x44);
  u32 vp = R32(P);
  u32 T = R32(R32(0x70039c) + 0x9b);
  u32 h = ((ThisFn5)R32(R32(T) + 0x114))(T, 0x6b4280, 0, 0x6b42a0, 0x23, 0);
  return ((ThisFn2)R32(vp + 0x130))(P, P, h & 0xffff);
}
PCREG(5c5910, port_5c5910);

// 0x46e2d0: pick the clamp for this[0xc4] from state this[0xd5] (jump table 0..3 -> 1, 1, this[0xba], 3), min with this[0xba], then
// either tail-call this.slot0x160() after slot0x110(0x10, 0) or this.slot0x304(this[0x92]); error log through the [0x700390] logger when slot 0x328 is null
extern "C" u32 THISCALL port_46e2d0(u32 self) {
  u32 r = ((ThisFn0)R32(R32(self) + 0x328))(self);
  if (r == 0) {
    u32 L = R32(0x700390);
    u32 o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x6887c4, 0xb4e);
    u32 s = R32(self + 4);
    if (s == 0) s = 0x67c8e8;
    return ((CdeclFn3)R32(R32(o) + 0x30))(o, 0x688d3c, s);
  }
  u32 st = R32(self + 0xd5);
  if (st <= 3) {
    switch (st) {
      case 0: case 1: W32(self + 0xc4, 1); break;
      case 2: W32(self + 0xc4, R32(self + 0xba)); break;
      case 3: W32(self + 0xc4, 3); break;
    }
  }
  s32 a = (s32)R32(self + 0xc4), b = (s32)R32(self + 0xba);
  s32 m = a < b ? a : b;
  W32(self + 0xc4, (u32)m);
  if (m != 0 && R8(self + 0xbf) != 0) {
    ((ThisFn2)R32(R32(self) + 0x110))(self, 0x10, 0);
    return ((ThisFn0)R32(R32(self) + 0x160))(self);
  }
  return ((ThisFn1)R32(R32(self) + 0x304))(self, R32(self + 0x92));
}
PCREG(46e2d0, port_46e2d0);

extern "C" u32 THISCALL ext_4dbe30_thiscall2(u32, u32) __asm__("ext_4dbe30");
extern "C" u32 THISCALL ext_4dc440_thiscall2(u32, u32) __asm__("ext_4dc440");
typedef u32 (__attribute__((cdecl)) *CdeclFn2)(u32, u32);

// 0x584480: look two named children up on this[0x44] (slot 0x25c); the first one (0x688bd0) is registered through the engine table (slot 0x4c -> this[0x362]),
// attached through the registry object [table+0xadc].slot0x288 and initialised (slot 0x224, 0x4dbe30, 0x4dc440, slot 0x24(0)); the second (0x690aec) only
// gets this[0x35e] = table.slot0x4c(child) and slot 0x24(0); a missing child is reported through the [0x700390] logger (lines 0x2a1 / 0x2ad)
extern "C" u32 THISCALL port_584480(u32 self) {
  u32 P = R32(self + 0x44);
  u32 esi = ((ThisFn2)R32(R32(P) + 0x25c))(P, 0x688bd0, 0);
  u32 eax = 0;
  if (esi == 0) {
    u32 L = R32(0x700390);
    u32 o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x6ab6d4, 0x2a1);
    eax = ((CdeclFn2)R32(R32(o) + 0x2c))(o, 0x6ab75c);
  } else {
    u32 T = R32(R32(0x70039c) + 0x9b);
    W32(self + 0x362, ((ThisFn1)R32(R32(T) + 0x4c))(T, esi));
    u32 Z = R32(R32(R32(0x70039c) + 0x9b) + 0xadc);
    ((u32(THISCALL *)(u32, u32, u32, u32))R32(R32(Z) + 0x288))(Z, esi, 0, 1);
    ((ThisFn1)R32(R32(esi) + 0x224))(esi, 1);
    ext_4dbe30_thiscall2(R32(esi + 8), 1);
    ext_4dc440_thiscall2(R32(esi + 8), 1);
    eax = ((ThisFn1)R32(R32(esi) + 0x24))(esi, 0);
  }
  P = R32(self + 0x44);
  esi = ((ThisFn2)R32(R32(P) + 0x25c))(P, 0x690aec, 0);
  if (esi == 0) {
    u32 L = R32(0x700390);
    u32 o = ((ThisFn2)R32(R32(L) + 0x20))(L, 0x6ab6d4, 0x2ad);
    return ((CdeclFn2)R32(R32(o) + 0x2c))(o, 0x6ab79c);
  }
  u32 T = R32(R32(0x70039c) + 0x9b);
  W32(self + 0x35e, ((ThisFn1)R32(R32(T) + 0x4c))(T, esi));
  return ((ThisFn1)R32(R32(esi) + 0x24))(esi, 0);
}
PCREG(584480, port_584480);

extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" float THISCALL ext_4e5e80_flt(u32) __asm__("ext_4e5e80");
extern "C" double VECTORCALL ext_634db2_dbl2(double, double) __asm__("ext_634db2");
extern "C" void ext_634047_noret(void) __asm__("ext_634047");

static inline float F_at(u32 a) { float f; __builtin_memcpy(&f, (void *)a, 4); return f; }
static inline s32 cvtt(float f) { s32 r; __asm__("cvttss2si %1, %0" : "=r"(r) : "x"(f)); return r; }

// 0x4b5db0: read a record from the stream (thiscall(stream) ret 4, /GS cookie): two ints -> this[0x50], this[0x58]; the engine's name resolver
// (renderer = engine[0x1a9f], slot 0x78(this[0x58]) -> path string) gives this[0x80..] = the path from its second '/' on with the last four characters
// (the extension) cut off; then ints/floats this[0x54], [0x5c], [0x60] (reciprocal of 1/pow(const, x/K) when x <= 0), flags [0x180], [0x181], optional [0x184], and
// this[0x48] = int((v10c + 60 * (v108 + 60 * ebx)) + v110 * K2) * K3)
extern "C" u32 THISCALL port_4b5db0(u32 self, u32 stream) {
  u32 eax = ext_4e5e60_thiscall1(stream);
  W32(self + 0x50, eax);
  eax = ext_4e5e60_thiscall1(stream);
  W32(self + 0x58, eax);
  u32 X = R32(R32(0x70039c) + 0x1a9f);
  if (X) {
    u32 p = ((ThisFn1)R32(R32(X) + 0x78))(X, eax);
    if (p) {
      u32 len = 0;
      while (R8(p + len)) len++;
      u32 i = 0;
      if (len != 0) { do { if (R8(p + i) == 0x2f) break; i++; } while (i < len); }
      i++;
      if (i < len) { do { if (R8(p + i) == 0x2f) break; i++; } while (i < len); }
      u8 buf[0x108];
      u32 q = p + i, n = 0;
      u8 ch;
      do { ch = R8(q + n); buf[n] = ch; n++; } while (ch != 0);
      u32 l2 = 0;
      while (buf[l2]) l2++;
      u32 cut = l2 - 4;
      if (cut >= 0x100) { ext_634047_noret(); }
      buf[cut] = 0;
      u32 k = 0;
      do { ch = buf[k]; *(u8 *)(self + 0x80 + k) = ch; k++; } while (ch != 0);
    }
  }
  R8(self + 0x180) = 1;
  u32 ebx = ext_4e5e60_thiscall1(stream);
  u32 v108 = ext_4e5e60_thiscall1(stream);
  u32 v10c = ext_4e5e60_thiscall1(stream);
  u32 v110 = ext_4e5e60_thiscall1(stream);
  W32(self + 0x54, ext_4e5e60_thiscall1(stream));
  { float f = ext_4e5e80_flt(stream); __builtin_memcpy((void *)(self + 0x5c), &f, 4); }
  { float f = ext_4e5e80_flt(stream); __builtin_memcpy((void *)(self + 0x60), &f, 4); }
  R8(self + 0x180) = ext_4e5e60_thiscall1(stream) != 0;
  R8(self + 0x181) = ext_4e5e60_thiscall1(stream) != 0;
  { u8 t = R8(R32(stream)); if (t != 0xff && (t & 0x3f) == 3) R8(self + 0x184) = ext_4e5e60_thiscall1(stream) != 0; }
  float f60 = F_at(self + 0x60);
  if (!(0.0f < f60)) {
    float e = f60 / F_at(0x67da30);
    double base; __builtin_memcpy(&base, (void *)0x692790, 8);
    float pw = (float)ext_634db2_dbl2(base, (double)e);
    float r = F_at(0x67cd40) / pw;
    __builtin_memcpy((void *)(self + 0x60), &r, 4);
  }
  s32 a = (s32)v108 + 60 * (s32)ebx;
  s32 b = (s32)v10c + 60 * a;
  float x0 = (float)(s32)v110 * F_at(0x686080);
  float x1 = ((float)b + x0) * F_at(0x685270);
  u32 res = (u32)cvtt(x1);
  W32(self + 0x48, res);
  return res;
}
PCREG(4b5db0, port_4b5db0);

extern "C" u32 THISCALL ext_44c230_thiscall2(u32, u32) __asm__("ext_44c230");
typedef float (THISCALL *RandFn)(u32, u32, u32);
static inline double D_at(u32 a) { double d; __builtin_memcpy(&d, (void *)a, 8); return d; }
static inline void F_set(u32 a, float f) { __builtin_memcpy((void *)a, &f, 4); }

// 0x4c2c00: push the parameters of a parsed record (this = record) into its target object C = this[0x44] and C's body A = C[0x18] (flags A[0x40]); thiscall(), SSE + x87
// (the engine random comes back on the x87 stack; the 1 - r*f and r - K steps are done in long double so the control-word precision matches the exe)
extern "C" u32 THISCALL port_4c2c00(u32 self) {
  u32 C = R32(self + 0x44);
  if (C == 0) return 0;
  if (R32(C + 0x1c) == 0) return 0;
  u32 G;
  float f48 = F_at(self + 0x48);
  if (!(0.0f < f48) && f48 == f48) {
    float e = f48 / F_at(0x67da30);
    double p = ext_634db2_dbl2(D_at(0x692790), (double)e);
    double q = D_at(0x693d60) / p;
    F_set(R32(C + 0x18) + 0x88, (float)q);
  }
  u32 ecx = R32(self + 0x4c);
  if (ecx) W32(R32(C + 0x18) + 0x68, ecx);
  ecx = R32(self + 0x50);
  if (ecx) ((ThisFn1)R32(R32(C) + 0x218))(C, ecx);
  float f54 = F_at(self + 0x54);
  if (f54 != 0.0f) { u32 bits; __builtin_memcpy(&bits, &f54, 4); ext_44c230_thiscall2(C, bits); }
  float f60 = F_at(self + 0x60);
  if (f60 != 0.0f) F_set(R32(C + 0x18) + 0x78, f60 * F_at(0x67d9fc));
  if (R32(self + 0x64) != 0) {
    u32 A = R32(C + 0x18);
    W32(A + 0x40, R32(A + 0x40) | 8);
    s32 cnt = (s32)R32(self + 0x64);
    if (cnt >= 2) {
      A = R32(C + 0x18);
      F_set(A + 0x70, (float)cnt * F_at(A + 0x70));
      G = R32(0x70039c);
      u32 T = R32(G + 0x9b);
      u32 al = ((ThisFn0)R32(R32(T) + 0x2c))(T);
      if ((al & 0xff) == 0) ((ThisFn1)R32(R32(self) + 0x64))(self, 0x10);
    } else {
      G = R32(0x70039c);
      u32 T = R32(G + 0x9b);
      u32 al = ((ThisFn0)R32(R32(T) + 0x2c))(T);
      if ((al & 0xff) == 0) ((ThisFn2)R32(R32(self) + 0x68))(self, 0x10, 0);
    }
  }
  if (R8(self + 0x68) != 0) { u32 A = R32(C + 0x18); W32(A + 0x40, R32(A + 0x40) | 0x10); }
  float f69 = F_at(self + 0x69);
  if (f69 != 0.0f) {
    if (f69 > 0.0f) {
      G = R32(0x70039c);
      float r = ((RandFn)R32(R32(G) + 0x1c0))(G, 0x693c40, 0x8ca);
      float v = (float)(1.0L - (long double)r * (long double)f69);
      F_set(R32(C + 0x18) + 0x84, v);
    } else if (0.0f > f69) {
      G = R32(0x70039c);
      float r = ((RandFn)R32(R32(G) + 0x1c0))(G, 0x693c40, 0x8cc);
      float e = F_at(self + 0x69) / F_at(0x67da30);
      double p = ext_634db2_dbl2(D_at(0x692790), (double)e);
      double d2 = D_at(0x678610);
      double res = d2 - (d2 / p) * (double)r;
      F_set(R32(C + 0x18) + 0x84, (float)res);
    }
  }
  if (R32(self + 0x6d) != 0) {
    G = R32(0x70039c);
    u32 vt = R32(C);
    float r = ((RandFn)R32(R32(G) + 0x1c0))(G, 0x693c40, 0x8ce);
    float t = (float)((long double)r - (long double)F_at(0x67a6ac));
    float x = (float)(s32)R32(self + 0x6d) * t;
    u32 n = (u32)cvtt(x) + R32(self + 0x50);
    ((ThisFn1)R32(vt + 0x218))(C, n);
  }
  ecx = R32(self + 0x71);
  if (ecx) { u32 A = R32(C + 0x18); W32(A + 0x40, R32(A + 0x40) | 0x80); W32(A + 0x2c, ecx); }
  if (R32(self + 0x79) == 0) { u32 A = R32(C + 0x18); W32(A + 0x40, R32(A + 0x40) & 0xfffffffd); }
  if (R32(self + 0x7d) == 0) { u32 A = R32(C + 0x18); W32(A + 0x40, R32(A + 0x40) & 0xfffffffb); }
  W32(R32(C + 0x18) + 0xc, R32(self + 0x75));
  return R32(self + 0x75);
}
PCREG(4c2c00, port_4c2c00);

typedef long double ld;

// 0x40d060: real-input FFT butterfly pass (cdecl(N, M, src, dst, tw), no result): src holds M rows of N floats followed by M more rows
// (src + N*M); every output row has 2N floats. Row-wise sum/difference of the first columns, a twiddled butterfly (tw[2k], tw[2k+1])
// over the inner columns, and the even-N tail (dst[N-1] = src[N-1], dst[N] = -src2[N-1]). All float steps go through x87 at the exe's precision (long double).
extern "C" void port_40d060(s32 N, s32 M, float *src, float *dst, float *tw) {
  s32 total = N * M;
  if (M > 0) {
    float *a = src, *b = src + total, *d1 = dst, *d2 = dst + (2 * N - 1);
    for (s32 j = M; j != 0; j--) {
      *d1 = (float)((ld)*a + (ld)*b);
      *d2 = (float)((ld)*a - (ld)*b);
      d1 += 2 * N; a += N; b += N; d2 += 2 * N;
    }
  }
  if (N < 2) return;
  if (N != 2) {
    if (M > 0) {
      float *pp = src, *qq = src + total, *oo1 = dst, *oo2 = dst + 2 * N;
      for (s32 row = M; row != 0; row--) {
        float *p = pp, *q = qq, *o1 = oo1, *o2 = oo2, *t = tw;
        for (u32 cnt = (u32)(N - 1) >> 1; cnt != 0; cnt--) {
          ld w0 = t[0], w1 = t[1];
          ld A = w0 * (ld)q[1] + (ld)q[2] * w1;
          ld B = w0 * (ld)q[2] - w1 * (ld)q[1];
          q += 2; p += 2; o1 += 2; o2 -= 2; t += 2;
          o1[0] = (float)(B + (ld)p[0]);
          o2[0] = (float)(B - (ld)p[0]);
          o1[-1] = (float)(A + (ld)p[-1]);
          o2[-1] = (float)((ld)p[-1] - A);
        }
        pp += N; qq += N; oo1 += 2 * N; oo2 += 2 * N;
      }
    }
    if (N & 1) return;
  }
  if (M > 0) {
    float *a = dst + N, *c = src + (N - 1), *e = src + (total + N - 1);
    for (s32 j = M; j != 0; j--) {
      *a = (float)(-(ld)*e);
      a[-1] = *c;      // bit copy of the float (mov dword)
      e += N; a += 2 * N; c += N;
    }
  }
}
PCREG(40d060, port_40d060);

extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4a21b0_thiscall3(u32, u32, u32) __asm__("ext_4a21b0");
typedef u64 (THISCALL *Fn64_2)(u32, u32, u32);
typedef u32 (THISCALL *ThisFn3)(u32, u32, u32, u32);

// 0x4a1e00: weighted "which of 8 slots wins" step. For k = 0..7: this[0x824 + 4k] += K[0x678858] / float(500 * 2^k + 1); the first slot that is
// strictly greater than the best so far (starting at 0.0) becomes the winner (ties and NaN do not win); the winner's accumulator is reset to 0;
// optional profiler log lines (engine slots 0x1c8 -> 0x178 / 0x17c) around the call of 0x4a21b0(this, winner, &vec) after the table object
// engine[0x9b].slot0x54(this[0]) and 0x4db670 filled the vector
extern "C" u32 THISCALL port_4a1e00(u32 self) {
  float c = F_at(0x678858);
  float best = 0.0f;
  u32 idx = 0;
  for (u32 k = 0; k < 8; k++) {
    float d = (float)(s32)((1u << k) * 0x1f4 + 1);
    float t = c / d;
    t = t + F_at(self + 0x824 + 4 * k);
    bool win = t > best;
    F_set(self + 0x824 + 4 * k, t);
    if (win) { best = t; idx = k; }
  }
  W32(self + 0x824 + 4 * idx, 0);
  u32 G = R32(0x70039c);
  float a = F_at(G + 0x9c7), b = F_at(G + 0x9c3);
  if (!(a == 0.0f) && !(b == 0.0f)) {
    u64 pr = ((Fn64_2)R32(R32(G) + 0x1c8))(G, 0x67a7f8, 0x259);
    u32 G2 = R32(0x70039c);
    ((ThisFn3)R32(R32(G2) + 0x178))(G2, (u32)pr, (u32)(pr >> 32), 0x68f6a8);
    G = R32(0x70039c);
  }
  u32 T = R32(G + 0x9b);
  u32 X = ((ThisFn1)R32(R32(T) + 0x54))(T, R32(self));
  if (X != 0) {
    u32 v[3] = {0, 0, 0};
    W32(0x7002e0, 0x1e);
    ext_4db670_thiscall2(X, (u32)v);
    ext_4a21b0_thiscall3(self, idx, (u32)v);
    G = R32(0x70039c);
    a = F_at(G + 0x9c7); b = F_at(G + 0x9c3);
    if (!(a == 0.0f) && !(b == 0.0f)) {
      u64 pr = ((Fn64_2)R32(R32(G) + 0x1c8))(G, 0x67a7f8, 0x260);
      u32 G3 = R32(0x70039c);
      ((ThisFn3)R32(R32(G3) + 0x17c))(G3, (u32)pr, (u32)(pr >> 32), 0x68f6a8);
    }
  }
  return 0;
}
PCREG(4a1e00, port_4a1e00);
