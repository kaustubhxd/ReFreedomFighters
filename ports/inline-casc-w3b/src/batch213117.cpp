#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_610100(void *self, void *stream);
extern "C" void THISCALL ext_4e12f0(void *stream, void *dst, u32 count);
extern "C" void THISCALL ext_4e12e0(void *stream, void *dst, u32 count);
extern "C" void THISCALL ext_4e1440(void *stream, void *dst);
extern "C" u32 THISCALL ext_4e1600(void *stream);
extern "C" void THISCALL ext_4e1b30(void *stream);
extern "C" void FASTCALL ext_4e0980(void *a, void *b);
extern "C" void *ext_41e290(u32 size);                       // cdecl allocator
extern "C" void *ext_634d10(void *dst, int c, u32 n);          // cdecl memset (IAT thunk)

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u32 sat_mul(u32 a, u32 b) {
  u64 p = (u64)a * (u64)b;
  return (p >> 32) ? 0xffffffffu : (u32)p;
}

// 0x4585b0: thiscall(stream) ret 4, /GS protected, void. A loader that reads the fields of this from a stream (reader helpers 0x4e12f0 / 0x4e12e0: (stream, dst, count);
// version byte = 0x4e1600(stream), 0x4e1440, 0x4e1b30). Reads 3 floats each into this+0x28, +0x44, +0x50; V = (1 / f[0x28], 1 / f[0x2c], 1 / f[0x30]) scales the vectors +0x44 and
// +0x50 (0x4e0980); version 2 reads f[0x18]; reads this[0x34]; version 3 reads one more at +0x38, then +0x38, +0x3c; version 3 reads four values into scratch slots else 0x4e1440
// reads one; reads this[0x40]; 0x4e1b30. Then this[0xcc] = alloc(sat(this[0x34] * (f[0x18] == [0x6785d0] ? 0x20 : 0x30))), memset(this+0xd4, 0, 0x280), the four 0xa0-byte
// slots at this+0xd4 + 0xa0 * k get (this[0x34], f[0x18] at +0x18 from base 0xec, this[0xcc] at +0xd8, -1 at +0xe8) and this[0xd0] = alloc(sat(this[0x34] * 0x10)).
extern "C" void THISCALL fn_4585b0(u8 *self, u8 *S) {
  u32 loc14, loc18;
  ext_610100(self, S);
  ext_4e12f0(S, self + 0x28, 3);
  ext_4e12f0(S, self + 0x44, 3);
  ext_4e12f0(S, self + 0x50, 3);
  float V[3];
  V[0] = 1.0f / rdf(self + 0x28);
  V[1] = 1.0f / rdf(self + 0x2c);
  V[2] = 1.0f / rdf(self + 0x30);
  ext_4e0980(self + 0x44, V);
  ext_4e0980(self + 0x50, V);
  if ((u8)ext_4e1600(S) == 2) ext_4e12f0(S, self + 0x18, 1);
  ext_4e12e0(S, self + 0x34, 1);
  if ((u8)ext_4e1600(S) == 3) ext_4e12f0(S, self + 0x38, 1);
  ext_4e12f0(S, self + 0x38, 1);
  ext_4e12f0(S, self + 0x3c, 1);
  if ((u8)ext_4e1600(S) == 3) {
    ext_4e12e0(S, &loc18, 1);
    ext_4e12f0(S, &loc14, 1);
    ext_4e12f0(S, &loc14, 1);
    ext_4e12f0(S, &loc14, 1);
    ext_4e12e0(S, &loc18, 1);
  } else {
    ext_4e1440(S, &loc18);
  }
  ext_4e12e0(S, self + 0x40, 1);
  ext_4e1b30(S);
  u32 mult = (rdf(self + 0x18) == G(float, 0x6785d0)) ? 0x20u : 0x30u;
  wr32u(self + 0xcc, (u32)ext_41e290(sat_mul(rd32u(self + 0x34), mult)));
  ext_634d10(self + 0xd4, 0, 0x280);
  for (int k = 0; k < 4; k++) {
    u8 *slot = self + 0xd4 + 0xa0 * k;
    wr32u(slot, rd32u(self + 0x34));
    wr32u(slot + 0x18, rd32u(self + 0x18));
    wr32u(slot + 4, rd32u(self + 0xcc));
    wr32u(slot + 0x14, 0xffffffffu);
  }
  wr32u(self + 0xd0, (u32)ext_41e290(sat_mul(rd32u(self + 0x34), 0x10)));
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4585b0, fn_4585b0);
