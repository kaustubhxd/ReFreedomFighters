// batch928.cpp - vehicles thread, batch 928: CUnderCarriageCar per-frame sub-steps (ground probe, weight
// transfer, anchors, reversed dampers, wheels and steering, dust, exhaust).
#include "ff.h"

extern "C" void THISCALL ext_5165d0(void *d, float a, u32 probe, float y, const void *box);  // damper ground (920)
extern "C" void THISCALL ext_516620(void *d, const float *p);                               // damper set x/z (921)
extern "C" void THISCALL ext_5162e0(void *d, const float *p);                               // damper reset at (920)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                             // vmmul
extern "C" void FASTCALL ext_441940(float *a, const float *b);                             // PSVECAdd
extern "C" void THISCALL ext_529e30(void *w, float tspd, float spd);                       // CWheel::Revolve (921)
extern "C" void FASTCALL ext_4ddcb0(float *m, const float *axis, float a);                 // LoadRotationAxisAngle
extern "C" void THISCALL ext_4dcb90(void *geom, const float *m);                           // ZBaseGeom::SetMatSimple
extern "C" u32 THISCALL ext_516250(void *d);                                               // damper ground dust (922)
extern "C" void THISCALL ext_52a070(void *w, void *def);                                   // CWheel set dust (922)
extern "C" void THISCALL ext_516f40(void *em, const float *d);                             // SetEmitDir (908)
extern "C" void THISCALL ext_5168b0(void *em);                                             // ParticleEmitter::FrameUpdate

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float ssub(float a, float b) { asm("subss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float sdiv(float a, float b) { asm("divss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float absd(float v) {
  return _mm_cvtss_f32(_mm_cvtpd_ps(_mm_and_pd(_mm_cvtps_pd(_mm_set_ss(v)), _mm_load_pd((const double *)ABS64))));
}
static inline float absdiv(float v, float d) {
  __m128d x = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(v)), _mm_load_pd((const double *)ABS64));
  return _mm_cvtss_f32(_mm_cvtpd_ps(_mm_div_sd(x, _mm_cvtps_pd(_mm_set_ss(d)))));
}
static inline float mn(float a, float b) { return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a), _mm_set_ss(b))); }
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x526470 (CUnderCarriageCar, unnamed: ground probe): as the tank's (round robin per axle), probing from 200 above
// the body height reference +0x64.
static void THISCALL ucCarProbeGround(u8 *s) {
  s32 n1 = *(s32 *)(s + 0x8c);
  *(s32 *)(s + 0x40) = (*(s32 *)(s + 0x40) + 1) % n1;
  *(s32 *)(s + 0x44) = (*(s32 *)(s + 0x44) + 1) % *(s32 *)(s + 0x90);
  float y = sadd(F(s, 0x64), 200.0f);
  for (s32 i = 0; i < *(s32 *)(s + 0x8c); i++)
    ext_5165d0(s + 0xbd + i * 0xde, F(s, 0x68), *(s32 *)(s + 0x40) == i, y, 0);
  for (s32 i = 0; i < *(s32 *)(s + 0x90); i++)
    ext_5165d0(s + 0x435 + i * 0xde, F(s, 0x68), *(s32 *)(s + 0x44) == i, y, 0);
}
PCREG(526470, ucCarProbeGround);

// 0x526ac0 (CUnderCarriageCar, unnamed: weight transfer): while moving (speed +0x68 > 2^-13) damper mass = 1 +
// min(20, |acceleration +0x6c| / +0x94) on the axle it pitches toward (front when acc * sign +0x7c < 0, rear when
// > 0); the turn (|+0x74| / +0x98, clamped to [0, 3]) adds to one wheel of every pair.
static void THISCALL ucCarWeight(u8 *s) {
  float a1 = 0, a2 = 0;
  if (F(s, 0x68) > 0.0001220703125f) {
    float v = F(s, 0x6c);
    float t = smul(F(s, 0x7c), v);
    if (0.0f > t)
      a1 = absdiv(v, F(s, 0x94));
    else if (t > 0.0f)
      a2 = absdiv(v, F(s, 0x94));
  }
  float r = mn(20.0f, a2), f = mn(20.0f, a1);
  if (*(s32 *)(s + 0x8c) > 0) {
    float m = sadd(f, 1.0f);
    for (s32 i = 0; i < *(s32 *)(s + 0x8c); i++)
      F(s, 0xc9 + i * 0xde) = m;
  }
  if (*(s32 *)(s + 0x90) > 0) {
    float m = sadd(r, 1.0f);
    for (s32 i = 0; i < *(s32 *)(s + 0x90); i++)
      F(s, 0x441 + i * 0xde) = m;
  }
  float w = F(s, 0x74);
  s32 side = 0.0f >= smul(w, F(s, 0x7c)) ? 1 : 0;
  float x = absdiv(w, F(s, 0x98));
  float x2 = 0.0f > x ? 0.0f : mn(3.0f, x);
  for (s32 i = 0; i < *(s32 *)(s + 0x8c); i += 2)
    F(s, 0xc9 + side * 0xde + (i / 2) * 0x1bc) = sadd(F(s, 0xc9 + side * 0xde + (i / 2) * 0x1bc), x2);
  for (s32 i = 0; i < *(s32 *)(s + 0x90); i += 2)
    F(s, 0x441 + side * 0xde + (i / 2) * 0x1bc) = sadd(F(s, 0x441 + side * 0xde + (i / 2) * 0x1bc), x2);
}
PCREG(526ac0, ucCarWeight);

// 0x526360 (CUnderCarriageCar, unnamed): damper x/z follow the wheel anchors (front +0x7c9 stride 0x163, rear
// +0xd55 stride 0x133) through group +0x88 GetRootPoint.
static void THISCALL ucCarDampersFollow(u8 *s) {
  static const u32 row[2][4] = {{0x8c, 0xbd, 0x7c9, 0x163}, {0x90, 0x435, 0xd55, 0x133}};
  for (int r = 0; r < 2; r++)
    for (s32 i = 0; i < *(s32 *)(s + row[r][0]); i++) {
      float p[3];
      u8 *a = s + row[r][2] + i * row[r][3];
      p[0] = F(a, 0);
      p[1] = F(a, 4);
      p[2] = F(a, 8);
      vcall<void>(*(void **)(s + 0x88), 0x84, p);
      ext_516620(s + row[r][1] + i * 0xde, p);
    }
}
PCREG(526360, ucCarDampersFollow);

// 0x524de0 CUnderCarriageCar::CorrectReversedDampers(): as the tank's; a rear damper reset also prints
// "Correcting Back Damper" (undercarriagecar.cpp line 0x35a).
typedef void *(THISCALL *dbgAt)(void *, const char *, u32);
typedef void (*dbgPrint)(void *, const char *);
static void THISCALL ucCarCorrectReversed(u8 *s) {
  static const u32 row[2][4] = {{0x8c, 0xbd, 0x7c9, 0x163}, {0x90, 0x435, 0xd55, 0x133}};
  for (int r = 0; r < 2; r++)
    for (s32 i = 0; i < *(s32 *)(s + row[r][0]); i++) {
      u8 *d = s + row[r][1] + i * 0xde;
      if (0.0f > ssub(F(d, 0x55), F(d, 0x41))) {
        if (r == 1) {
          void *dbg = *(void **)0x700390;
          void *o = (*(dbgAt *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x6a0918, 0x35a);
          (*(dbgPrint *)(*(u8 **)o + 0x2c))(o, (const char *)0x6a0990);
        }
        float p[3];
        u8 *a = s + row[r][2] + i * row[r][3];
        p[0] = F(a, 0);
        p[1] = F(a, 4);
        p[2] = F(a, 8);
        ext_4419f0(p, (float *)(s + 0xc));
        ext_441940(p, (float *)s);
        ext_5162e0(d, p);
      }
    }
}
PCREG(524de0, ucCarCorrectReversed);

// 0x52a0b0 (CSteeringWheel, unnamed: steer toward an angle, pops 4): the angle +0x10 moves toward the target +0x14
// at 60 degrees per second, snapping within 2^-13; a new target is only taken once the old one is reached (or when
// equal). The wheel geom ([+0x18]+8) gets the rotation about y by the angle clamped to +-45 degrees.
static void THISCALL steerTo(u8 *w, float target) {
  float rate = smul(smul(F(sysp(), 0x48), 60.0f), 0.01745329238474369f);
  float cur = F(w, 0x10), tgt = F(w, 0x14);
  bool take = true;
  if (cur > tgt) {
    cur = ssub(cur, rate);
    F(w, 0x10) = cur;
    if (!(sadd(tgt, 0.0001220703125f) > cur))
      take = false;
    else
      F(w, 0x10) = tgt;
  } else if (tgt > cur) {
    cur = sadd(cur, rate);
    F(w, 0x10) = cur;
    if (!(cur > ssub(tgt, 0.0001220703125f)))
      take = false;
    else
      F(w, 0x10) = tgt;
  }
  if (take)
    F(w, 0x14) = target;
  float a = F(w, 0x10);
  float ax[3], R[9];
  ax[0] = 0;
  ax[1] = 1.0f;
  ax[2] = 0;
  float c = -0.7853981852531433f > a ? -0.7853981852531433f : mn(0.7853981852531433f, a);
  ext_4ddcb0(R, ax, c);
  ext_4dcb90(*(void **)(*(u8 **)(w + 0x18) + 8), R);
}
PCREG(52a0b0, steerTo);

// 0x525f30 (CUnderCarriageCar, unnamed: wheels): front wheels (CWheel at +0x30 of each CSteeringWheel) spin with
// sign * speed and steer to steer * sign; rear wheels spin with sign * speed +- turn rate * track (+0xa8) / 2
// (left +, right -).
static void THISCALL ucCarWheels(u8 *s) {
  float h = smul(smul(F(s, 0xa8), F(s, 0x74)), 0.5f);
  float b = smul(F(s, 0x68), F(s, 0x7c));
  float r = ssub(b, h);
  float l = sadd(h, b);
  for (s32 i = 0; i < *(s32 *)(s + 0x8c); i += 2) {
    u8 *w = s + 0x7ad + (i / 2) * 0x2c6;
    ext_529e30(w + 0x30, b, F(s, 0x6c));
    ext_529e30(w + 0x163 + 0x30, b, F(s, 0x6c));
    steerTo(w, smul(F(s, 0x78), F(s, 0x7c)));
    steerTo(w + 0x163, smul(F(s, 0x78), F(s, 0x7c)));
  }
  for (s32 i = 0; i < *(s32 *)(s + 0x90); i += 2) {
    u8 *w = s + 0xd39 + (i / 2) * 0x266;
    ext_529e30(w, l, F(s, 0x6c));
    ext_529e30(w + 0x133, r, F(s, 0x6c));
  }
}
PCREG(525f30, ucCarWheels);

// 0x526880 (CUnderCarriageCar, unnamed: wheel dust). Per wheel emitter pair (+0x3d, +0xb6): intervals 100 / |v| and
// 70 / |v| above |v| = 20 (v = sign * speed, else 0), spread 0.4, strength |v| * 0.3, direction (0, 1, -1) (z = +1
// backward). When the first rear wheel spins free (state 2) the direction flips again and the strength is |v|; when
// it slips (state 1) the strength is acceleration + |v|; in both cases intervals 0.03 and spread 1.0. 10% of frames
// the dust type follows the ground under the first rear damper (undercarriagecar.cpp line 0x288).
static void THISCALL ucCarWheelDust(u8 *s) {
  float dir[3];
  dir[0] = 0;
  dir[1] = 1.0f;
  dir[2] = -1.0f;
  float v = smul(F(s, 0x7c), F(s, 0x68));
  float av = absd(v);
  float i1 = 0, i2 = 0, k = 0.4000000059604645f, e = smul(av, 0.30000001192092896f);
  typedef long double(THISCALL * rfn)(void *, const char *, u32);
  u8 *sy = sysp();
  volatile float rr = (float)(*(rfn *)(*(u8 **)sy + 0x1c0))(sy, (const char *)0x6a0918, 0x288);
  u8 *def = 0;
  if (0.1f >= rr)
    def = (u8 *)ext_516250(s + 0x435);
  if (av > 20.0f) {
    i1 = sdiv(100.0f, av);
    i2 = sdiv(70.0f, av);
  }
  float z;
  if (0.0f > v) {
    z = 1.0f;
    dir[2] = z;
  } else {
    z = dir[2];
  }
  u32 st = *(u32 *)(s + 0xd49);
  if (st == 2 || st == 1) {
    if (st == 2) {
      dir[2] = bitsf(fbits(z) ^ 0x80000000);
      e = av;
    } else {
      e = sadd(F(s, 0x6c), av);
    }
    i2 = 0.029999999329447746f;
    k = 1.0f;
    i1 = 0.029999999329447746f;
  }
  static const u32 row[2][3] = {{0x8c, 0x7dd, 0x163}, {0x90, 0xd39, 0x133}};
  for (int r = 0; r < 2; r++)
    for (s32 i = 0; i < *(s32 *)(s + row[r][0]); i++) {
      u8 *w = s + row[r][1] + i * row[r][2];
      if (def)
        ext_52a070(w, def);
      F(w, 0x4d) = i1;
      F(w, 0xc6) = i2;
      F(w, 0xca) = k;
      ext_516f40(w + 0xb6, dir);
      F(w, 0x113) = e;
    }
}
PCREG(526880, ucCarWheelDust);

// 0x526c60 (CUnderCarriageCar, unnamed: exhaust): as the tank's, emitters +0x1205 (count +0x12f7).
static void THISCALL ucCarExhaust(u8 *s) {
  float x = 0.05000000074505806f;
  float sp = F(s, 0x68);
  if (sp > 100.0f)
    x = sdiv(5.0f, sp);
  if (F(s, 0x6c) > 50.0f)
    x = 0.004999999888241291f;
  x = _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(0.004999999888241291f), _mm_set_ss(x)));
  for (s32 i = 0; i < *(s32 *)(s + 0x12f7); i++) {
    u8 *e = s + 0x1205 + i * 0x79;
    F(e, 0x10) = x;
    ext_5168b0(e);
  }
}
PCREG(526c60, ucCarExhaust);
