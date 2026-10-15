// batch1071.cpp - ZCAMERA::GetScreenSelect (0x445e90, high confidence in the class map). Camera thread, 2026-10-12.
#include "cam.h"

extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b (vector add)

// 0x445e90 GetScreenSelect(SScreenSelect *out, bool, u32 index, float a4) (thiscall, four stack args; the bool is
// unused). A query vector (0, 0, +0x64 + a4) goes to the object's slot 0x84 and (0, 0, +0x68) to its slot 0x88; the
// manager's +0xadc object (slot 0x2e0) casts the ray and fills the hit record (position at +0x28..+0x30, id at +0x44).
// On a hit whose id the manager's slot 0x54 accepts, out = (hit position, id at +0xc) and the result is true. Otherwise
// out = query + query2 and the result is false. The hit record is 0x74 bytes; the constructor step (0x4e1b60) sets +0x34
// to 1.0, +0x44 to 0 and the byte at +0x6c to 1.
static THISCALL u8 ZCAMERA_GetScreenSelect(u8 *self, u8 *out, u32, u32 index, float a4) {
  u8 v1[0x74];
  float *q1 = (float *)v1;
  at<float>(v1, 0x34) = 1.0f;
  at<u32>(v1, 0x44) = 0;
  at<u8>(v1, 0x6c) = 1;
  float z1 = at<float>(self, 0x64) + a4;
  q1[0] = 0.0f;
  q1[1] = 0.0f;
  q1[2] = z1;
  vcall<void>(self, 0x84, (void *)v1);
  float q2[3] = {0.0f, 0.0f, at<float>(self, 0x68)};
  vcall<void>(self, 0x88, (void *)q2);
  u32 hit = vcall<u32>(at<u8 *>(SYS9B, 0xadc), 0x2e0, (void *)v1, 0u, index, (u32)-1, 1u, 1u);
  if (hit & 0xff) {
    u32 id = at<u32>(v1, 0x44);
    u32 r = vcall<u32>(SYS9B, 0x54, id);
    if (r & 0xff) {
      at<float>(out, 0) = at<float>(v1, 0x28);
      at<float>(out, 4) = at<float>(v1, 0x2c);
      at<float>(out, 8) = at<float>(v1, 0x30);
      at<u32>(out, 0xc) = id;
      return 1;
    }
  }
  ext_43e8e0((float *)out, q1, q2);
  return 0;
}
PCREG(445e90, ZCAMERA_GetScreenSelect);
