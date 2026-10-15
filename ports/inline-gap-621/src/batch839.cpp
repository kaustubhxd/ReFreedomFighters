// batch839.cpp - gap band small functions with hooked callees (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 THISCALL ext_658d30(u8 *ent);                    // hooked (GUESS): returns nonzero when the entry is live
extern "C" float THISCALL ext_63eb90(u8 *self, u32 idx);        // hooked (GUESS): float in st0, ret 4

typedef u8 *(THISCALL *vp_t)(u8 *self);

// 0x640c10: thiscall(a) ret 4 - true when the object's id (u16 a[0x5a], 0 = none) is set, a[0x3c] bit 0x2000 is clear and the
// value read for it does not exceed 1000.0f: from the entry's owner (a[0x54]->vt[0x24c]()[0x271]) when 0x658d30(entry) is
// nonzero, else from 0x63eb90(this, id). NaN counts as not exceeding.
static u8 THISCALL belowLimit_640c10(u8 *self, u8 *a) {
  u32 id = *(u16 *)(a + 0x5a);
  if (!id) return 0;
  if (*(u32 *)(a + 0x3c) & 0x2000) return 0;
  u8 *ent = *(u8 **)(*(u8 **)(self + 0x68) + (id & 0xfff) * 4);
  float f;
  if (ext_658d30(ent)) {
    u8 *obj = *(u8 **)(a + 0x54);
    u8 *v = (*(vp_t *)(*(u8 **)obj + 0x24c))(obj);
    f = *(float *)(v + 0x271);
  } else {
    f = ext_63eb90(self, id);
  }
  return !(f > 1000.0f);
}
PCREG(640c10, belowLimit_640c10);
