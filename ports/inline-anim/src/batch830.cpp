// batch830.cpp - animation layer thread, batch 830: ZIKLNKOBJ scalar deleting destructor and CopyData(ZGEOM*).
#include "ff.h"

extern "C" void THISCALL ext_465660(void *self);           // ZIKLNKOBJ base destructor body (not ported here)
extern "C" void ext_45c510(void *p);                        // ZGEOM::operator delete (cdecl, 1 arg)
extern "C" void ext_4690b0(void *self, u32 code);           // error/leak-check hook used when the object is not heap-owned (cdecl)
extern "C" void THISCALL ext_45d5b0(void *self, void *geom);   // ZGEOM::CopyData (not ported here)

// ZIKLNKOBJ::~ZIKLNKOBJ() [medium], scalar deleting form: flag bit 0 = delete the storage. If the flag's
// bit 2 is clear the storage goes back through ZGEOM::operator delete; if set, the leak hook (code 0x1d2) runs instead.
// Returns this.
static void *THISCALL ZIKLNKOBJ_dtor(void *self, u32 flag) {
  ext_465660(self);
  if (flag & 1) {
    if (!(flag & 4)) ext_45c510(self);
    else ext_4690b0(self, 0x1d2);
  }
  return self;
}
PCREG(465720, ZIKLNKOBJ_dtor);

// ZIKLNKOBJ::CopyData(const ZGEOM* g) [medium]: the geometry base copy, then (when g is of class 0x200006)
// this->vt +0x2e4(g).
static void THISCALL CopyData(void *self, void *g) {
  ext_45d5b0(self, g);
  if (vcall<bool>(g, 0x1e0, 0x200006u)) vcall<void>(self, 0x2e4, g);
}
PCREG(462000, CopyData);
