// batch4012.cpp - area 70 (residue 9), batch 4012: 0x5be810, a visibility test of a four-corner quad against two
// rotated planes (names GUESS). Callees 0x591ae0 (lazy cache), 0x4e0be0 (rotation, batch 4011) and 0x43e960 (point
// transform) run as original code; the vtable call on the object at +0x44 (slot 0x80) is stubbed in the spec.
#include "ff.h"

extern "C" u8 *THISCALL ext_591ae0(u8 *self);                        // exe: lazy cache of [this+0x85e]
extern "C" void FASTCALL ext_4e0be0(float *dst, const float *src);    // exe: rotation by sin/cos of src
extern "C" void FASTCALL ext_43e960(float *p, const float *m);        // exe: point transform in place

static inline float rdf(const u8 *base, u32 off) { return *(const float *)(base + off); }

// 0x5be810 (name GUESS): thiscall, one stack argument (box, a pointer to floats at +0x11, +0x19, +0x21), ret 4, returns a
// bool in AL. The object at [this+0x91a] is the receiver of 0x591ae0; the vector and the 4x3 matrix come back from its
// +0x44 object's slot 0x80. Two rotated copies of that vector, A and B, are built with the constant angle -pi/4 and +pi/4
// (bit patterns 0xbf490fdb and 0x3f490fdb); the four corners (x from +0x11 or +0x15, y from +0x19, z from +0x21 or +0x25)
// are transformed and tested against both planes. Returns true as soon as corners are on the positive side of both.
static u8 THISCALL quadVisible(u8 *self, const u8 *box) {
  u8 *obj = *(u8 **)(self + 0x91a);
  if (!obj) return 1;
  u8 *o2 = ext_591ae0(obj);
  float v[3];
  float m[12];
  // slot 0x80 on the object at [o2+0x44]: arg1 = vector out, arg2 = matrix out
  vcall<void>(*(void **)(o2 + 0x44), 0x80, v, m);
  float A[3] = {v[0], v[1], v[2]};
  float B[3] = {v[0], v[1], v[2]};
  static const u32 kNegQuarterPi = 0xbf490fdb, kPosQuarterPi = 0x3f490fdb;
  float src[3] = {0.0f, 0.0f, 0.0f};
  float negA, posA;
  __builtin_memcpy(&negA, &kNegQuarterPi, 4);
  __builtin_memcpy(&posA, &kPosQuarterPi, 4);
  src[1] = negA;
  ext_4e0be0(A, src);
  src[0] = 0.0f;
  src[1] = posA;
  src[2] = 0.0f;
  ext_4e0be0(B, src);
  A[1] = 0.0f;   // the exe zeroes the y component of both rotated vectors before the loop ([ebp-0x24], [ebp-0x18])
  B[1] = 0.0f;

  static const int ia[4] = {0, 0, 1, 1};
  static const int ib[4] = {0, 1, 0, 1};
  u8 bh = 0, bl = 0;
  for (int k = 0; k < 4; k++) {
    float p[3];
    p[0] = rdf(box, 0x11 + 4 * ib[k]);
    p[1] = rdf(box, 0x19);
    p[2] = rdf(box, 0x21 + 4 * ia[k]);
    ext_43e960(p, m);
    float x = p[0], y = p[1], z = p[2];
    if (!bh) {
      float dotA = ((A[0] * x) + (y * A[1])) + (A[2] * z);
      if (dotA > 0.0f) {
        if (bl) return 1;
        bh = 1;
      }
    }
    if (!bl) {
      float dotB = ((B[0] * x) + (y * B[1])) + (B[2] * z);
      if (dotB > 0.0f) {
        if (bh) return 1;
        bl = 1;
      }
    }
  }
  return 0;
}
PCREG(5be810, quadVisible);
