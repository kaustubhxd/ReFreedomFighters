#include "ff.h"
extern "C" u32 ext_41e290(u32 size);
extern "C" void THISCALL ext_5577d0(void *self);
static u32 fn557930() {
  u8 *current = G(u8 *, 0x713f04);
  if (current) {
    return vcall<u32>(current, 0x24);
  }
  u8 *created = (u8 *)ext_41e290(0x28);
  if (created) {
    G(u32, created + 4) = 1;
    G(u32, created + 8) = 0;
    G(u32, created) = 0x6a57a4;
    G(u32, created + 0x14) = 0;
    G(u32, created + 0xc) = 0;
    G(u32, created + 0x10) = 0;
    G(u32, created + 0x14) = 0;
  }
  G(u8 *, 0x713f04) = created;
  ext_5577d0(created);
  return G(u32, 0x713f04);
}
PCREG(557930, fn557930);
