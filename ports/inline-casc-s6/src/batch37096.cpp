// batch37096.cpp - cascade s6 batch 37096: 0x5ae270.
#include "ff.h"

extern "C" void THISCALL ext_5ae450(u8 *self, u8 *buf);   // ret 4
extern "C" void THISCALL ext_5ae710(u8 *self, u32 v);     // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *cfg() {
  void *tab = *(void **)(*(u8 **)0x70039c + 0x9b);
  return (void *)vcall<u32>(tab, 0x134);
}

// 0x5ae270, thiscall(flag) ret 4, returns bool: reads two config switches (names 0x6a75b0 -> A, 0x6b0990 -> B). With flag set it only acts when B is set (reads a 0xc-byte
// string 0x6b09ac into a local buffer and hands it to 0x5ae450) and returns false. Without the flag, when A is set it reads the 7-byte 0x6a7a60 string into the buffer, the
// 8-byte 0x6b09bc string into +6, the int 0x6b09c8 into +0x86 and the 0x16-byte 0x6b09d8 string into +0x8a, calls 0x5ae450 and returns false; when A is clear it calls 0x5ae710(0),
// reports 0x6a777c (1, 2) to the config object and returns true.
static u8 THISCALL fn5ae270(u8 *self, u8 flag) {
  u8 buf[0x400];
  u8 A = 0, B = 0;
  self[5] = 1;
  vcall<void>(cfg(), 0x90, 0x6a75b0u, (u32)&A);
  vcall<void>(cfg(), 0x90, 0x6b0990u, (u32)&B);
  if (flag) {
    if (!B) return 0;
    vcall<void>(cfg(), 0x6c, (u32)buf, 0x6b09acu, 0xcu);
  } else {
    if (!A) {
      ext_5ae710(self, 0);
      vcall<void>(cfg(), 0x5c, 0x6a777cu, 1u, 2u);
      return 1;
    }
    vcall<void>(cfg(), 0x6c, (u32)buf, 0x6a7a60u, 7u);
    vcall<void>(cfg(), 0x6c, (u32)(self + 6), 0x6b09bcu, 8u);
    u32 C = 0;
    vcall<void>(cfg(), 0x88, 0x6b09c8u, (u32)&C);
    D32(self, 0x86) = C;
    vcall<void>(cfg(), 0x6c, (u32)(self + 0x8a), 0x6b09d8u, 0x16u);
  }
  ext_5ae450(self, buf);
  return 0;
}
PCREG(5ae270, fn5ae270);
