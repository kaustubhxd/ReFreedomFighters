// batch7.cpp - first-level functions, inline session batch 7 (Haiku, overnight).
#include "ff.h"

// 0x4ce640, thiscall (ret 4): indexed lookup in a chunked list. idx is checked against this+0x14 (signed); a chunk
// size is this+0xc & 0x7fffffff; the chain head is this+4 and each step follows +4. Returns the address
// head + 4 * (idx * this+0x18 + 4) after the walk, or 0 when idx >= this+0x14. Name unknown.
static u32 THISCALL chunkLookup(u8 *self, s32 idx) {
  if (!(idx < (s32)*(u32 *)(self + 0x14)))
    return 0;
  s32 chunk = (s32)(*(u32 *)(self + 0xc) & 0x7fffffffu);
  u32 base = *(u32 *)(self + 4);
  if (!(idx < chunk)) {
    do {
      base = *(u32 *)(base + 4);
      idx = (s32)((u32)idx - (u32)chunk);
    } while (idx >= chunk);
  }
  s32 scaled = (s32)((u32)idx * *(u32 *)(self + 0x18));
  return base + 4u * (u32)(scaled + 4);
}
PCREG(4ce640, chunkLookup);

// 0x4db9a0, thiscall (ret 4, returns AL): if this+0x54 is NULL, returns key == 0x200002. Otherwise walks the list
// starting at node->+0xc and returns 1 when some node has key at +0x23 (unaligned dword). Name unknown (ZBaseGeom list).
static u8 THISCALL hasKeyAt23(u8 *self, u32 key) {
  u32 head = *(u32 *)(self + 0x54);
  if (head == 0)
    return key == 0x200002u;
  u32 n = *(u32 *)(head + 0xc);
  if (n == 0)
    return 0;
  do {
    if (*(u32 *)(n + 0x23) == key)
      return 1;
    n = *(u32 *)(n + 0xc);
  } while (n != 0);
  return 0;
}
PCREG(4db9a0, hasKeyAt23);

// 0x4e86b0, thiscall (ret 8): BST lookup over nodes with key at +0xc, children at +4 (less) and +8 (greater or equal).
// start = arg2 when non-NULL, otherwise this+4. The sentinel is this+8. Returns the node whose key equals the argument,
// else 0. Name unknown (ZBinTree find).
static u32 THISCALL treeFind(u8 *self, s32 key, u32 start) {
  u32 n = start != 0 ? start : *(u32 *)(self + 4);
  u32 nil = *(u32 *)(self + 8);
  if (n == nil)
    return 0;
  for (;;) {
    s32 nk = (s32)*(u32 *)(n + 0xc);
    if (key == nk)
      return n;
    n = key >= nk ? *(u32 *)(n + 8) : *(u32 *)(n + 4);
    if (n == nil)
      return 0;
  }
}
PCREG(4e86b0, treeFind);
