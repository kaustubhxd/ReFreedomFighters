// batch6170.cpp - unclaimed-68 batch 17 (claim 16, gap band). Name from the GC name map (low confidence). The helper 0x4a0e40
// is claimed by another area; it runs as exe code here.
#include "ff.h"

extern "C" u32 THISCALL ext_4a0e40(u8 *self, u32 idx);

// 0x4a15b0, ZDistCheck::Promote(int) (low): thiscall, ret 4. Finds the section for idx (helper), swaps the entries idx and
// counter+1 when they differ, then bumps the counter of the section and sets the weight at +0x820 to 1.0 (0x3f800000).
static u32 THISCALL distCheckPromote(u8 *self, u32 idx) {
  u32 sec = ext_4a0e40(self, idx);
  u32 ebx = *(u32 *)(self + sec * 4 + 0x800) + 1;
  if (ebx != idx) {
    u32 ecx = *(u32 *)(self + idx * 4 + 4);
    u32 eax = *(u32 *)(self + ebx * 4 + 4);
    *(u32 *)(self + idx * 4 + 4) = eax;
    *(u32 *)(self + ebx * 4 + 4) = ecx;
  }
  u32 edx = sec + 1;
  if (edx < 8) {
    u8 *p = self + 0x804 + edx * 4;
    for (;;) {
      u32 eax = *(u32 *)p;
      if (eax != *(u32 *)(self + sec * 4 + 0x800)) break;
      eax++;
      edx++;
      *(u32 *)p = eax;
      p += 4;
      if (edx >= 8) break;
    }
  }
  *(u32 *)(self + sec * 4 + 0x800) += 1;
  *(u32 *)(self + sec * 4 + 0x820) = 0x3f800000u;
  return ebx;
}
PCREG(4a15b0, distCheckPromote);
