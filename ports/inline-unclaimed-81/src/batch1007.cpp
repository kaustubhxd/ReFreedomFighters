// batch1007.cpp - area 81 (residue 0), batch 1007: CExplodeMolotov::Load(ZLoadGame *lg), 0x5846c0, thiscall, one stack argument, ret 4.
// No SEH frame, no cookie check. Stand-ins: 0x6352f0 (thiscall, one argument, GUESS), 0x584bc0 (CExplodeMolotov::ReadInput, thiscall, one
// argument), 0x4e7480 (thiscall, one argument lg, GUESS). The loop runs five times with strides 0x44 (this+0x222), 0xc (this+0x18d),
// 4 (this+0x179) and 0x2c (this+0x9d); the global chain at 0x7003b8 -> +0x2c51 gets this+0x222+0x44i-0x18 appended when the float at +0x28 is nonzero.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_6352f0(void *self, u32 p);   // GUESS (stood in)
extern "C" void THISCALL ext_584bc0(void *self, u32 p);   // CExplodeMolotov::ReadInput (stood in)
extern "C" void THISCALL ext_4e7480(void *self, u32 p);   // GUESS (stood in)

// 0x5846c0 CExplodeMolotov::Load(lg).
static u32 THISCALL explodeMolotovLoad(u8 *self, u32 lgArg) {
  u32 local0 = 0;
  D(self, 4) &= 0xffffffbfu;
  ext_6352f0(self, (u32)&local0);
  ext_584bc0(self, (u32)&local0);
  u8 *lg = (u8 *)lgArg;
  vcall<void>(lg, 0x40, (u32)(self + 0x58));
  vcall<void>(lg, 0x50, (u32)(self + 0x5c));
  vcall<void>(lg, 0x50, (u32)(self + 0x60));
  vcall<void>(lg, 0x40, (u32)(self + 0x64));
  vcall<void>(lg, 0x6c, (u32)(self + 0x68));
  vcall<void>(lg, 0x6c, (u32)(self + 0x74));
  vcall<void>(lg, 0x6c, (u32)(self + 0x80));
  vcall<void>(lg, 0x68, (u32)(self + 0x8c));
  vcall<void>(lg, 0x6c, (u32)(self + 0x8d));
  vcall<void>(lg, 0x50, (u32)(self + 0x99));
  u8 *o = (u8 *)vcall<u32>(lg, 0x40, (u32)(self + 0x362));
  vcall<void>(o, 0x40, (u32)(self + 0x35e));

  u32 ptrC = (u32)(self + 0x18d);   // [ebp+8] in the exe, stride 0xc
  u32 ptr4 = (u32)(self + 0x179);   // [ebp-4], stride 4
  u32 ptrA = (u32)(self + 0x9d);    // [ebp-0x10], stride 0x2c
  u8 *b = self + 0x222;             // ebx, stride 0x44
  for (u32 i = 0; i < 5; ++i) {
    ext_4e7480((void *)ptrA, (u32)lg);
    u8 *ob = (u8 *)vcall<u32>(lg, 0x68, (u32)(self + 0x1c9 + i));
    vcall<void>(ob, 0x6c, ptrC + 0x41);
    u8 *od = (u8 *)vcall<u32>(lg, 0x40, ptr4);
    vcall<void>(od, 0x6c, ptrC);
    vcall<void>(lg, 0x50, (u32)(b + 0x28));
    vcall<void>(lg, 0x74, (u32)b);
    vcall<void>(lg, 0x40, (u32)(b + 0x24));
    vcall<void>(lg, 0x6c, (u32)(b - 0x18));
    vcall<void>(lg, 0x6c, (u32)(b - 0xc));
    float x = *(float *)(b + 0x28);
    if (x != 0.0f) {
      u8 *gg = *(u8 **)0x7003b8;
      u8 *base = (u8 *)D(gg, 0x2c51);
      u32 idx = D(base, 0x750);
      D(base, 0x754 + 4 * idx) = (u32)(b - 0x18);
      D(base, 0x750) = idx + 1;
      D(base, 0xa54) = (u32)(base + 4 * (idx + 1 + 0x1d5));
    }
    b += 0x44;
    ptrC += 0xc;
    ptr4 += 4;
    ptrA += 0x2c;
  }
  return 1;
}
PCREG(5846c0, explodeMolotovLoad);
