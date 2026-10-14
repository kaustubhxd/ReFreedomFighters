// batch1704.cpp - 0x476a60 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, one stack argument (src), ret 4, no SEH. Copies
// src's block (ZGROUP::CopyDataBlock 0x43f900, hooked; one argument), clears this+0x72 and the dword at this+0x73, then
// DBLK::Get(src, &this+0x5c, 1) (0x4e11e0, hooked; ret 8), DBLK::Get(src, &this+0x70, 1) (0x4e11d0, hooked; the exe's thunk,
// its stack effect is a GUESS and the target is hooked here), t = DBLK::GetType(src) (0x4e1600, hooked; returns al). When t == 3:
// DBLK::Get(src, &src_slot, 1) (0x4e12e0, hooked) and this+0x72 = (that value != 0). Then when DBLK::GetType(src) == 8:
// DBLK::Get(src, &this+0x73, 1). Returns DBLK::NextBlock(src) (0x4e1b30, hooked; eax). The src_slot is the exe's argument
// slot; the port uses a local.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_43f900[], ext_4e11e0[], ext_4e11d0[], ext_4e1600[], ext_4e12e0[], ext_4e1b30[];
typedef void(THISCALL *CopyBlk)(void *self, u32 src);
typedef void(THISCALL *Get2)(void *self, u32 out, u32 one);
typedef u32(THISCALL *GetType0)(void *self);
typedef u32(THISCALL *Next0)(void *self);

u32 THISCALL GUESS_476a60(u8 *self, u32 src) {
  ((CopyBlk)(void *)ext_43f900)(self, src);
  AT(u8, self, 0x72) = 0;
  AT(u32, self, 0x73) = 0;
  ((Get2)(void *)ext_4e11e0)((void *)src, (u32)(self + 0x5c), 1u);
  ((Get2)(void *)ext_4e11d0)((void *)src, (u32)(self + 0x70), 1u);
  u32 t = (u8)((GetType0)(void *)ext_4e1600)((void *)src);
  if (t == 3) {
    u32 slot = src;
    ((Get2)(void *)ext_4e12e0)((void *)src, (u32)&slot, 1u);
    AT(u8, self, 0x72) = slot != 0;
  }
  t = (u8)((GetType0)(void *)ext_4e1600)((void *)src);
  if (t == 8) ((Get2)(void *)ext_4e12e0)((void *)src, (u32)(self + 0x73), 1u);
  return ((Next0)(void *)ext_4e1b30)((void *)src);
}
PCREG(476a60, GUESS_476a60);
