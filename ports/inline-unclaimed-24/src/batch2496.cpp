// batch2496.cpp - decomp area 24, batch 2496 (residue 3, smallest first).
#include "ff.h"

typedef void (*cdecl0)(void);  // global function pointer, called with no arguments

// 0x57ebb0 (GUESS name). Argument object: slot 0x3c with the system table's slot 0x4c value of this+8, then for eight dwords at
// this+0xc onward: slot 0x3c with the table's slot 0x4c value of each. Thiscall, ret 4.
static void THISCALL pairedTableCalls(u8 *self, u8 *arg) {
  u32 r = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, *(u32 *)(self + 8));
  vcall<void>(arg, 0x3c, r);
  u32 *p = (u32 *)(self + 0xc);
  for (int n = 8; n != 0; n--) {
    u32 r2 = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, *p);
    vcall<void>(arg, 0x3c, r2);
    p++;
  }
}
PCREG(57ebb0, pairedTableCalls);

// 0x4b0f30 (GUESS name). Clears bit 0x40 of +4; calls the global at 0x7003b0 with no arguments; slot 0x98 of this with 0; then on the
// argument: slot 0x48 with this+0x48, slot 0x58 with this+0x50, slot 0x68 with this+0x6c. Returns AL = 1, ret 4.
static u8 THISCALL serializeFields(u8 *self, u8 *arg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  cdecl0 fn = (cdecl0)G(void *, 0x7003b0);
  fn();
  vcall<void>(self, 0x98, 0u);
  vcall<void>(arg, 0x48, self + 0x48);
  vcall<void>(arg, 0x58, self + 0x50);
  vcall<void>(arg, 0x68, self + 0x6c);
  return 1;
}
PCREG(4b0f30, serializeFields);
