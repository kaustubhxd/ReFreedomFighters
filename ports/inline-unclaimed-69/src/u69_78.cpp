// u69_78.cpp - area 69, group 78 (slice 8). Five small residue-8 functions. No callees.
#include "ff.h"

// 0x410bc0, cdecl (p, a, b; plain ret). Zeroes the five dwords at p, then p+0xc = a, p+8 = a, p+0x10 = b.
static void cdecl410bc0(u8 *p, u32 a, u32 b) {
  *(u32 *)(p + 0) = 0;
  *(u32 *)(p + 4) = 0;
  *(u32 *)(p + 8) = 0;
  *(u32 *)(p + 0xc) = 0;
  *(u32 *)(p + 0x10) = 0;
  *(u32 *)(p + 0xc) = a;
  *(u32 *)(p + 8) = a;
  *(u32 *)(p + 0x10) = b;
}
PCREG(410bc0, cdecl410bc0);

// 0x658180, stdcall (v; ret 4). Stores the float of the low byte of v in the global float at 0x6f6318.
static void STDCALL stdcall658180(u32 v) {
  *(float *)0x6f6318 = (float)(s32)(u8)v;
}
PCREG(658180, stdcall658180);

// 0x63eb40, thiscall (no args, ret), returns the largest +4 value over the lists at self+0x3408 (count) with heads at self+4*i (unsigned max, starting from 0).
static u32 THISCALL max63eb40(u8 *self) {
  u32 eax = 0;
  u32 edi = *(u32 *)(self + 0x3408);
  if (edi == 0)
    return eax;
  for (u32 esi = 0; esi < edi; ++esi) {
    u32 edx = *(u32 *)(self + 4 * esi);
    if (edx == 0)
      continue;
    do {
      if (eax < *(u32 *)(edx + 4))
        eax = *(u32 *)(edx + 4);
      edx = *(u32 *)(edx + 8);
    } while (edx != 0);
  }
  return eax;
}
PCREG(63eb40, max63eb40);

// 0x41d500, thiscall (ECX = the string s; no args; ret). Returns the position of the last '\\', '/' or ':' in s, or s-1 when there is none.
static u8 *THISCALL lastSep41d500(u8 *s) {
  u8 *edx = s;
  while (*edx != 0)
    ++edx;
  u8 *eax = s - 1 + (edx - s);
  if (eax < s)
    return eax;
  do {
    u8 c = *eax;
    if (c == 0x5c || c == 0x2f || c == 0x3a)
      return eax;
    --eax;
  } while (eax >= s);
  return eax;
}
PCREG(41d500, lastSep41d500);

// 0x534100, thiscall (ECX = base of 8-byte entries, one stack arg = index; ret 4). Counts the nodes of a chain that starts at entry index+1:
// each node's +4 value is the next index (0 and 0x80000000 end the chain).
static u32 THISCALL count534100(u8 *base, u32 arg) {
  u32 count = 0;
  if (arg == 0 || arg == 0x80000000u)
    return 0;
  u8 *p = base + (arg + 1) * 8;
  if (p == 0)
    return 0;
  while (p != 0) {
    u32 v = *(u32 *)(p + 4);
    ++count;
    if (v == 0 || v == 0x80000000u)
      p = 0;
    else
      p = base + (v + 1) * 8;
  }
  return count;
}
PCREG(534100, count534100);
