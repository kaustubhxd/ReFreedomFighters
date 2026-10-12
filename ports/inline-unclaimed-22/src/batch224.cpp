// batch224.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. Two vtable-heavy bodies:
// a guarded vtable call chain with a call to 0x4dcdf0 (one stack word), and a call through the global's object that copies
// 16 bytes from its argument after a call to 0x5a01e0.
#include "ff.h"

extern "C" void THISCALL ext_4dcdf0(u8 *self, u32 a);   // original, thiscall, one stack word (ret 4)
extern "C" void THISCALL ext_5a01e0(u8 *self);          // original, thiscall, no stack args (ret 0)

typedef u32(THISCALL *SlotU32)(u8 *, u32);
typedef u32(THISCALL *SlotU32Two)(u8 *, u32, u32);
typedef u32(THISCALL *SlotU32Three)(u8 *, u32, u32, u32);

// 0x4da6d0, thiscall(): e = this->[+0x6c]; if e == 0 return. rm = [0x70039c]; if rm->[+0x3c] > 0x64: o = rm->[+0x1aa3];
// if (u8)o->vt[0x18](e) != 0 return (the vtable call is on o->[+0x18]). Then obj = rm->[+0x1aa3]->[+0x18];
// r = obj->vt[0x6c](e, 0) (stack: first e, then 0); ext_4dcdf0(this, r). Name GUESS.
static void THISCALL guardedChain_4da6d0(u8 *self) {
  u32 e = *(u32 *)(self + 0x6c);
  if (!e) return;
  u8 *rm = *(u8 **)0x70039cu;
  if (*(u32 *)(rm + 0x3c) > 0x64) {
    u8 *o = *(u8 **)(rm + 0x1aa3);
    u8 *obj = *(u8 **)(o + 0x18);
    SlotU32 fn = (SlotU32)(*(u32 *)(*(u32 *)obj + 0x18));
    if ((u8)fn(obj, e)) return;
  }
  rm = *(u8 **)0x70039cu;
  u8 *o2 = *(u8 **)(rm + 0x1aa3);
  u8 *obj2 = *(u8 **)(o2 + 0x18);
  SlotU32Two fn2 = (SlotU32Two)(*(u32 *)(*(u32 *)obj2 + 0x6c));
  u32 r = fn2(obj2, e, 0);
  ext_4dcdf0(self, r);
}
PCREG(4da6d0, guardedChain_4da6d0);

// 0x5a2bd0, thiscall(a) ret 4 (ZFFActor helper, called from 0x59db34): cmd = (u16)ZEngineDataBase::RegisterZMsg(0x6a54b0,
// 0, 0x6ae6a0, 0xb62) (vtable 0x68d53c slot 0x114 = 0x493980, ret 0x10: FOUR words); then this->vt[0x130] =
// ZGEOM::SendCommand(this, cmd, a) (0x45fab0, ret 0xc); ext_5a01e0(this + 0x7ce); then the 16 bytes at a are copied to
// this + 0x8d2. The exe pushes a before the four RegisterZMsg words, so a stays on the stack as SendCommand's third
// argument (rewritten 2026-10-12; the first port passed five words to slot 0x114 and two to slot 0x130). Name GUESS.
static void THISCALL copyAfterCall_5a2bd0(u8 *self, u8 *a) {
  u8 *rm = *(u8 **)0x70039cu;
  u8 *o = *(u8 **)(rm + 0x9b);
  u8 *vt = *(u8 **)self;   // read before the call, as the exe does (esi)
  u32 r = vcall<u32>(o, 0x114, 0x6a54b0u, 0u, 0x6ae6a0u, 0xb62u);   // RegisterZMsg, ret 0x10
  u32 v = (u16)r;
  typedef void (THISCALL *SendCommand)(u8 *, u32, u32, u32);
  SendCommand fn = (SendCommand)(*(u32 *)(vt + 0x130));
  fn(self, (u32)self, v, (u32)a);
  ext_5a01e0(self + 0x7ce);
  u32 *src = (u32 *)a;
  u32 *dst = (u32 *)(self + 0x8d2);
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
}
PCREG(5a2bd0, copyAfterCall_5a2bd0);
