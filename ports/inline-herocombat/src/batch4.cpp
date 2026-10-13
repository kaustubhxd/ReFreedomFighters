// batch4.cpp - first-level functions, inline session batch 4 (Haiku, 2026-10-09 evening).
// Names marked "guessed" come from the body only.
#include "ff.h"

// 0x45efc0, stdcall (ret 0x10): out[i] = (b[i] - a[i]) * t + a[i], one float32 step each. Name guessed (lerp3).
static void STDCALL lerp3(float *out, const float *a, const float *b, float t) {
  out[0] = (b[0] - a[0]) * t + a[0];
  out[1] = (b[1] - a[1]) * t + a[1];
  out[2] = (b[2] - a[2]) * t + a[2];
}
PCREG(45efc0, lerp3);

// 0x4418f0, thiscall (ret 4): stores v[0] at this+0x3c and v[1] at this+0x40 (bitwise), then sets bit 0x200 of
// this+0x30 unless both values compare equal to 0.0 (NaN counts as not equal, so it sets the bit).
static void THISCALL setRange2(u8 *self, const u32 *v) {
  *(u32 *)(self + 0x3c) = v[0];
  float x = bitsf(*(u32 *)(self + 0x3c));
  float y = bitsf(v[1]);
  *(u32 *)(self + 0x40) = v[1];
  u32 flags = *(u32 *)(self + 0x30);
  if (!(x == 0.0f && y == 0.0f))
    flags |= 0x200;
  else
    flags &= ~0x200u;
  *(u32 *)(self + 0x30) = flags;
}
PCREG(4418f0, setRange2);

// 0x47c4e0, thiscall (ret 8): sets this+0x726 to 1, copies 3 dwords from a to this+0x660 and 3 from b to this+0x66c.
// Class name unknown.
static void THISCALL copyTwoVec3(u8 *self, const u32 *a, const u32 *b) {
  *(u8 *)(self + 0x726) = 1;
  *(u32 *)(self + 0x660) = a[0];
  *(u32 *)(self + 0x664) = a[1];
  *(u32 *)(self + 0x668) = a[2];
  *(u32 *)(self + 0x66c) = b[0];
  *(u32 *)(self + 0x670) = b[1];
  *(u32 *)(self + 0x674) = b[2];
}
PCREG(47c4e0, copyTwoVec3);

// 0x4ccbe0, thiscall (ret 8): constructor of a 2D table of rows x cols (cols = max(n, 1), rows = m + 1).
// Writes vtable 0x695734 at +0, zeroes +4, +8, +0x14, and sets +0xc = cols, +0x10 = cols * rows, +0x18 = rows.
// Returns this. Class name unknown.
static u32 *THISCALL initTable(u32 *self, s32 n, s32 m) {
  s32 cols = n >= 1 ? n : 1;
  u32 rows = (u32)m + 1;
  self[0] = 0x695734;
  self[5] = 0;
  self[6] = rows;
  self[3] = (u32)cols;
  self[4] = (u32)cols * rows;
  self[1] = 0;
  self[2] = 0;
  return self;
}
PCREG(4ccbe0, initTable);
