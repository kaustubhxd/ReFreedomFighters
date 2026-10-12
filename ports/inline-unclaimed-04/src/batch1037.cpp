// batch1037.cpp - unclaimed-04 batch 37 (docs/20-unclaimed-04.md): 0x495af0, thiscall, three stack arguments (ret 0xc).
#include "ff.h"

extern "C" u32 FASTCALL ext_4daf20(void *ecx, void *edx);  // original code (hooked by address in the spec; GUESS)
extern "C" u32 THISCALL ext_495950(void *self, u32 a1, u32 a2, u32 a3, u32 r, u32 eight);  // ret 0x14 (hooked; GUESS)

// 0x495af0
static void THISCALL unk495af0(u8 *self, u32 a1, u8 *a2, u32 a3) {
  u32 c = 0x200002;
  u32 p1 = *(u32 *)(a2 + 0x54);
  if (p1 != 0) {
    u32 p2 = *(u32 *)(p1 + 0xc);
    c = *(u32 *)(p2 + 0x23);
  }
  u32 r = ext_4daf20((void *)c, *(void **)(a2 + 0x3c));
  ext_495950(*(void **)(self + 0x1c), a1, (u32)a2, a3, r, 8);
}
PCREG(495af0, unk495af0);
