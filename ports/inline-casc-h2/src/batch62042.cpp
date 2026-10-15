#include "ff.h"

extern "C" u32 THISCALL ext_5f5620(u8 *self, u32 value);

static u32 THISCALL fn5f5680(u8 *self, u32 index) {
  u8 *state = (u8 *)G(u32, self + 0x96);
  u32 i = index & 0xffff;
  if (i < G(u32, state + 0x104)) {
    u32 value = G(u32, G(u32, state + 0x108) + i * 4);
    return ext_5f5620(self, value);
  }
  u32 assertion = G(u32, 0x7003b0);
  if (assertion) ((void (FASTCALL *)(void))assertion)();
  return ext_5f5620(self, index);
}

PCREG(5f5680, fn5f5680);
