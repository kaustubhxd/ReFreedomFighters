// batch913.cpp - unclaimed-09 batch 5: ZActionReloadItem::Load(ZLoadGame&) (docs/20-unclaimed-09.md, claim 5).
// thiscall, one stack argument (the ZLoadGame reference, a pointer), ret 4. The three loader calls and the item's own
// slot +0x2c go through vtables (unverified callees, stubbed in the spec).
#include "ff.h"

typedef void(THISCALL *LoadSlotPtr)(u8 *self, u8 *out);
typedef u32(THISCALL *ItemSlot2c)(u8 *self, u32 a);

static u32 vtSlot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x486dc0, ZActionReloadItem::Load(ZLoadGame&) (high): calls ld.vt[0x50](this+0x30); reads a flag byte through
// ld.vt[0x68]; when the flag is set reads a dword through ld.vt[0x40] and stores this.vt[0x2c](dword) at this+0x2c.
static void THISCALL reloadItemLoad(u8 *self, u8 *ld) {
  u8 flag = 0;
  u32 n = 0;
  ((LoadSlotPtr)vtSlot(ld, 0x50))(ld, self + 0x30);
  ((LoadSlotPtr)vtSlot(ld, 0x68))(ld, &flag);
  if (flag) {
    ((LoadSlotPtr)vtSlot(ld, 0x40))(ld, (u8 *)&n);
    *(u32 *)(self + 0x2c) = ((ItemSlot2c)vtSlot(self, 0x2c))(self, n);
  }
}
PCREG(486dc0, reloadItemLoad);
