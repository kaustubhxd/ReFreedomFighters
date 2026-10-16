// batch5722.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 22: two small delete-calling functions (names GUESS).
// 0x49df00 (thiscall, no args, ret): p = dword this+4 (read first); vtable 0x68f008 at this+0; if p is non-zero, delete(p, 1).
// 0x63a700 (cdecl, one argument a, no pop): delete(dword at a-4, 1). Operator delete 0x634273 (cdecl, ptr and size) is an unverified
// callee run as original code; the spec logs its arguments.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 size);  // operator delete (cdecl), original code (logged in the spec)

// 0x49df00 (GUESS)
static void THISCALL unnamed49df00(u8 *self) {
  u32 p = *(u32 *)(self + 4);
  *(u32 *)self = 0x68f008;
  if (p) ext_634273((u8 *)(unsigned long)p, 1);
}
PCREG(49df00, unnamed49df00);

// 0x63a700 (GUESS)
static void unnamed63a700(u8 *a) {
  u32 p = *(u32 *)(a - 4);
  ext_634273((u8 *)(unsigned long)p, 1);
}
PCREG(63a700, unnamed63a700);
