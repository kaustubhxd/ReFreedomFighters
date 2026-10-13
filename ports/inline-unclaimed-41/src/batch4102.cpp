// batch4102.cpp - unclaimed-41 batch 2 (residue 13): ZFFActorIf::collectOpaqueInfo(OpaqueObjectSerialBuffer_t&).
#include "ff.h"

// 0x5095b0, the base-class collect (original code, not lifted here): thiscall with one stack argument (the buffer, ret 4).
// A checksum stub in the spec (GUESS: its effects are not modelled).
extern "C" void THISCALL ext_5095b0(u8 *self, u32 buf);

// 0x55ebd0, ZFFActorIf::collectOpaqueInfo(OpaqueObjectSerialBuffer_t&) (high): thiscall, one stack argument (ret 4).
// ext_5095b0(this, buf); v = this.vt[+0x38](); buf.vt[+0](v) (the PC calls slot 0 of the buffer's vtable with ecx = buf).
static void THISCALL ffActorIfCollectOpaqueInfo(u8 *self, u8 *buf) {
  typedef u32(THISCALL * f38_t)(u8 *);
  typedef void(THISCALL * f0_t)(u8 *, u32);
  ext_5095b0(self, (u32)buf);
  u32 v = (*(f38_t *)(*(u32 *)self + 0x38))(self);
  (*(f0_t *)(*(u32 *)buf + 0))(buf, v);
}
PCREG(55ebd0, ffActorIfCollectOpaqueInfo);
