// f16b013.cpp - fresh slice 16, batch 13 (2026-10-12).
// 0x491340 ZEngineDataBase::GetTreesSize: MYSTR tmp = CalcCacheFileName 0x48c4b0(this; &tmp, 0x68d838) (ret 8); r =
//           [0x700394] slot 0x30(MYSTR c_str 0x4cc1d0(&tmp), 0) (the pushed 0 is slot 0x30's second argument); ~MYSTR
//           0x4cbec0(&tmp); returns r. SEH and stack cookie not reproduced.
// 0x42fa00 ZSysInterface::SaveGamePath(out): MYSTR tmp(0x679a2c) 0x4cbe80; MYSTR::operator+ 0x4cc1e0(this+0x123; out, &tmp)
//           (ret 8); ~MYSTR(&tmp); returns out. Ret 4. SEH and cookie not reproduced.
// 0x5fa740 constructor: 0x5fa7e0(this); 0x5faad0(this+0x3c); s = this+0x172 = {0, 0, 0}; p = CHostInterface::alloc
//           0x6014a0(s; 8) (ret 4); s = {p, p, p+8}; byte [p] = 0 (twice; the second behind a null test). Returns this.
//           SEH not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_48c4b0[], ext_4cc1d0[], ext_4cbec0[], ext_4cbe80[], ext_4cc1e0[], ext_5fa7e0[], ext_5faad0[], ext_6014a0[];

struct MYSTRbuf {
  u8 b[0x80];
};

extern "C" u32 THISCALL f16_491340(void *self) {
  volatile MYSTRbuf tmp;
  ((void(THISCALL *)(void *, volatile void *, u32))(void *)ext_48c4b0)(self, &tmp, 0x68d838u);
  u32 s = ((u32(THISCALL *)(volatile void *))(void *)ext_4cc1d0)(&tmp);
  u32 r = vcall<u32>(G(void *, 0x700394), 0x30, s, 0u);
  ((void(THISCALL *)(volatile void *))(void *)ext_4cbec0)(&tmp);
  return r;
}

extern "C" void *THISCALL f16_42fa00(u8 *self, void *out) {
  volatile MYSTRbuf tmp;
  ((void(THISCALL *)(volatile void *, u32))(void *)ext_4cbe80)(&tmp, 0x679a2cu);
  ((void(THISCALL *)(void *, void *, volatile void *))(void *)ext_4cc1e0)(self + 0x123, out, &tmp);
  ((void(THISCALL *)(volatile void *))(void *)ext_4cbec0)(&tmp);
  return out;
}

extern "C" void *THISCALL f16_5fa740(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_5fa7e0)(self);
  ((void(THISCALL *)(void *))(void *)ext_5faad0)(self + 0x3c);
  u32 *s = (u32 *)(self + 0x172);
  s[0] = 0;
  s[1] = 0;
  s[2] = 0;
  u8 *p = ((u8 * (THISCALL *)(void *, u32))(void *)ext_6014a0)(s, 8);
  s[0] = (u32)p;
  s[1] = (u32)p;
  s[2] = (u32)(p + 8);
  *p = 0;
  if (p) *p = 0;
  return self;
}

PCREG(491340, f16_491340);
PCREG(42fa00, f16_42fa00);
PCREG(5fa740, f16_5fa740);
