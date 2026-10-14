// u69_27.cpp - area 69, group 27 (slice 8). thiscall, one stack arg (bool, ret 4). Follows self+0xc -> p, p+4 -> q, and stores the low byte of the arg at q+0x40. No callees.
#include "ff.h"

static void THISCALL setFlag40At5f1700(u8 *self, u32 flag) {
  u8 *p = *(u8 **)(self + 0xc);
  u8 *q = *(u8 **)(p + 4);
  q[0x40] = (u8)flag;
}
PCREG(5f1700, setFlag40At5f1700);
