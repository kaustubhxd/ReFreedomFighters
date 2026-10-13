// batch13.cpp - first-level functions, inline session batch 13 (Haiku, overnight).
#include "ff.h"

// 0x613a70, thiscall (no stack args, returns a pointer or 0): like advanceSlot (0x613ae0) with 0x8c-byte nodes and the
// marker 0xffff1203, and more fields cleared. Name unknown.
static u32 THISCALL advanceSlot8c(u8 *self) {
  u16 w = *(u16 *)(self + 2);
  if (w == 0xffff)
    return 0;
  u8 *node = self + (u32)w * 0x8cu;
  *(u16 *)(self + 2) = *(u16 *)(node + 0x10);
  *(u32 *)(node + 0x10) = 0;
  *(u32 *)(node + 0x14) = 0xffff1203u;
  *(u32 *)(node + 0x48) = 0;
  *(u16 *)(node + 0x4d) = 0;
  *(u32 *)(node + 0x54) = 0;
  *(u32 *)(node + 0x50) = 0;
  node[0x4c] = 0;
  *(u32 *)(node + 0x58) = 0;
  node[0x4f] = 0;
  self[0] += 1;
  return (u32)(node + 0x10);
}
PCREG(613a70, advanceSlot8c);

// 0x613b30, thiscall (no stack args, returns a pointer or 0): like advanceSlot but with 28-byte nodes and the marker
// 0xffff1206. Name unknown.
static u32 THISCALL advanceSlot28(u8 *self) {
  u16 w = *(u16 *)(self + 2);
  if (w == 0xffff)
    return 0;
  u8 *node = self + (u32)w * 28u;
  *(u16 *)(self + 2) = *(u16 *)(node + 0x10);
  *(u32 *)(node + 0x10) = 0;
  *(u32 *)(node + 0x14) = 0xffff1206u;
  *(u32 *)(node + 0x18) = 0;
  *(u32 *)(node + 0x24) = 0;
  *(u32 *)(node + 0x1c) = 0;
  *(u32 *)(node + 0x20) = 0;
  *(u32 *)(node + 0x28) = 0;
  self[0] += 1;
  return (u32)(node + 0x10);
}
PCREG(613b30, advanceSlot28);

// 0x648630, thiscall (no stack args, returns a pointer or 0): like advanceSlot with 120-byte nodes, a vtable word
// 0x6bdab4 and the marker 0xffff1201. Name unknown.
static u32 THISCALL advanceSlot120(u8 *self) {
  u16 w = *(u16 *)(self + 2);
  if (w == 0xffff)
    return 0;
  u8 *node = self + (u32)w * 120u;
  *(u16 *)(self + 2) = *(u16 *)(node + 0x10);
  *(u32 *)(node + 0x14) = 0;
  *(u32 *)(node + 0x18) = 0xffff1201u;
  *(u32 *)(node + 0x1c) = 0;
  *(u32 *)(node + 0x10) = 0x6bdab4u;
  node[0x80] = 0;
  *(u32 *)(node + 0x84) = 0;
  self[0] += 1;
  return (u32)(node + 0x10);
}
PCREG(648630, advanceSlot120);

// 0x6069f0, fastcall (dst in ECX, end in EDX, src pointer on the stack, ret 4): fills the dwords from dst up to end
// with the dword that src points to. The count is (end - dst + 3) / 4 and is 0 when dst is above end (unsigned).
// Name unknown.
static void FASTCALL fillDwords(u8 *dst, u8 *end, const u8 *src) {
  u32 count = (u32)(end - dst) + 3;
  count >>= 2;
  if ((u32)dst > (u32)end)
    count = 0;
  for (u32 i = 0; i < count; i++) {
    *(u32 *)dst = *(const u32 *)src;
    dst += 4;
  }
}
PCREG(6069f0, fillDwords);
