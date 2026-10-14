// batch36057.cpp - cascade s4 batch 36057: 0x50fa90 (tier F row).
#include "ff.h"

typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x50fa90, stdcall(p) ret 4: flag = (*0x5003d0(p[4], 1) != 0) stored into the low byte of the argument slot, so the value passed on is (p & ~0xff) | flag. o = sys[0x9b]->slot 0x138(); r = 0x5003d0(p[4], 0); type r[4]: 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34();
// else logger(0x69c8e0, 0x111) prints (cdecl 3 args) 0x69c6b0, 0x69c9b0, assert hook (int3 when none), id = 0. Finally o->slot 0x68(id, flagword, 0).
static void STDCALL fn50fa90(u8 *p) {
  u8 *r1 = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 flagword = ((u32)p & 0xffffff00u) | (rd(r1) != 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 0);
  u32 t = r[4];
  u32 id;
  if (t == 3) {
    id = rd(r);
  } else if (t == 4) {
    u8 *x = *(u8 **)r;
    id = (*(v0r_t **)x)[0x34 / 4](x);
  } else {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0x111u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c9b0u);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    id = 0;
  }
  (*(v3_t **)o)[0x68 / 4](o, id, flagword, 0);
}
PCREG(50fa90, fn50fa90);
