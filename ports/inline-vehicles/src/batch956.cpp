// batch956.cpp - residue-03 (core todo), batch 956: ZFFMortar::Command(unsigned short, void*), 0x5dd1b0, thiscall, ret 8.
// Two message ids from the render manager (vslot 0x114, four pushed args: name, 0, file 0x6b6d70, line 0x38 / 0x4a).
// When cmd == id1: the flag bytes +0x75..+0x79 are cleared for the matching slots; when the value matches +0x51 or +0x55,
// the render manager's vslot 0x58 (this+0x5d) answers an object that gets vslot 0xbc with 1. When cmd == id2: the same
// bytes are set (+0x79 only when the value matches +0x59). Returns 0 in every path.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5dd1b0 ZFFMortar::Command(unsigned short, void*).
static void THISCALL mortarCommand(u8 *t, u16 cmd, u32 v) {
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u16 id1 = vcall<u16>(rm, 0x114, 0x6b6da0u, 0u, 0x6b6d70u, 0x38u);
  if (cmd == id1) {
    if (v == D(t, 0x49))
      t[0x75] = 0;
    if (v == D(t, 0x4d))
      t[0x76] = 0;
    u32 a = D(t, 0x51);
    if (v == a)
      t[0x77] = 0;
    u32 b = D(t, 0x55);
    if (v == b)
      t[0x78] = 0;
    if (v == D(t, 0x59))
      t[0x79] = 0;
    if (v == a || v == b) {
      void *o = (void *)vcall<u32>(rm, 0x58, D(t, 0x5d));
      vcall<void>(o, 0xbc, 1u);
    }
  }
  u16 id2 = vcall<u16>(rm, 0x114, 0x6b6dacu, 0u, 0x6b6d70u, 0x4au);
  if (cmd == id2) {
    if (v == D(t, 0x49))
      t[0x75] = 1;
    if (v == D(t, 0x4d))
      t[0x76] = 1;
    if (v == D(t, 0x51))
      t[0x77] = 1;
    if (v == D(t, 0x55))
      t[0x78] = 1;
    if (v == D(t, 0x59))
      t[0x79] = 1;
  }
}
PCREG(5dd1b0, mortarCommand);
