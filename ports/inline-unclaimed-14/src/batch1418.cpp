// batch1418.cpp - unclaimed-14 batch 18 (residue 13): CImpactResponse::Save(ZSaveGame*).
#include "ff.h"

// 0x5dc490, CImpactResponse::Save(ZSaveGame*) (high): thiscall, one stack argument (ret 4), returns al = 1. Clears bit 0x40
// of the dword at +4; save.vt[+0x6c](dword +0x48); save.vt[+0x70](&this+0x50); save.vt[+0x68](&this+0x74); n = strlen(this+0x4c);
// save.vt[+0x3c](n); save.vt[+0x10](this+0x4c, n). Each callee pops its own arguments.
static u8 THISCALL impactResponseSave(u8 *self, u8 *save) {
  typedef void(THISCALL * v1_t)(u8 *, u32);
  typedef void(THISCALL * v2_t)(u8 *, u32, u32);
  *(u32 *)(self + 4) &= ~0x40u;
  (*(v1_t *)(*(u32 *)save + 0x6c))(save, *(u32 *)(self + 0x48));
  (*(v1_t *)(*(u32 *)save + 0x70))(save, (u32)(self + 0x50));
  (*(v1_t *)(*(u32 *)save + 0x68))(save, (u32)(self + 0x74));
  const char *s = *(const char **)(self + 0x4c);
  u32 n = 0;
  while (s[n] != 0)
    n++;
  (*(v1_t *)(*(u32 *)save + 0x3c))(save, n);
  (*(v2_t *)(*(u32 *)save + 0x10))(save, (u32)s, n);
  return 1;
}
PCREG(5dc490, impactResponseSave);
