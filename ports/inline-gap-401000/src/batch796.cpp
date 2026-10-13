// batch796.cpp - gap band batch 796 (docs/20-gap-band-401000.md): 0x420f40, thiscall, void. The float result is single precision (SSE).
#include "ff.h"
typedef int i32;

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

static void THISCALL fn420f40(u8 *self) {
  u32 L4 = 0;
  u32 L8 = 0;
  vc1(self, 0x160, (u32)&L4);
  u32 *esi = (u32 *)(self + 0x40);
  u32 *ebx = (u32 *)(self + 0x44);
  if (ebx != esi) *ebx = *esi;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  const bool al = (vc0(obj, 0xb8) & 0xff) != 0;
  if (!al && esi != (u32 *)&L8) *esi = *(const u32 *)(self + 0x4c) + L4;
  const i32 d = (i32)*esi - (i32)*ebx;
  const float r = (float)d * G(float, 0x6785e4);
  *(float *)(self + 0x48) = r;
}

PCREG(420f40, fn420f40);
