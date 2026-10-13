// batch1315.cpp - inventory thread (inline-inventory, 2026-10-11): ZItem::PlaySound(unsigned int) (0x46ffd0).
// The sound is played at the item's position: the owner group (slot 0x2f4, twice when the first answer is set), the
// position vectors come from slots 0x2c8 and 0x94, the sound id is the reference id of slot 0x2f4's answer, and the
// group call ZGROUP::AddSound3d (0x43ec00) takes six stack arguments.
#include "ff.h"

extern "C" u32 THISCALL ext_43ec00(u8 *group, float *pos, float *vel, u32 sound, u32 zero1, u32 id, u32 zero2);
static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL itemPlaySound(u8 *self, u32 sound) {
  if (!sound) return;
  u32 v10[4] = {0, 0, 0, 0};    // [ebp-0x10] velocity out
  u32 v34[4] = {0, 0, 0, 0};    // [ebp-0x34] position out
  u8 *ob;
  if (vcall<u32>(self, 0x2f4)) {
    u32 g = vcall<u32>(self, 0x2f4);
    ob = (u8 *)vcall<u32>((u8 *)g, 0x20);
  } else {
    ob = self;
  }
  vcall<u32>(self, 0x2c8, v34, v10);
  vcall<u32>(ob, 0x94, v34, v10);
  u32 x = vcall<u32>(self, 0x2f4);
  u32 id = vcall<u32>(refTable(), 0x4c, x);
  ext_43ec00(ob, (float *)v34, (float *)v10, sound, 0u, id, 0u);
}
PCREG(46ffd0, itemPlaySound);
