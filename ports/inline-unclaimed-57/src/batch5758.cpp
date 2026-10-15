// batch5758.cpp - unclaimed-57, band batch 58 (name GUESS): 0x5c4580, thiscall, no args, ret. SEH-TAG: the original installs an exception frame on
// fs:[0] with a cookie and a state dword; the harness never raises an exception and those writes are not observed, so the frame is NOT reproduced.
// Observable behaviour: vtable 0x6b4088; 0x41e2c0(dword this+0x4c) (cdecl, one argument; hooked and logged); dword this+0x44 = 0; dword this+0x30 = 0;
// vtable 0x686874; engine (global 0x70039c, +0x9b) ->vt[+0x34](this) (thiscall, one argument; stubbed).
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *SlotEng)(u8 *self, u8 *a);

extern "C" void ext_41e2c0(u8 *p);  // cdecl, one argument (hooked and logged in the spec)

static void THISCALL unnamed5c4580(u8 *self) {
  *(u32 *)self = 0x6b4088;
  ext_41e2c0(*(u8 **)(self + 0x4c));
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *engine = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(engine + 0x9b);
  ((SlotEng)VT(obj)[0x34 / 4])(obj, self);
}
PCREG(5c4580, unnamed5c4580);
