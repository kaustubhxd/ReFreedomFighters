// batch1618.cpp - wave length (the "time left" every shout starts with) and FindObjectIdx (soundtimers thread).
#include "st.h"

// 0x537860 ZDllSound::GetWaveDuration(SWave*) [high]: the wave record's float +0xc (seconds), 0.0 for null.
float THISCALL ZDllSound_GetWaveDurationW(void *self, u8 *w) {
  if (!w) return 0.0f;
  return AT(float, w, 0xc);
}
PCREG(537860, ZDllSound_GetWaveDurationW);

// 0x5377d0 ZDllSound::GetWaveDuration(int id) [high]: a wave's own length, a sound's wave length (+8 -> wave); any
// other record logs "Unable to get duration for object %s" (sound.cpp line 0x3ed) and gives 0.0. No pitch or
// looping adjustment: this is what AddNewPlayBuffer stores as the time left (+0x70), and so what
// PlaySound_Enum_GetTime returns and what the 0.2 s / "still talking" checks compare against.
float THISCALL ZDllSound_GetWaveDuration(void *self, u32 id) {
  u8 *b = AT(u8 *, self, 0x5302);
  if (!b) return 0.0f;
  u8 *rec = (u8 *)((u32)b + id);
  u32 t = AT(u32, rec, 0);
  if (t == 2) {
    rec = (u8 *)((u32)b + AT(u32, rec, 8));
  } else if (t != 1) {
    void *log = G(void *, 0x700390);
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6a1e2c, (u32)0x3ed);
    const char *nm = vcall<const char *>(self, 0x1e8, rec);
    typedef void (*Print)(void *, const char *, const char *);
    (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6a2090, nm);
    return 0.0f;
  }
  return vcall<float>(self, 0x1e0, rec);
}
PCREG(5377d0, ZDllSound_GetWaveDuration);

// 0x5367c0 ZDllSound::FindObjectIdx(uint list, uint count, const char* name) [high]: the first entry of an offset
// list (base + list) whose record name (+4) matches `name` with striwcmp; 0 for no data, an empty name or no match.
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);
u32 THISCALL ZDllSound_FindObjectIdx(void *self, u32 list, u32 count, const char *name) {
  u8 *b = AT(u8 *, self, 0x5302);
  if (!b) return 0;
  if (!name || !*name) return 0;
  u32 *l = (u32 *)((u32)b + list);
  for (u32 i = 0; i < count; i++) {
    u8 *bb = AT(u8 *, self, 0x5302);
    const char *nm = (const char *)((u32)bb + AT(u32, (u32)bb + l[i], 4));
    if (ext_4cc850(nm, name) == 0) return l[i];
  }
  return 0;
}
PCREG(5367c0, ZDllSound_FindObjectIdx);
