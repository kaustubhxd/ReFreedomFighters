// batch1068.cpp - ZFFCam::CheckCollisions (0x5c9ba0; the ZFFCam variant). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_5c9910(void *self);                          // ZFFCam::CalcCollisionParameters (batch 1067)
extern "C" FASTCALL long double ext_4e0870(const float *a, const float *b);  // |a - b| in st0 (a float)

// 0x5c9ba0 ZFFCam::CheckCollisions(void) (thiscall): the offset rays are cast through the manager's +0xadc object
// (slot 0x2e0). Each ray's distance goes to the record at idx * 0x82 + 0xd9 (idx 1..4, wrapping), the centre ray (idx 0,
// at +0x6c / +0x94 / +0xd9) is cast too, and the nearest hit is kept (index in +0x64, flag in +0x30a). A hit closer
// than +0x2f6 + 0.000122 calls the object's own slot 0xc4. Returns the flag.
static THISCALL u8 ZFFCam_CheckCollisions(u8 *self) {
  ext_5c9910(self);
  u32 idx = at<u32>(self, 0x68) * 0x82u;
  at<u32>(self, 0x64) = 0xffffffffu;
  at<float>(self, idx + 0xa0) = 1.0f;
  u8 *obj = at<u8 *>(SYS9B, 0xadc);
  u8 hit = (u8)vcall<u32>(obj, 0x2e0, (void *)(self + idx + 0x6c), 0u, 0x40u, 0x200000u, 1u, 0u);
  if (hit) {
    at<float>(self, idx + 0xd9) = (float)ext_4e0870((const float *)(self + idx + 0x94), (const float *)(self + idx + 0x6c));
  } else {
    at<float>(self, idx + 0xd9) = bitsf(0x47c35000u);   // 100000.0
  }
  at<u32>(self, 0x68) = at<u32>(self, 0x68) + 1;
  if (at<u32>(self, 0x68) >= 5) at<u32>(self, 0x68) = 1;
  at<float>(self, 0xa0) = 1.0f;
  obj = at<u8 *>(SYS9B, 0xadc);
  hit = (u8)vcall<u32>(obj, 0x2e0, (void *)(self + 0x6c), 0u, 0x40u, 0x200000u, 1u, 0u);
  at<u8>(self, 0x30b) = hit;
  if (hit) {
    at<float>(self, 0xd9) = (float)ext_4e0870((const float *)(self + 0x94), (const float *)(self + 0x6c));
  } else {
    at<float>(self, 0xd9) = bitsf(0x47c35000u);
  }
  if (at<u32>(self, 0x68) != 1 && !at<u8>(self, 0x30b)) return at<u8>(self, 0x30a);
  float nearest = bitsf(0x47c35000u);   // 0x68af2c: 100000.0 (the initial minimum)
  at<u8>(self, 0x30a) = 0;
  if (nearest > at<float>(self, 0xd9)) {
    at<u8>(self, 0x30a) = 1;
    at<u32>(self, 0x64) = 0;
    nearest = at<float>(self, 0xd9);
  }
  for (u32 k = 1; k <= 4; k++) {
    float d = at<float>(self, 0xd9 + k * 0x82u);
    if (nearest > d) {
      at<u8>(self, 0x30a) = 1;
      at<u32>(self, 0x64) = k;
      nearest = d;
    }
  }
  if (at<u8>(self, 0x30a)) {
    float reach = at<float>(self, 0x2f6) + bitsf(0x39000000u);   // 0x679540: 0.000122
    if (reach > nearest) vcall<void>(self, 0xc4);
  }
  return at<u8>(self, 0x30a);
}
PCREG(5c9ba0, ZFFCam_CheckCollisions);
