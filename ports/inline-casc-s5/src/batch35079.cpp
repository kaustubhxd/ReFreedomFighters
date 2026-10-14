// batch35079.cpp - cascade s5 batch 35079: 0x473fe0 (GUESS query a value of the object o resolves to, 999 as the "not allowed" answer).
#include "ff.h"

typedef u8 *(THISCALL *g0_t)(void *);
typedef u8(THISCALL *b0_t)(void *);
typedef u8(THISCALL *b1_t)(void *, u32);
typedef u8 *(THISCALL *g1_t)(void *, void *);
typedef u32(THISCALL *w0_t)(void *);

// 0x473fe0, thiscall(o) ret 4, returns EAX. 0x3e7 when byte [[engine+0x9b]+0xbac] is set. p = o slot 0x350(); when p is non-null and p slot 0x328() (AL) is false: 0x3e7. q = this slot 0x55c(o); null gives 0;
// q slot 0x1e0(0x1007d8) false gives 0; otherwise q slot 0x320().
static u32 THISCALL fn473fe0(u8 *self, u8 *o) {
  u8 *eng = G(u8 *, 0x70039c);
  if ((*(u8 **)(eng + 0x9b))[0xbac]) return 0x3e7;
  u8 *p = (*(g0_t **)o)[0x350 / 4](o);
  if (p && !(*(b0_t **)p)[0x328 / 4](p)) return 0x3e7;
  u8 *q = (*(g1_t **)self)[0x55c / 4](self, o);
  if (!q) return 0;
  if (!(*(b1_t **)q)[0x1e0 / 4](q, 0x1007d8)) return 0;
  return (*(w0_t **)q)[0x320 / 4](q);
}
PCREG(473fe0, fn473fe0);
