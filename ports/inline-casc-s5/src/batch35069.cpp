// batch35069.cpp - cascade s5 batch 35069: 0x5af8f0 (GUESS look an entry up and run a lookup + two virtual calls on it, n times).
#include "ff.h"

extern "C" u32 *THISCALL ext_5af130(u32 self, u32 a);   // thiscall, ret 4
typedef u8 *(THISCALL *g2_t)(void *, u32, u32);
typedef u32(THISCALL *g3_t)(void *, u32, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x5af8f0, thiscall(a, n) ret 8, returns r (EAX = r on every path). r = 0x5af130([this+4], a); nothing more when r is null or [r] is zero. Otherwise n times: X = [r] (reloaded), tab = [engine+0x9b],
// o = X slot 0x2c4([tab+0xadc], 0x4954454d); when o is non-null: id = tab slot 0x4c([this], 0, 1); o slot 0x2f0(id) (the vtable slot read before the id lookup); o slot 0x2d0(1, 0).
static u32 *THISCALL fn5af8f0(u8 *self, u32 a, u32 n) {
  u32 *r = ext_5af130(*(u32 *)(self + 4), a);
  if (!r || *r == 0) return r;
  while (n) {
    u8 *X = (u8 *)*r;
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u8 *o = (*(g2_t **)X)[0x2c4 / 4](X, *(u32 *)(tab + 0xadc), 0x4954454d);
    if (o) {
      u32 f = (*(u32 **)o)[0x2f0 / 4];
      eng = G(u8 *, 0x70039c);
      tab = *(u8 **)(eng + 0x9b);
      u32 id = (*(g3_t **)tab)[0x4c / 4](tab, *(u32 *)self, 0, 1);
      ((v1_t)f)(o, id);
      (*(v2_t **)o)[0x2d0 / 4](o, 1, 0);
    }
    n--;
  }
  return r;
}
PCREG(5af8f0, fn5af8f0);
