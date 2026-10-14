// batch35133.cpp - cascade s5 batch 35133: 0x473f20 (GUESS fetch the current 3-dword value: the primary one when its owner resolves, else the queued one).
#include "ff.h"

extern "C" u32 THISCALL ext_4666d0(u8 *self);   // returns the unaligned dword at +0x39
extern "C" u32 *THISCALL ext_4673c0(u8 *self);  // returns self + 0x25 unless that dword is 0x7fffffff (then 0)
typedef u32(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v1p_t)(void *, u32 *);

// 0x473f20, thiscall(out) ret 4, returns bool. q = this + 0x26a. e = 0x4666d0(q) (the unaligned dword at this+0x2a3): when non-zero and [engine+0x9b] slot 0x58(e) resolves, out = {[this+0x3c8], [this+0x3cc], [this+0x3d0]}, true.
// Otherwise p = 0x4673c0(q): non-null copies its three dwords to out and calls this slot 0x84(out), true; null gives false.
static u8 THISCALL fn473f20(u8 *self, u32 *out) {
  u8 *q = self + 0x26a;
  u32 e = ext_4666d0(q);
  if (e) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    if ((*(e1_t **)tab)[0x58 / 4](tab, e)) {
      out[0] = *(u32 *)(self + 0x3c8);
      out[1] = *(u32 *)(self + 0x3cc);
      out[2] = *(u32 *)(self + 0x3d0);
      return 1;
    }
  }
  u32 *p = ext_4673c0(q);
  if (!p) return 0;
  out[0] = p[0];
  out[1] = p[1];
  out[2] = p[2];
  (*(v1p_t **)self)[0x84 / 4](self, out);
  return 1;
}
PCREG(473f20, fn473f20);
