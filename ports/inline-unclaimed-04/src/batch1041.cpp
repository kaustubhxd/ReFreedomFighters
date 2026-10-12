// batch1041.cpp - unclaimed-04 batch 41 (docs/20-unclaimed-04.md): 0x44c530, thiscall, one stack argument a (ret 4).
#include "ff.h"

extern "C" void __attribute__((stdcall)) ext_610100(u32 a);             // hooked by address in the spec (GUESS)
extern "C" void THISCALL ext_4e12e0(void *self, u32 *v, u32 one);      // thiscall, self = a; writes *v (GUESS)
extern "C" void THISCALL ext_4e1b30(void *self);                       // hooked by address in the spec (GUESS)

// 0x44c530
static void THISCALL unk44c530(u8 *self, u32 a) {
  ext_610100(a);
  u32 v = a;
  ext_4e12e0((void *)a, &v, 1);
  // the byte is 1 only for v == 1 (0 and other values store 0); then 0x4e1b30 runs on every path, with ecx = a
  self[0x18] = (v == 1) ? 1 : 0;
  ext_4e1b30((void *)a);
}
PCREG(44c530, unk44c530);
