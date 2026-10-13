// batch5.cpp - first-level functions, inline session batch 5 (Haiku, 2026-10-09 evening).
// Names marked "guessed" come from the body only.
#include "ff.h"

// 0x4cf290, thiscall (ret 4): list step. *p == 0 selects this+0x1c, else (*p)->next (+4); stores the chosen node
// back into *p. Returns node + 4 * (2 - this+0x18) when the node is non-NULL, else 0. Class name unknown.
static u32 THISCALL stepNodeA(u8 *self, u32 *p) {
  u32 node = *p;
  if (node != 0)
    node = *(u32 *)(node + 4);
  else
    node = *(u32 *)(self + 0x1c);
  u32 ecx = node;
  *p = node;
  if (ecx == 0)
    return 0;
  u32 k = 2u - *(u32 *)(self + 0x18);
  return ecx + k * 4;
}
PCREG(4cf290, stepNodeA);

// 0x4cf470, thiscall (ret 4): same shape as 0x4cf290, but a non-NULL *p is dereferenced (+0), not +4, and a NULL
// *p selects this+0x20. Class name unknown.
static u32 THISCALL stepNodeB(u8 *self, u32 *p) {
  u32 node = *p;
  if (node != 0)
    node = *(u32 *)node;
  else
    node = *(u32 *)(self + 0x20);
  u32 ecx = node;
  *p = node;
  if (ecx == 0)
    return 0;
  u32 k = 2u - *(u32 *)(self + 0x18);
  return ecx + k * 4;
}
PCREG(4cf470, stepNodeB);

// 0x534050, thiscall (ret 4): walks the chain starting at index idx through 8-byte entries at this+0xc (entry = link,
// flag). Each visited entry gets link = head | 0x80000000, the head becomes the visited index, count (this+0) drops by
// one. Stops at the sentinel 0x80000000. Name guessed (pool release chain).
static void THISCALL releaseChain(u8 *self, u32 idx) {
  u32 edi = idx;
  if (edi == 0x80000000u)
    return;
  do {
    u32 eax = *(u32 *)(self + 4);
    u32 edx = edi * 8;
    u32 esi = edi;
    eax |= 0x80000000u;
    u32 *ent = (u32 *)(self + 0xc + edx);
    edi = *ent;
    *ent = eax;
    *(u32 *)self -= 1;
    *(u32 *)(self + 4) = esi;
  } while (edi != 0x80000000u);
}
PCREG(534050, releaseChain);

// 0x5f0190, thiscall (ret 4, returns AL): byte push into a buffer. count = this+4, capacity = this+0, data = this+8.
// If count + 1 > capacity (unsigned), sets this+0xc = 1 and returns 0; otherwise stores the low byte at data[count],
// increments count and returns 1. Name guessed (CBuffer::PushByte).
static u8 THISCALL pushByte(u8 *self, u32 v) {
  u32 count = *(u32 *)(self + 4);
  if (count + 1u > *(u32 *)self) {
    *(u8 *)(self + 0xc) = 1;
    return 0;
  }
  u8 *data = (u8 *)*(u32 *)(self + 8);
  data[count] = (u8)v;
  *(u32 *)(self + 4) = count + 1u;
  return 1;
}
PCREG(5f0190, pushByte);

// 0x5eade0, thiscall (ret 0x14): initialises a 16-byte record: [0]=a, [4]=b, [8]=c, [0xc] = w | (sign-extended s << 16)
// (w as a zero-extended word). Returns this. Name guessed (a cell with 3 dwords and two packed fields).
static u32 *THISCALL initCell(u32 *self, u32 a, u32 b, u32 c, u32 w, u32 s) {
  self[0] = a;
  self[1] = b;
  self[2] = c;
  u32 wz = (u16)w;
  s32 sx = (s8)(u8)s;
  self[3] = 0;
  self[3] = wz;
  self[3] |= ((u32)sx << 16);
  return self;
}
PCREG(5eade0, initCell);
