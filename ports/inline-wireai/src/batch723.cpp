// batch723.cpp - soldier AI, batch 723 (2026-10-11): CCoverSpot::Init (0x5def10) and its ray helper 0x5ded60.
// Init(B, A, C, D, type, flags): the spot gets flags (+0xc), the position B (+0x10), the facing D copied to +0x1c and +0x28,
// and its type bit at +0x34 (type 0 -> bit 1, 1 -> bit 2, 2 -> bit 4). The lowest set bit then picks the branch:
//   bit 1 (type 0): ray tests at -67.5 and +67.5 degrees (flag 0) set bits 0x10 and 0x8; facing copy *= 1/cos(pi/4);
//                   return CheckShootOver(D, 50, 300).
//   bit 2 (type 1): facing copy *= 1/cos(pi/4); return CheckShootOver(D, 120, 300).
//   bit 4 (type 2): ray tests with flag 1; rotate the facing copy about Y by -pi/2 when bits 0x18 are 0x10, or +pi/2 when
//                   bit 0x10 is clear and bit 0x8 is set; facing copy *= 1/cos(pi/8); return (flags & 0x18) != 0.
// Ray helper 0x5ded60(C, scale, D, flag): ray from B along C*scale through the scene (slot 0x2e0); blocked -> false;
// flag 0 -> true; otherwise a second ray from B + C*scale along D*250; returns that ray unblocked.
// Vector helpers, the COLI constructor, rotation (vrot 0x4e0be0), cos and CheckShootOver run as exe code.
#include "ff.h"

struct ColiBuf { u8 b[0x90]; };   // COLI: start at 0, delta at 0xc, the flag byte at 0x6c

extern "C" void THISCALL ext_4e1b60(void *coli);                                     // COLI::COLI
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);            // vscalar: out = a * s (ecx, edx, stack)
extern "C" void FASTCALL ext_43e8e0(float *out, const float *a, const float *b);     // vadd: out = a + b
extern "C" void THISCALL ext_4e0d00(float *v, float s);                             // vscalar in place
extern "C" void FASTCALL ext_4e0be0(float *facing, const float *axis);               // vrot
extern "C" bool THISCALL ext_5deb20(void *spot, float *dir, float height, float length);   // CheckShootOver (batch 713)

static inline void *scene() { return *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc); }

static inline void copy3(float *d, const float *s) {
  d[0] = s[0];
  d[1] = s[1];
  d[2] = s[2];
}

// 0x5ded60 CCoverSpot ray helper (thiscall: this = the spot; args C, scale, D, flag).
static bool THISCALL spot_Ray(u8 *self, float *C, float scale, float *D, u8 flag) {
  ColiBuf c;
  ext_4e1b60(&c);
  float T[3];
  ext_4e0d40(T, C, scale);
  float *pos = (float *)(self + 0x10);
  copy3((float *)c.b, pos);            // start
  copy3((float *)(c.b + 0xc), T);      // delta
  c.b[0x6c] = 0;
  if (vcall<bool>(scene(), 0x2e0, &c, 0u, 1u, 0x200000u, 1u, 0u))
    return false;
  if (!flag)
    return true;
  float P2[3];
  ext_43e8e0(P2, pos, T);
  float F2[3];
  ext_4e0d40(F2, D, 250.0f);           // 0x437a0000
  copy3((float *)c.b, P2);
  copy3((float *)(c.b + 0xc), F2);
  c.b[0x6c] = 0;
  return !vcall<bool>(scene(), 0x2e0, &c, 0u, 1u, 0x200000u, 1u, 0u);
}
PCREG(5ded60, spot_Ray);

// 0x5def10 CCoverSpot::Init(float* B, float* A, float* C, float* D, eType type, uint flags) [low].
static bool THISCALL spot_Init(u8 *self, float *B, float *A, float *C, float *D, u32 type, u32 flags) {
  (void)A;
  *(u32 *)(self + 8) = 0;
  if (type == 0)
    *(u32 *)(self + 0x34) |= 1;
  else if (type == 1)
    *(u32 *)(self + 0x34) |= 2;
  else if (type == 2)
    *(u32 *)(self + 0x34) |= 4;
  else {
    void (*h)() = *(void (**)())0x7003b0;
    if (h)
      h();
    else
      __builtin_debugtrap();
  }
  *(u32 *)(self + 0xc) = flags;
  copy3((float *)(self + 0x10), B);
  copy3((float *)(self + 0x1c), D);
  copy3((float *)(self + 0x28), D);

  u32 f = *(u32 *)(self + 0x34);
  float *facing = (float *)(self + 0x1c);   // rotations and scales act on this copy
  if (f & 1) {                              // type 0
    if (spot_Ray(self, C, bitsf(0xc2870000u), D, 0))   // -67.5
      *(u32 *)(self + 0x34) |= 0x10;
    if (spot_Ray(self, C, bitsf(0x42870000u), D, 0))   // +67.5
      *(u32 *)(self + 0x34) |= 8;
    float s = (float)(1.0 / crt::cos(G(double, 0x6b72f0)));   // pi/4
    ext_4e0d00(facing, s);
    return ext_5deb20(self, D, bitsf(0x42480000u), bitsf(0x43960000u));   // 50, 300
  }
  if (f & 2) {                              // type 1
    float s = (float)(1.0 / crt::cos(G(double, 0x6b72f0)));   // pi/4
    ext_4e0d00(facing, s);
    return ext_5deb20(self, D, bitsf(0x42f00000u), bitsf(0x43960000u));   // 120, 300
  }
  // type 2 (bit 4)
  if (spot_Ray(self, C, bitsf(0xc2870000u), D, 1))
    *(u32 *)(self + 0x34) |= 0x10;
  if (spot_Ray(self, C, bitsf(0x42870000u), D, 1))
    *(u32 *)(self + 0x34) |= 8;
  u32 g = *(u32 *)(self + 0x34);
  float angle = 0.0f;
  bool rotate = false;
  if ((g & 0x18) == 0x10) {
    angle = bitsf(0xbec90fdbu);             // -pi/2
    rotate = true;
  } else if (!(g & 0x10) && (g & 0x8)) {
    angle = bitsf(0x3ec90fdbu);             // +pi/2
    rotate = true;
  }
  if (rotate) {
    float axis[3] = {0.0f, angle, 0.0f};
    ext_4e0be0(facing, axis);
  }
  float s = (float)(1.0 / crt::cos(G(double, 0x6b72e8)));   // pi/8
  ext_4e0d00(facing, s);
  return (*(u32 *)(self + 0x34) & 0x18) != 0;
}
PCREG(5def10, spot_Init);
