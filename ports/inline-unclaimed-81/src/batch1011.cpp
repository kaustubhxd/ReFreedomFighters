// batch1011.cpp - area 81, batch 1011: CTargetObtained::Command(cmd, unused), 0x5c53f0, thiscall, two stack arguments (the second is not read), ret 8.
// Cookie check not reproduced (no SEH frame). Stand-ins (GUESS): 0x5c5620 (thiscall, no arguments, returns a bool), 0x589c20 (one argument, ecx =
// the hook at 0x7003b8, returns an object), 0x59a580 (thiscall on that object, three arguments), 0x5c5810 (thiscall on this, no arguments), 0x596940
// (thiscall on the object's +0x852 word, four arguments). The global test function at 0x676414 is a cdecl pointer called with two arguments.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_5c5620(void *self);                           // GUESS (stood in)
extern "C" u32 THISCALL ext_589c20(void *self, u32 a);                    // GUESS (stood in)
extern "C" void THISCALL ext_59a580(void *self, u32 a, u32 b, u32 c);    // GUESS (stood in)
extern "C" void THISCALL ext_5c5810(void *self);                          // GUESS (stood in)
extern "C" void THISCALL ext_596940(void *self, u32 a, u32 b, u32 c, u32 d); // GUESS (stood in)

// 0x5c53f0 CTargetObtained::Command(cmd, unused).
static u32 THISCALL targetObtainedCommand(u8 *self, u32 cmdArg, u32 unusedArg) {
  (void)unusedArg;
  if ((u16)cmdArg != W16(self, 0x148))
    return 0;
  if (ext_5c5620(self))
    return 0;
  u32 L = 0;
  u8 *rm = (u8 *)D(*(u8 **)0x70039c, 0x9b);
  u8 *A = (u8 *)vcall<u32>(rm, 0x138);
  vcall<void>(A, 0x88, 0x6a5c48u, (u32)&L);
  u8 *x = (u8 *)vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, L);
  if (x) {
    u32 w = vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x114, 0x6a5c58u, 0u, 0x6b4204u, 0x94u, (u32)(self + 0x48), 0u);
    vcall<void>(x, 0x128, (u32)(u16)w);
  }
  u8 *esiP = self + 0xc8;
  u8 *B = (u8 *)D(D(*(u8 **)0x70039c, 0x9b), 0xae4);
  u8 *C = (u8 *)vcall<u32>(B, 0x0, (u32)esiP, 0x677b5au);
  u32 r = ((u32(*)(u32, u32))(*(u32 *)0x676414))((u32)C, 0x677b5au);
  u8 *edi = r == 0 ? esiP : C;
  u32 O = ext_589c20((void *)*(u8 **)0x7003b8, 0u);
  ext_59a580((void *)O, (u32)edi, 0xffffffffu, 0u);
  ext_5c5810(self);
  if (self[0x152]) {
    u32 L2 = 0;
    u8 *rm2 = (u8 *)D(*(u8 **)0x70039c, 0x9b);
    u8 *A2 = (u8 *)vcall<u32>(rm2, 0x138);
    vcall<void>(A2, 0x88, 0x681320u, (u32)&L2);
    u8 *x2 = (u8 *)vcall<u32>((void *)D(*(u8 **)0x70039c, 0x9b), 0x58, L2);
    u32 c2 = D(x2, 0x852);
    if (c2) {
      u32 v10[3] = {0u, 0u, 0u};
      ext_596940((void *)c2, 3u, (u32)v10, 1u, 0xffffffffu);
    }
  }
  return 0;
}
PCREG(5c53f0, targetObtainedCommand);
