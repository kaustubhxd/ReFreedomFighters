// batch1638.cpp - CActionController::RemoveEvaluator (0x4a1850, residue 13, 2026-10-12).
// The controller keeps a count at +0x48 and evaluator pointers at +0x5c (each evaluator's first dword is its id).
// Removal deletes every evaluator whose id matches, 0x844 bytes each (cdecl delete 0x634273), and moves the last
// pointer into the freed slot, copying the parallel word at +0x48 + 4*count into slot - 0x10 (the original's offsets;
// GUESS on what the parallel array is). The loop does not revisit a moved entry, as in the original.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[];  // __builtin_delete (cdecl: pointer, size)
typedef void(__attribute__((cdecl)) *DeleteFn)(void *p, u32 size);

void THISCALL CActionController_RemoveEvaluator(u8 *self, u32 key) {
  for (s32 b = 0; b < AT(s32, self, 0x48); b++) {
    u32 *edi = (u32 *)(self + 0x5c + 4 * b);
    if (key == AT(u32, *edi, 0)) {
      ((DeleteFn)(void *)ext_634273)((void *)*edi, 0x844);
      u32 cnt = AT(u32, self, 0x48);
      if ((u32)b != cnt - 1) {
        *edi = AT(u32, self, 0x58 + 4 * cnt);
        AT(u32, edi, -0x10) = AT(u32, self, 0x48 + 4 * cnt);
      }
      AT(u32, self, 0x48) = cnt - 1;
    }
  }
}
PCREG(4a1850, CActionController_RemoveEvaluator);
