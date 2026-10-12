// batch6309.cpp - unclaimed-63 batch 9 (docs/20-unclaimed-63.md): ZGROUP::DuplicateToResource(ZGROUP*, unsigned int, DBLK*, char*, bool)
// at 0x440220 (GC name, high). Body: f = 0x45df10(this; a1, a2, a3, a4, 0) (thiscall, five stack arguments, original code);
// if flag and f != 0: for each node n of the list at [this+0x50] (next = [n+0x60]): c = [n+0x54]; edx = 0x67c8e8, or [c+4] if
// nonzero; c->vtbl[+0x1c0](f, a2, 0, edx, 1) (thiscall, five stack arguments). Returns f.
// The PC's hook path for a null [n+0x54] is not verified: the spec never makes it null (the PC would read [0+4] next, a fault).
#include "ff.h"

extern "C" u32 THISCALL ext_45df10(void *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);   // original, stubbed by the spec

typedef u32(THISCALL * call5_fn)(void *, u32, u32, u32, u32, u32);

// 0x440220 (GC name ZGROUP::DuplicateToResource, high).
static u32 THISCALL groupDuplicateToResource(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 flag) {
  u32 f = ext_45df10(self, a1, a2, a3, a4, 0);
  if (((u8)flag) != 0 && f != 0) {
    u32 n = *(u32 *)(self + 0x50);
    while (n != 0) {
      u32 c = *(u32 *)(n + 0x54);
      u32 edx = 0x67c8e8u;
      u32 e = *(u32 *)(c + 4);
      if (e != 0)
        edx = e;
      u32 vt = *(u32 *)c;
      ((call5_fn)(*(u32 *)(vt + 0x1c0)))((void *)c, f, a2, 0, edx, 1);
      n = *(u32 *)(n + 0x60);
    }
  }
  return f;
}
PCREG(440220, groupDuplicateToResource);
