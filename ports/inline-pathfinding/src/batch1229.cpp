// batch1229.cpp - pathfinding tree: ZActor::SetAutoNewPathDest(float* dest) [map high; GC 80173... ZActor; 0x47bce0].
// thiscall, ret 4. Stores the destination (+0x742, three floats) and sets the flag at +0x74e. When a path is set (pointer
// at +0x695, an unaligned u32), the squared distance from the path's last point to the destination is measured (vdist2,
// fastcall: point in ecx, destination in edx); when it exceeds the constant at 0x68af30, vtable slot +0x63c runs with 0.
#include "pf.h"

extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);   // vdist2 (squared distance)

static void THISCALL actorSetAutoNewPathDest(u8 *self, float *dest) {
  self[0x74e] = 1;
  for (int k = 0; k < 3; k++) *(float *)(self + 0x742 + 4 * k) = dest[k];
  u32 pathRaw;
  __builtin_memcpy(&pathRaw, self + 0x695, 4);
  if (pathRaw) {
    u8 *path = (u8 *)pathRaw;
    u32 count = *(u32 *)(path + 8);
    u8 *base = *(u8 **)(path + 0xc);
    u8 *point = base - 0xc + count * 16;
    float d = ext_4e0830((const float *)point, dest);
    if (d > *(float *)0x68af30) vcall<void>(self, 0x63c, (u32)0);
  }
}
PCREG(47bce0, actorSetAutoNewPathDest);
