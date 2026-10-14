// batch37026.cpp - cascade s6 batch 37026: 0x6302f0.
#include "ff.h"

extern "C" void ext_630ce0(u8 *s, u8 *tree, s32 k);        // pqdownheap, cdecl
extern "C" void ext_6309a0(u8 *s, u8 *desc);                // gen_bitlen, cdecl
extern "C" void ext_630bb0(u8 *tree, s32 max_code, u8 *bl_count);   // gen_codes, cdecl

#define HEAPLEN(s) (*(s32 *)((s) + 0x1448))
#define HEAPMAX(s) (*(s32 *)((s) + 0x144c))
#define HEAP(s, i) (*(s32 *)((s) + 0xb54 + 4 * (i)))
#define DEPTH(s, i) (*(u8 *)((s) + 0x1450 + (i)))
#define FREQ(t, i) (*(u16 *)((t) + 4 * (i)))
#define DAD(t, i) (*(u16 *)((t) + 4 * (i) + 2))

// 0x6302f0, cdecl(s, desc): zlib's build_tree (deflate Huffman tree construction). desc: +0 tree, +4 max_code (written), +8 static descriptor ({+0 static tree, +0xc elems}).
// s: heap_len +0x1448, heap_max +0x144c, heap[] +0xb54, depth[] +0x1450, opt_len +0x16a0, static_len +0x16a4, bl_count +0xb34. pqdownheap/gen_bitlen/gen_codes are the zlib
// helpers (0x630ce0, 0x6309a0, 0x630bb0).
static void fn6302f0(u8 *s, u8 *desc) {
  u8 *tree = *(u8 **)desc;
  u8 *sd = *(u8 **)(desc + 8);
  u8 *stree = *(u8 **)sd;
  s32 elems = *(s32 *)(sd + 0xc);
  s32 max_code = -1;
  HEAPLEN(s) = 0;
  HEAPMAX(s) = 0x23d;
  for (s32 n = 0; n < elems; n++) {
    if (FREQ(tree, n) != 0) {
      HEAPLEN(s)++;
      HEAP(s, HEAPLEN(s)) = n;
      max_code = n;
      DEPTH(s, n) = 0;
    } else {
      DAD(tree, n) = 0;
    }
  }
  while (HEAPLEN(s) < 2) {
    s32 node = (max_code < 2) ? ++max_code : 0;
    HEAPLEN(s)++;
    HEAP(s, HEAPLEN(s)) = node;
    FREQ(tree, node) = 1;
    DEPTH(s, node) = 0;
    (*(s32 *)(s + 0x16a0))--;
    if (stree) *(s32 *)(s + 0x16a4) -= *(u16 *)(stree + 4 * node + 2);
  }
  *(s32 *)(desc + 4) = max_code;
  for (s32 n = HEAPLEN(s) / 2; n >= 1; n--) ext_630ce0(s, tree, n);
  s32 node = elems;
  do {
    s32 n = HEAP(s, 1);
    HEAP(s, 1) = HEAP(s, HEAPLEN(s));
    HEAPLEN(s)--;
    ext_630ce0(s, tree, 1);
    s32 m = HEAP(s, 1);
    HEAPMAX(s)--;
    HEAP(s, HEAPMAX(s)) = n;
    HEAPMAX(s)--;
    HEAP(s, HEAPMAX(s)) = m;
    FREQ(tree, node) = (u16)(FREQ(tree, m) + FREQ(tree, n));
    u8 dn = DEPTH(s, n), dm = DEPTH(s, m);
    u8 mx = dn < dm ? dm : dn;
    DEPTH(s, node) = (u8)(mx + 1);
    DAD(tree, m) = (u16)node;
    DAD(tree, n) = (u16)node;
    HEAP(s, 1) = node;
    node++;
    ext_630ce0(s, tree, 1);
  } while (HEAPLEN(s) >= 2);
  HEAPMAX(s)--;
  HEAP(s, HEAPMAX(s)) = HEAP(s, 1);
  ext_6309a0(s, desc);
  ext_630bb0(tree, max_code, s + 0xb34);
}
PCREG(6302f0, fn6302f0);
