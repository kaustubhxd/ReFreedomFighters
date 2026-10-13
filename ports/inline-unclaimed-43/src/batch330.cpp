// batch330.cpp - 0x43f9e0 (area 71 leaf, residue 10). stdcall, one stack argument (obj), ret 4, returns bool (al).
// Body: local = 0; DBLK::Get 0x4e11e0 (exe, thiscall: ecx = obj, args (&local, 1)); return local == 0.
#include "ff.h"

extern "C" void THISCALL ext_4e11e0(u8 *obj, u32 *out, u32 one);   // DBLK::Get (ret 8)

static bool STDCALL dblkGetIsZero(u8 *obj) {
  u32 local = 0;
  ext_4e11e0(obj, &local, 1u);
  return local == 0;
}
PCREG(43f9e0, dblkGetIsZero);
