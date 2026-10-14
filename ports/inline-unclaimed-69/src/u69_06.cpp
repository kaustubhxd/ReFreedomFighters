// u69_06.cpp - area 69, group 6 (unclaimed-69 thread).
#include "ff.h"

static inline u32 readU32Unaligned(const u8 *p) {
  u32 v = 0;
  for (int q = 0; q < 4; ++q)
    v |= (u32)p[q] << (8 * q);
  return v;
}

// 0x63da50, ZDrawBase::EndShadows() (GC map high). thiscall, void. For each of the pointers in the array at +0xf0 (count
// at +0xec, read again on every pass), slot 0x70 of the pointed-to object is called.
static void THISCALL drawBaseEndShadows(u8 *self) {
  for (u32 i = 0; i < *(u32 *)(self + 0xec); ++i) {
    void *o = *(void **)(self + 0xf0 + 4 * i);
    vcall<void>(o, 0x70);
  }
}
PCREG(63da50, drawBaseEndShadows);

// 0x4a8550, ZSelectNotify::Save(ZSaveGame*) (GC map high). thiscall, one stack arg (ret 4); returns true. Clears bit 6 of
// the dword at +4, then writes six values to the save object: dword +0x48 (slot 0x3c), word +0x4c (slot 0x40), unaligned
// dword +0x4e (slot 0x44), word +0x52 (slot 0x40), dword +0x54 (slot 0x3c).
static bool THISCALL selectNotifySave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(sg, 0x3c, *(u32 *)(self + 0x48));
  vcall<void>(sg, 0x40, (u32)*(u16 *)(self + 0x4c));
  vcall<void>(sg, 0x44, readU32Unaligned(self + 0x4e));
  vcall<void>(sg, 0x40, (u32)*(u16 *)(self + 0x52));
  vcall<void>(sg, 0x3c, *(u32 *)(self + 0x54));
  return true;
}
PCREG(4a8550, selectNotifySave);
