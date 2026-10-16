// batch1056.cpp - ZFFCameraClass registration helper at 0x5b22a0 (name not in the class map). Camera thread, 2026-10-11.
#include "cam.h"

// 0x5b22a0 (thiscall, no args): the object from the manager's slot 0x138 gets this camera's handle, from the manager's
// slot 0x4c (this, 0x10), through its own slot 0x60 with the descriptor 0x6b007c.
static THISCALL void ZFFCameraClass_Register(u8 *self) {
  u8 *obj = (u8 *)vcall<u32>(SYS9B, 0x138);
  u32 h = vcall<u32>(SYS9B, 0x4c, (void *)self, (u32)0x10);
  vcall<void>(obj, 0x60, (u32)0x6b007c, h);
}
PCREG(5b22a0, ZFFCameraClass_Register);
