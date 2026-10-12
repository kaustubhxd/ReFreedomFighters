#include "ff.h"
// batch929.cpp - unclaimed-80 claim 9 (docs/20-unclaimed-80.md). CFireController::AddActorOnFire(unsigned int, float, unsigned
// int) (0x581870, map name). Thiscall, three arguments (a1, arg2 float bits, arg3), ret 12.
// The table at this+0x50 holds up to seven 28-byte entries; the count is at +0x4c. If a1 is already an entry, nothing happens.
// Otherwise: b = (sub-object at 0x70039c+0x9b) slot +0x58 (no arguments); frame[0] = a1, frame[4] = arg3, frame[0x14] = arg2 bits;
// b slot +0x384 with (frame+0x1c, frame+8) (two stack pointers; the callee writes a 3-float vector to frame+8);
// if the global flag at 0x70039c+0x1a9f is nonzero and the count is below 7, edx = 0x466f60(b, this+0xa5c) (original code,
// stubbed by the spec); otherwise edx = 0. The entry is frame[0..0x18] + edx, appended; the count is incremented.

extern "C" u32 THISCALL ext_466f60(u8 *obj, u32 arg);   // (thiscall, one argument, original code)

static void THISCALL fireAddActorOnFire(u8 *self, u32 a1, u32 arg2, u32 arg3) {
  u32 count = *(u32 *)(self + 0x4c);
  u8 *base = self + 0x50;
  u8 *end = base + count * 0x1c;
  for (u8 *p = base; p != end; p += 0x1c) {
    if (*(u32 *)p == a1)
      return;
  }
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  typedef u8 *(THISCALL * r0_fn)(u8 *);
  u8 *b = ((r0_fn)(*(u32 *)(*(u32 *)sub + 0x58)))(sub);
  u8 fr[0x30] = {0};
  *(u32 *)(fr + 0x14) = arg2;
  *(u32 *)(fr + 4) = arg3;
  *(u32 *)(fr + 0) = a1;
  typedef void(THISCALL * v2_fn)(u8 *, u32, u32);
  ((v2_fn)(*(u32 *)(*(u32 *)b + 0x384)))(b, (u32)(fr + 0x1c), (u32)(fr + 8));
  u32 edx = 0;
  if (*(u32 *)(G(u8 *, 0x70039c) + 0x1a9f) != 0 && *(u32 *)(self + 0x4c) < 7)
    edx = ext_466f60(b, *(u32 *)(self + 0xa5c));
  u8 *entry = base + *(u32 *)(self + 0x4c) * 0x1c;
  for (u32 i = 0; i < 0x10; i++)
    entry[i] = fr[i];
  for (u32 i = 0; i < 8; i++)
    entry[0x10 + i] = fr[0x10 + i];
  *(u32 *)(entry + 0x18) = edx;
  *(u32 *)(self + 0x4c) += 1;
}
PCREG(581870, fireAddActorOnFire);
