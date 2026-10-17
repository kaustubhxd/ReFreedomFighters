// batch1221.cpp - pathfinding tree: ZPathfinder3::CopyDataBlock (the DBLK item walk that loads the octree data).
//
// Items read in order (decoders/pathfind-format.md section 1): 0 blob (SerializeData), 1 REFTAB (extra door geoms,
// Added to +0x2d), 2 int (+0x46 has data), 3 int (+0x25, clamped 2..10), 4 float (+0x20), 5 int (LooseOctree warning
// through 0x6e8fbc), 6 REFTAB (+0x32), 7 int (+0x31 packed), 8 int (+0x69, octree size). Item 9 ends the block.
// The exe's own DBLK readers stay real: GetType 0x4e1600, Get 0x4e0fd0 (REFTAB), 0x4e11e0 (int), 0x4e12e0 (int),
// 0x4e12f0 (float), FindNext 0x4e0e90 via NextBlock 0x4e1b30, the blob finder 0x4e0f60.
#include "pf.h"

extern "C" void THISCALL ext_610100(void *self, void *dblk);             // ZRenderGC::Init (ecx = self)
extern "C" int THISCALL ext_4e0f60(void *dblk, void *out);               // blob finder, returns the count
extern "C" void THISCALL ext_52cb60(void *self, void *blob, int n);      // ZPathfinder3::SerializeData(char*, int)
extern "C" void THISCALL ext_4ccba0(void *reftab);                       // REFTAB32 ctor
extern "C" void THISCALL ext_4ccf60(void *reftab);                       // REFTAB32 dtor
extern "C" u8 THISCALL ext_4e1600(void *dblk);                           // DBLK::GetType
extern "C" void THISCALL ext_4e0fd0(void *dblk, void *reftab);           // DBLK::Get(REFTAB32&)
extern "C" void THISCALL ext_4e11e0(void *dblk, void *p, int n);         // DBLK::Get(int, n)
extern "C" void THISCALL ext_4e12e0(void *dblk, void *p, int n);         // DBLK::Get(int, n) (jmp to 4e11e0)
extern "C" void THISCALL ext_4e12f0(void *dblk, void *p, int n);         // DBLK::Get(float, n)
extern "C" void THISCALL ext_4e1b30(void *dblk);                         // DBLK::NextBlock
extern "C" void THISCALL ext_530fd0(void *octree, int n);                // ZPFOctree_packed::Init(int)
extern "C" const char *THISCALL ext_4dc110(void *geom);                  // ZBaseGeom::Name
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);      // striwcmp, 0 = match

#define PF_FILE ((const char *)0x6a0f54)

// The door geoms of the collision list (named *door* with class 0x200002 / 0x100001) go to the doors list. Kept as a
// separate function: inside copyDataBlock the register holding dblk was reused for the iterator (see docs).
__attribute__((noinline)) static void addDoorGeoms(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *mgr = *(u8 **)(*(u8 **)(rm + 0x9b) + 0xadc);
  for (u8 *it = *(u8 **)(mgr + 8); it;) {
    const char *name = ext_4dc110(it);
    if (!ext_4cc850(name, (const char *)0x6a1244)) {
      u8 *obj = *(u8 **)(it + 0x54);
      if (obj) {
        u32 cls = *(u32 *)(*(u8 **)(obj + 0xc) + 0x23);
        if (cls == 0x200002 || cls == 0x100001) vcall<void>(*(void **)(self + 0x2d), 4, obj);
      }
    }
    vcall<void>(mgr, 0x50, &it);
  }
}

// 0x52ac10 ZPathfinder3::CopyDataBlock(DBLK*) [map high; GameCube reference; zpathfinder3.cpp lines 0x25ab / 0x2601].
// thiscall, ret 4.
static void THISCALL copyDataBlock(u8 *self, u8 *dblk) {
  u32 tmp178 = vcall<u32>(G(void *, 0x70038c), 0x48, 0xff00);
  ext_610100(self, dblk);
  u8 tmp16c[4];
  int cnt = ext_4e0f60(dblk, tmp16c);
  if (cnt > 0) {
    ext_52cb60(self, *(void **)tmp16c, 1);
  } else {
    void *r = vcall<void *>(G(void *, 0x700390), 0x20, PF_FILE, 0x25ab);
    typedef void (*fn)(void *, const char *);
    (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a1214);
    pfBreak();
  }
  // doors: a new REFTAB32 (0xac bytes) at +0x2d, then every door geom in the level's door list is added to it
  void *doors = ext_41e290(0xac);
  if (doors) ext_4ccba0(doors);
  *(void **)(self + 0x2d) = doors;
  addDoorGeoms(self);
  // item 1 (REFTAB, extra door refs): each ref goes through the message table and is added to the doors list
  if (ext_4e1600(dblk) == 9) {
    u8 tmpR[0xac];
    ext_4ccba0(tmpR);
    ext_4e0fd0(dblk, tmpR);
    u32 it[4] = {0, 0, 0, 0};          // REFTAB iterator: Begin writes 12 bytes, the first dword is "has next"
    vcall<void>(tmpR, 0x4c, it);
    u32 ref = vcall<u32>(tmpR, 0x5c, it);
    while (it[0]) {
      void *g = vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x58, ref);
      if (g) vcall<void>(*(void **)(self + 0x2d), 4, g);
      ref = vcall<u32>(tmpR, 0x5c, it);
    }
    ext_4ccf60(tmpR);
  }
  // item 2 (int, +0x46) and item 3 (int, +0x25 clamped to 2..10)
  self[0x46] = 0;
  if (ext_4e1600(dblk) == 3) {
    ext_4e11e0(dblk, tmp16c, 1);
    self[0x46] = *(int *)tmp16c != 0;
  }
  *(int *)(self + 0x25) = 3;
  if (ext_4e1600(dblk) == 3) {
    ext_4e11e0(dblk, self + 0x25, 1);
    if (*(int *)(self + 0x25) < 2) *(int *)(self + 0x25) = 2;
    if (*(int *)(self + 0x25) > 10) *(int *)(self + 0x25) = 10;
  }
  if (!self[0x31]) **(int **)(self + 0x51) = *(int *)(self + 0x25);
  // item 4 (float, +0x20)
  *(int *)(self + 0x20) = 0;
  if (ext_4e1600(dblk) == 2) ext_4e12f0(dblk, self + 0x20, 1);
  // item 5 (int, LooseOctree warning)
  G(u8, 0x6e8fbc) = 1;
  u8 warn = 0;
  if (ext_4e1600(dblk) == 3) {
    ext_4e11e0(dblk, tmp16c, 1);
    warn = G(u8, 0x6e8fbc) = (*(int *)tmp16c != 0);
  } else {
    warn = G(u8, 0x6e8fbc);
  }
  if (warn) {
    void *r = vcall<void *>(G(void *, 0x700390), 0x20, PF_FILE, 0x2601);
    typedef void (*fn)(void *, const char *);
    (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a124c);
  }
  // item 6 (REFTAB, +0x32)
  if (ext_4e1600(dblk) == 9) {
    u8 *old = *(u8 **)(self + 0x32);
    if (old) vcall<void>(old, 0, 1);
    void *nr = ext_41e290(0xac);
    u32 tmp174 = 0;
    if (nr) ext_4ccba0(nr);
    tmp174 = (u32)nr;
    *(void **)(self + 0x32) = nr;
    u8 tmp168[0xac];
    ext_4ccba0(tmp168);
    ext_4e0fd0(dblk, tmp168);
    ext_4ccf60(tmp168);
    (void)tmp174;
  }
  // item 7 (int, +0x31)
  self[0x31] = 1;
  if (ext_4e1600(dblk) == 3) {
    ext_4e11e0(dblk, tmp16c, 1);
    self[0x31] = *(int *)tmp16c != 0;
  }
  // item 8 (int, octree size)
  if (ext_4e1600(dblk) == 3) ext_4e12e0(dblk, self + 0x69, 1);
  ext_530fd0(*(void **)(self + 0x65), *(int *)(self + 0x69));
  ext_4e1b30(dblk);
  vcall<void>(G(void *, 0x70038c), 0x48, tmp178);
}
PCREG(52ac10, copyDataBlock);
