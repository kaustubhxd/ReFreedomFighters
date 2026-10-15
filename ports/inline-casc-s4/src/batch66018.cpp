// batch66018.cpp - cascade s4 batch 66018: 0x5491a0 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_4db860(void *self, u32 a);   // ret 4

static u8 *lookup(u32 id) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return (*(v1o_t **)tab)[0x58 / 4](tab, id);
}

// Release an entry: when its type record o[0xc] has flag 0x100000 at +0x23, walk the list o[8] (advance with slot 0x50(&it)) calling 0x4db860(it, 1), then o->slot 0x2f (0xbc)(1); returns true.
// Otherwise false.
static bool release(u8 *o) {
  u8 *ty = *(u8 **)(o + 0xc);
  if (!(rd(ty + 0x23) & 0x100000)) return false;
  u32 it = rd(o + 8);
  if (it) {
    do {
      ext_4db860((void *)it, 1);
      (*(v1_t **)o)[0x50 / 4](o, (u32)&it);
    } while (it);
  }
  (*(v1_t **)o)[0xbc / 4](o, 1);
  return true;
}

// 0x5491a0, thiscall() plain ret (this = t): a = lookup(t[0x4c]), b = lookup(t[0x50]). a set: release(a) false -> t[0x4c] = 0. b set: release(b) false -> t[0x50] = 0.
static void THISCALL fn5491a0(u8 *t) {
  u8 *a = lookup(rd(t + 0x4c));
  u8 *b = lookup(rd(t + 0x50));
  if (a && !release(a)) wr(t + 0x4c, 0);
  if (b && !release(b)) wr(t + 0x50, 0);
}
PCREG(5491a0, fn5491a0);
