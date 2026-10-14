// batch5724.cpp - unclaimed-57, band 0x5c1000-0x5e1000, batch 24: two unnamed functions (names GUESS).
// 0x5c7720 (thiscall, one stack arg obj, ret 4, returns al = 1): clear bit 0x40 of dword this+4; obj->vt[+0x60](byte this+0x54) (thiscall,
// one argument, obj as ECX).
// 0x5d9180 (thiscall, one stack arg a, ret 4): this+0x54 = reader A(a) = 0x4e5e60 (ECX = a, no stack args), dword result.
// The virtual slot and reader A are unverified callees: a logging stub and a fixed-result hook in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotByte)(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);  // reader A, original code (hooked in the spec)

static u8 THISCALL unnamed5c7720(u8 *self, u8 *obj) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotByte)VT(obj)[0x60 / 4])(obj, self[0x54]);
  return 1;
}
PCREG(5c7720, unnamed5c7720);

static void THISCALL unnamed5d9180(u8 *self, u8 *a) {
  *(u32 *)(self + 0x54) = ext_4e5e60(a);
}
PCREG(5d9180, unnamed5d9180);
