// batch1646.cpp - ZMoveOnSpline::RegisterWithVisionSystem() (0x513d10, residue 13, 2026-10-12). Name map: high
// (moveonspline.cpp, strings "TrackLinkObjects", "CheckVisible", "Msg_SeerObjectAdd", "Msg_SetVisOffset").
// Looks up the track-link object (sys+0x9b, manager +0xadc, slot 0x25c) and stores its handle at +0xd2 and the
// CheckVisible object at +0x13c. Gets the size of the geom at +8 (ZBaseGeom::GetSize), zeroes x and z and adds the
// slot 0x2f0 value to y. Then, for each object the slot 0x58 finds from +0xd6 (its +0x18 list, slot 0x4c/0x5c), sends
// two messages to this object's slot 0x130 with the message ids from slot 0x114. Stores the slot 0x84 result of the
// CheckVisible object at +0x140. GUESS: the names of the slots and fields are from the code only.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4db7c0[];  // ZBaseGeom::GetSize (thiscall, one out pointer to three floats)
typedef void(THISCALL *GetSizeFn)(void *self, float *out);

void THISCALL ZMoveOnSpline_RegisterWithVisionSystem(u8 *self) {
  u8 *sys = AT(u8 *, 0x70039c, 0);
  u8 *R = AT(u8 *, sys, 0x9b);
  u8 *M = AT(u8 *, R, 0xadc);
  u8 *T = (u8 *)vcall<u32>(M, 0x25c, (u32)0x685f44u, (u32)0);
  AT(u32, self, 0xd2) = vcall<u32>(R, 0x4c, (u32)T);
  AT(u32, self, 0x13c) = vcall<u32>(T, 0x100, (u32)0x690428u);
  u32 id1 = vcall<u16>(R, 0x114, (u32)0x690438u, (u32)0, (u32)0x69e4bcu, (u32)0x199u);
  u32 id2 = vcall<u16>(R, 0x114, (u32)0x6904a4u, (u32)0, (u32)0x69e4bcu, (u32)0x19au);
  u8 *obj24 = (u8 *)vcall<u32>(R, 0x58, AT(u32, self, 0xd6));

  float v[3];
  ((GetSizeFn)(void *)ext_4db7c0)(AT(void *, self, 8), v);
  v[0] = 0.0f;
  v[2] = 0.0f;
  v[1] = vcall<float>(self, 0x2f0) + v[1];
  u32 edi = vcall<u32>(R, 0x4c, (u32)self);

  if (obj24 && AT(u8 *, obj24, 0x18)) {
    u8 *Q = AT(u8 *, obj24, 0x18);
    u32 tmp;
    vcall<void>(Q, 0x4c, (u32)&tmp);
    u32 h = vcall<u32>(Q, 0x5c, (u32)&tmp);
    while (tmp != 0) {
      u32 buf40[2] = {edi, h};
      vcall<void>(self, 0x130, (u32)T, id1, (u32)buf40);
      struct {
        u32 a;
        float x, y, z;
      } b20 = {edi, v[0], v[1], v[2]};
      vcall<void>(self, 0x130, (u32)T, id2, (u32)&b20);
      h = vcall<u32>(Q, 0x5c, (u32)&tmp);
    }
  }
  AT(u32, self, 0x140) = vcall<u32>(AT(u8 *, self, 0x13c), 0x84, edi);
}
PCREG(513d10, ZMoveOnSpline_RegisterWithVisionSystem);
