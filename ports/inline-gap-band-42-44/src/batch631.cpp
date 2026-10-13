// batch631.cpp - band 0x421000-0x441000, batch 631: two thiscall functions.
//   0x42c100 (thiscall, one flag argument; ret 4): if flag == 0 return. p = slot 0x1b0 of this; if p is 0 return. q = slot 0x1b0 of
//     this again; tail-jump to slot 0x24 of q with ecx = q and the flag still on the stack (the target pops 4). The return value
//     is not defined on the early-return paths, so the spec compares no result.
//   0x422b50 (thiscall, two args a, b; ret 8): v = dword [this+0x1b49] * 0x10dcd + 1, stored back; out = (v sar 8) & 0x7fff;
//     call slot 0x1fc of this with (&out, 4, 0x12, a, b) (five arguments; the callee writes through &out); returns out.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vNone)(void *self);
typedef u32(THISCALL *vOneArg)(void *self, u32 a);
typedef u32(THISCALL *vFive)(void *self, u32 a, u32 b, u32 c, u32 d, u32 e);

static u32 THISCALL slot24OfSlot1b0(u8 *self, u32 flag) {
  if (flag == 0)
    return 0;
  u32 p = ((vNone)VT(self, 0x1b0))(self);
  if (p == 0)
    return 0;
  u32 q = ((vNone)VT(self, 0x1b0))(self);
  u8 *o = (u8 *)q;
  return ((vOneArg)VT(o, 0x24))(o, flag);
}
PCREG(42c100, slot24OfSlot1b0);

static u32 THISCALL randCallSlot1fc(u8 *self, u32 a, u32 b) {
  u32 v = *(u32 *)(self + 0x1b49) * 0x10dcdu;
  v += 1u;
  *(u32 *)(self + 0x1b49) = v;
  u32 out = (u32)((s32)v >> 8) & 0x7fffu;
  u32 res = out;                              // the exe returns esi, which the callee cannot change
  ((vFive)VT(self, 0x1fc))(self, (u32)&out, 4u, 0x12u, a, b);
  return res;
}
PCREG(422b50, randCallSlot1fc);
