// batch252.cpp - unclaimed area 25, slice floor(addr/16) mod 20 == 4.
#include "ff.h"

typedef int(__attribute__((cdecl)) * cmp_t)(const char *, const char *);
typedef u32 (THISCALL *F1)(u8 *self, u32 a);

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x438cc0, thiscall, ret 4 (one stack argument: name). ZInputActions::GetActionMap(const char*) (map name, body checked).
// Null name or null member at +0x1214 returns 0. Otherwise: vslot 0x4c(member, &flag), then vslot 0x5c(member, &flag)
// gives the first entry; while flag is set, an entry whose +8 string equals name (IAT strcmp at 0x676414, cdecl, 0 = equal)
// is returned, otherwise the next entry is taken with vslot 0x5c. Returns 0 when the walk ends.
static u32 THISCALL getActionMap(u8 *selfP, const char *name) {
  u32 self = (u32)(unsigned long)selfP;
  if (name == nullptr)
    return 0;
  u32 obj = rdw(self, 0x1214);
  if (obj == 0)
    return 0;
  u32 flag = 0;
  ((F1)rdw(rdw(obj, 0), 0x4c))((u8 *)(unsigned long)obj, (u32)(unsigned long)&flag);
  u32 esi = ((F1)rdw(rdw(obj, 0), 0x5c))((u8 *)(unsigned long)obj, (u32)(unsigned long)&flag);
  if (flag == 0)
    return 0;
  for (;;) {
    u32 p = rdw(esi, 8);
    if (p != 0 && (*(cmp_t *)0x676414)(name, (const char *)(unsigned long)p) == 0)
      return esi;
    obj = rdw(self, 0x1214);
    esi = ((F1)rdw(rdw(obj, 0), 0x5c))((u8 *)(unsigned long)obj, (u32)(unsigned long)&flag);
    if (flag == 0)
      return 0;
  }
}
PCREG(438cc0, getActionMap);
