// batch38054.cpp - cascade s8 batch 38054: 0x592580 (resolve the control's configuration entries by name).
#include "ff.h"

extern "C" void ext_634d10(void *p, u32 v, u32 n);   // memset, cdecl
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define CFG (*(u8 **)(G(u8 *, 0x70039c) + 0x1a9f))

// 0x592580, thiscall, no args, plain ret. Sets byte +0x143 = 4, clears the 0x60 bytes at +0xef2 and +0xf5a, asks slot 0x578 of this for the section id and, when the engine config object
// (unaligned dword at engine +0x1a9f) exists, stores the result of its slot 0x60(section, name) for each of 23 option names in the matching (unaligned) dwords from +0xef6 to +0xf4e.
static void THISCALL fn592580(u8 *self) {
  self[0x143] = 4;
  ext_634d10(self + 0xef2, 0, 0x60);
  *(u32 *)(self + 0xf5a) = 0;
  u32 sec = SLOT(self, 0x578, v0_t)(self);
  if (!CFG) return;
  static const struct {
    u32 name;
    u32 off;
  } tab[23] = {{0x6ad0ec, 0xef6}, {0x6ad0f4, 0xf02}, {0x6ad104, 0xf06}, {0x6ad114, 0xefa}, {0x6ad11c, 0xefe}, {0x6ad128, 0xf0a}, {0x6ad138, 0xf0e}, {0x6ad14c, 0xf12},
               {0x6ad15c, 0xf16}, {0x6ad164, 0xf1a}, {0x6ad174, 0xf1e}, {0x6ad180, 0xf22}, {0x6ad188, 0xf26}, {0x6ad194, 0xf2a}, {0x6ad19c, 0xf2e}, {0x6ad1a8, 0xf32},
               {0x6ad1b4, 0xf36}, {0x6ad1c0, 0xf3a}, {0x6ad1cc, 0xf3e}, {0x6ad1d4, 0xf42}, {0x6ad1dc, 0xf46}, {0x6ad1e4, 0xf4a}, {0x6ad1ec, 0xf4e}};
  for (int i = 0; i < 23; i++) {
    u8 *x = CFG;
    *(u32 *)(self + tab[i].off) = SLOT(x, 0x60, v2_t)(x, sec, tab[i].name);
  }
}
PCREG(592580, fn592580);
