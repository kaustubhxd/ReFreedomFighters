// batch6190.cpp - unclaimed-68 batch 19 (claim 18, gap band). Name from the GC name map (low confidence).
#include "ff.h"

// A command handler in a record (thiscall, one argument; the callee cleans its 4 bytes).
typedef u32(THISCALL *CmdFn)(u8 *self, u32 arg);

// 0x4a9e20, CFFCoverList::Command(unsigned short, void*) (low): thiscall, ret 8. Searches the 10-byte records at this+0x48 (the
// key word at +4, the count at this+0x4c) for the command word; on a match returns the result of the handler at record+6.
static u32 THISCALL coverListCommand(u8 *self, u32 cmd, u32 arg) {
  s32 n = *(s32 *)(self + 0x4c);
  if (n > 0) {
    u8 *base = *(u8 **)(self + 0x48);
    u32 i = 0;
    u8 *p = base + 4;
    do {
      if (*(u16 *)p == (u16)cmd) {
        return ((CmdFn)*(u32 *)(base + i * 10 + 6))(self, arg);
      }
      i++;
      p += 10;
    } while ((s32)i < n);
  }
  return 0;
}
PCREG(4a9e20, coverListCommand);
