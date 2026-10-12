// batch1926.cpp - unclaimed-66 batch 26: the release-global family, gap band 0x501000-0x521000 (GUESS names).
// Each: if the global is set, vtable +4 of the object is called with argument 0 (the callee pops it); then the global is cleared.
#include "ff.h"

static void releaseGlobal(u32 addr) {
  u8 *obj = *(u8 **)addr;
  if (obj) vcall<void>(obj, 4, (u32)0);
  *(u32 *)addr = 0;
}

// 0x50b4b0, GUESS FUN_0050b4b0 (global 0x7011fc).
static void THISCALL releaseA() { releaseGlobal(0x7011fc); }
PCREG(50b4b0, releaseA);

// 0x510b70, GUESS FUN_00510b70 (global 0x70139c).
static void THISCALL releaseB() { releaseGlobal(0x70139c); }
PCREG(510b70, releaseB);

// 0x511700, GUESS FUN_00511700 (global 0x7014b4).
static void THISCALL releaseC() { releaseGlobal(0x7014b4); }
PCREG(511700, releaseC);
