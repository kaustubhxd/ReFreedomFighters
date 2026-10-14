// batch244.cpp - parked row 0x47f680 (returns al only), ported with ret='al'. fastcall(a in ECX, b in EDX), plain ret.
// Returns 1 when the three float components compare equal (ucomiss with the parity check: a NaN component is not equal).
#include "ff.h"

static u8 FASTCALL vec3Equal_47f680(const float *a, const float *b) {
  if (!(a[0] == b[0])) return 0;
  if (!(a[1] == b[1])) return 0;
  if (!(a[2] == b[2])) return 0;
  return 1;
}
PCREG(47f680, vec3Equal_47f680);
