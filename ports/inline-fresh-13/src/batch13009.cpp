// batch13009.cpp - fresh slice 13, batch 9 (docs/20-fresh-13.md), 2026-10-12.
// 0x65e210 ZGeometryDecal::Add(const float* pos, const float* dir, unsigned a, unsigned b, float f1, float f2,
// const float* col) (name map medium). Thiscall, seven arguments (ret 0x1c); returns the new decal or 0.
// Takes a 0x68-byte element from the pool at this+0x2d0 (free head word pool+0x3402 = this+0x36d2, 0xffff = empty; the
// element's first word is the next free index; pool+0x3400 counts the elements in use), fills it (pos at +0, dir at +0xc,
// a/b at +0x1c/+0x20, f1/f2 at +0x28/+0x2c, col[4] at +0x30, 1.0f at +0x40, 2 at +0x24, 0 at +0x44) and appends it to
// the list at this+0xd0[count +0xcc] (more than 0x80 -> the hook at 0x7003b0, int3 when null; the store still happens).
// Field names are GUESS.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

typedef void (*Hook0)(void);

static u32 THISCALL decalAdd(u8 *self, u32 *pos, u32 *dir, u32 a, u32 b, u32 f1, u32 f2, u32 *col) {
  u16 idx = AT(u16, self, 0x36d2);
  if (idx == 0xffff)
    return 0;
  u8 *pool = self + 0x2d0;
  u8 *e = pool + (u32)idx * 0x68;
  u16 next = AT(u16, e, 0);
  AT(u16, pool, 0x3400)++;
  AT(u16, pool, 0x3402) = next;
  AT(u32, e, 0) = pos[0];
  AT(u32, e, 4) = pos[1];
  AT(u32, e, 8) = pos[2];
  AT(u32, e, 0xc) = dir[0];
  AT(u32, e, 0x10) = dir[1];
  AT(u32, e, 0x14) = dir[2];
  AT(u32, e, 0x1c) = a;
  AT(u32, e, 0x20) = b;
  AT(u32, e, 0x28) = f1;
  AT(u32, e, 0x2c) = f2;
  AT(u32, e, 0x40) = 0x3f800000;
  AT(u32, e, 0x30) = col[0];
  AT(u32, e, 0x34) = col[1];
  AT(u32, e, 0x38) = col[2];
  AT(u32, e, 0x3c) = col[3];
  AT(u32, e, 0x24) = 2;
  AT(u32, e, 0x44) = 0;
  if (AT(u32, self, 0xcc) + 1 > 0x80) {
    u32 h = G(u32, 0x7003b0);
    if (!h)
      __builtin_debugtrap();
    ((Hook0)h)();
  }
  u32 n = AT(u32, self, 0xcc);
  AT(u32, self, 0xd0 + 4 * n) = (u32)e;
  AT(u32, self, 0xcc) = n + 1;
  return (u32)e;
}
PCREG(65e210, decalAdd);
