// batch26.cpp - first-level functions, inline session batch 26 (Haiku, overnight).
#include "ff.h"

static inline u8 *P(u32 v) { return (u8 *)(unsigned long)v; }

// 0x4e4960, stdcall (ret 4): unlinks the node at the stack argument. Its +0 is the next link, +4 the previous link and
// +0x18 points at an object whose +0xc is the head when there is no previous link. Name unknown.
static void STDCALL unlinkNode(u8 *node) {
  u32 next = *(u32 *)node;
  u32 prev = *(u32 *)(node + 4);
  u8 *holder = P(*(u32 *)(node + 0x18));
  if (prev != 0)
    *(u32 *)P(prev) = next;
  else
    *(u32 *)(holder + 0xc) = next;
  u32 next2 = *(u32 *)node;
  if (next2 != 0)
    *(u32 *)(P(next2) + 4) = *(u32 *)(node + 4);
}
PCREG(4e4960, unlinkNode);

// 0x4f39a0, thiscall (ret 4), one byte stack argument: the object at this+0x6f gets dword +0x30 set to 5 when this+0x5fc
// is zero, or 0 otherwise. Then bit 0x8000 of its dword at +0x48 is set when the argument is nonzero and this+0x5fc is
// zero, and cleared otherwise. Name unknown.
static void THISCALL setFlag(u8 *self, u32 arg) {
  u8 on = (u8)arg;
  if (self[0x5fc] == 0)
    *(u32 *)(P(*(u32 *)(self + 0x6f)) + 0x30) = 5;
  else
    *(u32 *)(P(*(u32 *)(self + 0x6f)) + 0x30) = 0;
  if (on != 0 && self[0x5fc] == 0) {
    *(u32 *)(P(*(u32 *)(self + 0x6f)) + 0x48) |= 0x8000;
    return;
  }
  *(u32 *)(P(*(u32 *)(self + 0x6f)) + 0x48) &= 0xffff7fffu;
}
PCREG(4f39a0, setFlag);

// 0x4e4a50, thiscall (ret 8), two stack args: base (a pointer to the first dword is the base) and e. A null e sets the
// dword at +8 to 0. Otherwise the word at +8 is (e - base) >> 4 and the word at +0xa is the word at e+0xa plus one. Then
// the dwords at +0, +4 and +0xc are cleared. Name unknown.
static void THISCALL setIndex(u8 *self, u8 *base, u8 *e) {
  if (e == 0) {
    *(u32 *)(self + 8) = 0;
  } else {
    u32 idx = ((u32)(unsigned long)e - *(u32 *)base) >> 4;
    *(u16 *)(self + 8) = (u16)idx;
    *(u16 *)(self + 0xa) = (u16)(*(u16 *)(e + 0xa) + 1);
  }
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
}
PCREG(4e4a50, setIndex);
