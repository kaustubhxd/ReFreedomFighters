// batch67551.cpp - cascade s6 batch 67551: 0x6553a0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)
#define G8(a) (*(volatile u8 *)(a))

// 0x6553a0, thiscall() plain ret (eax unused): reads the debug keys. With key 0x11 down (sys slot 0xe4) plus 0x21 the speed factor sys[0x1b40] becomes 10.0 (latched in 0x7f6414, back to 1.0 on release);
// with 0x11 plus 0x22 it becomes 0.1 (latched in 0x7f6415). Key presses (slot 0xe8): 0x38 toggles the byte sys[0x1aa3][0x79], 0x39 toggles bit 0 and 0x30 bit 1 of this[0x1157].
static void THISCALL fn6553a0(u8 *self) {
  u32 flags = D32(self, 0x1157);
  if ((u8)vcall<u32>(SYS, 0xe4, 0x11u) && (u8)vcall<u32>(SYS, 0xe4, 0x21u)) {
    if (!G8(0x7f6414)) {
      G8(0x7f6414) = 1;
      D32(SYS, 0x1b40) = 0x41200000u;
    }
  } else if (G8(0x7f6414)) {
    G8(0x7f6414) = 0;
    D32(SYS, 0x1b40) = 0x3f800000u;
  }
  if ((u8)vcall<u32>(SYS, 0xe4, 0x11u) && (u8)vcall<u32>(SYS, 0xe4, 0x22u)) {
    if (!G8(0x7f6415)) {
      G8(0x7f6415) = 1;
      D32(SYS, 0x1b40) = 0x3dcccccdu;
    }
  } else if (G8(0x7f6415)) {
    G8(0x7f6415) = 0;
    D32(SYS, 0x1b40) = 0x3f800000u;
  }
  if ((u8)vcall<u32>(SYS, 0xe8, 0x38u)) {
    u8 *p = *(u8 **)(SYS + 0x1aa3);
    p[0x79] = p[0x79] == 0;
  }
  if ((u8)vcall<u32>(SYS, 0xe8, 0x39u)) flags ^= 1;
  if ((u8)vcall<u32>(SYS, 0xe8, 0x30u)) flags ^= 2;
  D32(self, 0x1157) = flags;
}
PCREG(6553a0, fn6553a0);
