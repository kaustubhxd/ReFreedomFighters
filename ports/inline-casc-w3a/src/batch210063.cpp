// batch210063.cpp - Sonnet-w3a: 0x4d8ef0 (find the container element whose length and bytes equal a key)
#include "ff.h"

static u32 STDCALL fn4d8ef0(u8 *cont, const u8 *key, u32 len) {
  u32 it[3];
  if (!cont) return 0;  // @4d8ef0_a
  vcall<u32, u32 *>(cont, 0x4c, it);  // @4d8ef0_b
  u8 *e = (u8 *)vcall<u32, u32 *>(cont, 0x64, it);  // @4d8ef0_c
  while (e) {
    if (*(u32 *)(e + 4) == len) {  // @4d8ef0_d
      const u8 *p = *(const u8 **)e;
      u32 i = 0;
      while (i < len && p[i] == key[i]) i++;  // @4d8ef0_e
      if (i == len) return (u32)e;  // @4d8ef0_f
    }
    e = (u8 *)vcall<u32, u32 *>(cont, 0x64, it);  // @4d8ef0_g
  }
  return 0;
}
PCREG(4d8ef0, fn4d8ef0);
