// batch1032.cpp - unclaimed-04 batch 32 (docs/20-unclaimed-04.md): 0x64a670, thiscall, no arguments.
// Drains the list headed at this+0xc: node = head, item = this+4, head = node+8, item->vt[0xc](node). Then clears +8, +0x10.
#include "ff.h"

typedef void(THISCALL *vfn1_t)(void *self, u32 a);

// 0x64a670
static void THISCALL unk64a670DrainList(u8 *self) {
  if (*(u32 *)(self + 0xc) != 0) {
    do {
      u8 *node = *(u8 **)(self + 0xc);
      u8 *item = *(u8 **)(self + 4);
      *(u32 *)(self + 0xc) = *(u32 *)(node + 8);
      ((vfn1_t)(*(u32 *)(*(u32 *)item + 0xc)))(item, (u32)node);
    } while (*(u32 *)(self + 0xc) != 0);
  }
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x10) = 0;
}
PCREG(64a670, unk64a670DrainList);
