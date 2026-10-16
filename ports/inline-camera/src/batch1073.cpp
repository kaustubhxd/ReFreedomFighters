// batch1073.cpp - two ICF-shared camera bodies (the class map lists several names for each address). Camera thread,
// 2026-10-12. The port follows the body only; the names are not confirmed by these functions alone.
#include "cam.h"

typedef void (*relfn)(void);

// 0x549de0 (no args): returns true. The class map names it ZCAMERA::DisableParentBoundAdjust and ZBaseCamera::Is1stPerson.
static THISCALL u8 ZCAM_ReturnTrue(u8 *self) {
  (void)self;
  return 1;
}
PCREG(549de0, ZCAM_ReturnTrue);

// 0x6368b0 (one stack arg): calls the global callback at 0x7003b0 (an unset callback is an int3 trap). The class map names it
// ZBaseCamera::GetCameraPosition, GetFocalOffset and GetFocalPos (the body is the same in all three).
static THISCALL void ZCAM_CallbackIfSet(u8 *self, float *out) {
  (void)self;
  (void)out;
  relfn cb = G(relfn, 0x7003b0);
  if (!cb) __builtin_trap();   // int3 in the original when unset (0x6368be)
  cb();
}
PCREG(6368b0, ZCAM_CallbackIfSet);
