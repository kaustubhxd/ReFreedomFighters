// batch6502.cpp - unclaimed-65: batch 2 (docs/20-unclaimed-65.md, claim 2). Thiscall. Callees are original code (ext_), replaced
// by logging stubs in the harness. The render object is at [0x70039c]+0x9b.
#include "ff.h"

extern "C" void THISCALL ext_4609e0(u8 *self);
extern "C" void THISCALL ext_45c3e0(u8 *self);
extern "C" void ext_45c510(u8 *self);
extern "C" void ext_4690b0(u8 *self, u32 size);
extern "C" void ext_634273(void *p, u32 size);

typedef u32(THISCALL *Vfn0)(u8 *self);
typedef u32(THISCALL *Vfn1)(u8 *self, u32 a);
typedef u32(THISCALL *Vfn2)(u8 *self, u32 a, u32 b);

// 0x44a960, ZSHAPE::~ZSHAPE() (residue 18): vtable := 0x67f874; operator delete of 0x38 bytes when the pointer at +0x18 is set;
// member destructor at +0x1c; base destructor; then with bit 0 of the flag set: bit 2 selects 0x4690b0(this, 0x30), else
// 0x45c510(this). Returns this.
static u8 *THISCALL shapeDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x67f874;
  u8 *inner = *(u8 **)(self + 0x18);
  if (inner) ext_634273(inner, 0x38);
  ext_4609e0(self + 0x1c);
  ext_45c3e0(self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4)
      ext_4690b0(self, 0x30);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(44a960, shapeDtor);

// 0x5879e0, CFFCoverList::Init2() (residue 18): R = [0x70039c]+0x9b; X = R's slot +0x138 (no arguments); X's slot +0x88 with the
// name 0x681320 and &tmp (writes tmp); then the dword at +0x6f becomes R's slot +0x58 with tmp.
static void THISCALL coverListInit2(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *r = *(u8 **)(rm + 0x9b);
  u8 *x = (u8 *)((Vfn0)(*(const u32 *)(*(const u32 *)r + 0x138)))(r);
  u32 tmp = 0;
  ((Vfn2)(*(const u32 *)(*(const u32 *)x + 0x88)))(x, 0x681320, (u32)&tmp);
  rm = G(u8 *, 0x70039c);
  r = *(u8 **)(rm + 0x9b);
  *(u32 *)(self + 0x6f) = ((Vfn1)(*(const u32 *)(*(const u32 *)r + 0x58)))(r, tmp);
}
PCREG(5879e0, coverListInit2);
