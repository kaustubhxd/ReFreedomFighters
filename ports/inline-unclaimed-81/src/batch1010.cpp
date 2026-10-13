// batch1010.cpp - area 81 (residue 11 remainder), batch 1010: ZHeli::Load(lg), 0x51c7b0, thiscall, one stack argument, ret 4. No SEH frame.
// 0x5135c0 (GUESS, stood in) gates the load (on failure its eax is returned as is). Then about sixty load-object slots, the stand-ins 0x5270f0,
// 0x5274a0, 0x516d10 and 0x513510 (GUESS, stood in), and two loops that read values with the load-object slot 0x40 into the stack argument
// (a8) and into a local (l8) and map them through the render manager's slot 0x58. On success eax = (eax & ~0xff) | 1 as in the exe (mov al,1).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_5135c0(void *self, void *lg);   // GUESS (stood in)
extern "C" void THISCALL ext_5270f0(void *self, void *lg);  // GUESS (stood in)
extern "C" void THISCALL ext_5274a0(void *self, void *lg);  // GUESS (stood in)
extern "C" void THISCALL ext_516d10(void *self, void *lg);  // GUESS (stood in)
extern "C" u32 THISCALL ext_513510(void *self, void *lg);   // GUESS (stood in)

// 0x51c7b0 ZHeli::Load(lg).
static u32 THISCALL heliLoad(u8 *self, u32 lgArg) {
  u8 *lg = (u8 *)lgArg;
  u32 gate = ext_5135c0(self, lg);
  if (!(u8)gate)
    return gate;
  vcall<void>(lg, 0x6c, (u32)(self + 0x216));
  vcall<void>(lg, 0x6c, (u32)(self + 0x222));
  vcall<void>(lg, 0x50, (u32)(self + 0x22e));
  vcall<void>(lg, 0x50, (u32)(self + 0x232));
  vcall<void>(lg, 0x50, (u32)(self + 0x236));
  vcall<void>(lg, 0x50, (u32)(self + 0x23a));
  vcall<void>(lg, 0x6c, (u32)(self + 0x23e));
  vcall<void>(lg, 0x6c, (u32)(self + 0x24a));
  vcall<void>(lg, 0x6c, (u32)(self + 0x256));
  vcall<void>(lg, 0x6c, (u32)(self + 0x3f1));
  vcall<void>(lg, 0x6c, (u32)(self + 0x262));
  vcall<void>(lg, 0x50, (u32)(self + 0x26e));
  vcall<void>(lg, 0x50, (u32)(self + 0x272));
  vcall<void>(lg, 0x6c, (u32)(self + 0x276));
  vcall<void>(lg, 0x6c, (u32)(self + 0x282));
  vcall<void>(lg, 0x6c, (u32)(self + 0x28e));
  ext_5270f0(self + 0x29a, lg);
  ext_5270f0(self + 0x2c3, lg);
  ext_5270f0(self + 0x2ec, lg);
  ext_5270f0(self + 0x315, lg);
  vcall<void>(lg, 0x50, (u32)(self + 0x33e));
  vcall<void>(lg, 0x50, (u32)(self + 0x342));
  vcall<void>(lg, 0x50, (u32)(self + 0x346));
  vcall<void>(lg, 0x40, (u32)(self + 0x34a));
  ext_5274a0(self + 0x34e, lg);
  ext_5270f0(self + 0x39f, lg);
  ext_5270f0(self + 0x3c8, lg);
  vcall<void>(lg, 0x40, (u32)(self + 0x3fd));
  vcall<void>(lg, 0x40, (u32)(self + 0x44d));
  vcall<void>(lg, 0x6c, (u32)(self + 0x45d));
  vcall<void>(lg, 0x48, (u32)(self + 0x469));
  vcall<void>(lg, 0x40, (u32)(self + 0x479));
  ext_516d10(self + 0x4ad, lg);
  vcall<void>(lg, 0x18, (u32)(self + 0x526), 0x6du);
  vcall<void>(lg, 0x50, (u32)(self + 0x593));
  vcall<void>(lg, 0x50, (u32)(self + 0x597));
  vcall<void>(lg, 0x40, (u32)(self + 0x491));
  vcall<void>(lg, 0x40, (u32)(self + 0x495));
  vcall<void>(lg, 0x40, (u32)(self + 0x499));
  vcall<void>(lg, 0x40, (u32)(self + 0x49d));
  vcall<void>(lg, 0x40, (u32)(self + 0x4a1));
  vcall<void>(lg, 0x48, (u32)(self + 0x4a5));
  vcall<void>(lg, 0x50, (u32)(self + 0x4a9));

  u32 a8 = lgArg;   // [ebp+8]: the stack argument itself, overwritten by the reads
  u32 l8 = 0;       // [ebp-8]
  u8 *sys = *(u8 **)0x70039c;
  u8 *edi = self + 0x425;
  for (u32 j = 0; j < 5; ++j) {
    vcall<void>(lg, 0x40, (u32)&a8);
    u32 r1 = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, a8);
    D(edi, -0x14) = r1;
    vcall<void>(lg, 0x40, (u32)&l8);
    u32 r2 = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, l8);
    D(edi, 0) = r2;
    edi += 4;
  }
  (void)sys;
  edi = self + 0x439;
  for (u32 j = 0; j < 4; ++j) {
    vcall<void>(lg, 0x40, (u32)&a8);
    D(edi, 0) = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, a8);
    edi += 4;
  }
  u32 r = ext_513510(self + 0x59b, lg);
  return (r & 0xffffff00u) | 1u;
}
PCREG(51c7b0, heliLoad);
