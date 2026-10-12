// batch1607.cpp - unclaimed-16 batch 7 (docs/20-unclaimed-16.md): ZInputActions::GetActionBase(const char*) (high).
// The helper at 0x4d8fc0 (name lookup, thiscall with the object at this+0x1330 and one argument) is original code
// called through ext_4d8fc0; the spec stubs it so the result is chosen per case. Not verified: the helper.
#include "ff.h"

extern "C" u32 THISCALL ext_4d8fc0(u8 *obj, u32 name); // name lookup, original code (stubbed in the spec)

// 0x438bc0, ZInputActions::GetActionBase(const char*): p = ext_4d8fc0(this+0x1330 object, name). Returns 0 if p is 0.
// If the dword at p is 0 or 1, stores (dword p+8 ? dword p+8 - 4 : 0) at this+0x1334. Returns p in every other case.
static u32 THISCALL inputGetActionBase(u8 *self, u32 a1) {
  u8 *obj = *(u8 **)(self + 0x1330);
  u32 p = ext_4d8fc0(obj, a1);
  if (p == 0)
    return 0;
  u32 v = *(u32 *)p;
  if (v == 0 || v == 1) {
    u32 c = *(u32 *)(p + 8);
    *(u32 *)(self + 0x1334) = (c != 0) ? c - 4 : 0;
  }
  return p;
}
PCREG(438bc0, inputGetActionBase);
