// f16b024.cpp - fresh slice 16, batch 24 (2026-10-12).
// 0x4d1e40 (thiscall a, b, c): e = 0x4d1cf0(this; a); none -> error report (0x695fec, 0x1bb; 0x696028), return. Else
//           +0x14 -> sized delete(+0x14, 4), +0x14 = 0; +0x10 = 0; p = new(0x14) -> 0x4d14a0(p; b, c, this, e). Ret 0xc.
//           SEH not reproduced.
// 0x577480 ZCutSequenceMenu::Init(): ZVideoSelector::Init; [+0x44] slot 0xbc(1); SetBackGroundPicture(0x6a6850); lim = 10 *
//           ([0x70039c] slot 0x5c(0x6a7584, &s) ? atoi(s) : 0); g = [+0x54] slot 0x25c(0x6a7590, 0); for n = [g+0x50] while
//           n's class flags have 0x100000 (via +0x60): c = [n+0x54]; c slot 0x1e0(0x100033) && c slot 0x310() < lim ->
//           c slot 0x2dc().
// 0x4929c0 (thiscall): two blocks (slots 0x200/0x204, +0xbb7, list slot 8 and slots 0x208/0x20c, +0xbbb, list slot 0xc):
//           n = this slot(); n != -1 -> old = [0x70038c] slot 0x48(0x8080ff); p = new(n); +off = p; this slot(p, n);
//           [[[0x70039c]+0x1aa3]+0x1c] slot(p, n); [0x70038c] slot 0x48(old).
#include "ff.h"
#include "f16log.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4d1cf0[], ext_634273[], ext_41e290[], ext_4d14a0[], ext_562440[], ext_563510[];

extern "C" void THISCALL f16_4d1e40(u8 *self, u32 a, u32 b, u32 c) {
  u32 e = ((u32(THISCALL *)(void *, u32))(void *)ext_4d1cf0)(self, a);
  if (!e) {
    f16_report(0x695fecu, 0x1bb, 0x696028u);
    return;
  }
  if (AT(void *, self, 0x14)) {
    ((void (*)(void *, u32))(void *)ext_634273)(AT(void *, self, 0x14), 4);
    AT(u32, self, 0x14) = 0;
  }
  AT(u32, self, 0x10) = 0;
  void *p = ((void *(*)(u32))(void *)ext_41e290)(0x14);
  if (p) ((void(THISCALL *)(void *, u32, u32, void *, u32))(void *)ext_4d14a0)(p, b, c, self, e);
}

static inline u32 tgflags(u8 *n) {
  u8 *c = AT(u8 *, n, 0x54);
  return c ? AT(u32, AT(u8 *, c, 0xc), 0x23) : 0x200002u;
}

extern "C" void THISCALL f16_577480(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_562440)(self);
  vcall<void>(AT(void *, self, 0x44), 0xbc, 1u);
  ((void(THISCALL *)(void *, u32))(void *)ext_563510)(self, 0x6a6850u);
  char *s;
  int n = 0;
  if (vcall<bool>(G(void *, 0x70039c), 0x5c, 0x6a7584u, &s)) {
    typedef int (*Atoi)(const char *);
    n = G(Atoi, 0x6762d8)(s);
  }
  int lim = n * 10;
  u8 *g = vcall<u8 *>(AT(void *, self, 0x54), 0x25c, 0x6a7590u, 0u);
  for (u8 *nd = AT(u8 *, g, 0x50); nd; nd = AT(u8 *, nd, 0x60)) {
    if (!(tgflags(nd) & 0x100000)) return;
    if (vcall<bool>(AT(void *, nd, 0x54), 0x1e0, 0x100033u)) {
      void *c = AT(void *, nd, 0x54);
      if (vcall<int>(c, 0x310) < lim) vcall<void>(c, 0x2dc);
    }
  }
}

static inline void dumpblk(u8 *self, u32 sget, u32 sset, u32 off, u32 lslot) {
  int n = vcall<int>(self, sget);
  if (n == -1) return;
  u32 old = vcall<u32>(G(void *, 0x70038c), 0x48, 0x8080ffu);
  void *p = ((void *(*)(u32))(void *)ext_41e290)((u32)n);
  AT(void *, self, off) = p;
  vcall<void>(self, sset, p, n);
  vcall<void>(AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x1aa3), 0x1c), lslot, AT(void *, self, off), n);
  vcall<u32>(G(void *, 0x70038c), 0x48, old);
}

extern "C" void THISCALL f16_4929c0(u8 *self) {
  dumpblk(self, 0x200, 0x204, 0xbb7, 8);
  dumpblk(self, 0x208, 0x20c, 0xbbb, 0xc);
}

PCREG(4d1e40, f16_4d1e40);
PCREG(577480, f16_577480);
PCREG(4929c0, f16_4929c0);
