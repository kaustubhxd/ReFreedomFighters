// batch945.cpp - 0x573860 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), two stack words (a, b), ret 8.
// r = manager (the dword at 0x70039c, slot +0x9b) slot +0x114 (thiscall: 0x6a6684, 0, 0x6a9104, 0x136; returns eax; stood in). The result's low
// word is compared with a's low word. Equal: if the byte at this+0x88 is non-zero, call 0x561c60 (thiscall, no args; stood in); return 0.
// Not equal: return 0x561cb0 (thiscall: this, a, b; ret 8; stood in), i.e. its eax is returned.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_561c60(void *self);                    // stood in (no args)
extern "C" u32 THISCALL ext_561cb0(void *self, u32 a, u32 b);       // stood in (two args, ret 8)

// 0x573860 (no name in the map).
static u32 THISCALL Dispatch573860(u8 *self, u32 a, u32 b) {
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u32 r = vcall<u32>(mgr, 0x114, 0x6a6684u, 0u, 0x6a9104u, 0x136u);
  if ((u16)a == (u16)r) {
    if (U8(self, 0x88)) ext_561c60(self);
    return 0;
  }
  return ext_561cb0(self, a, b);
}
PCREG(573860, Dispatch573860);
