// batch1615.cpp - ZDllSound footstep lookups and the AI sound event (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *base(void *self) { return AT(u8 *, self, 0x5302); }

// 0x537270 ZDllSound::GetMapping(uint a, uint b) [high]: the footstep table. Header record (offset at base+0):
// +0x10 count (signed), +0x28 offset of the mapping-offset list. A mapping matches when its (+0xc, +0x10) pair is
// (a, b) in either order; returns its sound id (+8), 0 when none. FootStep passes (ground material, footwear).
u32 THISCALL ZDllSound_GetMapping(void *self, u32 a, u32 b) {
  if (!a || !b) return 0;
  u8 *bs = base(self);
  if (!bs) return 0;
  u8 *hdr = (u8 *)((u32)bs + AT(u32, bs, 0));
  s32 n = AT(s32, hdr, 0x10);
  if (n <= 0) return 0;
  u32 *lst = (u32 *)((u32)bs + AT(u32, hdr, 0x28));
  for (s32 i = 0;; i++, lst++) {
    u8 *m = (u8 *)((u32)bs + *lst);
    u32 x = AT(u32, m, 0xc);
    if ((a == x && b == AT(u32, m, 0x10)) || (a == AT(u32, m, 0x10) && b == x)) return AT(u32, m, 8);
    if (i + 1 >= n) return 0;
  }
}
PCREG(537270, ZDllSound_GetMapping);

// 0x536720 ZDllSound::FindMaterial(const char*) [high]: FindObject(header +0x24, header +0xc, name) (own vtable
// +0x1b0), 0 without data.
u32 THISCALL ZDllSound_FindMaterial(void *self, const char *name) {
  u8 *bs = base(self);
  if (!bs) return 0;
  u8 *hdr = (u8 *)((u32)bs + AT(u32, bs, 0));
  return vcall<u32>(self, 0x1b0, AT(u32, hdr, 0x24), AT(u32, hdr, 0xc), name);
}
PCREG(536720, ZDllSound_FindMaterial);

// 0x534da0 ZDllSound::AddEvent(ZGROUP* group, float* pos, int kind, uint sound, uint a5, uint a6) [high]: with a
// nonzero kind and an event controller (+0x52fa), takes a new event (0x53a9e0, not ported) and fills it: +0 kind,
// +0x18 database ref of the group, +4 a5, +8 a6, +0xc..0x14 position. The sound id is not used. Always returns true.
// These are the sound events the AI hears (CEVENTCONTROLLER; footsteps send kind 4 with the walker's ref as a5).
extern "C" char ext_53a9e0[];
u8 THISCALL ZDllSound_AddEvent(void *self, void *group, float *pos, u32 kind, u32 sound, u32 a5, u32 a6) {
  if (kind) {
    void *ec = AT(void *, self, 0x52fa);
    if (ec) {
      u8 *ev = ((u8 * (THISCALL *)(void *))(void *)ext_53a9e0)(ec);
      AT(u32, ev, 0) = kind;
      u32 ref = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x4c, group);
      AT(u32, ev, 0x18) = ref;
      AT(u32, ev, 4) = a5;
      AT(u32, ev, 8) = a6;
      AT(u32, ev, 0xc) = AT(u32, pos, 0);
      AT(u32, ev, 0x10) = AT(u32, pos, 4);
      AT(u32, ev, 0x14) = AT(u32, pos, 8);
    }
  }
  return 1;
}
PCREG(534da0, ZDllSound_AddEvent);
