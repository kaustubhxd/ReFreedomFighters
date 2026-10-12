// batch620.cpp - band 0x421000-0x441000, batch 620: two functions.
//   0x43d360 ZHapticsBase::HapticsEnabled() (thiscall, no args, returns al): o = vslot 0xbc of [0x70039c] (no args);
//     returns (vslot 0x5c of o with (0x67c184, 0)) != 0. The callee of 0x5c pops 8.
//   0x434ab0 ZSysFile::ConvertFilename(this, const char *s) (stdcall, ret 8, returns this): MYSTR assign of s into this
//     (exe 0x4cbe80, claimed in docs/20-unclaimed-20.md: thiscall, one argument, stores its receiver and argument).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vNone)(void *self);
typedef u32(THISCALL *vTwo)(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_4cbe80(void *self, u32 s);         // MYSTR assign (thiscall, one argument; claimed)

static u8 THISCALL hapticsEnabled(u8 *self) {
  (void)self;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *o = (u8 *)((vNone)VT(sys, 0xbc))(sys);
  return ((vTwo)VT(o, 0x5c))(o, 0x67c184u, 0u) != 0;
}
PCREG(43d360, hapticsEnabled);

static u8 *STDCALL convertFilename(u8 *self, u32 s) {
  ext_4cbe80(self, s);
  return self;
}
PCREG(434ab0, convertFilename);
