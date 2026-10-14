// batch37088.cpp - cascade s6 batch 37088: 0x438910.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// Owner of an entry: the word at entry+8 points at a tagged link; tag 3 means the owner is the link minus 4, tag 1 means it is the pointer stored at link+8 minus 4, anything
// else (or a null link / null pointer) gives no owner.
static u8 *ownerOf(u8 *edi) {
  u8 *c = *(u8 **)(edi + 8);
  if (!c) return 0;
  u32 t = D32(c, 0);
  if (t == 3) return c - 4;
  if (t == 1) {
    u8 *y = *(u8 **)(c + 8);
    return y ? y - 4 : 0;
  }
  return 0;
}

// 0x438910, thiscall(), plain ret: drains the iterator object at +0x15 (slot 0x4c resets it, slot 0x5c yields the next key and sets a "valid" flag). For each key it walks the
// bucket list (10-byte buckets of the owner's table at world+0x1344, head at +4, node: payload pointer at +0, next at +5, flag byte +4) and unlinks every node whose payload is
// this+4 and whose first dword is 0, clearing the node and decrementing the world counter at +0x1208. Afterwards the iterator is destroyed through its slot 0 (arg 1) and cleared.
static void THISCALL fn438910(u8 *self) {
  u8 *it = *(u8 **)(self + 0x15);
  if (it) {
    u32 flag = 0;
    vcall<void>(it, 0x4c, (u32)&flag);
    u32 key = vcall<u32>(*(void **)(self + 0x15), 0x5c, (u32)&flag);
    if (flag) {
      u8 *edi = self + 4;
      do {
        u8 *w = *(u8 **)(ownerOf(edi) + 0x11);
        u8 *bucket = *(u8 **)(w + 0x1344) + key * 10;
        u8 *prev = 0;
        u8 *node = *(u8 **)(bucket + 4);
        while (node) {
          u8 *p = *(u8 **)node;
          if (D32(p, 0) == 0 && p == edi) {
            u8 *next = *(u8 **)(node + 5);
            if (prev) *(u8 **)(prev + 5) = next;
            else *(u8 **)(bucket + 4) = next;
            D32(node, 0) = 0;
            node[4] = 0;
            *(u32 *)(node + 5) = 0;
            u8 *w2 = *(u8 **)(ownerOf(edi) + 0x11);
            D32(w2, 0x1208)--;
            node = next;
          } else {
            prev = node;
            node = *(u8 **)(node + 5);
          }
        }
        key = vcall<u32>(*(void **)(self + 0x15), 0x5c, (u32)&flag);
      } while (flag);
    }
  }
  it = *(u8 **)(self + 0x15);
  if (it) vcall<void>(it, 0x0, 1u);
  *(u32 *)(self + 0x15) = 0;
}
PCREG(438910, fn438910);
