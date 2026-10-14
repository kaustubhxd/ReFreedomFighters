// batch35166.cpp - cascade s5 batch 35166: 0x4a1190 (GUESS reset a widget: register its name, read two configured words, clear the links).
#include "ff.h"

typedef u8 *(THISCALL *g0_t)(void *);
typedef u32(THISCALL *k2_t)(void *, u32, u32);
typedef u32(THISCALL *l2_t)(void *, u32, u32);
typedef u32(THISCALL *c4_t)(void *, u32, u32, u32, u32);

// 0x4a1190, thiscall, no args, no return value. o = tab slot 0x138() (tab = engine[+0x9b]; the vtable of o read first); w = tab slot 0x4c(this[0x44], 4); o slot 0x60(0x68f75c, w).
// Then this[0x8b0] (word) = tab slot 0x114(0x68f774, 0, 0x68f6b4, 0x220) and this[0x8b2] (word) = tab slot 0x114(0x68f788, 0, 0x68f6b4, 0x221) (four args each, engine re-read);
// then dwords +0x5c, +0x4c, +0x60, +0x50, +0x64, +0x54, +0x68, +0x58, +0x48 = 0.
static void THISCALL fn4a1190(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x138 / 4](tab);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 *vt = *(u32 **)o;
  u32 w = (*(k2_t **)tab)[0x4c / 4](tab, *(u32 *)(self + 0x44), 4);
  ((l2_t)vt[0x60 / 4])(o, 0x68f75c, w);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  *(u16 *)(self + 0x8b0) = (u16)(*(c4_t **)tab)[0x114 / 4](tab, 0x68f774, 0, 0x68f6b4, 0x220);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  *(u16 *)(self + 0x8b2) = (u16)(*(c4_t **)tab)[0x114 / 4](tab, 0x68f788, 0, 0x68f6b4, 0x221);
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x64) = 0;
  *(u32 *)(self + 0x54) = 0;
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x58) = 0;
  *(u32 *)(self + 0x48) = 0;
}
PCREG(4a1190, fn4a1190);
