#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
extern "C" u32 THISCALL ext_5ec670(void *self, float x, u32 i);
extern "C" u32 THISCALL ext_5ec5f0(void *self, u32 a, u32 i);
extern "C" u32 THISCALL ext_5ec340(void *self, u32 a, u32 i);
extern "C" u32 THISCALL ext_5ec5a0(void *self, u32 i);
extern "C" u32 THISCALL ext_591b20(void *self);

static inline u32 rd32u(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x5a57a0: thiscall(this, a, sel, float x, b) ret 0x10: sel 1..12 picks a sub-object at this+0x5f8..0x624 (else sel is itself the
// object and the assert hook [0x7003b0] runs); if its index [+0x42] is below the capacity [+0x3e] it stores x, a, b and bumps the index
u32 THISCALL fn_5a57a0(u8 *self, u32 a, u32 sel, float x, u32 b) {
  if (sel == 0) return 0;
  u32 i = sel - 1;
  u32 eax = i;
  u8 *e;
  if (i > 0xb) {
    typedef u32 (*Hook)();
    Hook h = G(Hook, 0x7003b0);
    if (!h) __builtin_trap();
    eax = h();
    e = (u8 *)sel;
  } else {
    static const u16 off[12] = {0x600, 0x5fc, 0x608, 0x5f8, 0x610, 0x60c, 0x614, 0x604, 0x620, 0x61c, 0x624, 0x618};
    e = *(u8 **)(self + off[i]);
  }
  u32 idx = rd32u(e + 0x42);
  if (idx < rd32u(e + 0x3e)) {
    ext_5ec670(e, x, idx);
    ext_5ec5f0(e, a, idx);
    ext_5ec340(e, b, idx);
    eax = ext_5ec5a0(e, idx + 1);
  }
  return eax;
}
PCREG(5a57a0, fn_5a57a0);

// 0x5919f0: thiscall(this): field of this chosen by the kind of o->[0x350]() where o = this->[0x504]()
u32 THISCALL fn_5919f0(u8 *self) {
  u8 *o = (u8 *)(*(V0 *)(*(u8 **)self + 0x504))(self);
  if (!o) return 0;
  u32 r = (*(V1 *)(*(u8 **)o + 0x1e0))(o, 0x1007d2);
  if ((u8)r) {
    u8 *e = (u8 *)(*(V0 *)(*(u8 **)o + 0x350))(o);
    u32 k = (*(V0 *)(*(u8 **)e + 0x330))(e);
    if (k > 0xc) return 0;
    static const u8 map[13] = {0, 0, 1, 1, 1, 1, 1, 2, 5, 5, 5, 3, 4};
    switch (map[k]) {
      case 0: return *(u32 *)(self + 0x79c);
      case 1: {
        u32 f = rd32u(self + 0x417);
        if (f & 0x400) return *(u32 *)(self + 0x790);
        if (f & 2) return *(u32 *)(self + 0x794);
        return *(u32 *)(self + 0x78c);
      }
      case 2: return *(u32 *)(self + 0x798);
      case 3: return *(u32 *)(self + 0x7a0);
      case 4: return *(u32 *)(self + 0x7a4);
      default: return 0;
    }
  }
  if (ext_591b20(self) == 0x10) return *(u32 *)(self + 0x7ac);
  return 0;
}
PCREG(5919f0, fn_5919f0);
