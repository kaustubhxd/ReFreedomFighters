// batch2419.cpp - decomp area 24, batch 2419: two vtable forwarders that keep the caller's stack argument.
#include "ff.h"

// 0x4625b0 (GUESS owner), thiscall, ret 4: forwards to slot 0x20 of the object at +0x6c.
static void THISCALL forwardSlot20(u8 *self, u32 arg) {
  vcall<void>(*(void **)(self + 0x6c), 0x20, arg);
}
PCREG(4625b0, forwardSlot20);

// 0x5f3230 SaveSerialInfo_t::saveint32(int), thiscall, ret 4: forwards to slot 0x44 of the object at +0x15.
static void THISCALL saveSerialInfoSaveInt32(u8 *self, u32 v) {
  vcall<void>(*(void **)(self + 0x15), 0x44, v);
}
PCREG(5f3230, saveSerialInfoSaveInt32);
