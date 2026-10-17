// batch1222.cpp - pathfinding tree: ZPathfinder3::SerializeData(char* blob, int mode) (save / load of the packed
// octree blob). Mode 1 = load, mode 2 = save; the magic number at the start of the blob selects the format.
//
// ZPathfinder3 fields: +0x24 bool "data corrupt", +0x31 bool "packed" (cPackData), +0x47 / +0x48 bools from the magic
// (ZPFOctree_packed::Init0 arguments), +0x65 ZPFOctree_packed*. Returns the number of blob bytes used (end - start).
// The exe wraps this in an SEH frame (fs:[0]); the port has no frame (nothing in it can throw in this harness).
#include "pf.h"

extern "C" u32 THISCALL ext_531270(void *octree, u8 *blob, u32 magic, u32 packed);  // ZPFOctree_packed::SerializeData
extern "C" void *THISCALL ext_52cfd0(void *octree);                                    // ZPFOctree_packed ctor
extern "C" void THISCALL ext_530fb0(void *octree, u8 a, u8 b);                        // ZPFOctree_packed::Init0

#define SD_FILE ((const char *)0x6a0f54)

// The reporter's printf-like slot (vtable +0x2c, cdecl) with one value.
static void logOne(int line, const char *fmt, u32 v) {
  void *r = vcall<void *>(G(void *, 0x700390), 0x20, SD_FILE, line);
  typedef void (*fn)(void *, const char *, u32);
  (*(fn *)(*(u8 **)r + 0x2c))(r, fmt, v);
}
static void logMsg(int line, const char *msg) {
  void *r = vcall<void *>(G(void *, 0x700390), 0x20, SD_FILE, line);
  typedef void (*fn)(void *, const char *);
  (*(fn *)(*(u8 **)r + 0x2c))(r, msg);
}

static u32 THISCALL serializeData(u8 *self, u8 *blob, u32 mode) {
  u32 magic = 0x1923484;   // default for an unknown mode
  u8 *ebx = blob;
  bool logOn = G(u8, 0x701b58) != 0;
  if (mode == 1) {
    magic = *(u32 *)blob;
    if (logOn) logOne(0x22a9, (const char *)0x6a0f98, magic);
  } else if (mode == 2) {
    if (logOn) logOne(0x22a9, (const char *)0x6a0fac, 0x1923484);
    *(u32 *)blob = magic;
  }
  if (magic == 0x1923483 || magic == 0x83349201) {
    logMsg(0x22ab, (const char *)0x6a0fc0);
    logMsg(0x22ac, (const char *)0x6a1008);
  }
  if (mode == 1) {
    if (magic == 0x82349201 || magic == 0x83349201 || magic == 0x84349201) {
      logMsg(0x22b9, (const char *)0x6a103c);
      self[0x24] = 1;
      return 0;
    }
    if (magic != 0x1923482 && magic != 0x1923483 && magic != 0x1923484) {
      logMsg(0x22b1, (const char *)0x6a103c);
      self[0x24] = 1;
      return 0;
    }
  }
  // flags from the magic (ZPFOctree_packed::Init0 arguments)
  self[0x47] = (magic == 0x1923483 || magic == 0x1923484 || magic == 0x83349201 || magic == 0x84349201) ? 1 : 0;
  self[0x48] = (magic == 0x1923484 || magic == 0x84349201) ? 1 : 0;
  self[0x24] = 0;
  u8 packed = 0;
  if (mode == 2) {
    packed = self[0x31];
    if (G(u8, 0x701b58)) logOne(0x22c8, (const char *)0x6a1090, (u32)(s32)(s8)packed);
    ebx[4] = packed;
  } else if (mode == 1) {
    packed = ebx[4];
    if (G(u8, 0x701b58)) logOne(0x22c8, (const char *)0x6a1078, (u32)(s32)(s8)packed);
  } else {
    packed = (u8)((u32)(unsigned long)blob >> 24);   // the exe reads the top byte of the blob pointer here (mode 0: unused)
  }
  ebx += 5;
  if (mode == 1) self[0x31] = packed != 0;
  if (!self[0x31]) {
    void *r = vcall<void *>(G(void *, 0x700390), 0x20, SD_FILE, 0x22cc);
    typedef void (*fn)(void *, const char *);
    (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a10a4);   // "Don't use unpacked data.\n"
    pfBreak();
    return (u32)(ebx - blob);
  }
  if (mode == 2) {
    logMsg(0x22d4, (const char *)0x6a10c0);
  } else if (mode == 1) {
    void *oct = ext_41e290(0xd1e);
    if (oct) oct = ext_52cfd0(oct);
    *(void **)(self + 0x65) = oct;
    ext_530fb0(oct, self[0x47], self[0x48]);
  }
  void *octree = *(void **)(self + 0x65);
  u32 used = ext_531270(octree, ebx, mode, 0);   // the exe passes esi = mode here
  ebx += used;
  return (u32)(ebx - blob);
}
PCREG(52cb60, serializeData);
