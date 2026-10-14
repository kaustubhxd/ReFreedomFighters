// batch35099.cpp - cascade s5 batch 35099: 0x49a0e0 (GUESS write a list's header and every record to this writer; counterpart of 0x49a650).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v1p_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x49a0e0, thiscall(s) ret 4. a = s slot 0x14(), this slot 0xc(a); b = s slot 0x18(), this slot 0xc(b); s slot 0x4c(&it); for every p returned by s slot 0x64(&it): this slot 0x10(p, b * 4).
static void THISCALL fn49a0e0(u8 *self, u8 *s) {
  u32 it[3];
  u32 a = (*(g0_t **)s)[0x14 / 4](s);
  (*(v1_t **)self)[0xc / 4](self, a);
  u32 b = (*(g0_t **)s)[0x18 / 4](s);
  (*(v1_t **)self)[0xc / 4](self, b);
  (*(v1p_t **)s)[0x4c / 4](s, it);
  u32 p = (*(g1p_t **)s)[0x64 / 4](s, it);
  if (p) {
    u32 bytes = b << 2;
    do {
      (*(v2_t **)self)[0x10 / 4](self, p, bytes);
      p = (*(g1p_t **)s)[0x64 / 4](s, it);
    } while (p);
  }
}
PCREG(49a0e0, fn49a0e0);
