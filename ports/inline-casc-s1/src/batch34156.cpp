// batch34156.cpp - cascade tier H, batch 34156: 0x528ae0, 0x656ac0, 0x515950, 0x59d4e0, 0x4bdc70, 0x5510a0, 0x656200.
#include "ff.h"

extern "C" void STDCALL ext_528f50(u32 obj, u32 f);               // ret 8
extern "C" void THISCALL ext_469870(void *self);                  // plain ret
extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);            // ret 4
extern "C" void THISCALL ext_500360(void *self, u32 f);           // ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static __m128 ld_ss(u8 *p) { return _mm_set_ss(bitsf(rd32(p))); }
static void st_ss(u8 *p, __m128 v) { wr32(p, __builtin_bit_cast(u32, _mm_cvtss_f32(v))); }

// 0x528ae0, thiscall plain: a = [this+0x80]/k + [this+0x22c4]; b = [this+0x7c]/k + [this+0x22c8] (k = constant 0x6a0bcc); [this+0x22c4] = a; [this+0x22c8] = b;
// ext_528f50(unaligned [this+0x21a9], -a); ext_528f50(unaligned [this+0x21a5], -[this+0x22c8]) (sign flip with the mask at 0x67af40, stdcall 2 args).
static void THISCALL fn528ae0(u8 *self) {
  __m128 k = _mm_set_ss(G(float, 0x6a0bcc));
  __m128 a = _mm_div_ss(ld_ss(self + 0x80), k);
  __m128 b = _mm_div_ss(ld_ss(self + 0x7c), k);
  a = _mm_add_ss(a, ld_ss(self + 0x22c4));
  b = _mm_add_ss(b, ld_ss(self + 0x22c8));
  st_ss(self + 0x22c4, a);
  u32 mask = G(u32, 0x67af40);
  u32 na = __builtin_bit_cast(u32, _mm_cvtss_f32(a)) ^ mask;
  st_ss(self + 0x22c8, b);
  ext_528f50(rd32(self + 0x21a9), na);
  u32 nb = rd32(self + 0x22c8) ^ mask;
  ext_528f50(rd32(self + 0x21a5), nb);
}
PCREG(528ae0, fn528ae0);

// 0x656ac0, stdcall(A, B) ret 8: A[0x10] = B[0x10]; A[0x14] = B[0x14]; lo = B[0x1c] - 1.0 (constant 0x678858); A[0x18] = (B[0x18] > lo) ? lo : B[0x18]; A[0x1c] = B[0x1c]; A[0x20] = 1.0 / (B[0x1c] - A[0x18]).
static void STDCALL fn656ac0(u8 *A, u8 *B) {
  __m128 one = _mm_set_ss(G(float, 0x678858));
  wr32(A + 0x10, rd32(B + 0x10));
  wr32(A + 0x14, rd32(B + 0x14));
  __m128 lo = _mm_sub_ss(ld_ss(B + 0x1c), one);
  __m128 hi = ld_ss(B + 0x18);
  if (_mm_comigt_ss(hi, lo)) st_ss(A + 0x18, lo);
  else st_ss(A + 0x18, hi);
  __m128 t = ld_ss(B + 0x1c);
  st_ss(A + 0x1c, t);
  t = _mm_sub_ss(t, ld_ss(A + 0x18));
  st_ss(A + 0x20, _mm_div_ss(one, t));
}
PCREG(656ac0, fn656ac0);

// 0x515950, thiscall plain: c = [this+0x5c]; nothing when the unaligned dword [c+0x39] == 2; by the unaligned kind [c+0x35]: 1 -> c->slot0x8(float [this+0xc0], float [c+0x5f]); 4 -> c->slot0x8(float [c+0x57], float [c+0x5b]).
static void THISCALL fn515950(u8 *self) {
  u8 *c = *(u8 **)(self + 0x5c);
  if (rd32(c + 0x39) == 2) return;
  u32 k = rd32(c + 0x35);
  if (k == 1) vcall<void>(c, 0x8, rd32(self + 0xc0), rd32(c + 0x5f));
  else if (k == 4) vcall<void>(c, 0x8, rd32(c + 0x57), rd32(c + 0x5b));
}
PCREG(515950, fn515950);

// 0x59d4e0, ecx = begin, edx = end, stack arg dest (ret 4): n = (end - begin) >> 6 (signed); for each of n: dest -= 0x40 and copies the 64 bytes at dest + (end - dest0) to dest in four 16-byte unaligned moves. Returns the final dest.
static u8 *FASTCALL fn59d4e0(u8 *begin, u8 *end, u8 *dest) {
  s32 n = (s32)((u32)end - (u32)begin) >> 6;
  if (n <= 0) return dest;
  u32 delta = (u32)end - (u32)dest;
  u8 *d = dest;
  do {
    __m128i m0 = _mm_loadu_si128((const __m128i *)(d + delta - 0x40));
    d -= 0x40;
    n--;
    _mm_storeu_si128((__m128i *)d, m0);
    __m128i m1 = _mm_loadu_si128((const __m128i *)(d + delta + 0x10));
    _mm_storeu_si128((__m128i *)(d + 0x10), m1);
    __m128i m2 = _mm_loadu_si128((const __m128i *)(d + delta + 0x20));
    _mm_storeu_si128((__m128i *)(d + 0x20), m2);
    __m128i m3 = _mm_loadu_si128((const __m128i *)(d + delta + 0x30));
    _mm_storeu_si128((__m128i *)(d + 0x30), m3);
  } while (n > 0);
  return d;
}
PCREG(59d4e0, fn59d4e0);

// 0x4bdc70, thiscall plain, returns this: ext_469870(this); [this+4] |= 0x20; [this] = 0x693b1c; dwords +0x44, +0x48, +0x4c, +0x50, +0x54 = 0; byte +0x58 = 1; unaligned dwords +0x59, +0x5d, +0x61 = 0; 16 zero bytes at +0x65 and at +0x75.
static u8 *THISCALL fn4bdc70(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x693b1c;
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x54) = 0;
  self[0x58] = 1;
  wr32(self + 0x59, 0);
  wr32(self + 0x5d, 0);
  wr32(self + 0x61, 0);
  for (int i = 0; i < 16; i++) self[0x65 + i] = 0;
  for (int i = 0; i < 16; i++) self[0x75 + i] = 0;
  return self;
}
PCREG(4bdc70, fn4bdc70);

// 0x5510a0, stdcall(a, b, pf) ret 0xc: s = a->slot0x18(b); when s: o = s->slot0x4c(); ext_500360(ext_5003d0(o, 0), *pf) (the float is the second call's argument). Returns s.
static u8 *STDCALL fn5510a0(u8 *a, u32 b, u32 *pf) {
  u8 *s = vcall<u8 *>(a, 0x18, b);
  if (!s) return s;
  u8 *o = vcall<u8 *>(s, 0x4c);
  u32 f = *pf;
  u8 *r = (u8 *)ext_5003d0(o, 0);
  ext_500360(r, f);
  return s;
}
PCREG(5510a0, fn5510a0);

// 0x656200, thiscall(w, x, y) ret 0xc: builds a 32-byte request {0x20100, word w, 0, 0, y, 0, 0, 0, x} and returns this->slot0x50(&request, 0x20).
static u32 THISCALL fn656200(u8 *self, u32 w, u32 x, u32 y) {
  u32 loc[8];
  for (int i = 0; i < 8; i++) loc[i] = 0;
  loc[0] = 0x20100;
  loc[1] = (u16)w;
  loc[3] = y;
  loc[7] = x;
  return vcall<u32>(self, 0x50, (u32)loc, 0x20u);
}
PCREG(656200, fn656200);
