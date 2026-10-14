// batch35050.cpp - cascade s5 batch 35050: 0x4fc9e0 (GUESS append a node to a linked list for every entry of the source list).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);   // cdecl alloc
typedef void(THISCALL *v1_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);

// 0x4fc9e0, thiscall, no arguments. L = [[this+0x44]+0x18] (null: nothing; reloaded before each use). L slot 0x4c(&it); for each entry e returned by L slot 0x5c(&it) while it[0] != 0: a 0x15-byte
// node n (0x41e290) when the allocation succeeds: n[0x14] = 0, n[0x10] = this, n[0] = e, n[4] = 0, n[8] = tail ([this+0x4c]), n[0xc] = 0; tail[0xc] = n (or head [this+0x48] = n when empty); [this+0x4c] = n.
static void THISCALL fn4fc9e0(u8 *self) {
  u32 it[4];
  u8 *L = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  if (!L) return;
  (*(v1_t **)L)[0x4c / 4](L, it);
  L = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  u32 e = (*(g1p_t **)L)[0x5c / 4](L, it);
  if (it[0] == 0) return;
  do {
    u8 *n = ext_41e290(0x15);
    if (n) {
      n[0x14] = 0;
      *(u8 **)(n + 0x10) = self;
      *(u32 *)n = e;
      *(u32 *)(n + 4) = 0;
      u8 *tail = *(u8 **)(self + 0x4c);
      *(u8 **)(n + 8) = tail;
      *(u32 *)(n + 0xc) = 0;
      if (tail) *(u8 **)(tail + 0xc) = n;
      else *(u8 **)(self + 0x48) = n;
      *(u8 **)(self + 0x4c) = n;
    }
    L = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
    e = (*(g1p_t **)L)[0x5c / 4](L, it);
  } while (it[0] != 0);
}
PCREG(4fc9e0, fn4fc9e0);
