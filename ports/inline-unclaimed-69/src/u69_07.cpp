// u69_07.cpp - area 69, group 7 (unclaimed-69 thread).
#include "ff.h"

extern "C" u8 THISCALL ext_45f3c0(void *self, void *lg);  // ZGEOM::Load(ZLoadGame*) (other area; stub in spec: GUESS)

static inline float readFloatUnaligned(const u8 *p) {
  float f;
  for (int q = 0; q < 4; ++q)
    ((u8 *)&f)[q] = p[q];
  return f;
}

// 0x4e74d0, ZParamParticle::Save(ZSaveGame*) (GC map high). thiscall, one stack arg (ret 4). Calls the save object's slot 0x68
// with this, slot 0x4c with the float at +0xc, slot 0x68 with this+0x10, slot 0x68 with this+0x1c, slot 0x4c with the float
// at +0x28.
static void THISCALL paramParticleSave(u8 *self, u8 *sg) {
  vcall<void>(sg, 0x68, (void *)self);
  vcall<void>(sg, 0x4c, readFloatUnaligned(self + 0xc));
  vcall<void>(sg, 0x68, (void *)(self + 0x10));
  vcall<void>(sg, 0x68, (void *)(self + 0x1c));
  vcall<void>(sg, 0x4c, readFloatUnaligned(self + 0x28));
}
PCREG(4e74d0, paramParticleSave);

// 0x44c110, ZSNDOBJ::Load(ZLoadGame*) (GC map high). thiscall, one stack arg (ret 4). After ZGEOM::Load succeeds (AL), slot
// 0x40 of the load object is called with this+0x1c and slot 0x68 with this+0x20; then the engine's slot 0x60 is called with
// the dword at this+0x1c and the result is stored at +0x18. Returns true; returns false when ZGEOM::Load fails.
static bool THISCALL sndObjLoad(u8 *self, u8 *lg) {
  if (!ext_45f3c0(self, lg))
    return false;
  vcall<void>(lg, 0x40, (void *)(self + 0x1c));
  vcall<void>(lg, 0x68, (void *)(self + 0x20));
  u8 *sys = G(u8 *, 0x70039c);
  u8 *engine = *(u8 **)(sys + 0x9b);
  u32 value = vcall<u32>(engine, 0x60, *(u32 *)(self + 0x1c));
  *(u32 *)(self + 0x18) = value;
  return true;
}
PCREG(44c110, sndObjLoad);
