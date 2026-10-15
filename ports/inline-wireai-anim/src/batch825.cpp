// batch825.cpp - animation layer thread, batch 825 (VM restart 2026-10-11): the soldier legs layer,
// ZActor::UpdateBaseMoveFrame (docs/36-parts/ub-anim.md section 4, row "soldier legs" and "soldier turn").
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" void ext_634dc4(void);                  // _CIfmod (CRT): fmod(ST1, ST0), pops one, result in ST0
extern "C" u32 THISCALL ext_478a80(void *mt);      // ZActor::SMoveType::GetAnimHeader() const (name map medium)

// ZActor::UpdateBaseMoveFrame() [GameCube reference, name map high], thiscall, no args.
// Move type = own slot 0x5a8(m_iQuePos +0x650); none, or byte +0x771 set -> nothing. Its clip is GetAnimHeader
// (inlined here: reference word + [[0x70039c]+0x9b]+0x44, 0 stays 0). Phase = (float)fmod((double)+0x755, 1.0).
// With a non-zero (or NaN) turn +0x76d and move type 8 (Forward): the turn clip is move type 10 (turn > 0) or 9
// (otherwise, weight = -turn by sign flip with the mask at 0x67af40); if it has a clip, SetDualFrame (slot 0x248)
// (legs clip, phase, turn clip, phase, weight, blend time +0x769). Otherwise SetBoneFrameBlend (slot 0x244)
// (legs clip, phase, blend time +0x769, 0, 0).
static void THISCALL UpdateBaseMoveFrame(u8 *self) {
  u32 *mt = vcall<u32 *>(self, 0x5a8, U32(self, 0x650));
  if (!mt || self[0x771])
    return;
  u32 clip = mt[0] ? U32(U32(G(u32, 0x70039c), 0x9b), 0x44) + mt[0] : 0;
  double x = (double)F32(self, 0x755);
  float phase;
  asm volatile("fldl %1\n\tfld1\n\tcall ext_634dc4\n\tfstps %0" : "=m"(phase) : "m"(x) : "eax", "ecx", "edx", "st", "st(1)", "memory");
  float turn = F32(self, 0x76d);
  if (!(turn == 0.0f) && U32(self, 0x650) == 8) {
    u32 c2 = 0;
    float w;
    if (turn > 0.0f) {
      void *r = vcall<void *>(self, 0x5a8, 10u);
      if (r)
        c2 = ext_478a80(r);
      w = F32(self, 0x76d);
    } else {
      void *r = vcall<void *>(self, 0x5a8, 9u);
      if (r)
        c2 = ext_478a80(r);
      u32 b = U32(self, 0x76d) ^ G(u32, 0x67af40);
      __builtin_memcpy(&w, &b, 4);
    }
    if (c2) {
      vcall<void>(self, 0x248, clip, phase, c2, phase, w, F32(self, 0x769));
      return;
    }
  }
  vcall<void>(self, 0x244, clip, phase, F32(self, 0x769), 0u, 0u);
}
PCREG(47c540, UpdateBaseMoveFrame);
