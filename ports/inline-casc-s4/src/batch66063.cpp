// batch66063.cpp - cascade s4 batch 66063: 0x555430 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

static void check_tag(u8 *r) {
  u8 t = r[4];
  if (t == 0 || t == 1) return;
  u8 *db = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0x104u);
  void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
  ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c938u);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x555430, stdcall(p) ret 4: r0 = 0x5003d0(p[4], 0), r1 = 0x5003d0(p[4], 1): each record's tag r[4] must be 0 or 1 (otherwise log line 0x104 and assert hook); a = r0[0], b = r1[0].
// A = sys[0x9b]->slot 0x58(a): A->slot 0xf7 (0x3dc)(); B = slot 0x58(a); B->slot 0x137 (0x4dc)(slot 0x58(b), 1).
static void STDCALL fn555430(u8 *p) {
  u8 *r0 = ext_5003d0(*(u8 **)(p + 4), 0);
  check_tag(r0);
  u32 a = rd(r0);
  u8 *r1 = ext_5003d0(*(u8 **)(p + 4), 1);
  check_tag(r1);
  u32 b = rd(r1);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *A = (*(v1o_t **)tab)[0x58 / 4](tab, a);
  (*(v0_t **)A)[0x3dc / 4](A);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *B = (*(v1o_t **)tab)[0x58 / 4](tab, a);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *C = (*(v1o_t **)tab)[0x58 / 4](tab, b);
  (*(v2_t **)B)[0x4dc / 4](B, (u32)C, 1);
}
PCREG(555430, fn555430);
