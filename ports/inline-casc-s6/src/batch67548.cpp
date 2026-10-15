// batch67548.cpp - cascade s6 batch 67548: 0x4c2280.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4c2280, thiscall(stream) ret 4, returns 1: loads the object's fields from a stream object: clears flag 0x40 of this[4], then reads one destination address per call: slot 0x48 (+0x48),
// slot 0x44 (+0x4c, +0x4e), slot 0x68 (+0x50..+0x54), slot 0x50 (+0x55, +0x59 ... +0x6d in steps of 4) and slot 0x68 (+0x71, +0x72, +0x73).
static u32 THISCALL fn4c2280(u8 *self, u8 *st) {
  D32(self, 4) &= 0xffffffbfu;
  vcall<void>(st, 0x48, (u32)(self + 0x48));
  vcall<void>(st, 0x44, (u32)(self + 0x4c));
  vcall<void>(st, 0x44, (u32)(self + 0x4e));
  for (u32 o = 0x50; o <= 0x54; o++) vcall<void>(st, 0x68, (u32)(self + o));
  for (u32 o = 0x55; o <= 0x6d; o += 4) vcall<void>(st, 0x50, (u32)(self + o));
  for (u32 o = 0x71; o <= 0x73; o++) vcall<void>(st, 0x68, (u32)(self + o));
  return 1;
}
PCREG(4c2280, fn4c2280);
