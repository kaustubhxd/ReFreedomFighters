// batch210067.cpp - Sonnet-w3a: 0x63d2f0 (drop one entry from a record's key table, cancel matching pending nodes in every registered owner, shrink the table)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_64c7e0(u8 *self, u32 id);
extern "C" u32 THISCALL ext_64d5f0(u8 *self, u8 *node);
extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);

static void THISCALL fn63d2f0(u8 *self, u8 *a, u32 b) {
  u32 id = *(u16 *)(a + 0x5a);
  if (!id) return;  // @63d2f0_a
  u32 idx4 = (id & 0xfff) << 2;
  u8 *rec = (u8 *)ld32((u8 *)ld32(self + 0x68) + idx4);
  u8 cnt = rec[0x3d];
  if (cnt <= 1) return;  // @63d2f0_b
  u8 *eng = G(u8 *, 0x70039c);
  u8 *ent = (u8 *)ld32(rec + 0x40);
  u32 i = 0;
  u32 key = ld32((u8 *)ld32(eng + 0x1aa3) + 0x20) + b;  // @63d2f0_c
  while (i != cnt) {  // @63d2f0_d
    if (ld32(ent + 4) == key) break;  // @63d2f0_e
    i++;
    ent += 8;
  }
  if (i == cnt) return;  // @63d2f0_f
  u32 n2 = ld32(self + 0xec);
  if (n2) {  // @63d2f0_g
    u8 *pp = self + 0xf0;
    for (u32 j = 0; j != n2; j = j + 1, pp += 4) {
      u8 *o = (u8 *)ld32(pp);
      u32 base = ld32(o + 0x10071);
      if (ld32((u8 *)(base + idx4)) != 0) {  // @63d2f0_h
        u8 *t = (u8 *)ext_64c7e0(o, id);  // @63d2f0_i
        u8 *edi = t + 0x1c;
        if (ld32(edi) != 0) {
          for (;;) {
            u8 *node = (u8 *)ld32(edi);
            u8 *x = (u8 *)ld32(node + 8);
            u8 *y = (u8 *)ld32(x + 0x10);
            if (key == ld32(y + 8)) {  // @63d2f0_j
              st32(node + 0x14, 0);
              u8 *x2 = (u8 *)ld32(node + 8);
              st32(x2 + 0x14, ld32(x2 + 0x14) & ~ld32(o + 0x10059));  // @63d2f0_k
              if (node[5] & 1) ext_64d5f0(o, node);  // @63d2f0_l
              st32(edi, ld32(node + 0x1c));  // @63d2f0_m
              st32(node + 0x1c, 0);
              break;
            }
            if (ld32(node + 0x1c) == 0) break;  // @63d2f0_n
            edi = node + 0x1c;
          }
        }
      }
    }
  }
  u8 *p0 = (u8 *)ld32(ent);
  if (p0) st32(p0 + 0xc, 0);  // @63d2f0_o
  u8 *arr = (u8 *)ld32(rec + 0x40);
  u8 *last = arr + rec[0x3d] * 8;
  st32(ent + 4, ld32(last - 4));  // @63d2f0_p
  u32 v = ld32(last - 8);
  st32(ent, v);
  if (v) ((u8 *)v)[8] = (u8)i;  // @63d2f0_q
  u32 sz = (u32)rec[0x3d] << 3;
  u8 *old = (u8 *)ld32(rec + 0x40);
  u8 *na = (u8 *)vcall<u32, u32>(self, 0x20, sz - 8);  // @63d2f0_r
  st32(rec + 0x40, (u32)na);
  ext_634d22((u32)na, (u32)old, sz - 8);  // @63d2f0_s
  vcall<u32, u8 *, u32>(self, 0x24, old, sz);  // @63d2f0_t
  rec[0x3d]--;  // @63d2f0_u
}
PCREG(63d2f0, fn63d2f0);
