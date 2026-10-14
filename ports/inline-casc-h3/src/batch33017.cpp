// batch33017.cpp - h3 batch 33017: simple 2-instruction setters
#include "ff.h"

// 0x4d23c0, thiscall, no args: set dword at this to 0x696168
static void THISCALL fn4d23c0(u8 *self) {
  *(u32 *)self = 0x696168;
}
PCREG(4d23c0, fn4d23c0);

// 0x527180, thiscall, no args: read byte at this+0x18, return in al
static u8 THISCALL fn527180(u8 *self) {
  return self[0x18];
}
PCREG(527180, fn527180);
