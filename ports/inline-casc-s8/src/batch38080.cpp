// batch38080.cpp - cascade s8 batch 38080: 0x61f5a0 (xml parser: intern the name just read into the string pool; register namespace declarations / split the prefix off a qualified name).
#include "ff.h"

extern "C" u32 ext_620180(u8 *pool, u32 a, u32 b, u32 c);   // cdecl: read a name into the pool
extern "C" u32 ext_6206e0(u8 *pool);                        // cdecl: grow the pool
extern "C" u8 *ext_61fd60(u8 *table, u8 *key, u32 size);    // cdecl: find / insert an entry
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x61f5a0, cdecl(ctx, a, b, c) -> entry pointer or 0. ctx+0x1a8 = pool {+8 limit, +0xc cursor, +0x10 start of the last name}; the same fields are ctx[0x1b0] / [0x1b4] / [0x1b8];
// tables: ctx+0x180 names, ctx+0x194 prefixes; ctx[0xe8] = namespace processing on.
static u8 *fn61f5a0(u8 *ctx, u32 a, u32 b, u32 c) {
  u8 *pool = ctx + 0x1a8;
  if (W(ctx, 0x1b4) == W(ctx, 0x1b0)) {
    if (!ext_6206e0(pool)) return 0;
  }
  *(u8 *)W(ctx, 0x1b4) = 0;
  W(ctx, 0x1b4)++;
  if (!ext_620180(pool, a, b, c)) return 0;
  if (W(pool, 0xc) == W(pool, 8)) {
    if (!ext_6206e0(pool)) return 0;
  }
  *(u8 *)W(pool, 0xc) = 0;
  W(pool, 0xc)++;
  u8 *edi = (u8 *)W(pool, 0x10);
  if (!edi) return 0;
  edi++;
  u8 *r2 = ext_61fd60(ctx + 0x180, edi, 0xc);
  if (!r2) return 0;
  if (W(r2, 0) != (u32)edi) {
    W(ctx, 0x1b4) = W(ctx, 0x1b8);
    return r2;
  }
  W(ctx, 0x1b8) = W(ctx, 0x1b4);
  if (W(ctx, 0xe8) == 0) return r2;
  if (edi[0] == 'x' && edi[1] == 'm' && edi[2] == 'l' && edi[3] == 'n' && edi[4] == 's' && (edi[5] == 0 || edi[5] == ':')) {
    if (edi[5] == 0) {
      W(r2, 4) = (u32)(ctx + 0x1dc);
    } else {
      W(r2, 4) = (u32)ext_61fd60(ctx + 0x194, edi + 6, 8);
    }
    r2[9] = 1;
    return r2;
  }
  if (edi[0] == 0) return r2;
  int k = 0;
  while (edi[k] != ':') {
    if (edi[k + 1] == 0) return r2;
    k++;
  }
  for (int i = 0; i < k; i++) {
    if (W(ctx, 0x1b4) == W(ctx, 0x1b0)) {
      if (!ext_6206e0(pool)) return 0;
    }
    *(u8 *)W(ctx, 0x1b4) = edi[i];
    W(ctx, 0x1b4)++;
  }
  if (W(ctx, 0x1b4) == W(ctx, 0x1b0)) {
    if (!ext_6206e0(pool)) return 0;
  }
  *(u8 *)W(ctx, 0x1b4) = 0;
  W(ctx, 0x1b4)++;
  u8 *r3 = ext_61fd60(ctx + 0x194, (u8 *)W(ctx, 0x1b8), 8);
  W(r2, 4) = (u32)r3;
  u32 m = W(ctx, 0x1b8);
  if (W(r3, 0) == m) W(ctx, 0x1b8) = W(ctx, 0x1b4);
  else W(ctx, 0x1b4) = m;
  return r2;
}
PCREG(61f5a0, fn61f5a0);
