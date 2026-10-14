// batch35061.cpp - cascade s5 batch 35061: 0x432560 (GUESS find the entry after the `skip` entry whose name matches).
#include "ff.h"

extern "C" u8 *THISCALL ext_4cc1d0(u8 *self);            // 3-byte accessor, plain ret
extern "C" u32 FASTCALL ext_4cc850(u8 *a, const u8 *name);   // fastcall (ecx, edx), plain ret
typedef void(THISCALL *v1_t)(void *, void *);
typedef u8 *(THISCALL *g1p_t)(void *, void *);

// 0x432560, thiscall(name, skip) ret 8, returns the entry or 0. List object embedded (aligned) at this+0x84: slot 0x4c(&it), then for each p from slot 0x64(&it): when 0x4cc850(0x4cc1d0(p), name) is zero
// (a name match) and the flag `found` (initially skip == 0) is set p is returned; otherwise found = (p == skip). The result is 0 when the list ends.
static u8 *THISCALL fn432560(u8 *self, const u8 *name, u8 *skip) {
  u32 it[3];
  u8 found = skip == 0;
  u8 *L = self + 0x84;
  (*(v1_t **)L)[0x4c / 4](L, it);
  u8 *p = (*(g1p_t **)L)[0x64 / 4](L, it);
  while (p) {
    if (ext_4cc850(ext_4cc1d0(p), name) == 0) {
      if (found) return p;
      found = skip == p;
    }
    p = (*(g1p_t **)L)[0x64 / 4](L, it);
  }
  return 0;
}
PCREG(432560, fn432560);
