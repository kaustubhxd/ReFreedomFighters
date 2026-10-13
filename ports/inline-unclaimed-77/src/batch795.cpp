// batch795.cpp - unclaimed-77 claim 30 (docs/20-unclaimed-77.md): REFTAB::AddUnique(unsigned int) (medium). Thiscall, one argument, ret 4.
// The object's virtual slots 0x2c and 0x4 are stubbed in the harness (GUESS).
#include "ff.h"

// 0x4cd980, REFTAB::AddUnique(unsigned int) (medium): p = slot 0x2c(key); p != 0 gives p + 4; else slot 4(key).
static u32 THISCALL refTabAddUnique(u8 *self, u32 key) {
  void **vt = *(void ***)self;
  u32 p = ((u32 (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x2c)))(self, key);
  if (p != 0) {
    return p + 4;
  }
  vt = *(void ***)self;
  return ((u32 (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 4)))(self, key);
}
PCREG(4cd980, refTabAddUnique);
