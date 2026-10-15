#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);

static u8 *fn63a720(u8 *info) {
  u8 *manager = G(u8 *, 0x70038c);
  u32 allocator = vcall<u32>(manager, 0x48, 0x80ff80u);
  u8 *raw = ext_41e290((u32)(info + 0x10));
  u8 *aligned = (u8 *)(((u32)raw + 0x10u) & 0xfffffff0u);
  *(u32 *)(aligned - 4) = (u32)raw;
  vcall<void>(manager, 0x48, allocator);
  return aligned;
}

PCREG(63a720, fn63a720);
