// batch5709.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 9: six call-free leaves from the full function list (names GUESS;
// the address is the identifier). Bodies copied from the PC bytes.
#include "ff.h"

// 0x410100 (GUESS, cdecl, one argument (a pointer to a pointer), no pop): al = byte at (*arg) + 4.
static u8 unnamed410100(u8 **a) {
  u8 *c = *a;
  return c[4];
}
PCREG(410100, unnamed410100);

// 0x4e7c40 (GUESS, thiscall, one argument, ret 4): this+9 = a (dword).
static void THISCALL unnamed4e7c40(u8 *self, u32 a) { *(u32 *)(self + 9) = a; }
PCREG(4e7c40, unnamed4e7c40);

// 0x4fa700 (GUESS, thiscall, one argument, ret 4): this+0x68 = a (dword).
static void THISCALL unnamed4fa700(u8 *self, u32 a) { *(u32 *)(self + 0x68) = a; }
PCREG(4fa700, unnamed4fa700);

// 0x5eebc0 (GUESS, thiscall, one argument, ret 4): this+0x73 = a (dword).
static void THISCALL unnamed5eebc0(u8 *self, u32 a) { *(u32 *)(self + 0x73) = a; }
PCREG(5eebc0, unnamed5eebc0);

// 0x650dc0 (GUESS, thiscall, one argument, ret 4): this+0xc = a (dword).
static void THISCALL unnamed650dc0(u8 *self, u32 a) { *(u32 *)(self + 0xc) = a; }
PCREG(650dc0, unnamed650dc0);

// 0x63ea80 (GUESS, stdcall, one argument, ret 4): returns the dword at (arg + 4) in eax.
static u32 STDCALL unnamed63ea80(u8 *a) { return *(u32 *)(a + 4); }
PCREG(63ea80, unnamed63ea80);
