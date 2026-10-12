#include "ff.h"
// batch8018.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

extern "C" void THISCALL ext_4690b0(u8 *self);   // bare ret (arity 0)

// 0x48cee0 (GUESS): thiscall, no arguments. Calls slot +0x40 of the global at 0x70038c, then tail-jumps to 0x4690b0 with
// this+8 as this when it is nonzero.
static void THISCALL f_48cee0(u8 *self) {
  vcall<void>(G(u8 *, 0x70038c), 0x40);
  u8 *c = *(u8 **)(self + 0x8);
  if (c != 0) ext_4690b0(c);
}
PCREG(48cee0, f_48cee0);

// 0x48cf00 (GUESS): thiscall, no arguments. Calls slot +0x44 of the global at 0x70038c, then tail-jumps to 0x4690b0 with
// this+8 as this when it is nonzero.
static void THISCALL f_48cf00(u8 *self) {
  vcall<void>(G(u8 *, 0x70038c), 0x44);
  u8 *c = *(u8 **)(self + 0x8);
  if (c != 0) ext_4690b0(c);
}
PCREG(48cf00, f_48cf00);
