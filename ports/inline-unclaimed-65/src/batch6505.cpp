// batch6505.cpp - unclaimed-65: batch 5 (docs/20-unclaimed-65.md, claim 5). No arguments (ret). The render object's slot +0x114
// (RegisterZMsg) takes four stack arguments and the callee pops them (ret 0x10), so the port passes them with no cleanup.
#include "ff.h"

typedef u32(THISCALL *RegZMsgFn)(u8 *self, u32 name, u32 zero, u32 file, u32 line);

static u32 registerZMsg(u32 name, u32 file, u32 line) {
  u8 *rr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((RegZMsgFn)(*(const u32 *)(*(const u32 *)rr + 0x114)))(rr, name, 0, file, line);
}

// 0x4c8fe0, ZShotActivate::RegisterMessages() (residue 18): four registrations; the low word of each result is stored at
// 0x70036c, 0x700370, 0x700374 and 0x700378 (in order). The names are 0x692ae4, 0x68a87c and 0x694df4, 0x694e08; the file is 0x694dc4.
static void THISCALL shotActivateRegisterMessages(u8 *self) {
  (void)self;
  G(u16, 0x70036c) = (u16)registerZMsg(0x692ae4, 0x694dc4, 0x50);
  G(u16, 0x700370) = (u16)registerZMsg(0x68a87c, 0x694dc4, 0x51);
  G(u16, 0x700374) = (u16)registerZMsg(0x694df4, 0x694dc4, 0x52);
  G(u16, 0x700378) = (u16)registerZMsg(0x694e08, 0x694dc4, 0x53);
}
PCREG(4c8fe0, shotActivateRegisterMessages);
