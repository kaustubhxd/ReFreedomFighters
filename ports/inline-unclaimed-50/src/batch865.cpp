// batch865.cpp - area 50 (residue-9 candidate): 0x5a2890 [80 instr, thiscall, two stack args (a name and a value), ret 8;
// no name in the map (GUESS "set a named slot of the object from a value")]. A zero value does nothing. The name is compared
// (stricmp, import 0x676414) with the constant at 0x6ae918: the slot at +0x7ae gets the object's vt +0x5a0 value of the new
// value and the old one goes to vt +0x598; the same with the constant at 0x6ae924 and the slot at +0x7b2. Otherwise a line is
// printed (logger 0x700390, file 0x6ae6a0, line 0x2e5, format 0x6ae930, the name) and vt +0x598 gets 0. The result is void
// here (the exe's zero path returns 0 in eax, not compared).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5a2890 (name GUESS).
static void THISCALL Fn5a2890(u8 *self, const char *name, u32 value) {
  if (value == 0) return;
  typedef int (*cmp_t)(const char *, const char *);   // cdecl (default on i686)
  cmp_t cmp = (cmp_t) * (u32 *)0x676414;
  if (cmp(name, (const char *)0x6ae918) == 0) {
    u32 old = U32(self, 0x7ae);
    U32(self, 0x7ae) = vcall<u32>(self, 0x5a0, value);
    vcall<void>(self, 0x598, old);
    return;
  }
  if (cmp(name, (const char *)0x6ae924) == 0) {
    u32 old = U32(self, 0x7b2);
    U32(self, 0x7b2) = vcall<u32>(self, 0x5a0, value);
    vcall<void>(self, 0x598, old);
    return;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *sink = vcall<u8 *>(lg, 0x20, (u32)0x6ae6a0, 0x2e5u);
  typedef void (*printf_t)(void *, const char *, const char *);
  (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x6ae930, name);
  vcall<void>(self, 0x598, 0u);
}
PCREG(5a2890, Fn5a2890);
