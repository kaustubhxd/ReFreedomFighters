// batch1044.cpp - area 81, batch 1044: 0x634844, plain ret, no arguments. Gets the flag block 0x6ff948 from 0x42acaf (real exe code, returns the
// address) and sets bit 4 of its first word; then gets 0x6ff950 from 0x42acb5 (real exe code) and sets bit 2 of its first word. The second word of each
// block is read and written back unchanged. No stand-ins.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void *__attribute__((cdecl)) ext_42acaf(void);   // real exe code: returns 0x6ff948
extern "C" void *__attribute__((cdecl)) ext_42acb5(void);   // real exe code: returns 0x6ff950

// 0x634844 (cdecl-style: no arguments).
static void __attribute__((cdecl)) setFlagBits(void) {
  u8 *a = (u8 *)ext_42acaf();
  u32 ecx = D(a, 4);
  D(a, 0) |= 4;
  D(a, 4) = ecx;
  u8 *b = (u8 *)ext_42acb5();
  ecx = D(b, 4);
  D(b, 0) |= 2;
  D(b, 4) = ecx;
}
PCREG(634844, setFlagBits);
