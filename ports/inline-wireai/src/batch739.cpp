// batch739.cpp - ZOnScreenDisplay::ClassInit2() (0x5a6230) [high], residue 11 slice (2026-10-12).
// Base class init (slot 0x110 with (0x10, 0)). Two int reads from the engine object at +0x190f (slots 0xd8 / 0xdc) become
// floats at +0x2f4 / +0x2f8. db slot 0x134 gives an object whose slot 0x90 writes a flag ("Multiplayer") into +0x658.
// CreateSprites, InitSprites, two ZGeomActionMarker::Init calls, db slot 0x138 -> slot 0x88 "ObjectCameraClass" -> db 0x58
// into +0x428, reset matrix, slot 0x7c(M, V). Mode +0x360: 2 / 3 / 4 choose "HitmanGround2/3/4", anything else "HitmanGround".
// The chosen object's slot 0x88 writes a reference (db 0x58) into +0x364; a non-null reference gets db 0x58 of its +0x676
// with slot 0x25c(this+8). A null reference uses the engine object's slot 0xb4 and db 0x58 instead. Finally +0x8a3 = gl+0x4ac.
#include "ff.h"

extern "C" void THISCALL ext_5a6980(void *self);                                    // CreateSprites
extern "C" void THISCALL ext_5a86c0(void *self);                                    // InitSprites
extern "C" void THISCALL ext_5a8550(void *self, u32 a, u32 b, u32 c);             // ZGeomActionMarker::Init
extern "C" void THISCALL ext_4de7a0(void *m);                                       // mreset

static inline void *db() { return *(void **)((u8 *)*(void **)0x70039c + 0x9b); }
static inline void *engObj() { return *(void **)((u8 *)*(void **)0x70039c + 0x190f); }

// 0x5a6230 ZOnScreenDisplay::ClassInit2() [high].
static void THISCALL osd_ClassInit2(u8 *self) {
  vcall<void>(self, 0x110, 0x10u, 0u);
  *(float *)(self + 0x2f4) = (float)vcall<s32>(engObj(), 0xd8);
  *(float *)(self + 0x2f8) = (float)vcall<s32>(engObj(), 0xdc);

  void *mp = vcall<void *>(db(), 0x134);
  u8 flag = 0;
  vcall<void>(mp, 0x90, (const char *)0x68a9d4, &flag);   // "Multiplayer"
  *(u8 *)(self + 0x658) = flag;

  ext_5a6980(self);
  ext_5a86c0(self);
  ext_5a8550(self + 0x53c, *(u32 *)(self + 0x52c), *(u32 *)(self + 0x530), 0xcu);
  ext_5a8550(self + 0x54a, *(u32 *)(self + 0x534), *(u32 *)(self + 0x538), 0xcu);

  void *cam = vcall<void *>(db(), 0x138);
  u32 t = 0;
  vcall<void>(cam, 0x88, (const char *)0x6b007c, &t);     // "ObjectCameraClass"
  *(u32 *)(self + 0x428) = vcall<u32>(db(), 0x58, t);

  float M[12];
  float V[3] = {0.0f, 0.0f, 0.0f};
  ext_4de7a0(M);
  vcall<void>(self, 0x7c, M, V);
  ext_4de7a0(self + 0x2d0);

  u32 mode = *(u32 *)(self + 0x360);
  const char *name = (const char *)0x681320;                 // "HitmanGround"
  if (mode == 2)
    name = (const char *)0x68fcbc;                           // "HitmanGround2"
  else if (mode == 3)
    name = (const char *)0x68fccc;                           // "HitmanGround3"
  else if (mode == 4)
    name = (const char *)0x68fcdc;                           // "HitmanGround4"

  void *obj = vcall<void *>(db(), 0x138);
  t = 0;
  vcall<void>(obj, 0x88, name, &t);
  u32 ref = vcall<u32>(db(), 0x58, t);
  *(u32 *)(self + 0x364) = ref;
  if (ref) {
    void *x = vcall<void *>(db(), 0x58, *(u32 *)(ref + 0x676));
    vcall<void>(x, 0x25c, *(u32 *)(self + 8));
  } else {
    u32 p = vcall<u32>(engObj(), 0xb4, 0u);   // one argument (0)
    void *o = vcall<void *>(db(), 0x58, p);
    vcall<void>(o, 0x25c, *(u32 *)(self + 8));
  }
  *(u32 *)(self + 0x8a3) = *(u32 *)(*(u8 **)0x7003b8 + 0x4ac);
}
PCREG(5a6230, osd_ClassInit2);
