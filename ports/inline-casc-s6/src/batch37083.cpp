// batch37083.cpp - cascade s6 batch 37083: 0x46f7d0.
#include "ff.h"

extern "C" void THISCALL ext_46f520(u8 *self, u8 *s);   // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define P(o) ((u32)(self + (o)))

// 0x46f7d0, thiscall(stream) ret 4, returns 1: serialises this object's fields through a chaining stream object (every slot takes one field address and 0x40 / 0x48 / 0x50 / 0x68
// return the stream to chain on): 0x46f520 first, then the byte / word / dword fields at +0xaa .. +0x101 in a fixed order (slot 0x6c, 0x40, 0x48, 0x68, 0x50 are the typed
// writers), the dword at +0xd5 being staged through a local, and finally slot 0x70 with the value at +0xd9.
static u8 THISCALL fn46f7d0(u8 *self, u8 *s) {
  void *r;
  ext_46f520(self, s);
  vcall<void>(s, 0x6c, P(0xaa));
  vcall<void>(s, 0x40, P(0xb6));
  vcall<void>(s, 0x48, P(0xba));
  r = (void *)vcall<u32>(s, 0x68, P(0xbe));
  r = (void *)vcall<u32>(r, 0x68, P(0xbf));
  r = (void *)vcall<u32>(r, 0x48, P(0xc0));
  r = (void *)vcall<u32>(r, 0x48, P(0xc4));
  r = (void *)vcall<u32>(s, 0x68, P(0xc8));
  r = (void *)vcall<u32>(r, 0x68, P(0xc9));
  r = (void *)vcall<u32>(r, 0x68, P(0xca));
  r = (void *)vcall<u32>(r, 0x68, P(0xcb));
  r = (void *)vcall<u32>(r, 0x68, P(0xcc));
  u32 tmp;
  r = (void *)vcall<u32>(s, 0x50, P(0xd1));
  vcall<u32>(r, 0x40, (u32)&tmp);
  D32(self, 0xd5) = tmp;
  r = (void *)vcall<u32>(s, 0x40, P(0xdd));
  r = (void *)vcall<u32>(r, 0x40, P(0xe5));
  r = (void *)vcall<u32>(r, 0x40, P(0xe1));
  r = (void *)vcall<u32>(r, 0x40, P(0xed));
  vcall<void>(s, 0x6c, P(0xf1));
  r = (void *)vcall<u32>(s, 0x40, P(0xfd));
  vcall<u32>(r, 0x40, P(0x101));
  vcall<void>(s, 0x70, D32(self, 0xd9));
  return 1;
}
PCREG(46f7d0, fn46f7d0);
