#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);

extern "C" u32 THISCALL ext_41e680(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x593af0: thiscall(a) ret 4: dispatches on the kind a->[0x48] with target object b = a->[0x44] (this is the object it works for).
// kind 0 / 1: b->slot_0x1e0(0x1007d1) low byte set -> this->slot_0x4e4 / 0x4e8(b); else the same test on t = b->slot_0x20(): this->slot_0x4e4 / 0x4e8(b->slot_0x20())
//   (kind 0 then falls back to engine table 0x70038c slot 0xcc(a->[0x106]), kind 1 does nothing);
// kind 2 / 3: this->slot_0x130(b, this->u16[0x7c8 / 0x7ca], ext_41e680(this));
// other kinds: a->slot_0x94(name) where name is 0 for a null this or for a nonzero table 0x70038c slot 0x20(this), else the inlined body of 0x41e680
//   (a callback [table + 8](this) when this lies in [[table + 0xc], [table + 0x10]), else [this - 4] after slot 0xac(this) when that is 0).
extern "C" void THISCALL fn_593af0(u8 *self, u8 *a) {
  u8 *b = *(u8 **)(a + 0x44);
  switch (rd32u(a + 0x48)) {
    case 0:
    case 1: {
      u32 slot = rd32u(a + 0x48) == 0 ? 0x4e4 : 0x4e8;
      if ((u8)(*(V1 *)(vt(b) + 0x1e0))(b, 0x1007d1)) {
        (*(V1 *)(vt(self) + slot))(self, (u32)b);
        return;
      }
      void *t = (void *)(*(V0 *)(vt(b) + 0x20))(b);
      if ((u8)(*(V1 *)(vt(t) + 0x1e0))(t, 0x1007d1)) {
        u8 *sv = vt(self);
        u32 x = (*(V0 *)(vt(b) + 0x20))(b);
        (*(V1 *)(sv + slot))(self, x);
        return;
      }
      if (slot == 0x4e4) {
        void *E = G(void *, 0x70038c);
        (*(V1 *)(vt(E) + 0xcc))(E, rd32u(a + 0x106));
      }
      return;
    }
    case 2:
    case 3: {
      u8 *sv = vt(self);
      u32 x = ext_41e680(self);
      u32 w = *(u16 *)(self + (rd32u(a + 0x48) == 2 ? 0x7c8 : 0x7ca));
      (*(V3 *)(sv + 0x130))(self, (u32)b, w, x);
      return;
    }
    default: {
      u32 name = 0;
      if (self) {
        u8 *E = G(u8 *, 0x70038c);
        if (!(*(V1 *)(vt(E) + 0x20))(E, (u32)self)) {
          u32 cb = rd32u(E + 8);
          if (cb && rd32u(E + 0xc) <= (u32)self && (u32)self < rd32u(E + 0x10)) {
            name = (*(V0 *)&cb)(self);
          } else {
            if (rd32u(self - 4) == 0) (*(V1 *)(vt(E) + 0xac))(E, (u32)self);
            name = rd32u(self - 4);
          }
        }
      }
      (*(V1 *)(vt(a) + 0x94))(a, name);
      return;
    }
  }
}
PCREG(593af0, fn_593af0);
