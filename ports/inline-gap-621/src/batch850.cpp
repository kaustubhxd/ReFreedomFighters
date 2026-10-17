// batch850.cpp - gap band entry release by kind (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void THISCALL ext_63ee70(u8 *self, u32 id);      // hooked (GUESS): ret 4
extern "C" void THISCALL ext_63faa0(u8 *self, u8 *ent);     // hooked (GUESS): ret 4 (verified separately in batch 845)
extern "C" void THISCALL ext_658fd0(u8 *ent, u32 arg);      // hooked (GUESS): ret 4
typedef void (THISCALL *vm0_t)(u8 *self);
typedef void (*cb_t)();

// 0x63fb40: thiscall(a) ret 4 - releases the entry a refers to by its u16 id (a[0x5a], 0 = none): looks up ent = this[0x68][(id & 0xfff)*4], runs
// 0x63ee70(id), clears a[0x3c] bit 0x1000 and a[0x5a], then by ent[4] (1..4): 1 -> vt[0x60](), ent[0xc] = 0; 2 -> ent[0x3c] = 0;
// 3 -> 0x63faa0(ent), and with ent[0x3c] bit 0x10 and ent[0x44] set 0x658fd0(ent, 0), then ent[0x38] = 0; 4 -> ent[0x38] = 0.
// Any other kind calls the assert hook [0x7003b0] (int3 when unset: the port traps) and returns.
static void THISCALL releaseEntry_63fb40(u8 *self, u8 *a) {
  u32 id = *(u16 *)(a + 0x5a);
  if (!id) return;
  u8 *ent = *(u8 **)(*(u8 **)(self + 0x68) + (id & 0xfff) * 4);
  ext_63ee70(self, id);
  *(u32 *)(a + 0x3c) &= 0xffffefffu;
  *(u16 *)(a + 0x5a) = 0;
  u32 kind = (u32)ent[4] - 1;
  switch (kind) {
    case 0:
      (*(vm0_t *)(*(u8 **)self + 0x60))(self);
      *(u32 *)(ent + 0xc) = 0;
      break;
    case 1:
      *(u32 *)(ent + 0x3c) = 0;
      break;
    case 2:
      ext_63faa0(self, ent);
      if ((*(u32 *)(ent + 0x3c) & 0x10) && *(u32 *)(ent + 0x44) != 0) ext_658fd0(ent, 0);
      *(u32 *)(ent + 0x38) = 0;
      break;
    case 3:
      *(u32 *)(ent + 0x38) = 0;
      break;
    default: {
      cb_t cb = G(cb_t, 0x7003b0);
      if (!cb) __builtin_trap();
      cb();
    }
  }
}
PCREG(63fb40, releaseEntry_63fb40);
