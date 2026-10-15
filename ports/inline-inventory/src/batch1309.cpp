// batch1309.cpp - inventory thread (inline-inventory, 2026-10-11): CInventory give-item family.
// GiveItemInGroup (0x4abf90), GiveAllItems (0x4ac310), GiveAllItemsInGroup (0x4ac120).
// Class types: ZItem 0x1007d1, ZItemTemplate 0x1007d3, container template 0x1007d4, ammo-type item 0x1007d8,
// bit 0x100000 = "gives items", 0x100001 = nested group. ZBaseGeom::IsDerivedFrom (0x4db9a0) stays original code.
#include "ff.h"

extern "C" u32 THISCALL ext_4db9a0(u8 *geom, u32 type);             // ZBaseGeom::IsDerivedFrom(unsigned int) const
extern "C" u32 THISCALL ext_4acf30(u8 *self, u32 id);                // CInventory::AddItem(unsigned int)

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }
typedef int (*stricmp_t)(u32, u32);
#define crt_stricmp (*(stricmp_t *)0x676414)                         // IAT: _stricmp
#define NONAME 0x67c8e8                                              // "<NONAME>"

// Class type id of a geom: template (+0x54) -> class desc (+0xc) -> type id (+0x23); 0x200002 with no template.
static inline u32 geomType(u8 *g) {
  u8 *t = *(u8 **)(g + 0x54);
  if (!t) return 0x200002;
  return *(u32 *)(*(u8 **)(t + 0xc) + 0x23);
}

// Looks through the inventory's item REFTAB (+0x11a) for an item of class `cls` whose template (slot 0x2e8) is
// `tmpl`. Begin = slot 0x4c, next = slot 0x5c, the cursor is a 3-dword local whose first dword is 0 at the end.
static bool hasItemOf(u8 *self, u32 cls, u32 tmpl) {
  u8 *lst = self + 0x11a;
  u32 cur[3];
  vcall<u32>(lst, 0x4c, cur);
  u32 v = vcall<u32>(lst, 0x5c, cur);
  while (cur[0]) {
    u8 *it = vcall<u8 *>(refTable(), 0x58, v);
    if (it && isA(it, cls) && vcall<u32>(it, 0x2e8) == tmpl) return true;
    v = vcall<u32>(lst, 0x5c, cur);
  }
  return false;
}

// ---------------------------------------------------------------- CInventory::GiveItemInGroup(ZGROUP*, const char*)
// 0x4abf90 (medium): walks the group's children (+0x50 first, +0x60 next). A child whose type has bit 0x100000 is
// looked at. A template child (IsA 0x1007d3) with a matching name (_stricmp == 0) gets its template id added
// (AddItem); a container child (0x1007d4) also adds its container key (slot 0x340) once, unless an ammo-type item
// with that key is already held; then the function returns 1. A non-template child with bit 0x100001 passes the
// template and name to its own slot 0x88. A child without bit 0x100000 ends the walk (return 0).
static u8 THISCALL giveItemInGroup(u8 *self, u8 *group, u32 name) {
  u8 *g = *(u8 **)(group + 0x50);
  for (;;) {
    if (!g || !(geomType(g) & 0x100000)) return 0;
    if (ext_4db9a0(g, 0x1007d3)) {
      u8 *tmpl = *(u8 **)(g + 0x54);
      u32 tn = *(u32 *)(tmpl + 4);
      if (crt_stricmp(tn ? tn : NONAME, name) == 0) {
        ext_4acf30(self, vcall<u32>(refTable(), 0x4c, tmpl));
        if (!ext_4db9a0(g, 0x1007d4)) return 1;
        u32 key = vcall<u32>(tmpl, 0x340, 0u);
        if (!hasItemOf(self, 0x1007d8, key)) ext_4acf30(self, vcall<u32>(refTable(), 0x4c, key));
        return 1;
      }
    } else if (ext_4db9a0(g, 0x100001)) {
      vcall<u32>(self, 0x88, *(u32 *)(g + 0x54), name);
    }
    g = *(u8 **)(g + 0x60);
  }
}
PCREG(4abf90, giveItemInGroup);

// ---------------------------------------------------------------- CInventory::GiveAllItems()
// 0x4ac310 (medium): two group names are looked up in the message map (slot 0x138 of the ref table, then slot 0x88
// (name, &id)): "ItemsGroup" (0x690ad0) and "WeaponsGroup" (0x690adc). For each: a missing id or group ends the call
// without the final sys call. A found group is passed to this->slot 0x8c; then every item of the inventory (+0x11a)
// that is ammo-type (0x1007d8) gets slot 0x324(999). Finally, if the sys flag byte +0x9b7 was set at entry, sys
// slot 0x10 runs. Sys slot 0x14 runs first. GUESS: 999 is the value of the "all items" cheat (ammo filled up).
static void THISCALL giveAllItems(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 flag = sys[0x9b7];
  vcall<u32>(sys, 0x14);
  static const u32 names[2] = {0x690ad0, 0x690adc};
  for (int k = 0; k < 2; k++) {
    u32 id = 0;
    vcall<u32>(vcall<u8 *>(refTable(), 0x138), 0x88, names[k], &id);
    if (!id) return;
    u8 *grp = vcall<u8 *>(refTable(), 0x58, id);
    if (!grp) return;
    vcall<u32>(self, 0x8c, grp);
    u8 *lst = self + 0x11a;
    u32 cur[3];
    vcall<u32>(lst, 0x4c, cur);
    u32 v = vcall<u32>(lst, 0x5c, cur);
    while (cur[0]) {
      u8 *it = vcall<u8 *>(refTable(), 0x58, v);
      if (it && isA(it, 0x1007d8)) vcall<u32>(it, 0x324, 0x3e7u);
      v = vcall<u32>(lst, 0x5c, cur);
    }
  }
  if (flag) vcall<u32>(sys, 0x10);
}
PCREG(4ac310, giveAllItems);

// ---------------------------------------------------------------- CInventory::GiveAllItemsInGroup(ZGROUP*)
// 0x4ac120 (medium): the group's children, as GiveItemInGroup but with no name. A template child (0x1007d3): if no
// held item of class 0x1007d1 has the template, AddItem(id(template)); a container child (0x1007d4) also gets its key
// (slot 0x340) added unless an ammo-type item (0x1007d8) with that key is already held. A nested child (bit 0x100001)
// passes its template to this->slot 0x8c. A child without bit 0x100000 ends the walk.
static void THISCALL giveAllItemsInGroup(u8 *self, u8 *group) {
  u8 *g = *(u8 **)(group + 0x50);
  for (;;) {
    if (!g || !(geomType(g) & 0x100000)) return;
    if (ext_4db9a0(g, 0x1007d3)) {
      u8 *tmpl = *(u8 **)(g + 0x54);
      if (!hasItemOf(self, 0x1007d1, (u32)tmpl)) ext_4acf30(self, vcall<u32>(refTable(), 0x4c, tmpl));
      if (ext_4db9a0(g, 0x1007d4)) {
        u32 key = vcall<u32>(tmpl, 0x340, 0u);
        if (!hasItemOf(self, 0x1007d8, key)) ext_4acf30(self, vcall<u32>(refTable(), 0x4c, key));
      }
    } else if (ext_4db9a0(g, 0x100001)) {
      vcall<u32>(self, 0x8c, *(u32 *)(g + 0x54));
    }
    g = *(u8 **)(g + 0x60);
  }
}
PCREG(4ac120, giveAllItemsInGroup);
