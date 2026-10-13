// batch4110.cpp - unclaimed-41 batch 10 (slice 13): 0x5a2f10 (name not in the map; GUESS).
#include "ff.h"

// 0x598e10: four stack arguments (the caller does not pop them, so the callee pops 0x10); checksum stub in the spec (GUESS).
extern "C" void THISCALL ext_598e10(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4);

// 0x5a2f10 (GUESS name): thiscall, one stack argument (ret 4).
//  if this.784 == arg return; if this.92e == 0 return; this.784 = arg; if arg == 0 return.
//  t = B.vt[+0x58](arg), with B = [0x70039c]+0x9b.
//  if (u8)t.vt[+0x1e0](0x2007f9) != 0: x = B.vt[+0x154](0x6adee8); if !(u8)t.vt[+0x1e0](x.dword[+0x23]) return; t[0x783] = 1.
//  else: x = B.vt[+0x154](0x6a6088); if !(u8)t.vt[+0x1e0](x.dword[+0x23]) return.
//  then 598e10 on z = [this.92e.dword[+0x852]] with (t, 5, 0.1f, 0) (ecx = z; the last one is a leftover push).
static void THISCALL fn5a2f10(u8 *self, u32 arg) {
  typedef u32(THISCALL * f58_t)(u8 *, u32);
  typedef u32(THISCALL * f1e0_t)(u8 *, u32);
  if (*(u32 *)(self + 0x784) == arg)
    return;
  if (*(u32 *)(self + 0x92e) == 0)
    return;
  *(u32 *)(self + 0x784) = arg;
  if (arg == 0)
    return;
  u8 *b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *t = (u8 *)(*(f58_t *)(*(u32 *)b + 0x58))(b, arg);
  u8 a1 = (u8)(*(f1e0_t *)(*(u32 *)t + 0x1e0))(t, 0x2007f9u);
  if (a1 != 0) {
    u8 *x = (u8 *)(*(f58_t *)(*(u32 *)b + 0x154))(b, 0x6adee8u);
    u8 a2 = (u8)(*(f1e0_t *)(*(u32 *)t + 0x1e0))(t, *(u32 *)(x + 0x23));
    if (a2 == 0)
      return;
    t[0x783] = 1;
  } else {
    u8 *x = (u8 *)(*(f58_t *)(*(u32 *)b + 0x154))(b, 0x6a6088u);
    u8 a2 = (u8)(*(f1e0_t *)(*(u32 *)t + 0x1e0))(t, *(u32 *)(x + 0x23));
    if (a2 == 0)
      return;
  }
  u8 *y = *(u8 **)(self + 0x92e);
  u8 *z = *(u8 **)(y + 0x852);
  ext_598e10(z, (u32)t, 5u, 0x3dcccccdu, 0u);
}
PCREG(5a2f10, fn5a2f10);
