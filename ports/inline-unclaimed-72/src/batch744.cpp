// batch744.cpp - CEntityTracker::Load(ZLoadGame* load) (0x5c06c0) [high], area 72 slice 0 (2026-10-12). SEH frame not used.
// Clears +4 bit 0x40; load slot 0x68(this+0x68); id via load slot 0x40, mapped by db 0x58 to +0x64; load slot 0x40 on
// +0x54 / +0x58 / +0x5c and slot 0x50 on +0x60. Count = +0x54: the record array (+0x50) has count*0x17 bytes and the id array
// (+0x4c) count*4 bytes; both allocations saturate to 0xffffffff on overflow (the exe's mul / seto / neg / or). For each
// record: an id from slot 0x40 mapped by db 0x58 to its first dword, slot 0x6c(rec+4), slot 0x68(rec+0x10), slot 0x50(rec+0x11),
// slot 0x44(rec+0x15); then slot 0x40 on the i-th id slot. Returns true.
#include "ff.h"

extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);   // operator new (caller pops)

static inline void *db() { return *(void **)((u8 *)*(void **)0x70039c + 0x9b); }

// 0x5c06c0 CEntityTracker::Load(ZLoadGame* load) [high].
static bool THISCALL tracker_Load(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(load, 0x68, self + 0x68);
  u32 id = 0;
  vcall<void>(load, 0x40, &id);
  *(u32 *)(self + 0x64) = vcall<u32>(db(), 0x58, id);
  vcall<void>(load, 0x40, self + 0x54);
  vcall<void>(load, 0x40, self + 0x58);
  vcall<void>(load, 0x40, self + 0x5c);
  vcall<void>(load, 0x50, self + 0x60);

  u32 sz = 0;
  u32 count = *(u32 *)(self + 0x54);
  if (__builtin_mul_overflow(count, (u32)0x17, &sz))
    sz = 0xffffffffu;
  *(void **)(self + 0x50) = ext_41e290(sz);

  count = *(u32 *)(self + 0x54);
  sz = 0;
  if (__builtin_mul_overflow(count, (u32)4, &sz))
    sz = 0xffffffffu;
  *(void **)(self + 0x4c) = ext_41e290(sz);

  for (u32 i = 0; i < *(u32 *)(self + 0x54); i++) {
    u8 *rec = *(u8 **)(self + 0x50) + i * 0x17;
    u32 tmp = 0;
    vcall<void>(load, 0x40, &tmp);
    *(u32 *)rec = vcall<u32>(db(), 0x58, tmp);
    vcall<void>(load, 0x6c, rec + 4);
    vcall<void>(load, 0x68, rec + 0x10);
    vcall<void>(load, 0x50, rec + 0x11);
    vcall<void>(load, 0x44, rec + 0x15);
    vcall<void>(load, 0x40, *(u8 **)(self + 0x4c) + i * 4);
  }
  return true;
}
PCREG(5c06c0, tracker_Load);
