// u69_25.cpp - area 69, group 25 (slice 8). Field ops on self, thiscall with one stack arg (ret 4), no callees.
#include "ff.h"

// ORs the dword at self+0x72 into the dword at self + 4*i + 0x8a (i is the stack arg).
static void THISCALL orInto5ad000(u8 *self, u32 i) {
  *(u32 *)((u32)self + i * 4 + 0x8a) |= *(u32 *)(self + 0x72);
}
PCREG(5ad000, orInto5ad000);

// Returns the old dword at self+4 and stores old + 4*n there.
static u32 THISCALL advance65ca00(u8 *self, u32 n) {
  u32 old = *(u32 *)(self + 4);
  *(u32 *)(self + 4) = old + n * 4;
  return old;
}
PCREG(65ca00, advance65ca00);

// Returns the old dword at self+0x5c and stores the arg there.
static u32 THISCALL swap5c650fc0(u8 *self, u32 v) {
  u32 prev = *(u32 *)(self + 0x5c);
  *(u32 *)(self + 0x5c) = v;
  return prev;
}
PCREG(650fc0, swap5c650fc0);
