// batch337.cpp - 0x478420 (area 71 leaf, residue 10). stdcall, three stack arguments (x, a, b), ret 0xc, returns a float in ST0.
// Body: if x == 0.0 (unordered counts as not equal): return 0. Else return ((x - b) * a) / (x * x).
#include "ff.h"

static float STDCALL ratioOfDifference(float x, float a, float b) {
  if (x == 0.0f)
    return 0.0f;
  return ((x - b) * a) / (x * x);
}
PCREG(478420, ratioOfDifference);
