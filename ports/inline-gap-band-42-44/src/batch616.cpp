// batch616.cpp - band 0x421000-0x441000, batch 616: three functions.
//   0x431f80 CConfiguration::ApplyKeys() (thiscall, ret 0): the object at [[0x70039c]+0x1907] gets slot 0 with (this+0x84).
//   0x433e40 (thiscall, returns al): al = ext_432cd0(this) (exe code, no arguments), then al &= slot 0x1e8 of [0x70039c]().
//   0x435b30 (thiscall, ret 0): [this] = vtable 0x67a630; if [this+8] is set, call 0x634273(p, 1) (cdecl, two arguments).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
typedef u32(THISCALL *vNone)(void *self);
extern "C" u8 THISCALL ext_432cd0(void *self);                  // exe code (thiscall, no arguments, returns al)
extern "C" void ext_634273(void *p, u32 flags);                 // exe free helper (cdecl, two arguments)

static void THISCALL applyKeys(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(sys + 0x1907);
  ((vOne)VT(o, 0))(o, (u32)(self + 0x84));
}
PCREG(431f80, applyKeys);

static u8 THISCALL flagAnd1e8(u8 *self) {
  u8 a = ext_432cd0(self);
  u8 *sys = G(u8 *, 0x70039c);
  u8 b = (u8)((vNone)VT(sys, 0x1e8))(sys);
  return a & b;
}
PCREG(433e40, flagAnd1e8);

static void THISCALL resetAndFree(u8 *self) {
  u32 p = *(u32 *)(self + 8);
  *(u32 *)self = 0x67a630;
  if (p)
    ext_634273((void *)p, 1);
}
PCREG(435b30, resetAndFree);
