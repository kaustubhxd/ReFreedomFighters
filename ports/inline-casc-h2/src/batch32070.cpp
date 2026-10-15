// batch32070.cpp - cascade h2 (Sonnet): 0x562af0 (two-digit code string builder, /GS frame), 0x4361a0 (replace an owned string copy), 0x45b2f0 (init).
#include "ff.h"

extern "C" void THISCALL ext_562b50(u8 *self, char *s);            // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                   // /GS check
extern "C" u8 *ext_41e290(u32 n);                                  // alloc, cdecl
extern "C" void ext_634273(u8 *p, u32 n);                          // free-style, cdecl
extern "C" void THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c); // thiscall ret 0xc

// 0x562af0, thiscall(n) ret 4: s = "C0" + char('0' + n/10) + char('@' + n%10) + NUL; 0x562b50(this, s); /GS check.
static void THISCALL fn562af0(u8 *self, u32 n) {
  char s[8];
  u32 q = n / 10;
  s[0] = 0x43; s[1] = 0x30;
  s[2] = (char)(q + 0x30);
  s[3] = (char)((u8)n - (u8)(q * 10) + 0x40);
  s[4] = 0;
  ext_562b50(self, s);
  ext_633654(0);
}
PCREG(562af0, fn562af0);

// 0x4361a0, thiscall(str) ret 4: free [this+8] (size 1) when set; strlen+1 bytes from 0x41e290; [this+8] = copy; returns the end pointer (eax).
static u8 *THISCALL fn4361a0(u8 *self, const u8 *str) {
  u8 *old = *(u8 **)(self + 8);
  if (old) ext_634273(old, 1);
  const u8 *e = str;
  while (*e++) {}
  u32 len = (u32)(e - str);
  u8 *p = ext_41e290(len);
  *(u8 **)(self + 8) = p;
  u8 c;
  do { c = *str++; *p++ = c; } while (c);
  return p;
}
PCREG(4361a0, fn4361a0);

// 0x45b2f0, thiscall(a, b, c) ret 0xc, returns this: 0x43de40(this, a, b, c), then constants and interior pointers.
static u8 *THISCALL fn45b2f0(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)(self + 0x28) = 0x41000000;
  *(u32 *)(self + 0x2c) = 0x41200000;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)self = 0x6849d0;
  *(u32 *)(self + 0x3f8) = 0;
  *(u8 **)(self + 0x40) = self + 0x258;
  *(u8 **)(self + 0x248) = self + 0x2d8;
  *(u8 **)(self + 0x24c) = self + 0x2f8;
  *(u8 **)(self + 0x250) = self + 0x378;
  *(u8 **)(self + 0x254) = self + 0x3f8;
  *(u32 *)(self + 0x1c) = 0x20;
  *(u32 *)(self + 0x20) = 1;
  *(u32 *)(self + 0x18) = 0x18;
  return self;
}
PCREG(45b2f0, fn45b2f0);
