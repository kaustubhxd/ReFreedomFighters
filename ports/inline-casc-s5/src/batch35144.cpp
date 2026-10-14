// batch35144.cpp - cascade s5 batch 35144: 0x553980 (GUESS apply a configured object's resource word and store its second output into a record).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4
extern "C" void THISCALL ext_5002f0(u32 self, u32 a);  // thiscall, ret 4
typedef u8 *(THISCALL *g0_t)(void *);
typedef void(THISCALL *v2p_t)(void *, u32, u32 *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u32(THISCALL *g6_t)(void *, u32, u32, u32, u32, u32 *, u32);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x553980, stdcall(a) ret 4. o = [engine+0x9b] slot 0x138(); id = 0, o slot 0x88(0x6a5c48, &id); p = tab slot 0x58(id) (null returns). w = low word of tab slot 0x114(0x6a5c78, 0, 0x6a57fc, 0x45c, &r, 0) (r an output dword);
// p slot 0x128(w) (p's vtable read first); 0x5002f0(0x5003d0([a+8], 0), r).
static void STDCALL fn553980(u8 *a) {
  u32 id, r;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x138 / 4](tab);
  id = 0;
  (*(v2p_t **)o)[0x88 / 4](o, 0x6a5c48, &id);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u8 *p = (*(e1_t **)tab)[0x58 / 4](tab, id);
  if (!p) return;
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 f = (*(u32 **)p)[0x128 / 4];
  u32 w = (*(g6_t **)tab)[0x114 / 4](tab, 0x6a5c78, 0, 0x6a57fc, 0x45c, &r, 0);
  ((v1_t)f)(p, w & 0xffff);
  u32 rec = ext_5003d0(*(u32 *)(a + 8), 0);
  ext_5002f0(rec, r);
}
PCREG(553980, fn553980);
