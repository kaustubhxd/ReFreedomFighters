// batch849.cpp - area 50 (residue-10 list): ZCar::Load(ZLoadGame*) [0x517f20, 171 instr, callee pops 4, returns bool].
// The vehicle load (ZVehicle::Load, 0x5159b0, the vehicles area's function, exe code) first; if it fails the result is
// false. Then the undercarriage load (0x525bc0, stood in by the harness) and the car's own fields through the load
// object's slots: 0x6c vectors (+0x15d3, +0x15df, +0x15eb), 0x50 floats (+0x15f7, +0x15fb, +0x15ff, +0x1607, +0x1610,
// +0x163d, +0x1641), 0x18 4-byte blocks (+0x1603, +0x160c), 0x68 bytes (+0x160b, +0x1614, +0x1649), 0x40 dwords (+0x1615,
// +0x1619, +0x161d, +0x1621, +0x1625, +0x1629, +0x162d, +0x1631), 0x48 dwords (+0x1635, +0x1639, +0x1645). These are the
// mirror of ZCar::Save (batch946 in the vehicles area: 0x68 -> 0x6c, 0x4c -> 0x50, 0x10 -> 0x18, 0x60 -> 0x68, 0x3c -> 0x40,
// 0x44 -> 0x48). Last, the script object: render manager slot 0x138 gives an object, its slot 0x88 writes an id for the
// name 0x681320, and the manager's slot 0x58 resolves the id into +0x164a.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// the engine's global manager (the object at [[0x70039c]+0x9b])
static inline void *FP_mgr() { return FP(G(void *, 0x70039c), 0x9b); }

extern "C" u8 THISCALL ext_5159b0(void *self, void *ls);   // ZVehicle::Load (vehicles area; exe code)
extern "C" void THISCALL ext_525bc0(void *uc, void *ls);   // CUnderCarriage load (not ported here; stood in by the harness)

// 0x517f20 ZCar::Load(ZLoadGame*).
static bool THISCALL ZCar_Load(u8 *self, void *ls) {
  if (!ext_5159b0(self, ls))
    return false;
  ext_525bc0(self + 0x2d8, ls);
  vcall<void>(ls, 0x6c, (u32)(self + 0x15d3));
  vcall<void>(ls, 0x6c, (u32)(self + 0x15df));
  vcall<void>(ls, 0x6c, (u32)(self + 0x15eb));
  vcall<void>(ls, 0x50, (u32)(self + 0x15f7));
  vcall<void>(ls, 0x50, (u32)(self + 0x15fb));
  vcall<void>(ls, 0x50, (u32)(self + 0x15ff));
  vcall<void>(ls, 0x18, (u32)(self + 0x1603), 4u);
  vcall<void>(ls, 0x50, (u32)(self + 0x1607));
  vcall<void>(ls, 0x68, (u32)(self + 0x160b));
  vcall<void>(ls, 0x18, (u32)(self + 0x160c), 4u);
  vcall<void>(ls, 0x50, (u32)(self + 0x1610));
  vcall<void>(ls, 0x68, (u32)(self + 0x1614));
  vcall<void>(ls, 0x40, (u32)(self + 0x1615));
  vcall<void>(ls, 0x40, (u32)(self + 0x1619));
  vcall<void>(ls, 0x40, (u32)(self + 0x161d));
  vcall<void>(ls, 0x40, (u32)(self + 0x1621));
  vcall<void>(ls, 0x40, (u32)(self + 0x1625));
  vcall<void>(ls, 0x40, (u32)(self + 0x1629));
  vcall<void>(ls, 0x40, (u32)(self + 0x162d));
  vcall<void>(ls, 0x40, (u32)(self + 0x1631));
  vcall<void>(ls, 0x48, (u32)(self + 0x1635));
  vcall<void>(ls, 0x48, (u32)(self + 0x1639));
  vcall<void>(ls, 0x50, (u32)(self + 0x163d));
  vcall<void>(ls, 0x50, (u32)(self + 0x1641));
  vcall<void>(ls, 0x48, (u32)(self + 0x1645));
  vcall<void>(ls, 0x68, (u32)(self + 0x1649));
  void *obj = vcall<void *>(FP_mgr(), 0x138);
  u32 tmp = 0;
  vcall<void>(obj, 0x88, (u32)0x681320, &tmp);
  F32(self, 0x164a) = vcall<u32>(FP_mgr(), 0x58, tmp);
  return true;
}
PCREG(517f20, ZCar_Load);
