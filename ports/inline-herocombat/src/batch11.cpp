// batch11.cpp - first-level functions, inline session batch 11 (Haiku, overnight).
#include "ff.h"

// 0x62f5a0, cdecl (plain ret, the caller pops): appends a 16-bit value to a byte buffer, high byte first. The buffer
// is at this+8 and the write position at this+0x14 (advanced by 2). Name unknown.
static void writeU16BE(u8 *self, u32 value) {
  u8 *buf = *(u8 **)(self + 8);
  buf[*(u32 *)(self + 0x14)] = (u8)(value >> 8);
  *(u32 *)(self + 0x14) += 1;
  buf[*(u32 *)(self + 0x14)] = (u8)value;
  *(u32 *)(self + 0x14) += 1;
}
PCREG(62f5a0, writeU16BE);

// 0x4caf50, thiscall (ret 4): copies ten dwords from src+0x68 .. src+0x8c to this+0x68 .. this+0x8c. Name unknown.
static void THISCALL copyTail10(u8 *self, u8 *src) {
  for (u32 off = 0x68; off <= 0x8c; off += 4)
    *(u32 *)(self + off) = *(u32 *)(src + off);
}
PCREG(4caf50, copyTail10);

// 0x4dd060, thiscall (ret 4): copies three dwords from src to this+0x40 .. this+0x48, then raises any of the first
// two and the third to the exe constant at 0x679540 (0x39000000) when they are below it (a NaN never changes).
// Sets bit 0x100000 in this+0x3c between the second and third check. Name unknown.
static void THISCALL clampFloor3(u8 *self, u8 *src) {
  float k = G(float, 0x679540);
  *(u32 *)(self + 0x40) = *(u32 *)(src + 0);
  *(u32 *)(self + 0x44) = *(u32 *)(src + 4);
  *(u32 *)(self + 0x48) = *(u32 *)(src + 8);
  if (k > *(float *)(self + 0x40))
    *(u32 *)(self + 0x40) = 0x39000000u;
  if (k > *(float *)(self + 0x44))
    *(u32 *)(self + 0x44) = 0x39000000u;
  *(u32 *)(self + 0x3c) |= 0x100000u;
  if (k > *(float *)(self + 0x48))
    *(u32 *)(self + 0x48) = 0x39000000u;
}
PCREG(4dd060, clampFloor3);

// 0x522e80, thiscall (no stack args, returns this): sets a vtable word 0x6a0750 and resets a block of fields, with 1.0f
// (0x3f800000) in several float slots. Name unknown.
static u32 THISCALL initVec(u8 *self) {
  *(u32 *)self = 0x6a0750u;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x42) = 0x3f800000u;
  *(u32 *)(self + 0x20) = 0x3f800000u;
  *(u32 *)(self + 0x63) = 0;
  *(u32 *)(self + 0x35) = 0;
  *(u32 *)(self + 0x4b) = 0;
  *(u32 *)(self + 0x4f) = 0;
  *(u32 *)(self + 0x3d) = 0;
  *(u32 *)(self + 0x39) = 0;
  self[0x34] = 1;
  self[0x46] = 0;
  *(u32 *)(self + 0x47) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x2c) = 0x3f800000u;
  *(u32 *)(self + 0x5b) = 0x3f800000u;
  *(u32 *)(self + 0x5f) = 0x3f800000u;
  *(u32 *)(self + 0x57) = 0x3f800000u;
  *(u32 *)(self + 8) = 0x3f800000u;
  *(u32 *)(self + 0xc) = 0x3f800000u;
  *(u32 *)(self + 0x10) = 0x3f800000u;
  return (u32)self;
}
PCREG(522e80, initVec);
