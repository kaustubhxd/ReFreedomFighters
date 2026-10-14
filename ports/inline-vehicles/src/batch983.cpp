// batch983.cpp - residue-11 (core todo), batch 983: ZFFSimpleTrain2::FrameUpdate(), 0x5b87f0, thiscall, no args, plain ret.
// Returns when [this+0xdd] is set. Else the timer [this+0xb3] += (float)(sys[0x40] - sys[0x44]) / 1024 (constant at 0x6785e4).
// When [this+0xb2] is set: tail call 0x5b8d80 (stood in). Otherwise, when the timer is above [this+0x5c]: timer = 0, flag [this+0xb2] = 1,
// and when [this+0xe2] is set: the render manager's 0x114(0x6b2718, 0, 0x6b2690, 0x158, 0, 0) gives an id and the object's slot
// 0x128(id) runs.
#include "ff.h"

extern "C" void THISCALL ext_5b8d80(void *self);   // tail target (stood in by the checker)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x5b87f0 ZFFSimpleTrain2::FrameUpdate().
static void THISCALL trainFrameUpdate(u8 *t) {
  if (t[0xdd])
    return;
  u8 *sys = *(u8 **)0x70039c;
  int diff = (int)(D(sys, 0x40) - D(sys, 0x44));
  float tm = F(t, 0xb3) + (float)diff * *(float *)0x6785e4;
  F(t, 0xb3) = tm;
  if (t[0xb2]) {
    ext_5b8d80(t);
    return;
  }
  if (tm > F(t, 0x5c)) {
    u8 *o = (u8 *)D(t, 0xe2);
    D(t, 0xb3) = 0;
    t[0xb2] = 1;
    if (o) {
      void *rm = *(void **)(sys + 0x9b);
      u16 id = vcall<u16>(rm, 0x114, 0x6b2718u, 0u, 0x6b2690u, 0x158u, 0u, 0u);
      vcall<void>(o, 0x128, (u32)id);
    }
  }
}
PCREG(5b87f0, trainFrameUpdate);
