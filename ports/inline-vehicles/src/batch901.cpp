// batch901.cpp - vehicles thread, batch 901: undercarriage impacts (CUnderCarriageCar/Tank::ReceiveImpact),
// CDamper::DoBump and CUnderCarriageTank::GetMatPos.
#include "ff.h"

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);  // distance between two points (float in st0)
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);   // mcpy: copy a 3x3 matrix (9 floats)

// 0x516040 CDamper::DoBump(float): a bump of strength f kicks the damper: +0x55 += 5f and +0x41 += 10f
// (0x679544 = 5.0).
static void THISCALL damperDoBump(u8 *self, float f) {
  __m128 a = _mm_mul_ss(_mm_set_ss(f), _mm_set_ss(5.0f));
  __m128 b = _mm_add_ss(a, a);
  a = _mm_add_ss(a, _mm_load_ss((float *)(self + 0x55)));
  b = _mm_add_ss(b, _mm_load_ss((float *)(self + 0x41)));
  _mm_store_ss((float *)(self + 0x55), a);
  _mm_store_ss((float *)(self + 0x41), b);
}
PCREG(516040, damperDoBump);

// Each wheel's damper gets bump = force * min(1, 100 / distance(wheel point, impact point)).
// x87 divide (0x67cd40 = 100.0, divided by the distance in st0), then minss against 1.0 (0x678858).
static inline float bump(float force, const float *wheel, const float *at) {
  float d = ext_4e0870(wheel, at);
  volatile float q = (float)(100.0L / (long double)d);
  return _mm_cvtss_f32(_mm_mul_ss(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(q)), _mm_set_ss(force)));
}

// The first statement stores (engine +0x40) + 0x1c00 into +0x84 (car) / +0x85 (tank): the compiler kept an
// assignment-from-temporary self check against a stack slot, which can never be equal, so it is a plain store.
// 0x525e20 CUnderCarriageCar::ReceiveImpact(float, const float[2]&): front wheels (count +0x8c, points from +0x7c9
// stride 0x163, dampers from +0xbd stride 0xde), then rear wheels (count +0x90, points +0xd55 stride 0x133,
// dampers +0x435 stride 0xde).
static void THISCALL ucCarReceiveImpact(u8 *self, float force, const float *at) {
  *(u32 *)(self + 0x84) = *(u32 *)(*(u8 **)0x70039c + 0x40) + 0x1c00;
  for (s32 i = 0; i < *(s32 *)(self + 0x8c); i++)
    damperDoBump(self + 0xbd + i * 0xde, bump(force, (float *)(self + 0x7c9 + i * 0x163), at));
  for (s32 i = 0; i < *(s32 *)(self + 0x90); i++)
    damperDoBump(self + 0x435 + i * 0xde, bump(force, (float *)(self + 0xd55 + i * 0x133), at));
}
PCREG(525e20, ucCarReceiveImpact);

// 0x5289d0 CUnderCarriageTank::ReceiveImpact: same with left/right track wheels: count +0x8d, points +0xe91
// stride 0x133, dampers +0x95; count +0x91, points +0x1829, dampers +0x785.
static void THISCALL ucTankReceiveImpact(u8 *self, float force, const float *at) {
  *(u32 *)(self + 0x85) = *(u32 *)(*(u8 **)0x70039c + 0x40) + 0x1c00;
  for (s32 i = 0; i < *(s32 *)(self + 0x8d); i++)
    damperDoBump(self + 0x95 + i * 0xde, bump(force, (float *)(self + 0xe91 + i * 0x133), at));
  for (s32 i = 0; i < *(s32 *)(self + 0x91); i++)
    damperDoBump(self + 0x785 + i * 0xde, bump(force, (float *)(self + 0x1829 + i * 0x133), at));
}
PCREG(5289d0, ucTankReceiveImpact);

// 0x525380 CUnderCarriageTank::GetMatPos(float[3][3]&, float[3]&): rotation from +0xc, position from +0.
static void THISCALL ucGetMatPos(u8 *self, float *mat, u32 *pos) {
  ext_4de420(mat, (float *)(self + 0xc));
  pos[0] = ((u32 *)self)[0];
  pos[1] = ((u32 *)self)[1];
  pos[2] = ((u32 *)self)[2];
}
PCREG(525380, ucGetMatPos);
