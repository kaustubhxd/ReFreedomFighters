// batch1903.cpp - unclaimed-66 batch 3 (residue 5): CEnemyFlag::~CEnemyFlag() (scalar deleting form, dtor). Same template as
// CHitpointControl (area 08 batch 9, 0x5817b0): this+0x44 = 0, this+0x30 = 0, vtable 0x686874, then the engine db's vtable
// +0x34 with this as the argument. The flag tail (bit 0 with bit 2 clear calls *0x7003b0) is NOT run: the spec keeps bit 0
// clear, a documented gap (docs/20-unclaimed-66.md). Returns this.
#include "ff.h"

// 0x5c0e90, CEnemyFlag::~CEnemyFlag().
static u8 *THISCALL enemyFlagDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *sys = *(u8 **)0x70039c;
  u8 *db = *(u8 **)(sys + 0x9b);
  vcall<void>(db, 0x34, (void *)self);
  if (flags & 1) {
    if (!(flags & 4)) {
      void (*hook)() = *(void (**)())0x7003b0;
      if (hook) hook();   // original: a null hook traps (int3); the spec never sets it to null
    }
  }
  return self;
}
PCREG(5c0e90, enemyFlagDtor);
