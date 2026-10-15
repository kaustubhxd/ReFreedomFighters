// batch67522.cpp - cascade s6 batch 67522: 0x4b4040.
#include "ff.h"

extern "C" void THISCALL ext_4b6b90(u8 *self, u8 *entry);              // ret 4
extern "C" void THISCALL ext_4b6e00(u8 *self, u32 handle, u32 flag);   // ret 8

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4b4040, thiscall(list, flag) ret 8: releases the references of every key the iterator at list+0x18 yields (slot 0x4c starts, 0x5c yields with an out count). A key found in the first
// map (embedded at +0x10e, lookup slot 0x2c) loses one reference; at zero it is torn down (0x4b6b90 when the flag is set) and erased (slot 0x3c). Otherwise the second container
// (embedded at +0xf2, walked with slots 0x4c / 0x64) is searched for the node with that key (+0xc); a node dropping to zero references releases its table object (slot 0x54 of the table
// object -> 0x4b6e00 with the flag) and is erased (slot 0x3c).
static void THISCALL fn4b4040(u8 *self, u8 *list, u32 flag) {
  u8 *it = *(u8 **)(list + 0x18);
  if (!it) return;
  u32 cnt;
  vcall<void>(it, 0x4c, (u32)&cnt);
  u32 key = vcall<u32>(it, 0x5c, (u32)&cnt);
  if (cnt == 0) return;
  do {
    u8 *m1 = self + 0x10e;
    u8 *entry = (u8 *)vcall<u32>(m1, 0x2c, key);
    bool done = false;
    if (entry) {
      D32(entry, 8)--;
      if (D32(entry, 8) == 0) {
        if ((u8)flag) ext_4b6b90(self, entry);
        vcall<void>(m1, 0x3c, D32(entry, 0));
        done = true;
      }
    }
    if (!done) {
      u8 *m2 = self + 0xf2;
      u32 cnt2;
      vcall<void>(m2, 0x4c, (u32)&cnt2);
      u8 *node = (u8 *)vcall<u32>(m2, 0x64, (u32)&cnt2);
      while (node) {
        if (D32(node, 0xc) == key) {
          D32(node, 8)--;
          if (D32(node, 8) == 0) {
            u32 h = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x54, D32(node, 0));
            if (h) ext_4b6e00(self, h, flag);
            vcall<void>(m2, 0x3c, D32(node, 0));
          }
          break;
        }
        node = (u8 *)vcall<u32>(m2, 0x64, (u32)&cnt2);
      }
    }
    key = vcall<u32>(it, 0x5c, (u32)&cnt);
  } while (cnt);
}
PCREG(4b4040, fn4b4040);
