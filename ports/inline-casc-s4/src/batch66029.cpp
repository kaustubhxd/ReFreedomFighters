// batch66029.cpp - cascade s4 batch 66029: 0x582060 (tier F row).
#include "ff.h"

typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" void THISCALL ext_5833e0(void *self, u32 a, void *b);   // ret 8
extern "C" void THISCALL ext_441730(void *self);                   // plain ret
extern "C" void THISCALL ext_440530(void *self);                   // plain ret
extern "C" void THISCALL ext_585200(void *self, u32 a);            // ret 4

// 0x582060, thiscall(code, p) ret 8, returns 0 (this = t): k = (u16) sys[0x9b]->slot 0x45 (0x114)(0x692b34, 0, 0x6ab6d4, 0x214). (u16) code == k: s = {0, p}; 0x5833e0(t, 1, &s).
// code == (u16) t[0x48]: 0x441730(0x69476c); p == 0 -> 0x5833e0(t, 0, 0); p[0] != 0 -> 0x5833e0(t, 1, p); p[4] != 0 -> 0x5833e0(t, 2, p); else 0x5833e0(t, 0, 0); then 0x440530(0x69476c).
// code == (u16) [0x71428c] -> 0x585200(t, p).
static u32 THISCALL fn582060(u8 *t, u32 code, u8 *p) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u16 k = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, 0x692b34u, 0, 0x6ab6d4u, 0x214);
  u16 cx = (u16)code;
  if (cx == k) {
    u32 s[2];
    s[1] = (u32)p;
    s[0] = 0;
    ext_5833e0(t, 1, s);
    return 0;
  }
  if (cx == *(u16 *)(t + 0x48)) {
    ext_441730((void *)0x69476c);
    if (!p) ext_5833e0(t, 0, 0);
    else if (rd(p)) ext_5833e0(t, 1, p);
    else if (rd(p + 4)) ext_5833e0(t, 2, p);
    else ext_5833e0(t, 0, 0);
    ext_440530((void *)0x69476c);
    return 0;
  }
  if (cx == G(u16, 0x71428c)) ext_585200(t, (u32)p);
  return 0;
}
PCREG(582060, fn582060);
