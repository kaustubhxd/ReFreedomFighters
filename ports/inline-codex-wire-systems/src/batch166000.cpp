#include "ff.h"
// the vtable slot +0x12c of the object at this+0x44 takes (dword +0x4c, word +0x4a zero-extended, arg2) in that stack order
typedef u32(THISCALL *ObjectCommandFn)(u8 *self, u32 a, u32 b, void *c);

// 0x4b85c0, ZRelayMessage::Command(unsigned short, void*) (high): when the word argument equals the word at +0x48, calls
// virtual slot +0x12c of the object at +0x44. Always returns 0.
static u32 THISCALL relayMessageCommand(u8 *self, u32 cmd, void *arg) {
  if ((u16)cmd == *(const u16 *)(self + 0x48)) {
    u8 *target = *(u8 **)(self + 0x44);
    const u32 vtbl = *(const u32 *)target;
    ObjectCommandFn fn = (ObjectCommandFn)(*(const u32 *)(vtbl + 0x12c));
    fn(target, *(const u32 *)(self + 0x4c), *(const u16 *)(self + 0x4a), arg);
  }
  return 0;
}
PCREG(4b85c0, relayMessageCommand);

