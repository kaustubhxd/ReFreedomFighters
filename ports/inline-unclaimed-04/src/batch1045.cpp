// batch1045.cpp - unclaimed-04 batch 45 (docs/20-unclaimed-04.md): 0x5f3370, thiscall, two stack arguments p and n (ret 8).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d22(u32 off, u32 p, u32 n);  // copy (p != 0), hooked (GUESS)
extern "C" void __attribute__((cdecl)) ext_634d10(u32 off, u32 zero, u32 n);  // copy (p == 0), hooked (GUESS)

// 0x5f3370
static void THISCALL unk5f3370(u8 *self, u32 p, u32 n) {
  u32 off = *(u32 *)(self + 8);
  if (off + n > *(u32 *)(self + 0xc)) {
    void (*cb)(void) = (void (*)(void)) * (u32 *)0x7003b0;
    cb();  // a null callback is an int3 assert in the exe (outside the contract)
  }
  off = *(u32 *)(self + 8);
  if (p != 0)
    ext_634d22(off, p, n);
  else
    ext_634d10(off, 0, n);
  *(u32 *)(self + 8) += n;
}
PCREG(5f3370, unk5f3370);
