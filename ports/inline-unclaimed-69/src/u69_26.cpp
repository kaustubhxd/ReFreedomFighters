// u69_26.cpp - area 69, group 26 (slice 8). stdcall, three stack args (ret 0xc): zeroes *p and returns 0. No callees.
#include "ff.h"

static u32 STDCALL zeroFirst607a00(u32 *p, char *buf, u32 n) {
  *p = 0;
  return 0;
}
PCREG(607a00, zeroFirst607a00);
