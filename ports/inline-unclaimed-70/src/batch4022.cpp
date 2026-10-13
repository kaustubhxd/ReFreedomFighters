// batch4022.cpp - area 70 (slice 4/5), batch 4022: 0x440ed0 and 0x4d28d0 (names GUESS). Exe callees 0x610420 and 0x4cee30
// are stubbed by address in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_610420(void *self, u32 a1, u32 a2, u32 a3, u32 a4);   // exe: stubbed by address, ret 0x10
extern "C" void THISCALL ext_4cee30(void *self, u32 a, u32 b);                    // exe: stubbed by address, ret 8

// 0x440ed0 (name GUESS): stdcall, four stack arguments, ret 0x10. r = slot 0x58 of the render manager (engine global
// 0x70039c, +0x9b), given the dword at [rm+0x14]. If r is zero, returns 0; otherwise calls 0x610420 with ECX = r and the four
// arguments, and returns 1.
static u8 STDCALL callRm440ed0(u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 *sys = G(u8 *, 0x70039c);
  void *rm = *(void **)(sys + 0x9b);
  u32 r = vcall<u32>(rm, 0x58, *(u32 *)((u8 *)rm + 0x14));
  if (r == 0) return 0;
  ext_610420((void *)r, a1, a2, a3, a4);
  return 1;
}
PCREG(440ed0, callRm440ed0);

// 0x4d28d0 (name GUESS): thiscall, no arguments, plain ret. Calls 0x4cee30 with ECX = this+0x40b4 and arguments (0, 0x4000);
// then calls slot 0xc of the vtable stored at [this+0x4008] with ECX = this+0x4008; then stores this+4 at [this+0x4004].
static void THISCALL init4d28d0(u8 *self) {
  ext_4cee30(self + 0x40b4, 0, 0x4000);
  vcall<void>(self + 0x4008, 0xc);
  *(u32 *)(self + 0x4004) = (u32)(self + 4);
}
PCREG(4d28d0, init4d28d0);
