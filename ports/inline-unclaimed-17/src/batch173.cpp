// batch173.cpp - unclaimed area 17, slice floor(addr/16) mod 20 == 16. DRAFT: not built against a spec yet.
#include "ff.h"

// 0x4fc500, thiscall (no stack args), CMAINCAMERACONTROL::GetCamera (map name, body checked). Returns this+? or 0.
// Engine global 0x70039c (+0x9b geom db) is read through G(). Embedded object at this+0x98 is called as a vtable
// object (slots 0x14, 0x30). Virtual slots used: geom 0x58 / 0x4c, object 0x128 / 0x12c, list node +0x48.
// The three ext_ calls below are not checked: ext_4fd800 is assumed THISCALL with one stack argument (ret 4).
extern "C" void THISCALL ext_4fd800(u32 self, u32 node);

typedef u32 (THISCALL *F0)(u32 self);
typedef u32 (THISCALL *F1)(u32 self, u32 a);
typedef u32 (THISCALL *F2)(u32 self, u32 a, u32 b);
typedef void (THISCALL *V2)(u32 self, u32 a, u32 b);
typedef void (THISCALL *V3)(u32 self, u32 a, u32 b, u32 c);

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline u16 rdh(u32 p, u32 off) { return *(u16 *)(unsigned long)(p + off); }
static inline void wrw(u32 p, u32 off, u32 v) { *(u32 *)(unsigned long)(p + off) = v; }
static inline u32 vt(u32 obj, u32 slot) { return *(u32 *)(unsigned long)(rdw(obj, 0) + slot); }
static inline u32 geom() { return rdw(rdw(0x70039c, 0), 0x9b); }

static u32 THISCALL getCamera(u32 self) {
  u32 emb = self + 0x98;
  u32 esi = 0, edi = 0, g = 0, a = 0;

  if (((F0)vt(emb, 0x14))(emb)) {   // embedded object: slot 0x14 nonzero
    esi = ((F1)vt(emb, 0x30))(emb, 0);
    goto L533;
  }

  // L5a0: no camera from the embedded object
  if (rdw(self, 0x84) == 0) {
    edi = ((F1)vt(geom(), 0x58))(geom(), rdw(self, 0x78));
    {
      u32 r = ((F2)vt(geom(), 0x4c))(geom(), rdw(self, 0x44), 0);
      // edi's vtable slot 0x128, with ecx = edi
      ((V2)vt(edi, 0x128))(edi, rdh(self, 0x80), r);
    }
    if (rdw(self, 0x84) == 0)
      return 0;
  }

  // L5fb: walk the list at this+0x84
  a = rdw(rdw(self, 0x84), 0x48);
  if (a == 0)
    goto L533;
  esi = rdw(a, 0);

L608:
  if (((F1)vt(geom(), 0x58))(geom(), esi))
    goto L533;
  ext_4fd800(rdw(self, 0x84), esi);
  g = rdw(rdw(self, 0x84), 0x48);
  if (g == 0)
    return 0;
  esi = rdw(g, 0);
  goto L608;

L533:
  edi = ((F1)vt(geom(), 0x58))(geom(), esi);
  if (esi == rdw(self, 0x74))
    wrw(self, 0x144, 0);
  else {
    if (rdw(self, 0x74) != 0) {
      u32 t = ((F1)vt(geom(), 0x58))(geom(), rdw(self, 0x74));
      if (t)
        ((V3)vt(t, 0x128))(t, rdh(self, 0x64), 0, 0);
    }
    if (edi) {
      ((V3)vt(rdw(self, 0x44), 0x12c))(rdw(self, 0x44), esi, rdh(self, 0x62), self);
      wrw(self, 0x74, esi);
    } else {
      esi = 0;
      wrw(self, 0x74, 0);
    }
  }
  // 0x4fc64f
  if (edi == 0)
    return 0;
  if (rdw(rdw(edi, 0xc), 0x23) & 0x400000)
    return edi;
  return 0;
}
PCREG(4fc500, getCamera);
