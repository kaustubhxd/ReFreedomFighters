// batch316.cpp - 0x45d1e0 (area 43, 2026-10-12). Two stack arguments (none used), ret 8, returns false (al = 0).
#include "ff.h"

static bool STDCALL returnFalse2(u32 a, u32 b) {
  (void)a;
  (void)b;
  return false;
}
PCREG(45d1e0, returnFalse2);
