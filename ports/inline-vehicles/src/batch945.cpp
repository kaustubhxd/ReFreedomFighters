// batch945.cpp - vehicles thread, batch 945: ZHeli::CopyDataBlock(DBLK*), 0x51c210, callee pops 4.
// Base copy (0x512850, stood in). The gun flag +0x44d is read (0x4e12e0, stood in); without it, the warning
// "WARNING! %s NO WEAPON" (line 0x102). The block type (0x4e1600, exe): type 8 reads the rocket flag +0x451 and warns
// "WARNING! %s No Rockets" (line 0x105) when it is zero; any other type clears +0x451. Then the block is finished.
#include "ff.h"

extern "C" void THISCALL ext_512850(void *self, void *dblk);
extern "C" u32 THISCALL ext_4e1600(void *dblk);                   // DBLK type (exe, pure)
extern "C" void THISCALL ext_4e12e0(void *dblk, u32 *out, u32 n); // DBLK read (stood in)
extern "C" void THISCALL ext_4e1b30(void *dblk);                  // DBLK finish (stood in)

typedef void *(THISCALL * dbgAt)(void *, const char *, u32);
typedef void(CDECL_FN)(void *, const char *, const char *);
static void warnName(u8 *s, u32 line, const char *fmt) {
  void *dbg = *(void **)0x700390;
  void *o = (*(dbgAt *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x69f8b8, line);
  u32 nm = *(u32 *)(s + 4);
  ((CDECL_FN *)(*(u32 **)o)[0x2c / 4])(o, fmt, nm ? (const char *)nm : (const char *)0x67c8e8);
}

// 0x51c210 ZHeli::CopyDataBlock(DBLK*).
static void THISCALL heliCopyDataBlock(u8 *s, void *dblk) {
  ext_512850(s, dblk);
  ext_4e12e0(dblk, (u32 *)(s + 0x44d), 1);
  if (*(u32 *)(s + 0x44d) == 0)
    warnName(s, 0x102, (const char *)0x69f8f4);
  if ((u8)ext_4e1600(dblk) == 8) {
    ext_4e12e0(dblk, (u32 *)(s + 0x451), 1);
    if (*(u32 *)(s + 0x451) == 0)
      warnName(s, 0x105, (const char *)0x69f90c);
  } else {
    *(u32 *)(s + 0x451) = 0;
  }
  ext_4e1b30(dblk);
}
PCREG(51c210, heliCopyDataBlock);
