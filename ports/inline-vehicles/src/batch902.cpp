// batch902.cpp - vehicles thread, batch 902: damper/wheel height leaves and the undercarriage Y updates.
#include "ff.h"

extern "C" void THISCALL ext_4dcd70(void *geom, const float *pos);       // ZBaseGeom::SetPosSimple
extern "C" void FASTCALL ext_43e960(float *a, const float *b);          // a -= b (x87, 3 floats)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);          // v = v * m (row vector times 3x3, x87)
extern "C" void THISCALL ext_525640(void *uc, const float *pos, const float *dir);  // CUnderCarriageCar::InitPosDir

// 0x5162d0 CDamper (name unknown, GetYPos by inference): the damper's current height +0x55, in st0.
static float THISCALL damperGetY(u8 *self) { return *(float *)(self + 0x55); }
PCREG(5162d0, damperGetY);

// 0x516230 CDamper::GetLowerPos(float[3]&): (x +0, lower y +0x41, z +8).
static void THISCALL damperGetLowerPos(u8 *self, u32 *out) {
  out[0] = *(u32 *)self;
  out[1] = *(u32 *)(self + 0x41);
  out[2] = *(u32 *)(self + 8);
}
PCREG(516230, damperGetLowerPos);

// Wheel height: y = rest + offset + dy, clamped to [lo, hi] (lo wins when lo > hi), stored at +8; then the wheel's
// geometry ([[+0x18]+8]) is moved to the wheel position +4.
static inline void wheelSetY(u8 *self, float dy, u32 o1, u32 o2, u32 lo, u32 hi) {
  float y = _mm_cvtss_f32(_mm_add_ss(_mm_add_ss(_mm_load_ss((float *)(self + o1)), _mm_load_ss((float *)(self + o2))),
                                     _mm_set_ss(dy)));
  float l = *(float *)(self + lo);
  float r = l > y ? l : _mm_cvtss_f32(_mm_min_ss(_mm_load_ss((float *)(self + hi)), _mm_set_ss(y)));
  *(float *)(self + 8) = r;
  ext_4dcd70(*(void **)(*(u8 **)(self + 0x18) + 8), (float *)(self + 4));
}

// 0x52a270 CWheel::SetYPos(float): rest +0x31, offset +0x14, limits +0x35 / +0x39.
static void THISCALL wheelSetYPos(u8 *self, float dy) { wheelSetY(self, dy, 0x31, 0x14, 0x35, 0x39); }
PCREG(52a270, wheelSetYPos);

// 0x52a220 front (steering) car wheel SetYPos, a CWheel subclass with its own layout: +0x61, +0x44, limits
// +0x28 / +0x2c. Name not in the GC map; inferred from its use for the car's front wheels.
static void THISCALL frontWheelSetYPos(u8 *self, float dy) { wheelSetY(self, dy, 0x61, 0x44, 0x28, 0x2c); }
PCREG(52a220, frontWheelSetYPos);

// Body height = mean damper height of both wheel sets (x87 sum stored as float each step, then SSE divide).
static float meanDamperY(u8 *self, u32 n1, u32 d1, u32 n2, u32 d2) {
  *(float *)(self + 4) = 0;
  for (s32 i = 0; i < *(s32 *)(self + n1); i++)
    *(float *)(self + 4) = (float)((long double)damperGetY(self + d1 + i * 0xde) + *(float *)(self + 4));
  for (s32 i = 0; i < *(s32 *)(self + n2); i++)
    *(float *)(self + 4) = (float)((long double)damperGetY(self + d2 + i * 0xde) + *(float *)(self + 4));
  s32 n = *(s32 *)(self + n2) + *(s32 *)(self + n1);
  return _mm_cvtss_f32(_mm_div_ss(_mm_load_ss((float *)(self + 4)), _mm_cvtepi32_ps(_mm_cvtsi32_si128(n))));
}

// 0x529760 CUnderCarriageTank::UpdateYPos(): y (+4) = mean damper height + 25 (0x685270).
static void THISCALL ucTankUpdateYPos(u8 *self) {
  float m = meanDamperY(self, 0x8d, 0x95, 0x91, 0x785);
  *(float *)(self + 4) = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss(m), _mm_set_ss(25.0f)));
}
PCREG(529760, ucTankUpdateYPos);

// 0x526df0 CUnderCarriageCar::UpdateYPos(): y (+4) = mean damper height. If that is more than 5000 (0x69eb5c) above
// the spline height +0x64, the debug log (0x700390 slot 0x20 with file/line 0x386, then cdecl slot 0x30) prints
// "WARNING CAR too high above it's spline: Correcting error" and InitPosDir((x, spline y, z), dir +0x4c) resets it.
typedef void *(THISCALL *dbgAt)(void *, const char *, u32);
typedef void (*dbgPrint)(void *, const char *);
static void THISCALL ucCarUpdateYPos(u8 *self) {
  float y = meanDamperY(self, 0x8c, 0xbd, 0x90, 0x435);
  float lim = _mm_cvtss_f32(_mm_add_ss(_mm_load_ss((float *)(self + 0x64)), _mm_set_ss(5000.0f)));
  *(float *)(self + 4) = y;
  if (y > lim) {
    void *dbg = *(void **)0x700390;
    void *o = (*(dbgAt *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x6a0918, 0x386);
    (*(dbgPrint *)(*(u8 **)o + 0x30))(o, (const char *)0x6a09a8);
    float p[3];
    p[0] = *(float *)self;
    p[2] = *(float *)(self + 8);
    p[1] = *(float *)(self + 0x64);
    ext_525640(self, p, (float *)(self + 0x4c));
  }
}
PCREG(526df0, ucCarUpdateYPos);

// Wheel heights follow their dampers: lower damper point minus body position (+0), into body space (rotation
// +0xc), and its y goes to the wheel's SetYPos.
template <class F>
static inline void wheelsFollow(u8 *self, u32 n, u32 d, u32 w, u32 ws, F setY) {
  for (s32 i = 0; i < *(s32 *)(self + n); i++) {
    float p[3];
    damperGetLowerPos(self + d + i * 0xde, (u32 *)p);
    ext_43e960(p, (float *)self);
    ext_441a60(p, (float *)(self + 0xc));
    setY(self + w + i * ws, p[1]);
  }
}

// 0x529660 CUnderCarriageTank::UpdateWheelsYPos(): dampers +0x95 / +0x785, wheels +0xe75 / +0x180d (stride 0x133).
static void THISCALL ucTankUpdateWheelsYPos(u8 *self) {
  wheelsFollow(self, 0x8d, 0x95, 0xe75, 0x133, wheelSetYPos);
  wheelsFollow(self, 0x91, 0x785, 0x180d, 0x133, wheelSetYPos);
}
PCREG(529660, ucTankUpdateWheelsYPos);

// 0x526cf0 CUnderCarriageCar::UpdateWheelsYPos(): front dampers +0xbd to front wheels +0x7ad (stride 0x163,
// 0x52a220), rear dampers +0x435 to wheels +0xd39 (stride 0x133, CWheel::SetYPos).
static void THISCALL ucCarUpdateWheelsYPos(u8 *self) {
  wheelsFollow(self, 0x8c, 0xbd, 0x7ad, 0x163, frontWheelSetYPos);
  wheelsFollow(self, 0x90, 0x435, 0xd39, 0x133, wheelSetYPos);
}
PCREG(526cf0, ucCarUpdateWheelsYPos);
