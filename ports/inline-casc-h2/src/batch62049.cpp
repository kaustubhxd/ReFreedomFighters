#include "ff.h"

extern "C" void STDCALL ext_610100(u32 arg);
extern "C" void THISCALL ext_4e12f0(u8 *reader, u32 out, u32 mode);
extern "C" void THISCALL ext_4e12e0(u8 *reader, u32 out, u32 value);
extern "C" u32 THISCALL ext_4e1b30(u8 *reader);

static u32 THISCALL fn45ba60(u8 *self, u8 *reader) {
  ext_610100((u32)reader);
  ext_4e12f0(reader, (u32)(self + 0x28), 1);
  ext_4e12f0(reader, (u32)(self + 0x2c), 1);
  ext_4e12e0(reader, (u32)(self + 0x48), G(u32, self + 0x1c));
  return ext_4e1b30(reader);
}

PCREG(45ba60, fn45ba60);
