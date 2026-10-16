// batch6510.cpp - unclaimed-65: batch 10 (docs/20-unclaimed-65.md, claim 11). Thiscall, two stack arguments (word cmd, void* arg), ret 8.
#include "ff.h"

extern "C" u32 THISCALL ext_472ae0(u8 *self, u32 cmd, u8 *arg);

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

// 0x477950, ZActor::ClassCommand(unsigned short, void*) (residue 17). The command word selects one branch: 0x6ffa40 (slot +0x58c,
// then the tail), this+0x5be (slot +0x590), this+0x5c0 (slot +0x594), 0x6ffa1c (slot +0x5e4 with the argument), 0x6ffa20 (the
// argument's object: slot +0x350, then +0x340 with 0, then +0x32c; a result of 4..6 or 8 sets byte arg+4 = 1; then the tail). The
// tail: if this's slot +0x2fc returns zero (low byte), 0x472ae0(this, cmd, arg) is called. Returns 0.
static u32 THISCALL actorClassCommand(u8 *self, u32 cmd, u8 *arg) {
  const u16 c = (u16)cmd;
  if (c == G(u16, 0x6ffa40)) {
    vc0(self, 0x58c);
  } else if (c == *(const u16 *)(self + 0x5be)) {
    vc0(self, 0x590);
    return 0;
  } else if (c == *(const u16 *)(self + 0x5c0)) {
    vc0(self, 0x594);
    return 0;
  } else if (c == G(u16, 0x6ffa1c)) {
    vc1(self, 0x5e4, (u32)arg);
    return 0;
  } else if (c == G(u16, 0x6ffa20)) {
    u8 *x = (u8 *)vc0(*(u8 **)arg, 0x350);
    u8 *r = (u8 *)vc1(x, 0x340, 0);
    if (r) {
      const u32 v = vc0(r, 0x32c);
      if ((v >= 4 && v <= 6) || v == 8) arg[4] = 1;
    }
  }
  const u32 ok = (u8)((F0)(*(const u32 *)(*(const u32 *)self + 0x2fc)))(self);
  if (!ok) ext_472ae0(self, cmd, arg);
  return 0;
}
PCREG(477950, actorClassCommand);
