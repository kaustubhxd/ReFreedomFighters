// batch918.cpp - unclaimed-09 batch 10: ZRunParamAnim::Load(ZLoadGame*) (docs/20-unclaimed-09.md, claim 10).
// thiscall, one stack argument (the loader pointer), ret 4. The loader's vtable calls are unverified callees (stubbed).
#include "ff.h"

typedef void(THISCALL *LoadPtrCall)(u8 *self, u8 *p);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4e6f40, ZRunParamAnim::Load(ZLoadGame*) (medium): ld.vt[0x50](this+0xb8), ld.vt[0x68](this+0xbc),
// ld.vt[0x50](this+0xbd). ld is the argument; the loader fills the fields.
static void THISCALL runParamLoad(u8 *self, u8 *ld) {
  ((LoadPtrCall)slot(ld, 0x50))(ld, self + 0xb8);
  ((LoadPtrCall)slot(ld, 0x68))(ld, self + 0xbc);
  ((LoadPtrCall)slot(ld, 0x50))(ld, self + 0xbd);
}
PCREG(4e6f40, runParamLoad);
