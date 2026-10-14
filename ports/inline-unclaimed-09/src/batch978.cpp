// batch978.cpp - area 56 band, claim A44 (0x534510): frees and one virtual call; void.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);  // original exe free (cdecl, hooked in the spec)

// A44 0x534510: free(this+8, 1); this+8 = 0; p = this->0: vt[0](p, 1), free(this+4, 4), this->0 = this->4 = 0; then this+0x100c
// and this+0x1010 = 0.
static void THISCALL cleanup534510(u8 *self) {
  u8 *p8 = *(u8 **)(self + 8);
  if (p8) ext_634273(p8, 1);
  u8 *p = *(u8 **)self;
  *(u32 *)(self + 8) = 0;
  if (p) {
    u8 *vt = *(u8 **)p;
    ((void(THISCALL *)(u8 *, u32))(*(u32 *)vt))(p, 1);
    ext_634273(*(u8 **)(self + 4), 4);
    *(u32 *)self = 0;
    *(u32 *)(self + 4) = 0;
  }
  *(u32 *)(self + 0x100c) = 0;
  *(u32 *)(self + 0x1010) = 0;
}
PCREG(534510, cleanup534510);
