// batch67547.cpp - cascade s6 batch 67547: 0x551fb0.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 idx);   // value node by index, ret 4

typedef void (__cdecl *log67547_t)(u8 *, ...);
typedef void (*hook67547_t)();

// 0x551fb0, stdcall(req) ret 4, return value unused: counts the children of the object named by the request's first value node (object table sys[0x9b] slot 0x58, its list at obj[0x18]
// iterated with slots 0x4c / 0x5c through an iterator dword) that pass slot 0x1e0(0x200074) and fail slot 0x438, and stores the count into the request's second value node (byte +4 = 1; a
// byte other than 0 / 1 is logged and reported through the assert hook first).
static void STDCALL fn551fb0(u8 *req) {
  u32 count = 0;
  u32 *n1 = ext_5003d0(*(u32 *)(req + 4), 0);
  u8 *obj = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, n1[0]);
  if (obj && *(u8 **)(obj + 0x18)) {
    u32 it;
    vcall<void>(*(u8 **)(obj + 0x18), 0x4c, (u32)&it);
    u32 id = vcall<u32>(*(u8 **)(obj + 0x18), 0x5c, (u32)&it);
    while (it != 0) {
      u8 *o = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, id);
      if ((u8)vcall<u32>(o, 0x1e0, 0x200074u)) {
        if (!(u8)vcall<u32>(o, 0x438)) count++;
      }
      id = vcall<u32>(*(u8 **)(obj + 0x18), 0x5c, (u32)&it);
    }
  }
  u32 *m = ext_5003d0(*(u32 *)(req + 8), 0);
  u8 b = *((u8 *)m + 4);
  if (b != 0 && b != 1) {
    u8 *lg = *(u8 **)0x700390;
    u8 *x = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x104u);
    (*(log67547_t *)(*(u8 **)x + 0x2c))(x, 0x69c6b0u, 0x69c938u);
    hook67547_t h = *(hook67547_t *)0x7003b0;
    if (h) h(); else __asm__ volatile("int3");
  }
  m[0] = count;
  *((u8 *)m + 4) = 1;
}
PCREG(551fb0, fn551fb0);
