// batch8803.cpp - hit-reaction thread, batch 8803: the script native DieByForce (the soldier script's death call).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" float *THISCALL ext_5003d0(void *args, u32 i);      // script argument i (8-byte value slot)

typedef void(THISCALL *vDie)(void *self, const float *pos, const float *force, float strength, u32 killer);

// 0x506a80 ZActorIf::DieByForce(OpaqueCallParameters_t&) (GC 801a3ba0, actor_if.cpp; not in the name map). Script args
// 0-2 hit point, 3-5 force, 6 strength (float), 7 killer (dword); the actor is [this+0x18]; calls its slot 0x668
// (ZFFActor::DieByForce 0x59f3e0 for soldiers). Arguments are fetched in the order 2, 1, 0, 5, 4, 3, 7, 6.
static void THISCALL actorIfDieByForce(u8 *self, u8 *call) {
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
  u32 *a7 = (u32 *)ext_5003d0(*(void **)(call + 4), 7);
  float *a6 = ext_5003d0(*(void **)(call + 4), 6);
  void *actor = *(void **)(self + 0x18);
  ((vDie)VT(actor, 0x668))(actor, pos, force, *a6, *a7);
}
PCREG(506a80, actorIfDieByForce);
