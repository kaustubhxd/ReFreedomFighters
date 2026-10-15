// batch1220.cpp - pathfinding tree: ZActor pathfinder entry points (path finished notice, special links for a box).
//
// ZActor fields used here (PC): +0x691 int "path request in flight" (> 0 = keep waiting), +0x6ba u32 saved response,
// +0x6be u8 "path found" flag, +0x690 u8 pathfinder enabled (batch 1200), +0x5b2 ZPathfinder3* (batch 1200).
#include "pf.h"

extern "C" void THISCALL ext_4db7c0(void *geom, float *size);      // ZBaseGeom::GetSize

#define MSGS (*(void **)((u8 *)g_pSysInterface + 0x9b))
#define ZACTOR_FILE ((const char *)0x68a7c4)                     // engine\geomsextend\zactor.cpp
#define PATH_MSG G(u16, 0x6ffa28)                                  // message id sent when a path is finished

// 0x4798d0 ZActor::OnPathFinished(unsigned int arg) [map high; GameCube reference; vtable slot 396]. thiscall, ret 4.
// Unless a request is still in flight (+0x691 > 0), the path-finished message (PATH_MSG, arg, 0) goes to the actor's
// own message handler (vtable +0x128); the saved response is cleared and the found flag reset.
static void THISCALL actorOnPathFinished(u8 *self, u32 arg) {
  if (*(int *)(self + 0x691) > 0) return;
  vcall<void>(self, 0x128, (u32)PATH_MSG, arg, 0);
  *(u32 *)(self + 0x6ba) = 0;
  self[0x6be] = 0;
}
PCREG(4798d0, actorOnPathFinished);

// 0x47bff0 ZActor::SetPathfinderLinks(unsigned int box, bool on) [map high; GameCube reference; zactor.cpp lines 0x4b9 / 0x4bf].
// thiscall, ret 8. The actor's pathfinder (vtable +0x5d0) must exist (warning otherwise); the box is the geom named by
// the message-table reference `box` (+0x58), its size (ZBaseGeom::GetSize) and world position (geom vtable +0x80, a
// matrix and a point), then the pathfinder switches the special links there (vtable +0x21c).
static void THISCALL actorSetPathfinderLinks(u8 *self, u32 box, bool on) {
  void *pf = vcall<void *>(self, 0x5d0);
  if (!pf) {
    void *r = vcall<void *>(G(void *, 0x700390), 0x20, ZACTOR_FILE, 0x4b9);
    typedef void (*fn)(void *, const char *);
    (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68aa70);
    return;
  }
  u8 *geom = vcall<u8 *>(MSGS, 0x58, box);
  if (!geom) {
    void *r = vcall<void *>(G(void *, 0x700390), 0x20, ZACTOR_FILE, 0x4bf);
    typedef void (*fn)(void *, const char *);
    (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68aaa0);
    return;
  }
  float size[3], mat[9], pos[3];
  ext_4db7c0(*(void **)(geom + 8), size);
  vcall<void>(geom, 0x80, mat, pos);
  vcall<void>(pf, 0x21c, pos, size, (u32)on);
}
PCREG(47bff0, actorSetPathfinderLinks);
