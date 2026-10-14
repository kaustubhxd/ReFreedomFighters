// batch863.cpp - area 50 (residue-9 candidate): 0x5cfd90 [99 instr, thiscall, one stack arg (the output vector), ret 4, returns
// bool; no name in the map (GUESS "nearest candidate record to the object's point")]. The records are 0x14 bytes each, from
// this+0x4c; the count is at this+0x48 (end = this + (5*count + 0x13)*4). For each record (its +4 part is the object): d = the
// distance from the point at this+0xc71 to the object (0x4e0830, exe); the record is a candidate when 640000 <= d is false,
// d <= 12250000, and e (0x5cf5d0, stood in) is not above 0.2617..., and d is below the best so far (the first best starts at
// 12250000). The output is the best record's three words at +4 (true) or false when there is none.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" float THISCALL ext_5cf5d0(void *self, void *obj);   // candidate value (stood in by the harness; ST0)
extern "C" float FASTCALL ext_4e0830(const void *obj, const float *v);   // distance from v to obj (exe; ST0)

// 0x5cfd90 (name GUESS).
static bool THISCALL Nearest5cfd90(u8 *self, float *out) {
  float bestKey = G(float, 0x6b4fd0);
  u8 *end = self + (U32(self, 0x48) * 5 + 0x13) * 4;
  u8 *best = end;
  for (u8 *p = self + 0x4c; p != end; p += 0x14) {
    float v[3] = {F32(self, 0xc71), F32(self, 0xc75), F32(self, 0xc79)};
    float d = ext_4e0830(p + 4, v);
    if (G(float, 0x6b4fcc) > d) continue;
    if (d > G(float, 0x6b4fd0)) continue;
    float e = ext_5cf5d0(self, p + 4);
    if (e > G(float, 0x69f9d4)) continue;
    if (!(bestKey > d)) continue;
    bestKey = d;
    best = p;
  }
  if (best == end) return false;
  out[0] = F32(best, 4);
  out[1] = F32(best, 8);
  out[2] = F32(best, 0xc);
  return true;
}
PCREG(5cfd90, Nearest5cfd90);
