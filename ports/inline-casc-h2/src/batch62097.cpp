#include "ff.h"
static u32 THISCALL fn6567e0(u8 *self, u8 *node, u32 count) {
  if (!node) return 0;
  for (;;) {
    u32 result = vcall<u32>(self, 0xc, (u32)node);
    if (count-- == 0) return (u32)node;
    node = (u8 *)*(u32 *)((u8 *)result + 8);
    if (!node) return 0;
  }
}
PCREG(6567e0, fn6567e0);
