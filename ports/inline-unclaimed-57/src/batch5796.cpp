// batch5796.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 96: 0x5c4c00 (GUESS name unnamed_5c4c00), thiscall, two stack arguments (a1 unused,
// db; ret 8), no return value. Order: this+0x48 = 0x4e5e60(db); this+0x50 = 0x4e5e60(db); 0x4e6180(db, this+0x64); 0x4e6180(db, this+0x70);
// if (int)this+0x50 > 5: this+0x50 = 5; n = this+0x50; arr = operator new(n*0x19, or 0xffffffff on overflow) (cdecl, hooked); if arr: each
// entry's dword at +0 is zeroed; this+0x4c = arr (0 if the allocation returned 0); for j < n: byte arr[0x19 j + 0x18] = 1, dword arr[0x19 j + 4]
// = 0; this+0x58 = holder->vt[+0x14]() where holder = (this+0x44)->+0x18. The readers and the allocator run as hooked stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotN)(u8 *self);

extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e6180(u8 *db, u8 *out);  // float array reader, original code (hooked in the spec)
extern "C" void *ext_41e290(u32 size);  // operator new (cdecl, size), original code (hooked in the spec)

// 0x5c4c00, thiscall, two stack arguments (GUESS name)
static void THISCALL unnamed5c4c00(u8 *self, u32 a1, u8 *db) {
  (void)a1;
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  *(u32 *)(self + 0x50) = ext_4e5e60(db);
  ext_4e6180(db, self + 0x64);
  ext_4e6180(db, self + 0x70);
  if ((s32)*(u32 *)(self + 0x50) > 5) *(u32 *)(self + 0x50) = 5;
  u32 n = *(u32 *)(self + 0x50);
  u32 sz;
  if (__builtin_mul_overflow(n, 0x19u, &sz)) sz = 0xffffffffu;
  u8 *arr = (u8 *)ext_41e290(sz);
  if (arr) {
    for (u32 i = 0; i < n; i++) *(u32 *)(arr + 0x19 * i) = 0;
  } else {
    arr = 0;
  }
  *(u32 *)(self + 0x4c) = (u32)(unsigned long)arr;
  if ((s32)*(u32 *)(self + 0x50) > 0) {
    for (u32 j = 0; j < *(u32 *)(self + 0x50); j++) {
      u8 *base = *(u8 **)(self + 0x4c);
      base[0x19 * j + 0x18] = 1;
      *(u32 *)(base + 0x19 * j + 4) = 0;
    }
  }
  u8 *o = *(u8 **)(self + 0x44);
  u8 *holder = *(u8 **)(o + 0x18);
  *(u32 *)(self + 0x58) = ((SlotN)VT(holder)[0x14 / 4])(holder);
}
PCREG(5c4c00, unnamed5c4c00);
