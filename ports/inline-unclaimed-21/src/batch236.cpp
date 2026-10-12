// batch236.cpp - small leaves, slice 0/1. 0x5ec190 (name GUESS): thiscall(a) (ret 4), this = ebx, a = edi. A sequence of vtable
// calls on a: 0x70(this+4), 0x68(this+0x28), 0x60(byte +0x34), 0x60(byte +0x35), 0x44(dword +0x36), 0x3c(dword +0x3e),
// 0x3c(+0x42), 0x68(+0x46), 0x3c(+0x52), 0x3c(+0x56), 0x3c(+0x5a), 0x3c(+0x5e), 0x3c(+0x6e), 0x3c(+0x72), 0x70(+0x76),
// 0x68(+0x9a), 0x60(byte +0xa6); p = [this+0x3a]: 0x3c(dword p[0]); 0x10(p[1], n*40) with n = [this+0x3e]; 0x3c((end-begin)>>2)
// with begin = [this+0x62], end = [this+0x66]; for each item in [begin, end): 0x10(item, 0x2c).
#include "ff.h"

typedef void(THISCALL *SlotOne)(u8 *, u32);     // vtable slot, one stack word, no result used
typedef void(THISCALL *SlotTwo)(u8 *, u32, u32);  // vtable 0x10: two stack words

static u32 vslot16(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void THISCALL serialize_5ec190(u8 *self, u8 *a) {
  u8 *E = a;
  ((SlotOne)vslot16(E, 0x70))(E, (u32)(self + 4));
  ((SlotOne)vslot16(E, 0x68))(E, (u32)(self + 0x28));
  ((SlotOne)vslot16(E, 0x60))(E, (u32)self[0x34]);
  ((SlotOne)vslot16(E, 0x60))(E, (u32)self[0x35]);
  ((SlotOne)vslot16(E, 0x44))(E, *(u32 *)(self + 0x36));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x3e));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x42));
  ((SlotOne)vslot16(E, 0x68))(E, (u32)(self + 0x46));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x52));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x56));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x5a));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x5e));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x6e));
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)(self + 0x72));
  ((SlotOne)vslot16(E, 0x70))(E, (u32)(self + 0x76));
  ((SlotOne)vslot16(E, 0x68))(E, (u32)(self + 0x9a));
  ((SlotOne)vslot16(E, 0x60))(E, (u32)self[0xa6]);
  u8 *p = *(u8 **)(self + 0x3a);
  ((SlotOne)vslot16(E, 0x3c))(E, *(u32 *)p);
  u32 sz = (*(u32 *)(self + 0x3e)) * 40u;
  ((SlotTwo)vslot16(E, 0x10))(E, *(u32 *)(p + 4), sz);
  s32 span = (s32)(*(u32 *)(self + 0x66) - *(u32 *)(self + 0x62));
  ((SlotOne)vslot16(E, 0x3c))(E, (u32)(span >> 2));
  u32 *it = *(u32 **)(self + 0x62);
  u32 *end = *(u32 **)(self + 0x66);
  for (; it != end; ++it) ((SlotTwo)vslot16(E, 0x10))(E, *it, 0x2c);
}
PCREG(5ec190, serialize_5ec190);
