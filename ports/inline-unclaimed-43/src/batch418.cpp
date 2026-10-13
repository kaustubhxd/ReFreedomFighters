// batch418.cpp - residue 2 leaves 0x57f960 and 0x54dfa0 (both thiscall, no arguments; no calls).
// 0x57f960: [this] = [this+4] = [this+8] = [this+0xc] = [this+0x10] = 0x6aaec8; [this+0x14], [this+0x18], [this+0x1c],
// [this+0x20] = 0; byte [this+0x28] = 0; returns this.
// 0x54dfa0: a = dword [this+0x61]; e = dword [this+8]; idx = dword [e+0x8018]; dword [e+0x4014 + 4*idx] = a; dword [e+0x8018]++;
// byte [this+0x7a] = 0; byte [this+0x7d] = 0; dword [this+0x61] = 0; if dword [this+0x75] == 3: p = dword [this+0x29];
// if p != 0: byte [p+0x58] = 0; dword [this+0x29] = 0.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u8 *THISCALL ctorDefaults57f960(u8 *self) {
  U32(self, 0x0) = 0x6aaec8u;
  U32(self, 0x4) = 0x6aaec8u;
  U32(self, 0x8) = 0x6aaec8u;
  U32(self, 0xc) = 0x6aaec8u;
  U32(self, 0x10) = 0x6aaec8u;
  U32(self, 0x14) = 0;
  U32(self, 0x18) = 0;
  U32(self, 0x1c) = 0;
  U32(self, 0x20) = 0;
  self[0x28] = 0;
  return self;
}

static void THISCALL appendAndClear54dfa0(u8 *self) {
  u32 a = U32(self, 0x61);
  u8 *e = (u8 *)(unsigned long)U32(self, 0x8);
  u32 idx = U32(e, 0x8018);
  U32(e, 0x4014 + 4 * idx) = a;
  U32(e, 0x8018) = idx + 1;
  self[0x7a] = 0;
  self[0x7d] = 0;
  U32(self, 0x61) = 0;
  if (U32(self, 0x75) == 3) {
    u32 p = U32(self, 0x29);
    if (p != 0) {
      ((u8 *)(unsigned long)p)[0x58] = 0;
      U32(self, 0x29) = 0;
    }
  }
}

PCREG(57f960, ctorDefaults57f960);
PCREG(54dfa0, appendAndClear54dfa0);
