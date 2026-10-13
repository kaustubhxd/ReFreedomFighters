// batch2495.cpp - decomp area 24, batch 2495 (residue 3, smallest first).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);            // __builtin_delete (cdecl, two arguments)
extern "C" void THISCALL ext_4cef90(void *self, void *arg);  // REFTAB::RunDelRef(RefRun*), thiscall, one argument (pops 4, assumed)

// 0x4cf070 (GUESS name, REFTAB element release). Argument: base at +0, index at +4, count at +8. For a positive count the element is at
// base (or, when index - this+0x18 is negative, at the base read through the first dword, with index this+0x10 - this+0x18) plus
// 4 * (offset + 4). Otherwise slot 0x78 of this gives the address of the element pointer. The block at the element is deleted (size 1),
// then RunDelRef on this with the argument. Returns void (ret 4).
static void THISCALL refTabRelease(u8 *self, u8 *arg) {
  u32 block;
  if (*(int *)(arg + 8) > 0) {
    u32 idx = *(u32 *)(arg + 4) - *(u32 *)(self + 0x18);
    u32 base = *(u32 *)arg;
    if ((int)idx < 0) {
      idx = *(u32 *)(self + 0x10) - *(u32 *)(self + 0x18);
      base = *(u32 *)base;
    }
    u32 addr = base + (idx + 4) * 4;
    block = *(u32 *)addr;
  } else {
    u32 p = vcall<u32>(self, 0x78, arg);
    block = *(u32 *)p;
  }
  ext_634273((void *)block, 1);
  ext_4cef90(self, arg);
}
PCREG(4cf070, refTabRelease);
