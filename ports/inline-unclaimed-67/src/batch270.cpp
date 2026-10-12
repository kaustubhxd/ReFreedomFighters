// batch270.cpp - unclaimed area 67, the switch at 0x573ba0 (pure: table of constants, default 0).
#include "ff.h"

// 0x573ba0, stdcall (ret 4, one argument x): x > 12 gives 0; x in 0..12 gives the case constant from the switch table.
static u32 STDCALL switchConst(u32 x) {
  static const u32 table[13] = {0x6a9018, 0x6a902c, 0x6a9044, 0x6a905c, 0x6a9074, 0x6a9080, 0x6a908c,
                                0x6a909c, 0x6a90ac, 0x6a90bc, 0x6a90cc, 0x6a90dc, 0x6a90f0};
  if (x > 12)
    return 0;
  return table[x];
}
PCREG(573ba0, switchConst);
