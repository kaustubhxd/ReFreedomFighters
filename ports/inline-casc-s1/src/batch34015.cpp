// batch34015.cpp - cascade tier E, batch 34015: 0x495d60, thiscall(n) ret 4: bump-allocate a 16-aligned block from a pool (header word +0x2c,
// zero guard word at the end), logging the allocation through the engine object at 0x70038c.
#include "ff.h"

extern "C" u32 THISCALL ext_4cd9b0(void *pool, u32 size, u32 flag);   // pool grow/reserve, thiscall ret 8, returns an offset

static u32 *THISCALL fn495d60(u8 *self, u32 n) {
  u32 edi = (n + 0x13) & 0xfffffff0u;
  void *pool = *(void **)(self + 0x2c);
  *(u32 *)(self + 0x3c) += 1;
  *(u32 *)(self + 0x38) += edi;
  u32 ebx = (edi + 0xf) & 0xfffffff0u;
  u32 off = ext_4cd9b0(pool, ebx, 1);
  u8 *blk = *(u8 **)(self + 0x30) + off;
  u8 *eng = G(u8 *, 0x70038c);
  if (eng) {
    vcall<void>(eng, 0x2c, 0x68e524u, off, ebx);
    eng = G(u8 *, 0x70038c);
  }
  vcall<void>(eng, 0x50, (u32)blk, ebx, 0x40c0ffu);
  *(u32 *)(blk + 0x2c) = edi;
  *(u32 *)(blk + edi - 4) = 0;
  return (u32 *)blk;
}
PCREG(495d60, fn495d60);
