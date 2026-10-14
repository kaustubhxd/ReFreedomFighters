// batch944.cpp - 0x557b20 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), no args, plain ret. Returns st0 = float [this].
// If byte [this+4] is 0 or 2, it returns at once. Otherwise: s = logger (the dword at 0x700390) slot +0x20 (thiscall: 0x69c8e0, 0x104; returns s),
// then s's slot +0x2c (cdecl, caller pops 12: s, 0x69c6b0, 0x69c938). Then the dword at 0x7003b0 is called (no args); when it is null the original reaches an int3 (a fault), which the port models.
// The float is read after these calls, so it is the value at the end. The engine logger and the sink are the harness stand-ins (install_logger).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))

// 0x557b20 (no name in the map).
static float THISCALL Log557b20(u8 *self) {
  u8 st = U8(self, 4);
  if (st != 0 && st != 2) {
    void *logger = G(void *, 0x700390);
    void *s = vcall<void *>(logger, 0x20, 0x69c8e0u, 0x104u);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, u32, u32);
    printf_t pf = *(printf_t *)(*(u8 **)s + 0x2c);
    pf(s, 0x69c6b0u, 0x69c938u);
    typedef void(THISCALL * hook_t)(void);
    hook_t hook = G(hook_t, 0x7003b0);
    if (hook) hook();
    else asm volatile("int3");   // the exe jumps to an int3 when the hook is null (the same trap as batch 921)
  }
  return *(float *)self;
}
PCREG(557b20, Log557b20);
