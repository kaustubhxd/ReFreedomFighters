#include "ff.h"

// 0x466600: 7 insns, thiscall(byte_param) ret 4: byte swap
u8 THISCALL fn_466600(u8 *self, u8 new_val) {
  u8 old_val = *self;
  *self = new_val;
  return old_val;
}
PCREG(466600, fn_466600);

// 0x475910: 7 insns, thiscall(byte_param) ret 4: conditional byte setter
void THISCALL fn_475910(u8 *self, u8 param) {
  self[0x3bb] = (param != 0) ? 1 : 0;
}
PCREG(475910, fn_475910);
