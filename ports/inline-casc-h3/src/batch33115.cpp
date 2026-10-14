// batch33115.cpp - h3 () batch 33115: tier H float/SSE functions
#include "ff.h"

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_579bd0(u8 *self, u32 f);                    // ret 4
extern "C" void THISCALL ext_579b20(u8 *self, u32 f);                    // ret 4
extern "C" void THISCALL ext_579a60(u8 *self, u32 f);                    // ret 4
extern "C" void THISCALL ext_579d20(u8 *self);                           // plain ret
extern "C" void THISCALL ext_524810(u8 *self, u8 *s);                    // ret 4
extern "C" void THISCALL ext_524460(u8 *self, u8 *s);                    // ret 4
extern "C" u32 THISCALL ext_461250(u8 *self, u8 *a, u32 b, u32 f1, u32 f2, u32 f3);   // ret 0x14

// 0x578aa0: thiscall no args: for each of [0x1a8] / [0x1ac] / [0x1b0] != -1.0: saved=[0x194]; [0x194]=0; helper(this, (int)f != 0); field=-1.0; [0x194]=saved; 0x579d20(this) (helpers 0x579bd0, 0x579b20, 0x579a60; the last one tail-calls 0x579d20)
static void THISCALL fn578aa0(u8 *self) {
  float f = bitsf(R32(self + 0x1a8));
  if (!(f == -1.0f)) {
    u32 saved = R32(self + 0x194);
    s32 k = _mm_cvttss_si32(_mm_set_ss(f));
    W32(self + 0x194, 0);
    ext_579bd0(self, k != 0);
    W32(self + 0x1a8, 0xbf800000);
    W32(self + 0x194, saved);
    ext_579d20(self);
  }
  f = bitsf(R32(self + 0x1ac));
  if (!(f == -1.0f)) {
    u32 saved = R32(self + 0x194);
    s32 k = _mm_cvttss_si32(_mm_set_ss(f));
    W32(self + 0x194, 0);
    ext_579b20(self, k != 0);
    W32(self + 0x1ac, 0xbf800000);
    W32(self + 0x194, saved);
    ext_579d20(self);
  }
  f = bitsf(R32(self + 0x1b0));
  if (!(f == -1.0f)) {
    u32 saved = R32(self + 0x194);
    s32 k = _mm_cvttss_si32(_mm_set_ss(f));
    ext_579a60(self, k != 0);
    W32(self + 0x194, saved);
    W32(self + 0x1b0, 0xbf800000);
    ext_579d20(self);
  }
}
PCREG(578aa0, fn578aa0);

// 0x516520: thiscall(s) ret 4, returns true: s->slot 0x68(this); slot 0x4c([+0xc]); slot 0x60(byte [+0x10]); slot 0x4c([+0x11], [+0x15], [+0x19], [+0x1d]); 0x524810(this+0x21, s); 0x524460(this+0x41, s); 0x524460(this+0x55, s); s->slot 0x10(this+0x69, 0x6d)
static u8 THISCALL fn516520(u8 *self, u8 *s) {
  vcall<u32>(s, 0x68, (u32)self);
  vcall<u32>(s, 0x4c, R32(self + 0xc));
  vcall<u32>(s, 0x60, (u32)self[0x10]);
  vcall<u32>(s, 0x4c, R32(self + 0x11));
  vcall<u32>(s, 0x4c, R32(self + 0x15));
  vcall<u32>(s, 0x4c, R32(self + 0x19));
  vcall<u32>(s, 0x4c, R32(self + 0x1d));
  ext_524810(self + 0x21, s);
  ext_524460(self + 0x41, s);
  ext_524460(self + 0x55, s);
  vcall<u32>(s, 0x10, (u32)(self + 0x69), 0x6du);
  return 1;
}
PCREG(516520, fn516520);

// 0x477670: thiscall(a, b, f1, f2, f3) ret 0x14: a == 0 -> 0; byte [0x726] && a[0x7c] & 0x40: [0x64c]==10 -> 0; (b & 4 or |a[0x70..]|^2 > 1/8192): slot 0x628(2,1,0); [0x726]=0; slot 0x62c(slot 0x588() != 0); then 0x461250(this, a, b, f1, f2, f3)
static u32 THISCALL fn477670(u8 *self, u8 *a, u32 b, u32 f1, u32 f2, u32 f3) {
  if (!a) return 0;
  if (self[0x726] != 0 && (R32(a + 0x7c) & 0x40) != 0) {
    if (R32(self + 0x64c) == 10) return 0;
    bool run = (b & 4) != 0;
    if (!run) {
      float x = bitsf(R32(a + 0x70)), y = bitsf(R32(a + 0x74)), z = bitsf(R32(a + 0x78));
      float s = x * x;
      float yy = y * y;
      float zz = z * z;
      s = s + yy;
      s = s + zz;
      run = s > 0.0001220703125f;
    }
    if (run) {
      vcall<u32>(self, 0x628, 2u, 1u, 0u);
      u8 *vt = *(u8 **)self;
      self[0x726] = 0;
      u32 r = vcall<u32>(self, 0x588);
      typedef u32(THISCALL * fn_t)(u8 *, u32);
      (*(fn_t *)(vt + 0x62c))(self, r != 0);
    }
  }
  return ext_461250(self, a, b, f1, f2, f3);
}
PCREG(477670, fn477670);
