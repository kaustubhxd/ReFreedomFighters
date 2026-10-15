// batch1620.cpp - freeing sound objects (soundtimers thread, 2026-10-11).
#include "st.h"

u8 *THISCALL ZSoundObjectManager_ConvRefToPtr(u8 *self, u32 h);  // batch 1617 (not used here; keeps st.h small)

// 0x534090 ZSoundObjectManager::FreeObject(uint handle) [medium]: when the generator releases the handle (+0x10,
// true), the pool slot goes back on the free list, the object's handle (+0x10) is cleared, the slot table entry
// becomes -1 and the in-use count drops.
void THISCALL ZSoundObjectManager_FreeObject(u8 *self, u32 h) {
  if (!vcall<u8>(AT(void *, self, 0), 0x10, h)) return;
  u32 i = AT(u32 *, self, 4)[AT(u32, AT(u8 *, self, 0), 0x10) & h];
  AT(u32, self, 0xc + i * 4) = AT(u32, self, 0x1010);
  AT(u32, AT(u8 *, self, 8) + i * 0xfd, 0x10) = 0;
  AT(u32, self, 0x1010) = i;
  AT(u32 *, self, 4)[AT(u32, AT(u8 *, self, 0), 0x10) & h] = 0xffffffffu;
  AT(u32, self, 0x100c) -= 1;
}
PCREG(534090, ZSoundObjectManager_FreeObject);

// 0x5331c0 ZDllSound::DeleteSnd(uint handle) [high]: FreeObject on the manager at +0x8b.
void THISCALL ZDllSound_DeleteSnd(u8 *self, u32 h) { ZSoundObjectManager_FreeObject(self + 0x8b, h); }
PCREG(5331c0, ZDllSound_DeleteSnd);

// 0x5331d0 ZDllSound::DeleteSoundPtr(ZSoundObject*) [high]: own +0x114 (DeleteSnd) with the object's handle.
void THISCALL ZDllSound_DeleteSoundPtr(void *self, u8 *o) {
  if (o) vcall<void>(self, 0x114, AT(u32, o, 0x10));
}
PCREG(5331d0, ZDllSound_DeleteSoundPtr);

// 0x44b740 (map: ~ZSoundObject, low; by body the sound object's operator delete, cdecl): DLL +0x118
// (DeleteSoundPtr) when there is a DLL. The original's SEH frame has no handler work and is not reproduced.
extern "C" void ZSoundObject_Delete(void *o) {
  void *dll = AT(void *, G(u8 *, 0x70039c), 0x1a9f);
  if (dll) vcall<void>(dll, 0x118, o);
}
PCREG(44b740, ZSoundObject_Delete);

// 0x534d80 ZDllSound::ActorRemove(ZGEOM*) [high]: CEVENTCONTROLLER::RemoveActor (0x53b1b0) on +0x52fa if present.
extern "C" char ext_53b1b0[];
void THISCALL ZDllSound_ActorRemove(void *self, void *actor) {
  void *ec = AT(void *, self, 0x52fa);
  if (ec) ((void(THISCALL *)(void *, void *))(void *)ext_53b1b0)(ec, actor);
}
PCREG(534d80, ZDllSound_ActorRemove);
