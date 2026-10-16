#include "ff.h"
extern "C" u32 THISCALL ext_4cc5f0(u8 *self);
extern "C" u32 THISCALL ext_4cc1d0(u8 *self);
extern "C" void THISCALL ext_4db860(u8 *object, u32 flag);

static void THISCALL fn4b12c0(u8 *self, u32 arg1, u32 arg2) {
  u32 result = 0;
  u32 child = G(u32, self + 0x50);
  if (child) {
    result = vcall<u32>(self, 0x94, arg1, child);
  } else if (ext_4cc5f0(self + 0x55)) {
    u32 item = ext_4cc1d0(self + 0x55);
    result = vcall<u32>(self, 0x90, arg1, arg2, item);
  }
  if (result) ext_4db860((u8 *)result, G(u8, self + 0x54));
}
PCREG(4b12c0, fn4b12c0);
