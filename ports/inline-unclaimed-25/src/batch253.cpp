// batch253.cpp - unclaimed area 25, slice floor(addr/16) mod 20 == 4.
#include "ff.h"

extern "C" void THISCALL ext_51f200(u8 *self, u8 *buf);   // first step of the opaque walk, original code (ret 4)

typedef u32 (THISCALL *F0)(u8 *self);
typedef void (THISCALL *V1)(u8 *self, u32 a);

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x51b5c0, thiscall, ret 4 (one stack argument: buf, an OpaqueObjectSerialBuffer_t&). ZCarIf::collectOpaqueInfo (map name,
// body checked). ext_51f200(this, buf) runs first; then r = this->vslot[0x38](this), and buf->vslot[0](buf, r).
static void THISCALL collectOpaqueInfo(u8 *selfP, u8 *bufP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 buf = (u32)(unsigned long)bufP;
  ext_51f200(selfP, bufP);
  u32 r = ((F0)rdw(rdw(self, 0), 0x38))(selfP);
  ((V1)rdw(rdw(buf, 0), 0))(bufP, r);
}
PCREG(51b5c0, collectOpaqueInfo);
