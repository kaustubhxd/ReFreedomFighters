// batch37017.cpp - cascade s6 batch 37017: 0x50cbc0.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 idx);     // ret 4
extern "C" void THISCALL ext_5002f0(u32 *self, u32 flag);   // ret 4
extern "C" u8 *THISCALL ext_4db2f0(u32 self, u32 zero);     // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(*cdl_t)(void *, ...);

static inline u8 *tabLookup(u32 id) { void *t = *(void **)(*(u8 **)0x70039c + 0x9b); return (u8 *)(*(v1_t **)t)[0x58 / 4](t, id); }
static inline void *logger(u32 line) { u8 *lg = *(u8 **)0x700390; return (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69d420, line); }

// 0x50cbc0, thiscall-less (arg a, ret 4): command handler. Finishes the node at a+8 first (0x5002f0, flag 0), looks the object whose id is node 1 of a+4 up in the
// object table (error 0x1aa when missing), checks slot 0x1e0(0x1007d1) (error 0x1af when it fails), then (when node 0 of a+4 is 0 and slot 0x2f4 gave an object) lets
// that object's owner take it over via slot 0x288, and calls slot 0x2f0 of the object with node 0, the name object slot 0x20 returns and 1; finishes with 0x5002f0 flag 1.
static void STDCALL fn50cbc0(u8 *a) {
  ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), 0);
  u8 *esi = tabLookup(*ext_5003d0(*(u32 *)(a + 4), 1));
  if (!esi) {
    void *L = logger(0x1aa);
    (*(cdl_t **)L)[0x2c / 4](L, 0x69d728);
    return;
  }
  if (!(u8)(*(v1_t **)esi)[0x1e0 / 4](esi, 0x1007d1)) {
    void *L = logger(0x1af);
    (*(cdl_t **)L)[0x2c / 4](L, 0x69d5fc, *(u32 *)(esi + 4));
    return;
  }
  u8 *ebx = (u8 *)(*(v0_t **)esi)[0x2f4 / 4](esi);
  if (*ext_5003d0(*(u32 *)(a + 4), 0) == 0 && ebx) {
    u32 v34[9], v10[3];
    (*(v2_t **)esi)[0x80 / 4](esi, (u32)v34, (u32)v10);
    u8 *o = ext_4db2f0(*(u32 *)(ebx + 8), 0);
    (*(v3_t **)o)[0x288 / 4](o, (u32)esi, 0, 1);
    (*(v2_t **)esi)[0x7c / 4](esi, (u32)v34, (u32)v10);
  }
  u8 *e2 = tabLookup(*ext_5003d0(*(u32 *)(a + 4), 0));
  u32 nm = 0;
  if (e2) nm = (*(v0_t **)e2)[0x20 / 4](e2);
  u32 *n = ext_5003d0(*(u32 *)(a + 4), 0);
  (*(v3_t **)esi)[0x2f0 / 4](esi, *n, nm, 1);
  ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), 1);
}
PCREG(50cbc0, fn50cbc0);
