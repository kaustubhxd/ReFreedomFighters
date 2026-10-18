#include "ff.h"

extern "C" u32 THISCALL ext_523f50(void *self);
extern "C" float STDCALL ext_522f60(float a, float b);

static inline u32 rd35(u8 *s) { u32 v; __builtin_memcpy(&v, s + 0x35, 4); return v; }
static inline void wr35(u8 *s, u32 v) { __builtin_memcpy(s + 0x35, &v, 4); }

// 0x524270: thiscall(this): small state machine on the dword at this+0x35 (0..4), driven by 0x523f50(this) and |0x522f60([this+4], 50.0)| vs 0.0175...
void THISCALL fn_524270(u8 *self) {
  u32 st = rd35(self);
  if (st > 4) return;
  const double T = __builtin_bit_cast(double, 0x3f91df46a0000000ULL);
  switch (st) {
    case 0:
      if ((u8)ext_523f50(self)) wr35(self, 1);
      return;
    case 1: wr35(self, 2); return;
    case 2: {
      double v = (double)ext_522f60(*(float *)(self + 4), 50.0f);
      v = __builtin_bit_cast(double, __builtin_bit_cast(u64, v) & 0x7fffffffffffffffULL);
      if (v > T) wr35(self, 3);
      return;
    }
    case 3: {
      double v = (double)ext_522f60(*(float *)(self + 4), 50.0f);
      v = __builtin_bit_cast(double, __builtin_bit_cast(u64, v) & 0x7fffffffffffffffULL);
      if (!(v > T)) wr35(self, 4);
      return;
    }
    default: wr35(self, 0); return;
  }
}
PCREG(524270, fn_524270);
