// batch35090.cpp - cascade s5 batch 35090: 0x597680 (GUESS find the next usable slot in a circular table, starting at `a` and stepping by `b`).
#include "ff.h"

extern "C" u32 THISCALL ext_59ffc0(u8 *self);   // returns the dword at +0x77f (plain ret)
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u8(THISCALL *b0_t)(void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x597680, thiscall(a, b) ret 8, returns the index or -1. n = signed [this+0x1fae]; a < 0 becomes n - 1; start = a < n ? a : 0. Loop with i = start: o = [engine+0x9b] slot 0x58(unaligned dword [this + 4i + 0x1dae]);
// when 0x59ffc0(o) != 5 and o slot 0x670() is false, i is returned. Otherwise i += b, wrapped like a (negative gives n - 1, i >= n gives 0); returning to start gives -1.
static s32 THISCALL fn597680(u8 *self, s32 a, s32 b) {
  s32 n = *(s32 *)(self + 0x1fae);
  if (a < 0) a = n - 1;
  s32 start = a < n ? a : 0;
  s32 i = start;
  for (;;) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, rd32u(self + (u32)i * 4 + 0x1dae));
    if (ext_59ffc0(o) != 5 && !(*(b0_t **)o)[0x670 / 4](o)) return i;
    i += b;
    if (i < 0) i = *(s32 *)(self + 0x1fae) - 1;
    i = i < *(s32 *)(self + 0x1fae) ? i : 0;
    if (i == start) return -1;
  }
}
PCREG(597680, fn597680);
