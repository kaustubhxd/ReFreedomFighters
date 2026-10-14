// batch35135.cpp - cascade s5 batch 35135: 0x44bb70 (GUESS bind this node to its data record and the engine's default value).
#include "ff.h"

extern "C" void THISCALL ext_44c2b0(u8 *self);   // plain ret
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *g0_t)(void *);
typedef u32(THISCALL *g1_t)(void *, u32);

// 0x44bb70, thiscall, no arguments. c = [this+0x18]; zero calls this slot 0x210(1) and ends. Otherwise [c+0x6c] = [engine+0x1c] (unless its address is that of the function's own stack local); the tab = [engine+0x9b]'s vtable slot 0x4c is
// called with ECX = tab and the id from this slot 0x20(): [c+0x3c] = result; [this+0x1c] = tab slot 0x64(c); [c+0x80] = [c+0x7c]; 0x44c2b0(this).
static void THISCALL fn44bb70(u8 *self) {
  u32 local;
  u8 *c = *(u8 **)(self + 0x18);
  if (!c) {
    (*(v1_t **)self)[0x210 / 4](self, 1);
    return;
  }
  u8 *eng = G(u8 *, 0x70039c);
  u32 v = *(u32 *)(eng + 0x1c);
  if ((u32 *)(c + 0x6c) != &local) {
    *(u32 *)(c + 0x6c) = v;
    eng = G(u8 *, 0x70039c);
  }
  u8 *tab = *(u8 **)(eng + 0x9b);
  u32 f = (*(u32 **)tab)[0x4c / 4];
  u32 id = (*(g0_t **)self)[0x20 / 4](self);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  c = *(u8 **)(self + 0x18);
  *(u32 *)(c + 0x3c) = ((g1_t)f)(tab, id);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 h = (*(g1_t **)tab)[0x64 / 4](tab, *(u32 *)(self + 0x18));
  c = *(u8 **)(self + 0x18);
  *(u32 *)(self + 0x1c) = h;
  *(u32 *)(c + 0x80) = *(u32 *)(c + 0x7c);
  ext_44c2b0(self);
}
PCREG(44bb70, fn44bb70);
