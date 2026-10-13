// f15b009.cpp - fresh slice 15, batch 9 (2026-10-12).
// 0x639bb0 (set slot idx of a 20-byte table at [this+0x14])(data, size, a, b, idx, copy): free the owned copy
//          (+0xc flag, +0x10 ptr; delete(p, 1)); copy -> flag = 1, p = new(size), memcpy(p, data, size); else p = data;
//          +0 = size, +4 = a, +8 = b. The table pointer is re-read for every access.
// 0x5365b0 ZDllSound::DumpObjectGroup(first, n, name): n == 0 -> nothing; report (0x6a1e2c line 0x29c, "%s %u" 0x6a1fe8);
//          for i < n: this->slot 0x1ec([this+0x5302] + [[this+0x5302] + first + 4i]); report (line 0x2a5, 0x6a1ff4).
// 0x6328b0 inflate_trees_bits(c, bb, tb, hp, z) (zlib 1.1): v = zalloc(opaque, 19, 4) or Z_MEM_ERROR (-4);
//          r = huft_build(c, 19, 19, 0, 0, tb, bb, hp, &hn, v); -3 -> msg 0x6c14c8; -5 or *bb == 0 -> msg 0x6c14f0, r = -3;
//          zfree(opaque, v); return r.
// 0x54e570 ZSoundStreamer::Run: round-robin over [this+0x1c5] streams of 0x6b bytes at +0x10 (cursor +8); stop on the
//          first stream whose Run (0x54e450) returns true, or whose +0x6a byte (copied to +0x1c9) is set (cursor steps back).
// 0x607e30 (vertex buffer ctor)(dev, fvf*, count*, usage): fields +0..+0x29; dev->slot 0x5c(dev, count*0x44,
//          usage|0x208, fvf, 0, this) (COM stdcall); return this.
// 0x42c2f0 ZSysInterface::DataPath() const: return (this+0x123) + MYSTR(0x6799f8) through the hidden return pointer.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_634273[], ext_41e290[], ext_634d22[], ext_632360[], ext_54e450[], ext_4cbe80[], ext_4cc1e0[],
    ext_4cbec0[], ext_633654[];

typedef void *(*Memcpy)(void *, const void *, u32);
#define E(o) (AT(u8 *, self, 0x14) + (o))

extern "C" void THISCALL f15_639bb0(u8 *self, void *data, u32 size, u32 a, u32 b, u32 idx, u32 copy) {
  u32 o = idx * 20;
  if (AT(u8, E(o), 0xc)) {
    ((void (*)(void *, u32))X(634273))(AT(void *, E(o), 0x10), 1);
    AT(u8, E(o), 0xc) = 0;
  }
  if ((u8)copy) {
    AT(u8, E(o), 0xc) = 1;
    void *p = ((void *(*)(u32))X(41e290))(size);
    AT(void *, E(o), 0x10) = p;
    ((Memcpy)X(634d22))(AT(void *, E(o), 0x10), data, size);
  } else {
    AT(void *, E(o), 0x10) = data;
  }
  AT(u32, E(o), 0) = size;
  AT(u32, E(o), 4) = a;
  AT(u32, E(o), 8) = b;
}

typedef void (*Rep2)(void *, u32, ...);
static inline void *report(u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, 0x6a1e2cu, line); }
static inline Rep2 rslot(void *t) { return (Rep2)AT(void *, AT(void *, t, 0), 0x2c); }

extern "C" void THISCALL f15_5365b0(u8 *self, u32 first, u32 n, u32 name) {
  if (!n) return;
  void *t = report(0x29c);
  rslot(t)(t, 0x6a1fe8u, name, n);
  u8 *base = (u8 *)(AT(u32, self, 0x5302) + first);
  for (u32 i = 0; i < n; i++) vcall<void>(self, 0x1ec, AT(u32, base, 4 * i) + AT(u32, self, 0x5302));
  t = report(0x2a5);
  rslot(t)(t, 0x6a1ff4u);
}

typedef u32 (*ZAlloc)(u32, u32, u32);
typedef void (*ZFree)(u32, u32);
extern "C" s32 f15_6328b0(u32 cc, u32 *bb, u32 tb, u32 hp, u8 *z) {
  u32 hn = 0;
  u32 v = AT(ZAlloc, z, 0x20)(AT(u32, z, 0x28), 0x13, 4);
  if (!v) return -4;
  s32 r = ((s32(*)(u32, u32, u32, u32, u32, u32, u32 *, u32, u32 *, u32))X(632360))(cc, 0x13, 0x13, 0, 0, tb, bb, hp,
                                                                                   &hn, v);
  if (r == -3) {
    AT(u32, z, 0x18) = 0x6c14c8u;
  } else if (r == -5 || *bb == 0) {
    AT(u32, z, 0x18) = 0x6c14f0u;
    r = -3;
  }
  AT(ZFree, z, 0x24)(AT(u32, z, 0x28), v);
  return r;
}

#define CUR AT(s32, self, 8)
#define CNT AT(s32, self, 0x1c5)
extern "C" void THISCALL f15_54e570(u8 *self) {
  AT(u8, self, 0x1c9) = 0;
  s32 e = CUR * 0x6b;
  if (AT(u8, self, e + 0x68) && AT(u8, self, e + 0x2c)) AT(u8, self, e + 0x69) = 1;
  for (s32 i = 0; i < CNT; i++) {
    CUR++;
    if (CUR == CNT) CUR = 0;
    e = CUR * 0x6b;
    if (!AT(u8, self, e + 0x68)) continue;
    if (((u8(THISCALL *)(void *))X(54e450))(self + 0x10 + e)) return;
    u8 al = AT(u8, self, CUR * 0x6b + 0x6a);
    AT(u8, self, 0x1c9) = al;
    if (al) {
      if (--CUR < 0) CUR = CNT - 1;
      return;
    }
  }
}

typedef void(STDCALL *CreateVB)(void *, u32, u32, u32, u32, void *);
extern "C" void *THISCALL f15_607e30(u8 *self, void *dev, u32 *fvf, u32 *cnt, u32 usage) {
  AT(u32, self, 0) = 0;
  AT(u32, self, 8) = 0;
  AT(u16, self, 0x10) = 0x100;
  AT(u32, self, 0xc) = 0;
  AT(u32, self, 4) = *cnt;
  for (int k = 0x12; k < 0x2a; k += 4) AT(u32, self, k) = 0;
  AT(u32, self, 0x12) = 0x64;
  AT(u32, self, 0x22) = *cnt * 0x44;
  AT(u32, self, 0x16) = 6;
  AT(u32, self, 0x1e) = 0;
  AT(u32, self, 0x26) = *fvf;
  u32 us = usage | 0x208;
  AT(u32, self, 0x1a) = us;
  AT(CreateVB, AT(void *, dev, 0), 0x5c)(dev, AT(u32, self, 4) * 0x44, us, AT(u32, self, 0x26), 0, self);
  return self;
}

extern "C" void *THISCALL f15_42c2f0(u8 *self, void *out) {
  u32 ck = G(u32, 0x6f5630);
  u8 s[0x80];
  ((void(THISCALL *)(void *, u32))X(4cbe80))(s, 0x6799f8u);
  ((void(THISCALL *)(void *, void *, void *))X(4cc1e0))(self + 0x123, out, s);
  ((void(THISCALL *)(void *))X(4cbec0))(s);
  ((void(FASTCALL *)(u32))X(633654))(ck);
  return out;
}

PCREG(639bb0, f15_639bb0);
PCREG(5365b0, f15_5365b0);
PCREG(6328b0, f15_6328b0);
PCREG(54e570, f15_54e570);
PCREG(607e30, f15_607e30);
PCREG(42c2f0, f15_42c2f0);
