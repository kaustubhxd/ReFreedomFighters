// batch1025.cpp - unclaimed-07 batch 25 (slice 6, small leaf): ZTreeGroup::MoveGlobalBound (high, 0x443aa0).
#include "ff.h"

// 0x443aa0, ZTreeGroup::MoveGlobalBound(eGlobalTreeType, ZBaseGeom*, COctreeObj*, float*, float*) (high), thiscall,
// ret 20. The object is the table entry at this+0x5d + 4*type; its slot +8 gets the last three arguments (no return).
// The second argument (ZBaseGeom*) is not used.
static void THISCALL treeGroupMoveGlobalBound(u8 *self, u32 type, u32 geom, u32 a3, u32 a4, u32 a5) {
  (void)geom;
  u8 *obj = *(u8 **)(self + 0x5d + 4 * type);
  vcall<void>(obj, 8, a3, a4, a5);
}
PCREG(443aa0, treeGroupMoveGlobalBound);
