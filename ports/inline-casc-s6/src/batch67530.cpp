// batch67530.cpp - cascade s6 batch 67530: 0x572090.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)

// 0x572090, thiscall(key, arg) ret 8, returns 0: for each of the three entries this[0x180 + i*4], when the object table (sys[0x9b], slot 0x58) maps `key` to that entry it formats a
// string (slot 0x198 of the logger's vtable, cdecl: (logger, buf, fmt 0x6a8948, arg)), hands it to the entry (slot 0x378) and then calls this-side slots 0x80 / 0x88 / 0x90 (i = 0 / 1 / 2) on
// the object sys slot 0xbc returns, followed by the table's slot 0x134 object logging (slot 0x60: fmt 0x6a8940 / 0x6a8930 / 0x6a8938, arg, 2).
static u32 THISCALL fn572090(u8 *self, u32 key, u32 arg) {
  char buf[0x80];
  for (int i = 0; i < 3; i++) {
    u8 *tab = *(u8 **)(SYS + 0x9b);
    u32 m = vcall<u32>(tab, 0x58, key);
    if (D32(self, 0x180 + i * 4) != m) continue;
    u8 *b = vcall<u8 *>(SYS, 0xbc);
    u8 *lg = vcall<u8 *>(SYS, 0x190);
    typedef void (__cdecl *fmt_t)(u8 *, char *, u32, u32);
    (*(fmt_t *)(*(u8 **)lg + 0x198))(lg, buf, 0x6a8948, arg);
    u8 *ent = *(u8 **)(self + 0x180 + i * 4);
    vcall<void>(ent, 0x378, (u32)buf);
    u32 fmt;
    if (i == 0) { vcall<void>(b, 0x80, arg); fmt = 0x6a8940; }
    else if (i == 1) { vcall<void>(b, 0x88, arg); fmt = 0x6a8930; }
    else { vcall<void>(b, 0x90, arg); fmt = 0x6a8938; }
    u8 *x = vcall<u8 *>(*(u8 **)(SYS + 0x9b), 0x134);
    vcall<void>(x, 0x60, fmt, arg, 2);
  }
  return 0;
}
PCREG(572090, fn572090);
