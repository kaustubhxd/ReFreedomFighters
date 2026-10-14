// batch35060.cpp - cascade s5 batch 35060: 0x438e30 (GUESS maximum (signed byte) of a per-entry value over a list).
#include "ff.h"

extern "C" u8 *THISCALL ext_438c30(u8 *self);   // plain ret, returns an object
typedef void(THISCALL *v1_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef u8(THISCALL *b1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x438e30, thiscall, no arguments, returns the AL maximum (signed byte compare, start 0). L = unaligned dword [this+0xd] (null: 0). L slot 0x4c(&it); for each e returned by L slot 0x5c(&it) (L reloaded)
// while it[0] != 0: v = (0x438c30(this)) slot 0x28(e) (AL); when (s8)v > (s8)best, best = v.
static u8 THISCALL fn438e30(u8 *self) {
  u32 it[3];
  s8 best = 0;
  u8 *L = (u8 *)rd32u(self + 0xd);
  if (!L) return 0;
  (*(v1_t **)L)[0x4c / 4](L, it);
  L = (u8 *)rd32u(self + 0xd);
  u32 e = (*(g1p_t **)L)[0x5c / 4](L, it);
  if (it[0] == 0) return (u8)best;
  do {
    u8 *o = ext_438c30(self);
    s8 v = (s8)(*(b1_t **)o)[0x28 / 4](o, e);
    if (v > best) best = v;
    L = (u8 *)rd32u(self + 0xd);
    e = (*(g1p_t **)L)[0x5c / 4](L, it);
  } while (it[0] != 0);
  return (u8)best;
}
PCREG(438e30, fn438e30);
