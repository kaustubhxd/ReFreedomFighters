// batch903.cpp - vehicles thread, batch 903: CPullToValueAccel leaves, the damper's ground probe and init,
// wheel travel limits, and the undercarriage InitGlobalDamperPositions / InitMinMaxForWheels.
#include "ff.h"

extern "C" u8 THISCALL ext_4e8c00(const void *box, void *info, const float *from, const float *dir, u32 b);
// ZCollisionBox::CalcLineCollision(SExtendedImpactInfo*, const float*, const float*, bool) const, callee pops 16

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
static inline double fabs64(double d) {
  return _mm_cvtsd_f64(_mm_and_pd(_mm_set_sd(d), _mm_load_pd((const double *)ABS64)));
}

// CPullToValueAccel (a value pulled toward a target with acceleration): +0 current, +4 destination, +8 speed,
// +0xc acceleration, +0x10 a time/mass term.
// 0x5243f0 (unnamed in the GC map; an inline "set value": current = destination = v, speed 0).
static void THISCALL pullSetVal(u8 *self, float v) {
  *(float *)self = v;
  *(float *)(self + 4) = v;
  *(u32 *)(self + 8) = 0;
}
PCREG(5243f0, pullSetVal);

// 0x5243d0 (unnamed; sets +0xc).
static void THISCALL pullSetC(u8 *self, float v) { *(float *)(self + 0xc) = v; }
PCREG(5243d0, pullSetC);

// 0x524390 CPullToValueAccel::Acc(): +0xc in st0.
static float THISCALL pullAcc(u8 *self) { return *(float *)(self + 0xc); }
PCREG(524390, pullAcc);

// 0x5243a0 (unnamed): 1 / +0x10 in x87 precision when +0x10 > 0, else 1e38 (0x67cd44).
static long double THISCALL pullInv(u8 *self) {
  float t = *(float *)(self + 0x10);
  if (t > 0.0f)
    return 1.0L / (long double)t;
  return (long double)bitsf(0x7e967699);
}
PCREG(5243a0, pullInv);

// 0x524980 / 0x5247e0: a distance tracker (damper +0x21) between two values pointed to by +0x18 and +0x1c:
// +0 and +4 = |*a - *b| (subtracted in float, abs taken in double), +8 = 0. 0x524980 also sets the pointers.
static void THISCALL distUpdate(u8 *self) {
  float d = _mm_cvtss_f32(_mm_sub_ss(_mm_load_ss(*(float **)(self + 0x18)), _mm_load_ss(*(float **)(self + 0x1c))));
  *(u32 *)(self + 8) = 0;
  float a = (float)fabs64((double)d);
  *(float *)self = a;
  *(float *)(self + 4) = a;
}
PCREG(5247e0, distUpdate);

static void THISCALL distInit(u8 *self, float *a, float *b) {
  *(float **)(self + 0x18) = a;
  *(float **)(self + 0x1c) = b;
  distUpdate(self);
}
PCREG(524980, distInit);

// 0x516130 (unnamed; CDamper ground probe, used by InitAtGround): ground height under the damper.
// With a collision box: a line from the damper position (+0) along (0, -2000, 0); hit -> the impact height
// (info +8), else the +0x41 pull's Acc(). Without one: the world line query (engine +0x9b, its +0xadc object,
// slot 0x2e0) with the ray block at +0x69 (start (x, y, z), dir (0, -2000, 0), +0x9d = 1.0) and flags
// (0, 0x20, 0x200000, 1, 0); hit -> +0x95, else Acc().
typedef u8(THISCALL *lineQ)(void *, void *, u32, u32, u32, u32, u32);
static float THISCALL damperGround(u8 *self, float y, const void *box) {
  if (box) {
    float info[18];
    float dir[3];
    info[0] = 1.0f;
    dir[0] = 0;
    dir[1] = -2000.0f;
    dir[2] = 0;
    if (ext_4e8c00(box, info, (float *)self, dir, 0))
      return info[2];
    return pullAcc(self + 0x41);
  }
  u8 *ray = self + 0x69;
  *(u32 *)(self + 0x9d) = 0x3f800000;
  ((u32 *)ray)[0] = ((u32 *)self)[0];
  ((u32 *)ray)[1] = ((u32 *)self)[1];
  ((u32 *)ray)[2] = ((u32 *)self)[2];
  *(float *)(self + 0x6d) = y;
  *(u32 *)(self + 0x75) = 0;
  *(u32 *)(self + 0x79) = 0xc4fa0000;
  *(u32 *)(self + 0x7d) = 0;
  u8 *q = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc);
  if ((*(lineQ *)(*(u8 **)q + 0x2e0))(q, ray, 0, 0x20, 0x200000, 1, 0))
    return *(float *)(self + 0x95);
  return pullAcc(self + 0x41);
}
PCREG(516130, damperGround);

// 0x516360 CDamper::InitAtGround(const float*): position = p; both pulls (+0x41 lower point, +0x55 damper)
// start at the ground height g; the damper rests at g + travel(+0x35) - clamp(|k(+0x11)| * inv(+0x55) / L(+0x2d),
// 0, travel); the distance tracker +0x21 follows (+0x41, +0x55).
static void THISCALL damperInitAtGround(u8 *self, const u32 *p) {
  ((u32 *)self)[0] = p[0];
  ((u32 *)self)[1] = p[1];
  ((u32 *)self)[2] = p[2];
  u8 *lo = self + 0x41;
  pullSetVal(lo, 0);
  pullSetC(lo, 0);
  volatile float g = damperGround(self, *(float *)(self + 4), 0);
  pullSetVal(lo, g);
  pullSetC(lo, g);
  float L = *(float *)(self + 0x2d);
  u8 *dm = self + 0x55;
  volatile double inv = (double)pullInv(dm);
  double x = fabs64((double)*(float *)(self + 0x11)) * inv;
  float c = (float)(x / (double)L);
  float cl = 0.0f;
  if (!(0.0f > c))
    cl = _mm_cvtss_f32(_mm_min_ss(_mm_load_ss((float *)(self + 0x35)), _mm_set_ss(c)));
  float y = _mm_cvtss_f32(_mm_add_ss(_mm_sub_ss(_mm_load_ss((float *)(self + 0x35)), _mm_set_ss(cl)), _mm_set_ss(g)));
  *(float *)(self + 4) = y;
  pullSetVal(dm, y);
  distInit(self + 0x21, (float *)lo, (float *)dm);
  distUpdate(self + 0x21);
}
PCREG(516360, damperInitAtGround);

// 0x529ca0 CSteeringWheel::InitMinMax(float) / 0x529cd0 CWheel::InitMinMax(float): travel limits around the rest
// height +8: lo = y - r*f, hi = r*f + y (r: +0x44 / +0x14; limits +0x28,+0x2c / +0x35,+0x39).
static inline void wheelMinMax(u8 *self, float f, u32 r, u32 lo, u32 hi) {
  __m128 k = _mm_mul_ss(_mm_load_ss((float *)(self + r)), _mm_set_ss(f));
  _mm_store_ss((float *)(self + lo), _mm_sub_ss(_mm_load_ss((float *)(self + 8)), k));
  _mm_store_ss((float *)(self + hi), _mm_add_ss(k, _mm_load_ss((float *)(self + 8))));
}
static void THISCALL steerInitMinMax(u8 *self, float f) { wheelMinMax(self, f, 0x44, 0x28, 0x2c); }
PCREG(529ca0, steerInitMinMax);
static void THISCALL wheelInitMinMax(u8 *self, float f) { wheelMinMax(self, f, 0x14, 0x35, 0x39); }
PCREG(529cd0, wheelInitMinMax);

// 0x5255d0 CUnderCarriageCar::InitMinMaxForWheels(): front (steering) wheels +0x7ad stride 0x163 and rear wheels
// +0xd39 stride 0x133, both with 0.5.
static void THISCALL ucCarInitMinMax(u8 *self) {
  for (s32 i = 0; i < *(s32 *)(self + 0x8c); i++)
    steerInitMinMax(self + 0x7ad + i * 0x163, 0.5f);
  for (s32 i = 0; i < *(s32 *)(self + 0x90); i++)
    wheelInitMinMax(self + 0xd39 + i * 0x133, 0.5f);
}
PCREG(5255d0, ucCarInitMinMax);

// 0x528090 CUnderCarriageTank::InitMinMaxForWheels(): both track wheel rows (+0xe75, +0x180d, stride 0x133), 3.0.
static void THISCALL ucTankInitMinMax(u8 *self) {
  for (s32 i = 0; i < *(s32 *)(self + 0x8d); i++)
    wheelInitMinMax(self + 0xe75 + i * 0x133, 3.0f);
  for (s32 i = 0; i < *(s32 *)(self + 0x91); i++)
    wheelInitMinMax(self + 0x180d + i * 0x133, 3.0f);
}
PCREG(528090, ucTankInitMinMax);

// InitGlobalDamperPositions: each wheel's local damper anchor goes through the group's slot 0x84 (local to world)
// and the damper is placed on the ground there.
// 0x5254c0 CUnderCarriageCar::InitGlobalDamperPositions(): group +0x88; front anchors +0x7c9 stride 0x163,
// dampers +0xbd; rear anchors +0xd55 stride 0x133, dampers +0x435.
static void THISCALL ucCarInitDampers(u8 *self) {
  for (s32 i = 0; i < *(s32 *)(self + 0x8c); i++) {
    float p[3];
    u8 *a = self + 0x7c9 + i * 0x163;
    p[0] = *(float *)a;
    p[1] = *(float *)(a + 4);
    p[2] = *(float *)(a + 8);
    vcall<void>(*(void **)(self + 0x88), 0x84, p);
    damperInitAtGround(self + 0xbd + i * 0xde, (u32 *)p);
  }
  for (s32 i = 0; i < *(s32 *)(self + 0x90); i++) {
    float p[3];
    u8 *a = self + 0xd55 + i * 0x133;
    p[0] = *(float *)a;
    p[1] = *(float *)(a + 4);
    p[2] = *(float *)(a + 8);
    vcall<void>(*(void **)(self + 0x88), 0x84, p);
    damperInitAtGround(self + 0x435 + i * 0xde, (u32 *)p);
  }
}
PCREG(5254c0, ucCarInitDampers);

// 0x527f80 CUnderCarriageTank::InitGlobalDamperPositions(): group +0x89; anchors +0xe91 / +0x1829 stride 0x133,
// dampers +0x95 / +0x785.
static void THISCALL ucTankInitDampers(u8 *self) {
  for (s32 i = 0; i < *(s32 *)(self + 0x8d); i++) {
    float p[3];
    u8 *a = self + 0xe91 + i * 0x133;
    p[0] = *(float *)a;
    p[1] = *(float *)(a + 4);
    p[2] = *(float *)(a + 8);
    vcall<void>(*(void **)(self + 0x89), 0x84, p);
    damperInitAtGround(self + 0x95 + i * 0xde, (u32 *)p);
  }
  for (s32 i = 0; i < *(s32 *)(self + 0x91); i++) {
    float p[3];
    u8 *a = self + 0x1829 + i * 0x133;
    p[0] = *(float *)a;
    p[1] = *(float *)(a + 4);
    p[2] = *(float *)(a + 8);
    vcall<void>(*(void **)(self + 0x89), 0x84, p);
    damperInitAtGround(self + 0x785 + i * 0xde, (u32 *)p);
  }
}
PCREG(527f80, ucTankInitDampers);

// 0x43e960 (unnamed vector helper, x87): a -= b for 3 floats (each difference rounded by fstp).
static void FASTCALL vsub3(float *a, const float *b) {
  long double x = (long double)a[0] - b[0], y = (long double)a[1] - b[1], z = (long double)a[2] - b[2];
  a[0] = (float)x;
  a[1] = (float)y;
  a[2] = (float)z;
}
PCREG(43e960, vsub3);
