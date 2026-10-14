// u69_13.cpp - area 69, group 13 (unclaimed-69 thread).
#include "ff.h"

extern "C" void ext_61be30(void *p);  // cdecl helper, other area (stubbed in the spec: GUESS)

// 0x61bbd0, thiscall with no stack args (ret). Passes the dword at self+4 to ext_61be30 as its one cdecl argument; the caller pops it.
static void THISCALL wrapper61bbd0(u8 *self) {
  ext_61be30(*(void **)(self + 4));
}
PCREG(61bbd0, wrapper61bbd0);
