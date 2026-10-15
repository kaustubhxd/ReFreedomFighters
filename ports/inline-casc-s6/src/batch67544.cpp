// batch67544.cpp - cascade s6 batch 67544: 0x555b30.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 idx);   // value node by index, ret 4
extern "C" void THISCALL ext_5002f0(u32 *node, u32 v);    // stores a value into a node, ret 4

typedef void (__cdecl *log67544_t)(u8 *, ...);
typedef void (*hook67544_t)();

// 0x555b30, stdcall(req) ret 4, return value unused: answers "can this object be added to the selection list" into the request's second value node. The object comes from the first node (byte +4
// must be 0 / 1, else logged and the assert hook runs) through the object table (sys[0x9b] slot 0x58). Result 1 when the object is missing, or when it passes slot 0x1e0(0x2007f9) and is already in
// the list at [0x7003b8]+0x2c55 (count + entries) or the list holds 12; 0 when it passes but the list has room; objects failing that test give 1, logging (0x5e3) unless slot 0x1e0(0x2003e8) accepts them.
static void STDCALL fn555b30(u8 *req) {
  u32 *n1 = ext_5003d0(*(u32 *)(req + 4), 0);
  u8 b = *((u8 *)n1 + 4);
  if (b != 0 && b != 1) {
    u8 *lg = *(u8 **)0x700390;
    u8 *x = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x104u);
    (*(log67544_t *)(*(u8 **)x + 0x2c))(x, 0x69c6b0u, 0x69c938u);
    hook67544_t h = *(hook67544_t *)0x7003b0;
    if (h) h(); else __asm__ volatile("int3");
  }
  u8 *obj = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, n1[0]);
  u32 v = 1;
  if (obj) {
    if ((u8)vcall<u32>(obj, 0x1e0, 0x2007f9u)) {
      u32 *base = (u32 *)(*(u8 **)0x7003b8 + 0x2c55);
      u32 cnt = base[0];
      u32 *end = base + 1 + cnt;
      u32 *p = base + 1;
      while (p != end && *p != (u32)obj) p++;
      v = (p != end || cnt == 0xc) ? 1 : 0;
    } else if (!(u8)vcall<u32>(obj, 0x1e0, 0x2003e8u)) {
      u8 *lg = *(u8 **)0x700390;
      u8 *x = vcall<u8 *>(lg, 0x20, 0x6a57fcu, 0x5e3u);
      u32 *n = ext_5003d0(*(u32 *)(req + 4), 0);
      (*(log67544_t *)(*(u8 **)x + 0x2c))(x, 0x6a5de8u, n[0], n[1]);
    }
  }
  ext_5002f0(ext_5003d0(*(u32 *)(req + 8), 0), v);
}
PCREG(555b30, fn555b30);
