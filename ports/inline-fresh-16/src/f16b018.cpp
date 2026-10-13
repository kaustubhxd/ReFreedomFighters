// f16b018.cpp - fresh slice 16, batch 18 (2026-10-12).
// 0x57ae00 ZFFSetStartZone::OnCommand(cmd): ZVideoSelector::OnCommand(cmd); lo = [0x70039c] slot 0x5c(0x6a7584, &s) ?
//           atoi(s) : 0; cmd >= lo (signed) and cmd - 2 <= 6 (unsigned): id = RegisterZMsg (db slot 0x114)(0x6a8530, 0,
//           0x6aa018, 0x3b); [this+0x44] slot 0x12c([this+0x180], (u16)id, &cmd) (SendCommand; &cmd is the 5th pushed word,
//           stack-word sharing); this slot 0xd0([this+0x180]). Returns false.
// 0x43dec0 (fastcall a, b; c, d): p = d ? 0x45c4f0(0x18, d) : 0x45c4b0(0x18); p -> ZGEOM::ZGEOM(p; c, a, b), vtable 0x67c3a4.
//           Returns p or 0. Ret 8. SEH not reproduced.
// 0x4f5ac0 ZWinGfxHandler::CopyData(src): ZBOXGATEGROUP::CopyData(src); copies dwords +0x60..+0x9c.
// 0x4cde80 STATICREFTAB::DelRefPtr(p): n = +0x18; +0x14--; e = p[n-1]; --e[2] != 0 -> [+0x1c] slot 4(p), return. Else unlink e
//           (e[0] = prev, e[1] = next; head at +4); h = +0x1c: h slot 0x4c(&it); r = h slot 0x5c(&it); while it[0]:
//           r[n-1] == e -> h slot 0x44(&it); r = h slot 0x5c(&it). Then this slot 0x7c(e).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_562c20[], ext_45c4f0[], ext_45c4b0[], ext_45c3a0[], ext_4ef200[];

extern "C" bool THISCALL f16_57ae00(u8 *self, u32 cmd) {
  ((u32(THISCALL *)(void *, u32))(void *)ext_562c20)(self, cmd);
  char *s;
  int lo = 0;
  if (vcall<bool>(G(void *, 0x70039c), 0x5c, 0x6a7584u, &s)) {
    typedef int (*Atoi)(const char *);
    lo = G(Atoi, 0x6762d8)(s);
  }
  if ((int)cmd >= lo && cmd - 2 <= 6) {
    void *h = AT(void *, self, 0x44);
    u32 id = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x6a8530u, 0u, 0x6aa018u, 0x3bu);
    vcall<void>(h, 0x12c, AT(u32, self, 0x180), (u32)(u16)id, &cmd);
    vcall<void>(self, 0xd0, AT(u32, self, 0x180));
  }
  return false;
}

extern "C" void *FASTCALL f16_43dec0(u32 a, u32 b, u32 c, u32 d) {
  void *p = d ? ((void *(*)(u32, u32))(void *)ext_45c4f0)(0x18, d) : ((void *(*)(u32))(void *)ext_45c4b0)(0x18);
  if (!p) return 0;
  ((void(THISCALL *)(void *, u32, u32, u32))(void *)ext_45c3a0)(p, c, a, b);
  AT(u32, p, 0) = 0x67c3a4u;
  return p;
}

extern "C" void THISCALL f16_4f5ac0(u8 *self, u8 *src) {
  ((void(THISCALL *)(void *, void *))(void *)ext_4ef200)(self, src);
  for (u32 o = 0x60; o <= 0x9c; o += 4) AT(u32, self, o) = AT(u32, src, o);
}

extern "C" void THISCALL f16_4cde80(u8 *self, u32 *p) {
  u32 n = AT(u32, self, 0x18);
  AT(u32, self, 0x14)--;
  u32 *e = (u32 *)p[n - 1];
  if (--e[2] != 0) {
    vcall<void>(AT(void *, self, 0x1c), 4, p);
    return;
  }
  u32 prev = e[0], next = e[1];
  if (prev)
    ((u32 *)prev)[1] = next;
  else
    AT(u32, self, 4) = next;
  if (e[1]) *(u32 *)e[1] = e[0];
  if (AT(void *, self, 0x1c)) {
    u32 it[3];
    vcall<void>(AT(void *, self, 0x1c), 0x4c, it);
    u32 *r = vcall<u32 *>(AT(void *, self, 0x1c), 0x5c, it);
    while (it[0]) {
      if (r[AT(u32, self, 0x18) - 1] == (u32)e) vcall<void>(AT(void *, self, 0x1c), 0x44, it);
      r = vcall<u32 *>(AT(void *, self, 0x1c), 0x5c, it);
    }
  }
  vcall<void>(self, 0x7c, e);
}

PCREG(57ae00, f16_57ae00);
PCREG(43dec0, f16_43dec0);
PCREG(4f5ac0, f16_4f5ac0);
PCREG(4cde80, f16_4cde80);
