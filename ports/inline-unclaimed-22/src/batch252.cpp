// batch252.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch252"): the inventory bridge
// that tells the HUD which weapon and how much ammo the hero holds. Names from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_4ccba0(u8 *tab);   // REFTAB32 constructor (original)
extern "C" void THISCALL ext_4ccf60(u8 *tab);   // REFTAB32 destructor (original)

typedef void(__attribute__((cdecl)) * log0_t)(void *, const char *);

// 0x5af0f0 ZFFInventoryInfoList::GetInventoryInfo(ZItemTemplate *t) ret 4: [this] = count, followed by count pointers to
// info records whose first word is a template; returns the first record for t, else 0.
static u8 *THISCALL getInventoryInfo_5af0f0(u32 *self, u32 t) {
  u32 n = self[0];
  for (u32 i = 0; i < n; i++)
    if (*(u32 *)self[1 + i] == t) return (u8 *)self[1 + i];
  return 0;
}
PCREG(5af0f0, getInventoryInfo_5af0f0);

// 0x5af300 ZFFInventoryBridge::GetAmmo(ZItem *item) ret 4: item->vt[0x35c]() (rounds in the gun) plus, when the owner's
// vt[0x55c](item) finds a spare-ammo item, that item's vt[0x320]().
static u32 THISCALL getAmmo_5af300(u8 **self, u8 *item) {
  u32 a = vcall<u32>(item, 0x35c);
  u8 *x = (u8 *)vcall<u32>(self[0], 0x55c, (u32)item);
  if (x) return vcall<u32>(x, 0x320) + a;
  return a;
}
PCREG(5af300, getAmmo_5af300);

// 0x5af5b0 ZFFInventoryBridge::GetWeapon(EFFItemType &type, unsigned &ammo, bool alt) ret 0xc. Needs owner (+0),
// info list (+4) and +8 set, else logs "ZFFInventoryBridge::GetWeapon, Warning member data not initialized..." (line 0x52)
// and leaves the outputs alone. Otherwise asks the owner for its inventory: RegisterZMsg("MSG_GETINVENTORYLIST")
// (engine db vt[0x114], four words) and owner->vt[0x130](owner, msg, &list) into a stack REFTAB32; walks it; for each item
// id (engine db vt[0x58]) looks up the info record of the item's template (vt[0x2e8]). Kinds 5, 6, 7, 8, 10, 11 match when
// alt is set, kinds 3 and 4 when it is not; the first match writes type = kind and ammo = GetAmmo(item). No match writes 0, 0.
static void THISCALL getWeapon_5af5b0(u8 **self, u32 *type, u32 *ammo, u8 alt) {
  if (!self[0] || !self[1] || !self[2]) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x6b0f44u, 0x52u);
    (*(log0_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6b1070u);
    return;
  }
  u8 tab[0xac];
  ext_4ccba0(tab);
  u8 *o = self[0];
  u8 *vt = *(u8 **)o;
  u8 *db = *(u8 **)(*(u8 **)0x70039cu + 0x9b);
  u32 r = vcall<u32>(db, 0x114, 0x690a30u, 0u, 0x6b0f44u, 0x57u);
  (*(void(THISCALL **)(u8 *, u8 *, u32, u8 *))(vt + 0x130))(o, o, (u16)r, tab);
  u32 it[3];
  vcall<void>(tab, 0x4c, (u32)it);
  u32 id = vcall<u32>(tab, 0x5c, (u32)it);
  while (it[0]) {
    u8 *g = (u8 *)vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x58, id);
    u32 t = vcall<u32>(g, 0x2e8);
    u8 *info = getInventoryInfo_5af0f0((u32 *)self[1], t);
    if (info) {
      u32 k = *(u32 *)(info + 0x10);
      bool hi = k == 5 || k == 6 || k == 7 || k == 8 || k == 0xb || k == 0xa;
      if ((hi && alt) || ((k == 3 || k == 4) && !alt)) {
        *type = k;
        *ammo = getAmmo_5af300(self, g);
        ext_4ccf60(tab);
        return;
      }
    }
    id = vcall<u32>(tab, 0x5c, (u32)it);
  }
  *type = 0;
  *ammo = 0;
  ext_4ccf60(tab);
}
PCREG(5af5b0, getWeapon_5af5b0);
