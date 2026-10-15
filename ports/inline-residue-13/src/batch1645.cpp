// batch1645.cpp - ZItemWeapon::CopyGeom(ZGEOM* self, ZGEOM* src, ZGROUP* grp, bool flag) (0x46d2d0, residue 13, 2026-10-12).
// STDCALL (four stack arguments, the first is the object). Calls the object's vtable +0x1c0 with (grp, 0x4954454d, 0, 0, 1)
// (the name map: ZItemWeapon[228] family, a lookup); on a found geom, sets its control 0x800000, optionally calls its
// vtable +0x2c, looks up "ItemState*" (+0x100) and passes the geom to that object's +0x54. It then reads the source's
// matrix (exe 0x4db2c0 into two local buffers at -0x34 and -0x10, 0x24 bytes apart) and feeds them to the geom's +0x74.
// Then it walks the geom's child list at +8 (vtable +0x50 writes the next child into the local): children without flag
// 0x800000 get +0x154, SetControl(0x800000, 0), two CallEvents (ids 1 and 2) and +0x158. Returns the geom or 0.
// GUESS: the names of the vtable slots, the strings and the child-list semantics are from the code only.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4dc630[];  // ZBaseGeom::SetControl (thiscall, two args)
extern "C" char ext_4db2c0[];  // ZBaseGeom::GetMatPos (thiscall, two args)
extern "C" char ext_4da340[];  // ZBaseGeom::CallEvents (thiscall, four args)

typedef void(THISCALL *SetCtrlFn)(void *self, u32 a, u32 b);
typedef void(THISCALL *GetMatPosFn)(void *self, void *a, void *b);
typedef void(THISCALL *CallEventsFn)(void *self, u32 a, u32 b, u32 c, u32 d);

u32 STDCALL ZItemWeapon_CopyGeom(u8 *self, u8 *src, u8 *grp, u8 flag) {
  u8 *geom = vcall<u8 *>(self, 0x1c0, (u32)grp, (u32)0x4954454d, (u32)0, (u32)0, (u32)1);
  if (!geom) return 0;
  ((SetCtrlFn)(void *)ext_4dc630)(AT(void *, geom, 8), 0, 0x800000u);
  if (flag) vcall<void>(geom, 0x2c);
  u8 *item = vcall<u8 *>(geom, 0x100, (u32)0x688854);
  if (item) vcall<void>(item, 0x54, geom);
  u8 buf[0x38];
  ((GetMatPosFn)(void *)ext_4db2c0)(AT(void *, src, 8), buf, buf + 0x24);
  vcall<void>(geom, 0x74, buf, buf + 0x24);
  u32 child = AT(u32, geom, 8);
  while (child) {
    u8 *c = (u8 *)child;
    if (!(AT(u32, c, 0x3c) & 0x800000u)) {
      u8 *c54 = AT(u8 *, c, 0x54);
      if (c54) vcall<void>(c54, 0x154);
      ((SetCtrlFn)(void *)ext_4dc630)(c, 0x800000u, 0);
      ((CallEventsFn)(void *)ext_4da340)(c, 1, 0, 0, 0);
      ((CallEventsFn)(void *)ext_4da340)(c, 2, 0, 0, 0);
      u8 *c54b = AT(u8 *, c, 0x54);
      if (c54b) vcall<void>(c54b, 0x158);
    }
    u32 next = child;   // the original reuses the child variable as the out pointer
    vcall<void>(geom, 0x50, &next);
    child = next;
  }
  return (u32)geom;
}
PCREG(46d2d0, ZItemWeapon_CopyGeom);
