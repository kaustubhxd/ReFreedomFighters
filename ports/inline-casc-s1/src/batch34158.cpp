// batch34158.cpp - cascade tier H, batch 34158: 0x4658d0 (run a pending callback), 0x476300 (stamp a time and reset), 0x51ebe0 (forward two cells), 0x562b50 (arm a state), 0x438050 (read a signed byte as a float), 0x484ed0 (forward a float to a slot).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);         // ret 4
extern "C" void THISCALL ext_59cb60(void *self, u32 a);         // ret 4
extern "C" void THISCALL ext_4f21f0(void *self, u32 b);         // ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4658d0, thiscall(base) ret 4: while the unaligned 16-byte record at [this+0x3d] has a non-zero function pointer fn (dword 0): the record is replaced by {0, 0, 0, 0xffffffff} and fn is called (thiscall plain) with ecx = dword 1 + base.
static void THISCALL fn4658d0(u8 *self, u32 base) {
  for (;;) {
    u32 fn = rd32(self + 0x3d);
    u32 adj = rd32(self + 0x41);
    if (!fn) return;
    wr32(self + 0x3d, 0);
    wr32(self + 0x41, 0);
    wr32(self + 0x45, 0);
    wr32(self + 0x49, 0xffffffff);
    ((void(THISCALL *)(u32))fn)(adj + base);
  }
}
PCREG(4658d0, fn4658d0);

// 0x476300, thiscall(w, unused) ret 8, returns 0: when (u16)w equals the word at [this+0x4c]: unaligned [this+0x52] = [[0x70039c]+0x40] - cvtt([this+0x48] * constant 0x67862c); this->slot0x64(0x10).
static u32 THISCALL fn476300(u8 *self, u32 w, u32 unused) {
  if ((u16)w == *(u16 *)(self + 0x4c)) {
    __m128 t = _mm_mul_ss(_mm_set_ss(*(float *)(self + 0x48)), _mm_set_ss(G(float, 0x67862c)));
    s32 n = _mm_cvttss_si32(t);
    wr32(self + 0x52, *(s32 *)(G(u8 *, 0x70039c) + 0x40) - n);
    vcall<void>(self, 0x64, 0x10u);
  }
  return 0;
}
PCREG(476300, fn476300);

// 0x51ebe0, thiscall(p) ret 4: a = *ext_5003d0([p+4], 0) (float); e = [this+0x18] + 0x34e (an embedded object): e->slot0(a, 0.0349066 (0x3d0efa35), 6.2831855 (0x40c90fdb)); unaligned [[this+0x18] + 0x33e] = *ext_5003d0([p+4], 1).
static void THISCALL fn51ebe0(u8 *self, u8 *p) {
  u32 a = *(u32 *)ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *e = *(u8 **)(self + 0x18) + 0x34e;
  vcall<void>(e, 0x0, a, 0x3d0efa35u, 0x40c90fdbu);
  u32 b = *(u32 *)ext_5003d0(*(u8 **)(p + 4), 1);
  wr32(*(u8 **)(self + 0x18) + 0x33e, b);
}
PCREG(51ebe0, fn51ebe0);

// 0x562b50, thiscall(a) ret 4: ext_59cb60([this+0x94], a); byte [this+0x84] = 1; when byte [this+0x85] is zero and dword [this+0xdc] == 2: byte [+0x85] = 1; [+0xdc] = 4; float [+0x64] = (float)[[0x70039c]+0x30] * constant 0x6785e4; ext_4f21f0(this->slot0x84(), 0).
static void THISCALL fn562b50(u8 *self, u32 a) {
  ext_59cb60(*(u8 **)(self + 0x94), a);
  u8 old85 = self[0x85];
  self[0x84] = 1;
  if (old85) return;
  if (*(u32 *)(self + 0xdc) != 2) return;
  self[0x85] = 1;
  s32 n = *(s32 *)(G(u8 *, 0x70039c) + 0x30);
  *(u32 *)(self + 0xdc) = 4;
  *(float *)(self + 0x64) = _mm_cvtss_f32(_mm_mul_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(n)), _mm_set_ss(G(float, 0x6785e4))));
  u8 *o = vcall<u8 *>(self, 0x84);
  ext_4f21f0(o, 0);
}
PCREG(562b50, fn562b50);

// 0x438050, thiscall(a, b) ret 8, float in st0: 0.0 when this->slot0x38(a, b) is false (low byte); else (float)(signed byte this->slot0xa4(a)) / constant 0x67af20.
static float THISCALL fn438050(u8 *self, u32 a, u32 b) {
  if (!(u8)vcall<u32>(self, 0x38, a, b)) return 0.0f;
  s32 v = (s8)vcall<u32>(self, 0xa4, a);
  return _mm_cvtss_f32(_mm_div_ss(_mm_cvtepi32_ps(_mm_cvtsi32_si128(v)), _mm_set_ss(G(float, 0x67af20))));
}
PCREG(438050, fn438050);

// 0x484ed0, thiscall(f) ret 4: loc = (byte [this+0x417] & 3) ? f : 0.0; r = this->slot0x5fc(); when r: this->slot0x244(r, loc, 0, 0, 0).
static void THISCALL fn484ed0(u8 *self, u32 f) {
  u32 loc = (self[0x417] & 3) ? f : 0;
  u32 r = vcall<u32>(self, 0x5fc);
  if (r) vcall<void>(self, 0x244, r, loc, 0u, 0u, 0u);
}
PCREG(484ed0, fn484ed0);
