// batch910.cpp - vehicles thread, batch 910: ZHeli::UpdateTurnMode, UpdateRollAndTilt, UpdateRollAndTiltMode,
// UpdateYPos.
#include "ff.h"

extern "C" float FASTCALL ext_44e630(float *out, const float *v);              // vnorm(out, v), length in st0
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);  // PSVECSubtract d = a - b

static inline u8 *sysp() { return *(u8 **)0x70039c; }
typedef long double(THISCALL *rfn)(void *, const char *, u32);
static inline long double rnd1c4(u32 line) {
  u8 *sy = sysp();
  return (*(rfn *)(*(u8 **)sy + 0x1c4))(sy, (const char *)0x69f8b8, line);
}
// The function pointer at 0x7003b0 is called at the top of two heli updates (a check hook; a NULL pointer is int3).
static inline void hook7003b0(void *self) {
  typedef void(THISCALL * hf)(void *);
  hf f = *(hf *)0x7003b0;
  if (!f)
    __builtin_trap();
  f(self);
}

static inline void normInPlace(float *d) {
  if (d[0] == 0.0f && d[1] == 0.0f && d[2] == 0.0f)
    return;
  long double x = d[0], y = d[1], z = d[2];
  long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
  d[0] = (float)(d[0] * inv);
  d[1] = (float)(d[1] * inv);
  d[2] = (float)(d[2] * inv);
}

// 0x51e560 ZHeli::UpdateTurnMode(): the wanted direction +0x222 eases (rate 2 * frame time) toward a flat direction:
// the normalised velocity +0x23e when it is moving (|v|^2 > 2^-13), else the path direction +0x256; with a look-at
// geom (+0x34a) the normalised direction from the heli position +0x60 to it instead. The y target is always 0.
static void THISCALL heliUpdateTurnMode(u8 *s) {
  float d[3];
  float *v = (float *)(s + 0x23e);
  float l2 = _mm_cvtss_f32(_mm_add_ss(_mm_add_ss(_mm_mul_ss(_mm_set_ss(v[0]), _mm_set_ss(v[0])),
                                                 _mm_mul_ss(_mm_set_ss(v[1]), _mm_set_ss(v[1]))),
                                      _mm_mul_ss(_mm_set_ss(v[2]), _mm_set_ss(v[2]))));
  ext_44e630(d, l2 > 0.0001220703125f ? v : (float *)(s + 0x256));
  u32 id = *(u32 *)(s + 0x34a);
  if (id) {
    u8 *g = vcall<u8 *>(*(void **)(sysp() + 0x9b), 0x58, id);
    float t[3];
    t[2] = 0;
    t[1] = 0;
    t[0] = 0;
    vcall<void>(g, 0x84, t);
    ext_43e920(d, t, (float *)(s + 0x60));
    normInPlace(d);
  }
  float k = *(float *)(sysp() + 0x48);
  k = k + k;
  d[1] = 0;
  float *w = (float *)(s + 0x222);
  w[0] = (d[0] - w[0]) * k + w[0];
  w[1] = (0.0f - w[1]) * k + w[1];
  w[2] = (d[2] - w[2]) * k + w[2];
}
PCREG(51e560, heliUpdateTurnMode);

// 0x51e470 ZHeli::UpdateRollAndTiltMode(): without a look-at geom (+0x34a): target tilt +0x232 = atan(height
// above ground / 3000) while firing, else 0.035 rad; a debug line "RollAngle: CUR: %.2f  NXT: %.2f" (roll +0x236,
// target roll +0x23a) goes to the engine's debug text (slot 0x190, then cdecl slot 0x184(obj, 10, 0x24, fmt, ...));
// target tilt clamped to [0, 15 deg], target roll to [-35, 35 deg].
typedef void (*dbgText)(void *, u32, u32, const char *, double, double);
static void THISCALL heliUpdateRollAndTiltMode(u8 *s) {
  hook7003b0(s);
  if (*(u32 *)(s + 0x34a))
    return;
  if (*(u32 *)(s + 0x469))
    *(float *)(s + 0x232) = (float)crt::atan((double)(*(float *)(s + 0x597) / 3000.0f));
  else
    *(float *)(s + 0x232) = 0.03500000014901161f;
  void *o = vcall<void *>(sysp(), 0x190);
  (*(dbgText *)(*(u8 **)o + 0x184))(o, 10, 0x24, (const char *)0x69f998, (double)*(float *)(s + 0x236),
                                    (double)*(float *)(s + 0x23a));
  float t = *(float *)(s + 0x232);
  *(float *)(s + 0x232) = 0.0f > t ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(0.2617993950843811f), _mm_set_ss(t)));
  float r = *(float *)(s + 0x23a);
  *(float *)(s + 0x23a) = -0.6108652353286743f > r
                              ? -0.6108652353286743f
                              : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(0.6108652353286743f), _mm_set_ss(r)));
}
PCREG(51e470, heliUpdateRollAndTiltMode);

// 0x51e340 ZHeli::UpdateRollAndTilt(): UpdateRollAndTiltMode (slot 0x380), then the roll (+0x236, generator +0x39f)
// and tilt (+0x22e, generator +0x3c8) follow their wobble generators; a finished generator restarts toward
// target + random * amplitude (roll: +0x23a + r * +0x342, line 0x2bd; tilt: +0x232 + r * +0x346, line 0x2c2).
static void THISCALL heliUpdateRollAndTilt(u8 *s) {
  hook7003b0(s);
  vcall<void>(s, 0x380);
  u8 *gr = s + 0x39f, *gt = s + 0x3c8;
  vcall<void>(gr, 8, s + 0x236);
  vcall<void>(gt, 8, s + 0x22e);
  if (vcall<u8>(gr, 0x20)) {
    void **vt = *(void ***)gr;
    float a = (float)(rnd1c4(0x2bd) * *(float *)(s + 0x342));
    typedef void(THISCALL * f3)(void *, float, float, float);
    ((f3)vt[1])(gr, *(float *)(s + 0x236), *(float *)(s + 0x23a) + a, 0.0f);
  }
  if (vcall<u8>(gt, 0x20)) {
    void **vt = *(void ***)gt;
    float a = (float)(rnd1c4(0x2c2) * *(float *)(s + 0x346));
    typedef void(THISCALL * f3)(void *, float, float, float);
    ((f3)vt[1])(gt, *(float *)(s + 0x22e), *(float *)(s + 0x232) + a, 0.0f);
  }
}
PCREG(51e340, heliUpdateRollAndTilt);

// 0x51e7b0 ZHeli::UpdateYPos(): the height offset +0x26e follows generator +0x29a; when it is done it restarts
// toward +0x272 (set by MoveToYPos).
static void THISCALL heliUpdateYPos(u8 *s) {
  u8 *g = s + 0x29a;
  vcall<void>(g, 8, s + 0x26e);
  if (vcall<u8>(g, 0x20))
    vcall<void>(g, 4, *(float *)(s + 0x26e), *(float *)(s + 0x272), 0.0f);
}
PCREG(51e7b0, heliUpdateYPos);
