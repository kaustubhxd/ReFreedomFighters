// batch1009.cpp - unclaimed-04 batch 9 (docs/20-unclaimed-04.md): CMsgForward::Command (0x49efb0, high name).
// thiscall, two stack arguments (ret 8): msg (dword, only the low 16 bits are compared) and data (pointer).
// The manager is the object the global at 0x70039c points to; its manager (at +0x9b) gets vtable slot 0x58 with this+0x48.
// The destination (this+0x44) gets vtable slot 0x130 with (target, msg, data). Both vtable slots are unverified (GUESS).
#include "ff.h"

typedef u32(THISCALL *fn1_t)(void *self, u32 a);
typedef void(THISCALL *fn3_t)(void *self, u32 a, u32 b, u32 c);

// 0x49efb0. Returns 0 in every path.
static u32 THISCALL msgForwardCommand(u8 *self, u32 msg, u32 data) {
  if (self[4] & 1) return 0;

  u8 *mgr = *(u8 **)0x70039c;
  u8 *m = *(u8 **)(mgr + 0x9b);
  u32 target = ((fn1_t)(*(u32 *)(*(u32 *)m + 0x58)))(m, *(u32 *)(self + 0x48));
  if (target == 0) return 0;

  u8 *dest = *(u8 **)(self + 0x44);
  if ((u32)dest == target) return 0;

  u16 filter = *(u16 *)(self + 0x4c);
  if (filter != 0 && filter != (u16)msg) return 0;

  ((fn3_t)(*(u32 *)(*(u32 *)dest + 0x130)))(dest, target, msg, data);
  return 0;
}
PCREG(49efb0, msgForwardCommand);
