// batch36062.cpp - cascade s4 batch 36062: 0x56d150 (tier F row).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_563110(void *self, u32 a, u32 b);   // ret 8
extern "C" void THISCALL ext_56d750(void *self);
extern "C" void THISCALL ext_56d840(void *self);
extern "C" void THISCALL ext_56d950(void *self);

// 0x56d150, thiscall(a, flag) ret 8 returns al = 0 (this = s): 0x563110(s, a, flag). flag (low byte) set: M = sys[0x1907]; M -> M->slot 3(0x6ec8f4, 0x6a8034, 0); r = [sys[0x1907]]->slot 0x18(0x6a8034) -> s[0x1c6];
// s[0x1ca .. 0x1e6] = r->slot 5 (0x14) for the eight names 0x6a7e84, 0x6a7e90, 0x6a7e9c, 0x6a7ea8, 0x6a7eb4, 0x6a7ec4, 0x6a7ed4, 0x6a7ee4; s[0x19c] = 0; 0x56d950(s); s[0x86] = 0. Then 0x56d750(s), 0x56d840(s).
static u8 THISCALL fn56d150(u8 *s, u32 a, u32 flag) {
  ext_563110(s, a, flag);
  if ((u8)flag) {
    u8 *M = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
    if (M) (*(v3_t **)M)[0xc / 4](M, 0x6ec8f4u, 0x6a8034u, 0);
    M = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
    u8 *r = (u8 *)(*(v1r_t **)M)[0x60 / 4](M, 0x6a8034u);
    wr(s + 0x1c6, (u32)r);
    wr(s + 0x1ca, (*(v1r_t **)r)[0x14 / 4](r, 0x6a7e84u));
    static const u32 names[7] = {0x6a7e90, 0x6a7e9c, 0x6a7ea8, 0x6a7eb4, 0x6a7ec4, 0x6a7ed4, 0x6a7ee4};
    static const u32 offs[7] = {0x1ce, 0x1d2, 0x1d6, 0x1da, 0x1de, 0x1e2, 0x1e6};
    for (int i = 0; i < 7; i++) {
      u8 *q = *(u8 **)(s + 0x1c6);
      wr(s + offs[i], (*(v1r_t **)q)[0x14 / 4](q, names[i]));
    }
    wr(s + 0x19c, 0);
    ext_56d950(s);
    s[0x86] = 0;
  }
  ext_56d750(s);
  ext_56d840(s);
  return 0;
}
PCREG(56d150, fn56d150);
