// batch35169.cpp - cascade s5 batch 35169: 0x45fc90 (GUESS set a string field: keep a pool string by pointer, copy any other).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);   // cdecl alloc
typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x45fc90, thiscall(s) ret 4, no return value. tab = engine[+0x9b]; tab slot 0x130(this[4]); B = the unaligned dword at tab+0x1c5d. When s >= B (unsigned), B != 0 and s < B + ([B-8] & 0x1fffffff) the string lives in the pool:
// this[4] = s. Otherwise len = strlen(s) + 1, this[4] = 0x41e290(len) and the bytes (with the NUL) are copied.
static void THISCALL fn45fc90(u8 *self, u8 *s) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  (*(v1_t **)tab)[0x130 / 4](tab, *(u32 *)(self + 4));
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 B = rd32u(tab + 0x1c5d);
  if (!((u32)s < B) && B != 0 && (u32)s < B + (*(u32 *)(B - 8) & 0x1fffffffu)) {
    *(u8 **)(self + 4) = s;
    return;
  }
  u32 len = 0;
  while (s[len]) len++;
  u8 *d = ext_41e290(len + 1);
  *(u8 **)(self + 4) = d;
  for (u32 i = 0; i <= len; i++) d[i] = s[i];
}
PCREG(45fc90, fn45fc90);
