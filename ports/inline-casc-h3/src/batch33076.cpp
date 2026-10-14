// batch33076.cpp - h3 () batch 33076: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_51c470(u8 *self);
extern "C" void THISCALL ext_523b90(u8 *self, u32 a, float f);     // ret 8

// 0x64fbf0: thiscall float: [this+0xb9] * 6.0 (x87 fld/fmul: the product is formed in double precision and left in st0)
static double THISCALL fn64fbf0(u8 *self) { return (double)*(float *)(self + 0xb9) * (double)6.0f; }
PCREG(64fbf0, fn64fbf0);

// 0x51c540: thiscall float: 0x51c470(this); returns [this+0x597] (fld)
static float THISCALL fn51c540(u8 *self) {
  ext_51c470(self);
  return *(float *)(self + 0x597);
}
PCREG(51c540, fn51c540);

// 0x527250: thiscall(float a) ret 4: [this+8] = a
static void THISCALL fn527250(u8 *self, float a) { *(float *)(self + 8) = a; }
PCREG(527250, fn527250);

// 0x4dce50: thiscall(float a) ret 4: [this+0x3c] |= 0x100000; [this+0x4c] = a
static void THISCALL fn4dce50(u8 *self, float a) {
  *(u32 *)(self + 0x3c) |= 0x100000;
  *(float *)(self + 0x4c) = a;
}
PCREG(4dce50, fn4dce50);

// 0x51cef0: thiscall(a, float f) ret 8: [this+0x4a5] = a (raw dword), [this+0x4a9] = f
static void THISCALL fn51cef0(u8 *self, u32 a, float f) {
  *(u32 *)(self + 0x4a5) = a;
  *(float *)(self + 0x4a9) = f;
}
PCREG(51cef0, fn51cef0);

// 0x539c70: thiscall(int a) ret 4: [this+0x51b1] = (float)a * 0.01f
static void THISCALL fn539c70(u8 *self, s32 a) { *(float *)(self + 0x51b1) = (float)a * 0.01f; }
PCREG(539c70, fn539c70);

// 0x5d0c60: thiscall(int a) ret 4: byte [this+0xb2f]=1; [this+0xb2b] = (float)a / -127.0f
static void THISCALL fn5d0c60(u8 *self, s32 a) {
  self[0xb2f] = 1;
  *(float *)(self + 0xb2b) = (float)a / -127.0f;
}
PCREG(5d0c60, fn5d0c60);

// 0x514410: thiscall(a, float f) ret 8: 0x523b90([this+0x5c], a, f)
static void THISCALL fn514410(u8 *self, u32 a, float f) { ext_523b90(*(u8 **)(self + 0x5c), a, f); }
PCREG(514410, fn514410);
