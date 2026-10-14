// u18_15.cpp - core-todo residue 17 (unclaimed-18 thread): ZRelayMessageList::CopyData (0x4b8950).
#include "ff.h"

// 0x4b8950, ZRelayMessageList::CopyData(ZEventBase*) (GC map high). thiscall, one stack arg (ret 4). Copies two words
// (+0x48, +0x4a) and the dwords at +0x50 and +0x54 from the event. When the event's object at +0x4c is set: its slot 0x4c
// is called with a flag (a local), its slot 0x5c gives a value with the flag; while the flag is non-zero, this object's
// slot 4 is called with the value and slot 0x5c of the event's object is called again.
// Note: the exe's local is uninitialised before the first call; it is set to 0 here, and the callee always writes it.
static void THISCALL relayMessageListCopyData(u8 *self, u8 *ev) {
  u32 flag = 0;
  *(u16 *)(self + 0x48) = *(u16 *)(ev + 0x48);
  *(u16 *)(self + 0x4a) = *(u16 *)(ev + 0x4a);
  void *obj = *(void **)(ev + 0x4c);
  if (obj) {
    vcall<void>(obj, 0x4c, &flag);
    u32 value = vcall<u32>(obj, 0x5c, &flag);
    while (flag != 0) {
      vcall<void>(*(void **)(self + 0x4c), 4, value);
      value = vcall<u32>(*(void **)(ev + 0x4c), 0x5c, &flag);
    }
  }
  *(u32 *)(self + 0x50) = *(u32 *)(ev + 0x50);
  *(u32 *)(self + 0x54) = *(u32 *)(ev + 0x54);
}
PCREG(4b8950, relayMessageListCopyData);
