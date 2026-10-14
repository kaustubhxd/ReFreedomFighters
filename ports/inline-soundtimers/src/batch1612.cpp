// batch1612.cpp - ZDllSound sound-set lookups behind every "*Name*" shout pattern (soundtimers thread).
//
// ZDllSound (PC): +0x5302 = base of the loaded sound data; sound sets and members are offsets into it.
// SSoundSet: +0 type (3 = sound set), +8 u16 member count, +0x10 offset of the member-offset table.
#include "st.h"

extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);  // striwcmp (batch 54): 0 = match, '*' wildcard

// 0x5370d0 ZDllSound::GetIdxFromSoundSet(SSoundSet*, const char*) [high] and
// 0x537160 ZDllSound::GetIdxFromSoundSet_Rec(SSoundSet*, const char*, uint depth) [high]: the first direct member
// whose name (own vtable +0x1e8(member)) matches the pattern; returns its offset, 0 when none. The scan stops at a
// zero member offset. The _Rec form only refuses depth 0; it does not recurse (same body on PC as on GC).
static u32 scan(void *self, u8 *set, const char *pat) {
  u8 *base = AT(u8 *, self, 0x5302);
  if (!base) return 0;
  for (u32 i = 0; i < AT(u16, set, 8); i++) {
    u32 tab = AT(u32, set, 0x10);
    if (!tab) return 0;
    u32 *t = (u32 *)(AT(u8 *, self, 0x5302) + tab);
    u32 m = t[i];
    if (!m) return 0;
    const char *name = vcall<const char *>(self, 0x1e8, AT(u8 *, self, 0x5302) + m);
    if (!name) return 0;
    if (ext_4cc850(name, pat) == 0) return t[i];
  }
  return 0;
}

u32 THISCALL ZDllSound_GetIdxFromSoundSet(void *self, u8 *set, const char *pat) {
  if (!set || !pat) return 0;
  return scan(self, set, pat);
}
PCREG(5370d0, ZDllSound_GetIdxFromSoundSet);

u32 THISCALL ZDllSound_GetIdxFromSoundSet_Rec(void *self, u8 *set, const char *pat, u32 depth) {
  if (depth < 1) return 0;
  if (!set || !pat) return 0;
  return scan(self, set, pat);
}
PCREG(537160, ZDllSound_GetIdxFromSoundSet_Rec);

// 0x536650 ZDllSound::FindInSoundSet(int set, const char* pattern) [high]: set 0 -> 0 (EAX = the 0 argument);
// no pattern or no data -> 0; not a sound set (type != 3) -> logs "ERROR: FindInSoundSet - index passed is not a
// sound set" (sound.cpp line 0x39e) and 0. Empty pattern -> own vtable +0x1c0(set) (not traced; presumably a random
// member); otherwise +0x1c4(set, pattern, 2) = GetIdxFromSoundSet_Rec with depth 2.
u32 THISCALL ZDllSound_FindInSoundSet(void *self, u32 set, const char *pat) {
  if (!set) return set;
  if (!pat || !AT(u8 *, self, 0x5302)) return 0;
  u32 pi = (u32)AT(u8 *, self, 0x5302) + set;  // integer add: the original tests the sum for 0
  if (!pi) return 0;
  u8 *p = (u8 *)pi;
  if (AT(u32, p, 0) != 3) {
    void *log = G(void *, 0x700390);
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6a1e2c, (u32)0x39e);
    typedef void (*Print)(void *, const char *);
    (*(Print *)(*(u8 **)ch + 0x30))(ch, (const char *)0x6a2058);
    return 0;
  }
  if (!*pat) return vcall<u32>(self, 0x1c0, p);
  return vcall<u32>(self, 0x1c4, p, pat, (u32)2);
}
PCREG(536650, ZDllSound_FindInSoundSet);
