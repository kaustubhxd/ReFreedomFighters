// batch33031.cpp - h3 batch 33031: field copies and conditional logic
#include "ff.h"

// 0x5d4210, thiscall: copy fields from arg to this at offsets 0x56,0x5a,0x5b,0x5f,0x63,0x67,0x6b
static void THISCALL fn5d4210(u8 *self, u8 *arg) {
  *(u32 *)(self + 0x56) = *(u32 *)(arg + 0x56);
  *(u8 *)(self + 0x5a) = *(u8 *)(arg + 0x5a);
  *(u32 *)(self + 0x5b) = *(u32 *)(arg + 0x5b);
  *(u32 *)(self + 0x5f) = *(u32 *)(arg + 0x5f);
  *(u32 *)(self + 0x63) = *(u32 *)(arg + 0x63);
  *(u32 *)(self + 0x67) = *(u32 *)(arg + 0x67);
  *(u32 *)(self + 0x6b) = *(u32 *)(arg + 0x6b);
}
PCREG(5d4210, fn5d4210);

// 0x537790, thiscall: check field at 0x5302, test arg, conditional comparisons
static u32 THISCALL fn537790(u8 *self, u32 arg) {
  u32 field = *(u32 *)(self + 0x5302);
  if (!field) return 0;
  if (!arg) return 0;
  u32 val = *(u32 *)arg;
  if (val == 1 || val == 2) {
    u32 result = *(u32 *)(arg + 8);
    if (result) return result;
  }
  return 0;
}
PCREG(537790, fn537790);
