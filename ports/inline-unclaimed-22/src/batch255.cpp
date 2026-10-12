// batch255.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch255"): CInventory::GiveItem,
// the give-item path that also refills every weapon. Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

typedef int(__attribute__((cdecl)) * stricmp_t)(const char *, const char *);

// 0x4abdd0 CInventory::GiveItem(const char *name) ret 4. Remembers the render manager's byte +0x9b7 and calls its vt[0x14]().
// For each group name of {"ItemsGroup", "WeaponsGroup"}: db->vt[0x138]() gives a scene object whose vt[0x88](group, &h)
// finds the group; a zero handle or a handle the engine db (vt[0x58]) does not know leaves the function at once (without the
// vt[0x10] call below). this->vt[0x88](groupGeom, name) gives the item; then every inventory entry (list at +0x11a: vt 0x4c
// start, vt 0x5c next) whose geom passes vt[0x1e0](0x1007d8) gets vt[0x324](n): 6 for "Molotov" and "FragGrenade" (name at
// geom +4, "<NONAME>" when null; _stricmp), else 200. At the end, when the remembered byte was set, the manager's vt[0x10]().
static void THISCALL giveItem_4abdd0(u8 *self, u32 name) {
  u8 *rm = *(u8 **)0x70039cu;
  u8 was = rm[0x9b7];
  vcall<void>(rm, 0x14);
  static const u32 groups[3] = {0x690ad0u, 0x690adcu, 0};
  stricmp_t cmp = *(stricmp_t *)0x676414u;
  for (const u32 *gp = groups; *gp; gp++) {
    u8 *scene = (u8 *)vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x138);
    u32 h = 0;
    vcall<void>(scene, 0x88, *gp, (u32)&h);
    if (!h) return;
    u32 grp = vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x58, h);
    if (!grp) return;
    vcall<void>(self, 0x88, grp, name);
    u8 *lst = self + 0x11a;
    u32 it[3];
    vcall<void>(lst, 0x4c, (u32)it);
    u32 id = vcall<u32>(lst, 0x5c, (u32)it);
    while (it[0]) {
      u8 *g = (u8 *)vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x58, id);
      if (g && (u8)vcall<u32>(g, 0x1e0, 0x1007d8u)) {
        const char *nm = *(const char **)(g + 4) ? *(const char **)(g + 4) : (const char *)0x67c8e8u;
        u32 n;
        if (!cmp(nm, (const char *)0x690aecu)) n = 6;
        else if (!cmp(*(const char **)(g + 4) ? *(const char **)(g + 4) : (const char *)0x67c8e8u, (const char *)0x690af4u)) n = 6;
        else n = 200;
        vcall<void>(g, 0x324, n);
      }
      id = vcall<u32>(lst, 0x5c, (u32)it);
    }
  }
  if (was) vcall<void>(*(u8 **)0x70039cu, 0x10);
}
PCREG(4abdd0, giveItem_4abdd0);
