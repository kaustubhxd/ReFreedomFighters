// batch3019.cpp - unclaimed-30: batch 19 (docs/20-unclaimed-30.md, claim 1). Unnamed in the name map: 0x5cfd90 [thiscall, one stack
// argument (out), returns al]. The object has a count at +0x48 and 20-byte records from +0x4c (the vector at record+4). The reference
// vector is the three floats at +0xc71. For each record: d = squared distance from the record's vector to the reference (exe 0x4e0830);
// the record is a candidate when 640000 <= d <= 12250000 and g = 0x5cf5d0(record vector) is not greater than 0.2617993950843811; the
// nearest candidate (strictly smaller d, starting from 12250000) is kept. If one was found, its vector goes to out and al = 1.
#include "ff.h"

extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);   // squared distance (exe; ret 0)
extern "C" float THISCALL ext_5cf5d0(u8 *self, const float *v);          // exe helper: float result in ST0 (ret 4)

static bool THISCALL nearestRecord(u8 *self, float *out) {
  u32 count = *(const u32 *)(self + 0x48);
  u8 *end = self + 0x4c + 20 * count;
  float bestd = 12250000.0f;
  u8 *best = end;
  for (u8 *rec = self + 0x4c; rec != end; rec += 20) {
    float v[3] = {*(const float *)(self + 0xc71), *(const float *)(self + 0xc75), *(const float *)(self + 0xc79)};
    float d = ext_4e0830((const float *)(rec + 4), v);
    bool take = !(640000.0f > d) && !(d > 12250000.0f);
    if (take) {
      float g = ext_5cf5d0(self, (const float *)(rec + 4));
      take = !(g > 0.2617993950843811f);
    }
    if (take && !(bestd <= d)) {
      bestd = d;
      best = rec;
    }
  }
  if (best != end) {
    out[0] = *(const float *)(best + 4);
    out[1] = *(const float *)(best + 8);
    out[2] = *(const float *)(best + 0xc);
    return true;
  }
  return false;
}
PCREG(5cfd90, nearestRecord);
