// batch917.cpp - 0x45f3c0 [thiscall (ECX = this), one stack arg (a stream object), ret 4, returns al = 1]. Body read in full.
// The stream's slot +0x40 reads a dword into this+0x14. The stream's slot +0x40 reads a dword into the argument slot (L). If L is
// nonzero: this's slot +0x40 (no args), then the dword L goes to the object at this+0x10, offset +0x18. Returns 1.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x45f3c0 (no name in the map).
static bool THISCALL Read45f3c0(u8 *self, u8 *stream) {
  vcall<void>(stream, 0x40, (void *)(self + 0x14));
  u32 L = (u32)stream;             // [ebp+8] is overwritten by the next read
  vcall<void>(stream, 0x40, (void *)&L);
  if (L != 0) {
    vcall<void>(self, 0x40);
    U32(FP(self, 0x10), 0x18) = L;
  }
  return true;
}
PCREG(45f3c0, Read45f3c0);
