// batch6350.cpp - area 73 batch 63 (gap band, GUESS name): FUN_4edc10.
#include "ff.h"

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 n);
extern "C" void THISCALL ext_4edeb0(u8 *self, u32 a);

// 0x4edc10 (GUESS FUN_4edc10): ret 4. A non-null argument makes a new 0x18-byte object (operator new), stores it at
// this+0x1a9, and calls 0x4edeb0 on that object with the argument.
static void THISCALL guess4edc10(u8 *self, u32 a) {
  if (!a)
    return;
  u8 *p = ext_41e290(0x18u);
  *(u8 **)(self + 0x1a9) = p;
  ext_4edeb0(p, a);
}
PCREG(4edc10, guess4edc10);
