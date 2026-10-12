// batch8802.cpp - hit-reaction thread, batch 8802: the script native StartAndHitRagdoll (EnemySoldier fn#24 calls it on
// a LIVE soldier hit by an explosion, damage type 4, at 0x5eab; a second call at 0x60e3 is gated by d[0x404], which the
// C01A scripts only ever set to 0).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" float *THISCALL ext_5003d0(void *args, u32 i);      // script argument i (8-byte value slot)
extern "C" void *THISCALL ext_5002f0(void *ret, u32 v);        // script return value (sets the bool)
extern "C" void THISCALL ext_466c10(void *self, const float *pos, const float *force, float strength);  // ZIKLNKOBJ::HitRagdoll

typedef u8(THISCALL *vB0)(void *self);
typedef u8(THISCALL *vBUU)(void *self, u32 a, u32 b);

// 0x55cae0 ZFFActorIf::StartAndHitRagdoll (GC 80129c0c by structure; not in the name map). Script args 0-2 hit point,
// 3-5 force, 6 strength. The actor is [this+0x1c]. When its bone modifier (+0x6c) has no active ragdoll (slot 0x34,
// IsRagdollActive), ActivateRagdoll(1, 1) (actor slot 0x354); when one is active or starts, HitRagdoll(pos, force,
// strength). Returns the Bool "active or started" through the call's return slot ([call+8] value 0).
static void THISCALL startAndHitRagdoll(u8 *self, u8 *call) {
  float *a2 = ext_5003d0(*(void **)(call + 4), 2);
  float *a1 = ext_5003d0(*(void **)(call + 4), 1);
  float *a0 = ext_5003d0(*(void **)(call + 4), 0);
  float pos[3], force[3];
  pos[0] = *a0;
  pos[1] = *a1;
  pos[2] = *a2;
  float *a5 = ext_5003d0(*(void **)(call + 4), 5);
  float *a4 = ext_5003d0(*(void **)(call + 4), 4);
  float *a3 = ext_5003d0(*(void **)(call + 4), 3);
  force[0] = *a3;
  force[1] = *a4;
  force[2] = *a5;
  u8 *actor = *(u8 **)(self + 0x1c);
  void *bm = *(void **)(actor + 0x6c);
  u8 ok = ((vB0)VT(bm, 0x34))(bm);
  if (!ok) {
    actor = *(u8 **)(self + 0x1c);
    ok = ((vBUU)VT(actor, 0x354))(actor, 1, 1);
    if (!ok) goto done;
  }
  {
    float *a6 = ext_5003d0(*(void **)(call + 4), 6);
    ext_466c10(*(void **)(self + 0x1c), pos, force, *a6);
  }
done:
  ext_5002f0(ext_5003d0(*(void **)(call + 8), 0), ok);
}
PCREG(55cae0, startAndHitRagdoll);
