// batch79.cpp - tele list and kill box, inline session batch 79: CTelePortList::FrameUpdate (0x4b8360) and
// ZKillBox::Init (0x5b1cb0). TelePort(int) (0x4b84b0) is exe code.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8(THISCALL *vcallBU)(void *self, u32 a);
typedef u32(THISCALL *vcallUUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *startFn)(void *self, u32 *valid, u32 bx);  // slot 0x4c: two stack args, the second is ebx
typedef u32(THISCALL *nextFn)(void *self, u32 *valid);            // slot 0x5c
typedef void(THISCALL *dispFn)(void *self, u32 handle, u32 id, u32 msg);

extern "C" void THISCALL ext_4b84b0(u8 *self, s32 n);  // CTelePortList::TelePort(int)

// 0x4b8360 CTelePortList::FrameUpdate(), thiscall, ret 0: when the render manager's slot 0xe8 says so for the
// list's handle at +0x4c, teleport by -1 when slot 0xe4(0x10) is true, else by 1.
static void THISCALL tpFrameUpdate(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  if (!((vcallBU)VT(rm, 0xe8))(rm, *(u32 *)(self + 0x4c)))
    return;
  if (((vcallBU)VT(rm, 0xe4))(rm, 0x10))
    ext_4b84b0(self, -1);
  else
    ext_4b84b0(self, 1);
}
PCREG(4b8360, tpFrameUpdate);

// 0x5b1cb0 ZKillBox::Init(), thiscall, ret 0: +0x4a = render manager's +0x9b object's +0xadc object's slot 0x25c
// (0x685f44, 0).
static void THISCALL kbInit(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u8 *obj = *(u8 **)(o + 0xadc);
  *(u32 *)(self + 0x4a) = ((vcallUUU)VT(obj, 0x25c))(obj, 0x685f44u, 0);
}
PCREG(5b1cb0, kbInit);

