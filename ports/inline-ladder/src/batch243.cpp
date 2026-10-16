// batch243.cpp - ZFFHERO::GetSpawnpointListFromTeam (inline-ladder thread, 2026-10-11). The body does not use this.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x592350 GetSpawnpointListFromTeam(int team) [GameCube reference, high], stdcall, ret 4, returns the list handle (EAX).
// team 3..6 pick the spawn-point list name SpawnPointList, SpawnPointList2, SpawnPointList3, SpawnPointList4. The
// database object (engine +0x9b) slot 0x138 gives the list manager; its slot 0x88(name, &out) fills out with the list.
// Other teams return 0.
static u32 STDCALL getSpawnpointListFromTeam(s32 team) {
  u32 out = 0;
  u32 idx = (u32)team - 3u;
  if (idx > 3u)
    return 0;
  const char *name = idx == 0 ? (const char *)0x6acfcc
                   : idx == 1 ? (const char *)0x6acfdc
                   : idx == 2 ? (const char *)0x6acfec
                   : (const char *)0x6acffc;
  u8 *db = (u8 *)U32(G(u32, 0x70039c), 0x9b);
  void *mgr = vcall<void *>(db, 0x138);
  vcall<void>(mgr, 0x88, name, &out);
  return out;
}
PCREG(592350, getSpawnpointListFromTeam);
