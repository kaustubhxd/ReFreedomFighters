#include "ff.h"
static void FASTCALL fn61a660(u8 *self, u8 *array) {
  u32 count = G(u32, array);
  u8 *entries = (u8 *)G(u32, array + 8);
  u8 *sys = (u8 *)G(u32, 0x724a00);
  u8 *vt = (u8 *)G(u32, sys);
  typedef void (FASTCALL *dispatch_fn)(u8 *, u8 *, u32, u32, u32, u32, u32, u32);
  for (u32 i = 0; i < count; ++i) {
    u8 *entry = entries + i * 8;
    u32 key = G(u32, entry) - 1;
    u32 value = G(u32, entry + 4);
    ((dispatch_fn)G(u32, vt + 0x11c))(entry, sys, (u32)sys, 3u, 0u, (u32)self, value, key);
  }
}
PCREG(61a660, fn61a660);
