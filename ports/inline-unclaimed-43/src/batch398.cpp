// batch398.cpp - 0x4a6060 (core: ZRequireMatPosSpeed::Init, thiscall with two stack arguments, ret 8; the first is unused,
// the second is an object passed as ECX to the readers). Five calls to 0x4e6180(obj, dst) read a float into dst at
// this+0x48, +0x54, +0x60, +0x6c, +0x78 (0x4e6180 is hooked by address in the spec, GUESS: a float reader, body not ported).
// Then 0x4e0d00 (exe, scales the three floats at its ECX object by a float argument; real exe code) with the constant
// 0x3c8efa35 on this+0x60 and this+0x48.
#include "ff.h"

extern "C" u32 THISCALL ext_4e6180(void *obj, float *dst);     // float reader (hooked by address in the spec)
extern "C" void THISCALL ext_4e0d00(void *self, float scale);  // scale three floats (exe code)

static void THISCALL matPosSpeedInit(u8 *self, u32 unused, u8 *obj) {
  (void)unused;
  ext_4e6180(obj, (float *)(self + 0x48));
  ext_4e6180(obj, (float *)(self + 0x54));
  ext_4e6180(obj, (float *)(self + 0x60));
  ext_4e6180(obj, (float *)(self + 0x6c));
  ext_4e6180(obj, (float *)(self + 0x78));
  u32 kbits = 0x3c8efa35u;
  float k = *(float *)&kbits;
  ext_4e0d00(self + 0x60, k);
  ext_4e0d00(self + 0x48, k);
}
PCREG(4a6060, matPosSpeedInit);
