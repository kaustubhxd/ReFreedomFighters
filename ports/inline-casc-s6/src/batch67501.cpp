// batch67501.cpp - cascade s6 batch 67501: 0x5c9330.
#include "ff.h"

extern "C" void THISCALL ext_5c82a0(u8 *self, u32 *vec);   // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x5c9330, thiscall(target) ret 4: moves this object's attachment to `target`. The previous object (table object of +0x70 -> its slot 0x2f4) is detached when it answers
// 0x2007f9 and differs from the target (marker +0x91c cleared, its slot-0x504 helper told 0, +0x88 cleared); the target, when it answers 0x2007f9, gets +0x91c = +0x70 and its helper
// told 1. If +0x80 is zero the table object of +0x74 is asked for a position (slot 0x84, a local vector {0, 0, 1000.0f}) which 0x5c82a0 applies. The first object finally receives
// the target's table handle (slot 0x2f0) and slot 0x2d0 (0, 0).
static void THISCALL fn5c9330(u8 *self, u8 *target) {
  u8 *A = (u8 *)vcall<u32>(tabObj(), 0x58, D32(self, 0x70));
  u8 *esi = (u8 *)vcall<u32>(A, 0x2f4);
  if (esi && (u8)vcall<u32>(esi, 0x1e0, 0x2007f9u) && esi != target) {
    D32(esi, 0x91c) = 0;
    if (vcall<u32>(esi, 0x504)) {
      void *h = (void *)vcall<u32>(esi, 0x504);
      vcall<void>(h, 0xbc, 0u);
    }
    D32(self, 0x88) = 0;
  }
  if (target) {
    if ((u8)vcall<u32>(target, 0x1e0, 0x2007f9u)) {
      D32(target, 0x91c) = D32(self, 0x70);
      if (vcall<u32>(target, 0x504)) {
        void *h = (void *)vcall<u32>(target, 0x504);
        vcall<void>(h, 0xbc, 1u);
      }
    }
    if (D32(self, 0x80) == 0) {
      u32 vec[3] = {0, 0, 0x447a0000u};
      u8 *B = (u8 *)vcall<u32>(tabObj(), 0x58, D32(self, 0x74));
      vcall<void>(B, 0x84, (u32)vec);
      ext_5c82a0(self, vec);
    }
  }
  u32 hd = vcall<u32>(tabObj(), 0x4c, (u32)target);
  vcall<void>(A, 0x2f0, hd, 0u, 0u);
  vcall<void>(A, 0x2d0, 0u, 0u);
}
PCREG(5c9330, fn5c9330);
