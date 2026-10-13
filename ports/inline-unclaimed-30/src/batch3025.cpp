// batch3025.cpp - unclaimed-30 claim 2 (residue 10): ZFFActor::ClassFrameUpdate() [map 0x59e2a0; thiscall, ret 0]. If this+0x79f is set:
// the message table's slot 0x58 turns this+0x78a into an object; if that is not null, its slot 0x2d0 is called with (0, 0); the flag
// is cleared. Then the allocator (0x70038c) slot 0x48 gives a value for 0xff0000; exe 0x477a30 runs on this; the allocator's slot 0x48
// gets that value; exe 0x59ead0 runs on this. Then this's slot 0x438 decides: when it is true and this+0x784 and this+0x92e are both
// non-zero, this+0x784 is cleared. When slot 0x438 is false and this+0x784 is non-zero, the exe tail-jumps to 0x5a3000.
#include "ff.h"

extern "C" void THISCALL ext_477a30(u8 *self);   // exe code (ret 0)
extern "C" void THISCALL ext_59ead0(u8 *self);   // exe code (ret 0)
extern "C" void THISCALL ext_5a3000(u8 *self);   // exe code, the tail-jump target (ret 0)

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL zffActorClassFrameUpdate(u8 *self) {
  if (self[0x79f]) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *msg = *(u8 **)(eng + 0x9b);
    u8 *o = (u8 *)vcall<u32>(msg, 0x58, rd32u(self + 0x78a));
    if (o) vcall<void>(o, 0x2d0, (u32)0, (u32)0);
    self[0x79f] = 0;
  }
  u32 v = vcall<u32>(G(u8 *, 0x70038c), 0x48, (u32)0xff0000);
  ext_477a30(self);
  vcall<void>(G(u8 *, 0x70038c), 0x48, v);
  ext_59ead0(self);
  if (!vcall<u8>(self, 0x438)) {
    // not ok: a non-zero +0x784 hands over to 0x5a3000 (the exe tail-jumps there)
    if (rd32u(self + 0x784) != 0) ext_5a3000(self);
    return;
  }
  if (rd32u(self + 0x784) != 0 && rd32u(self + 0x92e) != 0) wr32u(self + 0x784, 0);
}
PCREG(59e2a0, zffActorClassFrameUpdate);
