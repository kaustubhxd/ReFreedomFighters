// batch849.cpp - gap band UTF-16 token readers (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_62c640(u32 hi, u32 lo);                           // real callee: unit classifier
extern "C" u32 __attribute__((cdecl)) ext_6279e0(const u8 *cvt, const u8 *p, const u8 *end, u32 **out);   // hooked (GUESS)
extern "C" u32 __attribute__((cdecl)) ext_629a40(const u8 *cvt, const u8 *p, const u8 *end, u32 **out);   // hooked (GUESS)

// Shared body of the two readers: classifies the unit at p (high byte 0 uses cvt[0x4c + low], 'x' as the low byte of a zero high byte
// forwards to the number reader, other units use 0x62c640(high, low)); class 0x19 units are skipped; stops with *out = the stopping
// position and 0, or *out = just past a class 0x12 unit and 10, or -1 on reaching end.
template <bool BE, u32 (*NUM)(const u8 *, const u8 *, const u8 *, u32 **)>
static u32 readToken(const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  if (p == end) return 0xffffffffu;
  u32 hi = BE ? p[0] : p[1], lo = BE ? p[1] : p[0];
  u32 cls;
  if (hi == 0) {
    if (lo == 0x78) return NUM(cvt, p + 2, end, (u32 **)out);
    cls = cvt[0x4c + lo];
  } else {
    cls = ext_62c640(hi, lo);
  }
  if (cls != 0x19) {
    *out = p;
    return 0;
  }
  p += 2;
  for (;;) {
    if (p == end) return 0xffffffffu;
    hi = BE ? p[0] : p[1];
    lo = BE ? p[1] : p[0];
    cls = hi == 0 ? cvt[0x4c + lo] : ext_62c640(hi, lo);
    if (cls == 0x12) {
      *out = p + 2;
      return 10;
    }
    if (cls != 0x19) {
      *out = p;
      return 0;
    }
    p += 2;
    if (p == end) return 0xffffffffu;
  }
}

// 0x627470: cdecl(cvt, p, end, out) - readToken, big-endian
static u32 __attribute__((cdecl)) readTokenBE_627470(const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  return readToken<true, ext_6279e0>(cvt, p, end, out);
}
PCREG(627470, readTokenBE_627470);

// 0x6294d0: cdecl(cvt, p, end, out) - readToken, little-endian
static u32 __attribute__((cdecl)) readTokenLE_6294d0(const u8 *cvt, const u8 *p, const u8 *end, const u8 **out) {
  return readToken<false, ext_629a40>(cvt, p, end, out);
}
PCREG(6294d0, readTokenLE_6294d0);
