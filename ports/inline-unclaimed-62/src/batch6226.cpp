// batch6226.cpp - unclaimed-62 claim 19 (larger, 103 instructions): 0x4ce6a0 [thiscall, two arguments, ret 8, returns eax = edi + 4].
// SEH frame not reproduced (none in the body). this+0x24 is a sub-object C (vtable calls): without C the exe's helper 0x4cd540 (thiscall,
// one argument) gives a pointer p and edi = p - 4. With C: slot 0x4c and slot 0x5c take &loc (0x5c returns eax); loc zero -> edi = a2;
// otherwise edi = eax + (2 - this+0x18) * 4 and slot 0x44 takes &loc. Then *edi = a2 and slot 0x14 of C decides whether C is released
// (slot 0 with 1, then this+0x24 = 0). The tail links the element a2 into the list at a1 (this+0x18 entries, a1 - 8 base): the slot
// (a1 - 8) + 4*n gives the previous element, and the list head is this+0x1c, or the list at this+0x20 when that slot is null.
#include "ff.h"

extern "C" u32 THISCALL ext_4cd540(void *self, u32 a);   // exe: one stack argument (ret 4)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u32 THISCALL fn4ce6a0(u8 *self, u32 a1, u32 a2) {
  u32 loc = 0;
  u32 edi;
  if (rdp(self + 0x24) == 0) {
    edi = ext_4cd540(self, a2) - 4;
  } else {
    vcall<void>(rdp(self + 0x24), 0x4c, (u32)&loc);
    u32 eax = vcall<u32>(rdp(self + 0x24), 0x5c, (u32)&loc);
    if (loc == 0) {
      edi = a2;
    } else {
      u32 ecx = 2 - rd32u(self + 0x18);
      edi = eax + ecx * 4;
      vcall<void>(rdp(self + 0x24), 0x44, (u32)&loc);
    }
    wr32u((u8 *)edi, a2);
    if (vcall<u32>(rdp(self + 0x24), 0x14) == 0) {
      u8 *c = rdp(self + 0x24);
      if (c) vcall<void>(c, 0x0, (u32)1);
      wr32u(self + 0x24, 0);
    }
  }
  // tail (4ce71c): link into the list at a1
  u32 n = rd32u(self + 0x18);
  u32 base = a1 - 8;
  u8 *edx = (u8 *)(edi + (n - 2) * 4);
  wr32u(edx, 0);
  wr32u(edx + 4, 0);
  u32 slot = base + n * 4;
  if (slot == 0) {
    u32 e20 = rd32u(self + 0x20);
    wr32u(edx, e20);
    wr32u(edx + 4, 0);
    u32 e20b = rd32u(self + 0x20);
    if (e20b != 0) {
      wr32u((u8 *)(e20b + 4), (u32)edx);
      wr32u(self + 0x20, (u32)edx);
    } else {
      wr32u(self + 0x1c, (u32)edx);
      wr32u(self + 0x20, (u32)edx);
    }
    return edi + 4;
  }
  u32 prev = rd32u((const u8 *)slot);
  wr32u(edx, prev);
  wr32u(edx + 4, slot);
  if (prev != 0) wr32u((u8 *)(prev + 4), (u32)edx);
  wr32u((u8 *)slot, (u32)edx);
  if (prev == 0) wr32u(self + 0x1c, (u32)edx);
  return edi + 4;
}
PCREG(4ce6a0, fn4ce6a0);
