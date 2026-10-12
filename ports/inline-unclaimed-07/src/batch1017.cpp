// batch1017.cpp - unclaimed-07 batch 17 (residue-07 list, slice 6 work): ZItemTemplateWeapon::ModifyState.
// Name from the GC name map (medium). Body from the PC bytes. ECX is not used by the function; the object is the argument.
#include "ff.h"

// 0x4d2280 and 0x4d2330: constructor and destructor of a local helper object (thiscall, no arguments; original code,
// hooked in the spec).
extern "C" void THISCALL ext_4d2280(u8 *obj);
extern "C" void THISCALL ext_4d2330(u8 *obj);

// 0x46f930, ZItemTemplateWeapon::ModifyState(CCom*) (medium), thiscall (this unused), ret 4. Calls com slot +0x88 with the
// name 0x68884c and an out value; the engine (0x70039c)+0x9b object's slot +0x58(out2) gets the value; com slot +0x88 with
// 0x688b18 and a third out value; a local helper object is constructed and destroyed; returns true.
static bool THISCALL itemTemplateWeaponModifyState(u8 *self, u8 *com) {
  (void)self;
  u32 out1 = 0, out2 = 0, out3 = 0;
  vcall<void>(com, 0x88, 0x68884cu, (u32)&out1);
  vcall<void>(com, 0x88, 0x688a30u, (u32)&out2);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  vcall<u32>(ctl, 0x58, out2);
  vcall<void>(com, 0x88, 0x688b18u, (u32)&out3);
  u8 local[0x40c4];
  ext_4d2280(local);
  ext_4d2330(local);
  (void)out1;
  (void)out3;
  return true;
}
PCREG(46f930, itemTemplateWeaponModifyState);
