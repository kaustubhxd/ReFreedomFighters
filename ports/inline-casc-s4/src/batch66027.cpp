// batch66027.cpp - cascade s4 batch 66027: 0x4fb3e0 (tier F row).
#include "ff.h"

typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);

// 0x4fb3e0, thiscall() plain ret (this = t): for nine (name, line) pairs: (u16) sys[0x9b]->slot 0x45 (0x114)(name, 0, 0x69c234, line) is stored at t[0x48], 0x4a, ..., 0x58 (u16 each).
// Names 0x69c25c (0x10f), 0x69c274 (0x110), 0x69c288 (0x111), 0x69c2ac (0x112), 0x69c2d0 (0x113), 0x69c2e0 (0x114), 0x688f94 (0x115), 0x691ff0 (0x116), 0x69c2f0 (0x117).
static void THISCALL fn4fb3e0(u8 *t) {
  static const u32 names[9] = {0x69c25c, 0x69c274, 0x69c288, 0x69c2ac, 0x69c2d0, 0x69c2e0, 0x688f94, 0x691ff0, 0x69c2f0};
  for (u32 i = 0; i < 9; i++) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    *(u16 *)(t + 0x48 + 2 * i) = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, names[i], 0, 0x69c234u, 0x10f + i);
  }
}
PCREG(4fb3e0, fn4fb3e0);
