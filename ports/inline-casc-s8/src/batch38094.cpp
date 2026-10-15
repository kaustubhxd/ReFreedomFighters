// batch38094.cpp - cascade s8 batch 38094: 0x61fd60 (string-keyed open-addressing hash table: find an entry or insert a zeroed one, growing at the load threshold).
#include "ff.h"

extern "C" u32 ext_61fce0(const u8 *key);                   // string hash
extern "C" void *ext_634d10(void *p, u32 v, u32 n);          // memset
typedef u8 *(*alloc_t)(u32);
typedef void (*free_t)(void *);
#define U(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define ALLOC(t) (*(alloc_t *)(U(t, 0x10) + 0))
#define FREE(t) (*(free_t *)(U(t, 0x10) + 8))

static u32 hash_of(const u8 *s) {
  u32 h = 0;
  while (*s) h = h * 33 + *s++;
  return h;
}
static u32 probe(u32 *b, u32 idx, u32 n) {
  while (b[idx]) idx = idx == 0 ? n - 1 : idx - 1;
  return idx;
}

// 0x61fd60, cdecl(table, key, size) -> entry. table: +0 buckets, +4 capacity (power of two), +8 count, +0xc grow threshold, +0x10 allocator {+0 alloc(size), +8 free(ptr)}. Entries start with a pointer to their key string.
// size == 0 only looks up.
static u8 *fn61fd60(u8 *t, const u8 *key, u32 size) {
  u32 n = U(t, 4);
  u32 idx, h = 0;
  if (n == 0) {
    if (size == 0) return 0;
    u32 *b = (u32 *)ALLOC(t)(0x100);
    U(t, 0) = (u32)b;
    if (!b) return 0;
    ext_634d10(b, 0, 0x100);
    U(t, 4) = 0x40;
    U(t, 0xc) = 0x20;
    idx = ext_61fce0(key) & 0x3f;
  } else {
    h = hash_of(key);
    u32 *b = (u32 *)U(t, 0);
    idx = (n - 1) & h;
    while (b[idx]) {
      const u8 *name = *(const u8 **)b[idx];
      u32 i = 0;
      while (name[i] == key[i]) {
        if (key[i] == 0) return (u8 *)b[idx];
        i++;
      }
      idx = idx == 0 ? n - 1 : idx - 1;
    }
    if (size == 0) return 0;
    if (U(t, 8) == U(t, 0xc)) {
      u32 nn = n * 2;
      u32 *nb = (u32 *)ALLOC(t)(nn * 4);
      if (!nb) return 0;
      ext_634d10(nb, 0, nn * 4);
      for (u32 i = 0; i < U(t, 4); i++) {
        u32 e = ((u32 *)U(t, 0))[i];
        if (e) {
          u32 h2 = hash_of(*(const u8 **)e);
          u32 j = (nn - 1) & h2;
          j = probe(nb, j, nn);
          nb[j] = e;
        }
      }
      FREE(t)((void *)U(t, 0));
      U(t, 4) = nn;
      U(t, 0) = (u32)nb;
      U(t, 0xc) = nn >> 1;
      idx = probe(nb, (nn - 1) & h, nn);
    }
  }
  u8 *e = ALLOC(t)(size);
  ((u32 *)U(t, 0))[idx] = (u32)e;
  if (!e) return 0;
  ext_634d10(e, 0, size);
  U(e, 0) = (u32)key;
  U(t, 8)++;
  return e;
}
PCREG(61fd60, fn61fd60);
