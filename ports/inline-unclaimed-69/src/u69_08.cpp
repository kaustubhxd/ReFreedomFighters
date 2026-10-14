// u69_08.cpp - area 69, group 8 (unclaimed-69 thread).
#include "ff.h"

// 0x4cdfd0, REFTAB::Exists(unsigned int*) (GC map high). thiscall, one stack arg (ret 4). Returns false for a null table.
// Otherwise slot 0x4c fills a local, then slot 0x64 gives the first value; while the value differs from the argument, slot
// 0x64 is called again, and the walk stops with false on a zero value. True when the argument is reached.
static bool THISCALL refTabExists(u8 *self, u32 key) {
  if (!self)
    return false;
  u32 local = 0;
  vcall<void>(self, 0x4c, &local);
  u32 value = vcall<u32>(self, 0x64, &local);
  if (value == 0)
    return false;
  while (value != key) {
    value = vcall<u32>(self, 0x64, &local);
    if (value == 0)
      return false;
  }
  return true;
}
PCREG(4cdfd0, refTabExists);
