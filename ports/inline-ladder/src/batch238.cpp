// batch238.cpp - ZLNKWHANDS::GetAnimNameFromCollision (inline-ladder thread, 2026-10-11). Names of the hit-reaction
// animations come from the exe's string table; the one string typo ("*HitShoulderRightfRONT") is kept as is.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 FASTCALL ext_4cc850(const char *s, const char *pat);   // striwcmp (batch 54), wildcard compare

// Pick by side byte: side != 0 gives the first string, side == 0 the second (the exe's cmove on byte == 0).
static inline const char *pick(u8 side, u32 front, u32 back) {
  return (const char *)(side ? front : back);
}

// 0x474070 ZLNKWHANDS::GetAnimNameFromCollision(SIKBoneCollision *coli, bool big, ZItemTemplateWeapon *item) [GC
// 8018cf7c, high], thiscall, ret 0xc, returns the animation name (EAX).
// 1. kind = item->slot 0x330 (0 without an item). cl = big && !(this->slot 0x1e0(0x80200014)).
// 2. kind 9 (poison): name = item+4 or "<NONAME>"; striwcmp(name, "*Poison*") == 0 gives "Die_Poison", else "Die_Carrot".
// 3. kind 8 and cl: "Die_Carrot".
// 4. Otherwise pick the hit string by coli[0] (region 0..9, see the table) and coli[1] (side); when this->slot 0x21c(string)
//    is false, the generic "*Hit*FrontSmall"/"*Hit*BackSmall" by side.
static const char *THISCALL getAnimNameFromCollision(u8 *self, u8 *coli, u32 big, void *item) {
  u32 kind = item ? vcall<u32>(item, 0x330) : 0;
  u8 cl = (u8)big;
  if (vcall<u32>(self, 0x1e0, 0x80200014u) & 0xff)
    cl = 0;
  if (kind == 9) {
    const char *nm = item && U32(item, 4) ? (const char *)U32(item, 4) : (const char *)0x67c8e8;   // "<NONAME>"
    u32 r = ext_4cc850(nm, (const char *)0x689ab4);   // "*Poison*"
    return r == 0 ? (const char *)0x689ac0 : (const char *)0x689acc;   // "Die_Poison" / "Die_Carrot"
  }
  if (kind == 8 && cl)
    return (const char *)0x689acc;   // "Die_Carrot"
  const char *s = (const char *)0;
  u8 side = coli[1];
  switch (coli[0]) {
  case 0:   // left shoulder
    s = cl ? pick(side, 0x689ad8, 0x689af4) : pick(side, 0x689b0c, 0x689b28);
    break;
  case 1:   // torso
    s = cl ? pick(side, 0x689c90, 0x689ca4) : pick(side, 0x689cb8, 0x689ccc);
    break;
  case 2:
  case 3:   // head
    s = (const char *)0x689ce0;   // "*HitHeadFrontSmall"
    break;
  case 4:
  case 5:   // left shoulder, unsized variant
    s = cl ? pick(side, 0x689ad8, 0x689af4) : pick(side, 0x689b44, 0x689b5c);
    break;
  case 6:   // left leg
    s = cl ? pick(side, 0x689bdc, 0x689bf0) : pick(side, 0x689c04, 0x689c1c);
    break;
  case 7:
  case 8:   // right shoulder
    s = cl ? pick(side, 0x689b74, 0x689b90) : pick(side, 0x689bac, 0x689bc4);
    break;
  case 9:   // right leg
    s = cl ? pick(side, 0x689c34, 0x689c4c) : pick(side, 0x689c60, 0x689c78);
    break;
  default:
    s = (const char *)0;
    break;
  }
  if (vcall<u32>(self, 0x21c, s))
    return s;
  return pick(side, 0x689cf4, 0x689d04);   // "*Hit*FrontSmall" / "*Hit*BackSmall"
}
PCREG(474070, getAnimNameFromCollision);
