// batch118.cpp - ZLNKWHANDS::CalcAnimRemapNames (climb thread, batch 118). The hands object's remap table: each entry asks
// the object (slot 0x35c, RemapName-like lookup, inferred from the name) for the name's animation remap and stores the
// result in a field. Names are the strings in the exe; the table is generated from the disassembly of 0x472460 (42 entries
// in exe order, then the explicit tail, which is hand-ported).
#include "ff.h"

// Slot 0x35c of the hands object: lookup by name (one stack arg, thiscall; the callee pops 4 - verified by the checker).
static inline u32 lookupName(u8 *self, const char *name) { return vcall<u32>(self, 0x35c, name); }

#define CALL(addr, off) *(u32 *)(self + off) = lookupName(self, (const char *)addr)

static void THISCALL handsCalcAnimRemapNames(u8 *self) {
  CALL(0x6898ac, 0x20a);  // '*Drop_Item_L*'
  CALL(0x6898bc, 0x20e);  // '*Drop_Item_R*'
  CALL(0x6898cc, 0x212);  // '*Pick_Up*L*'
  CALL(0x6898d8, 0x216);  // '*Pick_Up*R*'
  CALL(0x6898e4, 0x1fa);  // '*Put_Gun_L*'
  CALL(0x6898f0, 0x1fe);  // '*Put_Gun_R*'
  CALL(0x6898e4, 0x202);  // '*Put_Gun_L*'
  CALL(0x6898f0, 0x206);  // '*Put_Gun_R*'
  CALL(0x6898fc, 0x1ea);  // '*Pull_Item_L*'
  CALL(0x68990c, 0x1ee);  // '*Pull_Item_R*'
  CALL(0x68991c, 0x1f2);  // '*Pull_Gun_L*'
  CALL(0x68992c, 0x1f6);  // '*Pull_Gun_R*'
  CALL(0x68993c, 0x21a);  // 'P*_Bu*L*'
  CALL(0x689948, 0x21e);  // 'P*_Bu*R*'
  CALL(0x689954, 0x222);  // '*Swap_Hands'
  CALL(0x689960, 0x226);  // '*reload_revolver'
  CALL(0x689960, 0x22a);  // '*reload_revolver'
  CALL(0x689974, 0x22e);  // 'ub_reload_pistol'
  CALL(0x689988, 0x236);  // 'ub_reload_smg'
  CALL(0x689998, 0x232);  // '*reload_rifle'
  CALL(0x6899a8, 0x23a);  // '*reload_shotgun'
  CALL(0x6899b8, 0x25e);  // '*reload_pumpgun'
  CALL(0x6899c8, 0x262);  // '*reload_rpg7'
  CALL(0x6899d8, 0x2b7);  // '*reload_gun'
  CALL(0x6899d8, 0x2bb);  // '*reload_gun'
  CALL(0x689998, 0x2bf);  // '*reload_rifle'
  CALL(0x6899a8, 0x2c3);  // '*reload_shotgun'
  CALL(0x6899e4, 0x2c7);  // '*chamber_pumpgun'
  CALL(0x6899c8, 0x2cb);  // '*reload_rpg7'
  CALL(0x6899f8, 0x2cf);  // 'UB_Get_Item'
  CALL(0x689a04, 0x2d3);  // '*Aim_Rifle'
  CALL(0x689a10, 0x2d7);  // '*Aim_Two*'
  CALL(0x689a1c, 0x2db);  // '*Aim_Gun'
  CALL(0x689a28, 0x2df);  // 'UB_Aim_Rpg*'
  CALL(0x689a34, 0x266);  // '*Point_Right'
  CALL(0x689a44, 0x23e);  // 'UB*Listen*01*'
  CALL(0x689a54, 0x242);  // 'UB*Listen*02*'
  CALL(0x689a64, 0x246);  // 'UB*Listen*03*'
  CALL(0x689a74, 0x24a);  // 'UB*Listen*04*'
  CALL(0x689a84, 0x24e);  // 'UB*Talk*01*'
  CALL(0x689a90, 0x252);  // 'UB*Talk*02*'
  CALL(0x689a9c, 0x256);  // 'UB*Talk*03*'
  // Tail: the "and [eax+0x7c], ~2" on the two objects stored at +0x21a and +0x21e (their flag bit 1 cleared; meaning GUESS).
  u32 o1 = *(u32 *)(self + 0x21a);
  if (o1)
    *(u32 *)(o1 + 0x7c) &= 0xfffffffdu;
  u32 o2 = *(u32 *)(self + 0x21e);
  if (o2)
    *(u32 *)(o2 + 0x7c) &= 0xfffffffdu;
  // Talk04 (its result stays in ebx, not stored, as in the exe; the Listen and Talk names above are already in the table).
  u32 ebx = lookupName(self, (const char *)0x689aa8);  // UB*Talk*04*
  u32 edx = *(u32 *)(self + 0x24e);
  u32 eax = *(u32 *)(self + 0x23e);
  u32 ecx = eax;
  *(u32 *)(self + 0x25a) = ebx;
  if (edx != 0) {
    if (ecx == 0)
      ecx = edx;
  } else {
    edx = ecx;
  }
  if (*(u32 *)(self + 0x24e) == 0)
    *(u32 *)(self + 0x24e) = edx;
  if (*(u32 *)(self + 0x252) == 0)
    *(u32 *)(self + 0x252) = edx;
  if (*(u32 *)(self + 0x256) == 0)
    *(u32 *)(self + 0x256) = edx;
  if (ebx == 0)
    *(u32 *)(self + 0x25a) = edx;
  if (eax == 0)
    *(u32 *)(self + 0x23e) = ecx;
  if (*(u32 *)(self + 0x242) == 0)
    *(u32 *)(self + 0x242) = ecx;
  if (*(u32 *)(self + 0x246) == 0)
    *(u32 *)(self + 0x246) = ecx;
  if (*(u32 *)(self + 0x24a) == 0)
    *(u32 *)(self + 0x24a) = ecx;
}
PCREG(472460, handsCalcAnimRemapNames);
