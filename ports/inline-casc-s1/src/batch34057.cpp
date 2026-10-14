// batch34057.cpp - cascade tier E, batch 34057: 0x4800a0 (read a record layout from a stream), 0x484c50 (first-time setup guarded by a counter, then a tail slot), 0x492a90 (copy a service blob
// inside a logger scope).
#include "ff.h"

extern "C" void THISCALL ext_610100(void *self, void *s);              // thiscall ret 4 (an empty stub in the exe: runs for real)
extern "C" u32 THISCALL ext_4e1600(void *s);                           // thiscall, plain ret: peeks a stream byte, result in AL
extern "C" void THISCALL ext_4e12e0(void *s, void *p, u32 n);          // thiscall ret 8 (thunk)
extern "C" void THISCALL ext_4e12f0(void *s, void *p, u32 n);          // thiscall ret 8
extern "C" void THISCALL ext_4e1620(void *s, s32 a);                   // thiscall ret 4
extern "C" u32 THISCALL ext_4e1b30(void *s);                           // thiscall, plain ret
extern "C" void THISCALL ext_4673d0(void *self);                       // thiscall, plain ret
extern "C" u32 ext_41e290(u32 size);                                   // cdecl alloc

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4800a0, thiscall(s) ret 4: 0x610100(this, s); when 0x4e1600(s) is 3: 0x4e12e0(s, this+0x18, 1); 0x4e12f0(s, this+0x1c, 1), (this+0x24, 1), (this+0x20, 1); 0x4e1620(s, -1);
// 0x4e12e0(s, this+0x28, 0x13); 0x4e1b30(s) (its result stays in EAX).
static u32 THISCALL fn4800a0(u8 *self, u8 *s) {
  ext_610100(self, s);
  if ((u8)ext_4e1600(s) == 3) ext_4e12e0(s, self + 0x18, 1);
  ext_4e12f0(s, self + 0x1c, 1);
  ext_4e12f0(s, self + 0x24, 1);
  ext_4e12f0(s, self + 0x20, 1);
  ext_4e1620(s, -1);
  ext_4e12e0(s, self + 0x28, 0x13);
  return ext_4e1b30(s);
}
PCREG(4800a0, fn4800a0);

// 0x484c50, thiscall, no args: n = the unaligned counter [this+0x60a], bumped by one; returns when n was non-zero. Otherwise this slot 0x418(); this slot 0x384(this+0x5ce, this+0x5f2);
// x = this slot 0x428() stored at [this+0x5ca] (0 when the engine table slot 0x58(x) object is missing, which otherwise gets slot 0x94(this+0x5ce, this+0x5f2)); 0x4673d0(this); then
// this slot 0x368() (a tail call in the original).
static void THISCALL fn484c50(u8 *self) {
  u32 n = rd32u(self + 0x60a);
  wr32u(self + 0x60a, n + 1);
  if (n != 0) return;
  vcall<void>(self, 0x418);
  vcall<void>(self, 0x384, (u32)(self + 0x5ce), (u32)(self + 0x5f2));
  u32 x = vcall<u32>(self, 0x428);
  wr32u(self + 0x5ca, x);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x58, x);
  if (o) vcall<void>(o, 0x94, (u32)(self + 0x5ce), (u32)(self + 0x5f2));
  else wr32u(self + 0x5ca, 0);
  ext_4673d0(self);
  vcall<void>(self, 0x368);
}
PCREG(484c50, fn484c50);

// 0x492a90, thiscall, no args: nothing when [engine+0x1a9f] is zero. Otherwise h = global(0x70038c)->slot0x48(0x7777); n = this->slot0x1f8() (signed; n <= 0 leaves the scope open); p = alloc(n),
// this->slot0x1fc(p, n), [engine+0x1a9f]->slot0x90(p, n), then global slot 0x48(h) closes the scope.
static void THISCALL fn492a90(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  if (*(u32 *)(eng + 0x1a9f) == 0) return;
  u8 *g = G(u8 *, 0x70038c);
  u32 h = vcall<u32>(g, 0x48, 0x7777u);
  s32 n = (s32)vcall<u32>(self, 0x1f8);
  if (n <= 0) return;
  u32 p = ext_41e290((u32)n);
  vcall<void>(self, 0x1fc, p, (u32)n);
  u8 *w = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
  vcall<void>(w, 0x90, p, (u32)n);
  vcall<void>(G(u8 *, 0x70038c), 0x48, h);
}
PCREG(492a90, fn492a90);
