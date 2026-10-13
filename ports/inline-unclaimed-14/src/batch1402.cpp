// batch1402.cpp - unclaimed-14 batch 2 (docs/20-unclaimed-14.md): ZFFActor::GetLastHitPos and ZActor::GetAnimOffset.
#include "ff.h"

// 0x59fe80, ZFFActor::GetLastHitPos(float*) (high): copies the three dwords at this+0x8fb, +0x8ff, +0x903 to the out
// pointer (the offsets are unaligned, so the PC code uses plain dword moves).
static void THISCALL ffActorGetLastHitPos(u8 *self, u32 out) {
  u32 *dst = (u32 *)out;
  dst[0] = *(u32 *)(self + 0x8fb);
  dst[1] = *(u32 *)(self + 0x8ff);
  dst[2] = *(u32 *)(self + 0x903);
}
PCREG(59fe80, ffActorGetLastHitPos);

// 0x478ad0, ZActor::GetAnimOffset(AnimHeader*) (high): stdcall, one stack argument. A null argument returns 0. Otherwise
// it returns the argument minus the dword at +0x44 of the object that the global pointer at 0x70039c points to, through
// its pointer at +0x9b (PC: mov ecx,[0x70039c]; mov ecx,[ecx+0x9b]; sub eax,[ecx+0x44]).
static u32 STDCALL actorGetAnimOffset(u32 p) {
  if (p == 0)
    return 0;
  u8 *obj = G(u8 *, 0x70039c);
  u8 *inner = *(u8 **)(obj + 0x9b);
  return p - *(u32 *)(inner + 0x44);
}
PCREG(478ad0, actorGetAnimOffset);
