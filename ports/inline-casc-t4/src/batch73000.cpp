#include "ff.h"

extern "C" void THISCALL ext_5f0af0(u8 *vec, u8 *end, const u8 *item);

// 0x5f0700: append a 12-byte event {2, arg, stack word} to this+0x7c.
// When the vector is full, delegate its growth and append operation to 0x5f0af0.
static void THISCALL fn5f0700(u8 *self, u32 arg) {
  u8 item[12];
  *(u32 *)(item + 0) = 2;
  *(u32 *)(item + 4) = arg;
  // The original leaves [ebp-4] untouched; the harness entry stack is 0xcc-filled.
  *(u32 *)(item + 8) = 0xcccccccc;
  u8 *vec = self + 0x7c;
  u8 *end = *(u8 **)(self + 0x80);
  if (end == *(u8 **)(self + 0x84)) {
    ext_5f0af0(vec, end, item);
    return;
  }
  if (end) {
    *(u64 *)end = *(u64 *)item;
    *(u32 *)(end + 8) = *(u32 *)(item + 8);
  }
  *(u32 *)(vec + 4) += 0xc;
}
PCREG(5f0700, fn5f0700);
