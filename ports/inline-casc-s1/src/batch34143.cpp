// batch34143.cpp - cascade tier E, batch 34143: 0x5f90a0 (sibling of 0x5f9010), 0x5fbf90 (find a value in a tree by key address).
#include "ff.h"

extern "C" void ext_42ab62(u32 a);   // cdecl
typedef void (*hook_t)();

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5f90a0, thiscall plain: as 0x5f9010 but the setup argument is the unaligned dword at this+0x82.
static u32 THISCALL fn5f90a0(u8 *self) {
  u8 *emb = self + 0xaca;
  u8 *s = vcall<u8 *>(emb, 0x0, 0x67a14cu, 0u);
  vcall<void>(s, 0x30, rd32(self + 0x82));
  if (*(u32 *)(self + 0x3c) >= *(u32 *)(self + 0x38)) {
    ext_42ab62(0x6b89b4);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 size = *(u32 *)(self + 0x3c);
  u8 *slot = *(u8 **)(self + 0x34) + size * 8;
  *(u32 *)(self + 0x3c) = size + 1;
  u8 k = slot[4];
  if (k == 0 || k == 4) {
    if (k == 4) vcall<void>(*(u8 **)slot, 0x28);
    *(u32 *)slot = vcall<u32>(s, 0x24);
    slot[4] = 4;
  }
  return vcall<u32>(s, 0x28);
}
PCREG(5f90a0, fn5f90a0);

// 0x5fbf90, thiscall(key) ret 4: tree with header h = [this+1] (all node fields unaligned: parent +1, left +5, right +9, payload pointer +0x19), walked in order from the leftmost node [h+5] until the header is reached again.
// Returns [payload + 0x172] for the first node whose payload + 0x3c equals key; when none matches the assert hook [0x7003b0] runs (int3 when null) and 0 is returned.
static u32 THISCALL fn5fbf90(u8 *self, u32 key) {
  u8 *h = (u8 *)rd32(self + 1);
  u8 *n = (u8 *)rd32(h + 5);
  while (n != h) {
    u8 *pl = (u8 *)rd32(n + 0x19);
    if (key == (u32)pl + 0x3c) return rd32(pl + 0x172);
    u8 *c = (u8 *)rd32(n + 9);
    if (c) {
      n = c;
      c = (u8 *)rd32(n + 5);
      while (c) {
        n = c;
        c = (u8 *)rd32(n + 5);
      }
    } else {
      c = (u8 *)rd32(n + 1);
      if (n == (u8 *)rd32(c + 9)) {
        do {
          n = c;
          c = (u8 *)rd32(c + 1);
        } while (n == (u8 *)rd32(c + 9));
      }
      if ((u8 *)rd32(n + 9) != c) n = c;
    }
  }
  hook_t hk = G(hook_t, 0x7003b0);
  if (!hk) __asm__ volatile("int3");
  hk();
  return 0;
}
PCREG(5fbf90, fn5fbf90);
