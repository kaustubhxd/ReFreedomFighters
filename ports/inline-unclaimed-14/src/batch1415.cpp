// batch1415.cpp - unclaimed-14 batch 15 (residue 13): ZWindControl::Save(ZSaveGame*) and ZFFActorActionThrow::Save(ZSaveGame&).
#include "ff.h"

static inline u32 bits(float f) { return fbits(f); }

// 0x4c36d0, ZWindControl::Save(ZSaveGame*) (high): thiscall, one stack argument (ret 4), returns al = 1. Clears bit 0x40 of
// the dword at +4; save.vt[+0x6c](dword +0x48); r1 = save.vt[+0x4c](float +0x4c); r1.vt[+0x4c](float +0x50);
// r2 = save.vt[+0x4c](float +0x54); r2.vt[+0x4c](float +0x5c). Each callee pops its one argument.
static u8 THISCALL windControlSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= ~0x40u;
  typedef void(THISCALL * v1_t)(u8 *, u32);
  typedef u32(THISCALL * r1_t)(u8 *, u32);
  (*(v1_t *)(*(u32 *)save + 0x6c))(save, *(u32 *)(self + 0x48));
  u8 *r1 = (u8 *)(*(r1_t *)(*(u32 *)save + 0x4c))(save, bits(*(float *)(self + 0x4c)));
  (*(v1_t *)(*(u32 *)r1 + 0x4c))(r1, bits(*(float *)(self + 0x50)));
  u8 *r2 = (u8 *)(*(r1_t *)(*(u32 *)save + 0x4c))(save, bits(*(float *)(self + 0x54)));
  (*(v1_t *)(*(u32 *)r2 + 0x4c))(r2, bits(*(float *)(self + 0x5c)));
  return 1;
}
PCREG(4c36d0, windControlSave);

// 0x5eb710, ZFFActorActionThrow::Save(ZSaveGame&) (medium): thiscall, one stack argument (the save object, ret 4), returns
// the eax of its last call. save.vt[+0x64](dword +8); save.vt[+0x3c](dword +0xc - [[0x70039c]+0x9b]+0x44); save.vt[+0x4c]
// (float +0x10); save.vt[+0x60](byte +0x14, zero-extended); return save.vt[+0x68](&+0x15).
static u32 THISCALL actionThrowSave(u8 *self, u8 *save) {
  typedef void(THISCALL * v1_t)(u8 *, u32);
  typedef u32(THISCALL * r1_t)(u8 *, u32);
  (*(v1_t *)(*(u32 *)save + 0x64))(save, *(u32 *)(self + 8));
  u8 *b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  (*(v1_t *)(*(u32 *)save + 0x3c))(save, *(u32 *)(self + 0xc) - *(u32 *)(b + 0x44));
  (*(v1_t *)(*(u32 *)save + 0x4c))(save, bits(*(float *)(self + 0x10)));
  (*(v1_t *)(*(u32 *)save + 0x60))(save, (u32)self[0x14]);
  return (*(r1_t *)(*(u32 *)save + 0x68))(save, (u32)(self + 0x15));
}
PCREG(5eb710, actionThrowSave);
