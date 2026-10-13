// batch1110.cpp - unclaimed-11 batch 10 (core-todo residue-10): ZFFActor::ClassFrameUpdate (0x59e2a0, high).
// Thiscall, no arguments. Callees 0x477a30 and 0x59ead0 are original exe code in the PC build (here: stubs in the harness).
#include "ff.h"

typedef u32(THISCALL *fnU32Arg)(void *self, u32 a);
typedef void(THISCALL *fnTwoArgs)(void *self, u32 a, u32 b);
typedef u32(THISCALL *fnNoArg)(void *self);
typedef void(THISCALL *fnVoid)(void *self);

extern "C" void THISCALL ext_477a30(void *self);
extern "C" void THISCALL ext_59ead0(void *self);
// 0x5a3000: the tail-jump target of the al == 0 path (mov ecx, this; jmp 0x5a3000). Called here, then return, which is
// the same control flow as the jump (the callee returns to our caller).
extern "C" void THISCALL ext_5a3000(void *self);

// 0x59e2a0, ZFFActor::ClassFrameUpdate() (high).
static void THISCALL ffActorClassFrameUpdate(u8 *self) {
  if (self[0x79f]) {
    void *rm = G(void *, 0x70039c);
    void *a = *(void **)((u8 *)rm + 0x9b);
    void *r = (void *)((fnU32Arg)(*(void ***)a)[0x58 / 4])(a, *(u32 *)(self + 0x78a));
    if (r) ((fnTwoArgs)(*(void ***)r)[0x2d0 / 4])(r, 0, 0);
    self[0x79f] = 0;
  }
  void *eng = G(void *, 0x70038c);
  u32 r1 = ((fnU32Arg)(*(void ***)eng)[0x48 / 4])(eng, 0xff0000);
  ext_477a30(self);
  eng = G(void *, 0x70038c);
  ((fnU32Arg)(*(void ***)eng)[0x48 / 4])(eng, r1);
  ext_59ead0(self);
  if ((u8)((fnNoArg)(*(void ***)self)[0x438 / 4])(self)) {
    if (*(u32 *)(self + 0x784) && *(u32 *)(self + 0x92e)) *(u32 *)(self + 0x784) = 0;
  } else if (*(u32 *)(self + 0x784)) {
    ext_5a3000(self);  // PC: je 0x59e337 -> cmp [edi+0x784]; jne -> mov ecx, edi; jmp 0x5a3000
  }
}
PCREG(59e2a0, ffActorClassFrameUpdate);
