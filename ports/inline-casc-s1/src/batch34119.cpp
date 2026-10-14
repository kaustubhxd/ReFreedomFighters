// batch34119.cpp - cascade tier E, batch 34119: 0x50f9f0 (resolve a handle through the engine table and push a value), 0x538220 (teardown loop).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);   // thiscall ret 4
extern "C" u32 THISCALL ext_506040(void *self);        // thiscall, plain ret
extern "C" u32 THISCALL ext_53a8f0(void *self);        // thiscall, plain ret
extern "C" u32 THISCALL ext_534510(void *self);        // thiscall, plain ret
extern "C" void ext_634273(void *p, u32 n);            // cdecl free

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x50f9f0, stdcall(a) ret 4: handle = *ext_5003d0([a+4], 0); o = [[0x70039c]+0x9b]->slot0x58(handle); 0 when o is null. Else with x = *ext_5003d0([a+4], 2), y = ext_506040(ext_5003d0([a+4], 1)):
// w = (u16) [[0x70039c]+0x9b]->slot0x114(y, 0, 0x69db34, 0x289, x, 0); returns o->slot0x138(w).
static u32 STDCALL fn50f9f0(u8 *a) {
  u32 handle = *ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x58, handle);
  if (!o) return 0;
  u32 x = *ext_5003d0(*(u8 **)(a + 4), 2);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 y = ext_506040(ext_5003d0(*(u8 **)(a + 4), 1));
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = (u16)vcall<u32>(tbl, 0x114, y, 0u, 0x69db34u, 0x289u, x, 0u);
  return vcall<u32>(o, 0x138, w);
}
PCREG(50f9f0, fn50f9f0);

// 0x538220, thiscall plain: m = unaligned [this+0x52fe]: m->slot0(1) when set; frees the unaligned block [this+0x5302] (size 1) and clears both fields; p = unaligned [this+0x52fa]: ext_53a8f0(p) and free(p, 0x1a) when set, field cleared;
// ext_534510(this+0x8b); this->slot0x208(); this->slot0x160(0x81); when byte [this+0x50ba] is set: this->slot0x19c() until its low byte is non-zero.
static void THISCALL fn538220(u8 *self) {
  u8 *m = (u8 *)rd32(self + 0x52fe);
  if (m) vcall<void>(m, 0, 1u);
  u8 *q = (u8 *)rd32(self + 0x5302);
  wr32(self + 0x52fe, 0);
  if (q) ext_634273(q, 1);
  u8 *p = (u8 *)rd32(self + 0x52fa);
  wr32(self + 0x5302, 0);
  if (p) {
    ext_53a8f0(p);
    ext_634273(p, 0x1a);
  }
  wr32(self + 0x52fa, 0);
  ext_534510(self + 0x8b);
  vcall<void>(self, 0x208);
  vcall<void>(self, 0x160, 0x81u);
  if (self[0x50ba]) {
    for (;;) {
      u32 v = vcall<u32>(self, 0x19c);
      if ((u8)v) break;
    }
  }
}
PCREG(538220, fn538220);
