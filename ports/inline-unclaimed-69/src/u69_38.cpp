// u69_38.cpp - area 69, group 38 (slice 8). One level of a tail-jump chain: the target 0x4cdd50 (thiscall, one stack arg, ret 4, other area) is a GUESS stub in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_4cdd50(void *self, u32 a);

// 0x4cde00, thiscall one stack arg (ret 4). If the dword at self+0x28 equals the arg, clears it; then jumps to 0x4cdd50 with the same ECX and argument. The port calls the target and returns its eax.
static u32 THISCALL chain4cde00(u8 *self, u32 a) {
  if (*(u32 *)(self + 0x28) == a)
    *(u32 *)(self + 0x28) = 0;
  return ext_4cdd50(self, a);
}
PCREG(4cde00, chain4cde00);
