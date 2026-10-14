// batch35071.cpp - cascade s5 batch 35071: 0x56cd90 (GUESS initialise a panel: defaults, log the table id, register two resources, notify twice).
#include "ff.h"

extern "C" void THISCALL ext_562440(u8 *self);                 // plain ret
extern "C" void THISCALL ext_563510(u8 *self, u32 a);          // ret 4
extern "C" void THISCALL ext_563610(u8 *self, u32 a);          // ret 4
typedef u8 *(THISCALL *g0_t)(void *);
typedef u32(THISCALL *g2_t)(void *, u32, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x56cd90, thiscall, no arguments. 0x562440(this); byte +0x1b5 = 1, unaligned dwords +0x1b6 = +0x1ba = 5. With tab = [engine+0x9b]: o = tab slot 0x138(); id = tab slot 0x4c([this+0x44], 0x10); o slot 0x60(0x6a7ffc, id)
// (slot read before the id lookup); unaligned dwords +0x1c6, +0x1be = 0; 0x563510(this, 0x6a8010); 0x563610(this, 0x6a801c); then tab slot 0x134() slot 0x68(0x68a9d4, 0, 0) and the same with 0x6a8028.
static void THISCALL fn56cd90(u8 *self) {
  ext_562440(self);
  self[0x1b5] = 1;
  wr32u(self + 0x1b6, 5);
  wr32u(self + 0x1ba, 5);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x138 / 4](tab);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 f = (*(u32 **)o)[0x60 / 4];
  u32 id = (*(g2_t **)tab)[0x4c / 4](tab, *(u32 *)(self + 0x44), 0x10);
  ((v2_t)f)(o, 0x6a7ffc, id);
  wr32u(self + 0x1c6, 0);
  wr32u(self + 0x1be, 0);
  ext_563510(self, 0x6a8010);
  ext_563610(self, 0x6a801c);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u8 *o2 = (*(g0_t **)tab)[0x134 / 4](tab);
  (*(v3_t **)o2)[0x68 / 4](o2, 0x68a9d4, 0, 0);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u8 *o3 = (*(g0_t **)tab)[0x134 / 4](tab);
  (*(v3_t **)o3)[0x68 / 4](o3, 0x6a8028, 0, 0);
}
PCREG(56cd90, fn56cd90);
