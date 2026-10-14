// batch35165.cpp - cascade s5 batch 35165: 0x4baf60 (GUESS release the buffers of every entry of an owned collection, then destroy it).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // cdecl, 2 args
typedef void(THISCALL *it_t)(void *, u32 *);
typedef u8 *(THISCALL *nx_t)(void *, u32 *);
typedef void(THISCALL *d1_t)(void *, u32);

// 0x4baf60, thiscall, no args, no return value. c = [this+0x48]. When non-null: c slot 0x4c(it) then for each e = c slot 0x64(it) (until null; c re-read): when [this+0x70] == 0 0x634273([e+0x1c], 4); always 0x634273([e+0x20], 4).
// Afterwards (c re-read) when non-null: c slot 0(1) (the scalar deleting destructor).
static void THISCALL fn4baf60(u8 *self) {
  u32 it[3];
  u8 *c = *(u8 **)(self + 0x48);
  if (c) {
    (*(it_t **)c)[0x4c / 4](c, it);
    c = *(u8 **)(self + 0x48);
    u8 *e = (*(nx_t **)c)[0x64 / 4](c, it);
    while (e) {
      if (*(u32 *)(self + 0x70) == 0) ext_634273(*(void **)(e + 0x1c), 4);
      ext_634273(*(void **)(e + 0x20), 4);
      c = *(u8 **)(self + 0x48);
      e = (*(nx_t **)c)[0x64 / 4](c, it);
    }
  }
  c = *(u8 **)(self + 0x48);
  if (c) (*(d1_t **)c)[0](c, 1);
}
PCREG(4baf60, fn4baf60);
