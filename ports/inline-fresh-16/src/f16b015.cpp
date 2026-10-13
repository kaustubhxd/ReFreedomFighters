// f16b015.cpp - fresh slice 16, batch 15 (2026-10-12).
// 0x490bc0 ZEngineDataBase::GetRoomInsideTreeData(buf, size): MYSTR tmp = CalcCacheFileName 0x48c4b0(this; &tmp, 0x68d834);
//           r = [0x700394] slot 0x60(c_str 0x4cc1d0(&tmp), buf, size, 0, 0); ~MYSTR(&tmp). Void (EAX is left from ~MYSTR). Ret 8. SEH/cookie not
//           reproduced.
// 0x42f780 ZSysInterface::ReadVarToken(str, p&, end) (stdcall): str.assign("", "") 0x5f2d60 (ret 8); while *p != end and
//           **p is [A-Za-z0-9_]: append it (full -> grow 0x431270(size + max(size, 1)), ret 4; then two zero bytes at end+1,
//           the char at end, end++), (*p)++. Ret 0xc.
// 0x4555c0 / 0x45b740 (fastcall a, b; c, d): alloc-and-construct of the 0x448000 shape (batch 14): tag 0x827 with ctor
//           0x455200, tag 0x6480 with ctor 0x45b2f0. SEH not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_48c4b0[], ext_4cc1d0[], ext_4cbec0[], ext_5f2d60[], ext_431270[], ext_45c4f0[], ext_45c4b0[],
    ext_455200[], ext_45b2f0[];

struct MYSTRbuf15 {
  u8 b[0x80];
};

extern "C" void THISCALL f16_490bc0(void *self, u32 buf, u32 size) {
  volatile MYSTRbuf15 tmp;
  ((void(THISCALL *)(void *, volatile void *, u32))(void *)ext_48c4b0)(self, &tmp, 0x68d834u);
  u32 s = ((u32(THISCALL *)(volatile void *))(void *)ext_4cc1d0)(&tmp);
  vcall<void>(G(void *, 0x700394), 0x60, s, buf, size, 0u, 0u);
  ((void(THISCALL *)(volatile void *))(void *)ext_4cbec0)(&tmp);
}

extern "C" void STDCALL f16_42f780(u8 **str, u8 **pp, u8 *end) {
  ((void(THISCALL *)(void *, u32, u32))(void *)ext_5f2d60)(str, 0x677b5au, 0x677b5au);
  while (*pp != end) {
    u8 c = **pp;
    if (!((u8)(c - 'a') <= 25 || (u8)(c - 'A') <= 25 || (u8)(c - '0') <= 9 || c == '_')) break;
    u8 *e = str[1];
    if (e + 1 == str[2]) {
      u32 size = (u32)(e - str[0]);
      u32 n = (size < 1 ? 1u : size) + size;
      ((void(THISCALL *)(void *, u32))(void *)ext_431270)(str, n);
    }
    u8 *z = str[1] + 1;
    if (z) *z = 0;
    *z = 0;
    *str[1] = c;
    str[1]++;
    (*pp)++;
  }
}

static inline u32 alloc_construct(u32 tag, char *ctor, u32 a, u32 b, u32 c, u32 d) {
  void *p = d ? ((void *(*)(u32, u32))(void *)ext_45c4f0)(tag, d) : ((void *(*)(u32))(void *)ext_45c4b0)(tag);
  if (!p) return 0;
  return ((u32(THISCALL *)(void *, u32, u32, u32))(void *)ctor)(p, c, a, b);
}

extern "C" u32 FASTCALL f16_4555c0(u32 a, u32 b, u32 c, u32 d) { return alloc_construct(0x827, ext_455200, a, b, c, d); }
extern "C" u32 FASTCALL f16_45b740(u32 a, u32 b, u32 c, u32 d) { return alloc_construct(0x6480, ext_45b2f0, a, b, c, d); }

PCREG(490bc0, f16_490bc0);
PCREG(42f780, f16_42f780);
PCREG(4555c0, f16_4555c0);
PCREG(45b740, f16_45b740);
