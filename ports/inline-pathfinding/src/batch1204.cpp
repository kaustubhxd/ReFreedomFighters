// batch1204.cpp - pathfinding tree: ZPathfinder3 wrappers (vtable slots 4..6, 85, 131..137 and friends).
// ZPathfinder3 (PC, /Zp1, 0x99 bytes): +0x31 bool "packed data loaded", +0x65 ZPFOctree_packed*, +0x75 u32 saved
// counter, +0x79 CPathRequestQueue*, +0x7d door-blocker array, +0x91 u16 id of MSG_EDITORCALCTABLE.
#include "pf.h"

extern "C" u32 THISCALL ext_52e0a0(void *oct, float *a, float *b, u32 flag);   // ZPFOctree_packed::CheckLine
extern "C" u32 THISCALL ext_52e240(void *oct, float *p);                       // ZPFOctree_packed::CheckPosition
extern "C" u32 THISCALL ext_45d380(void *self, u32 cmd, void *data);          // ZSTDOBJ::ClassCommand
extern "C" void THISCALL ext_43e0f0(void *self);                              // ZSTDOBJ::ClassInit
extern "C" void THISCALL ext_530b60(void *oct, u16 *out, float *p);           // GetLocalCoords (batch1201)
extern "C" void THISCALL ext_530db0(void *oct, s16 *out, float *v);           // GetLocalVector (batch1201)
extern "C" void THISCALL ext_52e4f0(void *oct, u16 *at, s16 *off, u32 on);    // ZPFOctree_packed::EnableSpecialLinks
extern "C" u32 THISCALL ext_52e670(void *oct, float *p, float a, float b, float c);  // ZPFOctree_packed::FindNearestPoint
extern "C" void THISCALL ext_45f3a0(void *self);                              // ZGEOM::Load2
extern "C" void THISCALL ext_52b9d0(void *self);                              // ZPathfinder3::ProcessAdditionalDoors
extern "C" u32 THISCALL ext_45f3c0(void *self, void *lg);                     // ZGEOM::Load
extern "C" void THISCALL ext_52b430(void *queue, void *lg);                   // CPathRequestQueue::Load
extern "C" u32 THISCALL ext_45f960(void *self, void *sg);                     // ZGEOM::Save
extern "C" u32 THISCALL ext_52c270(void *self, u32 id, const float *from, const float *to, u32 b1, float r, u32 b2,
                                   u32 b3);                                    // ZPathfinder3::RequestPathOld
extern "C" void THISCALL ext_52a600(void *self);                              // ~ZPathfinder3 body
extern "C" void ext_45c510(void *p);                                          // ZGEOM::operator delete
extern "C" void ext_4690b0(void *p, u32 size);                                // guard_check_icall (empty)
extern "C" void THISCALL ext_52d080(void *self);                              // ~ZPFOctree_packed body

#define PF_FILE ((const char *)0x6a0f54)        // "..\..\code\engine\pathfinder\zpathfinder3.cpp"
#define PF_UNPACKED ((const char *)0x6a10a4)    // "Don't use unpacked data.\n"
#define OCT(self) (*(void **)((u8 *)(self) + 0x65))

// 0x52a800 ZPathfinder3::CheckLine(float*, float*, bool) [map high; slot 136]. thiscall, ret 0xc, bool.
static u32 THISCALL pfCheckLine(u8 *self, float *a, float *b, u32 flag) {
  if (self[0x31]) return ext_52e0a0(OCT(self), a, b, flag);
  pfReport(PF_FILE, 0x26a9, PF_UNPACKED);
  pfBreak();
  return 0;
}
PCREG(52a800, pfCheckLine);

// 0x52aa90 ZPathfinder3::CheckPosition(float*) [map high; slot 135]. thiscall, ret 4, bool.
static u32 THISCALL pfCheckPosition(u8 *self, float *p) {
  if (self[0x31]) return ext_52e240(OCT(self), p);
  pfReport(PF_FILE, 0x269d, PF_UNPACKED);
  pfBreak();
  return 0;
}
PCREG(52aa90, pfCheckPosition);

// 0x52aae0 ZPathfinder3::ClassCommand(unsigned short, void*) [map medium]. thiscall, ret 8: base class, returns 0.
static u32 THISCALL pfClassCommand(u8 *self, u32 cmd, void *data) {
  ext_45d380(self, cmd, data);
  return 0;
}
PCREG(52aae0, pfClassCommand);

// 0x52abc0 ZPathfinder3::ClassInit() [map: vtable slot 85 = ClassInit; the map's "Setup" shares this PC function].
// thiscall. Base ClassInit, own vtable +0x110 (0x10, 0), then registers the message "MSG_EDITORCALCTABLE" with the
// engine's message table (g_pSysInterface +0x9b, vtable +0x114) and keeps its id at +0x91.
static void THISCALL pfClassInit(u8 *self) {
  ext_43e0f0(self);
  vcall<void>(self, 0x110, 0x10, 0);
  void *msgs = *(void **)((u8 *)g_pSysInterface + 0x9b);
  *(u16 *)(self + 0x91) = vcall<u16>(msgs, 0x114, (const char *)0x6a0f84, 0, PF_FILE, 0x2292);
}
PCREG(52abc0, pfClassInit);

// 0x52b020 ZPathfinder3::EnableSpecialLinks(float* pos, float* offset, bool on) [map high; slot 134]. thiscall,
// ret 0xc. World position and offset to local cell / cell offset, then the octree switches the links there.
static void THISCALL pfEnableSpecialLinks(u8 *self, float *pos, float *off, u32 on) {
  u16 at[3];
  s16 d[3];
  ext_530b60(OCT(self), at, pos);
  ext_530db0(OCT(self), d, off);
  ext_52e4f0(OCT(self), at, d, on);
}
PCREG(52b020, pfEnableSpecialLinks);

// 0x52b130 ZPathfinder3::FindNearestPoint(float*, float, float, float) [map medium; slot 133]. thiscall, ret 0x10.
static u32 THISCALL pfFindNearestPoint(u8 *self, float *p, float a, float b, float c) {
  return ext_52e670(OCT(self), p, a, b, c);
}
PCREG(52b130, pfFindNearestPoint);

// 0x52b330 ZPathfinder3::FindPathLength(const float*, const float*) [map high]. Unsupported in the shipped game:
// reports "FindPathLength() currently unsupported..." and returns 0.0 in ST0. ret 8.
static float THISCALL pfFindPathLength(void *, const float *, const float *) {
  pfReport(PF_FILE, 0x26b2, (const char *)0x6a137c);
  pfBreak();
  return 0.0f;
}
PCREG(52b330, pfFindPathLength);

// 0x52b3f0 ZPathfinder3::Load2() [map medium; slot 6]. thiscall. Same message registration as ClassInit, then the
// door list is rebuilt (ProcessAdditionalDoors, tail call).
static void THISCALL pfLoad2(u8 *self) {
  ext_45f3a0(self);
  void *msgs = *(void **)((u8 *)g_pSysInterface + 0x9b);
  *(u16 *)(self + 0x91) = vcall<u16>(msgs, 0x114, (const char *)0x6a0f84, 0, PF_FILE, 0x2292);
  ext_52b9d0(self);
}
PCREG(52b3f0, pfLoad2);

// 0x52b4a0 ZPathfinder3::Load(ZLoadGame*) [map high; slot 5]. thiscall, ret 4, bool. ZLoadGame vtable +0x48 loads
// a u32 into +0x75; the request queue loads itself.
static u32 THISCALL pfLoad(u8 *self, void *lg) {
  u32 r = ext_45f3c0(self, lg);
  if (!(u8)r) return r;
  vcall<void>(lg, 0x48, (void *)(self + 0x75));
  ext_52b430(*(void **)(self + 0x79), lg);
  return 1;
}
PCREG(52b4a0, pfLoad);

// 0x52cb00 ZPathfinder3::Save(ZSaveGame*) [map high; slot 4]. thiscall, ret 4, bool. ZSaveGame vtable +0x44 saves a
// u32, +0x10 a block (ptr, size). Saved: +0x75, then the queue's +4 (count), +8, +0xc and its 0x32-byte entries.
static u32 THISCALL pfSave(u8 *self, void *sg) {
  u32 r = ext_45f960(self, sg);
  if (!(u8)r) return r;
  vcall<void>(sg, 0x44, *(u32 *)(self + 0x75));
  u32 *q = *(u32 **)(self + 0x79);
  vcall<void>(sg, 0x44, q[1]);
  vcall<void>(sg, 0x44, q[2]);
  vcall<void>(sg, 0x44, q[3]);
  vcall<void>(sg, 0x10, q[0], q[1] * 0x32);
  return 1;
}
PCREG(52cb00, pfSave);

// 0x52c240 ZPathfinder3::RequestPath(unsigned int, const float*, const float*, bool, float, bool, bool) [map high;
// slot 132]. thiscall, ret 0x1c: forwards to RequestPathOld.
static u32 THISCALL pfRequestPath(u8 *self, u32 id, const float *from, const float *to, u32 b1, float r, u32 b2,
                                  u32 b3) {
  return ext_52c270(self, id, from, to, b1, r, b2, b3);
}
PCREG(52c240, pfRequestPath);

// 0x52a6c0 ZPathfinder3 scalar deleting destructor [map: slot 131, ~ZPathfinder3]. thiscall, ret 4. Flag 1 frees
// (flag 4: placement in an array, only the empty icall guard runs).
static void *THISCALL pfDelete(u8 *self, u32 flags) {
  ext_52a600(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x99);
    else ext_45c510(self);
  }
  return self;
}
PCREG(52a6c0, pfDelete);

// 0x52d190 ZPFOctree_packed scalar deleting destructor [map: vtable slot 0]. thiscall, ret 4. Object size 0xd1e.
static void *THISCALL octDelete(u8 *self, u32 flags) {
  ext_52d080(self);
  if (flags & 1) ext_634273(self, 0xd1e);
  return self;
}
PCREG(52d190, octDelete);
