// batch37078.cpp - cascade s6 batch 37078: 0x63c920.
#include "ff.h"

extern "C" void *__attribute__((cdecl)) ext_634d10(void *dst, u32 v, u32 n);   // memset thunk
typedef void (*hook_t)();

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x63c920, thiscall(out, unused) ret 8: self+8 heads a circular list of nodes (+1 byte tag, +2 start index, +8 next, an array of 0x18-byte elements from +0x10 whose first word is the
// next index in a chain, 0xffff ends it). Each node gets its position as its tag, the elements reachable from every node's start index are flagged in a zeroed matrix
// (nodes x slot 0x28 count), and the addresses of all unflagged elements are written to out. The tags are then restored to the first node's original tag.
static void THISCALL fn63c920(u8 *self, u32 *out, u32 unused) {
  u8 buf[0x10000];
  u8 *head = *(u8 **)(self + 8);
  if (!head) return;
  u8 saved = head[1];
  u8 bl = 0;
  u8 *node = head;
  do {
    if (bl == 0xff) {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    node[1] = bl;
    bl++;
    node = *(u8 **)(node + 8);
  } while (node != *(u8 **)(self + 8) && node);
  u32 n = vcall<u32>(self, 0x28);
  ext_634d10(buf, 0, (u32)bl * n);
  u8 *cur = *(u8 **)(self + 8);
  if (cur) {
    do {
      u32 dx = *(u16 *)(cur + 2);
      if (dx != 0xffff) {
        u8 *row = buf + (u32)cur[1] * n;
        do {
          row[dx] = 1;
          dx = *(u16 *)(cur + dx * 0x18 + 0x10);
        } while (dx != 0xffff);
      }
      cur = *(u8 **)(cur + 8);
    } while (cur != *(u8 **)(self + 8) && cur);
  }
  u32 o = 0, idx = 0;
  cur = *(u8 **)(self + 8);
  if (cur) {
    do {
      u8 *el = cur + 0x10;
      for (u32 k = 0; k < n; k++) {
        if (buf[idx++] == 0) out[o++] = (u32)el;
        el += 0x18;
      }
      cur = *(u8 **)(cur + 8);
    } while (cur != *(u8 **)(self + 8) && cur);
  }
  cur = *(u8 **)(self + 8);
  if (cur) {
    do {
      cur[1] = saved;
      cur = *(u8 **)(cur + 8);
    } while (cur != *(u8 **)(self + 8) && cur);
  }
}
PCREG(63c920, fn63c920);
