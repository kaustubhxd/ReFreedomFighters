// batch47005.cpp - cascade t8 batch 47005: 0x4a9110, 0x4af5b0 (tier F rows).
#include "ff.h"

typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef u8(THISCALL *v2b_t)(void *, u32, u32);

extern "C" void THISCALL ext_4daf90(void *self, u32 *out);   // ret 4: copies this[0x30..0x38] to out

// 0x4a9110, thiscall(stream) ret 4, returns 1: this[4] &= ~0x40; reads fields from the stream through its slots (each slot(ptr)): this+off with slot.
// 0x4a:0x48 0x5a:0x68 0x5b:0x48 0x5f:0x48 0x63:0x50 0x75:0x48 0x7d:0x6c 0x8b:0x6c 0x97:0x6c 0xbb/0xbf/0xc3/0xc9:0x40 0xd1:0x68 0xd2:0x48 0x52:0x40; then this slot 0x84().
static u32 THISCALL fn4a9110(u8 *self, u8 *s) {
  static const u16 tab[16][2] = {{0x4a, 0x48}, {0x5a, 0x68}, {0x5b, 0x48}, {0x5f, 0x48}, {0x63, 0x50}, {0x75, 0x48}, {0x7d, 0x6c}, {0x8b, 0x6c},
                                 {0x97, 0x6c}, {0xbb, 0x40}, {0xbf, 0x40}, {0xc3, 0x40}, {0xc9, 0x40}, {0xd1, 0x68}, {0xd2, 0x48}, {0x52, 0x40}};
  *(u32 *)(self + 4) &= 0xffffffbf;
  for (int i = 0; i < 16; i++) (*(v1_t **)s)[tab[i][1] / 4](s, (u32)(self + tab[i][0]));
  (*(v0_t **)self)[0x84 / 4](self);
  return 1;
}
PCREG(4a9110, fn4a9110);

static inline u16 rd16(u8 *p) { return (u16)(p[0] | (p[1] << 8)); }

// 0x4af5b0, thiscall(a) ret 4. it = a[0x18] iterator (slot 0x4c(&it), id = slot 0x5c(&it)); for each id until it == 0: obj = engine[0x9b]->slot 0x58(id); 0x4daf90(obj[8], &v);
// obj->slot 0x84(&v); this[0x44]->slot 0x8c(&v); this[0x44]->slot 0x180(&v, -10.0f) bool: true -> if this[0x5f] is set or this[0x5e] is 0: this[0x5e] = 1, this slot 0x84(word this[0x50]); return.
// After the loop (or no iterator): when this[0x5e]: this[0x5e] = 0, this slot 0x84(word this[0x52]).
static void THISCALL fn4af5b0(u8 *self, u8 *a) {
  u8 *o = *(u8 **)(a + 0x18);
  if (o) {
    u32 it;
    (*(v1_t **)o)[0x4c / 4](o, (u32)&it);
    o = *(u8 **)(a + 0x18);
    u32 id = (*(v1r_t **)o)[0x5c / 4](o, (u32)&it);
    while (it) {
      u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *obj = (u8 *)(*(v1r_t **)tbl)[0x58 / 4](tbl, id);
      u32 v[3];
      ext_4daf90(*(void **)(obj + 8), v);
      (*(v1_t **)obj)[0x84 / 4](obj, (u32)v);
      u8 *p = *(u8 **)(self + 0x44);
      (*(v1_t **)p)[0x8c / 4](p, (u32)v);
      p = *(u8 **)(self + 0x44);
      if ((*(v2b_t **)p)[0x180 / 4](p, (u32)v, 0xc1200000)) {
        if (self[0x5f] || !self[0x5e]) {
          self[0x5e] = 1;
          (*(v1_t **)self)[0x84 / 4](self, rd16(self + 0x50));
        }
        return;
      }
      o = *(u8 **)(a + 0x18);
      id = (*(v1r_t **)o)[0x5c / 4](o, (u32)&it);
    }
  }
  if (self[0x5e]) {
    self[0x5e] = 0;
    (*(v1_t **)self)[0x84 / 4](self, rd16(self + 0x52));
  }
}
PCREG(4af5b0, fn4af5b0);
