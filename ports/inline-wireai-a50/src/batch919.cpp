// batch919.cpp - 0x4fa230 [thiscall (ECX = this), one stack arg (a stream object), ret 4, returns al]. Body read in full.
// First 0x440e10 (thiscall: this, stream; verified in batch918; stood in here). If false, return 0. Otherwise the stream's slots +0x40
// with pointers into this (+0x60, +0x64, +0x6c, +0x70, +0x78, +0x7c, +0x80, +0x84, +0x74), +0x48 (+0x68), +0x68 (+0x88), then slot +0x48
// on a local dword whose value is stored at this+0x8b. Returns 1.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_440e10(void *self, void *stream);   // stood in here (verified separately in batch918)

// 0x4fa230 (no name in the map).
static bool THISCALL Read4fa230(u8 *self, u8 *stream) {
  if (!ext_440e10(self, stream)) return false;
  vcall<void>(stream, 0x40, (void *)(self + 0x60));
  vcall<void>(stream, 0x40, (void *)(self + 0x64));
  vcall<void>(stream, 0x48, (void *)(self + 0x68));
  vcall<void>(stream, 0x40, (void *)(self + 0x6c));
  vcall<void>(stream, 0x40, (void *)(self + 0x70));
  vcall<void>(stream, 0x40, (void *)(self + 0x78));
  vcall<void>(stream, 0x40, (void *)(self + 0x7c));
  vcall<void>(stream, 0x40, (void *)(self + 0x80));
  vcall<void>(stream, 0x40, (void *)(self + 0x84));
  vcall<void>(stream, 0x68, (void *)(self + 0x88));
  vcall<void>(stream, 0x40, (void *)(self + 0x74));
  u32 L = 0;
  vcall<void>(stream, 0x48, (void *)&L);
  U32(self, 0x8b) = L;
  return true;
}
PCREG(4fa230, Read4fa230);
