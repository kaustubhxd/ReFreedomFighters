#include "ff.h"

extern "C" float THISCALL ext_662870(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

// 0x6627c0: thiscall(float *p) ret 4 -> bool in AL: smoothed value tracker. Fields: [0] float current, [8] float previous, [0xc] byte "fresh" flag, [0xd] dword stamp,
// [0x11] dword duration, [0x19] float threshold; the engine object [0x70039c] holds the clock dword at +0x40. A set flag moves current to previous, clears itself and
// refreshes the stamp from the clock (unless the stamp aliases the clock). If |current - *p| (as a double, masked through the exe constant 0x67cd50) is above the
// threshold: current = previous = *p, the stamp is refreshed and 0 is returned; otherwise the value goes through 0x662870 (float), is stored in current and *p, and the
// result is clock >= stamp + duration (signed).
extern "C" u8 THISCALL fn_6627c0(u8 *self, float *p) {
  if (self[0xc]) {
    wr32u(self + 8, rd32u(self));
    self[0xc] = 0;
    u8 *clk = G(u8 *, 0x70039c) + 0x40;
    if (self + 0xd != clk) wr32u(self + 0xd, rd32u(clk));
  }
  float cur = rdf(self);
  float x = cur - *p;
  double dx = (double)x;
  u64 bits;
  __builtin_memcpy(&bits, &dx, 8);
  bits &= G(u64, 0x67cd50);
  __builtin_memcpy(&dx, &bits, 8);
  if (dx > (double)rdf(self + 0x19)) {
    u32 v;
    __builtin_memcpy(&v, p, 4);
    wr32u(self, v);
    wr32u(self + 8, v);
    u8 *clk = G(u8 *, 0x70039c) + 0x40;
    if (self + 0xd != clk) wr32u(self + 0xd, rd32u(clk));
    return 0;
  }
  float r = ext_662870(self);
  __builtin_memcpy(self, &r, 4);
  *p = r;
  u8 *g = G(u8 *, 0x70039c);
  s32 t = (s32)(rd32u(self + 0x11) + rd32u(self + 0xd));
  return (s32)rd32u(g + 0x40) >= t;
}
PCREG(6627c0, fn_6627c0);
