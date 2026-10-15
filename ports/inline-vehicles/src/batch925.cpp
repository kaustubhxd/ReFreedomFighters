// batch925.cpp - vehicles thread, batch 925: ZCar::PositionCarDrivingForward / Backward (the car's bicycle model
// along the path) and the 4-argument vaddscalar.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" void FASTCALL ext_43e960(float *a, const float *b);                  // a -= b
extern "C" void FASTCALL ext_441940(float *a, const float *b);                  // a += b
extern "C" void THISCALL ext_4e0d00(float *v, float k);                         // vscalar
extern "C" void FASTCALL ext_4e0be0(float *v, const float *ang);                // vrot (Euler angles)
extern "C" void THISCALL ext_523330(void *path, float *d);                      // CMoveAlongPath::GetDir
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);           // vangle
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);  // vcross
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x443ef0 vaddscalar(float* out, const float* a, const float* b, float k): out = a + b * k (x87, each component
// rounded to float), fastcall + 2 stack args.
static void FASTCALL vaddscalar4(float *out, const float *a, const float *b, float k) {
  long double x = (long double)b[0] * k, y = (long double)b[1] * k, z = (long double)b[2] * k;
  x = x + a[0];
  y = y + a[1];
  z = z + a[2];
  out[0] = (float)x;
  out[1] = (float)y;
  out[2] = (float)z;
}
PCREG(443ef0, vaddscalar4);

static inline void normXZ(float *v, bool checkY) {
  if (v[0] == 0.0f && (!checkY || v[1] == 0.0f) && v[2] == 0.0f)
    return;
  long double x = v[0], y = v[1], z = v[2];
  long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
  v[0] = (float)(v[0] * inv);
  v[1] = (float)(v[1] * inv);
  v[2] = (float)(v[2] * inv);
}

// Steering angle = signed angle from a to b (negative when the cross product's y is positive).
static inline void steerAngle(float *out, const float *a, const float *b) {
  float c[3];
  *out = ext_4e0030(a, b);
  ext_446ee0(c, a, b);
  if (c[1] > 0.0f)
    *out = bitsf(fbits(*out) ^ 0x80000000);
}

// 0x518380 ZCar::PositionCarDrivingForward(float* target, float* pos, float* dir, float& steer), pops 16. The front
// axle point = body point (group +8: +0x24) - old direction (+0x15df) * front offset (+0x37c); new direction =
// target - front point, flattened, normalised; position = target - direction * rear offset (+0x378); steering =
// signed angle from the flat path direction to the new direction.
static void THISCALL carPositionForward(u8 *s, const float *target, float *pos, float *dir, float *steer) {
  float f[3], g[3];
  vaddscalar4(f, (float *)(*(u8 **)(s + 8) + 0x24), (float *)(s + 0x15df), bitsf(fbits(F(s, 0x37c)) ^ 0x80000000));
  ext_43e920(dir, target, f);
  dir[1] = 0;
  normXZ(dir, false);
  vaddscalar4(pos, target, dir, bitsf(fbits(F(s, 0x378)) ^ 0x80000000));
  ext_523330(*(void **)(s + 0x5c), g);
  g[1] = 0;
  steerAngle(steer, g, dir);
}
PCREG(518380, carPositionForward);

// 0x518190 ZCar::PositionCarDrivingBackward(...), pops 16. Direction = minus the flat path direction, normalised,
// yawed by +0x15f7 * push time (+0x15fb) after an impact; position = target + direction * front offset (+0x37c);
// steering: T = (old dir - dir) * (rear + front offset) + old target - target;
// when longer than 0.1: signed angle from the direction to it.
static void THISCALL carPositionBackward(u8 *s, const float *target, float *pos, float *dir, float *steer) {
  ext_523330(*(void **)(s + 0x5c), dir);
  dir[1] = 0;
  ext_4e0d00(dir, -1.0f);
  normXZ(dir, true);
  float t = F(s, 0x15fb);
  if (t > 0.0f) {
    float r[3];
    r[0] = 0;
    r[2] = 0;
    r[1] = _mm_cvtss_f32(_mm_mul_ss(_mm_load_ss((float *)(s + 0x15f7)), _mm_set_ss(t)));
    ext_4e0be0(dir, r);
  }
  vaddscalar4(pos, target, dir, F(s, 0x37c));
  float T[3];
  ext_43e920(T, (float *)(s + 0x15df), dir);
  ext_4e0d00(T, _mm_cvtss_f32(_mm_add_ss(_mm_load_ss((float *)(s + 0x378)), _mm_load_ss((float *)(s + 0x37c)))));
  ext_441940(T, (float *)(s + 0x15d3));
  ext_43e960(T, target);
  float l2 = _mm_cvtss_f32(_mm_add_ss(_mm_add_ss(_mm_mul_ss(_mm_set_ss(T[0]), _mm_set_ss(T[0])),
                                                 _mm_mul_ss(_mm_set_ss(T[1]), _mm_set_ss(T[1]))),
                                      _mm_mul_ss(_mm_set_ss(T[2]), _mm_set_ss(T[2]))));
  if ((float)crt::sqrt((double)l2) > 0.1f)
    steerAngle(steer, dir, T);
}
PCREG(518190, carPositionBackward);
