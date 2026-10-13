#include "ff.h"
// batch3521.cpp - area 35 claim 21 (docs/20-unclaimed-35.md): 0x4a5820, ZMatPosAnim::ExpandBounds(float*, float*, float*, ZBaseGeom*)
// (residue name). Thiscall, four args (ret 0x10). Its float argument is this+0xc7, pushed onto the stack as a float.
// Stubbed in the harness: slot +0x4c and +0x98 of this+0x44 (logging), 0x4e7880, 0x4e7530 (thiscall, stack args; ecx is a
// stack address and is not logged), 0x4de420 (fastcall, logs ecx and edx).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a0);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a0, u32 a1);

extern "C" u32 THISCALL ext_4e7880(u8 *self, u32 a0, u32 a1, u32 a2, float a3);
extern "C" void THISCALL ext_4e7530(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern "C" u32 FASTCALL ext_4de420(u32 a0, u32 a1);

// 0x4a5820, ZMatPosAnim::ExpandBounds(...) (residue name).
void THISCALL matPosAnimExpandBounds(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3) {
  (void)a3;
  if (!*(u8 *)(self + 0xd4))
    return;
  u8 *A = *(u8 **)(self + 0x44);
  u32 esi = ((Slot1)*(u32 *)(*(u32 *)A + 0x4c))(A, 0x4b455953);
  float f = *(float *)(self + 0xc7);
  u32 local = 0;
  u32 mgr = *(u32 *)0x70039c;
  ext_4e7880((u8 *)&local, esi, *(u32 *)(mgr + 0x40), *(u8 *)(self + 0xc4), f);
  u8 *S = *(u8 **)(A + 8);
  ext_4e7530((u8 *)&local, a1, a2, (u32)(S + 0x30), (u32)(S + 0x40), *(u8 *)(self + 0xc6));
  ext_4de420(a0, (u32)S);
  ((Slot2)*(u32 *)(*(u32 *)A + 0x98))(A, a0, a1);
}
PCREG(4a5820, matPosAnimExpandBounds);
