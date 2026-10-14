// batch915.cpp - residue-9 slice: 0x62d210 [cdecl: object pointer, code; no pop; returns a dword]. Body read in full: code 0x0f -> 0;
// code 0x11 -> *obj = 0x62e120, returns 7; code 0x1c with obj[3] == 0 -> 0x34; otherwise *obj = 0x51f230 and returns -1.
#include "ff.h"

// 0x62d210 (no name in the map).
s32 Fn62d210(u32 *obj, u32 code) {
  if (code == 0x0fu) return 0;
  if (code == 0x11u) {
    obj[0] = 0x62e120u;
    return 7;
  }
  if (obj[3] == 0 && code == 0x1cu) return 0x34;
  obj[0] = 0x51f230u;
  return -1;
}
PCREG(62d210, Fn62d210);
