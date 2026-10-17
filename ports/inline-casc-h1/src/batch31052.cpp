#include "ff.h"

// 0x429b00: 3 insns, thiscall: write 0 to byte field at offset 0x75, return 1
u8 THISCALL fn_429b00(u8 *self) {
  self[0x75] = 0;
  return 1;
}
PCREG(429b00, fn_429b00);
