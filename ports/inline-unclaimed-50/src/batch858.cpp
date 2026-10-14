// batch858.cpp - area 50 (residue-9 candidate): 0x43f610 [106 instr, thiscall, three stack args (ret 0xc), returns bool;
// no name in the map (GUESS "walk the container at this+0x44 for an entry that accepts the transformed point")].
// The walk: an identity iterator (0x4de7a0) is set up; 0x4df330 (exe, pure math) tests the range at this+0x18 / this+0x24
// against a, b and c; the container at this+0x44 gives an id (vt +0x5c, with a flag at the pointer), the id resolves through
// the engine manager (vt +0x58) to an entry S. For an entry, the point b - (S+8)+0x24 is transformed by S+8 (0x441a60) and
// the iterator is updated from a and S+8 (0x4de4b0); S's vt +0x188 (iterator, point, c) decides. A missing entry is
// skipped through the container's vt +0x44. The container's vt +0x4c runs once at the start.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4de7a0(void *it);                                                    // identity iterator (exe)
extern "C" u8 FASTCALL ext_4df330(void *it, void *r, void *p0, void *p1, void *p2, u32 p3);       // range test (exe)
extern "C" void FASTCALL ext_441a60(float *v, const void *m);                                     // v = m * v (exe)
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);                    // d = a - b (exe)
extern "C" void FASTCALL ext_4de4b0(void *it, const void *a, const void *x);                      // iterator update (exe)

// 0x43f610 (name GUESS).
static bool THISCALL Walk43f610(u8 *self, void *a, void *b, u32 c) {
  u8 it[0x24];
  float v10[4] = {0, 0, 0, 0};
  u32 v48 = 0;
  ext_4de7a0(it);
  if (!ext_4df330(it, self + 0x24, self + 0x18, a, b, c)) return false;
  u8 *o = (u8 *)FP(self, 0x44);
  if (!o) return true;
  vcall<void>(o, 0x4c, &v48);
  u32 id = vcall<u32>(o, 0x5c, &v48);
  if (v48 == 0) return false;
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  for (;;) {
    u8 *s = vcall<u8 *>(mgr, 0x58, id);
    if (s) {
      u8 *x = (u8 *)FP(s, 8);
      ext_43e920(v10, (const float *)b, (const float *)(x + 0x24));
      ext_441a60(v10, x);
      ext_4de4b0(it, a, x);
      if (vcall<u8>(s, 0x188, it, v10, c)) return true;
    } else {
      vcall<void>(o, 0x44, &v48);
    }
    id = vcall<u32>(o, 0x5c, &v48);
    if (v48 == 0) return false;
  }
}
PCREG(43f610, Walk43f610);
