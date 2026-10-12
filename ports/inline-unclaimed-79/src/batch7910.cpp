#include "ff.h"
// batch7910.cpp - unclaimed-79 batch 10 (docs/20-unclaimed-79.md). Name from the GC name map (naming only).
// SEH frame not reproduced (fs:[0] writes not compared). The exe's cookie and fs:[0] frame setup is not ported.
// Helper 0x4e0830 (fastcall, float result in st0) runs as original code; the harness stubs it.

extern "C" float FASTCALL ext_4e0830(u8 *ecx, u8 *edx);

// 0x49f0a0, CMsgForwardToActors::Command(unsigned short, void*) (high). Thiscall, two stack arguments (ret 8). Returns 0 on
// every path. Walks a chain from this+0x50 (the object's +0x18 gets the start, slot +0x4c, then slot +0x5c with a flag). For
// each element, when it is not null and not this+0x44: if this+0x4c is positive, a squared-distance test (helper 0x4e0830 on two
// temporaries filled by slots +0x84) decides whether to continue; then slot +0x130 of the object at this+0x44 is called with
// (element, word at +0x4a or the command, arg).
static u32 THISCALL msgForwardToActorsCommand(u8 *self, u32 cmdArg, void *arg) {
  u16 cmd = (u16)cmdArg;
  u32 flag = 0;
  if (*(u8 **)(self + 0x50) == 0)
    return 0;
  u16 w48 = *(u16 *)(self + 0x48);
  if (w48 != 0 && w48 != cmd)
    return 0;
  if (*(u8 **)(*(u8 **)(self + 0x50) + 0x18) == 0)
    return 0;
  vcall<void, u32 *>(*(u8 **)(*(u8 **)(self + 0x50) + 0x18), 0x4c, &flag);
  u8 *cur = vcall<u8 *, u32 *>(*(u8 **)(*(u8 **)(self + 0x50) + 0x18), 0x5c, &flag);
  if (flag == 0)
    return 0;
  do {
    u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *edi = vcall<u8 *, u8 *>(t, 0x58, cur);
    if (edi != 0 && edi != *(u8 **)(self + 0x44)) {
      float r = *(float *)(self + 0x4c);
      bool doCall = true;
      if (r > 0.0f) {
        u32 L[6] = {0, 0, 0, 0, 0, 0};
        u8 *a44 = *(u8 **)(self + 0x44);
        vcall<void, u32 *>(a44, 0x84, &L[0]);
        vcall<void, u32 *>(edi, 0x84, &L[3]);
        float d = ext_4e0830((u8 *)&L[0], (u8 *)&L[3]);
        float lim = r * r;
        lim = lim * G(float, 0x67cd40);
        lim = lim * G(float, 0x67cd40);
        if (d > lim)
          doCall = false;
      }
      if (doCall) {
        u16 w4a = *(u16 *)(self + 0x4a);
        u32 k = w4a != 0 ? (u32)w4a : (u32)cmdArg;
        vcall<void, u32, u32, u32>(*(u8 **)(self + 0x44), 0x130, (u32)(unsigned long)edi, k, (u32)(unsigned long)arg);
      }
    }
    cur = vcall<u8 *, u32 *>(*(u8 **)(*(u8 **)(self + 0x50) + 0x18), 0x5c, &flag);
  } while (flag != 0);
  return 0;
}
PCREG(49f0a0, msgForwardToActorsCommand);
