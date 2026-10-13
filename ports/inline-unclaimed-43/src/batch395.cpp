// batch395.cpp - 0x4c4e00 (core: ZAnimSequence::FrameUpdate, thiscall, no arguments). If byte [+0x69] is set:
// let x = float [+0x60] * float 0x67862c; d = dword [+0x65] - (int)x; if the engine (global 0x70039c) dword [+0x40] > d:
// call 0x4c5090(dword [+0x50], dword [+0x54]) (exe; stdcall, hooked by address in the spec, GUESS: body not ported),
// call vtable slot 0x68 with (0x10, 0) (thiscall, two stack arguments), and clear byte [+0x69].
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void STDCALL ext_4c5090(u32 a, u32 b);   // callee by address (hooked in the spec)

static void THISCALL animFrameUpdate(u8 *self) {
  if (self[0x69] == 0)
    return;
  float x = *(float *)(self + 0x60) * G(float, 0x67862c);
  u32 d = U32(self, 0x65) - (u32)(s32)x;
  u8 *eng = (u8 *)(unsigned long)G(u32, 0x70039c);
  if ((s32)U32(eng, 0x40) > (s32)d) {
    ext_4c5090(U32(self, 0x50), U32(self, 0x54));
    vcall<void>((void *)self, 0x68, 0x10u, 0u);
    self[0x69] = 0;
  }
}
PCREG(4c4e00, animFrameUpdate);
