// batch912.cpp - unclaimed-09 batch 4: ZActivateBinoculars::Command (docs/20-unclaimed-09.md, claim 4).
// thiscall, two stack arguments (cmd, obj), ret 8. The virtual call goes through obj's vtable slot +0x88 (stubbed in
// the spec, unverified callee). The original passes the address of its own cmd argument; the port passes &cmd too.
#include "ff.h"

typedef void(THISCALL *BinocSlot88)(u8 *self, u32 a, const u16 *cmd);

// 0x4c9300, ZActivateBinoculars::Command(unsigned short, void*) (high): compares the low word of cmd with the word at
// this+0x48; when they match and obj is not null, calls obj's vtable slot +0x88 with (0x68884c, &cmd). Returns 0.
static u32 THISCALL binocCommand(u8 *self, u32 cmd, u8 *obj) {
  if ((u16)cmd == *(u16 *)(self + 0x48) && obj) {
    u32 vt = *(u32 *)obj;
    BinocSlot88 fn = (BinocSlot88)(*(u32 *)(vt + 0x88));
    fn(obj, 0x68884c, (const u16 *)&cmd);
  }
  return 0;
}
PCREG(4c9300, binocCommand);
