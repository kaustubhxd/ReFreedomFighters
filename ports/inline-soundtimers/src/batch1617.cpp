// batch1617.cpp - sound object handles: ZSoundObjectManager::AllocateObject / ConvRefToPtr, ZDllSound::SRefToPtr
// (soundtimers thread). Every "handle" in the shout code (speech +0x13b, the PlaySound returns) is one of these.
//
// ZSoundObjectManager (ZDllSound +0x8b): +0 handle generator (vtable +4 new handle, +0x14 is-valid(handle); field
// +0x10 = index mask), +4 slot table (handle & mask -> pool index, -1 = free), +8 pool of 0x400 objects of 0xfd bytes,
// +0xc free list (next index per index), +0x100c objects in use, +0x1010 free-list head.
#include "st.h"

// 0x533e00 ZSoundObjectManager::AllocateObject() [high]: a pool object and a fresh handle; with all 0x400 in use logs
// "ERROR: ZSoundObjectManager::AllocateObject() - OUT OF MEMORY" (soundobjectmanager.cpp line 0xeb) and returns 0.
// The new object: +0x10 handle, +0 / +0x20 / +0x24 / +0x30..0x38 / +0xe0 / +0xe4 = 0, +0x28 = +0xe8 = 1.0.
u32 THISCALL ZSoundObjectManager_AllocateObject(u8 *self) {
  if (AT(u32, self, 0x100c) == 0x400) {
    void *log = G(void *, 0x700390);
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6a19bc, (u32)0xeb);
    typedef void (*Print)(void *, const char *, u32);
    (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6a1a10, 0x400);
    return 0;
  }
  void *gen = AT(void *, self, 0);
  u32 i = AT(u32, self, 0x1010);
  AT(u32, self, 0x1010) = AT(u32, self, 0xc + i * 4);
  u32 h = vcall<u32>(gen, 4);
  u32 mask = AT(u32, AT(u8 *, self, 0), 0x10);
  AT(u32 *, self, 4)[h & mask] = i;
  u32 o = i * 0xfd;
  AT(u32, AT(u8 *, self, 8) + o, 0x10) = h;
  AT(u32, AT(u8 *, self, 8) + o, 0x30) = 0;
  AT(u32, AT(u8 *, self, 8) + o, 0x34) = 0;
  AT(u32, AT(u8 *, self, 8) + o, 0x38) = 0;
  AT(u32, AT(u8 *, self, 8) + o, 0) = 0;
  u8 *p = AT(u8 *, self, 8) + o;
  AT(u32, p, 0x20) = 0;
  AT(u32, p, 0x24) = 0;
  AT(u32, p, 0x28) = 0x3f800000;
  p = AT(u8 *, self, 8) + o;
  AT(u32, p, 0xe0) = 0;
  AT(u32, p, 0xe4) = 0;
  AT(u32, p, 0xe8) = 0x3f800000;
  AT(u32, self, 0x100c) += 1;
  return h;
}
PCREG(533e00, ZSoundObjectManager_AllocateObject);

// 0x533fc0 ZSoundObjectManager::ConvRefToPtr(uint handle) [medium]: 0 for handle 0, an invalid handle (generator
// +0x14) or a free slot (-1); else pool + index x 0xfd.
u8 *THISCALL ZSoundObjectManager_ConvRefToPtr(u8 *self, u32 h) {
  void *gen = AT(void *, self, 0);
  if (!gen) return 0;
  if (!h) return 0;
  if (!vcall<u8>(gen, 0x14, h)) return 0;
  s32 i = AT(s32 *, self, 4)[AT(u32, AT(u8 *, self, 0), 0x10) & h];
  if (i == -1) return 0;
  return (u8 *)((u32)(i * 0xfd) + (u32)AT(u8 *, self, 8));
}
PCREG(533fc0, ZSoundObjectManager_ConvRefToPtr);

// 0x533be0 ZDllSound::SRefToPtr(uint handle) [high]: the manager at +0x8b.
u8 *THISCALL ZDllSound_SRefToPtr(u8 *self, u32 h) { return ZSoundObjectManager_ConvRefToPtr(self + 0x8b, h); }
PCREG(533be0, ZDllSound_SRefToPtr);
