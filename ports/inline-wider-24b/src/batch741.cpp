// batch741.cpp - ZFFSearchLightGroup::Command(unsigned short cmd, void* data) (0x5c63f0) [high], residue 11 slice (2026-10-12).
// cmd must equal the word at 0x714340 (A) or 0x714344 (B). data[0] = spot ref, data[1] = group ref; a zero ref logs
// "Ref rSpot = 0" (line 0xde) or "Ref rGroup = 0" (line 0xe4) and returns 0. The table for A is GetRefTabToOperators, for B
// GetRefTabToEngageGuards (both called with the spot ref). Without a table: "rSpot not found" (0xf0). The group object is
// db 0x58 of data[1]; it must answer slot 0x1e0 with 0x100001 to count as a group. Then every element of the group (first at
// +8, next via slot 0x50) whose +0x54 object answers slot 0x1e0 with 0x2007f9 gets table slot 4(db 0x4c of that object). If
// the group does not answer 0x2007f9 at all, the single db 0x4c(group) goes to the table, or "rGroup was not a ref to a ZGRO"
// (line 0x118) is logged. Returns 0.
#include "ff.h"

extern "C" u32 THISCALL ext_5c6c50(void *self, u32 ref);   // GetRefTabToOperators
extern "C" u32 THISCALL ext_5c6bf0(void *self, u32 ref);   // GetRefTabToEngageGuards

static const char *kFile = (const char *)0x6b45c0;   // ZFFSearchLightGroup.cpp

static void logLine(u32 line, const char *msg) {
  void *log = vcall<void *>(*(void **)0x700390, 0x20, kFile, line);
  typedef void(__attribute__((cdecl)) * pf_t)(void *, const char *);
  (*(pf_t *)(*(u8 **)log + 0x2c))(log, msg);
}

static inline void *db() { return *(void **)((u8 *)*(void **)0x70039c + 0x9b); }

// 0x5c63f0 ZFFSearchLightGroup::Command(unsigned short cmd, void* data) [high].
static u32 THISCALL slg_Command(u8 *self, u32 cmdArg, u32 *data) {
  u16 cmd = (u16)cmdArg;
  u16 A = *(u16 *)0x714340;
  u16 B = *(u16 *)0x714344;
  if (cmd != A && cmd != B)
    return 0;
  if (data[0] == 0) {
    logLine(0xde, (const char *)0x6b45fc);       // "ZFFSearchLightGroup::Command, Ref rSpot = 0"
    return 0;
  }
  if (data[1] == 0) {
    logLine(0xe4, (const char *)0x6b4628);       // "ZFFSearchLightGroup::Command, Ref rGroup = 0"
    return 0;
  }
  u32 tab = (cmd == A) ? ext_5c6c50(self, data[0]) : ext_5c6bf0(self, data[0]);
  if (!tab) {
    logLine(0xf0, (const char *)0x6b4658);       // "rSpot not found in list of spots"
    return 0;
  }

  u8 *g = (u8 *)vcall<u32>(db(), 0x58, data[1]);
  if (g && vcall<bool>(g, 0x1e0, 0x100001u)) {
    u8 *g2 = (u8 *)vcall<u32>(db(), 0x58, data[1]);
    u32 cur = *(u32 *)(g2 + 8);
    if (!cur)
      return 0;
    while (cur) {
      u8 *el = (u8 *)cur;
      if (vcall<bool>(*(void **)(el + 0x54), 0x1e0, 0x2007f9u)) {
        u32 r = vcall<u32>(db(), 0x4c, *(u32 *)(el + 0x54));
        vcall<void>((void *)tab, 0x4, r);
      }
      vcall<void>(g2, 0x50, &cur);
    }
    return 0;
  }

  if (vcall<bool>(g, 0x1e0, 0x2007f9u)) {
    u32 r = vcall<u32>(db(), 0x4c, (u32)g);
    vcall<void>((void *)tab, 0x4, r);
  } else {
    logLine(0x118, (const char *)0x6b46b0);      // "rGroup was not a ref to a ZGROUP"
  }
  return 0;
}
PCREG(5c63f0, slg_Command);
