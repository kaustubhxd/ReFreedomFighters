// batch5733.cpp - unclaimed-57, band batch 33 (name GUESS): 0x5d8440, thiscall, no args, ret. Stack-address compare (TAGGED
// STACK-COMPARE): slot = this+0xb3; if slot equals the address of this function's frame slot (ebp-4), return. Otherwise
// dword slot = (dword engine+0x40) + 0x800, where engine = dword 0x70039c; then byte (dword 0x7003a0) + 0x79 = 0.
// The frame slot is taken from __builtin_frame_address (the same ebp the original sees when both runs are called at the same stack depth).
// The equal branch is NOT exercised by the spec: a pointer into the harness stack cannot be set up in the object, so only the
// not-equal path is compared; the compare itself is in the port.
#include "ff.h"

#define G(T, addr) (*(T *)(addr))

static void THISCALL unnamed5d8440(u8 *self) {
  u8 *slot = self + 0xb3;
  u8 *frame = (u8 *)__builtin_frame_address(0) - 4;  // TAGGED STACK-COMPARE
  if (slot == frame) return;
  u8 *engine = G(u8 *, 0x70039c);
  *(u32 *)slot = *(u32 *)(engine + 0x40) + 0x800;
  u8 *p = G(u8 *, 0x7003a0);
  p[0x79] = 0;
}
PCREG(5d8440, unnamed5d8440);
