// batch38029.cpp - cascade s8 batch 38029: 0x511450 (queue the eight pass callbacks of a scene object).
#include "ff.h"

typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32 (*hook_t)();
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define QCOUNT G(u32, 0x7014b0)
#define QARR(i) G(u32, 0x7014b8 + 4 * (i))

// 0x511450, thiscall(job) ret 4. Appends eight callback addresses (0x511090, 0x511200, 0x511410, 0x511150, 0x5113c0, 0x5112e0, 0x511330, 0x511380) to the global queue (count at 0x7014b0,
// array from 0x7014b8, capacity 0x32), stopping as soon as job[0xc] is clear. A full queue calls this slot 0x44 with the message 0x69e08c and the assert hook (int3 when it is null);
// the first seven overflows carry on with the reloaded count, the last one returns.
static void THISCALL fn511450(u8 *self, u8 *job) {
  static const u32 fns[8] = {0x511090, 0x511200, 0x511410, 0x511150, 0x5113c0, 0x5112e0, 0x511330, 0x511380};
  u32 count = QCOUNT;
  for (int i = 0; i < 8; i++) {
    if (job[0xc] == 0) return;
    if (count < 0x32) {
      QARR(count) = fns[i];
      count++;
      QCOUNT = count;
      continue;
    }
    SLOT(self, 0x44, v1_t)(self, 0x69e08c);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    if (i == 7) return;
    count = QCOUNT;
  }
}
PCREG(511450, fn511450);
