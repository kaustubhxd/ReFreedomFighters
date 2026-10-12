// batch815.cpp - unclaimed-08 batch 15: ZBoundDeactivator::Init(ZGEOM*, DBREAD&) (medium name). Slice: floor(addr/16) mod 20 = 7.
// Thiscall, two stack arguments (ret 8), void. The body: construct a REFTAB local (0x4ccba0, original code), call
// DBREAD::GetRefTab(&local) on the DBREAD argument (0x4e6330, stubbed in the spec: it writes nothing and its stack argument
// is not logged), destroy the local (0x4ccf60, original code). The geometry argument is not read.
#include "ff.h"

extern "C" void THISCALL ext_4ccba0(void *);
extern "C" void THISCALL ext_4ccf60(void *);
extern "C" void THISCALL ext_4e6330(void *, void *);

// 0x4c7b30, ZBoundDeactivator::Init(ZGEOM*, DBREAD&) (medium name).
static void THISCALL boundDeactivatorInit(u8 *self, void *geom, void *dbread) {
  (void)self;
  (void)geom;
  alignas(8) u8 tab[0xb0];
  ext_4ccba0(tab);
  ext_4e6330(dbread, tab);
  ext_4ccf60(tab);
}
PCREG(4c7b30, boundDeactivatorInit);
