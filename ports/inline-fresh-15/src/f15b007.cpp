// f15b007.cpp - fresh slice 15, batch 7 (2026-10-12): functions with stack buffers/structs passed to callees.
// 0x578eb0: a = [0x70039c] slot 0x190(); a slot 0x198(a, buf, 0x6a9af0, +0x194) (cdecl, 4 words: a formatter);
//          flag = 0; db slot 0x134() slot 0x90(buf, &flag); returns flag (byte). 0x44-byte buffer, cookie check.
// 0x655270: if +0x137: for each key code in the 0-terminated table at 0x6f62a8 (0x10, 0x11, 0x12):
//          r = GetAsyncKeyState(k); key byte [0x70039c]+0xa0b+5k: bit 7 = r & 0x8000, bit 5 |= r & 1;
//          then SetCapture(+0x133), byte +0x1185 = 1.
// 0x5aca30 CMessageBasics::SetTextLen(s, n): memcpy(buf, s, n) into a 0x400 buffer; n >= 0x400 -> range-check failure
//          (not run: the exe overflows its own buffer first); buf[n] = 0; +0x6a ? ReformatText(buf) : ReformatTextNoSymbols(buf).
// 0x51b530 / 0x55f870 (ZFFHeroIf::buildCMM): if [0x701800] / [0x7140c8] == 0: local vector {0,0,0, owns=1};
//          reserve 0x59a9b0(&v, 0x32); this slot 0x1c(&v); vector dtor 0x4ff9d0(&v).
// 0x5ed030 CSprite2D::Init(a..e): CSprite3D::Init; then [+0x3e] times push a zeroed 16-byte new() block onto the vector
//          at +0xcb (end +0xcf, cap +0xd3; full -> _M_insert_aux 0x5fe3b0(end, &p)).
// 0x613870 ZTextureManagerGC::InstallTextureBuffer(tex, desc): s = tex slot 0x38(0); surface = desc+0x38: slot 0x40
//          (COM: surf, 0, &lock, 0, 0); fills a 0x30-byte descriptor (pitch/bits from the lock, size from s, RGBA masks
//          0xff0000/0xff00/0xff/0xff000000 from 0x6bd8a0, 32 bpp) -> tex slot 0x14(&d, 0); surf slot 0x44(surf, 0).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_633654[], ext_634d22[], ext_634047[], ext_5abf00[], ext_5ac140[], ext_59a9b0[], ext_4ff9d0[],
    ext_5ebe00[], ext_41e290[], ext_5fe3b0[];

static inline void *db() { return AT(void *, G(u8 *, 0x70039c), 0x9b); }
typedef void(FASTCALL *Cookie)(u32);

extern "C" u8 THISCALL f15_578eb0(u8 *self) {
  u32 ck = G(u32, 0x6f5630);
  char buf[0x44];
  u8 flag;
  void *a = vcall<void *>(G(void *, 0x70039c), 0x190);
  (*(void (**)(void *, char *, u32, u32))(*(u8 **)a + 0x198))(a, buf, 0x6a9af0u, AT(u32, self, 0x194));
  void *o = vcall<void *>(db(), 0x134);
  flag = 0;
  vcall<void>(o, 0x90, (void *)buf, (void *)&flag);
  u8 r = flag;
  ((Cookie)X(633654))(ck);
  return r;
}

typedef u16(STDCALL *KeyFn)(u32);
typedef u32(STDCALL *CapFn)(u32);
extern "C" void THISCALL f15_655270(u8 *self) {
  if (AT(u32, self, 0x137)) {
    for (u32 *p = (u32 *)0x6f62a8; *p; p++) {
      u32 k = *p;
      s32 r = (s16)(*(KeyFn *)0x6761a0)(k);
      u8 *b = G(u8 *, 0x70039c) + 0xa0b + k * 5;
      if (r & 0x8000) *b |= 0x80;
      else *b &= 0x7f;
      if (r & 1) *(G(u8 *, 0x70039c) + 0xa0b + k * 5) |= 0x20;
    }
  }
  (*(CapFn *)0x6761ec)(AT(u32, self, 0x133));
  AT(u8, self, 0x1185) = 1;
}

typedef void *(*Memcpy)(void *, const void *, u32);
extern "C" void THISCALL f15_5aca30(u8 *self, const char *s, u32 n) {
  u32 ck = G(u32, 0x6f5630);
  char buf[0x400];
  ((Memcpy)X(634d22))(buf, s, n);
  if (n >= 0x400) ((void (*)())X(634047))();
  buf[n] = 0;
  if (AT(u32, self, 0x6a)) ((void(THISCALL *)(void *, char *))X(5abf00))(self, buf);
  else ((void(THISCALL *)(void *, char *))X(5ac140))(self, buf);
  ((Cookie)X(633654))(ck);
}

struct LocalVec { u32 a, b, c; u8 own; };
static inline void cmm(void *self) {
  LocalVec v;
  v.a = 0; v.b = 0; v.c = 0;
  v.own = 1;
  ((void(THISCALL *)(void *, u32))X(59a9b0))(&v, 0x32);
  vcall<void>(self, 0x1c, (void *)&v);
  ((void(THISCALL *)(void *))X(4ff9d0))(&v);
}
extern "C" void THISCALL f15_51b530(void *self) { if (G(u32, 0x701800) == 0) cmm(self); }
extern "C" void THISCALL f15_55f870(void *self) { if (G(u32, 0x7140c8) == 0) cmm(self); }

extern "C" void THISCALL f15_5ed030(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  ((void(THISCALL *)(void *, u32, u32, u32, u32, u32))X(5ebe00))(self, a, b, c, d, e);
  for (u32 i = 0; i < AT(u32, self, 0x3e); i++) {
    u32 *p = ((u32 * (*)(u32)) X(41e290))(0x10);
    p[1] = 0; p[2] = 0; p[3] = 0; p[0] = 0;
    u32 **end = AT(u32 **, self, 0xcf);
    if (end != AT(u32 **, self, 0xd3)) {
      if (end) *end = p;
      AT(u32, self, 0xcf) += 4;
    } else {
      ((void(THISCALL *)(void *, u32 **, u32 **))X(5fe3b0))(self + 0xcb, end, &p);
    }
  }
}

extern "C" void THISCALL f15_613870(void *self, void *tex, u8 *desc) {
  u32 *s = vcall<u32 *>(tex, 0x38, 0u);
  void *surf = AT(void *, desc, 0x38);
  u32 lk[2];
  (*(void(STDCALL **)(void *, u32, u32 *, u32, u32))(*(u8 **)surf + 0x40))(surf, 0, lk, 0, 0);
  u8 d[0x30];
  AT(u32, d, 0x2c) = lk[1];
  AT(u32, d, 0x10) = lk[0];
  AT(u32, d, 0) = 0;
  AT(u32, d, 4) = 0;
  AT(u32, d, 8) = s[1];
  AT(u32, d, 0xc) = s[2];
  AT(u32, d, 0x24) = 0x20;
  AT(u32, d, 0x14) = 0xff0000u;
  AT(u32, d, 0x18) = 0xff00u;
  AT(u32, d, 0x1c) = 0xffu;
  AT(u32, d, 0x20) = 0xff000000u;
  AT(u8, d, 0x28) = 0;
  vcall<void>(tex, 0x14, (void *)d, 0u);
  (*(void(STDCALL **)(void *, u32))(*(u8 **)surf + 0x44))(surf, 0);
}

PCREG(578eb0, f15_578eb0);
PCREG(655270, f15_655270);
PCREG(5aca30, f15_5aca30);
PCREG(51b530, f15_51b530);
PCREG(55f870, f15_55f870);
PCREG(5ed030, f15_5ed030);
PCREG(613870, f15_613870);
