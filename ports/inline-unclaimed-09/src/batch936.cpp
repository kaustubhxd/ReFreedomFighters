// batch936.cpp - unclaimed-09 batch 28: ZOnScreenDisplay::DrawBufferViewUpdate (core list; docs/20-unclaimed-09.md, claim 30).
// thiscall, two stack arguments, ret 8, returns false in al. The constructor (0x4de7a0) and the draw helper (0x5a76c0) are
// GUESS recording stubs in the spec (the struct is compared by contents).
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(u8 *self);                          // constructor on the local struct (stubbed)
extern "C" u32 THISCALL ext_5a76c0(u8 *self, u32 a0, u32 a1, u8 *p, u32 *q); // draw helper (stubbed); result unused

// 0x5a7640, ZOnScreenDisplay::DrawBufferViewUpdate (list name; GUESS on the arguments): constructs a 0x34-byte local
// struct, zeroes a dword, passes both to 0x5a76c0 with the two arguments, and returns false.
static u8 THISCALL drawBufferViewUpdate(u8 *self, u32 a0, u32 a1) {
  // The struct is 0x30 bytes: the frame's last four bytes hold the stack cookie at ebp-4. The output dword ebp-0x10 is offset
  // 0x24 of it, ebp-0xc is 0x28 and ebp-8 is 0x2c.
  u8 buf[0x30];
  ext_4de7a0(buf);
  *(u32 *)(buf + 0x2c) = 0;
  *(u32 *)(buf + 0x28) = 0;
  *(u32 *)(buf + 0x24) = 0;
  ext_5a76c0(self, a0, a1, buf, (u32 *)(buf + 0x24));
  return 0;
}
PCREG(5a7640, drawBufferViewUpdate);
