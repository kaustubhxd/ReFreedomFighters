// batch1635.cpp - ZDllSound::FindWave and GetObjFromSoundSet (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *base(void *self) { return AT(u8 *, self, 0x5302); }

// 0x536950 ZDllSound::FindWave(const char* name) [high]: FindObjectIdx(header +0x18, header +0, name) (vtable +0x1b0).
u32 THISCALL ZDllSound_FindWave(u8 *self, const char *name) {
  u8 *b = base(self);
  if (!b) return 0;
  u8 *h = (u8 *)((u32)b + AT(u32, b, 0));
  return vcall<u32>(self, 0x1b0, AT(u32, h, 0x18), AT(u32, h, 0), name);
}
PCREG(536950, ZDllSound_FindWave);

// 0x537340 ZDllSound::GetObjFromSoundSet(set, const char* name) [high]: the member id from the DLL's slot +0x1d8
// (name of that slot not traced: GUESS, a lookup of the set's member by name), then GetSoundObject(id) (slot +0x54).
// 0 when the lookup gives 0.
u32 THISCALL ZDllSound_GetObjFromSoundSet(u8 *self, u32 set, const char *name) {
  u32 id = vcall<u32>(self, 0x1d8, set, name);
  if (!id) return 0;
  return (u32)vcall<u8 *>(self, 0x54, id);
}
PCREG(537340, ZDllSound_GetObjFromSoundSet);
