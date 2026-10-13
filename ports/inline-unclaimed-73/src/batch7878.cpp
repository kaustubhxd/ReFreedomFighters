// batch7878.cpp - area 73 batch 78 (GUESS name): FUN_5001e0 (stdcall, ret 8, the two arguments are unused).
#include "ff.h"

// 0x5001e0 (GUESS FUN_5001e0): logs two strings through the engine logger, then calls the assert hook at 0x7003b0 when it is set.
static void STDCALL guess5001e0(u32 a1, u32 a2) {
  (void)a1;
  (void)a2;
  u8 *logger = G(u8 *, 0x700390);
  void *stream = vcall<void *>(logger, 0x20, 0x69c7b8u, 0x96u);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
  printf_t pf = *(printf_t *)(*(u8 **)stream + 0x2c);
  pf(stream, (const char *)0x69c6b0, (const char *)0x69c7f0);
  void (*hook)() = (void (*)())G(u32, 0x7003b0);
  if (hook)
    hook();
}
PCREG(5001e0, guess5001e0);
