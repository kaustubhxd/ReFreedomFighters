// batch242020.cpp - Sonnet-w4b, hand port of 0x4b73f0 (the lifter mis-tracks the pushes that straddle the call to 0x4dc130).
#include "ff.h"

#define R32(a) (*(u32 *)(u32)(a))
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
