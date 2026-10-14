// batch1128.cpp - unclaimed-11 batch 29 (gap band): 0x5a45c0, GUESS.
#include "ff.h"

typedef u8(THISCALL *predFn)(void *self, u32 flag);

// 0x5a45c0, GUESS: if obj is nonnull and obj->vt[0x1e0](0x2003e8) is true, index = [obj+0x684]; index-1 in 0..3 gives
// this+0x99+16*index; otherwise null.
static u8 *THISCALL guessIndexedPointer(u8 *self, u8 *obj) {
  if (obj == nullptr) return nullptr;
  if (!((predFn)(*(void ***)obj)[0x1e0 / 4])(obj, 0x2003e8)) return nullptr;
  s32 index = *(s32 *)(obj + 0x684);
  if ((u32)(index - 1) <= 3u) return self + 0x99 + (index << 4);
  return nullptr;
}
PCREG(5a45c0, guessIndexedPointer);
