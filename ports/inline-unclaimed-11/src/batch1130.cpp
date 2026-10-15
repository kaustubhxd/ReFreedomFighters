// batch1130.cpp - unclaimed-11 batch 31 (gap band): 0x5bf9b0, GUESS (one argument, ret 4, returns true).
#include "ff.h"

extern "C" void STDCALL ext_6352f0(u32 *dbread);   // ZEventBase::GetInput stub (stdcall, one argument)
extern "C" void THISCALL ext_5bf940(void *self);   // stubbed in the harness (no arguments)

typedef void(THISCALL *vfn1)(void *self, u32 *p);

static bool THISCALL guessPredicate5bf9b0(u8 *self, u8 *arg) {
  u32 local = 0;
  self[4] &= ~0x40;
  ext_6352f0(&local);
  ((vfn1)(*(void ***)self)[0x84 / 4])(self, &local);
  ext_5bf940(self);
  ((vfn1)(*(void ***)arg)[0x48 / 4])(arg, (u32 *)(self + 0x59));
  ((vfn1)(*(void ***)arg)[0x48 / 4])(arg, (u32 *)(self + 0x6a));
  ((vfn1)(*(void ***)arg)[0x68 / 4])(arg, (u32 *)(self + 0x72));
  return true;
}
PCREG(5bf9b0, guessPredicate5bf9b0);
