// batch2511.cpp - decomp area 24, batch 2511. 0x4fca70 (GUESS CMAINCAMERACONTROL free-camera key movement), thiscall, no args, plain ret.
// Reads the camera pose (object at this+8: position via 0x4db500, 3x3 matrix via 0x4db2a0), accumulates two ramp values
// (0x700e38 / 0x700e3c, clamped at 2.0) scaled into step sizes SA / SB, polls keys through the system object's slot 0xd4
// (0x12/0x11/0x10 modifiers, 0x25-0x28 arrows) into a six-float delta d, then (if any delta is non-zero or NaN) scales d[0..2] by 4,
// rotates it by the matrix, adds it to the position, rotates the three matrix columns about d[3..5] (0x4e0be0) and calls this->slot 0x74
// (matrix, position). With no key and no delta it zeroes the ramp values; with no non-zero delta after a key press it just returns.
// The stack cookie check (0x633654) has no effect when the cookie is intact and is not reproduced.
#include "ff.h"

extern "C" void THISCALL ext_4db500(void *self, float *out);   // copies this+0x24..0x2c, ret 4
extern "C" void THISCALL ext_4db2a0(void *self, float *out);   // copies 0x24 bytes, ret 4
extern "C" void THISCALL ext_4e0d00(float *v, float s);        // v *= s, ret 4
extern "C" void FASTCALL ext_4419f0(float *v, float *m);       // v = v * m
extern "C" void FASTCALL ext_441940(float *a, float *b);       // a += b
extern "C" void FASTCALL ext_4e0be0(float *v, float *axis);    // rotate

static inline bool key(u32 k) {
  u8 *ctx = G(u8 *, 0x70039c);
  typedef u8(THISCALL * fn)(void *, u32);
  return (*(fn **)ctx)[0xd4 / 4](ctx, k) != 0;
}

static void THISCALL freeCamMove(u8 *self) {
  float pos[3], m[9];
  float d[6] = {0, 0, 0, 0, 0, 0};
  void *obj = *(void **)(self + 8);
  ext_4db500(obj, pos);
  ext_4db2a0(obj, m);
  u8 *ctx = G(u8 *, 0x70039c);
  float lim = G(float, 0x680a60);
  float dt = *(float *)(ctx + 0x20);
  float t = dt * G(float, 0x67da1c);
  float x1 = t + G(float, 0x700e38);
  float x0 = t + G(float, 0x700e3c);
  G(float, 0x700e38) = x1;
  G(float, 0x700e3c) = x0;
  if (x1 > lim) { x1 = lim; G(float, 0x700e38) = x1; }
  if (x0 > lim) { x0 = lim; G(float, 0x700e3c) = x0; }
  x1 = x1 * G(float, 0x680a68);
  x0 = x0 * G(float, 0x680a5c);
  x1 = x1 * G(float, 0x67da18);
  dt = dt * G(float, 0x67da24);
  x1 = x1 / G(float, 0x67da2c);
  x0 = x0 * G(float, 0x679544);
  x1 = x1 * dt;
  x0 = x0 * dt;
  const float SA = x1, SB = x0;
  bool bl = false;

  if (!key(0x12) && !key(0x11) && !key(0x10)) {
    if (key(0x26)) { bl = true; d[2] = d[2] + SB; }
    if (key(0x28)) { bl = true; d[2] = d[2] - SB; }
    if (key(0x25)) { bl = true; d[4] = d[4] + SA; }
    if (key(0x27)) { bl = true; d[4] = d[4] - SA; }
  }
  if (key(0x11)) {
    if (key(0x10)) goto no_more;
    if (key(0x26)) { bl = true; d[1] = d[1] - SB; }
    if (key(0x28)) { bl = true; d[1] = d[1] + SB; }
    if (key(0x25)) { bl = true; d[0] = d[0] - SB; }
    if (!key(0x27)) goto no_more;
    d[0] = d[0] + SB;
    goto have_delta;
  } else {
    if (!key(0x10)) goto no_more;
    if (key(0x26)) { bl = true; d[3] = d[3] + SA; }
    if (key(0x28)) { bl = true; d[3] = d[3] - SA; }
    if (key(0x25)) { bl = true; d[5] = d[5] + SA; }
    if (!key(0x27)) goto no_more;
    d[5] = d[5] - SA;
    goto have_delta;
  }
no_more:
  if (!bl) {
    G(u32, 0x700e38) = 0;
    G(u32, 0x700e3c) = 0;
    return;
  }
have_delta:
  if (d[0] == 0 && d[1] == 0 && d[2] == 0 && d[3] == 0 && d[4] == 0 && d[5] == 0) return;
  {
    float v1[3] = {0, 0, 0}, v2[3] = {0, 0, 0}, v3[3] = {0, 0, 0};
    ext_4e0d00(d, 4.0f);
    ext_4419f0(d, m);
    ext_441940(pos, d);
    v1[0] = m[6]; v1[1] = m[3]; v1[2] = m[0];
    v2[0] = m[7]; v2[1] = m[4]; v2[2] = m[1];
    v3[0] = m[8]; v3[1] = m[5]; v3[2] = m[2];
    if (!(d[3] == 0 && d[4] == 0 && d[5] == 0)) {
      ext_4e0be0(v1, d + 3);
      ext_4e0be0(v2, d + 3);
      ext_4e0be0(v3, d + 3);
    }
    m[6] = v1[0]; m[3] = v1[1]; m[0] = v1[2];
    m[7] = v2[0]; m[4] = v2[1]; m[1] = v2[2];
    m[8] = v3[0]; m[5] = v3[1]; m[2] = v3[2];
    typedef void(THISCALL * fn)(void *, float *, float *);
    (*(fn **)self)[0x74 / 4](self, m, pos);
  }
}
PCREG(4fca70, freeCamMove);
