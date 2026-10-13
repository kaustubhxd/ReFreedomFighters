// batch1119.cpp - collision thread, batch 1119: ZCollisionBase::GetGeomsInBox (0x4ecf50).
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);   // mcpy (9 floats)

// 0x4ecf50 ZCollisionBase::GetGeomsInBox(ZBaseGeom **a, ZBaseGeom **b, eGlobalTreeType type, const float *p1,
// const float *p2, const float *p3, int start, bool roomPass, bool first, bool second) const [medium], thiscall,
// ret 0x28. Returns the count of geoms written to a and b from index 0.
// roomPass: this's slot 0x14 (begin, end, octree +0x19d, p1, p2, p3) fills a local room array; for each room, a copy
//   of p1 (mat) and p2 (vec) goes to the room's slot 0x94(mat, vec), then the room's slot 0x344(a+n, b, type, mat,
//   vec, p3, start, second) adds its count.
// first: this's slot 0x7c(a+n, b, type, p1, p2, p3, start, second) adds its count (returned as eax + n).
// The room-list call leaves its count in eax (the caller reads it), so the port returns it explicitly.
static u32 THISCALL getGeomsInBox(u8 *self, u8 **a, u8 **b, u32 type, const float *p1, const float *p2,
                                  const float *p3, u32 start, u8 roomPass, u8 first, u8 second) {
  u32 n = 0;
  if (roomPass) {
    u8 *rooms[256];
    u32 cnt = vcall<u32>(self, 0x14, rooms, rooms + 256, *(u8 **)(self + 0x19d), p1, p2, p3);
    for (u32 i = 0; i < cnt; i++) {
      float mat[9], vec[3];
      ext_4de420(mat, p1);
      vec[0] = p2[0];
      vec[1] = p2[1];
      vec[2] = p2[2];
      vcall<void>(rooms[i], 0x94, mat, vec);
      n += vcall<u32>(rooms[i], 0x344, a + n, b, type, mat, vec, p3, start, second);
    }
  }
  if (first)
    return vcall<u32>(self, 0x7c, a + n, b, type, p1, p2, p3, start, second) + n;
  return n;
}
PCREG(4ecf50, getGeomsInBox);
