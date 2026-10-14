// batch35126.cpp - cascade s5 batch 35126: 0x557020 (GUESS look up a configured object and apply a resource word derived from a record).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4
extern "C" u32 THISCALL ext_506040(u32 *rec);           // plain ret
typedef u8 *(THISCALL *g0_t)(void *);
typedef void(THISCALL *v2p_t)(void *, u32, u32 *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u32(THISCALL *g5_t)(void *, u32, u32, u32, u32, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x557020, stdcall(a) ret 4. o = [engine+0x9b] slot 0x138(); id = 0, o slot 0x88(0x6a5c48, &id); p = tab slot 0x58(id) (null returns). Then v = 0x506040(0x5003d0([a+4], 0)); w = low word of tab slot 0x114(0x6a5c58, 0, 0x6a57fc, 0x440, v, 0) (six stack args: a zero is staged before the 0x5003d0 call);
// p slot 0x128(w) (p's vtable read first).
static void STDCALL fn557020(u8 *a) {
  u32 id;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x138 / 4](tab);
  id = 0;
  (*(v2p_t **)o)[0x88 / 4](o, 0x6a5c48, &id);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u8 *p = (*(e1_t **)tab)[0x58 / 4](tab, id);
  if (!p) return;
  u32 f = (*(u32 **)p)[0x128 / 4];
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 *rec = ext_5003d0(*(u32 *)(a + 4), 0);
  u32 v = ext_506040(rec);
  u32 w = (*(g5_t **)tab)[0x114 / 4](tab, 0x6a5c58, 0, 0x6a57fc, 0x440, v, 0);
  ((v1_t)f)(p, w & 0xffff);
}
PCREG(557020, fn557020);
