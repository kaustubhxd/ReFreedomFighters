// batch1021.cpp - unclaimed-07 batch 21 (slice 6, small leaves): ZBaseGeom::IsMovingObject and ZStdObjBox::CalcCenSize.
// Names from the GC name map (medium and high). Bodies from the PC bytes.
#include "ff.h"

// 0x43df70: thiscall, no arguments (original code, hooked in the spec).
extern "C" void THISCALL ext_43df70(u8 *self);
// 0x4db7c0: thiscall, one argument, ECX = the object at this+8 (original code, hooked in the spec).
extern "C" void THISCALL ext_4db7c0(u8 *obj, u8 *arg);

// 0x4db9e0, ZBaseGeom::IsMovingObject() const (medium): p = this+0x54; when p, q = p+0x10; when q, the result is bit 2 of
// the byte at q+0x18. Otherwise false. (ret=None: the caller tests al.)
static bool THISCALL baseGeomIsMovingObject(u8 *self) {
  u8 *p = *(u8 **)(self + 0x54);
  if (!p)
    return false;
  u8 *q = *(u8 **)(p + 0x10);
  if (!q)
    return false;
  return (*(q + 0x18) & 2) != 0;
}
PCREG(4db9e0, baseGeomIsMovingObject);

// 0x45b060, ZStdObjBox::CalcCenSize() (high): ext_43df70(this); ext_4db7c0(this+8 object, this+0x18).
static void THISCALL stdObjBoxCalcCenSize(u8 *self) {
  ext_43df70(self);
  ext_4db7c0(*(u8 **)(self + 8), self + 0x18);
}
PCREG(45b060, stdObjBoxCalcCenSize);
