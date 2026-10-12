// batch2401.cpp - decomp area 24, batch 2401: ZActionControlMap::ModifyGameActions (0x5b3ef0), thiscall, plain ret.
// The map's fields (this offsets from the original): +0x5f a pointer to a player-state object (its +0x9e3 is a float
// stick value), +0x4c/+0x4d (mode dword at +0x4d), +0x55/+0x56 invert flags, +0x168, +0x169, +0x16d, +0x171..+0x174
// (stick bytes), +0x18b/+0x18f (stick x/y floats), +0x193/+0x197 (accumulated stick vector), and the byte flags
// +0x173 +0x189 +0x19f..+0x1a3 +0x1aa +0x1ab +0x1af +0x1b1 +0x1b3 +0x1b4 +0x1b6 +0x1bc +0x1bd +0x22f.
// The global sys object (0x70039c) gives the engine time at +0x40 and a mode byte at +0x6c.
// Helpers (exe, called through ext_): v2len (0x4dfda0, returns the 2D length in ST0 from ecx = vec) and the 2D
// normalise (0x4dff10, ecx = vec, returns ST0 = length or 0).
#include "ff.h"

extern "C" float THISCALL ext_4dfda0(float *v);   // v2len
extern "C" float THISCALL ext_4dff10(float *v);   // normalise 2D in place (ST0 result ignored)

static inline u8 *sys() { return G(u8 *, 0x70039c); }

static void THISCALL modifyGameActions(u8 *self) {
  u8 *edx = *(u8 **)(self + 0x5f);
  float s = *(float *)(edx + 0x9e3);
  bool inMain = true;                       // the jnp-to-else test: s == 0 (not NaN) takes the else branch
  if (s == 0.0f)
    inMain = false;
  if (inMain) {
    float t = s + 0.5f;
    s32 q = _mm_cvttss_si32(_mm_set_ss(t * 1024.0f));
    if (q >= (s32)*(u32 *)(sys() + 0x40))
      inMain = false;
  }
  if (inMain) {
    bool zero = self[0x1b4] || self[0x1b3] || self[0x1b1] || self[0x1bc] || self[0x189];
    if ((s8)self[0x1a0] > 0x3f || (s8)self[0x19f] > 0x3f || (s8)self[0x1a1] > 0x3f || (s8)self[0x1a2] > 0x3f)
      zero = true;
    if (zero)
      *(u32 *)(edx + 0x9e3) = 0;
  } else {
    self[0x1b1] &= (u8)~self[0x1a3];
  }
  u8 al = self[0x189];
  u8 cl = self[0x1bc];
  al |= cl;
  al = (u8)~al;
  al &= self[0x22f];
  self[0x1a3] &= al;
  if (sys()[0x6c] == 0 && *(u32 *)(self + 0x4d) == 3) {
    self[0x168] = 0;
    self[0x1bd] = 0;
  }
  float x1 = *(float *)(self + 0x18f);
  float x2 = *(float *)(self + 0x18b);
  u32 signBit = 0x80000000u;
  if (self[0x55] != 0)
    x1 = __builtin_bit_cast(float, __builtin_bit_cast(u32, x1) ^ signBit);
  if (self[0x56] != 0)
    x2 = __builtin_bit_cast(float, __builtin_bit_cast(u32, x2) ^ signBit);
  if (sys()[0x6c] == 0 && cl != 0) {
    if (self[0x1b6] == 0) {
      self[0x1b6] = 1;
      *(u32 *)(self + 0x193) = 0;
      *(u32 *)(self + 0x197) = 0;
    }
    float v2 = x2 * 5.0f + *(float *)(self + 0x193);
    float v1 = x1 * 5.0f + *(float *)(self + 0x197);
    *(float *)(self + 0x193) = v2;
    *(float *)(self + 0x197) = v1;
    float len = ext_4dfda0((float *)(self + 0x193));
    if (len > 1.0f)
      (void)ext_4dff10((float *)(self + 0x193));
    *(u32 *)(self + 0x171) = 0;
    float vx = *(float *)(self + 0x193);
    if (vx > 0.5f) {
      self[0x174] = 0x7f;
    } else if (-0.5f > vx) {
      self[0x173] = 0x7f;
    }
    float vy = *(float *)(self + 0x197);
    if (vy > 0.5f) {
      self[0x172] = 0x7f;
    } else if (-0.5f > vy) {
      self[0x171] = 0x7f;
    }
    *(u32 *)(self + 0x18b) = 0;
    *(u32 *)(self + 0x18f) = 0;
  } else {
    self[0x1b6] = 0;
  }
  if (self[0x4c] != 0) {
    self[0x1a3] = 0;
    *(u16 *)(self + 0x169) = 0;
    self[0x16d] = 0;
    *(u32 *)(self + 0x1ab) = 0;
    *(u16 *)(self + 0x1af) = 0;
    *(u32 *)(self + 0x1a6) = 0;
    self[0x1aa] = 0;
  }
}
PCREG(5b3ef0, modifyGameActions);
