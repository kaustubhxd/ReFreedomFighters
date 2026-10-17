// batch772.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void STDCALL ext_65f1e0(u8 *p, float f);   // original, stdcall ret 8 (stores f at +0x40, sets +0x24 bit 0)

typedef u8 *(THISCALL *VOneWord)(u8 *, u32);   // vt[0x2c]: ecx = object, one stack word, callee cleans (ret 4)
typedef void(__attribute__((cdecl)) *Fn2)(u32, u32);

// 0x63ea90, thiscall(arg) ret 4, returns bool-like byte (al). r = this->vt[0x2c](arg); return byte [r+1].
static u8 THISCALL flagByteOf_63ea90(u8 *self, u32 arg) {
  VOneWord f = (VOneWord)(*(u32 *)(*(u32 *)self + 0x2c));
  u8 *r = f(self, arg);
  return r[1];
}
PCREG(63ea90, flagByteOf_63ea90);

// 0x633170, cdecl(a, obj), no return value used. The original pushes obj->w first and a second (so the callee's first
// word is w = [obj+0x28] and its second is a). fn = [obj+0x24]. The C call below pushes its arguments in the same order.
static void __attribute__((cdecl)) callStored_633170(u32 a, u8 *obj) {
  Fn2 fn = (Fn2)(*(u32 *)(obj + 0x24));
  fn(*(u32 *)(obj + 0x28), a);
}
PCREG(633170, callStored_633170);

// 0x63f070, thiscall(p, f) ret 8. The original computes this+0x8270 and then calls 0x65f1e0(p, f). The port does the
// same call; the address is not used by the callee.
static void THISCALL forwardFloat_63f070(u8 *self, u8 *p, float f) {
  (void)self;
  ext_65f1e0(p, f);
}
PCREG(63f070, forwardFloat_63f070);
