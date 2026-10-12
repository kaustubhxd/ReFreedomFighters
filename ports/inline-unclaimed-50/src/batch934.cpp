// batch934.cpp - 0x483f20 ZPlayer::Load(ZLoadGame*) [thiscall (ECX = this), one stack arg (stream), ret 4, returns al]. Body read in full
// (2026-10-12). Gate 0x474770 (thiscall: this, stream; stood in). If false, return 0. Otherwise the stream's slots (the stream is ECX for each):
// +0x40 -> this+0x413; +0x48 -> +0x417; +0x68 -> +0x42c; +0x6c -> +0x445; +0x50 -> +0x596; +0x74 -> +0x59a; +0x6c -> +0x5be; +0x74 -> +0x4f5;
// +0x6c -> +0x519; +0x40 -> +0x5ca; +0x74 -> +0x5ce; +0x6c -> +0x5f2; +0x68 -> +0x5fe, +0x5ff, +0x601, +0x600; +0x48 -> +0x602, +0x606, +0x60a;
// +0x40 -> +0x60e; +0x50 -> +0x4dd. Then the dwords 0x420c0000, 0x42c80000, 0x420c0000 go to +0x439, +0x43d, +0x441. This's slot +0x628 (no args).
// Then for i = 1..count (count = dword at +0x459, only when count >= 1): entry = dword at +0x461 + 4*(i-1); if nonzero, entry's slot +0x38 with
// the stream. Finally the dword at +0x424 = 0, the byte at +0x412 = 1, return 1. The stack cookie is not part of this body.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_474770(void *self, void *stream);   // stood in (its body is not read)

// 0x483f20 (name in the map: ZPlayer::Load(ZLoadGame*)).
static bool THISCALL Load483f20(u8 *self, u8 *stream) {
  if (!ext_474770(self, stream)) return false;
  vcall<void>(stream, 0x40, (void *)(self + 0x413));
  vcall<void>(stream, 0x48, (void *)(self + 0x417));
  vcall<void>(stream, 0x68, (void *)(self + 0x42c));
  vcall<void>(stream, 0x6c, (void *)(self + 0x445));
  vcall<void>(stream, 0x50, (void *)(self + 0x596));
  vcall<void>(stream, 0x74, (void *)(self + 0x59a));
  vcall<void>(stream, 0x6c, (void *)(self + 0x5be));
  vcall<void>(stream, 0x74, (void *)(self + 0x4f5));
  vcall<void>(stream, 0x6c, (void *)(self + 0x519));
  vcall<void>(stream, 0x40, (void *)(self + 0x5ca));
  vcall<void>(stream, 0x74, (void *)(self + 0x5ce));
  vcall<void>(stream, 0x6c, (void *)(self + 0x5f2));
  vcall<void>(stream, 0x68, (void *)(self + 0x5fe));
  vcall<void>(stream, 0x68, (void *)(self + 0x5ff));
  vcall<void>(stream, 0x68, (void *)(self + 0x601));
  vcall<void>(stream, 0x68, (void *)(self + 0x600));
  vcall<void>(stream, 0x48, (void *)(self + 0x602));
  vcall<void>(stream, 0x48, (void *)(self + 0x606));
  vcall<void>(stream, 0x48, (void *)(self + 0x60a));
  vcall<void>(stream, 0x40, (void *)(self + 0x60e));
  vcall<void>(stream, 0x50, (void *)(self + 0x4dd));
  U32(self, 0x439) = 0x420c0000u;
  U32(self, 0x43d) = 0x42c80000u;
  U32(self, 0x441) = 0x420c0000u;
  vcall<void>(self, 0x628);
  u32 count = U32(self, 0x459);
  if (count >= 1) {
    u32 i = 1;
    do {
      u8 *entry = (u8 *)FP(self, 0x461 + 4 * (i - 1));
      if (entry) vcall<void>(entry, 0x38, (void *)stream);
      i++;
    } while (i <= count);
  }
  U32(self, 0x424) = 0;
  U8(self, 0x412) = 1;
  return true;
}
PCREG(483f20, Load483f20);
