// batch67565.cpp - cascade s6 batch 67565: 0x534fd0.
#include "ff.h"

extern "C" u32 THISCALL ext_533e00(u8 *pool);          // plain ret: allocates a record handle
extern "C" void THISCALL ext_44b610(u8 *o);            // plain ret
extern "C" void ext_44b740(u8 *o);                     // cdecl

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)

// 0x534fd0, thiscall(owner, kind) ret 8, returns the new handle or 0: creates an effect record. 0x533e00 (pool at this+0x8b) yields a handle, resolved through the object table (slot 0x60). The
// record gets the table's current-object stamp (slot 0x4c of sys[0x9b] on [0xadc]), default parameters (angle 180.0 at +0x44 / +0x48, scale 1.0 at +0x84 / +0x88, limits 10000.0 / 12800.0 at
// +0x54 / +0x5c, mode 2 or 6 in +0x40 depending on kind == 4 with the 0x30 bits cleared, state 3 at +4), the owner at +0x80 / +0x7c, the clock sys[0x1c] at +0x6c and the kind at +8, and is registered
// through this slot 0x4c; if that fails the record is shut down (0x44b610, 0x44b740) and 0 returned.
static u32 THISCALL fn534fd0(u8 *self, u32 owner, u32 kind) {
  u32 h = ext_533e00(self + 0x8b);
  if (!h) return 0;
  u8 *s = vcall<u8 *>(*(u8 **)(SYS + 0x9b), 0x60, h);
  u8 *tab = *(u8 **)(SYS + 0x9b);
  D32(s, 0x3c) = vcall<u32>(tab, 0x4c, D32(tab, 0xadc));
  D32(s, 0x40) = 2;
  D32(s, 0x64) = 0;
  D32(s, 0x60) = 0;
  D32(s, 0x68) = 0;
  D32(s, 0x84) = 0x3f800000u;
  D32(s, 0x88) = 0x3f800000u;
  D32(s, 0x44) = 0x43b40000u;
  D32(s, 0x40) = (kind == 4) * 4 + 2;
  D32(s, 0x40) &= 0xffffffcfu;
  D32(s, 0x48) = 0x43b40000u;
  D32(s, 0x4c) = 0;
  D32(s, 0x50) = 0;
  D32(s, 0x54) = 0x461c4000u;
  D32(s, 0x5c) = 0x46480000u;
  D32(s, 0x2c) = 0;
  D32(s, 0x78) = 0;
  D32(s, 0x8c) = 0;
  D32(s, 4) = 3;
  D32(s, 0x80) = owner;
  s[0xec] = 0;
  D32(s, 0xed) = 0;
  D32(s, 0xf1) = 0;
  D32(s, 0xf5) = 0;
  D32(s, 0x64) = 0;
  D32(s, 0x60) = 0;
  D32(s, 0x6c) = D32(SYS, 0x1c);
  D32(s, 0x7c) = owner;
  D32(s, 4) = 3;
  D32(s, 0x8c) = 0;
  D32(s, 8) = kind;
  if (!(u8)vcall<u32>(self, 0x4c, (u32)s)) {
    ext_44b610(s);
    ext_44b740(s);
    return 0;
  }
  return h;
}
PCREG(534fd0, fn534fd0);
