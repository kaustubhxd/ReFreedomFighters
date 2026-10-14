// batch1706.cpp - four unported functions in the area-13 band (2026-10-12, standing assignment). GUESS names.
// 0x64f850: virtual tail: obj = this+0xbd; jump to obj's vslot 0x4c (no arguments). Port: return vcall(obj, 0x4c).
// 0x4ce850: size = (this+0x10)*4 + 0x10; returns 0x41e290(size) (cdecl, hooked).
// 0x607910: calls 0x504880 (ZRenderBaseDll::Init, hooked; no arguments), then this's vslot 0x9c(1); returns its eax.
// 0x57c1d0: one stack argument (a DBREAD reader); this+0x180 = DBREAD::operator unsigned int(reader) (0x4e5e60, hooked).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_41e290[], ext_504880[], ext_4e5e60[];
typedef u32(*NewFn)(u32 size);
typedef void(THISCALL *Void0)(void *self);
typedef u32(THISCALL *U32Op)(void *reader);

u32 THISCALL GUESS_64f850(u8 *self) {
  void *obj = AT(void *, self, 0xbd);
  return vcall<u32>(obj, 0x4c);
}
PCREG(64f850, GUESS_64f850);

u32 THISCALL GUESS_4ce850(u8 *self) {
  u32 size = AT(u32, self, 0x10) * 4 + 0x10;
  return ((NewFn)(void *)ext_41e290)(size);
}
PCREG(4ce850, GUESS_4ce850);

u32 THISCALL GUESS_607910(u8 *self) {
  ((Void0)(void *)ext_504880)(self);
  return vcall<u32>(self, 0x9c, (u32)1);
}
PCREG(607910, GUESS_607910);

void THISCALL GUESS_57c1d0(u8 *self, u8 *reader) {
  AT(u32, self, 0x180) = ((U32Op)(void *)ext_4e5e60)(reader);
}
PCREG(57c1d0, GUESS_57c1d0);
