// batch608.cpp - damage thread, batch 608: which hit-reaction clip a hit plays.
#include "ff.h"

#pragma pack(push, 1)
struct SIKBoneCollision { u8 zone; u8 front; };
#pragma pack(pop)

// 0x59fd30 ZFFActor::GetHitAimHeaderFromCollision(SIKBoneCollision*) (GC 800744e4). The clip headers live in a global
// table: [0x7003b8] +0xb55 points at 64-byte records, one per actor hit-anim set (actor +0x932 is the index).
// Record (front, back): +0x08/+0x0c left shoulder, +0x10/+0x14 right shoulder, +0x18/+0x1c left leg,
// +0x20/+0x24 right leg, +0x28/+0x2c torso (zone 1), +0x38/+0x3c the pair used for head zones and as the fallback.
// Zones 0, 4, 5 -> left shoulder; 7, 8 -> right shoulder; 6 -> left leg; 9 -> right leg; 1 -> torso; 2, 3 -> head
// pair; anything else, or a missing (0) clip -> head pair.
static u32 THISCALL getHitAimHeaderFromCollision(u8 *self, SIKBoneCollision *c) {
  u8 *r = *(u8 **)(G(u8 *, 0x7003b8) + 0xb55) + (*(u32 *)(self + 0x932) << 6);
  u32 off;
  switch (c->zone) {
    case 0: case 4: case 5: off = 0x08; break;
    case 7: case 8: off = 0x10; break;
    case 6: off = 0x18; break;
    case 9: off = 0x20; break;
    case 1: off = 0x28; break;
    case 2: case 3: off = 0x38; break;
    default: off = 0; break;
  }
  if (off) {
    u32 h = *(u32 *)(r + (c->front ? off : off + 4));
    if (h) return h;
  }
  return *(u32 *)(r + (c->front ? 0x38 : 0x3c));
}
PCREG(59fd30, getHitAimHeaderFromCollision);

// 0x483980 ZPlayer::GetAnimNameFromCollision(SIKBoneCollision*, bool, bool) (GC 801514c4): the Hero's hit clip names.
// Zones 0, 4, 5 -> HitShoulderLeft{Front,Back}; 7, 8 -> HitShoulderRight{Front,Back}; 6 -> HitLegLeftFront and
// 9 -> HitLegRightFront (no back variants); 1, 2, 3 -> HitTorso{Front,Back}; other zones -> null. The two bools are
// not read.
static const char *THISCALL getAnimNameFromCollision(u8 *, SIKBoneCollision *c, u32, u32) {
  switch (c->zone) {
    case 0: case 4: case 5: return (const char *)(c->front ? 0x68bf78 : 0x68bf90);
    case 7: case 8: return (const char *)(c->front ? 0x68bfa4 : 0x68bfbc);
    case 6: return (const char *)0x68bfd4;
    case 9: return (const char *)0x68bfe4;
    case 1: case 2: case 3: return (const char *)(c->front ? 0x68bff8 : 0x68c008);
    default: return 0;
  }
}
PCREG(483980, getAnimNameFromCollision);
