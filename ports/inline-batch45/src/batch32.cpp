// batch32.cpp - walk-tree lift, inline session batch 32 (Haiku, night): GetAnimFromStatus.
#include "ff.h"

typedef void *(THISCALL *vcall0)(void *self);
typedef void *(THISCALL *vcall1)(void *self, u32 arg);

// 0x5e3dd0, thiscall, one stack arg (status), ret 4, returns a pointer. Two paths on status & 3.
// (1) status & 3 == 0: P = [this+4], v = [P+0x417]; the result is this + off, where off is 0x433 when v has bit 0x8000000,
//     else 0x41b when v has bit 0x400, else 0x403.
// (2) otherwise the anim object is this+0x523 when status has bit 0x10000000, else the value of the virtual call through
//     [vtable+0x60] (bit 1 of status set) or [vtable+0x64] (bit 1 clear) on this. Then the result is the virtual call
//     [vtable(obj)+0x10] with an argument of 2 (bit 4), 3 (bit 8), 4 (bit 0x10) or 1 (none of those).
// The result is then checked: if the dword at it equals 0xedededed, the hook at 0x7003b0 is called when set, else the original
// executes int3 (trap). Name ZFFHeroMovementBaseMove::GetAnimFromStatus.
static u8 *THISCALL getAnimFromStatus(u8 *self, u32 status) {
  u8 *esi;
  if ((status & 3) == 0) {
    u8 *p = *(u8 **)(self + 4);
    u32 v = *(u32 *)(p + 0x417);
    u32 off;
    if (v & 0x8000000u)
      off = 0x433;
    else
      off = (v & 0x400u) ? 0x41b : 0x403;
    esi = self + off;
  } else {
    u8 *obj;
    if (status & 0x10000000u) {
      obj = self + 0x523;
    } else {
      void **vt = *(void ***)self;
      if (status & 1)
        obj = (u8 *)((vcall0)vt[0x60 / 4])(self);
      else
        obj = (u8 *)((vcall0)vt[0x64 / 4])(self);
    }
    void **ovt = *(void ***)obj;
    u32 arg;
    if (status & 4)
      arg = 2;
    else if (status & 8)
      arg = 3;
    else if (status & 0x10)
      arg = 4;
    else
      arg = 1;
    esi = (u8 *)((vcall1)ovt[0x10 / 4])(obj, arg);
  }
  if (esi != 0 && *(u32 *)esi == 0xededededu) {
    void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
    if (hook != 0)
      hook();
    else
      __builtin_trap();
  }
  return esi;
}
PCREG(5e3dd0, getAnimFromStatus);
