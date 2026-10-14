// batch35121.cpp - cascade s5 batch 35121: 0x45c880 (GUESS merge a message's flag bits into the shared record and note the first listener).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);   // cdecl alloc
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x45c880, thiscall(m, x) ret 8 (x unused). f = [m+0x14]. Acts only when f != 0 and (bit 0x400 of [[this+8]+0x3c] is clear or f has 0x200). Then this slot 0x40(); rec = [this+0x10]; added = f & ~[rec+4]; [rec+4] |= added;
// when added has bit 8 (low byte tested) and [rec+0x10] is zero a node of 8 bytes (0x41e290; {0, this}) is allocated and stored there (zero when the allocation fails); finally m slot 0x64(f).
static void THISCALL fn45c880(u8 *self, u8 *m, u32 x) {
  (void)x;
  u32 f = *(u32 *)(m + 0x14);
  u32 flags = *(u32 *)(*(u8 **)(self + 8) + 0x3c);
  bool ok = ((u8)~(flags >> 10) & 1) != 0 || (f & 0x200) != 0;
  if (!ok || f == 0) return;
  (*(v0_t **)self)[0x40 / 4](self);
  u8 *rec = *(u8 **)(self + 0x10);
  u32 old = *(u32 *)(rec + 4);
  u32 added = ~old & f;
  *(u32 *)(rec + 4) = old | added;
  if ((u8)added & 8) {
    rec = *(u8 **)(self + 0x10);
    if (*(u32 *)(rec + 0x10) == 0) {
      u8 *n = ext_41e290(8);
      u8 *v = 0;
      if (n) {
        *(u32 *)n = 0;
        *(u8 **)(n + 4) = self;
        v = n;
      }
      *(u8 **)(*(u8 **)(self + 0x10) + 0x10) = v;
    }
  }
  (*(v1_t **)m)[0x64 / 4](m, f);
}
PCREG(45c880, fn45c880);
