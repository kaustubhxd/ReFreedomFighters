// batch1211.cpp - unclaimed-12: batch 11 (docs/20-unclaimed-12.md, claim 11, in slice). Thiscall; the callee pops the stack arg.
// Names are from the GC name map (high confidence).
#include "ff.h"

// 0x4b8ab0, the callee for an equal float (original code here; thiscall, one stack argument).
extern "C" void THISCALL ext_4b8ab0(u8 *self, void *arg);

typedef void(THISCALL *RelaySlotFn)(u8 *self, u32 a);

// 0x4b88f0, ZRelayMessageList::Command(unsigned short, void*) (high): the word argument must equal the word at +0x48.
// Then an ordered comparison of the float at +0x50 with 0.0: when equal, 0x4b8ab0 is called with the argument. Otherwise
// (also for NaN) the float at +0x54 becomes (float)(dword at [0x70039c]+0x40) * 2^-10, and virtual slot +0x64 of this is
// called with 0x10. The result is 0.
static u32 THISCALL relayMessageListCommand(u8 *self, u32 cmd, void *arg) {
  if ((u16)cmd == *(const u16 *)(self + 0x48)) {
    if (*(const float *)(self + 0x50) == 0.0f) {
      ext_4b8ab0(self, arg);
    } else {
      u8 *rm = G(u8 *, 0x70039c);
      const s32 value = *(const s32 *)(rm + 0x40);
      *(float *)(self + 0x54) = (float)value * G(float, 0x6785e4);
      RelaySlotFn fn = (RelaySlotFn)(*(const u32 *)(*(const u32 *)self + 0x64));
      fn(self, 0x10);
    }
  }
  return 0;
}
PCREG(4b88f0, relayMessageListCommand);

// 0x4b89d0, thiscall plain: t = cvtt(([this+0x54] + [this+0x50]) * constant 0x678620); when [[0x70039c]+0x40] >= t (signed): ext_4b8ab0(this, 0); this->slot0x68(0x10, 0).
static void THISCALL fn4b89d0(u8 *self) {
  __m128 s = _mm_add_ss(_mm_set_ss(*(float *)(self + 0x54)), _mm_set_ss(*(float *)(self + 0x50)));
  s32 t = _mm_cvttss_si32(_mm_mul_ss(s, _mm_set_ss(G(float, 0x678620))));
  if (*(s32 *)(G(u8 *, 0x70039c) + 0x40) < t) return;
  ext_4b8ab0(self, 0);
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(4b89d0, fn4b89d0);

