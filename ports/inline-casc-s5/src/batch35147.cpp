// batch35147.cpp - cascade s5 batch 35147: 0x4d5f20 (GUESS parse into a local record, then process it with a fallback id).
#include "ff.h"

extern "C" u8 THISCALL ext_4d6520(u8 *self, u32 a, u8 *out, u32 z);              // thiscall, ret 0xc
extern "C" u32 THISCALL ext_4d62c0(u8 *self, u8 *rec, u32 b, u32 z, u32 id);     // thiscall, ret 0x10

// 0x4d5f20, thiscall(a, b, c) ret 0x10 (the fourth argument is unused; the stack cookie is not reproduced). 0x4d6520(this, a, local(0x1c), 0) failing (al == 0) returns -1; otherwise
// id = c, or the unaligned dword at local + 0x12 when c is 0; 0x4d62c0(this, local, b, 0, id) returning 0 gives -1, otherwise id.
static u32 THISCALL fn4d5f20(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u8 local[0x1c];
  if (!ext_4d6520(self, a, local, 0)) return 0xffffffffu;
  u32 id = c;
  if (!id) {
    u32 v;
    u8 *p = (u8 *)&v;
    for (int i = 0; i < 4; i++) p[i] = local[0x12 + i];
    id = v;
  }
  if (!ext_4d62c0(self, local, b, 0, id)) return 0xffffffffu;
  return id;
}
PCREG(4d5f20, fn4d5f20);
