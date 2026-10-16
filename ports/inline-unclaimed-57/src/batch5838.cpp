// batch5838.cpp - residue 9, 0x592350 (ZFFHERO::GetSpawnpointListFromTeam(int), gc name map), stdcall, one stack argument (team), ret 4.
// Index i = team - 3 (unsigned); i > 3: return 0. Else O = (engine+0x9b)->vt[+0x138](); arg = 0; O->vt[+0x88](key[i], &arg) with key = 0x6acfcc, 0x6acfdc, 0x6acfec,
// 0x6acffc (the jump table at 0x5923fc: 0x59236b, 0x592389, 0x5923a7, 0x5923c5 in that order). Return arg.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot2v)(u8 *self, u32 a, u32 b);

// 0x592350, stdcall, one stack argument (ZFFHERO::GetSpawnpointListFromTeam)
static u32 STDCALL unnamed592350(u32 team) {
  static const u32 keys[4] = {0x6acfcc, 0x6acfdc, 0x6acfec, 0x6acffc};
  u32 i = team - 3;
  if (i > 3) return 0;
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *O = (u8 *)(unsigned long)((SlotN)VT(sub)[0x138 / 4])(sub);
  u32 arg = 0;
  ((Slot2v)VT(O)[0x88 / 4])(O, keys[i], (u32)(unsigned long)&arg);
  return arg;
}
PCREG(592350, unnamed592350);
