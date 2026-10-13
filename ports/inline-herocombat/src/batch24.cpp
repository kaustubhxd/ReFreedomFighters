// batch24.cpp - first-level functions, inline session batch 24 (Haiku, overnight).
#include "ff.h"

// 0x4cc4d0, fastcall (p in ECX, n in EDX, plain ret, returns EAX): steps back from p over UTF-8 continuation bytes and
// returns the first byte that is a lead byte (<= 0x7f, or bit 0x40 set). The walk stops at p - n when n > 0, otherwise
// at address 0. Name unknown.
static u8 *FASTCALL utf8Back(u8 *p, s32 n) {
  u32 limit = (n > 0) ? (u32)(unsigned long)p - (u32)n : 0;
  u8 a = *p;
  if (a <= 0x7f)
    return p;
  for (;;) {
    if (a & 0x40)
      return p;
    if ((u32)(unsigned long)p <= limit)
      return p;
    a = p[-1];
    p--;
    if (a <= 0x7f)
      return p;
  }
}
PCREG(4cc4d0, utf8Back);

// 0x4ba310, thiscall, no args, plain ret: sets dwords at +0x51 (1.0f), +0x55, +0x59 (0x469c4000), +0x5d, +0x61, +0x65,
// +0x71 to 0 or the constants shown, and clears the dword at +0x85. The float at +0x69 is 1/1024 times the int at
// global+0x44, the float at +0x81 is 1/1024 times the int at global+0x40, where the global is the pointer at 0x70039c.
// The dword at +0x89 is masked with 0xffffffb1 first. Name unknown.
static void THISCALL initScales(u8 *self) {
  *(u32 *)(self + 0x89) &= 0xffffffb1u;
  *(u32 *)(self + 0x51) = 0x3f800000u;
  *(u32 *)(self + 0x55) = 0;
  *(u32 *)(self + 0x59) = 0x469c4000u;
  *(u32 *)(self + 0x61) = 0;
  *(u32 *)(self + 0x5d) = 0;
  *(u32 *)(self + 0x65) = 0;
  *(u32 *)(self + 0x71) = 0;
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  float f = (float)*(s32 *)(g + 0x44) * G(float, 0x6785e4);
  *(float *)(self + 0x69) = f;
  float h = (float)*(s32 *)(g + 0x40) * G(float, 0x6785e4);
  *(u32 *)(self + 0x85) = 0;
  *(float *)(self + 0x81) = h;
}
PCREG(4ba310, initScales);

// 0x493140, thiscall (ret 4): pushes node onto a list whose head is the dword at this+0x5d29. The node takes the old
// value of the counter at this+0x10 at +0x20, the counter at this+0x10 and the dword at this+0x5d2d go up by one, the
// node's +0x24 is cleared and its +0x28 gets the old head (whose +0x24 is set to the node first). The head becomes the
// node; when the byte at this+0xbc2 is not zero the node's dword at +4 gets 0x10 or-ed in. Name unknown.
static void THISCALL pushNode(u8 *self, u8 *node) {
  *(u32 *)(node + 0x20) = *(u32 *)(self + 0x10);
  *(u32 *)(self + 0x10) += 1;
  *(u32 *)(self + 0x5d2d) += 1;
  u32 head = *(u32 *)(self + 0x5d29);
  if (head != 0)
    *(u32 *)(head + 0x24) = (u32)(unsigned long)node;
  *(u32 *)(node + 0x24) = 0;
  *(u32 *)(node + 0x28) = *(u32 *)(self + 0x5d29);
  u8 flag = self[0xbc2];
  *(u32 *)(self + 0x5d29) = (u32)(unsigned long)node;
  if (flag != 0)
    *(u32 *)(node + 4) |= 0x10;
}
PCREG(493140, pushNode);
