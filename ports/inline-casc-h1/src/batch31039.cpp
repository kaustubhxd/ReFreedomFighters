#include "ff.h"

// 0x52b370: 13 insns, thiscall(param) ret 4: calculated offset return or zero
u32 THISCALL fn_52b370(u8 *self, u32 param) {
  if (param == 0) return 0;
  u32 base = *(u32 *)(self + 0x7d);
  return base + param*8 - 8;
}
PCREG(52b370, fn_52b370);

// 0x4e5310: 14 insns, thiscall(param) ret 4: field check with conditional return
u32 THISCALL fn_4e5310(u8 *self, u32 *param) {
  u32 field = *(u32 *)(param + 0x13);
  if (field != 0) {
    return field;
  }
  return 0;
}
PCREG(4e5310, fn_4e5310);

// 0x5df690: 17 insns, thiscall(p1, p2, p3): copy three params to fields
void THISCALL fn_5df690(u8 *self, u32 param1, u32 param2, u32 param3) {
  *(u32 *)(self + 4) = param1;
  *(u32 *)(self + 8) = param2;
  *(u32 *)(self + 0xc) = param3;
}
PCREG(5df690, fn_5df690);
