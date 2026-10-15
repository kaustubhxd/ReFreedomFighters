// batch33099.cpp - h3 (Sonnet) batch 33099: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" float THISCALL ext_4e5e80(u8 *self);                      // float in st0
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                        // eax

// 0x4b5d00: thiscall(stream) ret 4: three u16 ids via sys table slot 0x114(name, 0, 0x691edc, line) -> [this+0x51], +0x53, +0x55; [this+0x48]=e80(s); [+0x4c]=e80(s); byte [+0x50] = e60(s) != 0
static void THISCALL fn4b5d00(u8 *self, u8 *s) {
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u16 w = (u16)vcall<u32>(tab, 0x114, 0x691f0cu, 0u, 0x691edcu, 0x6du);
  __builtin_memcpy(self + 0x51, &w, 2);
  tab = *(u8 **)(SYS + 0x9b);
  w = (u16)vcall<u32>(tab, 0x114, 0x67b508u, 0u, 0x691edcu, 0x6eu);
  __builtin_memcpy(self + 0x53, &w, 2);
  tab = *(u8 **)(SYS + 0x9b);
  w = (u16)vcall<u32>(tab, 0x114, 0x68f9e8u, 0u, 0x691edcu, 0x6fu);
  __builtin_memcpy(self + 0x55, &w, 2);
  float f = ext_4e5e80(s);
  *(float *)(self + 0x48) = f;
  f = ext_4e5e80(s);
  *(float *)(self + 0x4c) = f;
  self[0x50] = ext_4e5e60(s) != 0;
}
PCREG(4b5d00, fn4b5d00);
