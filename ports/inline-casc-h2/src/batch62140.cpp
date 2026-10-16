#include "ff.h"

static u32 THISCALL fn5d2860(u8 *self, u32 id) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *manager = (u8 *)G(u32, sys + 0x9b);
  u8 *resource = (u8 *)vcall<u32>(manager, 0x58, id);
  if (!resource) return 0;
  if (!(vcall<u32>(resource, 0x1e0, 0x2007f9u) & 0xff)) return 0;
  u8 *shift_obj = (u8 *)G(u32, resource + 0x54);
  u32 bit = 1u << (G(u32, shift_obj + 4) & 31);
  u8 *state = (u8 *)G(u32, self + 0x44);
  u8 *mask_obj = (u8 *)G(u32, state + 0x54);
  return (bit & G(u32, mask_obj + 0xc)) ? 2u : 1u;
}
PCREG(5d2860, fn5d2860);
