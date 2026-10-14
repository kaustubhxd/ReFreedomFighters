// batch1630.cpp - ZDllSound::AdjustExit (soundtimers thread, 2026-10-11).
#include "st.h"

// 0x5354a0 ZDllSound::AdjustExit(uint index, float openness) [high]: the sound graph's exit record at index
// (0xa4 bytes each, base = graph +0x11f9, count = graph +0x11e9) gets its openness at +8. index -1 does nothing;
// an index past the count logs "ERROR: Adjust exit - index % out of range" (sound.cpp line 0x584) and stops; an
// openness below 0 or above 1.0 logs "openness out of range %7.4f" (line 0x588) and is stored anyway (NaN is not
// logged, as the original's compares).
void THISCALL ZDllSound_AdjustExit(u8 *self, u32 index, float openness) {
  u8 *g = AT(u8 *, self, 0x52fe);
  if (!g) return;
  if (index == 0xffffffffu) return;
  void *log = G(void *, 0x700390);
  if (index >= AT(u32, g, 0x11e9)) {
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6a1e2c, (u32)0x584);
    typedef void (*Print)(void *, const char *, u32);
    (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6a2130, index);
    return;
  }
  if (0.0f > openness || openness > 1.0f) {  // comiss with 1.0 at 0x678858; NaN falls through
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6a1e2c, (u32)0x588);
    typedef void (*PrintD)(void *, const char *, double);
    (*(PrintD *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6a215c, (double)openness);
  }
  u8 *base = AT(u8 *, AT(u8 *, self, 0x52fe), 0x11f9);
  AT(float, base, index * 0xa4 + 8) = openness;
}
PCREG(5354a0, ZDllSound_AdjustExit);
