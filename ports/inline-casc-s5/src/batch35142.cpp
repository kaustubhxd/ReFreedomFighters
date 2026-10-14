// batch35142.cpp - cascade s5 batch 35142: 0x57a6b0 (GUESS flag the slots whose shift bit is missing from the global mask, then refresh).
#include "ff.h"

extern "C" void THISCALL ext_57aaf0(u8 *self);   // plain ret
typedef u32(THISCALL *g0_t)(void *);
typedef u8 *(THISCALL *r0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x57a6b0, thiscall, no arguments. mask = [0x7003a0] slot 0x4c(). For i in 0..3 with shift s = dword [this + 0x184 + 4i] (-1 skips): when bit (1 << (s & 31)) is not in mask and byte [this + 0x194 + i] is clear, it is set and byte +0x198 = 1.
// When +0x198 is set: P = [this+0x94] with bytes [P+0x13298] / [P+0x13299] (both clear, or no P) leads to 0x57aaf0(this); then when byte +0x88 is clear this slot 0x84() slot 0x2fc([this+0x44]).
static void THISCALL fn57a6b0(u8 *self) {
  u8 *g = G(u8 *, 0x7003a0);
  u32 mask = (*(g0_t **)g)[0x4c / 4](g);
  for (int i = 0; i < 4; i++) {
    u32 s = *(u32 *)(self + 0x184 + i * 4);
    if (s != 0xffffffffu) {
      u32 bit = 1u << (s & 31);
      if (!(mask & bit) && self[0x194 + i] == 0) {
        self[0x194 + i] = 1;
        self[0x198] = 1;
      }
    }
  }
  if (self[0x198] == 0) return;
  u8 *P = *(u8 **)(self + 0x94);
  if (P) {
    u8 a = P[0x13298];
    u8 c = P[0x13299];
    if (a || c) return;
  }
  ext_57aaf0(self);
  if (self[0x88] != 0) return;
  u8 *o = (*(r0_t **)self)[0x84 / 4](self);
  (*(v1_t **)o)[0x2fc / 4](o, *(u32 *)(self + 0x44));
}
PCREG(57a6b0, fn57a6b0);
