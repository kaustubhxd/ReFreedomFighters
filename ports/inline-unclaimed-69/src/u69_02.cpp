// u69_02.cpp - area 69, group 2 (unclaimed-69 thread). Names: GUESS (no GC match).
#include "ff.h"

extern "C" void THISCALL ext_655a70(void *self);  // base constructor body: stores its vtable 0x6c3be4 (original code, slice 3)

// 0x656e10, unnamed constructor body (GUESS): stores the vtable 0x6c3e28, then tail-jumps to the base constructor body at
// 0x655a70, which stores its own vtable (0x6c3be4) over it. Final vtable: 0x6c3be4.
static void THISCALL ctorStoreVtableThenBase(u8 *self) {
  *(u32 *)self = 0x6c3e28u;
  ext_655a70(self);
}
PCREG(656e10, ctorStoreVtableThenBase);
