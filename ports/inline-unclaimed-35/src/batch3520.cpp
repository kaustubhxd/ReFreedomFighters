#include "ff.h"
// batch3520.cpp - area 35 claim 20 (docs/20-unclaimed-35.md): 0x439760, ZInputAction::MakeActionExclusiveOwnerOfNodes(bool)
// (vtable-map name, medium). Thiscall, one stack argument (ret 4); only its low byte is used (mov bl, [ebp+8]).
// Stubbed in the harness: slot +0x4c and slot +0x5c of the object at this+0x15 (thiscall, one arg: &L, written through).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a0);

static u32 callSlot(u8 *o, u32 off, u32 arg) {
  return ((Slot1)*(u32 *)(*(u32 *)o + off))(o, arg);
}

void THISCALL inputActionMakeExclusive(u8 *self, u32 arg) {
  u8 bl = (u8)arg;
  u32 L = 0;
  u8 *A = *(u8 **)(self + 0x15);
  if (!A)
    return;
  callSlot(A, 0x4c, (u32)&L);
  A = *(u8 **)(self + 0x15);
  u32 R = callSlot(A, 0x5c, (u32)&L);
  if (!L)
    return;
  for (;;) {
    // P: the object behind this+0xc (type 3: B-4; type 1: [B+8]-4, or 0 when [B+8] is 0); M = P+0x11.
    u32 B = *(u32 *)(self + 0xc);
    u32 P = 0;
    if (B != 0) {
      if (*(u32 *)B == 3) {
        P = B - 4;
      } else if (*(u32 *)B == 1) {
        u32 q = *(u32 *)(B + 8);
        P = q ? q - 4 : 0;
      }
    }
    u32 M = *(u32 *)(P + 0x11);
    u32 T = *(u32 *)(M + 0x1344);
    u32 N = *(u32 *)(T + R * 10 + 4);
    if (N) {
      do {
        u32 V = *(u32 *)N;
        if (*(u32 *)V == 0) {
          u32 X = V ? V - 4 : 0;
          if (X == (u32)self) {
            if (bl)
              *(u32 *)(X + 0x46) <<= 1;
            else
              *(s32 *)(X + 0x46) >>= 1;
          } else if (!bl) {
            *(s32 *)(X + 0x46) >>= 1;
          } else {
            *(u32 *)(X + 0x46) = *(u32 *)(X + 0x46) * 2 + 1;
          }
        }
        N = *(u32 *)(N + 5);
      } while (N);
    }
    A = *(u8 **)(self + 0x15);
    R = callSlot(A, 0x5c, (u32)&L);
    if (!L)
      return;
  }
}
PCREG(439760, inputActionMakeExclusive);
