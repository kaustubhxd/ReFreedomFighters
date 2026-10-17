// batch6511.cpp - unclaimed-65: batch 11 (docs/20-unclaimed-65.md, claim 12). Thiscall, four stack arguments (ret 0x10).
#include "ff.h"

typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);

// 0x47ac90, ZActor::ReplaceMove(unsigned int, unsigned int, unsigned int, unsigned int) (residue 17). See docs/20-unclaimed-65.md.
static u32 THISCALL actorReplaceMove(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u32 esi = c;
  u8 *block = *(u8 **)(self + 0x49a + a * 4);
  if (block) {
    u8 *entry = block + b * 8 + 4;
    if (*(const u32 *)entry != 0) {
      if (*(const u32 *)entry == c && *(const u32 *)(entry + 4) == d) esi = 0;
    }
  }
  u8 *found = nullptr;
  for (u32 i = 0; i < 16; i++) {
    u8 *ent = self + 0x4b2 + 16 * i;
    if (*(const u32 *)ent == a && *(const u32 *)(ent + 4) == b) {
      found = ent;
      break;
    }
  }
  if (!found) {
    for (u32 i = 0; i < 16; i++) {
      u8 *ent = self + 0x4b2 + 16 * i;
      if (*(const u32 *)(ent + 8) == 0) {
        found = ent;
        *(u32 *)ent = a;
        *(u32 *)(ent + 4) = b;
        break;
      }
    }
  }
  *(u32 *)(found + 8) = esi;
  *(u32 *)(found + 0xc) = d;
  return ((F2)(*(const u32 *)(*(const u32 *)self + 0x5ac)))(self, *(const u32 *)(self + 0x4ae), 1);
}
PCREG(47ac90, actorReplaceMove);
