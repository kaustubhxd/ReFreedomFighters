// batch241.cpp - parked item from the loop, now ported. 0x437b00 (name GUESS): thiscall(A) (ret 4). SEH frame not reproduced.
// base = (M = [this+8]) ? (tag [M] == 3 ? M-4 : tag == 1 ? ([M+8] ? [M+8]-4 : 0) : 0) : 0; P = [base+0x11].
// idx = P->vt[0x64](A) (-1 is an error path, not modelled: the spec never returns -1).
// If [P+0x1210] (signed) > idx: if [this+0xd] == 0: [this+0xd] = 0x4ccbe0(alloc(0x1c), 2, 4) (the return value is kept);
// Bk = [this+0xd]; Q = Bk->vt[4](0); [Q-4] = idx; [Q] = 0 (byte); P2 = [base'+0x11] (recomputed); T = [P2+0x1344];
// E = T + 10*idx; R = 0x4382e0([E]); [R+5] = [E+4]; [E+4] = R; [R] = this.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);                              // allocator, cdecl (hooked by the harness)
extern "C" u32 THISCALL ext_4ccbe0(u8 *self, u32 p1, u32 p2);      // thiscall, two stack words, ret 8 (stubbed)
extern "C" u32 THISCALL ext_4382e0(u8 *self);                      // thiscall, no stack words (stubbed)

typedef u32(THISCALL *SlotOne)(u8 *, u32);

static u32 vslot22(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static u8 *baseOf_437b00(u8 *self) {
  u8 *M = *(u8 **)(self + 8);
  if (!M) return 0;
  u32 tag = *(u32 *)M;
  if (tag == 3) return M - 4;
  if (tag == 1) {
    u32 v = *(u32 *)(M + 8);
    return v ? (u8 *)(v - 4) : 0;
  }
  return 0;
}

static void THISCALL search_437b00(u8 *self, u32 A) {
  u8 *base = baseOf_437b00(self);
  u8 *P = *(u8 **)(base + 0x11);
  u32 idx = ((SlotOne)vslot22(P, 0x64))(P, A);
  base = baseOf_437b00(self);
  u8 *P2 = *(u8 **)(base + 0x11);
  if ((s32)*(u32 *)(P2 + 0x1210) <= (s32)idx) return;
  if (*(u32 *)(self + 0xd) == 0) {
    u8 *blk = ext_41e290(0x1c);
    u32 r = 0;
    if (blk) r = ext_4ccbe0(blk, 2, 4);
    *(u32 *)(self + 0xd) = r;
  }
  u8 *Bk = *(u8 **)(self + 0xd);
  u8 *Q = (u8 *)(u32)((SlotOne)vslot22(Bk, 4))(Bk, 0);
  *(u32 *)(Q - 4) = idx;
  *(u8 *)Q = 0;
  base = baseOf_437b00(self);
  u8 *P3 = *(u8 **)(base + 0x11);
  u32 T = *(u32 *)(P3 + 0x1344);
  u8 *E = (u8 *)(T + idx * 10u);
  u32 R = ext_4382e0((u8 *)(u32)*(u32 *)E);
  *(u32 *)(R + 5) = *(u32 *)(E + 4);
  *(u32 *)(E + 4) = R;
  *(u32 *)R = (u32)self;
}
PCREG(437b00, search_437b00);
