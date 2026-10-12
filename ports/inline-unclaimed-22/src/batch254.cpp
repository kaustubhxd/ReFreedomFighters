// batch254.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch254"): counting items of a
// kind (grenades, molotovs, medkits on the HUD). Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_4ccba0(u8 *tab);   // REFTAB32 constructor (original)
extern "C" void THISCALL ext_4ccf60(u8 *tab);   // REFTAB32 destructor (original)
extern "C" u8 *THISCALL ext_5af130(u8 *list, u32 kind);   // GetInventoryInfo(EFFItemType), verified in batch253

typedef void(__attribute__((cdecl)) * log0_t)(void *, const char *);

// 0x5af430 ZFFInventoryBridge::GetNoOfItem(EFFItemType k) ret 4. Needs owner (+0), info list (+4) and +8, else logs
// "ZFFInventoryBridge::GetNoOfItem, Warning..." (line 0x35) and returns 0. No info record of kind k (or one whose template
// word is 0) returns 0. Otherwise asks the owner for its inventory (RegisterZMsg("MSG_GETINVENTORYLIST") at line 0x3d,
// owner->vt[0x130](owner, msg, &list) into a stack REFTAB32) and counts the items whose template (geom vt[0x2e8]) is the
// record's template.
static u32 THISCALL getNoOfItem_5af430(u8 **self, u32 k) {
  if (!self[0] || !self[1] || !self[2]) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x6b0f44u, 0x35u);
    (*(log0_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6b1020u);
    return 0;
  }
  u32 *info = (u32 *)ext_5af130(self[1], k);
  if (!info || !info[0]) return 0;
  u8 tab[0xac];
  ext_4ccba0(tab);
  u8 *o = self[0];
  u8 *vt = *(u8 **)o;
  u8 *db = *(u8 **)(*(u8 **)0x70039cu + 0x9b);
  u32 r = vcall<u32>(db, 0x114, 0x690a30u, 0u, 0x6b0f44u, 0x3du);
  (*(void(THISCALL **)(u8 *, u8 *, u32, u8 *))(vt + 0x130))(o, o, (u16)r, tab);
  u32 n = 0;
  u32 it[3];
  vcall<void>(tab, 0x4c, (u32)it);
  u32 id = vcall<u32>(tab, 0x5c, (u32)it);
  while (it[0]) {
    u8 *g = (u8 *)vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x58, id);
    if (vcall<u32>(g, 0x2e8) == info[0]) n++;
    id = vcall<u32>(tab, 0x5c, (u32)it);
  }
  ext_4ccf60(tab);
  return n;
}
PCREG(5af430, getNoOfItem_5af430);
