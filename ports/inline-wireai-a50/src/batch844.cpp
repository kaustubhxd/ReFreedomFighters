// batch844.cpp - area 50 (residue-10 list): ZItemTemplateWeapon::Load(ZLoadGame*) [medium, vt 5]. Mirror of Save (batch 842):
// the base group is loaded first (ZGROUP::Load, 0x440e10, hooked); then values come from the stream: int into vt +0x70
// (the stored int is passed by value), pointers into vt +0x74 (+0xdb) and vt +0x6c (+0xff), floats by reference into
// vt +0x50 (+0x10b, +0x10f), and four words read by reference through vt +0x40 and resolved through the global manager's
// vt +0x58 (stored at +0x11b, +0x11f, +0x123, +0x127). The exe reuses its argument slot as the temporary (no effect here).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// the engine's global manager (the object at [[0x70039c]+0x9b])
static inline void *FP_mgr() { return FP(G(void *, 0x70039c), 0x9b); }

extern "C" void THISCALL ext_440e10(void *self, void *stream);   // ZGROUP::Load (not ported here)

static bool THISCALL ZItemTemplateWeapon_Load(u8 *self, void *s) {
  ext_440e10(self, s);
  vcall<void>(s, 0x70, F32(self, 0x70));
  vcall<void>(s, 0x74, self + 0xdb);
  vcall<void>(s, 0x6c, self + 0xff);
  vcall<void>(s, 0x50, self + 0x10b);
  vcall<void>(s, 0x50, self + 0x10f);
  for (u32 off = 0x11b; off <= 0x127; off += 4) {
    u32 tmp = 0;
    vcall<void>(s, 0x40, &tmp);
    F32(self, off) = vcall<u32>(FP_mgr(), 0x58, tmp);
  }
  return true;
}
PCREG(46f6e0, ZItemTemplateWeapon_Load);
