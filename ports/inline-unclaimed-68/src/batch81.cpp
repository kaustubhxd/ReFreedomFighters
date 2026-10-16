// batch81.cpp - unclaimed-68 batch 81 (slice 7). Names GUESS (FUN_addr).
#include "ff.h"

typedef void(__cdecl *CrtDelete)(u8 *ptr, u32 size);
typedef void(THISCALL *TailCall)(u8 *self);

// 0x636430: destructor. Thiscall, no args, ret 0.
// Sets two vtables (0x6c2080, 0x6c1fec). Conditionally calls CRT delete at +0x36 (size 1) and +0x2d (size 4).
// Tail jumps to exe code at 0x6363a0.
static void THISCALL g636430(u8 *self) {
  if (*(u8 *)(self + 0x3a)) {
    ((CrtDelete)G(u32, 0x634273))(*(u8 **)(self + 0x36), 1);
  }
  *(u32 *)self = 0x6c2080u;

  if (*(u8 *)(self + 0x31)) {
    ((CrtDelete)G(u32, 0x634273))(*(u8 **)(self + 0x2d), 4);
  }
  *(u32 *)self = 0x6c1fec;

  // Tail jump to exe 0x6363a0 (hooked by address)
  ((TailCall)G(u32, 0x6363a0))(self);
}
PCREG(636430, g636430);
