// batch6216.cpp - unclaimed-62 claim 9 (slice 1): 0x44b610 (no name in the name map) [thiscall, ret 0]. The exe's SEH frame is not
// reproduced. With the engine's helper object A (eng+0x1a9f) present and A's byte +0xc zero: if this+0 is set, the message table's slot
// 0x58 gives an object, which gets +0x1c = 0 and its slot 0x210 with 1 when non-null; if this+0x38 and this+0x7c are set, the message
// table's slot 0x64 (this) gives a value and A's slot 0x134 gets (this+0x38, &value); then A's slot 0x130 gets this+0x38, this+0x30 and
// this+0x34 when each is set; the three fields are cleared. The exe's dead local (this+0x7c copied to the stack) is not reproduced.
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL fn44b610(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *a = rdp(eng + 0x1a9f);
  if (!a || a[0xc]) return;
  u32 o0 = rd32u(self);
  if (o0) {
    u8 *obj = (u8 *)vcall<u32>(rdp(eng + 0x9b), 0x58, o0);
    if (obj) {
      wr32u(obj + 0x1c, 0);
      vcall<void>(obj, 0x210, (u32)1);
    }
  }
  if (rd32u(self + 0x38) && rd32u(self + 0x7c)) {
    u32 val = vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x9b), 0x64, (u32)self);
    vcall<void>(rdp(G(u8 *, 0x70039c) + 0x1a9f), 0x134, rd32u(self + 0x38), (u32)&val);
  }
  if (rd32u(self + 0x38))
    vcall<void>(rdp(G(u8 *, 0x70039c) + 0x1a9f), 0x130, rd32u(self + 0x38));
  if (rd32u(self + 0x30))
    vcall<void>(rdp(G(u8 *, 0x70039c) + 0x1a9f), 0x130, rd32u(self + 0x30));
  if (rd32u(self + 0x34))
    vcall<void>(rdp(G(u8 *, 0x70039c) + 0x1a9f), 0x130, rd32u(self + 0x34));
  wr32u(self + 0x38, 0);
  wr32u(self + 0x30, 0);
  wr32u(self + 0x34, 0);
}
PCREG(44b610, fn44b610);
