// batch1699.cpp - 0x47f6f0 (GUESS, residue 13 gap band, 2026-10-12). Destructor shape, thiscall, no arguments, plain ret. Sets
// the vtable 0x68af4c; when this+0x18 is set: r = manager slot 0x58(this+0x18); when r is set: r's slot 0x210(1). Then calls
// 0x43de70 (hooked; thiscall, no arguments; the ZGEOM destructor chain) and returns its eax. SEH frame not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_43de70[];
typedef u32(THISCALL *Tail0)(void *self);

u32 THISCALL GUESS_47f6f0(u8 *self) {
  u32 d = AT(u32, self, 0x18);
  AT(u32, self, 0) = 0x68af4cu;
  if (d) {
    u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
    u32 r = vcall<u32>(mgr, 0x58, d);
    if (r) vcall<void>((void *)r, 0x210, (u32)1);
  }
  return ((Tail0)(void *)ext_43de70)(self);
}
PCREG(47f6f0, GUESS_47f6f0);
