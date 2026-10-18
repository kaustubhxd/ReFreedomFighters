// batch1624.cpp - ZDllSound::SetGroupVolume (soundtimers thread, 2026-10-11).
//
// SetGroupVolume(int group, int value, int mode): the group's volume is stored as a fraction (+0x5159 + group*9).
// The value is a percentage. Mode 1: 10^((v-100)/20) (a decibel curve, pow with base 10; v == 100 is linear, which is
// the same value); NaN takes the pow path (the original's jnp tests the parity of the flags after test ah,0x44).
// Mode 2 maps 0..100 through a curve table: the 100 floats at 0x6a2500 (copied to the stack by the original) plus
// 100.0 at index 100 (the original writes it at ebp-8); values below 0 or above 100 stay linear. GUESS: the curve's
// meaning is not traced; only the table values are exact. Other modes: linear. Group types 0-2 scale the volume again
// by 0.56 / 0.49 / 0.89 (jump table at 0x539bc8), group 3 and above do not. A volume above 0 (ordered compare, so NaN
// stores 0) clears the group's "muted" flag (+0x515d) and, unless the DLL is paused (+0x50a9), sets the kind of every
// sound object of that group to 5 (the list at +0x53b2; GUESS: the list iterator's semantics are read from the vtable
// calls only). The group flag is set to 1 after a volume above 0, else 0; +0x5147 becomes 1.
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }

// The 100 floats at 0x6a2500 (copied at build time from the exe's data) plus 100.0 at index 100.
static const float kCurve[101] = {
    0.0f, 0.18000000715255737f, 0.2199999988079071f, 0.25999999046325684f, 0.3199999928474426f, 0.33000001311302185f, 0.3499999940395355f, 0.3799999952316284f, 0.4000000059604645f, 0.4699999988079071f,
    0.5600000023841858f, 0.6700000166893005f, 0.7900000214576721f, 0.8899999856948853f, 1.0f, 1.1200000047683716f, 1.2599999904632568f, 1.5f, 1.7799999713897705f, 2.109999895095825f,
    2.509999990463257f, 2.819999933242798f, 3.1600000858306885f, 3.549999952316284f, 3.9800000190734863f, 4.46999979019165f, 5.010000228881836f, 5.619999885559082f, 6.309999942779541f, 6.880000114440918f,
    7.5f, 8.180000305175781f, 8.90999984741211f, 9.720000267028809f, 10.59000015258789f, 11.550000190734863f, 12.59000015258789f, 13.34000015258789f, 14.130000114440918f, 14.960000038146973f,
    15.850000381469727f, 16.790000915527344f, 17.780000686645508f, 18.84000015258789f, 19.950000762939453f, 20.540000915527344f, 21.1299991607666f, 21.75f, 22.389999389648438f, 23.040000915527344f,
    23.709999084472656f, 24.40999984741211f, 25.1200008392334f, 25.850000381469727f, 26.610000610351562f, 27.3799991607666f, 28.18000030517578f, 29.010000228881836f, 29.850000381469727f, 30.729999542236328f,
    31.6200008392334f, 32.54999923706055f, 33.5f, 34.470001220703125f, 35.47999954223633f, 36.52000045776367f, 37.58000183105469f, 38.68000030517578f, 39.810001373291016f, 40.970001220703125f,
    42.16999816894531f, 43.400001525878906f, 44.66999816894531f, 45.970001220703125f, 47.31999969482422f, 48.70000076293945f, 50.119998931884766f, 51.58000183105469f, 53.09000015258789f, 54.63999938964844f,
    56.22999954223633f, 57.880001068115234f, 59.56999969482422f, 61.310001373291016f, 63.099998474121094f, 64.94000244140625f, 66.83000183105469f, 68.79000091552734f, 70.79000091552734f, 72.86000061035156f,
    74.98999786376953f, 77.18000030517578f, 79.43000030517578f, 81.75f, 84.13999938964844f, 86.5999984741211f, 89.12999725341797f, 91.7300033569336f, 94.41000366210938f, 97.16000366210938f,
    100.0f,
};

extern "C" char ext_634db2[];  // CRT pow (libm_sse2_pow_precise, base in xmm0, exponent in xmm1)
typedef double(VECTORCALL *PowFn)(double, double);

void THISCALL ZDllSound_SetGroupVolume(u8 *self, u32 group, s32 value, u32 mode) {
  float v = (float)value;
  float f = v;
  if (mode == 1 && !(v == 100.0f)) {
    float t = (v - 100.0f) / 20.0f;
    double p = ((PowFn)(void *)ext_634db2)(10.0, (double)t);
    f = (float)p * 100.0f;
  } else if (mode == 2 && v >= 0.0f && v <= 100.0f) {
    f = kCurve[(s32)v];
  }
  float vol = f * 0.01f;  // 0x67da00
  switch (group) {
    case 0: vol *= 0.5600000023841858f; break;  // 0x6a24dc
    case 1: vol *= 0.49000000953674316f; break;  // 0x6a24d8
    case 2: vol *= 0.8899999856948853f; break;  // 0x6a24e0
    default: break;
  }
  u32 off = group * 9;
  AT(float, self, off + 0x5159) = vol;
  if (vol > 0.0f) {
    if (!AT(u8, self, off + 0x515d) && !AT(u8, self, 0x50a9)) {
      u8 *lst = self + 0x53b2;
      u32 tmp = 0;
      vcall<void>(lst, 0x4c, &tmp);
      u32 r = vcall<u32>(lst, 0x5c, &tmp);
      while (tmp) {
        u8 *o = (u8 *)srefToPtr(r);
        if (o && AT(u32, o, 0x2c) == group) AT(u32, o, 4) = 5;
        r = vcall<u32>(lst, 0x5c, &tmp);
      }
    }
    AT(u8, self, off + 0x515d) = 1;
  } else {
    AT(u8, self, off + 0x515d) = 0;
  }
  AT(u8, self, 0x5147) = 1;
}
PCREG(5398f0, ZDllSound_SetGroupVolume);
