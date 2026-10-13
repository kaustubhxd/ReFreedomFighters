// batch1008.cpp - area 81 (residue 0), batch 1008: CEntityTracker::FrameUpdate(), 0x5bfe00, thiscall, no arguments, plain ret.
// Cookie check not reproduced (no SEH frame). Stand-ins (GUESS): 0x591ae0 (thiscall, returns the object whose +0x44 holds the vector object),
// 0x43e920 (fastcall, writes a three-float vector to ecx, one stack argument), 0x44c840 (thiscall on the vector, returns a float in st0),
// 0x646040 (thiscall on the object from 0x24c, returns a bool). The 0x80 vslot of the +0x44 object writes the three floats of f34.
// Float constants of the exe: 3500.0 at 0x69f9e0, 8000.0 at 0x6b3990, 0.5 at 0x67a6ac, 15000.0 at 0x6b3994, 2500.0 at 0x6b398c,
// 5000.0 at 0x69eb5c, 0.7070000171661377 at 0x6ad1f8, 1/1024 at 0x6785e4, -1024.0 at 0x67862c.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_591ae0(void *self);                                       // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_43e920(void *ecx, void *edx, void *a2);  // GUESS (stood in)
extern "C" float THISCALL ext_44c840(void *self);                                     // GUESS (stood in)
extern "C" u32 THISCALL ext_646040(void *self);                                       // GUESS (stood in)

// 0x5bfe00 CEntityTracker::FrameUpdate().
static void THISCALL entityTrackerFrameUpdate(u8 *self) {
  if (!D(self, 0x54))
    return;
  for (u32 i = 0; i < D(self, 0x5c); ++i) {
    if (D(self, 0x58) >= D(self, 0x54))
      D(self, 0x58) = 0;
    u32 j = D(self, 0x58);
    D(self, 0x58) = j + 1;
    vcall<void>(self, 0x98, D(self, 0x50) + j * 0x17);
  }
  u8 *g2 = (u8 *)D(self, 0x64);
  if (!g2 || !*(u8 *)(self + 0x68))
    return;
  u8 *g = ext_591ae0(g2);
  u32 l10 = 0;
  float f34[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>((void *)D(g, 0x44), 0x80, (u32)f34, (u32)&l10);
  float l44 = f34[0], l40 = f34[1], l48 = f34[2];

  for (u32 k = 0, off = 0; k < D(self, 0x54); ++k, off += 0x17) {
    u8 *edi = (u8 *)(D(self, 0x50) + off);
    u8 *o = (u8 *)D(edi, 0);
    float v58[3] = {0.0f, 0.0f, 0.0f};
    bool go = D((u8 *)D(o, 0x54), 8) != 4 && *(u8 *)(o + 0x917) != 0 && !(u8)vcall<u32>(o, 0x438);
    if (go) {
      u32 q = vcall<u32>(o, 0x24c);
      go = (u8)ext_646040((void *)q);
    }
    bool toY = false;
    if (go) {
      ext_43e920(v58, edi + 4, &l10);
      float f = ext_44c840(v58);
      float dot = (v58[1] * l40 + v58[0] * l44) + v58[2] * l48;
      u8 *o2 = (u8 *)D(edi, 0);
      bool flagSet = (D((u8 *)D(o2, 8), 0x3c) & 0x1000) != 0;
      bool toX;
      if (D((u8 *)D(o2, 0x54), 4) == 2)
        toX = 3500.0f > f || (8000.0f > f && dot > 0.5f);
      else
        toX = 2500.0f > f || (5000.0f > f && dot > 0.7070000171661377f);
      toY = !(toX || (15000.0f > f && flagSet));
    }
    if (toY) {
      if (*(u8 *)(edi + 0x10)) {
        float ff = *(float *)(edi + 0x11);
        u32 t = (u32)(int)(ff * -1024.0f);
        u32 ecx = 0x1000u - t;
        if ((int)D(*(u8 **)0x70039c, 0x40) > (int)ecx) {
          *(u8 *)(edi + 0x10) = 0;
          vcall<void>((void *)D(edi, 0), 0x114, 0x10u);
          vcall<void>((void *)D(self, 0x44), 0x130, D(edi, 0), (u32)W16(self, 0x48), 0u);
          vcall<void>((void *)D(edi, 0), 0x694, 0u);
          return;
        }
      }
      continue;
    }
    bool active = *(u8 *)(edi + 0x10) != 0;
    *(float *)(edi + 0x11) = (float)(int)D(*(u8 **)0x70039c, 0x40) * 0.0009765625f;
    if (active)
      continue;
    *(u8 *)(edi + 0x10) = 1;
    vcall<void>((void *)D(edi, 0), 0x110, 0x10u, 0u);
    vcall<void>((void *)D(self, 0x44), 0x130, D(edi, 0), (u32)W16(self, 0x4a), 0u);
    vcall<void>((void *)D(edi, 0), 0x694, 1u);
    return;
  }
}
PCREG(5bfe00, entityTrackerFrameUpdate);
