#include "ff.h"

typedef long long s64;
extern "C" s64 STDCALL ext_634290(s64 a, s64 b);
extern "C" long double THISCALL ext_662940(void *self, float t);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

// 0x662870: thiscall() -> st0 float: timed interpolation. Fields: [0] float, [4] end value, [8] start value, [0xd] stamp, [0x11] duration (s32), the engine clock is the dword
// [0x70039c] + 0x40. Clock >= stamp + duration -> end value [4]. Otherwise t = float((((clock - stamp) << 10) / duration) as signed 64-bit divide 0x634290, low dword)
// * [0x6785e4]; t < 0 or t > [0x678858] (1.0) returns the current value [0]; else e = ease curve 0x662940(t) (t <= [0x67a6ac]) or 1 - ease curve(1 - t) and the result is
// (end - start) * (float)e + start in single precision.
extern "C" long double THISCALL fn_662870(u8 *self) {
  s32 clk = (s32)rd32u(G(u8 *, 0x70039c) + 0x40);
  s32 dur = (s32)rd32u(self + 0x11);
  s32 stamp = (s32)rd32u(self + 0xd);
  if (clk >= (s32)((u32)stamp + (u32)dur)) return (long double)rdf(self + 4);
  s64 a = (s64)(clk - stamp) << 10;
  s64 q = ext_634290(a, (s64)dur);
  float t = (float)(s32)q * G(float, 0x6785e4);
  if (0.0f > t) return (long double)rdf(self);
  if (t > G(float, 0x678858)) return (long double)rdf(self);
  float ef;
  if (G(float, 0x67a6ac) >= t) {
    ef = (float)ext_662940(self, t);
  } else {
    long double e1 = ext_662940(self, G(float, 0x678858) - t);
    ef = (float)(1.0L - e1);
  }
  float r = (rdf(self + 4) - rdf(self + 8)) * ef + rdf(self + 8);
  return (long double)r;
}
PCREG(662870, fn_662870);
