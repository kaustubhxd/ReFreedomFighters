// batch621.cpp - band 0x421000-0x441000, batch 621: 0x4cc1e0 (string concatenation helper) and 0x42fa90 (ScenesPath).
//   0x4cc1e0 (thiscall, two stack arguments: out, second; ret 8): first = this (a MYSTR).
//     If first == second or second is null: out := assign(first's char* or the empty string 0x677b5a).
//     Otherwise: tmp := assign(first's char*); tmp := tmp + second (exe 0x4cc2c0); out := assign(tmp's char*);
//     if tmp's char* is not its own buffer (tmp+4), free it (exe 0x634273, cdecl, flags 1). Returns out.
//   0x42fa90 ZSysInterface::ScenesPath(dest) (thiscall, one argument, ret 4): concat(this+0x123, dest, this+0x1a3); returns dest.
// The assign (0x4cc630), concat step (0x4cc2c0) and free (0x634273) are exe code; the free is hooked in the spec.
#include "ff.h"

extern "C" void THISCALL ext_4cc630(void *mystr, u32 s);         // MYSTR::SetString (thiscall, one argument; claimed)
extern "C" void THISCALL ext_4cc2c0(void *mystr, u32 other);     // concat step (thiscall, one argument; exe code)
extern "C" void ext_634273(void *p, u32 flags);                  // free helper (cdecl, two arguments)

static const u32 kEmpty = 0x677b5a;

static u8 *THISCALL concatMystr(u8 *first, u8 *out, u8 *second) {
  u32 a = *(u32 *)first;
  if (first == second || second == 0) {
    ext_4cc630(out, a ? a : kEmpty);
    return out;
  }
  u8 tmp[0x94];
  ext_4cc630(tmp, a ? a : kEmpty);                 // lea ecx,[ebp-0x90] : tmp+0 is the char*, tmp+4 the buffer
  ext_4cc2c0(tmp, (u32)second);
  u32 b = *(u32 *)tmp;
  ext_4cc630(out, b ? b : kEmpty);
  if (*(u32 *)tmp != (u32)(tmp + 4))
    ext_634273((void *)*(u32 *)tmp, 1);
  return out;
}
PCREG(4cc1e0, concatMystr);

static u8 *THISCALL scenesPath(u8 *self, u8 *dest) {
  concatMystr(self + 0x123, dest, self + 0x1a3);
  return dest;
}
PCREG(42fa90, scenesPath);
