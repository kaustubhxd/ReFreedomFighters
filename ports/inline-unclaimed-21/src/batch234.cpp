// batch234.cpp - small leaves, slice 0/1. 0x563750 (name GUESS): thiscall(mode, flag) (ret 8). The local block
// L (3 slots: L[0] u32, L[1] float, L[2] float) is the argument of the vtable 0x70 calls. mode 2: if !flag: this->vt[0xd4](0xfe);
// L = (0, float(int [this+0x8b]), 0); n = [this+0x4c]: n->vt[0x70](&L); m = [this+0x50]: m->vt[0x70](&L); [this+0xdc] = 2.
// mode 3: if !flag: this->vt[0xd4](0); L = (0, -1, 0) if n else (0, ?, 0): n -> vt[0x70](&L), then m -> vt[0xbc](1) inside the n branch;
// then if m: L[1] = float(rm[0x73] + 1), m->vt[0x70](&L), m->vt[0xbc](1); [this+0xdc] = 3. mode 5: L = (0, float(2*[this+0x8b]), 0);
// n -> vt[0x70](&L); if m: L[1] = 0, m->vt[0x70](&L); [this+0xdc] = 5. Other modes: nothing. rm = [0x70039c].
#include "ff.h"

typedef void(THISCALL *SlotPtr)(u8 *, u32 *);      // vtable 0x70: one stack pointer
typedef void(THISCALL *SlotWord)(u8 *, u32);       // vtable 0xd4 / 0xbc: one stack word

static u32 vslot14(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void THISCALL modeCall_563750(u8 *self, u32 mode, u32 flag) {
  u32 L[3] = {0, 0, 0};
  float *Lf = (float *)L;
  u8 *n = *(u8 **)(self + 0x4c);
  u8 *m = *(u8 **)(self + 0x50);
  if (mode == 2) {
    if (!(u8)flag) ((SlotWord)vslot14(self, 0xd4))(self, 0xfe);
    L[0] = 0;
    Lf[1] = (float)(s32)*(u32 *)(self + 0x8b);
    L[2] = 0;
    if (n) ((SlotPtr)vslot14(n, 0x70))(n, L);
    if (m) ((SlotPtr)vslot14(m, 0x70))(m, L);
    *(u32 *)(self + 0xdc) = 2;
  } else if (mode == 3) {
    if (!(u8)flag) ((SlotWord)vslot14(self, 0xd4))(self, 0);
    L[0] = 0;
    L[2] = 0;
    if (n) {
      Lf[1] = -1.0f;
      ((SlotPtr)vslot14(n, 0x70))(n, L);
      ((SlotWord)vslot14(m, 0xbc))(m, 1);
    }
    if (m) {
      u8 *rm = G(u8 *, 0x70039c);
      Lf[1] = (float)(s32)(*(u32 *)(rm + 0x73) + 1);
      ((SlotPtr)vslot14(m, 0x70))(m, L);
      ((SlotWord)vslot14(m, 0xbc))(m, 1);
    }
    *(u32 *)(self + 0xdc) = 3;
  } else if (mode == 5) {
    L[0] = 0;
    L[2] = 0;
    if (n) {
      Lf[1] = (float)(s32)(*(u32 *)(self + 0x8b) * 2u);
      ((SlotPtr)vslot14(n, 0x70))(n, L);
    }
    if (m) {
      Lf[1] = 0.0f;
      ((SlotPtr)vslot14(m, 0x70))(m, L);
    }
    *(u32 *)(self + 0xdc) = 5;
  }
}
PCREG(563750, modeCall_563750);
