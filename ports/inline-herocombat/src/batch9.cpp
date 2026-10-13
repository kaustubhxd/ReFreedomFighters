// batch9.cpp - first-level functions, inline session batch 9 (Haiku, overnight).
#include "ff.h"

// 0x46abf0, thiscall (ret 4): appends value to the u32 array at this+0x8b8 (count at this+0x8b4) unless the value is
// already in it. Searches the current count entries; when not found, writes arr[count] and increments the count.
// Name unknown. No capacity check in the original.
static void THISCALL insertUnique(u8 *self, u32 value) {
  u32 *count = (u32 *)(self + 0x8b4);
  u32 *arr = (u32 *)(self + 0x8b8);
  u32 n = *count;
  for (u32 i = 0; i < n; i++) {
    if (arr[i] == value)
      return;
  }
  arr[*count] = value;
  *count += 1;
}
PCREG(46abf0, insertUnique);

// 0x4ce180, thiscall (ret 4): clears bit idx & (size-1) of a u32 bitmap (this+4, size this+8, power of two), then
// links that index into a free chain: this+0xc holds the head (-1 when empty), this+0x10 is a counter, decremented.
// Name unknown.
static void THISCALL bitmapFreeIndex(u8 *self, u32 idx) {
  u32 size = *(u32 *)(self + 8);
  u32 mask = 0u - size;
  u32 i = idx & (size - 1);
  u32 *bits = *(u32 **)(self + 4);
  bits[i] &= mask;
  if (*(s32 *)(self + 0xc) == -1)
    *(u32 *)(self + 0xc) = i;
  bits[i] |= *(u32 *)(self + 0xc);
  *(u32 *)(self + 0x10) -= 1;
  *(u32 *)(self + 0xc) = i;
}
PCREG(4ce180, bitmapFreeIndex);

// 0x613ae0, thiscall (no stack args, returns a pointer): if the u16 at this+2 is 0xffff returns 0. Otherwise moves
// the u16 at node+0x10 into this+2, where node = this + 24 * old value, clears the node's fields, bumps the byte at
// this+0, and returns node+0x10. Name unknown.
static u32 THISCALL advanceSlot(u8 *self) {
  u16 w = *(u16 *)(self + 2);
  if (w == 0xffff)
    return 0;
  u8 *node = self + (u32)w * 24u;
  *(u16 *)(self + 2) = *(u16 *)(node + 0x10);
  *(u16 *)(node + 0x1c) = 0;
  *(u32 *)(node + 0x20) = 0;
  *(u32 *)(node + 0x24) = 0;
  *(u32 *)(node + 0x10) = 0;
  *(u32 *)(node + 0x14) = 0xffff1205u;
  *(u32 *)(node + 0x18) = 0;
  self[0] += 1;
  return (u32)(node + 0x10);
}
PCREG(613ae0, advanceSlot);

// 0x439230, stdcall (ret 4): searches the global table at 0x6e48c0 (16-byte entries, key in the first dword, a zero key
// ends the table) for key. Returns the address 0x6e48b8 + 16 * index of the matching entry, or 0 when not found.
// Name unknown.
static u32 STDCALL findTableSlot(u32 key) {
  u32 idx = 0;
  u32 k = G(u32, 0x6e48c0);
  if (k == 0)
    return 0;
  while (key != k) {
    idx++;
    k = G(u32, 0x6e48c0 + idx * 16);
    if (k == 0)
      return 0;
  }
  return 0x6e48b8u + idx * 16;
}
PCREG(439230, findTableSlot);
