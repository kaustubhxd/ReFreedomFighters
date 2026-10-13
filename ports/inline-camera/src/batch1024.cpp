// batch1024.cpp - CCameraBox (level camera boxes) and ZBaseCamera command / room hints. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" void ext_634273(void *p, u32 size);                 // operator delete(void*, size) (cdecl)
extern "C" void *ext_41e290(u32 size);                         // operator new (cdecl)
extern "C" THISCALL long double ext_4e5e80(void *db);          // DBREAD::operator float
extern "C" THISCALL void ext_4dc630(void *geom, u32 set, u32 mask);  // ZBaseGeom::SetControl
extern "C" THISCALL u8 *ext_4db550(void *geom);                // ZBaseGeom::GetRoomList
extern "C" THISCALL u32 ext_4dc130(void *geom);                // ZBaseGeom::ParentGroup
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b

// Script reference of an object through the reference table at 0x70038c (same code as ZCamHelper::Command).
static inline u32 script_ref(u8 *p) {
  if (!p) return 0;
  u8 *t = G(u8 *, 0x70038c);
  if (vcall<u32>(t, 0x20, p)) return 0;
  t = G(u8 *, 0x70038c);
  typedef u32(THISCALL * refcb)(void *);
  refcb cb = at<refcb>(t, 8);
  if (cb && at<u32>(t, 0xc) <= (u32)p && (u32)p < at<u32>(t, 0x10)) return cb(p);
  if (*(u32 *)(p - 4) == 0) vcall<void>(t, 0xac, p);
  return *(u32 *)(p - 4);
}

// CCameraBox fields: +0x44 own geometry, +0x48 maximum camera distance inside the box, +0x4c the box record
// {geometry handle, max distance} that ZFFCamera1::TestBox reads.

// 0x5c7d90 CCameraBox::End(): free the box record.
static THISCALL void CCameraBox_End(void *self) { ext_634273(ptr(self, 0x4c), 8); }
PCREG(5c7d90, CCameraBox_End);

// 0x5c7da0 CCameraBox::FrameUpdate(): vslot 0x68(0x10, 0) (inferred: switch the per-frame event off).
static THISCALL u32 CCameraBox_FrameUpdate(void *self) { return vcall<u32>(self, 0x68, 0x10u, 0u); }
PCREG(5c7da0, CCameraBox_FrameUpdate);

// 0x5d86b0 CCameraBox::CopyEventDataBlock(DBREAD&) (shared with CScrollText, ZTextureAnim): one float at +0x48.
static THISCALL void CCameraBox_CopyEventDataBlock(void *self, void *db) {
  at<float>(self, 0x48) = (float)ext_4e5e80(db);
}
PCREG(5d86b0, CCameraBox_CopyEventDataBlock);

// 0x5c7db0 CCameraBox::Init(): make the box record and add it to the level's "CameraBoxList" (a ZLIST created on
// first use: flag 0x800000 cleared, slot 0x154, slot 0x124(1, 0, 0, 0)) by script reference (list slot 0x21c).
static THISCALL void CCameraBox_Init(void *self) {
  u32 *rec = (u32 *)ext_41e290(8);
  at<u32 *>(self, 0x4c) = rec;
  rec[1] = at<u32>(self, 0x48);
  rec[0] = vcall<u32>(SYS9B, 0x4c, at<u32>(self, 0x44));
  void *world = ptr(SYS9B, 0xadc);
  u8 *l = vcall<u8 *>(world, 0x25c, (const char *)0x6b48dc, 0u);  // "CameraBoxList"
  if (!l) {
    l = vcall<u8 *>(ptr(SYS9B, 0xadc), 0x294, (const char *)0x6b48dc, (const char *)0x67f610, 0u, 1u);  // "ZLIST"
    vcall<void>(l, 0x154);
    ext_4dc630(ptr(l, 8), 0x800000, 0);
    vcall<void>(l, 0x124, 1u, 0u, 0u, 0u);
  }
  vcall<void>(l, 0x21c, script_ref(ptr(self, 0x4c)));
}
PCREG(5c7db0, CCameraBox_Init);

// 0x4fb260 ZBaseCamera::Command(unsigned short, void*): registered messages +0x48 get quality (float to *data),
// +0x4c activate(data), +0x4e deactivate, +0x50 enable, +0x52 disable, +0x58 vslot 0xa8.
static THISCALL u32 ZBaseCamera_Command(void *self, u32 cmd, void *data) {
  u16 c = (u16)cmd;
  if (c == at<u16>(self, 0x48)) {
    *(float *)data = (float)vcall<long double>(self, 0x98);
  } else if (c == at<u16>(self, 0x4c)) {
    vcall<void>(self, 0x9c, data);
  } else if (c == at<u16>(self, 0x4e)) {
    vcall<void>(self, 0xa0);
  } else if (c == at<u16>(self, 0x50)) {
    vcall<void>(self, 0xa4, 1u);
  } else if (c == at<u16>(self, 0x52)) {
    vcall<void>(self, 0xa4, 0u);
  } else if (c == at<u16>(self, 0x58)) {
    vcall<void>(self, 0xa8);
  }
  return 0;
}
PCREG(4fb260, ZBaseCamera_Command);

// The room of geometry g (g slot 0x20 -> +8 -> GetRoomList, valid when +0x1c is set), else 0.
static inline u32 room_of(void *g) {
  u8 *x = vcall<u8 *>(g, 0x20);
  void *y = ptr(x, 8);
  if (!y) return 0;
  u8 *rl = ext_4db550(y);
  if (rl && rl[0x1c]) return *(u32 *)rl;
  return 0;
}

// 0x4fb610 (unnamed) ZBaseCamera::CalcCameraRoomHint1stPerson() (inferred from CalcRoomHint): the camera's room
// hint (camera geometry slot 0x284) is the room of the controlled geometry (control +0x5c -> +0x48) when it is
// of kind 0x80200014.
static THISCALL void ZBaseCamera_RoomHint1st(void *self) {
  u8 *c = ptr(self, 0x5c);
  void *g = c ? vcall<void *>(SYS9B, 0x58, at<u32>(c, 0x48)) : 0;
  u32 r = 0;
  if (vcall<bool>(g, 0x1e0, 0x80200014u)) r = room_of(g);
  vcall<void>(ptr(self, 0x44), 0x284, r);
}
PCREG(4fb610, ZBaseCamera_RoomHint1st);

// 0x4fb680 ZBaseCamera::CalcCameraRoomHint3rdPerson(): line test (collision manager sys +0x1aa3 -> +0x1c, slot
// 0x30) from the camera position to the focal point; if it hits a portal-like object (+0x54 slots 0x234/0x230/
// 0x14/0x30 -> geometry -> ParentGroup) that group is the hint, otherwise the controlled geometry's room.
static THISCALL void ZBaseCamera_CalcCameraRoomHint3rdPerson(void *self) {
  u32 res = 0;
  u8 *c = ptr(self, 0x5c);
  void *g = c ? vcall<void *>(SYS9B, 0x58, at<u32>(c, 0x48)) : 0;
  if (vcall<bool>(g, 0x1e0, 0x80200014u)) {
    float p[3] = {0.0f, 0.0f, 0.0f};
    vcall<void>(g, 0x84, p);
    vcall<void>(self, 0x8c, p);
    vcall<void>(self, 0x90, p);
    float q[3];
    vcall<void>(self, 0x94, q);
    float d[3];
    ext_43e920(d, p, q);
    alignas(4) u8 rec[0x48];
    *(u32 *)rec = 0x3f800000;
    void *coll = ptr(ptr(G(u8 *, 0x70039c), 0x1aa3), 0x1c);
    bool hit = vcall<bool>(coll, 0x30, rec, 2u, q, d, 0u, 0xffffffffu, 1u, 0u);
    u8 *obj = hit ? *(u8 **)(rec + 0x10) : 0;
    if (obj) {
      u8 *b = ptr(obj, 0x54);
      if (vcall<bool>(b, 0x234)) {
        u8 *x = vcall<u8 *>(b, 0x230);
        if (x && vcall<u32>(x, 0x14)) {
          u32 y = vcall<u32>(x, 0x30, 0u);
          void *z = vcall<void *>(SYS9B, 0x54, y);
          if (z) res = ext_4dc130(z);
        }
      }
    }
    if (!res) res = room_of(g);
  }
  vcall<void>(ptr(self, 0x44), 0x284, res);
}
PCREG(4fb680, ZBaseCamera_CalcCameraRoomHint3rdPerson);
