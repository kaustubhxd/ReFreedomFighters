// batch1632.cpp - ZDllSound lookup wrappers and the sound-object allocator front (soundtimers thread, 2026-10-11).
// The find functions are thin: they read the header of the loaded sound data (base +0 gives the header offset) and
// pass three fields to the DLL's own FindObject / FindObjectIdx (vtable +0x1ac / +0x1b0) with the name.
#include "st.h"

extern "C" char ext_533da0[];  // ZRefAlloc::AddToChain (medium), thiscall, two u32 args, result in EAX
typedef u32(THISCALL *AddToChainFn)(void *self, u32 a, u32 b);
u32 THISCALL ZSoundObjectManager_AllocateObject(u8 *self);  // batch 1617

static inline u8 *base(void *self) { return AT(u8 *, self, 0x5302); }
static inline u8 *hdrOf(u8 *b) { return (u8 *)((u32)b + AT(u32, b, 0)); }

// 0x535490 ZDllSound::AddToRefChain(uint a, uint b) [high]: jumps to ZRefAlloc::AddToChain on the object at +0x109f.
u32 THISCALL ZDllSound_AddToRefChain(u8 *self, u32 a, u32 b) {
  return ((AddToChainFn)(void *)ext_533da0)(self + 0x109f, a, b);
}
PCREG(535490, ZDllSound_AddToRefChain);

// 0x535570 ZDllSound::AllocateObject() [high]: a fresh sound object from the manager at +0x8b; the object's handle is
// resolved once through the database (vtable +0x60) and the result is not returned (the original's own behaviour).
void THISCALL ZDllSound_AllocateObject(u8 *self) {
  u32 h = ZSoundObjectManager_AllocateObject(self + 0x8b);
  if (!h) return;
  vcall<void *>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x60, h);
}
PCREG(535570, ZDllSound_AllocateObject);

// 0x5372f0 ZDllSound::GetName(int id) [medium]: GetName(GetSoundObject(id)) through the DLL's own slots +0x54 and +0x1e8.
const char *THISCALL ZDllSound_GetNameById(u8 *self, s32 id) {
  u8 *o = vcall<u8 *>(self, 0x54, (u32)id);
  return vcall<const char *>(self, 0x1e8, o);
}
PCREG(5372f0, ZDllSound_GetNameById);

// 0x5366f0 FindMapping(name): FindObject(header +0x28, header +0x10, name) (vtable +0x1ac); no data gives 0.
u32 THISCALL ZDllSound_FindMapping(u8 *self, const char *name) {
  u8 *b = base(self);
  if (!b) return 0;
  u8 *h = hdrOf(b);
  return vcall<u32>(self, 0x1ac, AT(u32, h, 0x28), AT(u32, h, 0x10), name);
}
PCREG(5366f0, ZDllSound_FindMapping);

// 0x536840 FindRoom(name): FindObject(header +0x2c, header +0x14, name).
u32 THISCALL ZDllSound_FindRoom(u8 *self, const char *name) {
  u8 *b = base(self);
  if (!b) return 0;
  u8 *h = hdrOf(b);
  return vcall<u32>(self, 0x1ac, AT(u32, h, 0x2c), AT(u32, h, 0x14), name);
}
PCREG(536840, ZDllSound_FindRoom);

// 0x536870 FindSound(name): FindObjectIdx(header +0x1c, header +4, name) (vtable +0x1b0).
u32 THISCALL ZDllSound_FindSound(u8 *self, const char *name) {
  u8 *b = base(self);
  if (!b) return 0;
  u8 *h = hdrOf(b);
  return vcall<u32>(self, 0x1b0, AT(u32, h, 0x1c), AT(u32, h, 4), name);
}
PCREG(536870, ZDllSound_FindSound);

// 0x536920 FindSoundSet(name): FindObjectIdx(header +0x20, header +8, name).
u32 THISCALL ZDllSound_FindSoundSet(u8 *self, const char *name) {
  u8 *b = base(self);
  if (!b) return 0;
  u8 *h = hdrOf(b);
  return vcall<u32>(self, 0x1b0, AT(u32, h, 0x20), AT(u32, h, 8), name);
}
PCREG(536920, ZDllSound_FindSoundSet);
