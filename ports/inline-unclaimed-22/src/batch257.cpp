// batch257.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch257"): finding or creating
// the action controller that runs scripted actions. Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_4dc630(u8 *geom, u32 a, u32 b);   // ZBaseGeom::SetControl (hooked, GUESS stub; blocked in docs/20)

typedef void(__attribute__((cdecl)) * log0_t)(void *, const char *);

// 0x4a0d40 CActionController::GetCurrentController(bool create): static, the bool arrives in cl. Looks up
// "rActionController" (db->vt[0x138]()->vt[0x88](name, &h)); with a handle, [0x70038c]->vt[0xcc](h) is returned when
// nonzero. Otherwise returns 0 unless create: then (db +0xadc)->vt[0x294]("ActionController", "ZLIST", 0, 1) makes a list
// geom, ->vt[0x10c]("ZLIST_ActionController", -1) the controller; none logs "Unable to create actioncontroller"
// (action.cpp line 0x206) and returns 0; else list->vt[0x154](), list->vt[0x124](1, 0, 0, 0), SetControl(list +8,
// 0x800000, 0), and the controller is returned. Arities are proven by the pops before the frame restore at 0x4a0e03/0x4a0e37.
static u32 THISCALL getCurrentController_4a0d40(u32 ecxArg) {
  u8 create = (u8)ecxArg;
  u8 *db = *(u8 **)(*(u8 **)0x70039cu + 0x9b);
  u8 *scene = (u8 *)vcall<u32>(db, 0x138);
  u32 h = 0;
  vcall<void>(scene, 0x88, 0x68f724u, (u32)&h);
  if (h) {
    u32 ctl = vcall<u32>(*(u8 **)0x70038cu, 0xcc, h);
    if (ctl) return ctl;
  }
  if (!create) return 0;
  u8 *mk = *(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x9b) + 0xadc);
  u8 *lst = (u8 *)vcall<u32>(mk, 0x294, 0x68f548u, 0x67f610u, 0u, 1u);
  u32 ctl = vcall<u32>(lst, 0x10c, 0x686060u, 0xffffffffu);
  if (!ctl) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x68f6b4u, 0x206u);
    (*(log0_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x68f738u);
    return 0;
  }
  vcall<void>(lst, 0x154);
  vcall<void>(lst, 0x124, 1u, 0u, 0u, 0u);
  ext_4dc630(*(u8 **)(lst + 8), 0x800000u, 0u);
  return ctl;
}
PCREG(4a0d40, getCurrentController_4a0d40);
