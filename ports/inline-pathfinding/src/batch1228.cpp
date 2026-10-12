// batch1228.cpp - pathfinding tree: ZActor path setters (each a single store into the actor, thiscall, ret 4).
// Field names are the setters' names; the offsets are the store targets in the exe.
#include "pf.h"

static void THISCALL actorSetMaxPathLen(u8 *self, float v) { *(float *)(self + 0x6b6) = v; }      // 0x47be90
PCREG(47be90, actorSetMaxPathLen);

static void THISCALL actorSetPathNotify(u8 *self, float v) { *(float *)(self + 0x6ba) = v; }      // 0x47bfc0
PCREG(47bfc0, actorSetPathNotify);

static void THISCALL actorSetPathNotifySyncToCycle(u8 *self, u32 on) {                              // 0x47bfe0
  self[0x6be] = (u8)on;
}
PCREG(47bfe0, actorSetPathNotifySyncToCycle);

static void THISCALL actorSetStayInsidePath(u8 *self, u32 on) { self[0x6c4] = (u8)on; }            // 0x47c130
PCREG(47c130, actorSetStayInsidePath);
