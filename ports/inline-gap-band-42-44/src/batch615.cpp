// batch615.cpp - band 0x421000-0x441000, batch 615: two forwarders to virtual calls.
//   0x434e00 ZSysFileGC::LoadWholeSceneZip(const char *name) (cdecl-style ret 4 wrapper, see note): the object at global
//     0x700394 gets slot 0x90 with (name, 1); returns nothing. Thiscall with the object as this.
//   0x4359d0 ZSysFile::UseBig(const char *name, bool flag) (thiscall, ret 8): slot 0x128 of this with (name, flag); returns 1.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vTwo)(void *self, u32 a, u32 b);

static void THISCALL loadWholeSceneZip(u8 *unused, u32 name) {
  (void)unused;
  u8 *o = G(u8 *, 0x700394);
  ((vTwo)VT(o, 0x90))(o, name, 1);
}
PCREG(434e00, loadWholeSceneZip);

static u8 THISCALL useBig(u8 *self, u32 name, u32 flag) {
  ((vTwo)VT(self, 0x128))(self, name, flag);
  return 1;
}
PCREG(4359d0, useBig);
