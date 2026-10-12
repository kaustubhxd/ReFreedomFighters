// batch308.cpp - unclaimed-03 batch 8 (docs/20-unclaimed-03.md): ZItem::GetItemRootTM(float*, float*) at 0x46e760.
// Name from the GC name map (high). The PC body calls two virtuals on this (slots +0x2c8 and +0x2dc) and five original
// engine helpers (0x4dfd10, 0x4de480, 0x441970, 0x4de420, 0x43e960), which stay original code (ext_). The /GS cookie
// check at the end (0x633654) is not reproduced: it only aborts when the frame is corrupted.
#include "ff.h"

// Original engine helpers, bound by build.sh to their PC addresses. All are fastcall (ECX, EDX, rest on the stack).
extern "C" void FASTCALL ext_4dfd10(void *ecx, u32 edx);
extern "C" void FASTCALL ext_4de480(void *ecx, u32 edx);
extern "C" void FASTCALL ext_441970(void *ecx, u32 edx, void *stack1);
extern "C" void FASTCALL ext_4de420(void *ecx, u32 edx);
extern "C" void FASTCALL ext_43e960(void *ecx, u32 edx);

// 0x46e760, ZItem::GetItemRootTM(float*, float*) (high). Calls this->vtbl[+0x2c8](a1, a2) (thiscall), then X =
// this->vtbl[+0x2dc]() (thiscall, no arguments). If X is not null: transforms into a local buffer A (at frame+0x0c) and
// B (at frame+0): helper(A, [X+8]); helper(A, a1); helper(B, [X+8]+0x24, stack A); helper(a1, A); helper(a2, B).
// Callee pops 8 (ret 8).
static void THISCALL itemGetItemRootTM(u8 *self, u32 a1, u32 a2) {
  typedef void(THISCALL * virt2_fn)(u8 *, u32, u32);
  typedef u32(THISCALL * virt0_fn)(u8 *);
  ((virt2_fn)(*(u32 *)(*(u32 *)self + 0x2c8)))(self, a1, a2);
  u8 *x = (u8 *)((virt0_fn)(*(u32 *)(*(u32 *)self + 0x2dc)))(self);
  if (!x) return;
  u8 frame[0x34];
  u8 *A = frame + 0x0c;
  u8 *B = frame;
  u32 xp = *(u32 *)(x + 8);
  ext_4dfd10(A, xp);
  ext_4de480(A, a1);
  ext_441970(B, xp + 0x24, A);
  ext_4de420((void *)a1, (u32)A);
  ext_43e960((void *)a2, (u32)B);
}
PCREG(46e760, itemGetItemRootTM);
