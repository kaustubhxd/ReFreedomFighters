// batch1114.cpp - unclaimed-11 batch 15 (slice 10): two leaves.
#include "ff.h"

// 0x4d5120, IOFSMemoryAccess_t::nativeEof(ImpNativeFd_t*) (high). The name map's argument is not read by the body;
// the result is (signed this+8 >= signed this+0xc).
static bool THISCALL ioFsNativeEof(u8 *self, void *fd) { return (s32)*(u32 *)(self + 8) >= (s32)*(u32 *)(self + 0xc); }
PCREG(4d5120, ioFsNativeEof);

// 0x58a660, GUESS (no name match): the byte argument, sign-extended, indexes a dword slot at this+0x2c2d.
static void THISCALL guessSlotStore(u8 *self, u8 index, u32 value) {
  *(u32 *)(self + 0x2c2d + (s32)(s8)index * 4) = value;
}
PCREG(58a660, guessSlotStore);
