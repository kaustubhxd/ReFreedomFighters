// batch 78004: 0x5d0f10 (camera stick motion update).
#include "ff.h"

extern "C" double VECTORCALL ext_634db2(double, double);
static inline double crt_pow(double x, double y) { return ext_634db2(x, y); }
template <class T> static inline T &at(const void *p, u32 off) { return *(T *)((u8 *)p + off); }
static inline void THISCALL fn5d0f10(void *self) {
  float pitchSpeed;
  if (!at<u8>(self, 0xb45) && at<u32>(self, 0xad5) != 5) {
    float s = at<float>(self, 0xadd);
    at<float>(self, 0xa60) = at<float>(self, 0xb1f) * G(float, 0x6b4ff4) * s;
    pitchSpeed = at<float>(self, 0xb23) * G(float, 0x6b4fb8) * s;
  } else {
    float s = at<float>(self, 0xadd), y = at<float>(self, 0xb23), x = at<float>(self, 0xb1f);
    float ay = y * s * G(float, 0x680a70);
    float ax = s * x * G(float, 0x6b4d48);
    at<float>(self, 0xa6c) = ay;
    at<float>(self, 0xa68) = ax;
    float dt = *(float *)(G(u8 *, 0x70039c) + 0x48);
    at<float>(self, 0xa60) = dt * ax + at<float>(self, 0xa60);
    at<float>(self, 0xa64) = dt * ay + at<float>(self, 0xa64);
    if (y == 0.0f || at<u8>(self, 0xa71)) at<u32>(self, 0xa64) = 0;
    if (x == 0.0f || at<u8>(self, 0xa70)) at<u32>(self, 0xa60) = 0;
    at<float>(self, 0xa60) = (float)(crt_pow(G(double, 0x6785f8), (double)dt) * (double)at<float>(self, 0xa60));
    pitchSpeed = (float)(crt_pow(G(double, 0x6785f8), (double)dt) * (double)at<float>(self, 0xa64));
  }
  float yawSpeed = at<float>(self, 0xa60);
  at<float>(self, 0xa64) = pitchSpeed;
  if (!(yawSpeed == 0.0f && pitchSpeed == 0.0f)) at<u32>(self, 0xb05) = 0x3f800000;
  float dt = *(float *)(G(u8 *, 0x70039c) + 0x48);
  float pi = G(float, 0x67da18);
  float step = yawSpeed * dt;
  if (step > G(float, 0x6ad1fc) || G(float, 0x6ad234) > step) step = pi;
  float yaw = at<float>(self, 0xa54) + step;
  if (yaw > pi) yaw -= G(float, 0x68aef8);
  else if (G(float, 0x6ad238) > yaw) yaw += G(float, 0x68aef8);
  at<float>(self, 0xa54) = yaw;
  at<float>(self, 0xa5c) = at<float>(self, 0xa64) * dt + at<float>(self, 0xa5c);
  if (!(at<float>(self, 0xb1f) == 0.0f && at<float>(self, 0xb23) == 0.0f)) at<u8>(self, 0xab6) = 0;
  float p = at<float>(self, 0xa5c), lo = at<float>(self, 0xa9e);
  at<float>(self, 0xa5c) = lo > p ? lo : (at<float>(self, 0xaa2) < p ? at<float>(self, 0xaa2) : p);
}
PCREG(5d0f10, fn5d0f10);
