// batch919.cpp - vehicles thread, batch 919: the damper physics step (Verlet integration of the two
// CPullToValueAccel points of each CDamper with a spring between them) and CUnderCarriageTank::DynamicsFrameUpdate.
#include "ff.h"

extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void FASTCALL ext_4ddcb0(float *m, const float *axis, float a);          // LoadRotationAxisAngle
extern "C" void FASTCALL ext_4de480(float *mat, const float *m2);                   // mat = mat * m2
extern "C" void THISCALL ext_529760(void *uc);  // CUnderCarriageTank::UpdateYPos (902)
extern "C" void THISCALL ext_527710(void *uc);  // CUnderCarriageTank::CalcRollAndTilt (904)

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
// SSE ops with the destination fixed to the first operand, as MSVC emitted them: when both operands are NaN the
// result is the first one, and clang would otherwise be free to swap the operands of a commutative add/mul.
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float ssub(float a, float b) { asm("subss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// CPullToValueAccel as a point mass: +0 position, +4 previous position, +8 force, +0xc ground (lower point only),
// +0x10 1/mass.
// 0x524370 (unnamed): ground + 0.1 >= position (a bool nobody uses, see CDamper update).
static u8 THISCALL pullNearGround(u8 *p) { return F(p, 0xc) + 0.1f >= F(p, 0) ? 1 : 0; }
PCREG(524370, pullNearGround);

// Verlet step: next = force * (1/mass) * dt^2 + (2 * pos - prev), the move limited to +-1.5 per step.
// 0x524540 (unnamed): the damper's upper point.
static void THISCALL pullStep(u8 *p, float dt) {
  float cur = F(p, 0);
  float n = sadd(smul(smul(F(p, 0x10), F(p, 8)), smul(dt, dt)), ssub(sadd(cur, cur), F(p, 4)));
  float d = ssub(n, cur);
  if (d > 1.5f) {
    F(p, 4) = cur;
    F(p, 0) = sadd(cur, 1.5f);
    return;
  }
  if (-1.5f > d)
    n = ssub(cur, 1.5f);
  F(p, 4) = cur;
  F(p, 0) = n;
}
PCREG(524540, pullStep);

// 0x5245c0 (unnamed): the lower point, the same step plus the ground (+0xc): when it ends up at least 2^-13 below
// the ground it is put on the ground and its previous position moved by half the penetration (a bounce).
static void THISCALL pullStepGround(u8 *p, float dt) {
  float cur = F(p, 0);
  float n = sadd(smul(smul(F(p, 0x10), F(p, 8)), smul(dt, dt)), ssub(sadd(cur, cur), F(p, 4)));
  float d = ssub(n, cur);
  if (d > 1.5f)
    n = sadd(cur, 1.5f);
  else if (-1.5f > d)
    n = ssub(cur, 1.5f);
  float g = F(p, 0xc);
  float pen = ssub(g, n);
  *(u32 *)(p + 4) = *(u32 *)p;
  F(p, 0) = n;
  if (pen >= 0.0001220703125f) {
    F(p, 0) = g;
    F(p, 4) = sadd(smul(pen, 0.5f), F(p, 4));
  }
}
PCREG(5245c0, pullStepGround);

// 0x5246a0 (unnamed): the damper spring (+0x21 of the damper): length +0 = |a - b| (abs in double), rest +0x14,
// stiffness +0xc, damping +0x10, length speed +8; force f = -(len - rest) * k - damping * speed goes onto a's force
// (+8) and off b's, signed by which point is higher. Returns f in st0 (0 when the length is exactly 0, which skips
// the rest); speed = (len - previous len) / dt.
static long double THISCALL springStep(u8 *s, float dt) {
  float *a = *(float **)(s + 0x18), *b = *(float **)(s + 0x1c);
  float len = (float)_mm_cvtsd_f64(_mm_and_pd(_mm_set_sd((double)ssub(a[0], b[0])), _mm_load_pd((const double *)ABS64)));
  F(s, 0) = len;
  if (len == 0.0f)
    return 0.0L;
  float f = ssub(bitsf(fbits(smul(ssub(len, F(s, 0x14)), F(s, 0xc))) ^ 0x80000000), smul(F(s, 0x10), F(s, 8)));
  volatile float fr = f;
  float sg = 0.0f > ssub(a[0], b[0]) ? -1.0f : 1.0f;
  float F2 = smul(sg, f);
  a[2] = sadd(a[2], F2);
  float *bb = *(float **)(s + 0x1c);
  bb[2] = ssub(bb[2], F2);
  float dl = ssub(F(s, 0), F(s, 4));
  *(u32 *)(s + 4) = *(u32 *)s;
  F(s, 8) = _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(dl), _mm_set_ss(dt)));
  return (long double)fr;
}
PCREG(5246a0, springStep);

extern "C" long double THISCALL ext_5243a0(void *p);  // CPullToValueAccel 1 / +0x10 (903)

// 0x516070 (CDamper, unnamed: physics step of one damper, dt): gravity force on both points = (1/+0x10, x87) *
// gravity (+0x11) * mass (+0xc); the spring; Verlet steps (lower point with the ground). Bottomed-out flag +0x10 =
// (minimum length +0x1d >= length). Outside the travel range [+0x15, +0x19] the near-ground check runs (unused).
static void THISCALL damperStep(u8 *d, float dt) {
  float m = smul(F(d, 0x11), F(d, 0xc));
  F(d, 0x49) = (float)(ext_5243a0(d + 0x41) * (long double)m);
  F(d, 0x5d) = (float)(ext_5243a0(d + 0x55) * (long double)m);
  springStep(d + 0x21, dt);
  pullStepGround(d + 0x41, dt);
  pullStep(d + 0x55, dt);
  float l = ssub(F(d, 0x55), F(d, 0x41));
  d[0x10] = 0;
  if (F(d, 0x1d) >= l)
    d[0x10] = 1;
  float lim;
  if (F(d, 0x15) > l)
    lim = F(d, 0x15);
  else if (l > F(d, 0x19))
    lim = F(d, 0x19);
  else
    return;
  if (0.0f > ssub(l, lim))
    pullNearGround(d + 0x41);
}
PCREG(516070, damperStep);

// 0x527b30 (CUnderCarriageTank, unnamed: one physics step): every damper of both rows steps by +0x21b5; +0x22cc =
// 1.0 when any bottomed out (else 0).
static void THISCALL ucTankStep(u8 *s) {
  *(u32 *)(s + 0x22cc) = 0;
  for (s32 i = 0; i < *(s32 *)(s + 0x8d); i++) {
    damperStep(s + 0x95 + i * 0xde, F(s, 0x21b5));
    if (s[0xa5 + i * 0xde])
      *(u32 *)(s + 0x22cc) = 0x3f800000;
  }
  for (s32 i = 0; i < *(s32 *)(s + 0x91); i++) {
    damperStep(s + 0x785 + i * 0xde, F(s, 0x21b5));
    if (s[0x795 + i * 0xde])
      *(u32 *)(s + 0x22cc) = 0x3f800000;
  }
}
PCREG(527b30, ucTankStep);

// 0x527bd0 CUnderCarriageTank::DynamicsFrameUpdate(): fixed 5 ms steps (+0x21b5 = 0.005) from the simulated time
// +0x48 to now, at most 10 (then the clock jumps to now); then body height, roll/tilt and the body matrix
// (direction +0x4c flattened, turned by roll +0x38 about row 0 and tilt +0x30 about row 2).
static void THISCALL ucTankDynamics(u8 *s) {
  F(s, 0x21b5) = 0.004999999888241291f;
  s32 t = *(s32 *)(*(u8 **)0x70039c + 0x40) - _mm_cvttss_si32(_mm_set_ss(F(s, 0x48) * 1024.0f));
  float q = _mm_cvtss_f32(_mm_div_ss(_mm_set_ss((float)t * 0.0009765625f), _mm_set_ss(0.004999999888241291f)));
  s32 n = _mm_cvttss_si32(_mm_set_ss(q));
  if (n >= 10)
    n = 10;
  if (n > 0) {
    for (s32 i = 0; i < n; i++)
      ucTankStep(s);
    if (n >= 10)
      F(s, 0x48) = (float)*(s32 *)(*(u8 **)0x70039c + 0x40) * 0.0009765625f;
    else
      F(s, 0x48) = sadd(smul((float)n, F(s, 0x21b5)), F(s, 0x48));
  }
  ext_529760(s);
  ext_527710(s);
  float roll = F(s, 0x38), tilt = F(s, 0x30);
  float *mat = (float *)(s + 0xc);
  *(u32 *)(s + 0x50) = 0;
  ext_4de040(mat, (float *)(s + 0x4c), 0);
  float r1[9], r2[9];
  ext_4ddcb0(r1, mat, roll);
  ext_4ddcb0(r2, mat + 6, tilt);
  ext_4de480(mat, r1);
  ext_4de480(mat, r2);
}
PCREG(527bd0, ucTankDynamics);
