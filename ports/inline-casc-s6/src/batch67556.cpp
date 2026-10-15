// batch67556.cpp - cascade s6 batch 67556: 0x553690.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 idx);   // value node by index, ret 4

typedef void (__cdecl *log67556_t)(u8 *, ...);
typedef void (*hook67556_t)();

// 0x553690, stdcall(req) ret 4, return value unused: sets a UI object's state from the request. Node 0 (byte +4 must be 0 / 1, else logged and the assert hook runs) gives a count, node 1 the object id
// (object table sys[0x9b] slot 0x58). Two lookups through the table's slot 0x114 (4 args, then 6 args with an out variable and a word result) give another object id whose object is fed the
// word through slot 0x128; that second object then gets slot 0x2d0(0, 0) and, when the count is positive, additionally 0x360(count), 0x358(1) and 0x2d0(3, 0).
typedef u32 (THISCALL *tab4_t)(u8 *, u32, u32, u32, u32);
typedef u32 (THISCALL *tab6_t)(u8 *, u32, u32, u32, u32, u32, u32);
static void STDCALL fn553690(u8 *req) {
  u32 *n1 = ext_5003d0(*(u32 *)(req + 4), 0);
  u8 b = *((u8 *)n1 + 4);
  if (b != 0 && b != 1) {
    u8 *lg = *(u8 **)0x700390;
    u8 *x = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x104u);
    (*(log67556_t *)(*(u8 **)x + 0x2c))(x, 0x69c6b0u, 0x69c938u);
    hook67556_t h = *(hook67556_t *)0x7003b0;
    if (h) h(); else __asm__ volatile("int3");
  }
  int count = (int)n1[0];
  u32 *n2 = ext_5003d0(*(u32 *)(req + 4), 1);
  u8 *obj = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, n2[0]);
  u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  (*(tab4_t *)(*(u8 **)tab + 0x114))(tab, 0x6a584cu, 0, 0x6a57fcu, 0x104u);
  u32 loc;
  tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u32 r = (*(tab6_t *)(*(u8 **)tab + 0x114))(tab, 0x6a584cu, 0, 0x6a57fcu, 0x105u, (u32)&loc, 0);
  vcall<void>(obj, 0x128, r & 0xffff);
  u8 *o2 = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, loc);
  if (count > 0) {
    vcall<void>(o2, 0x2d0, 0u, 0u);
    vcall<void>(o2, 0x360, (u32)count);
    vcall<void>(o2, 0x358, 1u);
    vcall<void>(o2, 0x2d0, 3u, 0u);
  } else {
    vcall<void>(o2, 0x2d0, 0u, 0u);
  }
}
PCREG(553690, fn553690);
