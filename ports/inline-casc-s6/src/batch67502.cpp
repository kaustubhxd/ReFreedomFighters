// batch67502.cpp - cascade s6 batch 67502: 0x58bc60.
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(u8 *m);                                  // resets a 0x24-byte matrix block (plain ret)
extern "C" void THISCALL ext_4deb20(u8 *m, u32 angle, u32 x, u32 y, u32 z);  // builds a rotation (angle, axis) into m, ret 0x10 (floats passed as bit patterns)
extern "C" void FASTCALL ext_4de480(u8 *dst, u8 *src);                       // multiplies dst by src (tail-jumps, plain ret)
extern "C" void THISCALL ext_4dcbb0(u8 *self, u32 flag);                     // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x58bc60, thiscall(entry) ret 4: places entry's model with a per-kind pose. entry's slot 0x2e8 object name (default 0x67c8e8) is compared with the string at 0x6ac9a0;
// a match uses the offset vector {x = -23.5f (or -20.0f when byte +0xeec is 0), y = 0, z = 30.0f} and rotations 90 about x then -30 about y, otherwise {-25 (or -20.0f), -15, 12}
// with 90 about x then 150 about y. The accumulated matrix and the vector go to slot 0x290 of this (with entry+8 and 0xc), 0x4dcbb0 flags entry+8 and the entry's table handle is
// stored in +0x842.
static void THISCALL fn58bc60(u8 *self, u8 *entry) {
  u32 m58[9], m34[9];
  u32 vec[3];
  u8 *r = (u8 *)vcall<u32>(entry, 0x2e8);
  const char *a = D32(r, 4) ? *(const char **)(r + 4) : (const char *)0x67c8e8;
  const char *b = (const char *)0x6ac9a0;
  bool eq = true;
  for (;; a++, b++) {
    if (*a != *b) {
      eq = false;
      break;
    }
    if (!*a) break;
  }
  u32 axisAngle2[4];
  if (eq) {
    vec[1] = 0;
    vec[2] = 0x41f00000u;
    vec[0] = 0xc1bd0000u;
    if (*(u8 *)(self + 0xeec) == 0) vec[0] = 0xc1a00000u;
    axisAngle2[0] = 0xc1f00000u; axisAngle2[1] = 0x3f800000u; axisAngle2[2] = 0; axisAngle2[3] = 0;
  } else {
    vec[1] = 0xc1700000u;
    vec[2] = 0x41400000u;
    vec[0] = 0xc1c80000u;
    if (*(u8 *)(self + 0xeec) == 0) vec[0] = 0xc1a00000u;
    axisAngle2[0] = 0x43160000u; axisAngle2[1] = 0x3f800000u; axisAngle2[2] = 0; axisAngle2[3] = 0;
  }
  ext_4de7a0((u8 *)m58);
  ext_4deb20((u8 *)m34, 0x42b40000u, 0, 0, 0x3f800000u);
  ext_4de480((u8 *)m58, (u8 *)m34);
  ext_4deb20((u8 *)m34, axisAngle2[0], axisAngle2[1], axisAngle2[2], axisAngle2[3]);
  ext_4de480((u8 *)m58, (u8 *)m34);
  vcall<void>(self, 0x290, D32(entry, 8), 0xcu, (u32)m58, (u32)vec);
  ext_4dcbb0(*(u8 **)(entry + 8), 1);
  D32(self, 0x842) = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x4c, (u32)entry);
}
PCREG(58bc60, fn58bc60);
