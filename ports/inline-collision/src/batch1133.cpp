// batch1133.cpp - collision thread, batch 1133 (gap-list rows, names GUESS): 0x4d2bc0 and 0x5ac640 (two stores), and 0x4d39c0,
// a wrapper of 0x4d24e0 (its ECX is passed through; the stub of 0x4d24e0 is in the spec).
#include "ff.h"

extern "C" u32 THISCALL ext_4d24e0(u32 ecx, u32 a, u32 b, u32 c, u32 d);   // exe: stubbed by address in the spec, ret 0x10

// 0x4d2bc0 (name GUESS): thiscall (ECX = value c), two stack arguments (out at [ebp+8], b at [ebp+0xc]), ret 8. Stores
// c at out[0] and b at out[1].
static void THISCALL store2_4d2bc0(u32 c, u32 *out, u32 b) {
  out[0] = c;
  out[1] = b;
}
PCREG(4d2bc0, store2_4d2bc0);

// 0x5ac640 (name GUESS): thiscall (ECX = this), two stack arguments (a at [ebp+8], b at [ebp+0xc]), ret 8. Stores a at
// [this+0xd] and b at [this+0x15] (unaligned dword stores).
static void THISCALL store2at_5ac640(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 0xd) = a;
  *(u32 *)(self + 0x15) = b;
}
PCREG(5ac640, store2at_5ac640);

// 0x4d39c0 (name GUESS): thiscall with ECX passed through, three stack arguments (a at [ebp+8], b at [ebp+0xc], c at
// [ebp+0x10]), ret 0xc. Calls 0x4d24e0 with (a, 2, b, c) and returns its EAX.
static u32 THISCALL wrap4d39c0(u32 ecx, u32 a, u32 b, u32 c) {
  return ext_4d24e0(ecx, a, 2u, b, c);
}
PCREG(4d39c0, wrap4d39c0);
