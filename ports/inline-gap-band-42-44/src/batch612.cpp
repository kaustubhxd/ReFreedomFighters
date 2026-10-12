// batch612.cpp - band 0x421000-0x441000, batch 612: two methods.
//   0x429ab0 (thiscall, no arguments, returns al = 1): calls vslot 0x2c of this; if [this+0xd] is set, calls its vslot 8
//     with the object itself as the one argument, then clears the dword at [this+0xd]. The first call is unconditional.
//   0x4331f0 (thiscall, one byte argument): if the low byte of [this+0x101] differs from the argument, store it and notify
//     0x431580(this, 0x67a058, value) where value = 1 when the argument is 0, else 0 (sete). Notify is hooked in the spec.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
typedef u32(THISCALL *vNone)(void *self);
extern "C" void THISCALL ext_431580(void *self, u32 name, u32 value);  // notify helper (thiscall, ret 8)

static u8 THISCALL releaseSelf(u8 *self) {
  ((vNone)VT(self, 0x2c))(self);
  u8 *o = *(u8 **)(self + 0xd);
  if (o) {
    ((vOne)VT(o, 8))(o, (u32)o);
    *(u32 *)(self + 0xd) = 0;
  }
  return 1;
}
PCREG(429ab0, releaseSelf);

static void THISCALL setByte101(u8 *self, u32 arg) {
  u8 v = (u8)arg;
  if (*(u8 *)(self + 0x101) == v)
    return;
  *(u8 *)(self + 0x101) = v;
  ext_431580(self, 0x67a058, v == 0 ? 1u : 0u);
}
PCREG(4331f0, setByte101);
