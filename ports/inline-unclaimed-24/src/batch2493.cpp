// batch2493.cpp - decomp area 24, batch 2493 (residue 3, smallest first).
#include "ff.h"

extern "C" void THISCALL ext_4f2240(void *self, u32 level, u32 group);  // ZWINDOWS::FadeGroup(unsigned char, ZWINGROUP*), 2 args, pops 8 (assumed)

// 0x4f3ab0 (GUESS name, ZWINGROUP fade step). Byte +0x68: above 0xfa clears +0x69; below 0x96 stores the word 0x197 at +0x68. When the
// truncated float at +0x6b * 1024 is below the system dword at +0x40, +0x68 changes by +10 (flag +0x69 set) or -2, and +0x6b += 0.015.
// Then FadeGroup(byte +0x68, the dword at +0x64) on this.
static void THISCALL fadeStep(u8 *self) {
  u8 al = *(u8 *)(self + 0x68);
  if (al > 0xfa)
    *(u8 *)(self + 0x69) = 0;
  if (al < 0x96)
    *(u16 *)(self + 0x68) = 0x197;
  float x = *(float *)(self + 0x6b);
  u8 *sys = G(u8 *, 0x70039c);
  int s = (int)(x * 1024.0f);
  if (s < *(int *)(sys + 0x40)) {
    if (*(u8 *)(self + 0x69))
      *(u8 *)(self + 0x68) += 0xa;
    else
      *(u8 *)(self + 0x68) += 0xfe;
    *(float *)(self + 0x6b) = x + 0.015f;
  }
  ext_4f2240(self, (u32)*(u8 *)(self + 0x68), *(u32 *)(self + 0x64));
}
PCREG(4f3ab0, fadeStep);

// 0x4d7130 (GUESS name, path normaliser). Copies the string at ecx to the buffer at edx, mapping each backslash to '/', then
// terminates the copy. Returns the buffer (fastcall, plain ret).
static char *FASTCALL normalizePath(const char *src, char *dst) {
  u32 n = 0;
  if (*src) {
    do {
      char c = *src++;
      dst[n++] = (c == '\\') ? '/' : c;
    } while (*src);
  }
  dst[n] = 0;
  return dst;
}
PCREG(4d7130, normalizePath);
