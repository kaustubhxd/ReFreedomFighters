#include "ff.h"
// batch2701.cpp - unclaimed-27 claim 1 (docs/20-unclaimed-27.md). Names from the GC name map (high).

// 0x475910 is original code (bound by build.sh as ext_475910): thiscall, ret 4; sets the byte at this+0x3bb to (arg != 0).
extern "C" void THISCALL ext_475910(u8 *self, u32 a1);

// 0x484320, ZPlayer::MoveToMatPos(const float*, const float*) (high). Thiscall, ret 8.
// Builds a local vector: local[0] = in[0], local[1] = (float at this+0x451) + in[1], local[2] = in[2]; then calls vtable
// slot +0x5b0 with (a1, &local). a1 is the first argument, passed through unchanged.
static void THISCALL zPlayerMoveToMatPos(u8 *self, u32 a1, const float *in) {
  float local[3];
  local[0] = in[0];
  local[1] = *(float *)(self + 0x451) + in[1];
  local[2] = in[2];
  typedef void(THISCALL * slot5b0_fn)(u8 *, u32, float *);
  ((slot5b0_fn)(*(u32 *)(*(u32 *)self + 0x5b0)))(self, a1, local);
}
PCREG(484320, zPlayerMoveToMatPos);

// 0x484fa0, ZPlayer::SetDialog(bool) (high). Thiscall, ret 4.
// If the low byte of the argument is 0 and vtable slot +0x534 returns nonzero (low byte), calls vtable slot +0x220 with 0.
// Then calls 0x475910 with the argument (the dword) on every path.
static void THISCALL zPlayerSetDialog(u8 *self, u32 a1) {
  if ((u8)a1 == 0) {
    typedef u8(THISCALL * slot534_fn)(u8 *);
    if (((slot534_fn)(*(u32 *)(*(u32 *)self + 0x534)))(self) != 0) {
      typedef void(THISCALL * slot220_fn)(u8 *, u32);
      ((slot220_fn)(*(u32 *)(*(u32 *)self + 0x220)))(self, 0u);
    }
  }
  ext_475910(self, a1);
}
PCREG(484fa0, zPlayerSetDialog);
