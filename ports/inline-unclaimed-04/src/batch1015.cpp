// batch1015.cpp - unclaimed-04 batch 16 (docs/20-unclaimed-04.md): four slice-3 leaves (GUESS labels).
#include "ff.h"

// 0x658130: al = 1; ret 8 (two stack arguments, not read).
static u8 THISCALL unk658130ReturnsTrue(u8 *self, u32 a, u32 b) {
  (void)self;
  (void)a;
  (void)b;
  return 1;
}
PCREG(658130, unk658130ReturnsTrue);

// 0x608130: store vtable 0x6bc88c at this.
static void THISCALL unk608130SetVtable(u8 *self) {
  *(u32 *)self = 0x6bc88c;
}
PCREG(608130, unk608130SetVtable);

// 0x658db0: return the dword at this+0x48, plus 0x20.
static u32 THISCALL unk658db0Get48Plus20(u8 *self) {
  return *(u32 *)(self + 0x48) + 0x20;
}
PCREG(658db0, unk658db0Get48Plus20);

// 0x499970: store vtable 0x68e9cc at this, then clear the dword at this+0xc.
static void THISCALL unk499970SetVtableClearC(u8 *self) {
  *(u32 *)self = 0x68e9cc;
  *(u32 *)(self + 0xc) = 0;
}
PCREG(499970, unk499970SetVtableClearC);
