// batch55.cpp - throw tree, inline session batch 55: ZFFHERO::ControlSpecialItems (0x58ff30).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u8(THISCALL *vcallB0)(void *self);
typedef u8(THISCALL *vcallBU)(void *self, u32 a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef void(THISCALL *vcallVU)(void *self, u32 a);

extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);   // striwcmp (batch 54)

// MSVC's inline strcmp, only tested for zero.
static bool same(const u8 *a, const u8 *b) {
  for (;;) {
    if (a[0] != b[0]) return false;
    if (a[0] == 0) return true;
    if (a[1] != b[1]) return false;
    if (a[1] == 0) return true;
    a += 2;
    b += 2;
  }
}

// The hero's slot 0x3ec turns an action id into an action, and slot 0x3d8 starts it.
static void startAction(u8 *self, u32 id) {
  void **vt = *(void ***)self;
  u32 a = ((vcallUU)vt[0x3ec / 4])(self, id);
  ((vcallVU)vt[0x3d8 / 4])(self, a);
}

// 0x58ff30 ZFFHERO::ControlSpecialItems(), thiscall, result in al. Only with the use key (byte +0x669) held and an item
// in hand (slot 0x504). A weapon (slot 0x1e0(0x1007d2)) of kind 0xb or 0xc (slot 0x330 of its slot 0x350 object) with
// ammo (slot 0x35c) is thrown, action 0x11, when its slot 0x354 is true, byte +0x66a is set and the state (slot 0x3f0)
// is 0. Kind 8 starts action 0x19 when slot 0x5a4 is true and the state is 0. Other weapons return 0. A non-weapon
// named FirstAid_Small, FirstAid_Medium or (wildcard) FirstAid_Large is used in state 0: its render-manager handle
// (slot 0x4c) goes to +0x83e, action 0x14, 0x15 or 0x16 starts, and +0x66b is cleared. Other items return 0.
static u8 THISCALL controlSpecialItems(u8 *self) {
  if (!self[0x669])
    return 0;
  u8 *w = (u8 *)((vcallU0)VT(self, 0x504))(self);
  if (!w)
    return 0;
  if (((vcallBU)VT(w, 0x1e0))(w, 0x1007d2)) {
    u8 *m = (u8 *)((vcallU0)VT(w, 0x350))(w);
    u32 kind = ((vcallU0)VT(m, 0x330))(m);
    if ((kind == 0xb || kind == 0xc) && ((vcallU0)VT(w, 0x35c))(w) != 0) {
      if (!((vcallB0)VT(w, 0x354))(w) || !self[0x66a] || ((vcallU0)VT(self, 0x3f0))(self) != 0)
        return 1;
      startAction(self, 0x11);
      return 1;
    }
    if (kind != 8)
      return 0;
    if (!((vcallB0)VT(self, 0x5a4))(self) || ((vcallU0)VT(self, 0x3f0))(self) != 0)
      return 1;
    startAction(self, 0x19);
    return 1;
  }
  u8 *ti = (u8 *)((vcallU0)VT(w, 0x2e8))(w);
  const u8 *name = *(const u8 **)(ti + 4);
  if (!name)
    name = (const u8 *)0x67c8e8u;   // "<NONAME>"
  u32 id;
  if (same(name, (const u8 *)0x6ace88u))   // "FirstAid_Small"
    id = 0x14;
  else if (same(name, (const u8 *)0x6ace98u))   // "FirstAid_Medium"
    id = 0x15;
  else if (ext_4cc850((const char *)name, (const char *)0x6acb04u) == 0)   // "FirstAid_Large"
    id = 0x16;
  else
    return 0;
  if (((vcallU0)VT(self, 0x3f0))(self) != 0)
    return 1;
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 h = ((vcallUU)VT(rm, 0x4c))(rm, (u32)w);
  *(u32 *)(self + 0x83e) = h;
  startAction(self, id);
  self[0x66b] = 0;
  return 1;
}
PCREG(58ff30, controlSpecialItems);
