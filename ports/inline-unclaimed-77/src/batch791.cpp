// batch791.cpp - unclaimed-77 claims 21 and 22 (docs/20-unclaimed-77.md): two functions (medium names). The CRT delete 0x634273 (cdecl)
// is stubbed in the harness (GUESS), and so is the native function pointer at the global 0x6763ac (cdecl, one argument).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // CRT delete, cdecl, stubbed (GUESS)

// 0x5fa600, ScriptHostInterface_t::~ScriptHostInterface_t() (medium): vtable 0x6b91dc; global 0x724270 = 0; delete (this, 4) when bit 0 is set.
static u8 *THISCALL scriptHostInterfaceDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b91dcu;
  G(u32, 0x724270) = 0;
  if ((u8)flags & 1) {
    ext_634273(self, 4u);
  }
  return self;
}
PCREG(5fa600, scriptHostInterfaceDtor);

// 0x4d4a00, IOFSPhysicalAccess_t::nativeClose(ImpNativeFd_t*) (medium): r = native(*fd) through the pointer at 0x6763ac (cdecl);
// delete (fd, 4); returns r. Stdcall, one argument.
static u32 __attribute__((stdcall)) ioFsPhysicalAccessNativeClose(u32 *fd) {
  u32 h = *fd;
  u32 (*nat)(u32) = (u32 (*)(u32))G(u32, 0x6763ac);
  u32 r = nat(h);
  ext_634273(fd, 4u);
  return r;
}
PCREG(4d4a00, ioFsPhysicalAccessNativeClose);
