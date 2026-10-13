#include "ff.h"
// batch3534.cpp - gap band claim 34 (docs/20-gap-band-561000.md): 0x561f10 (GUESS name). Stdcall, one arg (ret 4), no this.
// R = [mgr+0x9b] vtable +0x134() (stubbed); then R vtable +0x68 with (0x6a66d8, arg low byte == 0, 0).

typedef u32(THISCALL *TU0)(u8 *self);
typedef void(THISCALL *TU3)(u8 *self, u32 a0, u32 a1, u32 a2);

void STDCALL gapStatic561f10(u32 flag) {
  u8 *M = *(u8 **)(*(u32 *)0x70039c + 0x9b);
  u8 *R = (u8 *)((TU0)*(u32 *)(*(u32 *)M + 0x134))(M);
  u32 cond = ((u8)flag == 0) ? 1u : 0u;
  ((TU3)*(u32 *)(*(u32 *)R + 0x68))(R, 0x6a66d8, cond, 0);
}
PCREG(561f10, gapStatic561f10);
