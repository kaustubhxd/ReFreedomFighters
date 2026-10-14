// batch35189.cpp - cascade s5 batch 35189 (tier H): 0x5a5f70 (GUESS per-frame timer update of a character: fade timers, animation blend and pulse).
#include "ff.h"

extern "C" void THISCALL ext_5ec2b0(u8 *self, float v, s32 m);   // ret 8
extern "C" void THISCALL ext_5eebf0(u8 *self);                    // plain ret
extern "C" void THISCALL ext_5efcc0(u8 *self);                    // plain ret
extern "C" void THISCALL ext_5eff00(u8 *self);                    // plain ret
extern "C" void THISCALL ext_5ac5b0(u8 *self, float v);           // ret 4
extern "C" void THISCALL ext_5acac0(u8 *self, u32 z);             // ret 4
extern "C" s32 VECTORCALL ext_633910(float f);                    // CRT float-to-int helper
extern "C" double VECTORCALL ext_634d70(double);                  // CRT routine (cos), argument/result in XMM0

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { return bitsf(rd32u(p)); }
static inline void wrf(u8 *p, float f) { wr32u(p, fbits(f)); }
static inline float dtime() { return *(float *)(G(u8 *, 0x70039c) + 0x48); }

// 0x5a5f70, thiscall, no args, no return value. dt = float [engine+0x48]. (1) [this+0x300] != 0x10000000: float [+0x8bb] = dt + [+0x8bb]. (2) O1 = [+0x689] (non-null): when float [+0x68d] f > 0: f -= dt, stored, zeroed when negative, then 0x5ec2b0(O1, [+0x68d], -1); else O1[0x35] = 0.
// (3) byte [+0x658] == 0: 0x5eebf0([+0x638]). (4) 0x5efcc0([+0x64c]); 0x5eff00([+0x634]). (5) when KA (0x67c198) > float [+0x2fc]: x = dt + [+0x8d4] stored; O2[0x35] = (KB (0x67c194) > x), x > KA resets [+0x8d4] = 0; else O2[0x35] = 1 (O2 = [+0x434]).
// (6) byte [+0x3c7]: x = dt + [+0x3c8] stored; x > KA clears both [+0x3c8] and the byte; else m = ftoi(x * KC (0x67d164)) % 100 (unsigned); [+0x3c2] = m < 50 ? dword [+0x3cc] : 9.
// (7) float [+0x3d0] != 0: -= dt, stored; when negative it is zeroed and [+0x3c2] = 8. (8) g = float [+0x374] != 0: stored g - dt; when g was exactly 1.0 (0x678858): [+0x378] += ftoi(dt * KC); r = [+0x378] % 1000;
// angle = (float)r * [0x68aef8] / KC; v = (float)((cos(angle) + [0x678610]) * [0x6b01c8] + [0x68c740]); 0x5ac5b0([+0x630], v); otherwise when g - dt is negative: 0x5acac0([+0x630], 0), [+0x374] = 0, [+0x650] = 0; else 0x5ac5b0([+0x630], g - dt).
static void THISCALL fn5a5f70(u8 *self) {
  if (rd32u(self + 0x300) != 0x10000000) wrf(self + 0x8bb, dtime() + rdf(self + 0x8bb));
  u8 *O1 = (u8 *)rd32u(self + 0x689);
  if (O1) {
    float f = rdf(self + 0x68d);
    if (f > 0.0f) {
      f = f - dtime();
      wrf(self + 0x68d, f);
      if (0.0f > f) wr32u(self + 0x68d, 0);
      ext_5ec2b0(O1, rdf(self + 0x68d), -1);
    } else {
      O1[0x35] = 0;
    }
  }
  if (self[0x658] == 0) ext_5eebf0((u8 *)rd32u(self + 0x638));
  ext_5efcc0((u8 *)rd32u(self + 0x64c));
  ext_5eff00((u8 *)rd32u(self + 0x634));
  float KA = G(float, 0x67c198);
  if (KA > rdf(self + 0x2fc)) {
    float KB = G(float, 0x67c194);
    float x = dtime() + rdf(self + 0x8d4);
    u8 *O2 = (u8 *)rd32u(self + 0x434);
    wrf(self + 0x8d4, x);
    O2[0x35] = (KB > x) ? 1 : 0;
    if (rdf(self + 0x8d4) > KA) wr32u(self + 0x8d4, 0);
  } else {
    u8 *O2 = (u8 *)rd32u(self + 0x434);
    O2[0x35] = 1;
  }
  float KC = G(float, 0x67d164);
  if (self[0x3c7]) {
    float x = dtime() + rdf(self + 0x3c8);
    wrf(self + 0x3c8, x);
    if (x > KA) {
      wr32u(self + 0x3c8, 0);
      self[0x3c7] = 0;
    } else {
      u32 m = (u32)ext_633910(x * KC) % 100;
      wr32u(self + 0x3c2, m < 50 ? rd32u(self + 0x3cc) : 9);
    }
  }
  float h = rdf(self + 0x3d0);
  if (h != 0.0f) {
    h = h - dtime();
    wrf(self + 0x3d0, h);
    if (0.0f > h) {
      wr32u(self + 0x3d0, 0);
      wr32u(self + 0x3c2, 8);
    }
  }
  float g = rdf(self + 0x374);
  if (g != 0.0f) {
    bool one = (g == G(float, 0x678858));
    float g2 = g - dtime();
    wrf(self + 0x374, g2);
    if (one) {
      wr32u(self + 0x378, rd32u(self + 0x378) + (u32)ext_633910(dtime() * KC));
      u32 r = rd32u(self + 0x378) % 1000;
      float ang = (float)((double)(int)r + G(double, 0x680aa0));
      ang = ang * G(float, 0x68aef8);
      ang = ang / G(float, 0x67d164);
      double cs = ext_634d70((double)ang);
      cs = cs + G(double, 0x678610);
      cs = cs * G(double, 0x6b01c8);
      cs = cs + G(double, 0x68c740);
      ext_5ac5b0((u8 *)rd32u(self + 0x630), (float)cs);
    } else if (0.0f > g2) {
      u8 *o = (u8 *)rd32u(self + 0x630);
      wr32u(self + 0x374, 0);
      ext_5acac0(o, 0);
      wr32u(self + 0x650, 0);
    } else {
      ext_5ac5b0((u8 *)rd32u(self + 0x630), g2);
    }
  }
}
PCREG(5a5f70, fn5a5f70);
