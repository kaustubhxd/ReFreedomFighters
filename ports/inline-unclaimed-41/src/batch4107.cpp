// batch4107.cpp - unclaimed-41 batch 7 (slice 13, loop): 0x5ab9d0 (name not in the map; GUESS).
#include "ff.h"

extern "C" void THISCALL ext_4db7c0(u8 *self, u32 outptr);    // one stack argument (a float out pointer); checksum stub (GUESS)
extern "C" void THISCALL ext_5ac660(u8 *self, u32 a1, u32 a2); // two stack arguments (ret 8); checksum stub (GUESS)
extern "C" u32 THISCALL ext_5ebde0(u8 *self, u32 a1);          // one stack argument; returns eax; checksum stub (GUESS)

// 0x5ab9d0 (GUESS name): thiscall, no arguments, returns an int in eax. ebx = 0; for each 16-byte entry e in [this+0x6e, this+0x72):
//   tmp = (float) written by 0x4db7c0 through &tmp, with ecx = [[e+8]+8]
//   ebx = (int)(tmp * C + (float)ebx), where C is the float at 0x680a60
//   if [e] != 0 and [this+0x6a] != 0: ext_5ac660(this, [e], 0); ebx += ext_5ebde0([this+0x6a], 0)
// Then it returns ebx.
static u32 THISCALL loopSum5ab9d0(u8 *self) {
  int ebx = 0;
  u8 *e = *(u8 **)(self + 0x6e);
  u8 *end = *(u8 **)(self + 0x72);
  while (e != end) {
    u8 *p = *(u8 **)(e + 8);
    u8 *q = *(u8 **)(p + 8);
    float tmp;
    ext_4db7c0(q, (u32)&tmp);
    float v = tmp * G(float, 0x680a60) + (float)ebx;
    ebx = (int)v;
    u32 first = *(u32 *)e;
    if (first != 0 && *(u32 *)(self + 0x6a) != 0) {
      ext_5ac660(self, first, 0u);
      ebx = (int)((u32)ebx + ext_5ebde0(*(u8 **)(self + 0x6a), 0u));
    }
    e += 0x10;
  }
  return (u32)ebx;
}
PCREG(5ab9d0, loopSum5ab9d0);
