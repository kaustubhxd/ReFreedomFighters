// u69_22.cpp - area 69, group 22 (slice 8). thiscall, no args, ret; clears bit 1 of the byte at self+5; no callees.
#include "ff.h"

static void THISCALL clearBit2At5(u8 *self) {
  self[5] &= 0xfd;
}
PCREG(613940, clearBit2At5);
