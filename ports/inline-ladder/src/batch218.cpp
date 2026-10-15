// batch218.cpp - hero action bodies (inline-ladder thread, 2026-10-11): ZFFActionUseHealth::CallBack (first aid).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

struct Quad218 { u32 a, b, c, d; };
extern "C" void THISCALL ext_467410(void *handPart, u32 hero, u32 zero, Quad218 q);   // no GC name; ret 0x18
extern "C" void THISCALL ext_59a580(void *osd, const char *msg, u32 color, u32 sound); // ZGameOSD::MessageAdd
extern "C" void THISCALL ext_5ab090(void *p);                                          // no GC name (on osd+0x1d0f)
extern "C" long double THISCALL ext_58b9c0(void *hero, float amount, u32 ref, u32 b);  // ZFFHERO::AdjustHitPoints (ST0)

static inline void *db218() { return (void *)U32(G(u32, 0x70039c), 0x9b); }

// 0x5dfd00 ZFFActionUseHealth::CallBack() [GameCube reference, high ("HealthFull")], slot 3, AL = 0.
// +8 hero, +0xc hand, +0x14 action id (0x14/0x15/0x16 = FirstAid_Small/Medium/Large, docs/20 batch 55).
// The kit is the hand's item; it is touched (slot 0x2e8) and its owner (slot 0x2f4) gets a ZCamHelper made on demand
// (+0x85a, owner slot 0x100("ZCamHelper")). If owner +0x7ff equals +0x7fb (health already at maximum; NaN counts as
// different): the OSD (+0x852) shows the text "Menu/HelpText"/"HealthFull" (database +0xae4 slot 0, colour 0xffffff00,
// no sound) and nothing is used. Otherwise: amount = +0x7fb for ids 0x14..0x16 (all three heal to full), else 0;
// osd+0x1d0f gets 0x5ab090 when there is an OSD; AdjustHitPoints(amount, ref(owner), false); the kit is released from
// the hand (0x467410, hand slot 8(hero, 0)), dropped (slot 0x2d0(3, 0)), unowned (slot 0x2f0(0, 0, 1)) and slot 0x210(1)
// (probably "remove").
static bool THISCALL useHealthCallBack(u8 *self) {
  float amount = 0.0f;
  void *kit = vcall<void *>((void *)U32(self, 0xc), 0x10);
  vcall<u32>(kit, 0x2e8);
  u8 *owner = vcall<u8 *>(kit, 0x2f4);
  if (U32(owner, 0x85a) == 0)
    U32(owner, 0x85a) = vcall<u32>(owner, 0x100, (const char *)0x6a6e88);
  float maxHp = F32(owner, 0x7fb);
  float hp = F32(owner, 0x7ff);
  if (hp == maxHp) {
    void *osd = (void *)U32(owner, 0x852);
    if (!osd)
      return false;
    const char *msg = vcall<const char *>((void *)U32(db218(), 0xae4), 0, (const char *)0x6a67e8, (const char *)0x6b74dc);
    ext_59a580(osd, msg, 0xffffff00u, 0);
    return false;
  }
  u32 id = U32(self, 0x14);
  if (id == 0x14 || id == 0x15 || id == 0x16)
    amount = maxHp;
  if (U32(owner, 0x852))
    ext_5ab090((void *)U32(U32(owner, 0x852), 0x1d0f));
  u32 ref = vcall<u32>(db218(), 0x4c, owner);
  (void)ext_58b9c0(owner, amount, ref, 0);
  vcall<u32>(db218(), 0x4c, kit);
  Quad218 q = {0, 0, 0, 0xffffffffu};
  ext_467410((u8 *)U32(self, 0xc) + 4, U32(self, 8), 0, q);
  vcall<void>((void *)U32(self, 0xc), 8, U32(self, 8), 0u);
  vcall<void>(kit, 0x2d0, 3u, 0u);
  vcall<void>(kit, 0x2f0, 0u, 0u, 1u);
  vcall<void>(kit, 0x210, 1u);
  return false;
}
PCREG(5dfd00, useHealthCallBack);
