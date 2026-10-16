// batch5771.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 71: 0x5d8cf0 (GUESS name unnamed_5d8cf0), thiscall, one stack
// argument a (ret 4), no return value. Order: 0x610100(a) (stdcall, plain ret 4 in the original; runs as original code);
// 0x4e12e0(ECX = a, this+0x28, 1); 0x4e11e0(ECX = a, this+0x2c, 1); 0x4e11e0(this+0x30); 0x4e11e0(this+0x3c); 0x4e11e0(this+0x40);
// 0x4e12f0(ECX = a, this+0x38, 1). The helpers run as hooked stubs in the spec.
#include "ff.h"

extern "C" void STDCALL ext_610100(u32 a);  // plain ret 4, original code
extern "C" void THISCALL ext_4e12e0(u8 *self, u32 p, u32 v);  // helper, original code (hooked in the spec)
extern "C" void THISCALL ext_4e11e0(u8 *self, u32 p, u32 v);  // helper, original code (hooked in the spec)
extern "C" void THISCALL ext_4e12f0(u8 *self, u32 p, u32 v);  // helper, original code (hooked in the spec)

// 0x5d8cf0, thiscall, one stack argument (GUESS name)
static void THISCALL unnamed5d8cf0(u8 *self, u32 a) {
  ext_610100(a);
  ext_4e12e0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x28), 1);
  ext_4e11e0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x2c), 1);
  ext_4e11e0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x30), 1);
  ext_4e11e0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x3c), 1);
  ext_4e11e0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x40), 1);
  ext_4e12f0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x38), 1);
}
PCREG(5d8cf0, unnamed5d8cf0);
