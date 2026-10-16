#include "ff.h"

extern "C" float THISCALL ext_4e5f90(void *self);
extern "C" u32 THISCALL ext_4e6420(void *self);
extern "C" u32 THISCALL ext_4e6400(void *self);

// advance the typed-value cursor by one record (same switch as 0x4e6420, inlined in the originals)
static inline void adv(u8 **self) {
  u8 *p = *self;
  u32 i = (u32)(p[0] & 0x3f) - 1;
  if (i > 10) return;
  static const u8 map[11] = {0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1};
  u8 *q;
  switch (map[i]) {
    case 0: q = p + 9; break;
    case 1: q = p + 5; break;
    case 2: {
      u8 *c = p + 1;
      do {} while (*c++ != 0);
      q = p + 2 + (c - (p + 2));
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

// 0x4e6180: thiscall(this, float *out) ret 4: reads typed values until the "more" flag clears; returns the count
u32 THISCALL fn_4e6180(u8 **self, float *out) {
  u32 n = 1;
  float v = ext_4e5f90(self);
  ext_4e6420(self);
  out[0] = v;
  while ((u8)ext_4e6400(self)) {
    v = ext_4e5f90(self);
    adv(self);
    out[n] = v;
    n++;
  }
  return n;
}
PCREG(4e6180, fn_4e6180);

// 0x4e6250: same with double outputs
u32 THISCALL fn_4e6250(u8 **self, double *out) {
  u32 n = 1;
  float v = ext_4e5f90(self);
  ext_4e6420(self);
  out[0] = (double)v;
  while ((u8)ext_4e6400(self)) {
    v = ext_4e5f90(self);
    adv(self);
    out[n] = (double)v;
    n++;
  }
  return n;
}
PCREG(4e6250, fn_4e6250);
