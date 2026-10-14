#include "ff.h"

// 0x658d00: 16 insns, thiscall: conditional offset calculation with shifts
u32 THISCALL fn_658d00(u8 *self) {
  u8 byte_val = self[0x3f];
  if (byte_val != 0) {
    u32 ptr = *(u32 *)(self + 0x48);
    return ptr + 0x90 + (byte_val * 3) * 32;
  }
  return byte_val * 3 * 32;
}
PCREG(658d00, fn_658d00);

// 0x410100: 5 insns, cdecl(param) ret 4: dereference param and read byte at offset 4
u8 fn_410100(u8 *param) {
  u8 *ptr = *(u8 **)param;
  return ptr[4];
}
PCREG(410100, fn_410100);
