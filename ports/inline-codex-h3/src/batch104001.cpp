#include "ff.h"
extern "C" void THISCALL ext_460af0(u8*, u8*, u8*, float);
extern "C" float FASTCALL ext_4e0030(u8*, u8*);
extern "C" void FASTCALL ext_446ee0(u8*, u8*, u8*);
static float THISCALL sample_map_angle(u8* self, float a, float b) {
  u8* map = G(u8*, self + 0x4b);
  if (!map) return 0.0f;
  u8 first[12], second[12], cross[12];
  ext_460af0(map + 0x1c, cross, first, a);
  float t = a + (b / G(float, self + 0x53)) * G(float, self + 0x20);
  if (!(t < 0.0f)) { float cap = G(float, 0x678858); if (cap < t) t = cap; }
  ext_460af0(map + 0x1c, second, cross, t);
  float angle = ext_4e0030(cross, second);
  ext_446ee0(cross, first, second);
  if (G(float, cross + 8) < 0.0f) angle = bitsf(fbits(angle) ^ G(u32, 0x67af40));
  return angle;
}
PCREG(522f60, sample_map_angle);
