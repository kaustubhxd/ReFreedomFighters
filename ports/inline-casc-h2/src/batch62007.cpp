#include "ff.h"

extern "C" void THISCALL ext_5e93f0(u8 *self, u32 value, u32 zero);

// 0x594540, thiscall(arg) ret 4: when enabled, obtains an object through the
// engine table, asks it for a value via an out pointer, then removes arg from it.
static void THISCALL fn594540(u8 *self, u32 arg) {
  if (!self[0x9e7]) return;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *table = *(u8 **)(sys + 0x9b);
  u8 *object = vcall<u8 *>(table, 0x138);
  u32 value = 0;
  vcall<void>(object, 0x88, 0x6acf30u, &value);
  ext_5e93f0((u8 *)value, arg, 0);
}

PCREG(594540, fn594540);
