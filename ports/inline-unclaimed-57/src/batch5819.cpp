// batch5819.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 119: 0x5c1640 (CEnemyFlag::CopyEventDataBlock(DBREAD&), vtable forwarder), thiscall,
// one stack argument (the DBREAD reference, ret 4). The original is push ebp; mov ebp,esp; pop ebp; jmp 0x5c1dc0: a tail jump, so the callee receives the
// same stack argument and its ret 4 returns to our caller. The port makes the same call and returns. The callee (area 49's batch 605) is hooked in the spec.
#include "ff.h"

extern "C" void THISCALL ext_5c1dc0(u8 *self, u8 *db);  // area 49's batch 605 function, original code (hooked in the spec)

// 0x5c1640, thiscall, one stack argument (GUESS name)
static void THISCALL unnamed5c1640(u8 *self, u8 *db) {
  ext_5c1dc0(self, db);
}
PCREG(5c1640, unnamed5c1640);
