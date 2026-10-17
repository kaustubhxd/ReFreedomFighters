// batch1224.cpp - pathfinding tree: ZPathfinder3::ZPathfinder3(ZGEOMCLASSINFO*, const char*, ZBaseGeom*) [map low; GC
// 80192f90; zpathfinder3.cpp lines 0x254a..0x254c]. thiscall, ret 0xc.
//
// Builds the time-slice record (0x11 bytes, +0x18), the CFindPath context object (0x231 bytes, +0x1c, with the name
// "CClassFrameUpdateContext" at +0), registers the messages "FindPath", "PathResponse" and "msg_OpenBoxes", stores
// the object under the name "rEnemyPathFinder3" in the scene, and makes the request queue (50 entries of 50 bytes,
// +0x79; the first request id +0x75 is 1). Sub-object constructors are the exe's own.
#include "pf.h"

extern "C" void THISCALL ext_43de40(void *self, void *cls, const char *name, void *geom);  // ZSTDOBJ::ZSTDOBJ
extern "C" void THISCALL ext_52cec0(void *ts, u32 budget, u32 slices);                    // time slice ctor
extern "C" void THISCALL ext_52cea0(void *ctx, void *ts);                                  // CContext ctor
extern "C" void THISCALL ext_52a300(void *ctx, void *ts);                                  // CFindPathContext ctor

#define ZPF_FILE ((const char *)0x6a0f54)

// 0x52a370 ZPathfinder3 constructor.
static void THISCALL zpf3Ctor(u8 *self, void *cls, const char *name, void *geom) {
  ext_43de40(self, cls, name, geom);
  *(u32 *)self = 0x6a0c7c;
  *(u32 *)(self + 0x36) = 0;
  *(u32 *)(self + 0x3a) = 0;
  *(u16 *)(self + 0x47) = 0;
  *(u32 *)(self + 0x65) = 0;
  *(u32 *)(self + 0x18) = 0;
  u8 *ts = (u8 *)ext_41e290(0x11);
  if (ts) ext_52cec0(ts, 0x2dc6c0, 0x3c);
  *(u8 **)(self + 0x18) = ts;
  u8 *ctx = (u8 *)ext_41e290(0x231);
  if (ctx) {
    void *tsObj = *(void **)(self + 0x18);
    ext_52cea0(ctx, tsObj);
    ext_52a300(ctx + 0x51, tsObj);
    ctx[0x230] = 0;
    __builtin_memcpy(ctx, (const void *)0x6a0f2c, 16);       // "CClassFrameUpdateContext"
    __builtin_memcpy(ctx + 0x10, (const void *)0x6a0f3c, 8);
    ctx[0x18] = *(const u8 *)0x6a0f44;
  }
  *(u8 **)(self + 0x1c) = ctx;
  *(u32 *)(self + 0x20) = 0;
  self[0x46] = 0;
  G(u8, 0x6e8fbc) = 1;
  *(u32 *)(self + 0x25) = 3;
  self[0x24] = 0;
  *(u32 *)(self + 0x2d) = 0;
  *(u32 *)(self + 0x32) = 0;
  *(u32 *)(self + 0x7d) = 0;
  self[0x31] = 1;
  *(u32 *)(self + 0x69) = 0x4e20;
  *(u32 *)(self + 0x81) = 0;
  *(u32 *)(self + 0x59) = 8;
  *(u32 *)(self + 0x5d) = 8;
  *(u32 *)(self + 0x61) = 8;
  *(u32 *)(self + 0x4d) = 0;
  *(u32 *)(self + 0x51) = 0;
  *(u32 *)(self + 0x55) = 0;
  // messages
  u8 *msgs = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u16 *)(self + 0x93) = (u16)vcall<u32>(msgs, 0x114, (const char *)0x6a11f8, 0, ZPF_FILE, 0x254a);   // "FindPath"
  *(u16 *)(self + 0x95) = (u16)vcall<u32>(msgs, 0x114, (const char *)0x68a88c, 0, ZPF_FILE, 0x254b);   // "PathResponse"
  *(u16 *)(self + 0x97) = (u16)vcall<u32>(msgs, 0x114, (const char *)0x6a1204, 0, ZPF_FILE, 0x254c);   // "msg_OpenBoxes"
  // the scene object: register this pathfinder under "rEnemyPathFinder3"
  u8 *scene = vcall<u8 *>(msgs, 0x138);
  u32 ref = vcall<u32>(msgs, 0x4c, self);
  vcall<void>(scene, 0x4c, (const char *)0x68a9e0, ref);
  *(u32 *)(self + 0x49) = 0;
  // request queue: 50 entries of 50 bytes
  u8 *q = (u8 *)ext_41e290(0x14);
  if (q) {
    *(u32 *)(q + 4) = 0x32;
    u8 *buf = (u8 *)ext_41e290(0x32 * 0x32);
    *(u8 **)q = buf;
    *(u32 *)(q + 8) = 0;
    *(u32 *)(q + 0xc) = 0;
  } else {
    q = 0;
  }
  *(u8 **)(self + 0x79) = q;
  *(u32 *)(self + 0x75) = 1;
}
PCREG(52a370, zpf3Ctor);
