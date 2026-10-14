// batch35066.cpp - cascade s5 batch 35066: 0x647430 (GUESS combine record E of three parallel arrays through a 36-byte local).
#include "ff.h"

extern "C" void FASTCALL ext_4de440(u8 *l, u8 *src, u32 a);      // ret 4
extern "C" void FASTCALL ext_43e920(u8 *dst, u32 a, u8 *b);      // ret 4
extern "C" void FASTCALL ext_441a60(u8 *a, u8 *b);               // plain ret
extern "C" void FASTCALL ext_4de4f0(u8 *a, u8 *b);               // plain ret
extern "C" void FASTCALL ext_4de1d0(u8 *a, u8 *b);               // plain ret

// 0x647430, stdcall(A, B, C, D, E, F, G) ret 0x1c. e = E; tgt = A + 48e; src = C + 36e; p = B + 48 * [D + 48e + 0xc]. l (36 bytes) is filled by 0x4de440(l, src, F); then 0x43e920(tgt + 0x24, G, p + 0x24),
// 0x441a60(tgt + 0x24, p), 0x4de4f0(l, p) and 0x4de1d0(tgt, l).
static void STDCALL fn647430(u8 *A, u8 *B, u8 *C, u8 *D, u32 E, u32 F, u32 G) {
  u8 l[0x24];
  u32 k = *(u32 *)(D + E * 48 + 0xc);
  u8 *p = B + k * 48;
  u8 *tgt = A + E * 48;
  ext_4de440(l, C + E * 36, F);
  ext_43e920(tgt + 0x24, G, p + 0x24);
  ext_441a60(tgt + 0x24, p);
  ext_4de4f0(l, p);
  ext_4de1d0(tgt, l);
}
PCREG(647430, fn647430);
