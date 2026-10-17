#include "ff.h"

extern "C" void THISCALL ext_52db40(void *s1);
extern "C" u32 THISCALL ext_52e320(void *s2, void *mv);
extern "C" u32 THISCALL ext_531070(void *s2, void *mv);
extern "C" void FASTCALL ext_633654(u32 cookie);

// Transliteration of 0x52dbb0 on a copy of the original frame (ebp = fr + 0xe8): the real helpers 0x52db40 / 0x52e320 / 0x531070 read and write the stack structs
// (S1 at ebp-0xac, S2 at ebp-0x3c), so the locals keep their original offsets. Packed 16-bit pair arithmetic is done on the same words as the original.
#define EBP (fr + 0xe8)
#define P(off) (EBP - (off))
static inline u16 R16(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W16(u8 *p, u16 v) { __builtin_memcpy(p, &v, 2); }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

// 0x52dbb0: thiscall(a, b, unused) ret 0xc -> bool (al), /GS: walks the integer line from the cell a (words at +0 / +4 / +6 / +8) towards b, stepping the cell by +-1 along the
// dominant axis of the 2D cross products, asking 0x52e320 / 0x531070 (struct at ebp-0x3c, move vector at ebp-0xc) whether each step is open, trying z-1 / z+1 variants; true when
// b is reached (x, y equal and |z - b.z| in -2..5), false when blocked, the z drift test leaves -2..5, or after 1000 steps.
static bool body_52dbb0(u8 *self, u8 *a, u8 *b) {
  u8 fr[0x100];
  __builtin_memset(fr, 0xcc, sizeof fr);  // uninitialised stack bytes of the original read 0xcc in the emulator; they are struct padding (S1+0x1e) copied into S2
  float one = *(float *)0x678858;
  s32 dz = (s16)(u16)(R16(b + 8) - R16(a + 8));
  s32 dy = (s16)(u16)(R16(b + 6) - R16(a + 6));
  s32 dxo = (s16)(u16)(R16(b + 4) - R16(a + 4));
  W32(P(0x5c), (u32)dz);
  W32(P(0x58), (u32)dy);
  W32(P(0x54), (u32)dxo);
  s32 sumsq = dxo * dxo + dy * dy + dz * dz;
  W16(P(0x6c), (u16)(dxo > 0 ? 1 : -1));
  float inv = one / (float)sumsq;
  W16(P(0x6a), (u16)(dy > 0 ? 1 : -1));
  u16 ax = R16(a + 4), ay = R16(a + 6), az = R16(a + 8);
  W16(P(0x40), ax);
  W16(P(0x4c), ax);
  W16(P(0x42), ay);
  W16(P(0x4a), ay);
  W16(P(0x44), az);
  W16(P(0x48), az);
  WF(P(0x74), inv);
  if (self) {
    W32(P(0xac), (u32)self);
    W32(P(0xa8), (u32)self + 0x96);
    W32(P(0xa4), 0x40);
  }
  u32 e38 = R32(self + 0x38);
  u16 a0 = R16(a);
  u16 di = R16(P(0x44));
  W16(P(0x94), ax);
  W16(P(0x92), ay);
  W16(P(0x90), di);
  W16(P(0xa0), ax);
  W16(P(0x9e), ay);
  W16(P(0x9c), di);
  W16(P(0x96), a0);
  W32(P(0x9a), e38);
  *P(0x8d) = (u8)e38;
  if (a0 == 0) return false;
  ext_52db40(P(0xac));
  *P(0x3d) = *P(0x80);
  u8 X4[16], X3[16], X2[8];
  __builtin_memcpy(X4, P(0xac), 16);
  u32 d84 = R32(P(0x84));
  __builtin_memcpy(X2, P(0x8c), 8);
  W32(P(0x64), 0);
  __builtin_memcpy(X3, P(0x9c), 16);
  W32(P(0x50), d84);
  __builtin_memcpy(P(0x7c), X2, 8);
  __builtin_memcpy(P(0xdc), X3, 16);
  __builtin_memcpy(P(0xcc), X4, 16);
  for (;;) {
    u32 esi = R32(P(0x6c));
    u32 edi = R32(P(0x4c));
    esi += edi;
    u16 cx16 = (u16)(R16(P(0x42)) - R16(a + 6));
    u32 edx = R32(P(0x4a)) + R32(P(0x6a));
    W16(P(0xb4), (u16)esi);
    u16 si16 = (u16)((u16)esi - R16(a + 4));
    u16 ax16 = (u16)(R16(P(0x40)) - R16(b + 4));
    s32 eax = (s32)(s16)ax16;
    eax *= (s32)R32(P(0x58));
    W16(P(0xba), (u16)edx);
    u16 dx16 = (u16)((u16)edx - R16(b + 6));
    s32 ecx = (s32)(s16)cx16;
    W32(P(0x60), (u32)ecx);
    ecx = (s32)(s16)dx16;
    ecx *= (s32)R32(P(0x54));
    s32 ebx = (s32)(s16)si16;
    W32(P(0x70), (u32)ebx);
    eax -= ecx;
    ecx = (s32)R32(P(0x60));
    ecx *= (s32)R32(P(0x54));
    s32 sgn = eax >> 31;
    s32 esi1 = (eax ^ sgn) - sgn;
    eax = ebx;
    eax *= (s32)R32(P(0x58));
    eax -= ecx;
    sgn = eax >> 31;
    eax = (eax ^ sgn) - sgn;
    u32 sx, sy;
    if (eax < esi1) {
      sx = R32(P(0xb4)) - edi;
      sy = 0;
    } else {
      sy = R32(P(0xba)) - R32(P(0x4a));
      sx = 0;
    }
    u16 mvx = (u16)sx, mvy = (u16)sy;
    W32(P(0x14), R32(P(0x50)));
    bool is3 = *P(0x8c) == 3;
    *P(0x10) = *P(0x3d);
    W16(P(0xa), mvy);
    W16(P(0xc), mvx);
    W16(P(8), 0);
    __builtin_memcpy(P(0x3c), X4, 16);
    __builtin_memcpy(P(0x2c), X3, 16);
    __builtin_memcpy(P(0x1c), X2, 8);
    u16 r = (u16)(is3 ? ext_52e320(P(0x3c), P(0xc)) : ext_531070(P(0x3c), P(0xc)));
    s16 dzv = 0;
    bool ok = r != 0;
    if (!ok) {
      is3 = *P(0x8c) == 3;
      W32(P(0x14), R32(P(0x50)));
      *P(0x10) = *P(0x3d);
      __builtin_memcpy(P(0x3c), P(0xcc), 16);
      W16(P(8), 1);
      __builtin_memcpy(P(0x2c), P(0xdc), 16);
      __builtin_memcpy(P(0x1c), P(0x7c), 8);
      r = (u16)(is3 ? ext_52e320(P(0x3c), P(0xc)) : ext_531070(P(0x3c), P(0xc)));
      ok = r != 0;
      dzv = 1;
    }
    if (!ok) {
      is3 = *P(0x8c) == 3;
      __builtin_memcpy(P(0x3c), P(0xcc), 16);
      W32(P(0x14), R32(P(0x50)));
      __builtin_memcpy(P(0x2c), P(0xdc), 16);
      *P(0x10) = *P(0x3d);
      W16(P(8), 0xffff);
      __builtin_memcpy(P(0x1c), P(0x7c), 8);
      r = (u16)(is3 ? ext_52e320(P(0x3c), P(0xc)) : ext_531070(P(0x3c), P(0xc)));
      if (r == 0) return false;
      dzv = -1;
    }
    // success of a step
    u32 d14 = R32(P(0x14));
    u16 dxn = (u16)(R16(P(0x40)) + mvx);
    u16 syn = (u16)(R16(P(0x42)) + mvy);
    W32(P(0x50), d14);
    u8 b10 = *P(0x10);
    s32 e1 = (s32)R32(P(0x60)) * (s32)R32(P(0x58));
    *P(0x3d) = b10;
    s32 e2 = (s32)R32(P(0x70)) * (s32)R32(P(0x54));
    u16 czn = (u16)(R16(P(0x44)) + (u16)dzv);
    float x0 = (float)(s32)R32(P(0x5c));
    W16(P(0x40), dxn);
    W16(P(0x44), czn);
    s32 e3 = e2 + e1;
    W16(P(0x48), czn);
    s32 ecx2 = (s32)(u32)czn;
    __builtin_memcpy(X2, P(0x1c), 8);
    __builtin_memcpy(X4, P(0x3c), 16);
    W16(P(0x4c), dxn);
    float x1 = (float)e3;
    W16(P(0x42), syn);
    W16(P(0x4a), syn);
    s32 azv = (s32)(u32)R16(a + 8);
    __builtin_memcpy(X3, P(0x2c), 16);
    x1 = x1 * RF(P(0x74));
    __builtin_memcpy(P(0xcc), X4, 16);
    x1 = x1 * x0;
    float x2f = (float)azv;
    __builtin_memcpy(P(0xdc), X3, 16);
    x1 = x1 + x2f;
    __builtin_memcpy(P(0x7c), X2, 8);
    __builtin_memcpy(P(0x8c), X2, 8);
    s32 dzr = (s32)x1 - ecx2;
    if (dzr > 5) return false;
    if (dzr < -2) return false;
    if (dxn == R16(b + 4) && syn == R16(b + 6)) {
      s32 rem = ecx2 - (s32)(u32)R16(b + 8);
      if (rem <= 5 && rem >= -2) return true;
    }
    u32 n = R32(P(0x64)) + 1;
    W32(P(0x64), n);
    if ((s32)n >= 0x3e8) return false;
  }
}
extern "C" u32 THISCALL fn_52dbb0(u8 *self, u8 *a, u8 *b, u32 unused);
extern "C" u32 THISCALL fn_52dbb0(u8 *self, u8 *a, u8 *b, u32 unused) {
  bool r = body_52dbb0(self, a, b);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(52dbb0, fn_52dbb0);
