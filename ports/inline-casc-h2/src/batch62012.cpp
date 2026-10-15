#include "ff.h"

extern "C" void THISCALL ext_515790(u8 *self, u8 *reader);
extern "C" void THISCALL ext_4e12e0(u8 *reader, u8 *destination, u32 count);
extern "C" void THISCALL ext_4e1b30(u8 *reader);

// 0x520ad0: initialize the reader, decode two adjacent fields, then finalize it.
static void THISCALL fn520ad0(u8 *self, u8 *reader) {
  ext_515790(self, reader);
  ext_4e12e0(reader, self + 0x25d5, 1);
  ext_4e12e0(reader, self + 0x25d9, 1);
  ext_4e1b30(reader);
}

PCREG(520ad0, fn520ad0);
