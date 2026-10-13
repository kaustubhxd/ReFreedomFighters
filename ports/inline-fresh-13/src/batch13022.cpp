// batch13022.cpp - fresh slice 13, batch 22 (docs/20-fresh-13.md), 2026-10-12.
// 0x431a50 CConfiguration::AddKeyMapping(SActionOverride*) (name map high): thiscall, ret 4. Returns the number of
// overrides with the same action and context (+1 when a new one was added).
//  - The list at this+0x84 (iterator slots 0x4c / 0x64, remove-current 0x44, new node 0x4) is walked. An entry
//    matches when _stricmp(name(entry), name(src)) == 0 (MYSTR c_str 0x4cc1d0 run as exe code) and the context strings
//    at +0xaf are both null or _stricmp-equal. Each match counts; a match whose keys (+0x80..+0x8c, +0xa1) are all the
//    same marks `found`, any other match is removed from the list.
//  - found: return the count. Otherwise a node is created (slot 4 with 0; the object is the result - 4, constructed
//    by MYSTR::MYSTR 0x4cbeb0 run as exe code), the fields are copied, MYSTR::operator= 0x4cbee0 copies the name and
//    the context string is duplicated with operator new 0x41e290 (strlen + 1) and a byte copy. Returns count + 1.
//  The SEH frame and /GS cookie are not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_4cc1d0[], ext_4cbeb0[], ext_4cbee0[], ext_41e290[];
typedef u32(THISCALL *R0)(void *self);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef void(THISCALL *PI)(void *self, u32 *it);
typedef u8 *(THISCALL *NI)(void *self, u32 *it);
typedef s32 (*Cmp)(const char *a, const char *b);
typedef void *(*New)(u32 n);

static inline s32 stricmp_(u32 a, u32 b) { return (*(Cmp *)0x676414)((const char *)a, (const char *)b); }

static u32 THISCALL fn431a50(u8 *self, u8 *src) {
  u8 *lst = self + 0x84;
  s32 count = 0;
  u8 found = 0;
  if (lst) {
    u32 it[6];
    ((PI)VT(lst, 0x4c))(lst, it);
    for (u8 *e = ((NI)VT(lst, 0x64))(lst, it); e; e = ((NI)VT(lst, 0x64))(lst, it)) {
      u32 ns = ((R0)(void *)ext_4cc1d0)(src);
      u32 ne = ((R0)(void *)ext_4cc1d0)(e);
      if (stricmp_(ne, ns))
        continue;
      u32 a = AT(u32, src, 0xaf);
      if (a || AT(u32, e, 0xaf)) {
        if (!a)
          continue;
        u32 b = AT(u32, e, 0xaf);
        if (!b || stricmp_(a, b))
          continue;
      }
      count++;
      if (AT(u32, src, 0x80) == AT(u32, e, 0x80) && AT(u32, src, 0x84) == AT(u32, e, 0x84) &&
          AT(u32, src, 0x88) == AT(u32, e, 0x88) && AT(u32, src, 0x8c) == AT(u32, e, 0x8c) &&
          AT(u32, src, 0xa1) == AT(u32, e, 0xa1)) {
        found = 1;
        continue;
      }
      ((PI)VT(lst, 0x44))(lst, it);
    }
    if (found)
      return count;
  }
  u8 *n = (u8 *)((R1)VT(lst, 4))(lst, 0) - 4;
  u8 *o = 0;
  if (n)
    o = (u8 *)((R0)(void *)ext_4cbeb0)(n);
  AT(u8, o, 0xa0) = AT(u8, src, 0xa0);
  AT(u32, o, 0xa1) = AT(u32, src, 0xa1);
  AT(u8, o, 0xa5) = AT(u8, src, 0xa5);
  AT(u8, o, 0xa6) = AT(u8, src, 0xa6);
  AT(u32, o, 0x80) = AT(u32, src, 0x80);
  AT(u32, o, 0x90) = AT(u32, src, 0x90);
  AT(u32, o, 0x84) = AT(u32, src, 0x84);
  AT(u32, o, 0x94) = AT(u32, src, 0x94);
  AT(u32, o, 0x88) = AT(u32, src, 0x88);
  AT(u32, o, 0x98) = AT(u32, src, 0x98);
  AT(u32, o, 0x8c) = AT(u32, src, 0x8c);
  AT(u32, o, 0x9c) = AT(u32, src, 0x9c);
  AT(u32, o, 0xa7) = AT(u32, src, 0xa7);
  AT(u32, o, 0xab) = AT(u32, src, 0xab);
  ((R1)(void *)ext_4cbee0)(o, (u32)src);
  const char *s = AT(const char *, src, 0xaf);
  if (s) {
    u32 len = 0;
    while (s[len])
      len++;
    char *d = (char *)((New)(void *)ext_41e290)(len + 1);
    AT(char *, o, 0xaf) = d;
    const char *q = AT(const char *, src, 0xaf);
    char ch;
    do {
      ch = *q++;
      *d++ = ch;
    } while (ch);
  } else {
    AT(u32, o, 0xaf) = 0;
  }
  return count + 1;
}
PCREG(431a50, fn431a50);
