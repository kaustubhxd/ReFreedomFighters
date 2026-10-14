// batch5713.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 13: ZSoundStream::DataNeeded() (0x54e1c0, medium name), thiscall,
// no arguments, returns al. If the dword this+0x5b is 0: return 1 and clear byte +0x1d when +0x1d is set, else return 0. Otherwise:
// return 0 if byte +0x57 or byte +0x1d is 0; else clear byte +0x1d and return 1.
#include "ff.h"

static u8 THISCALL soundStreamDataNeeded(u8 *self) {
  if (*(u32 *)(self + 0x5b) == 0) {
    if (self[0x1d]) {
      self[0x1d] = 0;
      return 1;
    }
    return 0;
  }
  if (self[0x57] == 0) return 0;
  if (self[0x1d] == 0) return 0;
  self[0x1d] = 0;
  return 1;
}
PCREG(54e1c0, soundStreamDataNeeded);
