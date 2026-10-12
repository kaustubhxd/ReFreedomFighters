#include "ff.h"
// batch7907.cpp - unclaimed-79 batch 7 (docs/20-unclaimed-79.md). Name from the residue list (no GC conflict).
// Base copy 0x46cee0, DBLK helpers 0x4e11e0, 0x4e12f0, 0x4e12e0, 0x4e1600, and 0x4e1b30 run as original code (stubbed by the
// harness); the logger at 0x700390 is an object whose vtable slot +0x20 returns an object (see docs/20-unclaimed-79.md).

extern "C" void THISCALL ext_46cee0(u8 *self, u8 *blk);
extern "C" void THISCALL ext_4e11e0(u8 *blk, u8 *p, u32 n);
extern "C" void THISCALL ext_4e12f0(u8 *blk, u8 *p, u32 n);
extern "C" void THISCALL ext_4e12e0(u8 *blk, u8 *p, u32 n);
extern "C" u8 THISCALL ext_4e1600(u8 *blk);
extern "C" void THISCALL ext_4e1b30(u8 *blk);

// 0x46cf60, ZItemTemplateAmmo::CopyDataBlock(DBLK*) (residue list). Thiscall, one stack argument (ret 4).
static void THISCALL itemTemplateAmmoCopyDataBlock(u8 *self, u8 *blk) {
  u8 *b = blk;   // the exe keeps the block in esi; its argument slot is overwritten by the helper below
  ext_46cee0(self, b);
  ext_4e11e0(b, self + 0x7c, 1u);
  ext_4e12f0(b, self + 0x84, 1u);
  ext_4e12f0(b, self + 0x88, 1u);
  ext_4e11e0(b, (u8 *)&blk, 1u);   // the exe passes the address of its argument slot, then reads the slot back
  *(u32 *)(self + 0x8c) = (u32)(unsigned long)blk;
  ext_4e12e0(b, self + 0x90, 1u);
  ext_4e12e0(b, self + 0x94, 1u);
  if (ext_4e1600(b) == 3) {
    ext_4e11e0(b, self + 0x80, 1u);
    ext_4e1b30(b);
    return;
  }
  *(u32 *)(self + 0x80) = 1;
  u8 *logger = G(u8 *, 0x700390);
  u8 *obj = vcall<u8 *, u32, u32>(logger, 0x20, 0x6887c4u, 0xdd2u);
  u8 *vt = *(u8 **)obj;
  ((void(__attribute__((cdecl)) *)(u32, u32)) * (u32 *)(vt + 0x2c))((u32)(unsigned long)obj, 0x688d98u);
  ext_4e1b30(b);
}
PCREG(46cf60, itemTemplateAmmoCopyDataBlock);
