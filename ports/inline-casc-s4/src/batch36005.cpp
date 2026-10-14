// batch36005.cpp - cascade s4 batch 36005: 0x5370d0 (tier F row).
#include "ff.h"

typedef u32(THISCALL *v1r_t)(void *, u32);
extern "C" u32 FASTCALL ext_4cc850(u32 a, u32 b);  // wildcard match (fastcall: ecx, edx); 0 = match

// 0x5370d0, thiscall(tab, name) ret 8, this = E: returns 0 when tab or name is null, or E[0x5302] (unaligned) is 0. Searches i in 0..u16 tab[8]:
// arr = tab[0x10] (return 0 when null), item = (arr + base)[i] (0 ends), r = E->slot 0x1e8(item + base) (0 ends), ext_4cc850(r, name) == 0 returns item.
static u32 THISCALL fn5370d0(u8 *E, u8 *tab, u32 name) {
  if (!tab || !name) return 0;
  if (*(u32 *)(E + 0x5302) == 0) return 0;
  s32 i = 0;
  if (0 >= *(u16 *)(tab + 8)) return 0;
  for (;;) {
    u32 off = *(u32 *)(tab + 0x10);
    if (!off) return 0;
    u32 base = *(u32 *)(E + 0x5302);
    u32 *arr = (u32 *)(off + base);
    u32 item = arr[i];
    if (!item) return 0;
    u32 r = (*(v1r_t **)E)[0x1e8 / 4](E, item + base);
    if (!r) return 0;
    if (ext_4cc850(r, name) == 0) return arr[i];
    i++;
    if (!(i < (s32) * (u16 *)(tab + 8))) return 0;
  }
}
PCREG(5370d0, fn5370d0);
