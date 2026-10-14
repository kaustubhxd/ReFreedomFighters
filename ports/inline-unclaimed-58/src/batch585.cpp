// batch585.cpp - gameplay-CORE functions from decomp-pilot/core-todo/residue-17.txt (area 58).
#include "ff.h"

typedef int i32;
typedef signed char i8;

typedef u32(THISCALL *VtArgU32)(u8 *, u32);
typedef void(THISCALL *VtArgFloat)(u8 *, float);
typedef u32(THISCALL *VtArgTwo)(u8 *, u32, u32);

// 0x4e7110, ZRunParamAnim::Save(save) ret 4 (core list): save->vt[0x4c](save, float [this+0xb8]); save->vt[0x60](save,
// zero-extended byte [this+0xbc]); save->vt[0x4c](save, float [this+0xbd]). The result in eax is not part of the contract.
static void THISCALL saveAnim_4e7110(u8 *self, u8 *save) {
  VtArgFloat f4c = (VtArgFloat)(*(u32 *)(*(u32 *)save + 0x4c));
  f4c(save, *(float *)(self + 0xb8));
  VtArgU32 f60 = (VtArgU32)(*(u32 *)(*(u32 *)save + 0x60));
  f60(save, (u32)self[0xbc]);
  f4c = (VtArgFloat)(*(u32 *)(*(u32 *)save + 0x4c));
  f4c(save, *(float *)(self + 0xbd));
}
PCREG(4e7110, saveAnim_4e7110);

// 0x438110, ZInputActions::CheckActionDigital(const char* name, void* out) ret 8 (core list): r = this->vt[0x38](this, a1,
// a2). If the low byte of r is zero, return r. Otherwise v = this->vt[0xa4](this, a1); the result is |sext8(low byte of v)|
// in eax, with the low byte replaced by (|sext8| > 0x40). Name GUESS.
static u32 THISCALL checkActionDigital_438110(u8 *self, u32 a1, u32 a2) {
  VtArgTwo f38 = (VtArgTwo)(*(u32 *)(*(u32 *)self + 0x38));
  u32 r = f38(self, a1, a2);
  if ((u8)r == 0) return r;
  VtArgU32 fa4 = (VtArgU32)(*(u32 *)(*(u32 *)self + 0xa4));
  u32 v = fa4(self, a1);
  i32 low = (i8)(u8)v;
  i32 ab = low < 0 ? -low : low;
  return ((u32)ab & ~0xffu) | ((i32)ab > 0x40 ? 1u : 0u);
}
PCREG(438110, checkActionDigital_438110);
