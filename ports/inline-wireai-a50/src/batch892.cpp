// batch892.cpp - gap band slice: 0x41e6d0 [~18 instr, thiscall, one stack arg (a key), ret 4, returns a dword]. A zero key gives
// zero; otherwise the key must pass the object's slot +0x14 (called with the key), and then the entry at (key & mask) in the
// array at this+0x28 is returned, where mask is the object's +0x10 word.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x41e6d0 (name GUESS "Lookup41e6d0").
static u32 THISCALL Lookup41e6d0(u8 *self, u32 key) {
  if (key == 0) return 0;
  u8 *obj = (u8 *)FP(self, 4);
  if (!vcall<bool>(obj, 0x14, key)) return 0;
  u32 mask = U32(FP(self, 4), 0x10);
  u32 *arr = (u32 *)FP(self, 0x28);
  return arr[mask & key];
}
PCREG(41e6d0, Lookup41e6d0);
