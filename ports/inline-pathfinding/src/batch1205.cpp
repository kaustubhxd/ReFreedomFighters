// batch1205.cpp - pathfinding tree: ZPathfinderControl (the event that switches special links in boxes on and off).
// Layout (PC, /Zp1): +4 flags (bit 0x40 cleared on load/save), +0x48 REFTAB* of box geoms, +0x4c / +0x4e / +0x50 u16
// message ids (toggle / on / off), +0x52 bool state, +0x53 ZPathfinder3* (the geom ref "rEnemyPathFinder3").
#include "pf.h"

extern "C" void THISCALL ext_4c5770(void *self, u32 on);          // ZPathfinderControl::SetPFLinkState (below)
extern "C" void THISCALL ext_4db7c0(void *geom, float *size);     // ZBaseGeom::GetSize
extern "C" u32 THISCALL ext_4e5e40(void *rd);                     // DBREAD::operator unsigned short
extern "C" u32 THISCALL ext_4e5e60(void *rd);                     // DBREAD::operator unsigned int
extern "C" void THISCALL ext_4e6330(void *rd, void *reftab);      // DBREAD::GetRefTab

#define MSGS (*(void **)((u8 *)g_pSysInterface + 0x9b))

// 0x4c5770 ZPathfinderControl::SetPFLinkState(bool) [map high]. thiscall, ret 4. For every box geom in the REFTAB
// (vtable +0x4c starts an iterator, +0x5c returns the next ref; iterator word 0 = valid): resolve the ref (message
// table +0x58), take its size (ZBaseGeom::GetSize of geom+8) and world position (geom vtable +0x80 (matrix, pos)),
// and call ZPathfinder3::EnableSpecialLinks(pos, size, on) (vtable +0x21c) on the level's pathfinder.
static void THISCALL setPFLinkState(u8 *self, u32 on) {
  if (!*(void **)(self + 0x48)) return;
  u32 it[3];
  vcall<void>(*(void **)(self + 0x48), 0x4c, it);
  void *ref = vcall<void *>(*(void **)(self + 0x48), 0x5c, it);
  while (it[0]) {
    u8 *geom = vcall<u8 *>(MSGS, 0x58, ref);
    float size[3], mat[9], pos[3];
    ext_4db7c0(*(void **)(geom + 8), size);
    vcall<void>(geom, 0x80, mat, pos);
    vcall<void>(*(void **)(self + 0x53), 0x21c, pos, size, on);
    ref = vcall<void *>(*(void **)(self + 0x48), 0x5c, it);
  }
}
PCREG(4c5770, setPFLinkState);

// 0x4c54d0 ZPathfinderControl::Command(unsigned short, void*) [map high; slot 17]. thiscall, ret 8, returns 1.
// Toggle / on / off messages. The toggle pushes the new state in AL only: the upper bits of the pushed EAX are left
// over (message word, caller's EAX). SetPFLinkState only passes it on as a bool, so the port pushes 0/1 and the spec
// compares the low byte of that argument.
static u32 THISCALL pfcCommand(u8 *self, u32 msg, void *) {
  u16 m = (u16)msg;
  if (m == *(u16 *)(self + 0x4c)) {
    u8 v = self[0x52] == 0;
    self[0x52] = v;
    ext_4c5770(self, v);
    return 1;
  }
  if (m == *(u16 *)(self + 0x4e)) {
    self[0x52] = 1;
    ext_4c5770(self, 1);
    return 1;
  }
  if (m == *(u16 *)(self + 0x50)) {
    self[0x52] = 0;
    ext_4c5770(self, 0);
  }
  return 1;
}
PCREG(4c54d0, pfcCommand);

// Resolve "rEnemyPathFinder3": message table +0x138 gives the scene object, its +0x88 (name, &ref) finds the ref,
// message table +0x58 turns the ref into the geom.
static inline void *findEnemyPathFinder() {
  void *scene = vcall<void *>(MSGS, 0x138);
  u32 ref = 0;
  vcall<void>(scene, 0x88, (const char *)0x68a9e0, &ref);
  return vcall<void *>(MSGS, 0x58, ref);
}

// 0x4c5620 ZPathfinderControl::Init2() [map medium; slot 3]. thiscall.
static void THISCALL pfcInit2(u8 *self) {
  *(void **)(self + 0x53) = findEnemyPathFinder();
  ext_4c5770(self, self[0x52]);
}
PCREG(4c5620, pfcInit2);

// 0x4c5680 ZPathfinderControl::Load2() [map medium; slot 12]. thiscall: re-applies the saved state.
static void THISCALL pfcLoad2(u8 *self) { ext_4c5770(self, self[0x52]); }
PCREG(4c5680, pfcLoad2);

// 0x4c5690 ZPathfinderControl::Load(ZLoadGame*) [map high; slot 8]. thiscall, ret 4, returns true.
static bool THISCALL pfcLoad(u8 *self, void *lg) {
  *(u32 *)(self + 4) &= ~0x40u;
  *(void **)(self + 0x53) = findEnemyPathFinder();
  vcall<void>(lg, 0x68, self + 0x52);
  return true;
}
PCREG(4c5690, pfcLoad);

// 0x4c5750 ZPathfinderControl::Save(ZSaveGame*) [map high; slot 7]. thiscall, ret 4, returns true.
static bool THISCALL pfcSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(sg, 0x60, (u32)self[0x52]);
  return true;
}
PCREG(4c5750, pfcSave);

// 0x4c5700 ZPathfinderControl::ReadInput(DBREAD&) [map high; slot 33]. thiscall, ret 4. Event data: three u16 message
// ids, the box REFTAB, a u32 start state.
static void THISCALL pfcReadInput(u8 *self, void *rd) {
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(rd);
  *(u16 *)(self + 0x4e) = (u16)ext_4e5e40(rd);
  *(u16 *)(self + 0x50) = (u16)ext_4e5e40(rd);
  ext_4e6330(rd, *(void **)(self + 0x48));
  self[0x52] = ext_4e5e60(rd) != 0;
}
PCREG(4c5700, pfcReadInput);
