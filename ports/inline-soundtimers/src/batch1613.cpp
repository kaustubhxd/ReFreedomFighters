// batch1613.cpp - ZDllSound::AddSound3d: where flag 4 ("test against the sound graph") comes from (soundtimers).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
typedef u32(THISCALL *AllocFn)(void *mgr);
typedef void(THISCALL *Fn0)(void *);
extern "C" char ext_533e00[], ext_44b610[];  // ZSoundObjectManager::AllocateObject [high]; pre-free method
extern "C" void ext_44b740(void *o);         // frees a ZSoundObject (cdecl)

// 0x535150 ZDllSound::AddSound3d(ZGEOM* geom, int sound, float* mat, float* pos) [high]. Allocates a sound object
// (manager at +0x8b) and initialises it: +0x40 flags = 6 then |= 0x80 (so flag 4 is ON for every 3D sound made here),
// +4 type 3, +8 = 1, +0x7c sound id, +0x80 sound id, volume +0x84 = +0x88 = 1.0, +0x44 = +0x48 = 360.0,
// +0x58 = 1.0, +0x6c = engine time (sys+0x1c), +0x3c = database reference of the geom (+0x4c(geom)), position
// +0x14..0x1c = pos, +0x20..0x28 = the first 3 floats of mat, the rest (+0x2c category, +0x4c, +0x50, +0x60..+0x78,
// +0x8c, +0xd0, fade state +0xec..) zeroed. Then own vtable +0x4c(object) (adds it to the play list, inferred); on
// failure the object is freed and 0 returned. Returns the handle.
// The original guards two stores with "this != &local" checks (inlined assignments); they are never equal and are
// not reproduced.
u32 THISCALL ZDllSound_AddSound3d(void *self, void *geom, u32 sound, float *mat, float *pos) {
  u32 h = ((AllocFn)(void *)ext_533e00)((u8 *)self + 0x8b);
  if (!h) return 0;
  u8 *o = vcall<u8 *>(AT(void *, sys(), 0x9b), 0x60, h);
  AT(u32, o, 0x40) &= 0xfffffff7u;
  AT(u32, o, 8) = 0xffffffffu;
  AT(u32, o, 0xd0) = 0;
  AT(u32, o, 0x6c) = 0;
  AT(u32, o, 0x80) = sound;
  AT(u32, o, 0x70) = 0;
  AT(u32, o, 8) = 1;
  AT(u32, o, 0x84) = 0x3f800000;
  AT(u32, o, 0x88) = 0x3f800000;
  AT(u32, o, 0x44) = 0x43b40000;
  AT(u32, o, 0x48) = 0x43b40000;
  AT(u32, o, 0x4c) = 0;
  AT(u32, o, 0x50) = 0;
  AT(u32, o, 0x2c) = 0;
  AT(u32, o, 0x78) = 0;
  AT(u32, o, 0x8c) = 0;
  AT(u32, o, 0x64) = 0;
  AT(u32, o, 0x68) = 0;
  AT(u32, o, 0x60) = 0;
  AT(u32, o, 0x40) = 6;
  AT(u32, o, 0x6c) = AT(u32, sys(), 0x1c);
  AT(u32, o, 4) = 3;
  AT(u32, o, 0x7c) = sound;
  u32 ref = vcall<u32>(AT(void *, sys(), 0x9b), 0x4c, geom);
  AT(u32, o, 0x40) |= 0x80;
  AT(u32, o, 0x3c) = ref;
  AT(u32, o, 8) = 1;
  AT(u32, o, 0x2c) = 0;
  AT(u32, o, 0x58) = 0x3f800000;
  AT(u8, o, 0xec) = 0;
  AT(u32, o, 0xed) = 0;
  AT(u32, o, 0xf1) = 0;
  AT(u32, o, 0xf5) = 0;
  AT(u32, o, 0x14) = AT(u32, pos, 0);
  AT(u32, o, 0x18) = AT(u32, pos, 4);
  AT(u32, o, 0x1c) = AT(u32, pos, 8);
  AT(u32, o, 0x20) = AT(u32, mat, 0);
  AT(u32, o, 0x24) = AT(u32, mat, 4);
  AT(u32, o, 0x28) = AT(u32, mat, 8);
  if (vcall<u8>(self, 0x4c, o)) return h;
  ((Fn0)(void *)ext_44b610)(o);
  ext_44b740(o);
  return 0;
}
PCREG(535150, ZDllSound_AddSound3d);

// 0x534fd0 ZDllSound::AddSound2d(int sound, uint type) [high]: a 2D sound object: geom reference = the database's
// own (+0xadc), flags +0x40 = 6 when type is 4 else 2 (bits 0x30 cleared), +8 = type, min 10000 / max 12800,
// volume 1.0, +0x6c = engine time; then +0x4c(object) as in AddSound3d. ZGROUP::AddSound2d passes type 4, so its
// sounds also get flag 4 (but a 2D sound has no position; see docs/31 GetAudiable for how flag 4 is used).
u32 THISCALL ZDllSound_AddSound2d(void *self, u32 sound, u32 type) {
  u32 h = ((AllocFn)(void *)ext_533e00)((u8 *)self + 0x8b);
  if (!h) return 0;
  u8 *o = vcall<u8 *>(AT(void *, sys(), 0x9b), 0x60, h);
  void *db = AT(void *, sys(), 0x9b);
  AT(u32, o, 0x3c) = vcall<u32>(db, 0x4c, AT(u32, db, 0xadc));
  AT(u32, o, 0x40) = 2;
  AT(u32, o, 0x64) = 0;
  AT(u32, o, 0x60) = 0;
  AT(u32, o, 0x68) = 0;
  AT(u32, o, 0x84) = 0x3f800000;
  AT(u32, o, 0x88) = 0x3f800000;
  AT(u32, o, 0x44) = 0x43b40000;
  AT(u32, o, 0x40) = (type == 4) * 4 + 2;
  AT(u32, o, 0x40) &= 0xffffffcfu;
  AT(u32, o, 0x48) = 0x43b40000;
  AT(u32, o, 0x4c) = 0;
  AT(u32, o, 0x50) = 0;
  AT(u32, o, 0x54) = 0x461c4000;  // 10000
  AT(u32, o, 0x5c) = 0x46480000;  // 12800
  AT(u32, o, 0x2c) = 0;
  AT(u32, o, 0x78) = 0;
  AT(u32, o, 0x8c) = 0;
  AT(u32, o, 4) = 3;
  AT(u32, o, 0x80) = sound;
  AT(u8, o, 0xec) = 0;
  AT(u32, o, 0xed) = 0;
  AT(u32, o, 0xf1) = 0;
  AT(u32, o, 0xf5) = 0;
  AT(u32, o, 0x64) = 0;
  AT(u32, o, 0x60) = 0;
  AT(u32, o, 0x6c) = AT(u32, sys(), 0x1c);
  AT(u32, o, 0x7c) = sound;
  AT(u32, o, 4) = 3;
  AT(u32, o, 0x8c) = 0;
  AT(u32, o, 8) = type;
  if (vcall<u8>(self, 0x4c, o)) return h;
  ((Fn0)(void *)ext_44b610)(o);
  ext_44b740(o);
  return 0;
}
PCREG(534fd0, ZDllSound_AddSound2d);
