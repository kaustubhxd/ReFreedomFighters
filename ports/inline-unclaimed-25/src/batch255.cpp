// batch255.cpp - unclaimed area 25 (residue-05 item, claim written in docs/20-unclaimed-25.md).
#include "ff.h"

extern "C" void THISCALL ext_4b8ab0(u8 *self, u32 a);   // original code, one stack argument (ret 4)

typedef void (THISCALL *V2)(u8 *self, u32 a, u32 b);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline float rdf(u32 p, u32 off) { return *(float *)(unsigned long)(p + off); }

// 0x4b89d0, ZRelayMessageList::FrameUpdate (map name, body checked), thiscall, no stack args.
// v = (f(+0x54) + f(+0x50)) * f(0x678620), as a truncated int. If the engine global's +0x40 is not below v, call
// ext_4b8ab0(this, 0) and then vslot 0x68 of this with (0x10, 0).
static void THISCALL relayFrameUpdate(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 eng = rdw(0x70039c, 0);
  float t = (rdf(self, 0x54) + rdf(self, 0x50)) * *(float *)0x678620;
  int v = (int)t;
  if ((int)rdw(eng, 0x40) < v)
    return;
  ext_4b8ab0(selfP, 0);
  ((V2)rdw(rdw(self, 0), 0x68))(selfP, 0x10, 0);
}
PCREG(4b89d0, relayFrameUpdate);
