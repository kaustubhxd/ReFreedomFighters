// batch955.cpp - 0x5196a0 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one arg (a), ret 4, void.
// f = slot +0x300 of [this+0x14] (no args; returns a float in st0; stored as float). p = 0x5003d0(index 0) on ECX = [a+8] (stood in).
// If p[4] is 0 or 2: *(float *)p = f and p[4] = 2. Otherwise: logger (0x700390) slot +0x20 (0x69c8e0, 0xd5) gives a sink; the sink's cdecl
// slot +0x2c with (sink, 0x69c6b0, 0x69c938); then the hook at 0x7003b0 is called with no args (null: the exe traps with int3).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);   // stood in (one arg, returns a pointer)

// 0x5196a0 (no name in the map).
static void THISCALL Apply5196a0(u8 *self, u8 *a) {
  float f = vcall<float>(FP(self, 0x14), 0x300);
  u8 *p = (u8 *)ext_5003d0(FP(a, 8), 0u);
  u8 v = U8(p, 4);
  if (v == 0 || v == 2) {
    *(float *)p = f;
    U8(p, 4) = 2;
    return;
  }
  void *logger = G(void *, 0x700390);
  void *sink = vcall<void *>(logger, 0x20, 0x69c8e0u, 0xd5u);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, u32, u32);
  printf_t pf = *(printf_t *)(*(u8 **)sink + 0x2c);
  pf(sink, 0x69c6b0u, 0x69c938u);
  typedef void(THISCALL * hook_t)(void);
  hook_t hook = G(hook_t, 0x7003b0);
  if (hook) hook();
  else asm volatile("int3");   // the exe jumps to an int3 when the hook is null
}
PCREG(5196a0, Apply5196a0);
