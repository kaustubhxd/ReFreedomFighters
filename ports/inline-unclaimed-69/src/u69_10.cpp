// u69_10.cpp - area 69, group 10 (unclaimed-69 thread).
#include "ff.h"

// 0x5f2e10, SerialInfo_t::loadbool(bool& out) (GC map medium). thiscall, one stack arg (ret 4). The cursor at +8 must leave
// four bytes before the end at +0xc; otherwise the assert hook at 0x7003b0 is called (or the code traps when it is null) and
// execution goes on. Then the dword at the cursor is read, the cursor advances by four, and out = (dword != 0).
static void THISCALL serialInfoLoadBool(u8 *self, u8 *out) {
  u32 cursor = *(u32 *)(self + 8);
  if (cursor + 4 > *(u32 *)(self + 0xc)) {
    typedef void (*assertfn)();
    assertfn hook = G(assertfn, 0x7003b0);
    if (hook)
      hook();
    else
      __builtin_trap();
  }
  cursor = *(u32 *)(self + 8);
  u32 value = *(u32 *)cursor;
  *(u32 *)(self + 8) = cursor + 4;
  *out = (value != 0) ? 1 : 0;
}
PCREG(5f2e10, serialInfoLoadBool);
