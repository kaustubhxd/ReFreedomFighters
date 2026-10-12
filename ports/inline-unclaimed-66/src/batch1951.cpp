// batch1951.cpp - unclaimed-66 batches 56 and 57 (gap band, GUESS names).
//   0x511410 (STDCALL, one argument x, ret 4): p0 = 0x5003d0(ECX = [x+4], 0); v = vtable +0x60 of the ZSysInterface child with *p0;
//       if v: 0x44b610(ECX = v) (THISCALL, no arguments), then 0x44b740(v) (cdecl, one argument). Helpers hooked by address in the spec.
//   0x519470 (THISCALL(this), one argument x, ret 4): p0 = 0x5003d0(ECX = [x+4], 0); a = 0x5122c0(ECX = [this+0x14], *p0) (STDCALL, one
//       argument: the low byte of the result is zero-extended); p1 = 0x5003d0(ECX = [x+8], 0); then 0x5002f0(ECX = p1, a).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec
extern "C" void THISCALL ext_44b610(u8 *self);                // no arguments (hooked in the spec)
extern "C" void ext_44b740(u32 v);                            // cdecl, one argument (hooked in the spec)
extern "C" u8 THISCALL ext_5122c0(u8 *obj, u32 v);            // ECX = obj, one argument, ret 4 (hooked in the spec)
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);         // ret 4 (one argument), hooked in the spec

// 0x511410, GUESS FUN_00511410 (batch 56).
static void STDCALL gapFn511410(u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *v = (u8 *)vcall<u32>(child, 0x60, *(u32 *)p0);
  if (v) {
    ext_44b610(v);
    ext_44b740((u32)v);
  }
}
PCREG(511410, gapFn511410);

// 0x519470, GUESS FUN_00519470 (batch 57).
static void THISCALL gapFn519470(u8 *self, u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u32 a = (u32)ext_5122c0(*(u8 **)(self + 0x14), *(u32 *)p0);
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 8), 0);
  ext_5002f0(p1, a);
}
PCREG(519470, gapFn519470);
