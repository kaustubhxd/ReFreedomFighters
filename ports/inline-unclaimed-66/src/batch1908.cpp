// batch1908.cpp - unclaimed-66 batch 8: three slice-5 leaves (names GUESS; bodies from the bytes).
#include "ff.h"

// 0x4eb3d0, GUESS FUN_004eb3d0: [this] = 0x697738; then a jump to the no-op ret at 0x4690b0 (ECX is not used there).
static void THISCALL leaf4eb3d0(u8 *self) {
  *(u32 *)self = 0x697738;
}
PCREG(4eb3d0, leaf4eb3d0);

// 0x61bc50, GUESS FUN_0061bc50: cdecl(obj, a): ECX = obj, pushes a, calls vtable +8 of obj (callee pops a). Plain ret (cdecl).
static void leaf61bc50(u8 *obj, u32 a) {
  vcall<void>(obj, 8, a);
}
PCREG(61bc50, leaf61bc50);

// 0x4aff10, GUESS FUN_004aff10: clears bit 6 of this+4; calls vtable +0x84 of this (no argument); returns AL = 1 (ret 4).
static u8 THISCALL leaf4aff10(u8 *self, u32 unused) {
  (void)unused;
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(self, 0x84);
  return 1;
}
PCREG(4aff10, leaf4aff10);
