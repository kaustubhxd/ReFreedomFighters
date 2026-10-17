// batch818.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" char *THISCALL ext_5acfe0(u8 *self);                 // real callee: returns self + 8
extern "C" void THISCALL ext_5ae900(u8 *self, const char *s);   // real callee: strcpy(self + 6, s)
extern "C" u8 THISCALL ext_663190(u8 *self);                    // hooked (GUESS)
typedef u8(THISCALL *VPathFlag)(u8 *, const char *, u32);      // vt thiscall, two words, callee cleans (ret 8)

static inline void copyStr(char *d, const char *s) {
  while ((*d++ = *s++) != 0) {
  }
}
static inline void catStr(char *d, const char *s) {
  while (*d) ++d;
  copyStr(d, s);
}

// 0x663770, thiscall(out) ret 4, /GS frame: name = sub->(0x35a)+8 with sub = [this+0x12104]; file = name + ".dat"
// (literal at 0x678d08); sub+6 = file (0x5ae900); path = (this+0x121b4) + file; [0x700394]->vt[0x34](path, 0).
// True: *out = 0x10, returns 0. False: 0x663190(this); false again gives *out = 0x12 and 0, true gives 1.
static u8 THISCALL openDat_663770(u8 *self, u32 *out) {
  char file[0x80];
  char path[0x80];
  u8 *sub = *(u8 **)(self + 0x12104);
  copyStr(file, ext_5acfe0(sub + 0x35a));
  catStr(file, (const char *)0x678d08u);
  copyStr(path, (const char *)(self + 0x121b4));
  catStr(path, file);
  ext_5ae900(*(u8 **)(self + 0x12104), file);
  u8 *fs = *(u8 **)0x700394u;
  VPathFlag f = (VPathFlag)(*(u32 *)(*(u32 *)fs + 0x34));
  if (f(fs, path, 0u)) {
    *out = 0x10;
    return 0;
  }
  if (!ext_663190(self)) {
    *out = 0x12;
    return 0;
  }
  return 1;
}
PCREG(663770, openDat_663770);
