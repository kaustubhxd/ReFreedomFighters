// batch1134.cpp - collision thread, batch 1134 (gap-list row, name GUESS): 0x5eef00, a dispatcher: slot 8 of [this+4] and of
// [this+8], then a tail jump to slot 8 of [this+0xc] (its EAX is the result).
#include "ff.h"

// 0x5eef00 (name GUESS): thiscall, no arguments, plain ret.
static u32 THISCALL dispatch5eef00(u8 *self) {
  vcall<void>(*(void **)(self + 4), 8);
  vcall<void>(*(void **)(self + 8), 8);
  return vcall<u32>(*(void **)(self + 0xc), 8);
}
PCREG(5eef00, dispatch5eef00);
