#include "ff.h"
// batch1505.cpp - unclaimed-15 claim 5 (docs/20-unclaimed-15.md): CEntityTracker::UpdateEntity(ZLNKOBJ*) (0x5c0a20).
// Name from the GC name map (naming only). Thiscall, one argument, ret 4.
// The array at +0x50 holds entries of 0x17 bytes; the count at +0x54 is signed. The key is each entry's first dword.
// If the key is found at index i, the argument becomes the entry's address and the call tail-jumps to vtable slot +0x98;
// its return value is the function's. If not found, the function returns the count (0 when the count is not positive).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

// 0x5c0a20, CEntityTracker::UpdateEntity(ZLNKOBJ*) (high).
static u32 THISCALL entityTrackerUpdateEntity(u8 *self, u32 key) {
  s32 count = *(s32 *)(self + 0x54);
  s32 i = 0;
  if (count > 0) {
    u8 *base = *(u8 **)(self + 0x50);
    for (; i < count; ++i) {
      u8 *entry = base + i * 0x17;
      if (*(u32 *)entry == key) {
        u32 vt = *(u32 *)self;
        return ((Slot1)*(u32 *)(vt + 0x98))(self, (u32)entry);
      }
    }
  }
  return (u32)i;
}
PCREG(5c0a20, entityTrackerUpdateEntity);
