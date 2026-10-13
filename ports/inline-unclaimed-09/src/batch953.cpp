// batch953.cpp - area 56 band (claim A12): 0x537a70, thiscall, one stack argument, stores it at this+0x5302, returns true.
#include "ff.h"

// 0x537a70 (unnamed; band list): dword this+0x5302 = argument; returns true in al.
static u8 THISCALL store537a70(u8 *self, u32 a) {
  *(u32 *)(self + 0x5302) = a;
  return 1;
}
PCREG(537a70, store537a70);
