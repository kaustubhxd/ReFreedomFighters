// batch3004.cpp - unclaimed-30: batch 4 (docs/20-unclaimed-30.md, claim 1). CFFTargetList::Init(arg, DBREAD&) [map 0x5b23d0;
// thiscall, ret 8]. The DBREAD flag (0x4e5e60, original code patched by the harness) picks the name string (0x6b1908 when set,
// else 0x6acfbc). The message table's collision object is asked for an object by name (slot 0x25c); when none comes back, the
// object is made (slot 0x294) and set up (slot 0x154, the exe's 0x4dc630 on its +8, slot 0x124). Either way the object takes
// arg (slot 0x218), and this's slot 0x58 is called last.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);                    // DBREAD::operator unsigned int (patched in the harness)
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a1, u32 a2);     // exe code (ret 8)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static void THISCALL cfTargetListInit(u8 *self, u32 arg, u8 *dbread) {
  u32 cond = ext_4e5e60(dbread);
  u32 name = cond ? 0x6b1908u : 0x6acfbcu;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *msg = *(u8 **)(eng + 0x9b);
  u8 *coll = *(u8 **)(msg + 0xadc);
  u8 *o = (u8 *)vcall<u32>(coll, 0x25c, name, (u32)0);
  if (!o) {
    o = (u8 *)vcall<u32>(coll, 0x294, name, (u32)0x67f610, (u32)0, (u32)1);
    vcall<void>(o, 0x154);
    ext_4dc630(rdp(o + 8), 0x800000u, 0u);
    vcall<void>(o, 0x124, 1u, 0u, 0u, 0u);
  }
  vcall<void>(o, 0x218, arg);
  vcall<void>(self, 0x58);
}
PCREG(5b23d0, cfTargetListInit);
