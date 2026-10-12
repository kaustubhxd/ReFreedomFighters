// batch240.cpp - area 59, docs/20-unclaimed-59.md (coordinator loop). Appends the string at obj[0] to this's string (this[0]
// is the char pointer; the inline buffer is at this+4). If this is the same object, or obj is null, returns this. If the
// current string is inline and the result would be under 0x7c bytes, the copy goes into the inline buffer. Otherwise a new
// block of len1 + 1 + len2 bytes is allocated (0x41e290, cdecl), both strings are copied, and the old block is freed
// (0x634273, cdecl, size 1) unless it is the inline buffer. Returns this. Name GUESS.
#include "ff.h"

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);      // original allocator, cdecl (one stack word)
extern "C" void __attribute__((cdecl)) ext_634273(u8 *p, u32 size);   // original free, cdecl (two stack words)

static u32 strLen_4cc2c0(const u8 *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x4cc2c0, thiscall(obj) ret 4.
static u8 *THISCALL appendStr_4cc2c0(u8 *self, u8 *obj) {
  if (self == obj || obj == nullptr) return self;
  u8 *p = *(u8 **)self;
  u8 *srcp = *(u8 **)obj;
  u32 len1 = strLen_4cc2c0(p);
  u32 len2 = strLen_4cc2c0(srcp);
  if (p == self + 4 && len1 + 1 + len2 < 0x7cu) {
    for (u32 i = 0; i <= len2; i++) p[len1 + i] = srcp[i];   // len2 + 1 bytes, including the terminator
    return self;
  }
  u8 *nb = ext_41e290(len1 + 1 + len2);
  for (u32 i = 0; i <= len1; i++) nb[i] = p[i];
  for (u32 i = 0; i <= len2; i++) nb[len1 + i] = srcp[i];
  if (p != self + 4) ext_634273(p, 1);
  *(u8 **)self = nb;
  return self;
}
PCREG(4cc2c0, appendStr_4cc2c0);
