// batch1406.cpp - unclaimed-14 batch 6 (slice 13): ZActorIf::SetVisLightMultiplier(OpaqueCallParameters_t&).
#include "ff.h"

// 0x5003d0, original code (not lifted here): array accessor, thiscall with this = the table struct and one stack argument
// (the index); returns a pointer to the element.
extern "C" u8 *THISCALL ext_5003d0(u8 *table, u32 index);

// 0x508410, ZActorIf::SetVisLightMultiplier(OpaqueCallParameters_t&) (high): stdcall-style one stack argument (ret 4).
// Sequence (PC): r1 = B.slot+0x4c(C) where B = [0x70039c]+0x9b and C = this+0x18; ext_5003d0(X+4 table, 0) with the float
// read discarded; r2 = (u16) B.slot+0x114(0x6904b8, 0, 0x69cff0, 0x12e, &r1); s = B.slot+0x58([C+0x73a], r2); then
// C.slot+0x130(s).
static void THISCALL actorIfSetVisLightMultiplier(u8 *self, u32 x) {
  typedef u32(THISCALL * f4c_t)(u8 *, u32);
  typedef u32(THISCALL * f114_t)(u8 *, u32, u32, u32, u32, u32 *);
  typedef u32(THISCALL * f58_t)(u8 *, u32, u32);
  typedef void(THISCALL * f130_t)(u8 *, u32);
  u8 *b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *c = *(u8 **)(self + 0x18);
  u32 r1 = (*(f4c_t *)(*(u32 *)b + 0x4c))(b, (u32)c);
  u8 *table = *(u8 **)(x + 4);
  u8 *elem = ext_5003d0(table, 0);
  (void)*(float *)elem;
  u32 r2 = (*(f114_t *)(*(u32 *)b + 0x114))(b, 0x6904b8u, 0u, 0x69cff0u, 0x12eu, &r1) & 0xffffu;
  u32 s = (*(f58_t *)(*(u32 *)b + 0x58))(b, *(u32 *)(c + 0x73a), r2);
  (*(f130_t *)(*(u32 *)c + 0x130))(c, s);
}
PCREG(508410, actorIfSetVisLightMultiplier);
