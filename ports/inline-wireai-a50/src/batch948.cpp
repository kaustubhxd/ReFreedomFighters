// batch948.cpp - 0x5ee920 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), no args, plain ret (the callee's stack use is
// cleared by mov esp, ebp). If the dword at this+0x19 is 0, return. Otherwise let b = this+5 and e = this+9 (dwords). If the dword at this+0x11 is 1,
// call 0x5edcb0 with ECX = b, EDX = b + 4 (fastcall; stood in) and stack words (e, 0, this). Otherwise k = ((e - b) >> 2) - 1 (signed), and the
// same call with EDX = b + 4k. Then the dword at this+0x41 = 0.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void FASTCALL ext_5edcb0(void *ecx, void *edx, u32 s1, u32 s2, void *s3);   // stood in (ecx, edx, then three stack words, ret 0xc)

// 0x5ee920 (no name in the map).
static void THISCALL Apply5ee920(u8 *self) {
  if (U32(self, 0x19) == 0) return;
  u32 b = U32(self, 5);
  u32 e = U32(self, 9);
  if (U32(self, 0x11) == 1) {
    ext_5edcb0((void *)b, (void *)(b + 4), e, 0u, self);
  } else {
    s32 k = ((s32)(e - b) >> 2) - 1;
    ext_5edcb0((void *)b, (void *)(b + (u32)k * 4), e, 0u, self);
  }
  U32(self, 0x41) = 0;
}
PCREG(5ee920, Apply5ee920);
