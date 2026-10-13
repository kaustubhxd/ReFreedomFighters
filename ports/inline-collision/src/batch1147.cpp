// batch1147.cpp - collision thread, batch 1147 (name GUESS): 0x4407c0. Thiscall (ECX = this), two stack arguments (s, mask), ret 8.
// p = strchr(s, '\\') (IAT 0x676254), or the end of s when there is none; blen = p - s. Walks the entries from [this+0x50] through
// [entry+0x60]: each entry's type T = [entry+0x54]; its flag word is the dword at [[T+0xc]+0x23] (0x200002 when T is null); a
// flag word without bit 0x100000 returns 0. If [T+0x30] & mask is set, the name is [T+4] (or 0x67c8e8) and it matches s over blen
// bytes when its length is blen and _memicmp (IAT 0x67640c) returns 0: then returns slot 0x25c of T with (p+1, 0) when *p is not
// zero, else T. Returns 0 when no entry matches. The two CRT calls go through their IAT slots (stubs in the spec).
#include "ff.h"

typedef char *(*StrchrFn)(const char *, int);
typedef int (*MemicmpFn)(const void *, const void *, u32);

static u8 *THISCALL find4407c0(u8 *self, const char *s, u32 mask) {
  char *p = ((StrchrFn)G(void *, 0x676254))(s, 0x5c);
  if (p == 0) {
    u32 n = 0;
    while (s[n] != 0) n++;
    p = (char *)(s + n);
  }
  u32 blen = (u32)(p - s);
  for (u8 *ent = *(u8 **)(self + 0x50); ent != 0; ent = *(u8 **)(ent + 0x60)) {
    u8 *T = *(u8 **)(ent + 0x54);
    u32 fl = (T != 0) ? *(u32 *)(*(u8 **)(T + 0xc) + 0x23) : 0x200002u;
    if ((fl & 0x100000u) == 0) return 0;
    if ((*(u32 *)(T + 0x30) & mask) == 0) continue;
    const char *name = (*(u32 *)(T + 4) != 0) ? (const char *)*(u32 *)(T + 4) : (const char *)0x67c8e8;
    u32 nl = 0;
    while (name[nl] != 0) nl++;
    if (nl != blen) continue;
    if (((MemicmpFn)G(void *, 0x67640c))(name, s, blen) != 0) continue;
    if (*p != 0) return vcall<u8 *>(T, 0x25c, (u32)(p + 1), 0u);
    return T;
  }
  return 0;
}
PCREG(4407c0, find4407c0);
