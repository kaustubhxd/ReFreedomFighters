// batch1959.cpp - unclaimed-66 batches 69 to 71 (gap band, GUESS names). Three lazy-init singleton getters of one shape (cdecl, no arguments,
// returns eax): if the global is set, return vtable +0x24 of it; else p = 0x41e290(0xc) (allocator, hooked by address); if p: [p+4] = 1,
// [p+8] = 0, [p] = the vtable constant; the global = p; the init (THISCALL, ECX = p, no arguments; hooked by address); return the global.
//   0x50d880: global 0x7012cc, vtable 0x69d3b8, init 0x50d6c0.
//   0x510f30: global 0x70139c, vtable 0x69dad4, init 0x510ae0.
//   0x5117d0: global 0x7014b4, vtable 0x69e044, init 0x511670.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);           // cdecl, one argument (hooked in the spec)
extern "C" void THISCALL ext_50d6c0(u8 *self);   // THISCALL, no arguments, plain ret (hooked in the spec)
extern "C" void THISCALL ext_510ae0(u8 *self);   // THISCALL, no arguments, plain ret (hooked in the spec)
extern "C" void THISCALL ext_511670(u8 *self);   // THISCALL, no arguments, plain ret (hooked in the spec)

// 0x50d880, GUESS FUN_0050d880 (batch 69).
static u32 gapGet50d880(void) {
  u8 *obj = *(u8 **)0x7012cc;
  if (obj) return vcall<u32>(obj, 0x24);
  u8 *p = (u8 *)ext_41e290(0xc);
  if (p) {
    *(u32 *)(p + 4) = 1;
    *(u32 *)(p + 8) = 0;
    *(u32 *)p = 0x69d3b8;
  }
  *(u32 *)0x7012cc = (u32)p;
  ext_50d6c0(p);
  return *(u32 *)0x7012cc;
}
PCREG(50d880, gapGet50d880);

// 0x510f30, GUESS FUN_00510f30 (batch 70).
static u32 gapGet510f30(void) {
  u8 *obj = *(u8 **)0x70139c;
  if (obj) return vcall<u32>(obj, 0x24);
  u8 *p = (u8 *)ext_41e290(0xc);
  if (p) {
    *(u32 *)(p + 4) = 1;
    *(u32 *)(p + 8) = 0;
    *(u32 *)p = 0x69dad4;
  }
  *(u32 *)0x70139c = (u32)p;
  ext_510ae0(p);
  return *(u32 *)0x70139c;
}
PCREG(510f30, gapGet510f30);

// 0x5117d0, GUESS FUN_005117d0 (batch 71).
static u32 gapGet5117d0(void) {
  u8 *obj = *(u8 **)0x7014b4;
  if (obj) return vcall<u32>(obj, 0x24);
  u8 *p = (u8 *)ext_41e290(0xc);
  if (p) {
    *(u32 *)(p + 4) = 1;
    *(u32 *)(p + 8) = 0;
    *(u32 *)p = 0x69e044;
  }
  *(u32 *)0x7014b4 = (u32)p;
  ext_511670(p);
  return *(u32 *)0x7014b4;
}
PCREG(5117d0, gapGet5117d0);
