// batch1209.cpp - fresh slice 12, batch 9. Names are FUN_ in the exe list (no map entry). Exe callees run as
// ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);     // ret 8 (render-manager call; hooked)
extern "C" u32 THISCALL ext_4fbab0(u8 *self, u32 a);             // ret 4
extern "C" u32 THISCALL ext_4fd800(u8 *self, u32 a);             // ret 4
extern "C" u32 THISCALL ext_4fbb20(u8 *self, u32 a);             // ret 4
extern "C" u32 THISCALL ext_562d90(u8 *self, u32 v);             // ret 4
extern "C" u32 THISCALL ext_566f10(u8 *self);                    // ret 0
extern "C" void THISCALL ext_563d20(u8 *self, u32 a, u32 *p, u32 n);   // ret 0xc
extern "C" void THISCALL ext_563d40(u8 *self, u32 a, u32 *p, u32 n);   // ret 0xc
extern "C" void THISCALL ext_5672c0(u8 *self, u32 v);            // ret 4
extern "C" void THISCALL ext_567510(u8 *self);                   // ret 0

// 0x448ec0: for every id in the list at +0x1c (slot 0x4c(&it) begins, slot 0x5c(&it) yields the id, it.first == 0
// ends): engine(+0x9b)->slot 0x58(id)->slot 0x218() when found. Then 0x4dc630(+8, 0x2000, 0) and +0x18 |= 9.
static void THISCALL f448ec0(u8 *self) {
  u8 *l = *(u8 **)(self + 0x1c);
  if (l) {
    u32 it[3];
    vcall<u32>(l, 0x4c, it);
    u32 id = vcall<u32>(*(u8 **)(self + 0x1c), 0x5c, it);
    while (it[0]) {
      u8 *o = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, id);
      if (o) vcall<u32>(o, 0x218);
      id = vcall<u32>(*(u8 **)(self + 0x1c), 0x5c, it);
    }
  }
  ext_4dc630(*(u8 **)(self + 8), 0x2000, 0);
  *(u32 *)(self + 0x18) |= 9;
}
PCREG(448ec0, f448ec0);

// 0x4fbfc0: id switch (u16): +0x54 -> 0x4fbab0(a); +0x56 -> 0x4fd800(a); +0x5a -> engine(+0x9b)->slot 0x58(a)->slot
// 0x128(word +0x5c, this, 0); +0x60 -> 0x4fbb20(a). Returns 0. ret 8.
static u32 THISCALL onEvent(u8 *self, u16 id, u32 a) {
  if (id == *(u16 *)(self + 0x54)) {
    ext_4fbab0(self, a);
  } else if (id == *(u16 *)(self + 0x56)) {
    ext_4fd800(self, a);
  } else if (id == *(u16 *)(self + 0x5a)) {
    u8 *o = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, a);
    vcall<u32>(o, 0x128, (u32) * (u16 *)(self + 0x5c), self, 0);
  } else if (id == *(u16 *)(self + 0x60)) {
    ext_4fbb20(self, a);
  }
  return 0;
}
PCREG(4fbfc0, onEvent);

// 0x574600: id = v == 1 ? +0x1bc : v == 2 ? +0x1b8 : 0; o = engine(+0x9b)->slot 0x58(id); when found:
// r = o->slot 0x20()->slot 0x25c(0x6a912c, 0); this goes into the first free one of r's four slots at +0x18, and
// r->+0x28 = v. EAX: 0 when o is null, else r. ret 4.
static u32 THISCALL attachSlot(u8 *self, u32 v) {
  u32 id = 0;
  if (v == 1) id = *(u32 *)(self + 0x1bc);
  else if (v == 2) id = *(u32 *)(self + 0x1b8);
  u8 *o = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, id);
  if (!o) return 0;
  u8 *q = vcall<u8 *>(o, 0x20);
  u8 *r = vcall<u8 *>(q, 0x25c, 0x6a912c, 0);
  for (s32 i = 0; i < 4; i++) {
    if (!((u32 *)(r + 0x18))[i]) {
      ((u8 **)(r + 0x18))[i] = self;
      break;
    }
  }
  *(u32 *)(r + 0x28) = v;
  return (u32)r;
}
PCREG(574600, attachSlot);

// 0x567180: refuses (false) while slot 0xd8() is true. v other than 0x102 / 0x103 goes to 0x562d90(v). Otherwise
// t = 0x566f10(); 0x563d20 (0x102) or 0x563d40 (0x103) gets (0, &t, 2); then 0x5672c0(t) and 0x567510(); true. ret 4.
static u32 THISCALL f567180(u8 *self, u32 v) {
  if (vcall<u8>(self, 0xd8)) return 0;
  if (v != 0x102 && v != 0x103) return ext_562d90(self, v);
  u32 t = ext_566f10(self);
  if (v == 0x102) ext_563d20(self, 0, &t, 2);
  else ext_563d40(self, 0, &t, 2);
  ext_5672c0(self, t);
  ext_567510(self);
  return 1;
}
PCREG(567180, f567180);
