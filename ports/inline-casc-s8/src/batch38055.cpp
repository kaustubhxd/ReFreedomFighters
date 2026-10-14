// batch38055.cpp - cascade s8 batch 38055: 0x5703c0 (event handler of a menu page: apply / cancel / reset).
#include "ff.h"

extern "C" u32 THISCALL ext_59be70(u8 *o);              // AL
extern "C" void THISCALL ext_594f10(u8 *o, u32 a);      // ret 4
extern "C" void THISCALL ext_5706f0(u8 *self);
extern "C" void THISCALL ext_5718b0(u8 *self);
extern "C" void THISCALL ext_5707d0(u8 *self);
extern "C" u32 THISCALL ext_561cb0(u8 *self, u32 id, u32 v);   // ret 8 (generic handler)
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))
#define CFG (*(u8 **)(ENG + 0x1a9f))
#define U16F(off) (*(u16 *)(self + (off)))

static u16 name_id(u32 name, u32 line) {
  u8 *t = TABLE;
  return (u16)SLOT(t, 0x114, v4_t)(t, name, 0, 0x6a8684, line);
}

// 0x5703c0, thiscall(id, v) ret 8. Without the active flag (+0x1a3) every event goes to the generic handler 0x561cb0. Otherwise the u16 id is matched against the named ids of the table (0x69c814 line 0x1d0 =
// confirm, 0x6a6698 line 0x1ee = reset) and the stored ids at +0x1a4 / +0x1a6: confirm runs 0x594f10(this[0x90], 0) after either applying the pending value (0x59be70 true: sends the looked-up value
// and its name id to this[0x44] slot 0x12c and 4.0f to the config object's slot 0xd4) or cancelling (table slot 0xb4(1), config slot 0x138(1), slot 0x84 object slot 0x2fc); +0x1a4 clears the pending state
// (+0x1a0 = 1, +0x1a2 = 0); +0x1a6 runs 0x5706f0; reset runs 0x5718b0 / 0x5707d0 when the name at this[0x94] + 0x48 equals the string at 0x6a7808, else the generic handler.
static u32 THISCALL fn5703c0(u8 *self, u32 idarg, u32 v) {
  u16 id = (u16)idarg;
  if (self[0x1a3] == 0) return ext_561cb0(self, idarg, v);
  if (id == name_id(0x69c814, 0x1d0)) {
    if ((u8)ext_59be70(*(u8 **)(self + 0x94))) {
      u8 *d = (u8 *)SLOT(self, 0x84, v0_t)(self);
      u8 *t = TABLE;
      u8 *h = (u8 *)SLOT(t, 0x138, v0_t)(t);
      u32 l = 0;
      SLOT(h, 0x88, v2_t)(h, 0x6a86ec, (u32)&l);
      SLOT(d, 0x2f8, v1_t)(d, l);
      t = TABLE;
      h = (u8 *)SLOT(t, 0x138, v0_t)(t);
      l = 0;
      SLOT(h, 0x88, v2_t)(h, 0x6a5c48, (u32)&l);
      u8 *o44 = *(u8 **)(self + 0x44);
      u32 lv = l;
      u8 **vt = *(u8 ***)o44;
      u16 id2 = name_id(0x6a4f40, 0x1d6);
      ((v3_t)vt[0x12c / 4])(o44, lv, id2, 0);
      u8 *c = CFG;
      if (c) SLOT(c, 0xd4, v2_t)(c, 5, 0x40800000);
    } else {
      u8 *t = TABLE;
      SLOT(t, 0xb4, v1_t)(t, 1);
      u8 *c = CFG;
      if (c) SLOT(c, 0x138, v1_t)(c, 1);
      u8 *d = (u8 *)SLOT(self, 0x84, v0_t)(self);
      SLOT(d, 0x2fc, v1_t)(d, *(u32 *)(self + 0x44));
    }
    ext_594f10(*(u8 **)(self + 0x90), 0);
    return 0;
  }
  if (id == U16F(0x1a4)) {
    U16F(0x1a0) = 1;
    self[0x1a2] = 0;
    return 0;
  }
  if (id == U16F(0x1a6)) {
    ext_5706f0(self);
    return 0;
  }
  if (id == name_id(0x6a6698, 0x1ee)) {
    const u8 *a = *(u8 **)(self + 0x94) + 0x48;
    const u8 *b = (const u8 *)0x6a7808;
    bool eq = true;
    for (u32 i = 0;; i++) {
      if (a[i] != b[i]) {
        eq = false;
        break;
      }
      if (a[i] == 0) break;
    }
    if (eq) {
      ext_5718b0(self);
      ext_5707d0(self);
      return 0;
    }
  }
  return ext_561cb0(self, idarg, v);
}
PCREG(5703c0, fn5703c0);
