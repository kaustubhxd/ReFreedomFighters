// batch1231.cpp - pathfinding tree: ZActor::OnPathNotify() [0x4798d0 family; msg global 0x6ffa44] and
// ZActor::OnPathRequest(unsigned int actor) [0x47a500; msg global 0x6ffa24].
#include "pf.h"

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);   // vdist (distance)

// 0x47a4d0 ZActor::OnPathNotify(). thiscall, no args. Sends the notice (id, 0, 0), then clears the notify interval
// and the sync flag.
static void THISCALL actorOnPathNotify(u8 *self) {
  vcall<void>(self, 0x128, (u32)G(u16, 0x6ffa44), (u32)0, (u32)0);
  *(u32 *)(self + 0x6ba) = 0;
  self[0x6be] = 0;
}
PCREG(47a4d0, actorOnPathNotify);

// 0x47a500 ZActor::OnPathRequest(unsigned int actor). thiscall, ret 4. Without the auto-destination flag (+0x74e) the
// request notice (id 0x6ffa24, actor, 0) is sent. With it, the actor's position (vtable +0x84) is compared with the
// destination (+0x742): at most 75 units clears the flag; otherwise the speed is set by distance (1.2 beyond 300,
// 0.9 under 200, else 1.0; vtable +0x624), and beyond 150 the destination is passed to vtable +0x634 and +0x5e8 runs.
static void THISCALL actorOnPathRequest(u8 *self, u32 actor) {
  if (!self[0x74e]) {
    vcall<void>(self, 0x128, (u32)G(u16, 0x6ffa24), actor, (u32)0);
    return;
  }
  float pos[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(self, 0x84, pos);
  float *dest = (float *)(self + 0x742);
  float d = ext_4e0870(dest, pos);
  if (!(d > 75.0f)) {          // jbe: a NaN distance also clears the flag
    self[0x74e] = 0;
    return;
  }
  float speed = d > 300.0f ? 1.2f : (200.0f > d ? 0.9f : 1.0f);
  vcall<void>(self, 0x624, speed);
  if (d > 150.0f) {
    vcall<void>(self, 0x634, (u32)dest, (u32)0);
    vcall<void>(self, 0x5e8, (u32)0);
  }
}
PCREG(47a500, actorOnPathRequest);
