// batch37038.cpp - cascade s6 batch 37038: 0x4e5160.
#include "ff.h"

extern "C" s32 FASTCALL ext_4cc850(const char *str, const char *pat);   // wildcard compare, 0 = match
typedef int(*stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)

static u8 *tableBase(u8 *e, u32 *count) {
  *count = *(u32 *)e;
  u32 f = *(u32 *)(e + 4) & 0xc0000000u;
  u32 off = (f == 0x40000000u || f == 0x80000000u || f == 0xc0000000u) ? *(u32 *)(e + 8) : 8;
  return e + off;
}

// 0x4e5160, thiscall(name) ret 4: looks a name up in the name table of this+4's object (flag bits at +4 select the entry list; names live at this+0xc plus the stored
// offsets). First pass: case-insensitive equality with the name stripped of its '*' characters; second pass: wildcard match (0x4cc850) of each entry against the name as given.
// Returns the entry's name pointer or 0 (also 0 for an empty name).
static u8 *THISCALL fn4e5160(u8 *self, const char *name) {
  if (*name == 0) return 0;
  char buf[0x84];
  {
    char *d = buf;
    char c = name[0];
    buf[0] = c;
    const char *s = name;
    do {
      char prev = c;
      c = s[1];
      s++;
      if (prev != '*') d++;
      *d = c;
    } while (c != 0);
  }
  u8 *h = *(u8 **)(self + 4);
  u8 *e;
  u32 fl = *(u32 *)(h + 4);
  if ((s32)fl < 0) {
    if (fl & 0x40000000u) e = h + *(u32 *)(h + 0x10) * 4 + 0x14;
    else e = h + 0x10;
  } else {
    e = 0;
  }
  u32 n;
  u8 *tab = tableBase(e, &n);
  for (u32 i = 0; i < n; i++) {
    u8 *nm = (u8 *)(*(u32 *)(self + 0xc) + ((u32 *)tab)[i]);
    if (imp_stricmp((const char *)nm, buf) == 0) return nm;
  }
  tab = tableBase(e, &n);
  for (u32 i = 0; i < n; i++) {
    u8 *nm = (u8 *)(*(u32 *)(self + 0xc) + ((u32 *)tab)[i]);
    if (ext_4cc850((const char *)nm, name) == 0) return nm;
  }
  return 0;
}
PCREG(4e5160, fn4e5160);
