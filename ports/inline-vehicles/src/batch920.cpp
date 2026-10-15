// batch920.cpp - vehicles thread, batch 920: tank undercarriage ground probing and damper resets.
#include "ff.h"

extern "C" float THISCALL ext_516130(void *damper, float y, const void *box);  // CDamper ground probe (903)
extern "C" void THISCALL ext_5243f0(void *pull, float v);                      // pull set value (903)
extern "C" void THISCALL ext_5243d0(void *pull, float v);                      // pull set +0xc (ground) (903)
extern "C" void THISCALL ext_524980(void *dist, void *a, void *b);             // distance tracker init (903)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                 // vmmul
extern "C" void FASTCALL ext_441940(float *a, const float *b);                 // PSVECAdd

#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x5244d0 (CPullToValueAccel, unnamed: set ground): ground +0xc = g unless g is exactly -1e38 (0x67cd48, "none").
// The second argument is not used.
static void THISCALL pullSetGround(u8 *p, float g, float unused) {
  if (g != bitsf(0xfe967699))
    F(p, 0xc) = g;
}
PCREG(5244d0, pullSetGround);

// 0x5165d0 (CDamper, unnamed: update the ground under the wheel), (a, probe, y, box), pops 16: probe -> ground from
// the probe at height y, else "none" (-1e38); handed to the lower point.
static void THISCALL damperUpdateGround(u8 *d, float a, u32 probe, float y, const void *box) {
  float g = bitsf(0xfe967699);
  if ((u8)probe) {
    volatile float t = ext_516130(d, y, box);
    g = t;
  }
  pullSetGround(d + 0x41, g, a);
}
PCREG(5165d0, damperUpdateGround);

// 0x5162e0 (CDamper, unnamed: reset at a position): position = p; lower point at p.y - travel (+0x35) with the
// ground probed at p.y; damper height p.y; spring tracker re-linked.
static void THISCALL damperResetAt(u8 *d, const u32 *p) {
  ((u32 *)d)[0] = p[0];
  ((u32 *)d)[1] = p[1];
  ((u32 *)d)[2] = p[2];
  ext_5243f0(d + 0x41, _mm_cvtss_f32(_mm_sub_ss(_mm_load_ss((float *)(d + 4)), _mm_load_ss((float *)(d + 0x35)))));
  volatile float g = ext_516130(d, F(d, 4), 0);
  ext_5243d0(d + 0x41, g);
  ext_5243f0(d + 0x55, F(d, 4));
  ext_524980(d + 0x21, d + 0x41, d + 0x55);
}
PCREG(5162e0, damperResetAt);

// 0x529130 (CUnderCarriageTank, unnamed: ground probing): one damper per wheel row probes the ground each frame,
// round robin (+0x40 / +0x44 = next index modulo the row counts; a row count of 0 divides by zero as in the exe);
// all dampers get the probe result or keep their ground (value +0x68, height +0x64).
static void THISCALL ucTankProbeGround(u8 *s) {
  s32 n1 = *(s32 *)(s + 0x8d);
  *(s32 *)(s + 0x40) = (*(s32 *)(s + 0x40) + 1) % n1;
  *(s32 *)(s + 0x44) = (*(s32 *)(s + 0x44) + 1) % *(s32 *)(s + 0x91);
  for (s32 i = 0; i < *(s32 *)(s + 0x8d); i++)
    damperUpdateGround(s + 0x95 + i * 0xde, F(s, 0x68), *(s32 *)(s + 0x40) == i, F(s, 0x64), 0);
  for (s32 i = 0; i < *(s32 *)(s + 0x91); i++)
    damperUpdateGround(s + 0x785 + i * 0xde, F(s, 0x68), *(s32 *)(s + 0x44) == i, F(s, 0x64), 0);
}
PCREG(529130, ucTankProbeGround);

// 0x5279f0 (CUnderCarriageTank, unnamed: the tank's CorrectReversedDampers): a damper whose upper point fell below
// its lower point is reset at its wheel anchor in world space (anchor * body matrix + body position).
static void THISCALL ucTankCorrectReversed(u8 *s) {
  static const u32 row[2][4] = {{0x8d, 0x95, 0xe91, 0}, {0x91, 0x785, 0x1829, 0}};
  for (int r = 0; r < 2; r++) {
    for (s32 i = 0; i < *(s32 *)(s + row[r][0]); i++) {
      u8 *d = s + row[r][1] + i * 0xde;
      if (0.0f > _mm_cvtss_f32(_mm_sub_ss(_mm_load_ss((float *)(d + 0x55)), _mm_load_ss((float *)(d + 0x41))))) {
        float p[3];
        u8 *a = s + row[r][2] + i * 0x133;
        p[0] = F(a, 0);
        p[1] = F(a, 4);
        p[2] = F(a, 8);
        ext_4419f0(p, (float *)(s + 0xc));
        ext_441940(p, (float *)s);
        damperResetAt(d, (u32 *)p);
      }
    }
  }
}
PCREG(5279f0, ucTankCorrectReversed);
