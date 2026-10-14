// u69_15.cpp - area 69, group 15 (unclaimed-69 thread).
#include "ff.h"

// 0x658fd0, thiscall with one stack arg (ret 4), no callees. Stores the arg at self+0x44 and sets (non-zero arg) or clears (zero arg) bit 0x10 of the byte at self+0x3c.
static void THISCALL setPtrFlag10(u8 *self, u32 v) {
  *(u32 *)(self + 0x44) = v;
  if (v)
    self[0x3c] |= 0x10;
  else
    self[0x3c] &= 0xef;
}
PCREG(658fd0, setPtrFlag10);
