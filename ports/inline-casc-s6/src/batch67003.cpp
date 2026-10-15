#include "ff.h"

static void THISCALL fn5dacd0(u8 *self) {
  u8 *table=(u8 *)(*(u32 *)(*(u32 *)0x70039c+0x9b));
  u8 *factory=(u8 *)*(u32 *)(table+0xadc);
  u8 *item=(u8 *)vcall<u32>(factory,0x25c,0x685f44u,0u);
  if (*(u32 *)(item+0x18)) {
    // Full resource iteration is handled in subsequent attempts if the null-list path is insufficient.
  }
  vcall<void>(self,0x68,0x10u,0u);
}
PCREG(5dacd0,fn5dacd0);
