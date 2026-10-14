// batch934.cpp - unclaimed-09 batch 26: ZPlayer::CopyDataBlock(DBLK*) (core list; docs/20-unclaimed-09.md, claim 28).
// thiscall, one stack argument (the block), ret 4. The exe calls and the ZPlayer vtable calls are unverified callees.
#include "ff.h"

extern "C" void THISCALL ext_473370(u8 *self, u8 *d);           // base copy, one argument (hooked in the spec)
extern "C" u8 THISCALL ext_4e1600(u8 *d);                       // returns al (hooked)
extern "C" void THISCALL ext_4e12e0(u8 *d, u32 p, u32 n);       // two arguments (hooked)
extern "C" void THISCALL ext_4e1b30(u8 *d);                     // (hooked)
extern "C" void THISCALL ext_4dc630(u8 *obj, u32 a, u32 b);     // two arguments (hooked)

typedef u8 *(THISCALL *GetObj)(u8 *self);
typedef void(THISCALL *NoArg)(u8 *self);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x482800, ZPlayer::CopyDataBlock(DBLK*) (list name): base copy; clears the dword at this+0x60e; when the low byte of
// 0x4e1600(d) is 0xb, calls 0x4e12e0(d, &this+0x60e, 1); then 0x4e1b30(d); 0x4dc630(this+8, 0, 1); this.vt[0x40]();
// o = this.vt[0x20](); 0x4dc630(o+8, 0, 1).
static void THISCALL playerCopyDataBlock(u8 *self, u8 *d) {
  ext_473370(self, d);
  *(u32 *)(self + 0x60e) = 0;
  if (ext_4e1600(d) == 0xb) ext_4e12e0(d, (u32)(self + 0x60e), 1);
  ext_4e1b30(d);
  ext_4dc630(*(u8 **)(self + 8), 0, 1);
  ((NoArg)slot(self, 0x40))(self);
  u8 *o = ((GetObj)slot(self, 0x20))(self);
  ext_4dc630(*(u8 **)(o + 8), 0, 1);
}
PCREG(482800, playerCopyDataBlock);
