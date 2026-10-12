// batch1921.cpp - unclaimed-66 batch 21: GUESS FUN_005002d0. p = the allocator 0x41e290(0x34) (cdecl, hooked by address in the spec);
// if p is 0 the result is 0; else the function tail-jumps to 0x4ff7b0 with ECX = p (a no-argument thiscall, exe code), which
// returns the result. Cdecl with no arguments.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);
extern "C" u32 THISCALL ext_4ff7b0(void *);

// 0x5002d0, GUESS FUN_005002d0.
static u32 allocAndConstruct() {
  void *p = ext_41e290(0x34);
  if (p == 0) return 0;
  return ext_4ff7b0(p);
}
PCREG(5002d0, allocAndConstruct);
