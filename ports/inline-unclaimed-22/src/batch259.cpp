// batch259.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch259"): movement parameters
// of path followers and players. Names from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);   // original allocator (verified in inline-unclaimed-64)
extern "C" u8 *THISCALL ext_487600(u8 *mem, u8 *owner, u32 n); // movement action constructor (verified in inline-unclaimed-21)

// 0x523b10 CMoveAlongPath::SetMoveParams(float a, float b, float c) ret 0xc: stores the three at +0x57, +0x5b, +0x5f;
// each that is below 1.0 (ordered compare, so NaN stays) becomes 1.0. When +0x39 is 1, this->vt[8](+0x57, +0x5b) passes
// the first two on (two float words).
static void THISCALL setMoveParams_523b10(u8 *self, float a, float b, float c) {
  *(float *)(self + 0x57) = a;
  *(float *)(self + 0x5b) = b;
  *(float *)(self + 0x5f) = c;
  if (1.0f > a) *(u32 *)(self + 0x57) = 0x3f800000u;
  if (1.0f > b) *(u32 *)(self + 0x5b) = 0x3f800000u;
  if (1.0f > c) *(u32 *)(self + 0x5f) = 0x3f800000u;
  if (*(u32 *)(self + 0x39) == 1) vcall<void>(self, 8, *(u32 *)(self + 0x57), *(u32 *)(self + 0x5b));
}
PCREG(523b10, setMoveParams_523b10);

// 0x483b10 ZPlayer::GetMoveSpeeds(float *out) const ret 4: copies the three words at +0x445, +0x449, +0x44d.
static void THISCALL getMoveSpeeds_483b10(u8 *self, u32 *out) {
  out[0] = *(u32 *)(self + 0x445);
  out[1] = *(u32 *)(self + 0x449);
  out[2] = *(u32 *)(self + 0x44d);
}
PCREG(483b10, getMoveSpeeds_483b10);

// 0x482890 ZPlayer::CreateMovementAction() (no args): new 0x22 bytes; when that worked, returns
// ctor 0x487600(mem, this, 4); else 0.
static u32 THISCALL createMovementAction_482890(u8 *self) {
  u8 *m = ext_41e290(0x22);
  if (!m) return 0;
  return (u32)ext_487600(m, self, 4);
}
PCREG(482890, createMovementAction_482890);
