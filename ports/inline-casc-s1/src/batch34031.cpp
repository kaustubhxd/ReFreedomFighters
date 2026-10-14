// batch34031.cpp - cascade tier E, batch 34031: 0x5175a0 (initialise a widget from engine services), 0x52b0c0 (rate-limit counter), 0x5b3ba0 (run a
// helper for three channels with the engine time).
#include "ff.h"

extern "C" void THISCALL ext_515630(void *self);                                          // thiscall, plain ret
extern "C" void THISCALL ext_5b58a0(void *self, void *a, void *b, u32 c, u32 t);          // thiscall ret 0x10

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5175a0, thiscall, no args: 0x515630(this); when the engine object at +0x1a9f exists: [this+0x161d] = it->slot0x60([this+0x12f], 0x69e5ec) (unaligned fields);
// this->slot0x80(this+0x6c, this+0x60); t = engine table slot 0x138(); id = 0; t->slot0x88(0x681320, &id); [this+0x164a] = engine table slot 0x58(id).
static void THISCALL fn5175a0(u8 *self) {
  ext_515630(self);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *w = *(u8 **)(eng + 0x1a9f);
  if (w) {
    u32 r = vcall<u32>(w, 0x60, rd32u(self + 0x12f), 0x69e5ecu);
    wr32u(self + 0x161d, r);
  }
  vcall<void>(self, 0x80, (u32)(self + 0x6c), (u32)(self + 0x60));
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *t = vcall<u8 *>(tbl, 0x138);
  u32 id = 0;
  vcall<void>(t, 0x88, 0x681320u, (u32)&id);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr32u(self + 0x164a, vcall<u32>(tbl, 0x58, id));
}
PCREG(5175a0, fn5175a0);

// 0x52b0c0, thiscall, no args, returns bool: p = [this+0x44]; when p and byte [p+0x10]: now = engine slot 0x1c8(0x6a0ea8, 0x3d); gap = now - [p]; ok = gap > [p+4] (unsigned),
// [p] = now when ok; the result is ok while the counter [p+0xc] is below the limit [p+8] (and then [p+0xc]++), else false. Always [this+0x49]++ (unaligned).
static bool THISCALL fn52b0c0(u8 *self) {
  u8 *p = *(u8 **)(self + 0x44);
  bool ok = false;
  if (p && p[0x10]) {
    u8 *eng = G(u8 *, 0x70039c);
    u32 now = (u32)vcall<u64>(eng, 0x1c8, 0x6a0ea8u, 0x3du);
    u8 *q = *(u8 **)(self + 0x44);
    u32 gap = now - *(u32 *)q;
    ok = gap > *(u32 *)(q + 4);
    if (ok) *(u32 *)q = now;
    u8 *c = *(u8 **)(self + 0x44);
    u32 cnt = *(u32 *)(c + 0xc);
    if (cnt >= *(u32 *)(c + 8)) ok = false;
    else if (ok) *(u32 *)(c + 0xc) = cnt + 1;
  }
  wr32u(self + 0x49, rd32u(self + 0x49) + 1);
  return ok;
}
PCREG(52b0c0, fn52b0c0);

// 0x5b3ba0, thiscall, no args: three calls of 0x5b58a0 (ECX = this+0x1be / +0x1cb / +0x1d8) with (this+0x1ad, this+0x1b0, byte +0x170, [engine+0x40]),
// (this+0x1ab, this+0x1ae, byte +0x16e, [engine+0x40]) and (this+0x1ac, this+0x1af, byte +0x16f, [engine+0x40]); the engine value is re-read each time.
static void THISCALL fn5b3ba0(u8 *self) {
  ext_5b58a0(self + 0x1be, self + 0x1ad, self + 0x1b0, (u32)self[0x170], *(u32 *)(G(u8 *, 0x70039c) + 0x40));
  ext_5b58a0(self + 0x1cb, self + 0x1ab, self + 0x1ae, (u32)self[0x16e], *(u32 *)(G(u8 *, 0x70039c) + 0x40));
  ext_5b58a0(self + 0x1d8, self + 0x1ac, self + 0x1af, (u32)self[0x16f], *(u32 *)(G(u8 *, 0x70039c) + 0x40));
}
PCREG(5b3ba0, fn5b3ba0);
