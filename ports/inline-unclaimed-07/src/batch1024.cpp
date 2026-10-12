// batch1024.cpp - unclaimed-07 batch 24 (slice 6, small leaf): ZTreeGroup::FreeDynamicTrees() (high, 0x442f60).
#include "ff.h"

// 0x4e3f00: thiscall, no arguments, ECX = the tree object (original code, hooked in the spec).
extern "C" void THISCALL ext_4e3f00(u8 *tree);
// 0x634273: operator delete (cdecl, pointer and size; hooked in the spec).
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x442f60, ZTreeGroup::FreeDynamicTrees() (high), thiscall, plain ret: when the pointer at this+0x71 is non-null, calls
// 0x4e3f00 on it, deletes it with 0x634273(ptr, 0x2d), and sets this+0x71 to 0.
static void THISCALL treeGroupFreeDynamicTrees(u8 *self) {
  u8 *t = *(u8 **)(self + 0x71);
  if (t) {
    ext_4e3f00(t);
    ext_634273(t, 0x2d);
    *(u32 *)(self + 0x71) = 0;
  }
}
PCREG(442f60, treeGroupFreeDynamicTrees);
