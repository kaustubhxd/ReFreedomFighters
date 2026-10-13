// batch6508.cpp - unclaimed-65: batch 8 (docs/20-unclaimed-65.md, claim 8). Thiscall, no stack arguments (ret). Every call is virtual
// or on the render object; the render slot +0x114 takes four stack arguments (popped by the callee), so the fifth value pushed before
// it (0) stays on the stack and is the third argument of the next call (slot +0x12c, three arguments, callee pops).
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *F4)(u8 *self, u32 a, u32 b, u32 c, u32 d);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }
static u32 vc3(u8 *o, u32 s, u32 a, u32 b, u32 c) { return ((F3)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c); }
static u32 vc4(u8 *o, u32 s, u32 a, u32 b, u32 c, u32 d) { return ((F4)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c, d); }

// 0x4816e0, ZPlayer::CallBackAimInPosition() (residue 18): see docs/20-unclaimed-65.md (claim 8).
static void THISCALL playerCallBackAimInPosition(u8 *self) {
  vc1(self, 0x518, 3);
  u32 b = vc0(self, 0x50c);
  u32 s = vc0(self, 0x508);
  if (b && s) {
    u8 *x = (u8 *)vc0((u8 *)b, 0x350);
    const u32 b1 = vc0(x, 0x330);
    u8 *y = (u8 *)vc0((u8 *)s, 0x350);
    const u32 b2 = vc0(y, 0x330);
    if ((b1 == 0 || b1 == 1) && (b2 == 0 || b2 == 1)) vc1(self, 0x51c, 3);
  }
  u8 *rm = G(u8 *, 0x70039c);
  u8 *render = *(u8 **)(rm + 0x9b);
  u8 *z = (u8 *)vc0(render, 0x138);
  u32 tmp = 0;
  vc2(z, 0x88, 0x68c070, (u32)&tmp);
  if (tmp) {
    rm = G(u8 *, 0x70039c);
    render = *(u8 **)(rm + 0x9b);
    const u32 word = (u16)vc4(render, 0x114, 0x68c078, 0, 0x68bcbc, 0x712);
    vc3(self, 0x12c, tmp, word, 0);
  }
  u8 *o2 = *(u8 **)(self + 0x61a);
  if (vc0(o2, 0x14)) {
    const u32 r = vc1(o2, 0x34, 0);
    vc1(o2, 0x20, r);
  }
}
PCREG(4816e0, playerCallBackAimInPosition);
