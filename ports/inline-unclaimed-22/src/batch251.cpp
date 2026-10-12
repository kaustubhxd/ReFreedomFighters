// batch251.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch251"): CInventory::GetItemOfType.
// Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" const char *THISCALL ext_4cc1d0(u8 *str);   // original string c_str (returns [this])
extern "C" void THISCALL ext_4cbec0(u8 *str);          // original string destructor (frees a non-inline buffer)

typedef void(__attribute__((cdecl)) * logs_t)(void *, const char *, const char *);

// Logs fmt with the name of obj (obj->vt[0x1d8](&str, 1) fills a stack string; c_str; destructor), at inventory.cpp line.
static void logWithName(u32 line, u8 *obj, const char *fmt) {
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x6909a4u, line);
  u8 str[0x80];
  u8 *sp = (u8 *)vcall<u32>(obj, 0x1d8, (u32)str, 1u);
  (*(logs_t *)(*(u8 **)log + 0x2c))(log, fmt, ext_4cc1d0(sp));
  ext_4cbec0(str);
}

// 0x4ac820 CInventory::GetItemOfType(int type) ret 4: walks the item list embedded at +0x11a (vt[0x4c](&it) starts,
// vt[0x5c](&it) returns the next item id, it = 0 at the end). Each id is turned into a geom (engine db vt[0x58]); a missing
// geom logs "WARNING: Item has been removed even though it's still in %s's inventory" (owner name from +0x44, line 0x22e)
// and removes the entry (vt[0x44](&it)); a geom without an item template (vt[0x2e8]) logs "WARNING: Missing ItemGroup value
// for item %s" (line 0x235) and removes it too. The first item whose template's vt[0x1e0](type) is true is returned; else 0.
// SEH frame and stack cookie not reproduced.
static u32 THISCALL getItemOfType_4ac820(u8 *self, u32 type) {
  u8 *lst = self + 0x11a;
  if (!lst) return 0;
  u32 it;
  vcall<void>(lst, 0x4c, (u32)&it);
  u32 id = vcall<u32>(lst, 0x5c, (u32)&it);
  while (it) {
    u8 *rm = *(u8 **)0x70039cu;
    u8 *o = (u8 *)vcall<u32>(*(u8 **)(rm + 0x9b), 0x58, id);
    if (!o) {
      logWithName(0x22e, *(u8 **)(self + 0x44), (const char *)0x690b00u);
      vcall<void>(lst, 0x44, (u32)&it);
    } else {
      u8 *t = (u8 *)vcall<u32>(o, 0x2e8);
      if (!t) {
        logWithName(0x235, o, (const char *)0x690b48u);
        vcall<void>(lst, 0x44, (u32)&it);
      } else if ((u8)vcall<u32>(t, 0x1e0, type)) {
        return id;
      }
    }
    id = vcall<u32>(lst, 0x5c, (u32)&it);
  }
  return 0;
}
PCREG(4ac820, getItemOfType_4ac820);
