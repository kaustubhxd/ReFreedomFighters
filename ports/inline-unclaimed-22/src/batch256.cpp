// batch256.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch256"): ZFFHERO::Resurrect,
// what happens when the hero is brought back. Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_595100(u8 *hero);             // ZFFHERO::SetupInventoryBindingList (hooked, GUESS stub)
extern "C" void THISCALL ext_59a850(u8 *osd, u8 *actor);   // ZGameOSD::RemoveActorActionMarker (hooked, GUESS stub)
extern "C" void THISCALL ext_5e0dd0(u8 *osd, u32 hpBits);  // ZGameOSD::SetHealth(float) (hooked, GUESS stub; float bits)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))
#define OSDMGR (*(u8 **)(*(u8 **)0x70039cu + 0x1aa3))

// 0x594600 ZFFHERO::Resurrect() (no args). Only when this->vt[0x438]() (byte) is true:
//  - SendCommand (vt[0x128]) of RegisterZMsg("Msg_ResetControls", 0, ZFFHero.cpp, 0x1061) with data 0, 0 (the two zero
//    words are pushed before the RegisterZMsg words and become SendCommand's last two arguments);
//  - (+0x6c)->vt[0x30](this, 0, 1, 1) (four words, the same at 0x46578a, 0x59536b, 0x59538c);
//  - two OSD manager vt[0x94]() calls: the first result gets +4 = 1.0f, the second +0x10 = 0;
//  - when byte +0x9e7 is set: SetupInventoryBindingList, every non-null entry of the actor table at [0x7003b8] (+0x40c,
//    count +0x408) gets RemoveActorActionMarker(entry's OSD +0x852, this), and +0x658 = 0;
//  - +0x417 = 0, +0x7ff = +0x7fb; SetHealth(1.0f) on this hero's OSD (+0x852) when there is one;
//  - this->vt[0x644](2), vt[0x588](), vt[0x36c]();
//  - finds "rDEADMENU" (db->vt[0x138]()->vt[0x88](name, &h)) and, when the db knows h, geom->vt[0x2c4]()->vt[0x300]().
static void THISCALL resurrect_594600(u8 *self) {
  if (!(u8)vcall<u32>(self, 0x438)) return;
  u8 *vt = *(u8 **)self;
  u32 r = vcall<u32>(DB, 0x114, 0x6acf90u, 0u, 0x6ac6d0u, 0x1061u);
  (*(void(THISCALL **)(u8 *, u32, u32, u32))(vt + 0x128))(self, (u16)r, 0u, 0u);
  vcall<void>(*(u8 **)(self + 0x6c), 0x30, (u32)self, 0u, 1u, 1u);
  *(u32 *)(vcall<u32>(OSDMGR, 0x94) + 4) = 0x3f800000u;
  *(u8 *)(vcall<u32>(OSDMGR, 0x94) + 0x10) = 0;
  if (self[0x9e7]) {
    ext_595100(self);
    for (u32 i = 0;; i++) {
      u8 *tab = *(u8 **)0x7003b8u;
      if (i >= *(u32 *)(tab + 0x408)) break;
      u8 *e = *(u8 **)(tab + 0x40c + 4 * i);
      if (e) ext_59a850(*(u8 **)(e + 0x852), self);
    }
    *(u32 *)(self + 0x658) = 0;
  }
  u8 *osd = *(u8 **)(self + 0x852);
  u32 hp = *(u32 *)(self + 0x7fb);
  *(u32 *)(self + 0x417) = 0;
  *(u32 *)(self + 0x7ff) = hp;
  if (osd) ext_5e0dd0(osd, 0x3f800000u);
  vcall<void>(self, 0x644, 2u);
  vcall<void>(self, 0x588);
  vcall<void>(self, 0x36c);
  u8 *scene = (u8 *)vcall<u32>(DB, 0x138);
  u32 h = 0;
  vcall<void>(scene, 0x88, 0x6acaf8u, (u32)&h);
  u8 *g = (u8 *)vcall<u32>(DB, 0x58, h);
  if (g) vcall<void>((u8 *)vcall<u32>(g, 0x2c4), 0x300);
}
#undef DB
#undef OSDMGR
PCREG(594600, resurrect_594600);
