// batch35039.cpp - cascade s5 batch 35039: 0x454ca0 (GUESS refresh the resolved value of every listed entry).
#include "ff.h"

extern "C" u32 THISCALL ext_45be60(u8 *self, u32 a);   // thiscall, ret 4
typedef u32 (*hook_t)();
typedef void(THISCALL *v1_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef u8 *(THISCALL *e1_t)(void *, u32);

// 0x454ca0, thiscall, no arguments. L = [this+0x5c] (null: nothing; reloaded before each use). L slot 0x4c(&it); for each entry e returned by L slot 0x5c(&it) while it[0] != 0:
// o = engine table ([engine+0x9b]) slot 0x58(e[0x20]); when o is non-null: when the unaligned dword at [o+0xc]+0x23 is not 0x2000ee the assert hook 0x7003b0 is called (int3 when null);
// e[0x38] = 0x45be60(o, e[0x34]).
static void THISCALL fn454ca0(u8 *self) {
  u32 it[3];
  u8 *L = *(u8 **)(self + 0x5c);
  if (!L) return;
  (*(v1_t **)L)[0x4c / 4](L, it);
  L = *(u8 **)(self + 0x5c);
  u8 *e = (u8 *)(*(g1p_t **)L)[0x5c / 4](L, it);
  if (it[0] == 0) return;
  do {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, *(u32 *)(e + 0x20));
    if (o) {
      u8 *blk = *(u8 **)(o + 0xc);
      u32 kind = blk[0x23] | blk[0x24] << 8 | blk[0x25] << 16 | (u32)blk[0x26] << 24;
      if (kind != 0x2000ee) {
        hook_t h = G(hook_t, 0x7003b0);
        if (!h) __asm__ volatile("int3");
        h();
      }
      *(u32 *)(e + 0x38) = ext_45be60(o, *(u32 *)(e + 0x34));
    }
    L = *(u8 **)(self + 0x5c);
    e = (u8 *)(*(g1p_t **)L)[0x5c / 4](L, it);
  } while (it[0] != 0);
}
PCREG(454ca0, fn454ca0);
