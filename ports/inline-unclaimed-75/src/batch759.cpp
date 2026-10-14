// batch759.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

typedef int i32;

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 w);            // original accessor, one stack word, ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);           // original setter, one stack word, ret 4 (stores a)
extern "C" void THISCALL ext_5057e0(u8 *self, u32 a, u32 b);    // original, two stack words, ret 8

typedef u32(THISCALL *VtSix)(u8 *, u32, u32, u32, u32, u32, u32);   // render vt[0x50]: six stack words (ret 0x18)

// 0x505490, thiscall(arg) ret 4 (GUESS name). r = 5003d0(ecx = [arg+4], 0); edi = [r] (dword). If edi > 0, val =
// this->vt[0x50](this, [render obj + 0x44] + edi, 1, 0, -1.0f, 0, 1.0f); else 5057e0(this, 0x69ce60, edi) and val = 0. Then
// 5002f0(ecx = 5003d0(ecx = [arg+8], 0), val). The value left on the stack by 5003d0 is 5002f0's argument.
static void THISCALL setFromAccessor_505490(u8 *self, u8 *arg) {
  u8 *r = ext_5003d0(*(u8 **)(arg + 4), 0u);
  i32 edi = (i32)*(u32 *)r;
  u32 val;
  if (edi > 0) {
    u8 *rm = *(u8 **)0x70039cu;
    u8 *obj = *(u8 **)(rm + 0x9b);
    u32 ptr = *(u32 *)(obj + 0x44) + (u32)edi;
    VtSix f50 = (VtSix)(*(u32 *)(*(u32 *)self + 0x50));
    val = f50(self, ptr, 1u, 0u, 0xbf800000u, 0u, 0x3f800000u);
  } else {
    ext_5057e0(self, 0x69ce60u, (u32)edi);
    val = 0;
  }
  u8 *r2 = ext_5003d0(*(u8 **)(arg + 8), 0u);
  ext_5002f0(r2, val);
}
PCREG(505490, setFromAccessor_505490);
