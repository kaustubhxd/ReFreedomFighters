// batch47004.cpp - cascade t8 batch 47004: 0x4ce870, 0x564e80 (tier F rows).
#include "ff.h"

typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v2r_t)(void *, u32, u32);
typedef u8 *(THISCALL *v2or_t)(void *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void (*hook_t)();

extern "C" void THISCALL ext_564a40(void *self, u32 a);   // ret 4

// 0x4ce870, thiscall(), returns eax. When this[0x18] (byte) and engine[0x9b7] (byte) are both nonzero: assert hook (int3 when none).
// o = this[8]: if set: o->slot 0x4c(&loc); edi = o->slot 0x5c(&loc); while loc != 0: o->slot 0x44(&loc); edi--; t = ~this[0x10]; edi |= this[4][edi] & t;
// when edi & t return edi; else logger 0x700390 slot 0x20(0x695b7c, 0x636) -> lo, lo->slot 0x2c(0x695d0c, this[0x10] & edi) (cdecl); edi = this[8]->slot 0x5c(&loc).
// After: this[0x10] < this[0xc]: logger slot 0x24(0x695d1c, this[0x10] + 1) (cdecl). Returns this[0xc] | (1 << (this[0x14] & 31)); this[0xc]++.
static u32 THISCALL fn4ce870(u8 *self) {
  if (self[0x18] && G(u8 *, 0x70039c)[0x9b7]) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *o = *(u8 **)(self + 8);
  if (o) {
    u32 loc;
    (*(v1_t **)o)[0x4c / 4](o, (u32)&loc);
    o = *(u8 **)(self + 8);
    u32 edi = (*(v1r_t **)o)[0x5c / 4](o, (u32)&loc);
    while (loc) {
      o = *(u8 **)(self + 8);
      (*(v1_t **)o)[0x44 / 4](o, (u32)&loc);
      edi--;
      u32 t = ~*(u32 *)(self + 0x10);
      u32 w = (*(u32 **)(self + 4))[edi];
      edi |= w & t;
      if (edi & t) return edi;
      u8 *db = G(u8 *, 0x700390);
      u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x695b7c, 0x636);
      void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
      ((void (*)(u8 *, u32, u32))fn)(lo, 0x695d0c, *(u32 *)(self + 0x10) & edi);
      o = *(u8 **)(self + 8);
      edi = (*(v1r_t **)o)[0x5c / 4](o, (u32)&loc);
    }
  }
  u32 lim = *(u32 *)(self + 0x10);
  if (*(u32 *)(self + 0xc) > lim) {
    u8 *db = G(u8 *, 0x700390);
    void *fn = *(void **)((u8 *)*(void ***)db + 0x24);
    ((void (*)(u8 *, u32, u32))fn)(db, 0x695d1c, lim + 1);
  }
  u32 n = *(u32 *)(self + 0xc);
  u32 r = n | (1u << (*(u32 *)(self + 0x14) & 31));
  *(u32 *)(self + 0xc) = n + 1;
  return r;
}
PCREG(4ce870, fn4ce870);

// 0x564e80, thiscall(), plain ret. Looks up child objects by name through slot 0x25c(name, 0) of this[0x54] and of the results, storing them at this+0xc6a / 0xc6e / 0xc72 /
// 0xc62 / 0xc76 / 0xc7a / 0xc7e / 0xc66; sets the pair {256.0f, 0.5f} (0x43820000, 0x3f000000) on the objects at 0xc76 and 0xc7a via slot 0x258(&pair, 0);
// 0x564a40(this, 0); this->slot 0x64(4); this[0xc5e] = this[0x94] + 0x1064.
static void THISCALL fn564e80(u8 *self) {
  u8 *p = *(u8 **)(self + 0x54);
  u8 *esi = (*(v2or_t **)p)[0x25c / 4](p, 0x6a69b0, 0);
  *(u8 **)(self + 0xc6a) = (*(v2or_t **)esi)[0x25c / 4](esi, 0x6a69bc, 0);
  *(u8 **)(self + 0xc6e) = (*(v2or_t **)esi)[0x25c / 4](esi, 0x6a69c4, 0);
  *(u8 **)(self + 0xc72) = (*(v2or_t **)esi)[0x25c / 4](esi, 0x6a69cc, 0);
  p = *(u8 **)(self + 0x54);
  esi = (*(v2or_t **)p)[0x25c / 4](p, 0x6a69d4, 0);
  *(u8 **)(self + 0xc62) = (*(v2or_t **)esi)[0x25c / 4](esi, 0x6a69e0, 0);
  *(u8 **)(self + 0xc76) = (*(v2or_t **)esi)[0x25c / 4](esi, 0x6a69e8, 0);
  u8 *r = (*(v2or_t **)esi)[0x25c / 4](esi, 0x6a69f0, 0);
  p = *(u8 **)(self + 0x54);
  *(u8 **)(self + 0xc7a) = r;
  r = (*(v2or_t **)p)[0x25c / 4](p, 0x6a69fc, 0);
  *(u8 **)(self + 0xc7e) = r;
  r = (*(v2or_t **)r)[0x25c / 4](r, 0x6a6a0c, 0);
  *(u8 **)(self + 0xc66) = r;
  u32 pair[2] = {0x43820000, 0x3f000000};
  u8 *q = *(u8 **)(self + 0xc76);
  (*(v2_t **)q)[0x258 / 4](q, (u32)pair, 0);
  q = *(u8 **)(self + 0xc7a);
  (*(v2_t **)q)[0x258 / 4](q, (u32)pair, 0);
  ext_564a40(self, 0);
  (*(v1_t **)self)[0x64 / 4](self, 4);
  *(u32 *)(self + 0xc5e) = *(u32 *)(self + 0x94) + 0x1064;
}
PCREG(564e80, fn564e80);
