// batch37069.cpp - cascade s6 batch 37069: 0x5e4790.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5e4790, thiscall(this), plain ret: binds named resources of a UI-like object. Slot 0x58 resolves a name constant to a handle (stored in a field), slot 0x54 registers a field's
// address, and the embedded sub-objects (+0x10d, +0x13d, +0x155, +0x16d, each with its own vtable at offset 0) are given (handle field, 0, weight) through their slot 8.
static void THISCALL fn5e4790(u8 *t) {
  const u32 one = 0x3f800000, tenth = 0x3dcccccd;
  D32(t, 0x1d) = vcall<u32>(t, 0x58, 0x68d1acu);
  D32(t, 0x35) = vcall<u32>(t, 0x58, 0x68acf8u);
  D32(t, 0x4d) = vcall<u32>(t, 0x58, 0x68d1ccu);
  D32(t, 0x65) = vcall<u32>(t, 0x58, 0x68d1e0u);
  u8 *s1 = t + 0x10d;
  vcall<void>(s1, 8, (u32)(t + 0x35), 0u, one);
  vcall<void>(s1, 8, (u32)(t + 0x4d), 0u, tenth);
  vcall<void>(s1, 8, (u32)(t + 0x65), 0u, tenth);
  D32(t, 0xc5) = vcall<u32>(t, 0x58, 0x6b7a38u);
  vcall<void>(t + 0x13d, 8, (u32)(t + 0xc5), 0u, one);
  D32(t, 0xf5) = vcall<u32>(t, 0x58, 0x6b7a44u);
  vcall<void>(t, 0x54, (u32)(t + 0xf5));
  vcall<void>(t + 0x16d, 8, (u32)(t + 0xf5), 0u, one);
  vcall<void>(t, 0x54, (u32)(t + 0x35));
  vcall<void>(t, 0x54, (u32)(t + 0x4d));
  vcall<void>(t, 0x54, (u32)(t + 0x65));
  vcall<void>(t, 0x54, (u32)(t + 0x1d));
  D32(t, 0xdd) = vcall<u32>(t, 0x58, 0x6b7a50u);
  vcall<void>(t, 0x54, (u32)(t + 0xdd));
  vcall<void>(t + 0x155, 8, (u32)(t + 0xdd), 0u, one);
}
PCREG(5e4790, fn5e4790);
