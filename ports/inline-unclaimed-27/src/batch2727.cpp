#include "ff.h"
// batch2727.cpp - unclaimed-27 batch 27 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// 0x4ffea0 is thiscall with three stack arguments (ret 0xc); 0x54f870 is stdcall, two arguments (ret 8). Both are hooked (stubs).
extern "C" u32 THISCALL ext_4ffea0(u8 *self, u32 n, u32 begin, u32 capEnd);
extern "C" void STDCALL ext_54f870(u32 begin, u32 size);

// 0x59a9b0 (GUESS): thiscall, one argument n, void, ret 4. If (end - begin) >> 2 >= n (unsigned), returns. Otherwise cap =
// (cap end - begin) >> 2, the new block is 0x4ffea0(this, n, begin, cap end), the old block is released with 0x54f870 when its
// count is nonzero, and this+0, +4, +8 are set to: the new block, new + 4*cap, new + 4*n.
static void THISCALL funcGrowBlock(u8 *self, u32 n) {
  u32 begin = *(u32 *)(self + 0);
  u32 count = (u32)((s32)(*(u32 *)(self + 8) - begin) >> 2);
  if (count >= n) return;

  u32 capEnd = *(u32 *)(self + 4);
  u32 cap = (u32)((s32)(capEnd - begin) >> 2);
  u32 blk = ext_4ffea0(self, n, begin, capEnd);

  u32 oldBegin = *(u32 *)(self + 0);
  u32 oldCount = (u32)((s32)(*(u32 *)(self + 8) - oldBegin) >> 2);
  if (oldCount != 0) ext_54f870(oldBegin, oldCount << 2);

  *(u32 *)(self + 0) = blk;
  *(u32 *)(self + 4) = blk + cap * 4;
  *(u32 *)(self + 8) = blk + n * 4;
}
PCREG(59a9b0, funcGrowBlock);
