// batch5768.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 68: 0x5d5ae0 (GUESS name unnamed_5d5ae0), thiscall, one stack
// argument a (ret 4), no return value. Order: 0x610100(a) (stdcall, a plain ret 4 in the original; runs as original code);
// 0x4e12e0(ECX = a, this+0x1d, 1); 0x4e12e0(ECX = a, this+0x21, 1); 0x4e12e0(ECX = a, &a, 1); 0x4e14a0(ECX = a, this+0x31, 1);
// this+0x25 = (engine 0x70039c)+0x9b ->vt[+0x58](a). The helpers 0x4e12e0 and 0x4e14a0 run as hooked stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);

extern "C" void STDCALL ext_610100(u32 a);  // plain ret 4, original code
extern "C" void THISCALL ext_4e12e0(u8 *self, u32 p, u32 v);  // helper, original code (hooked in the spec)
extern "C" void THISCALL ext_4e14a0(u8 *self, u32 p, u32 v);  // helper, original code (hooked in the spec)

// 0x5d5ae0, thiscall, one stack argument (GUESS name)
static void THISCALL unnamed5d5ae0(u8 *self, u32 a) {
  ext_610100(a);
  ext_4e12e0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x1d), 1);
  ext_4e12e0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x21), 1);
  ext_4e12e0((u8 *)(unsigned long)a, (u32)(unsigned long)&a, 1);
  ext_4e14a0((u8 *)(unsigned long)a, (u32)(unsigned long)(self + 0x31), 1);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x25) = ((SlotA)VT(sub)[0x58 / 4])(sub, a);
}
PCREG(5d5ae0, unnamed5d5ae0);
