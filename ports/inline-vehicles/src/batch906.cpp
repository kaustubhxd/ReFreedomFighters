// batch906.cpp - vehicles thread, batch 906: ZHeli::UpdateCannonSound.
#include "ff.h"

extern "C" void THISCALL ext_4db2c0(void *geom, float *mat, float *pos);  // ZBaseGeom::GetMatPos
extern "C" u32 THISCALL ext_43ec00(void *grp, float *mat, float *pos, u32 snd, u32 a, u32 b, u32 c);
// ZGROUP::AddSound3d(float*, float*, int, int, unsigned, unsigned) -> sound handle
extern "C" void THISCALL ext_46b440(void *node, float a, float b);  // sound node fade (0 over 0.1 s), name unknown

static inline void *world() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// One wing-gun loop: when the gun (group id at `gun`) has no handle yet (`h`), start sound set +0x495 at the
// gun's matrix/position (AddSound3d), then tune the node (world slot 0x60 handle -> node).
static inline u8 *startGunLoop(u8 *s, u32 gun, u32 h) {
  u32 id = *(u32 *)(s + gun);
  if (!id || *(u32 *)(s + h))
    return 0;
  u8 *g = vcall<u8 *>(world(), 0x58, id);
  if (!g)
    return 0;
  float mat[9], pos[3];
  ext_4db2c0(*(void **)(g + 8), mat, pos);
  u32 snd = ext_43ec00(g, mat, pos, *(u32 *)(s + 0x495), 0, 0, 0);
  *(u32 *)(s + h) = snd;
  return vcall<u8 *>(world(), 0x60, snd);
}

static inline void stopGunLoop(u8 *s, u32 h) {
  u32 snd = *(u32 *)(s + h);
  if (!snd)
    return;
  u8 *n = vcall<u8 *>(world(), 0x60, snd);
  if (n)
    ext_46b440(n, 0.0f, 0.1f);
  *(u32 *)(s + h) = 0;
}

// 0x51d6f0 ZHeli::UpdateCannonSound(). While firing (+0x469): the gun group +0x409 gets a looping shot sound
// (handle +0x4a1) with +0x78 = 0.1 (start delay), pitch +0x60 = 25 - old +0x64 and +0x64 = 25; the gun group
// +0x40d gets one (handle +0x49d) with +0x60 = -old +0x64 and +0x64 = 0. Both copy the heli's +0x1f1 into node
// +0x84. Not firing: both loops fade out (0x46b440(0, 0.1)) and the handles are cleared.
static void THISCALL heliUpdateCannonSound(u8 *s) {
  if (!*(u32 *)(s + 0x469)) {
    stopGunLoop(s, 0x4a1);
    stopGunLoop(s, 0x49d);
    return;
  }
  u8 *n = startGunLoop(s, 0x409, 0x4a1);
  if (n) {
    *(u32 *)(n + 0x78) = 0x3dcccccd;
    *(s32 *)(n + 0x60) = 0x19 - *(s32 *)(n + 0x64);
    *(u32 *)(n + 0x64) = 0x19;
    *(u32 *)(n + 0x84) = *(u32 *)(s + 0x1f1);
  }
  n = startGunLoop(s, 0x40d, 0x49d);
  if (n) {
    s32 p = *(s32 *)(n + 0x64);
    *(u32 *)(n + 0x64) = 0;
    *(s32 *)(n + 0x60) = -p;
    *(u32 *)(n + 0x84) = *(u32 *)(s + 0x1f1);
  }
}
PCREG(51d6f0, heliUpdateCannonSound);
