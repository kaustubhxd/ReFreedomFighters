// batch37058.cpp - cascade s6 batch 37058: 0x49db30.
#include "ff.h"

extern "C" void FASTCALL ext_4e69b0(u32 *keys, u32 *vals, u32 lo, u32 hi);   // parallel quicksort, ret 8 (original code)
typedef u32(THISCALL *v1_t)(void *, u32);
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SORT(k, v, n) do { if ((s32)(n) > 1) ext_4e69b0((k), (v), 0, (n) - 1); } while (0)

// 0x49db30, thiscall, no args: filters and orders the id array at this+8 (this+0x14 entries). Ids the allocator at 0x70038c (slot 0xcc) does not know are dropped; the others are
// kept in place and get a key from slot 0xc of this. The array is sorted by that key (0x4e69b0, parallel quicksort), then within each run of equal keys it is sorted again by a
// composite key: the 16-bit kind (word at +0x1d of the record's object, found through +0x1c via table slot 0x58 or +0x40) shifted left 20 OR the record's +0x20. Finally
// this+0x14 = number kept.
static void THISCALL fn49db30(u8 *self) {
  u32 n = D32(self, 0x14);
  if (!n) return;
  u32 *keys = (u32 *)__builtin_alloca(n * 4);
  u32 m = 0;
  u32 i = 0;
  do {
    u8 *g = *(u8 **)0x70038c;
    u32 r = (*(v1_t **)g)[0xcc / 4](g, ((u32 *)D32(self, 8))[i]);
    if (r) {
      u32 *ids = (u32 *)D32(self, 8);
      ids[m] = ids[i];
      u32 k = (*(v1_t **)self)[0xc / 4](self, r);
      keys[m] = k;
      m++;
    }
    i++;
  } while (i != D32(self, 0x14));
  if ((s32)m <= 1) {
    D32(self, 0x14) = m;
    return;
  }
  ext_4e69b0(keys, (u32 *)D32(self, 8), 0, m - 1);
  u32 cur = keys[0];
  u32 lo = 0;
  u32 e = 0;
  do {
    u32 key = keys[e];
    if (cur != key) {
      s32 len = (s32)(e - lo);
      if (len > 1) ext_4e69b0(keys + lo, (u32 *)D32(self, 8) + lo, 0, len - 1);
      cur = key;
      lo = e;
    }
    u8 *g = *(u8 **)0x70038c;
    u8 *r2 = (u8 *)(*(v1_t **)g)[0xcc / 4](g, ((u32 *)D32(self, 8))[e]);
    u32 esi = 0;
    if (r2) {
      u32 t = D32(r2, 0x1c);
      u8 *obj2;
      bool have = true;
      if (t) {
        void *tab = *(void **)(*(u8 **)0x70039c + 0x9b);
        u8 *o = (u8 *)(*(v1_t **)tab)[0x58 / 4](tab, t);
        if (o) obj2 = *(u8 **)(o + 0xc);
        else { obj2 = 0; have = false; }
      } else {
        obj2 = *(u8 **)(r2 + 0x40);
      }
      if (have) esi = *(u16 *)(obj2 + 0x1d);
      esi = (esi << 0x14) | D32(r2, 0x20);
    }
    keys[e] = esi;
    e++;
  } while (e != m);
  s32 len = (s32)(e - lo);
  if (len > 1) ext_4e69b0(keys + lo, (u32 *)D32(self, 8) + lo, 0, len - 1);
  D32(self, 0x14) = m;
}
PCREG(49db30, fn49db30);
