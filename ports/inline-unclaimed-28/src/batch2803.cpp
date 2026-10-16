#include "ff.h"
// batch2803.cpp - unclaimed-28 batch 3 (docs/20-unclaimed-28.md). Name from the GC name map (naming only).

// 0x5bf1f0, CCivilianPathList::Save(ZSaveGame*) (high). Clears bit 0x40 at this+4. Slot +0x44 with the dwords at
// this+0x90c and this+0x910. Then, when the count at +0x90c is positive, for each record i (0x3a bytes, record i at
// this+0x55 + 0x3a*i; the count is re-read at the end of each pass): slot +0x64 with the dword at record-9, slot +0x44
// with the sign-extended byte at record-5, slot +0x4c with the float at record, slot +0x60 with the byte at record-4,
// slot +0x60 with the byte at record-3, slot +0x44 with the byte at record-2, slot +0x44 with the byte at record-1,
// slot +0x68 with record+0x20, slot +0x4c with the float at record+0x2c, slot +0x60 with the byte at record+0x30, slot
// +0x10 with (record+8, 0x18). Then slot +0x10 with (this+0x718, 5 * the dword at +0x910), slot +0x44 with the dwords at
// +0x91e, +0x922, +0x926, slot +0x64 with +0x91a, slot +0x10 with (this+0x92a, 0x68). Returns true.
static u8 THISCALL civilianPathListSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x90c));
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x910));
  s32 n = *(s32 *)(self + 0x90c);
  if (n > 0) {
    s32 i = 0;
    u8 *rec = self + 0x55;
    do {
      vcall<void, u32>(sg, 0x64, *(u32 *)(rec - 9));
      vcall<void, u32>(sg, 0x44, (u32)(s32)(s8)rec[-5]);
      vcall<void, float>(sg, 0x4c, *(float *)rec);
      vcall<void, u32>(sg, 0x60, (u32)rec[-4]);
      vcall<void, u32>(sg, 0x60, (u32)rec[-3]);
      vcall<void, u32>(sg, 0x44, (u32)rec[-2]);
      vcall<void, u32>(sg, 0x44, (u32)rec[-1]);
      vcall<void, u8 *>(sg, 0x68, rec + 0x20);
      vcall<void, float>(sg, 0x4c, *(float *)(rec + 0x2c));
      vcall<void, u32>(sg, 0x60, (u32)rec[0x30]);
      vcall<void, u8 *, u32>(sg, 0x10, rec + 8, 0x18u);
      rec += 0x3a;
      ++i;
    } while (i < *(s32 *)(self + 0x90c));
  }
  vcall<void, u8 *, u32>(sg, 0x10, self + 0x718, 5u * *(u32 *)(self + 0x910));
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x91e));
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x922));
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x926));
  vcall<void, u32>(sg, 0x64, *(u32 *)(self + 0x91a));
  vcall<void, u8 *, u32>(sg, 0x10, self + 0x92a, 0x68u);
  return 1;
}
PCREG(5bf1f0, civilianPathListSave);
