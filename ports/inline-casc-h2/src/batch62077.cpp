#include "ff.h"
extern "C" void THISCALL ext_4dcbb0(void *self, u32 one);

static void THISCALL fn4b8da0(u8 *self) {
  if (G(u8, self + 0x58)) return;
  G(u8, self + 0x58) = 1;
  u8 *sys = (u8 *)g_pSysInterface;
  u32 item = vcall<u32>(*(u8 **)(sys + 0x9b), 0x58, G(u32, self + 0x4c));
  u32 payload = G(u32, (u8 *)item + 8);
  if (G(u32, self + 0x54) == 1) ext_4dcbb0((void *)payload, 1);
  vcall<void>((void *)G(u32, self + 0x59), 0x290,
              payload, G(u32, self + 0x50), 0u, 0u);
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(4b8da0, fn4b8da0);
