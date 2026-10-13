// batch796.cpp - unclaimed-77 claims 31 to 34 (docs/20-unclaimed-77.md), residue 4 rows. The base-destructor thunk 0x43de70 is stubbed (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);   // stubbed (GUESS): plain thiscall, logs ecx

// 0x64fb80, ZRender::GetClippedPrimTriangles (medium): no body; ret 0x20 (eight stack arguments, not read).
static void THISCALL renderGetClippedPrimTriangles(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  (void)self; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7; (void)a8;
}
PCREG(64fb80, renderGetClippedPrimTriangles);

// 0x608140, GUESS FUN_608140: stores the vtable 0x6bc884 at this.
static void THISCALL guessFun608140(u8 *self) {
  *(u32 *)self = 0x6bc884u;
}
PCREG(608140, guessFun608140);

// 0x612140, ZRender::ShadowMode() const (medium): returns the byte at this+0x1e.
static u8 THISCALL renderShadowMode(u8 *self) {
  return self[0x1e];
}
PCREG(612140, renderShadowMode);

// 0x44c400, GUESS FUN_44c400: stores the vtable 0x67ff2c at this, then tail-jumps to 0x43de70 (forwarded here as a plain call).
static void THISCALL guessFun44c400(u8 *self) {
  *(u32 *)self = 0x67ff2cu;
  ext_43de70(self);
}
PCREG(44c400, guessFun44c400);
