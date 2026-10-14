// batch35098.cpp - cascade s5 batch 35098: 0x49a650 (GUESS copy `count` records of `size` dwords from this into the buffer of w).
#include "ff.h"

extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1p_t)(void *, u32 *);
typedef void(THISCALL *v2p_t)(void *, u32 *, u32);
typedef u8 *(THISCALL *g1_t)(void *, u32);

// 0x49a650, thiscall(w) ret 4. w slot 0xc(); this slot 0x14(&count) and this slot 0x14(&size); bytes = size * 4. Then count times: this slot 0x10(&src, bytes) (writes a source pointer into src), p = w slot 4(0), and
// memcpy(p - 4, src, bytes). The loop is skipped when count is zero.
static void THISCALL fn49a650(u8 *self, u8 *w) {
  u32 count, size, src;
  (*(v0_t **)w)[0xc / 4](w);
  (*(v1p_t **)self)[0x14 / 4](self, &count);
  (*(v1p_t **)self)[0x14 / 4](self, &size);
  u32 bytes = size * 4;
  u32 i = 0;
  if (count == 0) return;
  for (;;) {
    (*(v2p_t **)self)[0x10 / 4](self, &src, bytes);
    u8 *p = (*(g1_t **)w)[4 / 4](w, 0);
    ext_634d22(p - 4, (void *)src, bytes);
    i++;
    if (i == count) break;
  }
}
PCREG(49a650, fn49a650);
