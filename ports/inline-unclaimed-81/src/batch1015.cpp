// batch1015.cpp - area 81, batch 1015: ZParamAnim::Load(lg), 0x4a29f0, thiscall, one stack argument, ret 4. SEH frame not reproduced; cookie check
// not reproduced. Stand-ins (GUESS): 0x4a2f90 (thiscall, no arguments), 0x4cc1d0 (thiscall on the object from +0x1d8, returns a value), 0x4cbec0
// (thiscall on the local object, no arguments). The inline object at this+0x59 has slots 0x14 and 0x8 (one argument each). The null branch
// prints through the channel's vtable slot 0x2c (cdecl: channel, format, value). Return eax = (last call's eax & ~0xff) | 1 (mov al,1).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4a2f90(void *self);     // GUESS (stood in)
extern "C" u32 THISCALL ext_4cc1d0(void *self);      // GUESS (stood in)
extern "C" void THISCALL ext_4cbec0(void *self);     // GUESS (stood in)

// 0x4a29f0 ZParamAnim::Load(lg).
static u32 THISCALL paramAnimLoad(u8 *self, u32 lgArg) {
  u8 *lg = (u8 *)lgArg;
  D(self, 4) &= 0xffffffbfu;
  vcall<void>(lg, 0x68, (u32)(self + 0x48));
  vcall<void>(lg, 0x44, (u32)(self + 0x11a));
  vcall<void>(lg, 0x58, (u32)(self + 0x49));
  vcall<void>(lg, 0x58, (u32)(self + 0x4d));
  vcall<void>(lg, 0x50, (u32)(self + 0x51));
  vcall<void>(lg, 0x50, (u32)(self + 0x55));
  vcall<void>(lg, 0x68, (u32)(self + 0x11d));
  vcall<void>(lg, 0x50, (u32)(self + 0x11e));
  u8 *M = (u8 *)D(self, 0x44);
  u32 R = vcall<u32>(M, 0x4c, 0x80004u);
  ext_4a2f90(self);
  u32 last = vcall<u32>(self + 0x59, 0x14, lgArg);
  (void)last;
  if (R == 0) {
    u8 *chan = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x68f94cu, 0xc5u);
    u8 l90[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    u32 Q = vcall<u32>(M, 0x1d8, (u32)l90, 0u);
    u32 V = ext_4cc1d0((void *)Q);
    typedef void(__attribute__((cdecl)) * print_fn)(u32, u32, u32);
    print_fn fn = (print_fn)D(*(u8 **)chan, 0x2c);
    fn((u32)chan, 0x68f9c0u, V);
    ext_4cbec0(l90);
    last = vcall<u32>(self, 0x58);
  } else {
    u8 *rm = (u8 *)D(*(u8 **)0x70039c, 0x9b);
    *(u16 *)0x7002f0 = (u16)vcall<u32>(rm, 0x114, 0x688c10u, 0u, 0x68f94cu, 0xc9u);
    *(u16 *)0x7002f4 = (u16)vcall<u32>(rm, 0x114, 0x688c1cu, 0u, 0x68f94cu, 0xcau);
    last = vcall<u32>(self + 0x59, 0x8, R);   // esi holds R here (the exe pushes esi, not lg)
  }
  return (last & 0xffffff00u) | 1u;
}
PCREG(4a29f0, paramAnimLoad);
