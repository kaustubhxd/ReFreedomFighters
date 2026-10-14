// batch33028.cpp - h3 batch 33028: conditional add and field initialization
#include "ff.h"

// 0x537770, thiscall: load field at 0x5302, if nonzero add arg to it, return result
static u32 THISCALL fn537770(u8 *self, u32 arg) {
  u32 val = *(u32 *)(self + 0x5302);
  if (!val) return 0;
  if (!arg) return 0;
  return arg + val;
}
PCREG(537770, fn537770);

// 0x5df5f0, thiscall with 3 args: store at self+4/8/c and constant at self+0
static void THISCALL fn5df5f0(u8 *self, u32 arg1, u32 arg2, u32 arg3) {
  *(u32 *)(self + 0x04) = arg1;
  *(u32 *)(self + 0x08) = arg2;
  *(u32 *)(self + 0x0c) = arg3;
  *(u32 *)(self + 0x00) = 0x6b7478;
}
PCREG(5df5f0, fn5df5f0);
