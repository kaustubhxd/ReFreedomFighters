// batch1038.cpp - unclaimed-04 batch 38 (docs/20-unclaimed-04.md): 0x654cb0, thiscall, three stack arguments (ret 0xc).
#include "ff.h"

typedef void(THISCALL *vt3_t)(void *self, u32 a, u32 b, u32 c);

static inline u32 vslot(void *o, u32 off) {
  return *(u32 *)(*(u32 *)o + off);
}

// 0x654cb0: this->vt[0x230](a1, a2, a3), then set bit 0x80 in four bytes of the global object at 0x70039c.
static void THISCALL unk654cb0(u8 *self, u32 a1, u32 a2, u32 a3) {
  ((vt3_t)vslot(self, 0x230))(self, a1, a2, a3);
  u8 *g = *(u8 **)0x70039c;
  g[0xa10] |= 0x80;
  g = *(u8 **)0x70039c;
  g[0xad8] |= 0x80;
  g = *(u8 **)0x70039c;
  g[0x13fc] |= 0x80;
  g = *(u8 **)0x70039c;
  g[0x13f7] |= 0x80;
}
PCREG(654cb0, unk654cb0);
