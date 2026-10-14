// batch35093.cpp - cascade s5 batch 35093: 0x4fd800 (GUESS unlink the node with a given key from a doubly linked list and free it; companion of 0x4fc9e0).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // CRT free-style, cdecl
typedef void(THISCALL *v1_t)(void *, u32);

// 0x4fd800, thiscall(key) ret 4. Nodes (0x15 bytes): [0] key, [8] prev, [0xc] next, [0x10] owner; the list head is [this+0x48] and the tail [this+0x4c] (kept in the owner). Nothing when the list is empty or no node has the key.
// Found n: [this+0x44]'s [+0x18] slot 0x3c(key); owner[0x50] == n makes owner[0x50] = next; prev gets next as its next (or the owner's head [+0x48] = next); next gets prev as its prev, or the owner's
// tail [+0x4c] = prev; free(n, 0x15).
static void THISCALL fn4fd800(u8 *self, u32 key) {
  u8 *n = *(u8 **)(self + 0x48);
  if (!n) return;
  while (*(u32 *)n != key) {
    n = *(u8 **)(n + 0xc);
    if (!n) return;
  }
  u8 *obj = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  (*(v1_t **)obj)[0x3c / 4](obj, key);
  u8 *owner = *(u8 **)(n + 0x10);
  if (*(u8 **)(owner + 0x50) == n) *(u8 **)(owner + 0x50) = *(u8 **)(n + 0xc);
  u8 *prev = *(u8 **)(n + 8);
  u8 *next = *(u8 **)(n + 0xc);
  if (prev) *(u8 **)(prev + 0xc) = next;
  else *(u8 **)(*(u8 **)(n + 0x10) + 0x48) = next;
  next = *(u8 **)(n + 0xc);
  prev = *(u8 **)(n + 8);
  if (next) {
    *(u8 **)(next + 8) = prev;
    ext_634273(n, 0x15);
    return;
  }
  *(u8 **)(*(u8 **)(n + 0x10) + 0x4c) = prev;
  ext_634273(n, 0x15);
}
PCREG(4fd800, fn4fd800);
