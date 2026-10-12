// batch2452.cpp - decomp area 24, batch 2452 (gap band).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);       // __builtin_delete (cdecl)
extern "C" void THISCALL ext_43de70(void *self);     // tail target, plain ret

// 0x44ee20 (GUESS destructor body), thiscall, plain ret. Vtable 0x68110c, three deletes, then the tail jump.
static void THISCALL guessDtor44ee20(u8 *self) {
  *(u32 *)self = 0x68110cu;
  ext_634273(*(void **)(self + 0x8c), 2u);
  ext_634273(*(void **)(self + 0xac), 4u);
  ext_634273(*(void **)(self + 0xb0), 0x3cu);
  ext_43de70(self);
}
PCREG(44ee20, guessDtor44ee20);
