// batch1127.cpp - collision thread, batch 1127: two ZCollisionBase getters.
#include "ff.h"

// 0x4edca0 ZCollisionBase::IsCollisionBoxLocked() const [medium], thiscall, plain ret: returns the byte at +0xa9.
static u8 THISCALL isCollisionBoxLocked(const u8 *self) { return self[0xa9]; }
PCREG(4edca0, isCollisionBoxLocked);

// 0x4ecb30 ZCollisionBase::GetCollisionPack() [medium], thiscall, plain ret: returns the dword at +0x1ad (unaligned).
static u32 THISCALL getCollisionPack(const u8 *self) { return *(const u32 *)(self + 0x1ad); }
PCREG(4ecb30, getCollisionPack);
