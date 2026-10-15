// batch41000.cpp - cascade t2 (Sonnet): tier H float functions 0x462510 and 0x51d000.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

extern "C" void THISCALL ext_51db60(u8 *self);                          // thiscall, plain ret
extern "C" void THISCALL ext_51cf10(u8 *self);                          // thiscall, plain ret (tail target)
extern "C" void THISCALL ext_523520(u8 *self, u8 *p, float a, float b); // thiscall, ret 0xc

// 0x462510, thiscall(flag) ret 4: m = [this+0x6c]; when m is null nothing happens. When the low byte of flag is set: m slot 0x4c(&loc[3]), then while
// e = [this+0x6c] slot 0x64(&loc): f = [this+0x6c] slot 0x9c(e) (float on x87); if [e+4], call [e+8] with ecx = [this+0x74] and (this, f, -1.0f, 0).
// Always: [this+0x6c] slot 0 (scalar delete, arg 1) when non-null, then [this+0x6c] = 0.
static void THISCALL fn462510(u8 *self, u32 flag) {
  void *m = (void *)rd32(self + 0x6c);
  if (!m) return;
  if (flag & 0xff) {
    u32 loc[3];
    vcall<void>(m, 0x4c, (u32)loc);
    u8 *e = vcall<u8 *>((void *)rd32(self + 0x6c), 0x64, (u32)loc);
    while (e) {
      float f = vcall<float>((void *)rd32(self + 0x6c), 0x9c, (u32)e);
      if (rd32(e + 4)) {
        typedef void(THISCALL * fp_t)(void *, u8 *, float, float, u32);
        ((fp_t)rd32(e + 8))((void *)rd32(self + 0x74), self, f, -1.0f, 0);
      }
      e = vcall<u8 *>((void *)rd32(self + 0x6c), 0x64, (u32)loc);
    }
  }
  void *m2 = (void *)rd32(self + 0x6c);
  if (m2) vcall<void>(m2, 0x0, 1u);
  wr32(self + 0x6c, 0);
}
PCREG(462510, fn462510);

// 0x51d000, thiscall, no args: A = [this+0x5c]; [this+0x24a..0x252] = A[8], A[0xc], A[0x10]; f = A slot 0xc() (float x87, no args);
// 0x523520(A, this+0x256, f, 500.0f) (ret 0xc); when [this+0x499] != 0: r = sys[0x9b] slot 0x60([this+0x499]); when r: t = (int)(A'[0x24] * [this+0x4a9]) + [this+0x4a5];
// [r+0x60] = t - [r+0x64]; [r+0x64] = t. Then sys[0x9b] slot 0x58([this+0x123]); this slots 0x390, 0x374, 0x364; 0x51db60(this); tail 0x51cf10(this).
static void THISCALL fn51d000(u8 *self) {
  u8 *a = (u8 *)rd32(self + 0x5c);
  wr32(self + 0x24a, rd32(a + 8));
  wr32(self + 0x24e, rd32(a + 0xc));
  wr32(self + 0x252, rd32(a + 0x10));
  float f = vcall<float>(a, 0xc);
  ext_523520((u8 *)rd32(self + 0x5c), self + 0x256, f, 500.0f);
  u32 id = rd32(self + 0x499);
  if (id) {
    u8 *tbl = (u8 *)rd32(G(u8 *, 0x70039c) + 0x9b);
    u8 *r = vcall<u8 *>(tbl, 0x60, id);
    if (r) {
      u8 *a2 = (u8 *)rd32(self + 0x5c);
      float p = rdf(a2 + 0x24) * rdf(self + 0x4a9);
      u32 t = (u32)_mm_cvttss_si32(_mm_set_ss(p)) + rd32(self + 0x4a5);
      wr32(r + 0x60, t - rd32(r + 0x64));
      wr32(r + 0x64, t);
    }
  }
  vcall<void>((void *)rd32(G(u8 *, 0x70039c) + 0x9b), 0x58, rd32(self + 0x123));
  vcall<void>(self, 0x390);
  vcall<void>(self, 0x374);
  vcall<void>(self, 0x364);
  ext_51db60(self);
  ext_51cf10(self);
}
PCREG(51d000, fn51d000);
