// batch30.cpp - gameplay leaves (walk, shoot, throw, mounted trees), inline session batch 30 (Haiku, evening).
#include "ff.h"

// 0x4667e0, thiscall, one stack arg (out pointer), ret 4. Copies the 16 bytes at this+0x3d to out (an unaligned movups).
// Name ZTARGET::GetCallBack.
static void THISCALL getCallBack(u8 *self, u8 *out) {
  for (int i = 0; i < 16; i++)
    out[i] = self[0x3d + i];
}
PCREG(4667e0, getCallBack);

// 0x467aa0, thiscall, three stack args (a, b, c), ret 0xc. If a is null the dword at this+1 becomes 0x7fffffff, else nine
// dwords from a go to this+1 (mcpy, 36 bytes). Then if b is null the dword at +0x25 becomes 0x7fffffff, else three dwords from b
// go to +0x25, +0x29, +0x2d. The dword c goes to +0x39 in both cases. The mcpy store comes first, so its last dword (+0x25)
// is overwritten by the later store, in the original order. Name ZTARGET::SetMatPosGeom.
static void THISCALL setMatPosGeom(u8 *self, const u8 *a, const u8 *b, u32 c) {
  if (a == 0) {
    *(u32 *)(self + 1) = 0x7fffffffu;
  } else {
    for (int i = 0; i < 36; i++)
      self[1 + i] = a[i];
  }
  if (b == 0) {
    *(u32 *)(self + 0x25) = 0x7fffffffu;
  } else {
    *(u32 *)(self + 0x25) = *(const u32 *)(b + 0);
    *(u32 *)(self + 0x29) = *(const u32 *)(b + 4);
    *(u32 *)(self + 0x2d) = *(const u32 *)(b + 8);
  }
  *(u32 *)(self + 0x39) = c;
}
PCREG(467aa0, setMatPosGeom);

// 0x4e09e0, fastcall (out in ECX, a in EDX), plain ret. out[i] = -a[i] for three floats (xorps with the sign mask at 0x67af40).
static void FASTCALL vnegFrom(u32 *out, const u32 *a) {
  u32 m = G(u32, 0x67af40);
  out[0] = a[0] ^ m;
  out[1] = a[1] ^ m;
  out[2] = a[2] ^ m;
}
PCREG(4e09e0, vnegFrom);

// 0x4de7a0, thiscall, no args, plain ret. Resets the matrix-like block: 1.0 at +0x18, +0x10 and +0x8 (dword 0x3f800000 at
// +8 is the last store), zeros at +0x1c, +0x20, +0xc, +0x14, +0, +4.
static void THISCALL mreset(u8 *self) {
  *(u32 *)(self + 0x18) = 0x3f800000u;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0x3f800000u;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0) = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0x3f800000u;
}
PCREG(4de7a0, mreset);

// 0x594f10, thiscall, one byte stack arg (bool), ret 4. If the byte at this+0x669 differs from the argument, store the argument
// there, and when it is nonzero also set the byte at +0x66b to 1. Name ZFFHERO::SetHoldFire.
static void THISCALL setHoldFire(u8 *self, u8 on) {
  if (self[0x669] == on)
    return;
  self[0x669] = on;
  if (on != 0)
    self[0x66b] = 1;
}
PCREG(594f10, setHoldFire);
