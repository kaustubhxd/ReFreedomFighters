#include "ff.h"
// batch930.cpp - unclaimed-80 claim 10 (docs/20-unclaimed-80.md). ZInputActions::GetInputNode(const char*) (0x4392b0, vtable entry).
// Global table list at 0x6e48c0 (stride 16: dword at +0 = a table pointer, zero ends the list) with the base values at 0x6e48b8
// (+16i). Each table has 12-byte entries whose first dword is a name pointer (zero ends the table). The compare is the function
// pointer stored at 0x676414 (cdecl, called with the entry name then the argument; zero means equal). Found: returns
// base[i] + j. Not found: returns -1. Thiscall with one argument (ret 4).

static u32 THISCALL inputActionsGetInputNode(u8 *self, const char *name) {
  (void)self;
  typedef u32(* cmp_fn)(const char *, const char *);
  cmp_fn cmp = (cmp_fn)G(u32, 0x676414);
  if (G(u32, 0x6e48c0) == 0)
    return 0xffffffffu;
  u32 i = 0;
  for (;;) {
    u32 *t = (u32 *)G(u32, 0x6e48c0 + 16 * i);
    if (t[0] != 0) {
      u32 j = 0;
      do {
        if (cmp((const char *)t[3 * j], name) == 0)
          return G(u32, 0x6e48b8 + 16 * i) + j;
        j++;
      } while (t[3 * j] != 0);
    }
    i++;
    if (G(u32, 0x6e48c0 + 16 * i) == 0)
      break;
  }
  return 0xffffffffu;
}
PCREG(4392b0, inputActionsGetInputNode);
