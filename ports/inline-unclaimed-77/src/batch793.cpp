// batch793.cpp - unclaimed-77 claims 24 to 26 (docs/20-unclaimed-77.md). The function pointer at 0x676144, CRT 0x634d22 and 0x41e2c0 are
// stubbed in the harness (GUESS).
#include "ff.h"

// 0x549800, ZSynthGC::CmdFrameReady() (medium): r = fp(dword at 0x701b6c, 0) (stdcall); the low byte of eax becomes (r == 0x102), the upper
// bits stay as the callee left them (sete al).
static u32 THISCALL synthGCCmdFrameReady(u8 *self) {
  (void)self;
  u32 (__attribute__((stdcall)) *fp)(u32, u32) = (u32 (__attribute__((stdcall)) *)(u32, u32))G(u32, 0x676144);
  u32 r = fp(G(u32, 0x701b6c), 0u);
  return (r & 0xffffff00u) | (u32)(r == 0x102u);
}
PCREG(549800, synthGCCmdFrameReady);

extern "C" u32 ext_634d22(u32 a, u32 x, u32 b);   // CRT, cdecl, stubbed (GUESS)
extern "C" void ext_41e2c0(u32 a);                // cdecl, one argument, stubbed (GUESS)

// 0x54a200, GUESS FUN_54a200 (two arguments): calls the CRT with (a, this+0x231a, b); returns b.
static u32 THISCALL guessFun54a200(u8 *self, u32 a, u32 b) {
  ext_634d22(a, *(u32 *)(self + 0x231a), b);
  return b;
}
PCREG(54a200, guessFun54a200);

// 0x4d5540, GUESS FUN_4d5540 (no arguments): when this+8 is nonzero, frees it through 0x41e2c0 and zeroes this+8, this+4 and this.
static void THISCALL guessFun4d5540(u8 *self) {
  u32 p = *(u32 *)(self + 8);
  if (p != 0) {   // the exe's je to the pop skips the three stores when the field is zero
    ext_41e2c0(p);
    *(u32 *)(self + 8) = 0;
    *(u32 *)(self + 4) = 0;
    *(u32 *)self = 0;
  }
}
PCREG(4d5540, guessFun4d5540);
