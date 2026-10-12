// batch6336.cpp - unclaimed-63 gap-band batch 36: 0x4cea50 (C-set; no GC name), thiscall, no stack arguments (plain ret).
//   If this is null, return. vtbl[+0x4c](&local). v = vtbl[+0x64](&local); if v == 0 return.
//   Loop: k = [this+0x18]; f = the float at v + 4k - 0xc. lg = [0x700390]; L = lg->vtbl[+0x20](0x695b7c, 0x523) (thiscall, callee pops 8).
//     L->vtbl[+0x2c](L, 0x695cac, [v], (double)f) (cdecl, caller cleans 20 bytes). v = vtbl[+0x64](&local); repeat while v != 0.
#include "ff.h"

typedef void(THISCALL * call1v_fn)(void *, u32 *);
typedef u32(THISCALL * call1r_fn)(void *, u32 *);
typedef u32(THISCALL * log20_fn)(void *, u32, u32);
typedef void (*printf_fn)(u32, u32, u32, double);

// 0x4cea50 (C-set).
static void THISCALL unnamed4cea50(u8 *self) {
  if (self == 0)
    return;
  u32 local;   // not initialised: the original does not store to it before the calls
  ((call1v_fn)(*(u32 *)(*(u32 *)self + 0x4c)))((void *)self, &local);
  u32 v = ((call1r_fn)(*(u32 *)(*(u32 *)self + 0x64)))((void *)self, &local);
  if (v == 0)
    return;
  do {
    u32 k = *(u32 *)(self + 0x18);
    float f = *(float *)(v + k * 4 - 0xc);
    u32 lg = G(u32, 0x700390);
    u32 l = ((log20_fn)(*(u32 *)(*(u32 *)lg + 0x20)))((void *)lg, 0x695b7cu, 0x523u);
    ((printf_fn)(*(u32 *)(*(u32 *)l + 0x2c)))(l, 0x695cacu, *(u32 *)v, (double)f);
    v = ((call1r_fn)(*(u32 *)(*(u32 *)self + 0x64)))((void *)self, &local);
  } while (v != 0);
}
PCREG(4cea50, unnamed4cea50);
