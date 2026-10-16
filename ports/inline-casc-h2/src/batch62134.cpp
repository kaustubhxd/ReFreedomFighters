#include "ff.h"
typedef void (__attribute__((cdecl)) * visit_fn)(u8 *node);

static void __attribute__((cdecl)) fn620670(u8 *state) {
  u8 *callback_table = (u8 *)G(u32, state + 0x14);
  visit_fn visit = (visit_fn)G(u32, callback_table + 8);
  for (u8 *node = (u8 *)G(u32, state); node; node = (u8 *)G(u32, node)) visit(node);
  for (u8 *node = (u8 *)G(u32, state + 4); node; node = (u8 *)G(u32, node)) visit(node);
  G(u32, state) = 0;
  G(u32, state + 4) = 0;
  G(u32, state + 8) = 0;
  G(u32, state + 0xc) = 0;
  G(u32, state + 0x10) = 0;
}
PCREG(620670, fn620670);
