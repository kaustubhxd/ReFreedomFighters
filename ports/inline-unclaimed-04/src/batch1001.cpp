// batch1001.cpp - unclaimed-04 batch 1 (docs/20-unclaimed-04.md): eight leaf accessors.
// Every function is thiscall (this in ECX) and does exactly what the PC bytes do. GC names are naming only.
#include "ff.h"

// 0x438790, no GC name (owner unknown): decrements the dword at this+0x120c, returns. void, ret 0.
static void THISCALL unk438790DecDword120c(u8 *self) {
  *(u32 *)(self + 0x120c) -= 1;
}
PCREG(438790, unk438790DecDword120c);

// 0x647170, no GC name (owner unknown): if the dword at this+0x291 is nonzero, returns the byte at (pointer + 0x15);
// otherwise returns 0. The result is in al.
static u8 THISCALL unk647170ByteViaPtr291(u8 *self) {
  u32 p = *(u32 *)(self + 0x291);
  if (p == 0) return 0;
  return *(u8 *)(p + 0x15);
}
PCREG(647170, unk647170ByteViaPtr291);

// 0x647190, no GC name (owner unknown): returns the byte at this+0x295 in al.
static u8 THISCALL unk647190Byte295(u8 *self) {
  return self[0x295];
}
PCREG(647190, unk647190Byte295);

// 0x4fc680, CMAINCAMERACONTROL::GetOldCam() (low): returns the dword at this+0x74 in eax.
static u32 THISCALL cmainCameraControlGetOldCam(u8 *self) {
  return *(u32 *)(self + 0x74);
}
PCREG(4fc680, cmainCameraControlGetOldCam);

// 0x4fdd10, CMAINCAMERACONTROL::ToggleFreeCam() (low, GUESS: the name says toggle, the body only sets): stores 1 in the
// byte at this+0x69. void, ret 0.
static void THISCALL cmainCameraControlToggleFreeCam(u8 *self) {
  self[0x69] = 1;
}
PCREG(4fdd10, cmainCameraControlToggleFreeCam);

// 0x5231b0, CMoveAlongPath::DirFactor() const (low): loads the float at this+0x20 onto the FPU stack (st0).
static float THISCALL moveAlongPathDirFactor(u8 *self) {
  return *(float *)(self + 0x20);
}
PCREG(5231b0, moveAlongPathDirFactor);

// 0x523460, CMoveAlongPath::GetPath() (low): returns the dword at this+0x4b in eax.
static u32 THISCALL moveAlongPathGetPath(u8 *self) {
  return *(u32 *)(self + 0x4b);
}
PCREG(523460, moveAlongPathGetPath);

// 0x523980, CMoveAlongPath::PathLength() const (low): loads the float at this+0x53 onto the FPU stack (st0).
static float THISCALL moveAlongPathPathLength(u8 *self) {
  return *(float *)(self + 0x53);
}
PCREG(523980, moveAlongPathPathLength);
