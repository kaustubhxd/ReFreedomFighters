// f16b003.cpp - fresh slice 16, batch 3 (2026-10-12).
// 0x4cbcc0 ZTextureAnim::Command(u16 cmd, void*): cmd == 0x401 -> o = [[0x70039c]+0x1aa3]+0x18; o slot 0xe0([[this+0x44]+8],
//           float this+0x4c). Returns 0. Ret 8.
// 0x423980 ZSysInterfaceGC::Save(sg): ZSysInterface::Save 0x42f8c0; sg slot 0x50(this+0x23c6, this+0x23ca);
//           sg slot 0x58(double this+0x23ce, passed as two raw words). Ret 4.
// 0x6071c0: lower_bound of key (ECX) in the 28-dword sorted table 0x6b9e58; returns the entry, or -5 (0xfffffffb) at end.
// 0x4f3e00 ZWINDOW::CopyDataBlock(blk): ZMaterialDescGroup::CopyDataBlock 0x44edd0; DBLK::Get 0x4e12e0(this+0x60, 1);
//           GetType 0x4e1600 == 8 -> Get(this+0x64, 1); NextBlock 0x4e1b30. Ret 4.
// 0x5ffb00 VMImageInfo_t::getCommonString(u16 i): walk images via +0x9c; first with +0xa8 != 0 and +0xa0 <= i ->
//           tail 0x5ffd10(img+0xa0; arg) (ret 4); none -> handler at 0x7003b0 (int3 if null; that path is not run).
// 0x57bd00 ZFFLoadError::Init: CFileWindow::Init 0x564b10; s = db slot 0x138(); CCom::SetVal (s slot 0x60, ret 0xc)(0x6aa478, db slot 0x4c(+0x44) (ret 4), 0x10).
//           The pushed 0x10 before db slot 0x4c is SetVal's third argument (stack-word sharing).
// 0x64c040 (stdcall p): o = [[p+8]+0x38], non-null -> [o+0x54]; p+0x16 = o slot 0xf8() (AL); p+0xc non-null -> copy 48 bytes
//           from [p+8]+8. A null o calls through address 0 (fault); that input is not generated.
// 0x651180 ZRender::TextDisplayEnabled: x = sys slot 0x1b0(); x and x slot 0xc() -> false; else sys+0x9c7 != [0x6785d0]
//           (0.0f; NaN counts as not equal) and this+0x74 != 0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_42f8c0[], ext_44edd0[], ext_4e12e0[], ext_4e1600[], ext_4e1b30[], ext_5ffd10[], ext_564b10[];

extern "C" u32 THISCALL f16_4cbcc0(u8 *self, u32 cmd, u32) {
  if ((u16)cmd == 0x401) {
    void *o = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x1aa3), 0x18);
    vcall<void>(o, 0xe0, AT(u32, AT(u8 *, self, 0x44), 8), AT(u32, self, 0x4c));
  }
  return 0;
}

extern "C" void THISCALL f16_423980(u8 *self, void *sg) {
  ((void(THISCALL *)(void *, void *))(void *)ext_42f8c0)(self, sg);
  vcall<void>(sg, 0x50, AT(u32, self, 0x23c6), AT(u32, self, 0x23ca));
  vcall<void>(sg, 0x58, AT(u32, self, 0x23ce), AT(u32, self, 0x23d2));
}

extern "C" u32 FASTCALL f16_6071c0(u32 key) {
  const u32 *p = (const u32 *)0x6b9e58;
  s32 n = 0x1c;
  while (n > 0) {
    s32 h = n >> 1;
    if (p[h] < key) {
      p = p + h + 1;
      n = n - h - 1;
    } else {
      n = h;
    }
  }
  return p == (const u32 *)0x6b9ec8 ? 0xfffffffbu : *p;
}

extern "C" void THISCALL f16_4f3e00(u8 *self, void *blk) {
  typedef void(THISCALL * Get)(void *, void *, u32);
  ((void(THISCALL *)(void *, void *))(void *)ext_44edd0)(self, blk);
  ((Get)(void *)ext_4e12e0)(blk, self + 0x60, 1);
  if (((u8(THISCALL *)(void *))(void *)ext_4e1600)(blk) == 8) ((Get)(void *)ext_4e12e0)(blk, self + 0x64, 1);
  ((void(THISCALL *)(void *))(void *)ext_4e1b30)(blk);
}

extern "C" u32 THISCALL f16_5ffb00(u8 *img, u32 arg) {
  do {
    if (AT(u32, img, 0xa8) != 0 && AT(u32, img, 0xa0) <= (u16)arg)
      return ((u32(THISCALL *)(void *, u32))(void *)ext_5ffd10)(img + 0xa0, arg);
    img = AT(u8 *, img, 0x9c);
  } while (img);
  typedef u32 (*Hfn)();
  Hfn h = G(Hfn, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}

extern "C" void THISCALL f16_57bd00(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_564b10)(self);
  void *s = vcall<void *>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x138);
  u32 r = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x4c, AT(u32, self, 0x44));
  vcall<void>(s, 0x60, 0x6aa478u, r, 0x10u);
}

extern "C" void STDCALL f16_64c040(u8 *p) {
  void *o = AT(void *, AT(u8 *, p, 8), 0x38);
  if (o) o = AT(void *, o, 0x54);
  AT(u8, p, 0x16) = vcall<u8>(o, 0xf8);
  u32 *d = AT(u32 *, p, 0xc);
  if (d) {
    const u32 *s = (const u32 *)(AT(u8 *, p, 8) + 8);
    for (int i = 0; i < 12; ++i) d[i] = s[i];
  }
}

extern "C" bool THISCALL f16_651180(u8 *self) {
  void *x = vcall<void *>(G(void *, 0x70039c), 0x1b0);
  if (x && vcall<bool>(x, 0xc)) return false;
  float f = AT(float, G(u8 *, 0x70039c), 0x9c7);
  return f != G(float, 0x6785d0) && AT(u32, self, 0x74) != 0;
}

PCREG(4cbcc0, f16_4cbcc0);
PCREG(423980, f16_423980);
PCREG(6071c0, f16_6071c0);
PCREG(4f3e00, f16_4f3e00);
PCREG(5ffb00, f16_5ffb00);
PCREG(57bd00, f16_57bd00);
PCREG(64c040, f16_64c040);
PCREG(651180, f16_651180);
