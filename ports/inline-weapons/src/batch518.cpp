// batch518.cpp - weapons thread, batch 518: ZFFHERO::ControlDrop (dropping the held item; throwables keep their
// spare rounds) and ZFFHERO::AttachItemBack (carrying a large weapon on the back).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *vU4)(void *self, u32 a, u32 b, u32 c, u32 d);
typedef u8(THISCALL *vBU)(void *self, u32 a);
extern "C" void THISCALL ext_473000(u8 *self, u32 item);                        // ZLNKWHANDS::ControlDrop
extern "C" void FASTCALL ext_4de7a0(float *m);                                  // mreset
extern "C" void FASTCALL ext_4deb20(float *out, float deg, float x, float y, float z);   // mrotaxis
extern "C" void FASTCALL ext_4de480(float *m, const float *r);                  // m = m * r
extern "C" void THISCALL ext_4dcbb0(void *geom, u8 on);                         // ZBaseGeom::SetOwnerDraw

static inline u32 handleOf(u32 o) {
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((vUU)VT(rm, 0x4c))(rm, o);
}

// 0x58eb50 ControlDrop(item): remembers the item's handle (+0x83e). For thrown weapons (template type 0xb or 0xc)
// the rounds beyond the one in hand go back to the inventory ammo item (created from the ammo template in the hero's
// 'MEIT' group when missing, owned by the hero) and the item keeps 1; then a fresh item of the same template is
// created in the world ('MEIT' in [render manager]+0xadc), owned by the hero, state 1. Then ZLNKWHANDS::ControlDrop.
static void THISCALL heroControlDrop(u8 *self, u8 *item) {
  *(u32 *)(self + 0x83e) = handleOf((u32)item);
  if (((vBU)VT(item, 0x1e0))(item, 0x1007d2)) {
    u8 *t = (u8 *)((vU0)VT(item, 0x2e8))(item);
    if (((vU0)VT(t, 0x330))(t) == 0xc || ((vU0)VT(t, 0x330))(t) == 0xb) {
      s32 n = (s32)((vU0)VT(item, 0x35c))(item);
      if (n > 1) {
        u8 *a = (u8 *)((vUU)VT(self, 0x55c))(self, (u32)item);
        if (!a) {
          u8 *at = (u8 *)((vU0)VT(item, 0x328))(item);
          u32 grp = ((vUU)VT(self, 0x20))(self, 0x4954454d);
          a = (u8 *)((vUU)VT(at, 0x2c4))(at, grp);
          ((vUUUU)VT(a, 0x2f0))(a, handleOf((u32)self), 0, 1);
        }
        u32 have = ((vU0)VT(a, 0x320))(a);
        ((vUU)VT(a, 0x324))(a, have + (u32)(n - 1));
        ((vUU)VT(item, 0x360))(item, 1);
      }
      u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *nw = (u8 *)((vUUU)VT(t, 0x2c4))(t, *(u32 *)(rm + 0xadc), 0x4954454d);
      ((vUUUU)VT(nw, 0x2f0))(nw, handleOf((u32)self), 0, 1);
      ((vUUU)VT(nw, 0x2d0))(nw, 1, 0);
    }
  }
  ext_473000(self, (u32)item);
}
PCREG(58eb50, heroControlDrop);

// 0x58bc60 AttachItemBack(item): the RPG ("Rpg7V" template) and other large weapons hang on the back on bone 0xc
// (own slot 0x290) at an offset (RPG: (-23.5 or -20 when +0xeec is clear, 0, 30); others: (-25 or -20, -15, 12)),
// rotated 90 degrees about z and then -30 (RPG) or 150 degrees about x; owner-draw on; handle kept at +0x842.
static void THISCALL attachItemBack(u8 *self, u8 *item) {
  u8 *t = (u8 *)((vU0)VT(item, 0x2e8))(item);
  const char *nm = *(const char **)(t + 4);
  if (!nm)
    nm = (const char *)0x67c8e8;
  const char *rpg = (const char *)0x6ac9a0;   // "Rpg7V"
  int diff = 0;
  for (int i = 0;; i++) {
    if (nm[i] != rpg[i]) { diff = 1; break; }
    if (!nm[i]) break;
  }
  float pos[3], m[9], r[9];
  if (!diff) {
    pos[1] = 0.0f;
    pos[2] = 30.0f;
    pos[0] = self[0xeec] ? -23.5f : -20.0f;
    ext_4de7a0(m);
    ext_4deb20(r, 90.0f, 0.0f, 0.0f, 1.0f);
    ext_4de480(m, r);
    ext_4deb20(r, -30.0f, 1.0f, 0.0f, 0.0f);
  } else {
    pos[1] = -15.0f;
    pos[2] = 12.0f;
    pos[0] = self[0xeec] ? -25.0f : -20.0f;
    ext_4de7a0(m);
    ext_4deb20(r, 90.0f, 0.0f, 0.0f, 1.0f);
    ext_4de480(m, r);
    ext_4deb20(r, 150.0f, 1.0f, 0.0f, 0.0f);
  }
  ext_4de480(m, r);
  ((vU4)VT(self, 0x290))(self, *(u32 *)(item + 8), 0xc, (u32)m, (u32)pos);
  ext_4dcbb0(*(void **)(item + 8), 1);
  *(u32 *)(self + 0x842) = handleOf((u32)item);
}
PCREG(58bc60, attachItemBack);
