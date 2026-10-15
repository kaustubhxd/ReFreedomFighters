// batch67543.cpp - cascade s6 batch 67543: 0x5570d0.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 idx);   // value node by index, ret 4

typedef void (__cdecl *log67543_t)(u8 *, ...);
typedef void (*hook67543_t)();

// 0x5570d0, stdcall(req) ret 4, return value unused: toggles an object in the global selection list (count at [0x7003b8]+0x2c55, up to 12 entries after it). The request's node 0 (byte +4
// must be 0 / 1, else logged and the assert hook runs) names the object through the object table (sys[0x9b] slot 0x58); node 1's value is the "add" flag. If the object passes slot 0x1e0(0x2007f9):
// an entry already in the list is removed (swap with the last), otherwise it is appended when the flag is non-zero and fewer than 12 are present. A missing / unsuitable object logs.
static void STDCALL fn5570d0(u8 *req) {
  u32 *n1 = ext_5003d0(*(u32 *)(req + 4), 0);
  u8 b = *((u8 *)n1 + 4);
  if (b != 0 && b != 1) {
    u8 *lg = *(u8 **)0x700390;
    u8 *x = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x104u);
    (*(log67543_t *)(*(u8 **)x + 0x2c))(x, 0x69c6b0u, 0x69c938u);
    hook67543_t h = *(hook67543_t *)0x7003b0;
    if (h) h(); else __asm__ volatile("int3");
  }
  u8 *obj = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, n1[0]);
  u32 *n2 = ext_5003d0(*(u32 *)(req + 4), 1);
  u32 flag = n2[0];
  if (obj && (u8)vcall<u32>(obj, 0x1e0, 0x2007f9u)) {
    u32 *base = (u32 *)(*(u8 **)0x7003b8 + 0x2c55);
    u32 cnt = base[0];
    u32 *end = base + 1 + cnt;
    u32 *p = base + 1;
    while (p != end && *p != (u32)obj) p++;
    if (p != end) {
      *p = base[cnt];
      base[0]--;
    } else if (flag && cnt < 0xc) {
      *end = (u32)obj;
      base[0]++;
    }
    return;
  }
  u8 *lg = *(u8 **)0x700390;
  u8 *x = vcall<u8 *>(lg, 0x20, 0x6a57fcu, 0x5c9u);
  (*(log67543_t *)(*(u8 **)x + 0x2c))(x, 0x6a5dacu);
}
PCREG(5570d0, fn5570d0);
