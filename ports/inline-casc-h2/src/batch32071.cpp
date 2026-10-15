// batch32071.cpp - cascade h2 (Sonnet): 0x4e6720 (store a string copy + value), 0x4ccd60 (free-list table init), 0x5f1720 (pull a pointer back by whole dwords).
#include "ff.h"

extern "C" void THISCALL ext_5fb5a0(u8 *self);              // thiscall, plain ret
extern "C" u8 *ext_41e290(u32 n);                           // alloc, cdecl
extern "C" void ext_634273(u8 *p, u32 n);                   // free-style, cdecl

// 0x4e6720, thiscall(v, str) ret 8, returns v: free [this+4] (size 1) when set; [this+4] = copy of str (strlen+1 bytes from 0x41e290); [this+8] = v.
static u32 THISCALL fn4e6720(u8 *self, u32 v, const u8 *str) {
  u8 *old = *(u8 **)(self + 4);
  if (old) ext_634273(old, 1);
  const u8 *e = str;
  while (*e++) {}
  u8 *p = ext_41e290((u32)(e - str));
  *(u8 **)(self + 4) = p;
  u8 c;
  do { c = *str++; *p++ = c; } while (c);
  *(u32 *)(self + 8) = v;
  return v;
}
PCREG(4e6720, fn4e6720);

// 0x4ccd60, thiscall(n) ret 4, returns this: size = 1 << (n & 31); vtable 0x695b40; table = alloc(size*4, or -1 when that overflows);
// [4] = table, [0xc] = [0x10] = 0; table[i] = i + 1 for i < size-1, table[size-1] = size-1.
static u8 *THISCALL fn4ccd60(u8 *self, u32 n) {
  u32 size = 1u << (n & 31);
  *(u32 *)(self + 8) = size;
  *(u32 *)self = 0x695b40;
  u64 bytes = (u64)size * 4;
  u32 *t = (u32 *)ext_41e290(bytes >> 32 ? 0xffffffffu : (u32)bytes);
  *(u32 **)(self + 4) = t;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  u32 i = 0;
  if (size - 1 != 0) {
    do { t[i] = i + 1; i++; } while (i != size - 1);
  }
  t[i] = i;
  return self;
}
PCREG(4ccd60, fn4ccd60);

// 0x5f1720, thiscall, no args: 0x5fb5a0(this2->[4]) with b = [this+0xc]; then [b+0xb0] -= ([b+0xb0] - [b+0xac]) rounded down to whole dwords (arithmetic).
static void THISCALL fn5f1720(u8 *self) {
  u8 *b = *(u8 **)(self + 0xc);
  ext_5fb5a0(*(u8 **)(b + 4));
  b = *(u8 **)(self + 0xc);
  int d = ((int)(*(u32 *)(b + 0xb0) - *(u32 *)(b + 0xac))) >> 2;
  *(u32 *)(b + 0xb0) += (u32)(-d) << 2;
}
PCREG(5f1720, fn5f1720);
