// batch921.cpp - vehicles thread, batch 921: tank undercarriage per-frame pieces: weight transfer, damper anchors,
// track speeds and wheel spin (CWheel::Revolve), track texture scroll.
#include "ff.h"

extern "C" void FASTCALL ext_4ddcb0(float *m, const float *axis, float a);  // LoadRotationAxisAngle
extern "C" void FASTCALL ext_4de420(float *d, const float *s);              // mcpy
extern "C" void FASTCALL ext_4de480(float *mat, const float *m2);           // mat = mat * m2
extern "C" void THISCALL ext_4dcb90(void *geom, const float *m);            // ZBaseGeom::SetMatSimple
extern "C" void THISCALL ext_5168b0(void *em);                              // ParticleEmitter::FrameUpdate

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float ssub(float a, float b) { asm("subss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float sdiv(float a, float b) { asm("divss %1, %0" : "+x"(a) : "x"(b)); return a; }
// (float)(|(double)v| / (double)d), as cvtps2pd + andps + divsd + cvtpd2ps.
static inline float absdiv(float v, float d) {
  __m128d x = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(v)), _mm_load_pd((const double *)ABS64));
  return _mm_cvtss_f32(_mm_cvtpd_ps(_mm_div_sd(x, _mm_cvtps_pd(_mm_set_ss(d)))));
}
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x529450 (CUnderCarriageTank, unnamed: weight transfer): damper mass (+0xc) = 1 + |acceleration +0x6c| /
// +0x21ad on the row it pitches toward (row 1 when acc * drive sign +0x78 < 0, row 2 when > 0), and the turn
// (+0x74, / +0x21b1, clamped to [0, 3]) adds to one damper of every pair (the second when turn * sign > 0).
static void THISCALL ucTankWeight(u8 *s) {
  float v = F(s, 0x6c);
  float t = smul(v, F(s, 0x78));
  float a1 = 0, a2 = 0;
  if (0.0f > t)
    a1 = absdiv(v, F(s, 0x21ad));
  if (t > 0.0f)
    a2 = absdiv(v, F(s, 0x21ad));
  float m1 = sadd(a1, 1.0f), m2 = sadd(a2, 1.0f);
  for (s32 i = 0; i < *(s32 *)(s + 0x8d); i++)
    F(s, 0xa1 + i * 0xde) = m1;
  for (s32 i = 0; i < *(s32 *)(s + 0x91); i++)
    F(s, 0x791 + i * 0xde) = m2;
  float w = F(s, 0x74);
  s32 side = 0.0f >= smul(w, F(s, 0x78)) ? 1 : 0;
  float x = absdiv(w, F(s, 0x21b1));
  float x2 = 0.0f > x ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(3.0f), _mm_set_ss(x)));
  for (s32 i = 0; i < *(s32 *)(s + 0x8d); i += 2)
    F(s, 0xa1 + side * 0xde + (i / 2) * 0x1bc) = sadd(F(s, 0xa1 + side * 0xde + (i / 2) * 0x1bc), x2);
  for (s32 i = 0; i < *(s32 *)(s + 0x91); i += 2)
    F(s, 0x791 + side * 0xde + (i / 2) * 0x1bc) = sadd(F(s, 0x791 + side * 0xde + (i / 2) * 0x1bc), x2);
}
PCREG(529450, ucTankWeight);

// 0x516620 (CDamper, unnamed): x and z of the damper position from p (y kept).
static void THISCALL damperSetXZ(u8 *d, const u32 *p) {
  ((u32 *)d)[0] = p[0];
  ((u32 *)d)[2] = p[2];
}
PCREG(516620, damperSetXZ);

// 0x529020 (CUnderCarriageTank, unnamed): every damper's x/z follow its wheel anchor in world space (group +0x89
// GetRootPoint).
static void THISCALL ucTankDampersFollow(u8 *s) {
  static const u32 row[2][3] = {{0x8d, 0x95, 0xe91}, {0x91, 0x785, 0x1829}};
  for (int r = 0; r < 2; r++)
    for (s32 i = 0; i < *(s32 *)(s + row[r][0]); i++) {
      float p[3];
      u8 *a = s + row[r][2] + i * 0x133;
      p[0] = F(a, 0);
      p[1] = F(a, 4);
      p[2] = F(a, 8);
      vcall<void>(*(void **)(s + 0x89), 0x84, p);
      damperSetXZ(s + row[r][1] + i * 0xde, (u32 *)p);
    }
}
PCREG(529020, ucTankDampersFollow);

// 0x529e30 CWheel::Revolve(float trackSpeed, float speed), pops 8: spin angle = frame time * trackSpeed / radius
// (+0x14). State +0x10: 2 (no spin) when speed <= +0x2d; 1 when speed >= +0x29 and slipping is allowed (+0x28),
// angle * (speed / +0x29 + 1); else 0. The wheel geom ([+0x18]+8) matrix turns by the angle about x; the wheel's two
// particle emitters update (+0x3d only when effects are on, global 0x7003b8 byte +0xab8 clear).
static void THISCALL wheelRevolve(u8 *w, float tspd, float spd) {
  float ax[3];
  ax[0] = 1.0f;
  ax[1] = 0;
  ax[2] = 0;
  float a = sdiv(smul(F(*(u8 **)0x70039c, 0x48), tspd), F(w, 0x14));
  if (F(w, 0x2d) >= spd) {
    a = 0;
    *(u32 *)(w + 0x10) = 2;
  } else if (spd >= F(w, 0x29) && w[0x28]) {
    *(u32 *)(w + 0x10) = 1;
    a = smul(sadd(sdiv(spd, F(w, 0x29)), 1.0f), a);
  } else {
    *(u32 *)(w + 0x10) = 0;
  }
  float M[9], R[9];
  u8 *g = *(u8 **)(*(u8 **)(w + 0x18) + 8);
  ext_4de420(M, (float *)g);
  ext_4ddcb0(R, ax, a);
  ext_4de480(M, R);
  ext_4dcb90(*(void **)(*(u8 **)(w + 0x18) + 8), M);
  if (!(*(u8 **)0x7003b8)[0xab8])
    ext_5168b0(w + 0x3d);
  ext_5168b0(w + 0xb6);
}
PCREG(529e30, wheelRevolve);

// 0x528b60 (CUnderCarriageTank, unnamed: track speeds): left/right track speed +0x7c/+0x80 = sign * speed
// (+0x78 * +0x68) +- turn rate * track width / 2 (+0x74 * +0x21b9 * 0.5); each wheel pair spins its left wheel with
// +0x7c and its right wheel with +0x80 (Revolve, vehicle speed +0x6c).
static void THISCALL ucTankTracks(u8 *s) {
  float h = smul(smul(F(s, 0x21b9), F(s, 0x74)), 0.5f);
  float b = smul(F(s, 0x78), F(s, 0x68));
  F(s, 0x7c) = sadd(b, h);
  F(s, 0x80) = ssub(b, h);
  static const u32 row[2][2] = {{0x8d, 0xe75}, {0x91, 0x180d}};
  for (int r = 0; r < 2; r++)
    for (s32 i = 0; i < *(s32 *)(s + row[r][0]); i += 2) {
      u8 *w = s + row[r][1] + (i / 2) * 0x266;
      wheelRevolve(w, F(s, 0x7c), F(s, 0x6c));
      wheelRevolve(w + 0x133, F(s, 0x80), F(s, 0x6c));
    }
}
PCREG(528b60, ucTankTracks);

// 0x528f50 (CUnderCarriageTank, unnamed: track texture offset), (geom, v), pops 8: for texture layers 0 and 1 of
// the geom's mesh (render manager engine +0x1aa3: its +0x18 slot 0x60(mesh +0x6c of group +8, layer), slot
// 0xe4(.., "*"), then the manager's slot 0x80) the UV parameter +0x10 = v; stops at the first missing layer.
static void THISCALL ucTrackUV(u8 *s, u8 *g, float v) {
  for (u32 layer = 0; layer < 2; layer++) {
    u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x1aa3);
    u32 m = vcall<u32>(*(void **)(rm + 0x18), 0x60, *(u32 *)(*(u8 **)(g + 8) + 0x6c), layer);
    u32 t = vcall<u32>(*(void **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x18), 0xe4, m, 0x678d04);
    u8 *u = vcall<u8 *>(*(void **)(*(u8 **)0x70039c + 0x1aa3), 0x80, t);
    if (!u)
      return;
    F(u, 0x10) = v;
  }
}
PCREG(528f50, ucTrackUV);

// 0x528ae0 (CUnderCarriageTank, unnamed: track texture scroll): the track UV offsets +0x22c4 / +0x22c8 advance by
// track speed / 13000 and go (negated) to the right (+0x21a9) and left (+0x21a5) track geoms.
static void THISCALL ucTankTrackScroll(u8 *s) {
  float r = sadd(sdiv(F(s, 0x80), 13000.0f), F(s, 0x22c4));
  float l = sadd(sdiv(F(s, 0x7c), 13000.0f), F(s, 0x22c8));
  F(s, 0x22c4) = r;
  F(s, 0x22c8) = l;
  ucTrackUV(s, *(u8 **)(s + 0x21a9), bitsf(fbits(r) ^ 0x80000000));
  ucTrackUV(s, *(u8 **)(s + 0x21a5), bitsf(fbits(F(s, 0x22c8)) ^ 0x80000000));
}
PCREG(528ae0, ucTankTrackScroll);
