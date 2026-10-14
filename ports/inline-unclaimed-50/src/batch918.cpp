// batch918.cpp - 0x440e10 [thiscall (ECX = this), one stack arg (a stream object), ret 4, returns al]. Body read in full.
// First 0x45f3c0 (thiscall: this, stream; verified in batch917; stood in here). If it is false, return 0. Otherwise the stream's
// slots are called with pointers into this: +0x6c (this+0x18), +0x6c (+0x24), +0x40 (+0x30), +0x48 (+0x34), +0x48 (+0x38),
// +0x50 (+0x3c), +0x50 (+0x40), +0x50 (+0x58). Returns 1.
#include "ff.h"

extern "C" bool THISCALL ext_45f3c0(void *self, void *stream);   // stood in here (verified separately in batch917)

// 0x440e10 (no name in the map).
static bool THISCALL Read440e10(u8 *self, u8 *stream) {
  if (!ext_45f3c0(self, stream)) return false;
  vcall<void>(stream, 0x6c, (void *)(self + 0x18));
  vcall<void>(stream, 0x6c, (void *)(self + 0x24));
  vcall<void>(stream, 0x40, (void *)(self + 0x30));
  vcall<void>(stream, 0x48, (void *)(self + 0x34));
  vcall<void>(stream, 0x48, (void *)(self + 0x38));
  vcall<void>(stream, 0x50, (void *)(self + 0x3c));
  vcall<void>(stream, 0x50, (void *)(self + 0x40));
  vcall<void>(stream, 0x50, (void *)(self + 0x58));
  return true;
}
PCREG(440e10, Read440e10);
