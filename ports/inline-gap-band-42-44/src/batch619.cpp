// batch619.cpp - band 0x421000-0x441000, batch 619: two functions.
//   0x4346c0 (stdcall, four arguments: this, a, b, c; ret 0x10): calls vslot 4 of this with (a, 0, b, c); the callee pops.
//   0x433cf0 (thiscall, no arguments): s = MYSTR::c_str (exe 0x4cc1d0, claimed in docs/20-collision.md) of [0x70039c]+0x1a17;
//     then vslot 0x48 of this with the one argument s.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vFour)(void *self, u32 a, u32 b, u32 c, u32 d);
typedef u32(THISCALL *vOne)(void *self, u32 a);
extern "C" u32 THISCALL ext_4cc1d0(void *obj);                  // MYSTR::c_str (thiscall, no args)

static void STDCALL callSlot4(u8 *self, u32 a, u32 b, u32 c) {
  ((vFour)VT(self, 4))(self, a, 0u, b, c);
}
PCREG(4346c0, callSlot4);

static void THISCALL callSlot48(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u32 s = ext_4cc1d0(sys + 0x1a17);
  ((vOne)VT(self, 0x48))(self, s);
}
PCREG(433cf0, callSlot48);
