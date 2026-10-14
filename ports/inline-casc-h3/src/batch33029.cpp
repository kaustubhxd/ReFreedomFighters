// batch33029.cpp - h3 batch 33029: field test and array compare
#include "ff.h"

// 0x537e40, thiscall: test arg, if zero return 0; load field at 0x5302, if zero return 0; compare [field+arg] to 1
static u8 THISCALL fn537e40(u8 *self, u32 arg) {
  if (!arg) return 0;
  u32 *field = *(u32 **)(self + 0x5302);
  if (!field) return 0;
  u32 val = *(u32 *)((u8 *)field + arg);
  return val == 1 ? 1 : 0;
}
PCREG(537e40, fn537e40);

// 0x658d00, thiscall: test byte at 0x3f, if zero return 0, else (byte*3)<<5 + ([0x48]+0x90)
static u32 THISCALL fn658d00(u8 *self) {
  u8 b = self[0x3f];
  if (!b) return 0;
  u32 base = *(u32 *)(self + 0x48);
  return (u32)b * 3 * 32 + base + 0x90;
}
PCREG(658d00, fn658d00);
