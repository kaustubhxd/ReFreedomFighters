// batch909.cpp - vehicles thread, batch 909: ZHeli::UpdateDeltaPos (hover wobble) and ZHeli::UpdateDir.
#include "ff.h"

extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);                 // vangle (radians, st0)
extern "C" void FASTCALL ext_4e0130(float *out, const float *cur, const float *to, float maxang);  // vangpul

static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x51d8f0 ZHeli::UpdateDeltaPos(): three wobble generators (objects at +0x2c3, +0x2ec, +0x315, one per axis) write
// the hover offset +0x276/+0x27a/+0x27e (slot 8). When one has reached its goal (slot 0x20), a new goal =
// engine random (slot 0x1c4(file, line 0x262/0x268/0x26e), st0) * amplitude (+0x28e/+0x292/+0x296) is stored at
// +0x282/+0x286/+0x28a and the generator restarts from the current offset (slot 4(cur, goal, 0)).
static void THISCALL heliUpdateDeltaPos(u8 *s) {
  typedef long double(THISCALL * rfn)(void *, const char *, u32);
  static const u32 gen[3] = {0x2c3, 0x2ec, 0x315};
  for (int i = 0; i < 3; i++)
    vcall<void>(s + gen[i], 8, s + 0x276 + 4 * i);
  static const u32 line[3] = {0x262, 0x268, 0x26e};
  for (int i = 0; i < 3; i++) {
    u8 *g = s + gen[i];
    if (!vcall<u8>(g, 0x20))
      continue;
    u8 *sy = sysp();
    long double r = (*(rfn *)(*(u8 **)sy + 0x1c4))(sy, (const char *)0x69f8b8, line[i]);
    float goal = (float)(r * *(float *)(s + 0x28e + 4 * i));
    *(float *)(s + 0x282 + 4 * i) = goal;
    vcall<void>(g, 4, *(float *)(s + 0x276 + 4 * i), goal, 0.0f);
  }
}
PCREG(51d8f0, heliUpdateDeltaPos);

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};

// 0x51da80 ZHeli::UpdateDir(): UpdateTurnMode (slot 0x378), then the direction +0x216 turns toward the wanted
// direction +0x222 by at most frame time * |sin(angle between them)| radians (vangpul), and is normalised
// (x87, skipped when exactly zero).
static void THISCALL heliUpdateDir(u8 *s) {
  vcall<void>(s, 0x378);
  float *d = (float *)(s + 0x216);
  volatile double a = (double)ext_4e0030((float *)(s + 0x222), d);
  double sn = crt::sin(a);
  float m = (float)_mm_cvtsd_f64(_mm_and_pd(_mm_set_sd(sn), _mm_load_pd((const double *)ABS64)));
  ext_4e0130(d, d, (float *)(s + 0x222), *(float *)(sysp() + 0x48) * m);
  if (d[0] == 0.0f && d[1] == 0.0f && d[2] == 0.0f)
    return;
  long double x = d[0], y = d[1], z = d[2];
  long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
  d[0] = (float)(d[0] * inv);
  d[1] = (float)(d[1] * inv);
  d[2] = (float)(d[2] * inv);
}
PCREG(51da80, heliUpdateDir);
