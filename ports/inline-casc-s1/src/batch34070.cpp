// batch34070.cpp - escalation batch 34070: 0x4dbd10 recursive node update.
#include "ff.h"

extern "C" void STDCALL ext_4dc630(u32 a, u32 b);      // stdcall ret 8
extern "C" void THISCALL ext_4d9ce0(void *self);       // thiscall, plain ret
extern "C" void THISCALL ext_4d9bf0(void *self);       // thiscall, plain ret
extern "C" void THISCALL ext_4d9d20(void *self, u32 a);   // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4dbd10, thiscall, plain ret, recursive: nothing unless flag bit 10 of [this+0x3c] is set (so the 0x200c00 tests below always see 0x400: the ext_4d9ce0/4d9bf0/4d9d20 paths are dead). If [[this+0x50]+0x3c] has 0x400: logging call (engine object 0x700390 slot 0x20(0x696e24, 0x248) returns a
// printer; printer slot 0x2c is called cdecl(printer, 0x696e4c, name of [this+0x54], name of [[this+0x50]+0x54]) where a name is [x+4] or "" 0x67c8e8). Else: ext_4dc630(0, 0x400); when flags & 0x200c00 is clear and
// 0x40000 set: (ext_4d9ce0 if [this+0x64] == 0) and ext_4d9bf0; q = [this+0x54]: q->slot0x24(1); when [[q+0xc]+0x23] (default 0x200002 for null q) has 0x100000, walk the chain c = [q+0x50] via [c+0x60]
// recursing on each; finally, when flags & 0x200c00 is clear: ext_4d9d20(this, 0).
static void THISCALL fn4dbd10(u8 *self) {
  if (!(rd32(self + 0x3c) >> 10 & 1)) return;
  u8 *n = *(u8 **)(self + 0x50);
  if (rd32(n + 0x3c) & 0x400) {
    u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x696e24u, 0x248u);
    u8 *p = *(u8 **)(n + 0x54);
    u32 name1 = 0x67c8e8, name2 = 0x67c8e8;
    if (p) { u32 v = *(u32 *)(p + 4); if (v) name1 = v; }
    u8 *q = *(u8 **)(self + 0x54);
    if (q) { u32 v = *(u32 *)(q + 4); if (v) name2 = v; }
    typedef void (*pf)(u8 *, u32, u32, u32);
    (*(pf *)(*(u8 **)pr + 0x2c))(pr, 0x696e4c, name2, name1);
    return;
  }
  ext_4dc630(0, 0x400);
  u32 fl = rd32(self + 0x3c);
  if (!(fl & 0x200c00) && (fl & 0x40000)) {
    if (*(u32 *)(self + 0x64) == 0) ext_4d9ce0(self);
    ext_4d9bf0(self);
  }
  u8 *q = *(u8 **)(self + 0x54);
  if (q) vcall<void>(q, 0x24, 1u);
  q = *(u8 **)(self + 0x54);
  u32 e = q ? rd32(*(u8 **)(q + 0xc) + 0x23) : 0x200002;
  if (e & 0x100000) {
    u8 *c = q ? *(u8 **)(q + 0x50) : 0;
    while (c) {
      u8 *s = *(u8 **)(c + 0x60);
      fn4dbd10(c);
      c = s;
    }
  }
  if (!(rd32(self + 0x3c) & 0x200c00)) ext_4d9d20(self, 0);
}
PCREG(4dbd10, fn4dbd10);
