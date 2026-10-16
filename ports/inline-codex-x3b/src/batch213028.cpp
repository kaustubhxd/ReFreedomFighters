#include "ff.h"
#include <emmintrin.h>

typedef u32(THISCALL *V0)(void *);
extern "C" s32 THISCALL ext_4e5f10(void *self);
extern "C" u32 THISCALL ext_4e6420(void *self);
extern "C" u32 THISCALL ext_4e6400(void *self);
extern "C" u32 THISCALL ext_473e50(void *self);

static inline void adv2(u8 **self) {
  u8 *p = *self;
  u32 i = (u32)(p[0] & 0x3f) - 1;
  if (i > 10) return;
  static const u8 map[11] = {0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1};
  u8 *q;
  switch (map[i]) {
    case 0: q = p + 9; break;
    case 1: q = p + 5; break;
    case 2: {
      u32 n = 0;
      while (p[1 + n] != 0) n++;
      q = p + 2 + n;
      break;
    }
    case 3: {
      u32 len;
      __builtin_memcpy(&len, p + 1, 4);
      q = p + (len + 1);
      break;
    }
    default: return;
  }
  *self = q;
}

// 0x4e6050: thiscall(this, int *out) ret 4: typed value stream to ints: first value through 0x4e5f10 and the 0x4e6420 advance, then while
// 0x4e6400 says more: double / float truncated or dword read in place, other tags give 0, advance inline; returns the count
u32 THISCALL fn_4e6050(u8 **self, s32 *out) {
  u32 n = 1;
  s32 v = ext_4e5f10(self);
  ext_4e6420(self);
  out[0] = v;
  while ((u8)ext_4e6400(self)) {
    u8 *p = *self;
    u32 i = (u32)(p[0] & 0x3f) - 1;
    if (i > 10) {
      v = 0;
    } else {
      static const u8 map[11] = {0, 1, 2, 3, 3, 3, 3, 2, 3, 2, 2};
      switch (map[i]) {
        case 0: {
          double d;
          __builtin_memcpy(&d, p + 1, 8);
          v = _mm_cvttsd_si32(_mm_set_sd(d));
          break;
        }
        case 1: {
          float f;
          __builtin_memcpy(&f, p + 1, 4);
          v = _mm_cvttss_si32(_mm_set_ss(f));
          break;
        }
        case 2: __builtin_memcpy(&v, p + 1, 4); break;
        default: v = 0; break;
      }
    }
    adv2(self);
    out[n] = v;
    n++;
  }
  return n;
}
PCREG(4e6050, fn_4e6050);

// 0x591880: thiscall(this): picks a field by flags at +0x417 and the kind of this->[0x50c]()'s object ->[0x350]()->[0x330](); otherwise tail-calls 0x473e50
u32 THISCALL fn_591880(u8 *self) {
  u32 flags;
  __builtin_memcpy(&flags, self + 0x417, 4);
  if (flags & 0x40000) return 0;
  if (flags & 0x2000000) return *(u32 *)(self + 0x744);
  u8 *o = (u8 *)(*(V0 *)(*(u8 **)self + 0x50c))(self);
  if (!o) return *(u32 *)(self + 0x266);
  if ((u8)(*(V0 *)(*(u8 **)self + 0x49c))(self)) {
    u8 *e = (u8 *)(*(V0 *)(*(u8 **)o + 0x350))(o);
    u32 k = (*(V0 *)(*(u8 **)e + 0x330))(e);
    if (k <= 7) {
      static const u8 map[8] = {0, 0, 1, 1, 1, 1, 1, 2};
      switch (map[k]) {
        case 0:
          if ((*(V0 *)(*(u8 **)self + 0x508))(self)) return *(u32 *)(self + 0x74c);
          return *(u32 *)(self + 0x750);
        case 1: return *(u32 *)(self + 0x754);
        default: return *(u32 *)(self + 0x758);
      }
    }
  }
  u8 *e = (u8 *)(*(V0 *)(*(u8 **)o + 0x350))(o);
  u32 k = (*(V0 *)(*(u8 **)e + 0x330))(e);
  if (k == 3) return *(u32 *)(self + 0x740);
  if (k - 10 <= 2) return 0;
  return ext_473e50(self);
}
PCREG(591880, fn_591880);
