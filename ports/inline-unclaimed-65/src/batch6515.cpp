// batch6515.cpp - unclaimed-65: batch 15 (docs/20-unclaimed-65.md, claim 15). Thiscall, two stack arguments (ret 8). SEH frame not
// reproduced: the fs:[0] writes are not compared; the cookie check is not called.
#include "ff.h"

extern "C" void THISCALL ext_4ccba0(u8 *loc);           // builds the local struct (plain)
extern "C" void THISCALL ext_4ccf60(u8 *loc);           // releases it (plain)
extern "C" u32 THISCALL ext_4e6330(u8 *dbread, u8 *loc);  // DBREAD read into the struct (one argument, ret 4)

typedef u32(THISCALL *F0)(u8 *self);
static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }

// 0x4c7aa0, ZBoundDeactivateRegister::Init(ZGEOM*, DBREAD&) (residue 18). The first argument is not used.
static void THISCALL boundDeactivateRegisterInit(u8 *self, u8 *geom, u8 *dbread) {
  (void)geom;
  u8 loc[0xc0];
  ext_4ccba0(loc);
  ext_4e6330(dbread, loc);
  vc0(self, 0x58);
  ext_4ccf60(loc);
}
PCREG(4c7aa0, boundDeactivateRegisterInit);
