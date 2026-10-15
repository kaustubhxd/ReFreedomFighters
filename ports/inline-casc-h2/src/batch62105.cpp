#include "ff.h"
static u32 THISCALL fn45eeb0(u8 *self, u8 *object, u32 mask) {
  u32 flags = *(u32 *)(*(u32 *)(self + 0xc) + 0x23);
  if ((flags & mask) == 0) return mask;
  u8 *table = (u8 *)*(u32 *)(*(u32 *)0x70039c + 0x9b);
  u32 token = vcall<u32>(table, 0x4c, self);
  u32 result = vcall<u32>(object, 0x28, token);
  if (result == 0) {
    token = vcall<u32>(table, 0x4c, self);
    result = vcall<u32>(object, 4, token);
  }
  return result;
}
PCREG(45eeb0, fn45eeb0);
