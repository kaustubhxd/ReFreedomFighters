#include "ff.h"

// 0x4d6e70: 5 insns, thiscall: add 4 to ecx, tail-jump to 0x4d9230
extern "C" void THISCALL ext_4d9230(u8 *self);
void THISCALL fn_4d6e70(u8 *self) {
  self = self + 4;
  ext_4d9230(self);
}
PCREG(4d6e70, fn_4d6e70);
