// batch40001.cpp - cascade t1 (Sonnet), tier H: 0x5ab970, 0x5a0da0, 0x52a700, 0x452e60, 0x4f1b20, 0x4804e0.
#include "ff.h"

extern "C" void THISCALL ext_4db7c0(u8 *self, float *out);       // thiscall ret 4
extern "C" void THISCALL ext_5a01e0(u8 *self);                   // thiscall, plain ret
extern "C" u8 *ext_41e290(u32 n);                                // cdecl allocator

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static u8 *sysobj() { return G(u8 *, 0x70039c); }
static u8 *engTable() { return (u8 *)rd32(sysobj() + 0x9b); }

// 0x5ab970, thiscall() returns eax: a = unaligned [this+0x6e], b = unaligned [this+0x72]; (b - a) & ~0xf == 0 -> 0; else o = [[a+8]+8]; ext_4db7c0(o, buf); return (int)(buf[1] * K(0x680a60)).
static s32 THISCALL fn5ab970(u8 *self) {
  u32 a = rd32(self + 0x6e);
  if (((rd32(self + 0x72) - a) & 0xfffffff0u) == 0) return 0;
  u8 *o = *(u8 **)(*(u8 **)((u8 *)a + 8) + 8);
  float buf[4];
  ext_4db7c0(o, buf);
  return _mm_cvttss_si32(_mm_set_ss(buf[1] * G(float, 0x680a60)));
}
PCREG(5ab970, fn5ab970);

// 0x5a0da0, thiscall(): n = unaligned [this+0x7ce]; n == 0 -> nothing; vt = [this]; p = this + 0x7c2 + n*16;
// ax = (u16) engine table slot 0x114 (0x6a54b0, 0, 0x6ae6a0, 0xb62, p); vt->slot 0x130 (this, ax); ext_5a01e0(this + 0x7ce); copies 16 bytes p -> this + 0x8d2.
static void THISCALL fn5a0da0(u8 *self) {
  u32 n = rd32(self + 0x7ce);
  if (!n) return;
  u8 *vt = *(u8 **)self;
  u8 *p = self + 0x7c2 + (n << 4);
  u32 ax = (u16)vcall<u32>(engTable(), 0x114, (u32)0x6a54b0, (u32)0, (u32)0x6ae6a0, (u32)0xb62, (u32)p);
  ((void(THISCALL *)(u8 *, u8 *, u32))rd32(vt + 0x130))(self, self, ax);
  ext_5a01e0(self + 0x7ce);
  u8 t[16];
  for (int i = 0; i < 16; i++) t[i] = p[i];
  for (int i = 0; i < 16; i++) self[0x8d2 + i] = t[i];
}
PCREG(5a0da0, fn5a0da0);

// 0x52a700, thiscall(rec) ret 4, returns al: ring buffer: buf = [this], cap = [this+4], tail = [this+8], head = [this+0xc] (signed);
// (head + 1) % cap == tail -> false; else copies 0x32 bytes rec to buf + head*0x32; head = (head + 1) % cap; true.
static u32 THISCALL fn52a700(u8 *self, u8 *rec) {
  s32 head = *(s32 *)(self + 0xc);
  s32 cap = *(s32 *)(self + 4);
  if ((head + 1) % cap == *(s32 *)(self + 8)) return 0;
  u8 *d = *(u8 **)self + head * 0x32;
  for (int i = 0; i < 0x32; i++) d[i] = rec[i];
  *(s32 *)(self + 0xc) = (head + 1) % cap;
  return 1;
}
PCREG(52a700, fn52a700);

// 0x452e60, thiscall(float f) ret 4: this->slot 0x238(); q = [[sys + 0x1aa3 (unaligned)] + 0x18]; id = [[this+8] + 0x6c];
// q->slot 0x8c(id, buf); buf[5] = f; q->slot 0xac(id, buf) (buf is 7 dwords, filled by the first slot); this->slot 0x220(1).
static void THISCALL fn452e60(u8 *self, float f) {
  u32 buf[7];
  vcall<void>(self, 0x238);
  u8 *q = *(u8 **)((u8 *)rd32(sysobj() + 0x1aa3) + 0x18);
  u32 id = *(u32 *)(*(u8 **)(self + 8) + 0x6c);
  vcall<void>(q, 0x8c, id, (u32)buf);
  buf[5] = fbits(f);
  q = *(u8 **)((u8 *)rd32(sysobj() + 0x1aa3) + 0x18);
  vcall<void>(q, 0xac, *(u32 *)(*(u8 **)(self + 8) + 0x6c), (u32)buf);
  vcall<void>(self, 0x220, (u32)1);
}
PCREG(452e60, fn452e60);

// 0x4f1b20, thiscall(p) ret 4: r = engine table slot 0x4c(p); q = this + 0x1a7 (object with vtable at q); q->slot 0x2c(r) == 0 -> q->slot 0x98(r, (float)-(s32)[p+0x4c], 0).
static void THISCALL fn4f1b20(u8 *self, u8 *p) {
  u32 r = vcall<u32>(engTable(), 0x4c, (u32)p);
  u8 *q = self + 0x1a7;
  u32 vt = rd32(q);
  u32 res = ((u32(THISCALL *)(u8 *, u32))rd32((u8 *)vt + 0x2c))(q, r);
  if (res) return;
  vt = rd32(self + 0x1a7);
  float f = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(-*(s32 *)(p + 0x4c))));
  ((void(THISCALL *)(u8 *, u32, float, u32))rd32((u8 *)vt + 0x98))(q, r, f, 0);
}
PCREG(4f1b20, fn4f1b20);

// 0x4804e0, thiscall(): a = ext_41e290(8); [this+0x8c] = a; [a] = 1; b = ext_41e290(0x44); [a+4] = b; fills the 0x44-byte record b: identity-like 3x3 (1.0 at +0x14, +0x1c, +0x20, +0x28), zeros,
// [b+0x2c] = [b+0x30] = 2 * float [this+0x1c], [b+0x34..0x40] = -1.
static void THISCALL fn4804e0(u8 *self) {
  u8 *a = ext_41e290(8);
  *(u8 **)(self + 0x8c) = a;
  *(u32 *)a = 1;
  u8 *b = ext_41e290(0x44);
  *(u8 **)(a + 4) = b;
  float f = *(float *)(self + 0x1c);
  u32 *w = (u32 *)b;
  w[0] = 0; w[1] = 0; w[2] = 0;
  w[0x2c / 4] = fbits(f + f);
  w[3] = 0; w[4] = 0; w[5] = 0x3f800000; w[6] = 0; w[7] = 0x3f800000;
  w[0x30 / 4] = fbits(f + f);
  w[8] = 0x3f800000; w[9] = 0; w[10] = 0x3f800000;
  w[0x34 / 4] = 0xffffffff; w[0x38 / 4] = 0xffffffff; w[0x3c / 4] = 0xffffffff; w[0x40 / 4] = 0xffffffff;
}
PCREG(4804e0, fn4804e0);
