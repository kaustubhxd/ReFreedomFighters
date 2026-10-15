// batch67542.cpp - cascade s6 batch 67542: 0x557230.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 idx);   // value node by index, ret 4
extern "C" u32 THISCALL ext_4db9a0(u8 *self, u32 key);    // ret 4, bool in al
extern "C" void THISCALL ext_5002f0(u8 *node, u32 v);     // ret 4

typedef void (__cdecl *log67542_t)(u8 *, ...);
typedef void (*hook67542_t)();

// 0x557230, stdcall(req) ret 4, return value unused: counts the children of the object named by the request's first node (req[4] node 0 -> id -> object table sys[0x9b] slot 0x58; the object must
// pass slot 0x1e0(0x100001)) whose 0x4db9a0(0x2007f9) test is set, walking the chain with slot 0x50 (&cursor) from obj[8], and stores the count in the request's second node (req[8] node 0, first dword)
// marking its byte +4 as 1; a node whose byte is not 0 / 1 is logged and reported through the assert hook first. A missing / unsuitable object logs and resets the second node (0x5002f0).
static void STDCALL fn557230(u8 *req) {
  u32 count = 0;
  u32 *n1 = ext_5003d0(*(u32 *)(req + 4), 0);
  u8 *obj = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, *n1);
  if (!obj || !(u8)vcall<u32>(obj, 0x1e0, 0x100001u)) {
    u8 *lg = *(u8 **)0x700390;
    u8 *x = vcall<u8 *>(lg, 0x20, 0x6a57fcu, 0x356u);
    (*(log67542_t *)(*(u8 **)x + 0x2c))(x, 0x6a5b28u);
    u32 *n = ext_5003d0(*(u32 *)(req + 8), 0);
    ext_5002f0((u8 *)n, 0);
    return;
  }
  u32 cur = *(u32 *)(obj + 8);
  while (cur) {
    if ((u8)ext_4db9a0((u8 *)cur, 0x2007f9u)) count++;
    vcall<void>(obj, 0x50, (u32)&cur);
  }
  u32 *m = ext_5003d0(*(u32 *)(req + 8), 0);
  u8 al = *((u8 *)m + 4);
  if (al != 0 && al != 1) {
    u8 *lg = *(u8 **)0x700390;
    u8 *x = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x104u);
    (*(log67542_t *)(*(u8 **)x + 0x2c))(x, 0x69c6b0u, 0x69c938u);
    hook67542_t h = *(hook67542_t *)0x7003b0;
    if (h) h(); else __asm__ volatile("int3");
  }
  m[0] = count;
  *((u8 *)m + 4) = 1;
}
PCREG(557230, fn557230);
