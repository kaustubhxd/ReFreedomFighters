// batch6480.cpp - unclaimed-68 batch 48 (claim 48, gap band). Name from the GC name map. The helper 0x4db860 runs as exe code.
#include "ff.h"

extern "C" void THISCALL ext_4db860(u8 *self, u32 a);  // exe helper, one argument, callee cleans
typedef u32(THISCALL *VEng50)(u8 *self, u32 a);

// 0x4a8d90, ZSIGTE::HideAll() (high): thiscall, void. The list starts at the pointer found through the unaligned field this+0x4e, then at +0x50;
// each node follows its next pointer at +0x60. For each node the engine's slot +0x50 gives r; when r differs from the dword at this+0xbb, the exe
// helper 0x4db860 runs on the node with argument 1.
static void THISCALL sigteHideAll(u8 *self) {
  u8 *node = *(u8 **)(self + 0x4e);
  node = *(u8 **)(node + 0x50);
  while (node) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *en = *(u8 **)(eng + 0x9b);
    u32 r = ((VEng50)*(u32 *)(*(u8 **)en + 0x50))(en, (u32)node);
    if (r != *(u32 *)(self + 0xbb)) ext_4db860(node, 1);
    node = *(u8 **)(node + 0x60);
  }
}
PCREG(4a8d90, sigteHideAll);
