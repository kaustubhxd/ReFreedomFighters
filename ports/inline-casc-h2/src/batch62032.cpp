#include "ff.h"

static void THISCALL fn5ebda0(u8 *self, u8 *callback, u32 ignored) {
  (void)ignored;
  if (!self[0x35]) return;
  u8 *data = *(u8 **)(self + 0x3a);
  if (!*(u32 *)data) return;
  vcall<void>(callback, 0x28,
              *(u32 *)(self + 0x36), (u32)data,
              (u32)(self + 0x76), (u32)(self + 0x9a),
              (u32)self[0x5e], 0u);
}

PCREG(5ebda0, fn5ebda0);
