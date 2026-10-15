#include "ff.h"
static u8 *THISCALL fn5f3bf0(u8 *dst, u8 *src) {
  if (dst == src) return dst;
  if (dst[4] == 4) {
    u8 *old = (u8 *)*(u32 *)dst;
    vcall<void>(old, 0x28);
  }
  u8 type = src[4];
  if (type == 4) {
    u8 *value = (u8 *)*(u32 *)src;
    *(u32 *)dst = vcall<u32>(value, 0x24);
  } else {
    *(u32 *)dst = *(u32 *)src;
  }
  dst[4] = type;
  return dst;
}
PCREG(5f3bf0, fn5f3bf0);
