// batch1012.cpp - unclaimed-04 batch 12 (docs/20-unclaimed-04.md): ZFenceGate::Command (0x5c2630, high name).
// thiscall, two stack arguments (ret 8). msg is compared as a word with three words in the image (0x71432c, 0x714330,
// 0x714334). The first sets this+0x25b, gets a target from the manager (global 0x70039c, +0x9b, slot 0x58 with this+0x50),
// and when the target is non-null calls the manager's slot 0x114 (RegisterZMsg, four arguments, ret 0x10), then the
// target's slot 0x12c with the low word of the result and the two values the exe leaves on the stack (0x3e8, 0).
// The second and third words set and clear this+0x25a.
#include "ff.h"

typedef u32(THISCALL *fn1_t)(void *self, u32 a);
typedef u32(THISCALL *fn4_t)(void *self, u32 a, u32 b, u32 c, u32 d);
typedef void(THISCALL *fn12c_t)(void *self, u32 a, u32 b, u32 c);

// 0x5c2630
static u32 THISCALL fenceGateCommand(u8 *self, u32 msg, u32 data) {
  (void)data;
  u16 m = (u16)msg;
  if (m == *(u16 *)0x71432c) {
    self[0x25b] = 1;
    u8 *g = *(u8 **)0x70039c;
    u8 *mgr = *(u8 **)(g + 0x9b);
    u32 target = ((fn1_t)(*(u32 *)(*(u32 *)mgr + 0x58)))(mgr, *(u32 *)(self + 0x50));
    if (target) {
      // the exe pushes 0, 0x3e8, 0x4f, 0x6b3cdc, 0, 0x68fee8; slot 0x114 pops four of them, and 0x3e8 and 0 stay on
      // the stack as the 2nd and 3rd arguments of the next call
      u16 id = (u16)((fn4_t)(*(u32 *)(*(u32 *)mgr + 0x114)))(mgr, 0x68fee8, 0, 0x6b3cdc, 0x4f);
      ((fn12c_t)(*(u32 *)(*(u32 *)target + 0x12c)))((void *)target, (u32)id, 0x3e8, 0);
    }
    return 0;
  }
  if (m == *(u16 *)0x714330) {
    self[0x25a] = 1;
    return 0;
  }
  if (m == *(u16 *)0x714334) {
    self[0x25a] = 0;
    return 0;
  }
  return 0;
}
PCREG(5c2630, fenceGateCommand);
