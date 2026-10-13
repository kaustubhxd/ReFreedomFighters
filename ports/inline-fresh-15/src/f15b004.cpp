// f15b004.cpp - fresh slice 15, batch 4 (2026-10-12). 0x42333d (Catch funclet) is listed apart, not ported.
// 0x4d1bb0(p): n = this slot 0x2c(); for i < n: x = this slot 0x40(i); y = this slot 0x3c(i); p slot 0x1c(y, x)
//          (x is pushed before slot 0x3c's argument and becomes p's second argument: one shared stack word).
// 0x4d3ff0: deleting dtor, vtable 0x6965c0: delete([+0xc], 1) if set, delete([+4], 4), flags&1 -> delete(this, 0x14).
// 0x63db70(a): first non-zero 0x64b430([+0xf0 + 4i], a) over [+0xec] entries, else 0.
// 0x5721f0 CSoundMenu::OnWindowOpen(a, b): ZVideoSelector::OnWindowOpen; o = this slot 0x84();
//          o slot 0x34c(0x10000, 0, [this+0x44], 10.0f, 0) (callee pops 20); returns false.
// 0x4d0f30 (ZMallocSimple init)(base, size, n): +0 = base, +4 = n, +8 = +0xc = +0x88 = 0; AddFreeBlock(base + 8n, size - 8n, 0).
// 0x57cfb0: if byte [0x70039c]+0x6c == 0: L = this+0x23c; for i < L slot 0x14() (signed, re-read): [0x70038c] slot 0xcc(L slot 0x30(i)).
// 0x648430 ZDrawArray<ZPrimInstViewEntry>::Add: skip full blocks (word +2 == 0xffff) along +8 links; else grow (0x648d50);
//          count +0xc and tail call 0x6486e0(block).
// 0x5fb270 (span less-than, stdcall a, b): _strnicmp(a.begin, b.begin, min len); r ? r < 0 : len a < len b.
// 0x636230: ctor, vtable 0x6c2194, +4 = 'DXT1' (0x44585431), +8..+0x1c = 0, byte +0x28 = 0, +0x29 = 0.
// 0x572fb0 CZoneMenu::Command(id, p): db slot 0x114(0x6a7b48, 0, 0x6a8bc4, 0x78) (RegisterZMsg, pops 16);
//          (u16)id == (u16)r -> byte +0x180 = 1, return 1; else CFileWindow::Command(id, p).
// 0x5fb8b0 (span compare with C string): r = _strnicmp(begin, s, min); r ? r : (len < n ? -1 : len > n).
// 0x481930 ZPlayerTest::CheckLineColi(out, a, b): d = vadd 0x43e8e0(a, b) (fastcall); a[1] >= 0 && d[1] < 0 ->
//          out = 0, return true; else false.
// 0x5492f0: ctor over 0x54cb80, vtable 0x6a3338, several fields.
// 0x63e7f0 ZDrawBase::GeomDrawEntryUpdate(e): flag bits at byte e+5 (0x20 active, 0x40 slot 0xf0 on [g+0x54]);
//          [e] == [0x70039c]+0x3c && WantCameraMsg(g) && [g+0x54] -> SendCommand slot 0x130(h, 0x401, 0).
// 0x427f70 ZSysFileGC::RemoveSaveGame(n): for i = 1..3: this slot 0x144(buf, n, i); this slot 0x5c(buf); cookie check.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_634273[], ext_64b430[], ext_563110[], ext_4d0fc0[], ext_648d50[], ext_6486e0[], ext_561cb0[],
    ext_43e8e0[], ext_54cb80[], ext_4dd8d0[], ext_633654[];

extern "C" void THISCALL f15_4d1bb0(void *self, void *p) {
  u32 n = vcall<u32>(self, 0x2c);
  if (!n) return;
  u32 i = 0;
  do {
    u32 x = vcall<u32>(self, 0x40, i);
    u32 y = vcall<u32>(self, 0x3c, i);
    vcall<void>(p, 0x1c, y, x);
    i++;
  } while (i != n);
}

typedef void (*Del)(void *, u32);
extern "C" void *THISCALL f15_4d3ff0(void *self, u32 flags) {
  AT(u32, self, 0) = 0x6965c0u;
  if (AT(void *, self, 0xc)) ((Del)X(634273))(AT(void *, self, 0xc), 1);
  ((Del)X(634273))(AT(void *, self, 4), 4);
  if (flags & 1) ((Del)X(634273))(self, 0x14);
  return self;
}

extern "C" u32 THISCALL f15_63db70(void *self, u32 a) {
  for (u32 i = 0; i != AT(u32, self, 0xec); i++) {
    u32 r = ((u32(THISCALL *)(void *, u32))X(64b430))(AT(void *, self, 0xf0 + 4 * i), a);
    if (r) return r;
  }
  return 0;
}

extern "C" u8 THISCALL f15_5721f0(void *self, u32 a, u32 b) {
  ((void(THISCALL *)(void *, u32, u32))X(563110))(self, a, b);
  void *o = vcall<void *>(self, 0x84);
  vcall<void>(o, 0x34c, 0x10000u, 0u, AT(u32, self, 0x44), 0x41200000u, 0u);
  return 0;
}

extern "C" void *THISCALL f15_4d0f30(void *self, u8 *base, u32 size, u32 n) {
  AT(u32, self, 4) = n;
  AT(u8 *, self, 0) = base;
  AT(u32, self, 8) = 0;
  AT(u32, self, 0xc) = 0;
  AT(u32, self, 0x88) = 0;
  ((void(THISCALL *)(void *, u8 *, u32, u32))X(4d0fc0))(self, base + n * 8, size - n * 8, 0);
  return self;
}

extern "C" void THISCALL f15_57cfb0(void *self) {
  if (AT(u8, G(u8 *, 0x70039c), 0x6c)) return;
  void *L = (u8 *)self + 0x23c;
  for (s32 i = 0; i < vcall<s32>(L, 0x14); i++) {
    u32 x = vcall<u32>(L, 0x30, (u32)i);
    vcall<void>(G(void *, 0x70038c), 0xcc, x);
  }
}

typedef u32(THISCALL *Get0)(void *);
extern "C" u32 THISCALL f15_648430(void *self) {
  u8 *c = AT(u8 *, self, 8);
  if (c) {
    do {
      u8 *e = AT(u8 *, self, 8);
      if (*(u16 *)(e + 2) != 0xffff) {
        AT(u32, self, 0xc)++;
        return ((Get0)X(6486e0))(e);
      }
      e = AT(u8 *, e, 8);
      AT(u8 *, self, 8) = e;
      if (c == e || !e) break;
    } while (1);
  }
  if (!(u8)((Get0)X(648d50))(self)) return 0;
  AT(u32, self, 0xc)++;
  return ((Get0)X(6486e0))(AT(void *, self, 8));
}

typedef s32 (*Strnicmp)(const void *, const void *, u32);
extern "C" u32 STDCALL f15_5fb270(u32 *a, u32 *b) {
  s32 lb = (s32)(b[1] - b[0]), la = (s32)(a[1] - a[0]);
  s32 m = lb < la ? lb : la;
  s32 r = (*(Strnicmp *)0x676408)((void *)a[0], (void *)b[0], (u32)m);
  if (r) return (u32)r >> 31;
  if (la < lb) return 1;
  return 0;
}

extern "C" void *THISCALL f15_636230(void *self) {
  AT(u32, self, 0x1c) = 0;
  AT(u32, self, 4) = 0x44585431u;
  AT(u32, self, 8) = 0;
  AT(u32, self, 0xc) = 0;
  AT(u32, self, 0x10) = 0;
  AT(u32, self, 0x14) = 0;
  AT(u32, self, 0x18) = 0;
  AT(u8, self, 0x28) = 0;
  AT(u32, self, 0x29) = 0;
  AT(u32, self, 0) = 0x6c2194u;
  return self;
}

extern "C" u32 THISCALL f15_572fb0(void *self, u32 id, u32 p) {
  void *db = AT(void *, G(u8 *, 0x70039c), 0x9b);
  u32 r = vcall<u32>(db, 0x114, 0x6a7b48u, 0u, 0x6a8bc4u, 0x78u);
  if ((u16)id == (u16)r) {
    AT(u8, self, 0x180) = 1;
    return 1;
  }
  return ((u32(THISCALL *)(void *, u32, u32))X(561cb0))(self, id, p);
}

extern "C" s32 THISCALL f15_5fb8b0(u32 *self, const char *s) {
  const char *e = s;
  while (*e) e++;
  s32 n = (s32)(e - s);
  s32 len = (s32)(self[1] - self[0]);
  s32 m = n < len ? n : len;
  s32 r = (*(Strnicmp *)0x676408)((void *)self[0], s, (u32)m);
  if (r) return r;
  if (len < n) return -1;
  return len > n;
}

extern "C" u8 THISCALL f15_481930(void *self, float *out, const float *a, const float *b) {
  float d[3];
  ((void(FASTCALL *)(float *, const float *, const float *))X(43e8e0))(d, a, b);
  if (a[1] >= 0.0f && 0.0f > d[1]) {
    out[0] = 0; out[1] = 0; out[2] = 0;
    return 1;
  }
  return 0;
}

extern "C" void *THISCALL f15_5492f0(void *self) {
  ((void(THISCALL *)(void *))X(54cb80))(self);
  AT(u32, self, 0) = 0x6a3338u;
  AT(u32, self, 0x8055) = 8;
  AT(u8, self, 0xa26d) = 0;
  AT(u32, self, 0x8061) = 0;
  AT(u32, self, 0xa269) = 0;
  AT(u32, self, 0x801d) = 0x701b70u;
  AT(u8, self, 0xa272) = 0;
  return self;
}

extern "C" void THISCALL f15_63e7f0(void *self, void *e) {
  u8 b = AT(u8, e, 5);
  if (!(b & 0x20)) return;
  void *g = AT(void *, e, 0x38);
  void *h = AT(void *, g, 0x54);
  if (b & 0x40) vcall<void>(h, 0xf0);
  if (AT(u32, e, 0) != AT(u32, G(u8 *, 0x70039c), 0x3c)) return;
  if (!(u8)((Get0)X(4dd8d0))(g)) return;
  void *o = AT(void *, g, 0x54);
  if (o) vcall<void>(o, 0x130, h, 0x401u, 0u);
}

extern "C" void THISCALL f15_427f70(void *self, u32 n) {
  u32 ck = G(u32, 0x6f5630);
  char buf[0x400];
  for (u32 i = 1; i < 4; i++) {
    vcall<void>(self, 0x144, buf, n, i);
    vcall<void>(self, 0x5c, buf);
  }
  ((void(FASTCALL *)(u32))X(633654))(ck);
}

PCREG(4d1bb0, f15_4d1bb0);
PCREG(4d3ff0, f15_4d3ff0);
PCREG(63db70, f15_63db70);
PCREG(5721f0, f15_5721f0);
PCREG(4d0f30, f15_4d0f30);
PCREG(57cfb0, f15_57cfb0);
PCREG(648430, f15_648430);
PCREG(5fb270, f15_5fb270);
PCREG(636230, f15_636230);
PCREG(572fb0, f15_572fb0);
PCREG(5fb8b0, f15_5fb8b0);
PCREG(481930, f15_481930);
PCREG(5492f0, f15_5492f0);
PCREG(63e7f0, f15_63e7f0);
PCREG(427f70, f15_427f70);
