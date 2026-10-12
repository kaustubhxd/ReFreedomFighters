// batch2485.cpp - decomp area 24, batch 2485.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);  // operator new (cdecl)

// 0x5c06c0 CEntityTracker::Load(ZLoadGame*), thiscall, ret 4, AL = 1 (parked item 744).
// Reads a count through the load object, allocates two arrays (23-byte records and one dword per record) with the
// overflow-saturating size, then loops over the records. Each record: value through the system table (slot 0x58),
// then four load calls on the record fields. The count-sized dword array is filled by the load object (slot 0x40).
static u8 THISCALL entityTrackerLoad(u8 *self, void *ld) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(ld, 0x68, self + 0x68);
  u32 v = 0;
  vcall<void>(ld, 0x40, &v);
  u8 *sys = G(u8 *, 0x70039c);
  *(u32 *)(self + 0x64) = vcall<u32>(*(void **)(sys + 0x9b), 0x58, v);
  vcall<void>(ld, 0x40, self + 0x54);
  vcall<void>(ld, 0x40, self + 0x58);
  vcall<void>(ld, 0x40, self + 0x5c);
  vcall<void>(ld, 0x50, self + 0x60);

  u32 cnt = *(u32 *)(self + 0x54);
  u64 p = (u64)cnt * 0x17u;
  *(void **)(self + 0x50) = ext_41e290((p >> 32) ? 0xffffffffu : (u32)p);
  u64 q = (u64)cnt * 4u;
  *(void **)(self + 0x4c) = ext_41e290((q >> 32) ? 0xffffffffu : (u32)q);

  for (u32 i = 0; i < *(u32 *)(self + 0x54); i++) {
    u8 *rec = *(u8 **)(self + 0x50) + i * 0x17u;
    u32 a = 0;
    vcall<void>(ld, 0x40, &a);
    *(u32 *)rec = vcall<u32>(*(void **)(sys + 0x9b), 0x58, a);
    vcall<void>(ld, 0x6c, rec + 4);
    vcall<void>(ld, 0x68, rec + 0x10);
    vcall<void>(ld, 0x50, rec + 0x11);
    vcall<void>(ld, 0x44, rec + 0x15);
    vcall<void>(ld, 0x40, (u8 *)(*(u8 **)(self + 0x4c)) + i * 4);
  }
  return 1;
}
PCREG(5c06c0, entityTrackerLoad);
