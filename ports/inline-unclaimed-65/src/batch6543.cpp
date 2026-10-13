// batch6543.cpp - unclaimed-65: batch 43 (docs/20-unclaimed-65.md, claim 23): 0x4d2330, the destructor of the class whose vtable is
// 0x696220 then 0x696168. Plain thiscall, no arguments. The SEH frame and the cookie are not reproduced (tagged in the doc).
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }

extern "C" void THISCALL ext_4cee30(u8 *self, u32 a, u32 b);   // thiscall, two arguments (ret 8)
extern "C" void THISCALL ext_4cd180(u8 *self);                 // plain
extern "C" void THISCALL ext_4ccf60(u8 *self);                 // plain

// 0x4d2330, the destructor body (the prologue and epilogue of the SEH frame are not reproduced).
static void THISCALL classDtor4d2330(u8 *self) {
  *(u32 *)self = 0x696220;
  ext_4cee30(self + 0x40b4, 0, 0x4000);
  vc0(self + 0x4008, 0xc);
  *(u32 *)(self + 0x4004) = (u32)(self + 4);
  ext_4cd180(self + 0x40b4);
  ext_4ccf60(self + 0x4008);
  *(u32 *)self = 0x696168;
}

PCREG(4d2330, classDtor4d2330);
