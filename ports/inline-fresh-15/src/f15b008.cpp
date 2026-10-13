// f15b008.cpp - fresh slice 15, batch 8 (2026-10-12).
// 0x5ab4f0 CMessageBasics::~CMessageBasics (deleting): vt 0x6b01f4; delete +0x6a (slot 0(1)); free the 16-byte-element
//          vector at +0x6e (0x54f870(this+0x6e: begin, (cap-begin) & ~15) when not empty); vt 0x6b01dc; flags&1 -> delete(this, 0xa8).
// 0x4fbc30: factory (allocator slot 0x44(ecx)), base 0x469870, +4 |= 0x20, +0x44 = 0, vt 0x69c4b0, REFTAB32 at +0x98, byte +0x69 = 0.
// 0x57cd30 (CopyEventDataBlock-style)(rd): ZSoundController::CopyData; +0x180, +0x184 = (u32)rd; a, b = (u32)rd;
//          +0x318 = db slot 0x58(a); +0x18c = db slot 0x58(b); +0x188 = (u32)rd.
// 0x4910b0 ZEngineDataBase::GetStaticSize / 0x491470 GetWaveDataSize: s = CalcCacheFileName(name 0x68d844 / 0x68d858)
//          (MYSTR returned through a hidden pointer); r = [0x700394] slot 0x30(s.c_str(), 0); ~MYSTR(s); return r.
//          The 0 is pushed before the c_str call (0x4cc1d0, plain ret) and becomes slot 0x30's second argument.
// 0x522d30: p = new(0x20); p -> ctor 0x51a9f0(p, this), vt 0x6a06f4, p+0x1c = this, [0x701a78] == 0 -> 0x522c50(p); return p.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_54f870[], ext_634273[], ext_469870[], ext_4ccba0[], ext_610100[], ext_4e5e60[], ext_48c4b0[],
    ext_4cc1d0[], ext_4cbec0[], ext_41e290[], ext_51a9f0[], ext_522c50[], ext_633654[];

typedef void (*Del)(void *, u32);
static inline void *db() { return AT(void *, G(u8 *, 0x70039c), 0x9b); }

extern "C" void *THISCALL f15_5ab4f0(u8 *self, u32 flags) {
  AT(u32, self, 0) = 0x6b01f4u;
  void *o = AT(void *, self, 0x6a);
  if (o) vcall<void>(o, 0, 1u);
  u8 *v = self + 0x6e;
  s32 n = (s32)(AT(u32, v, 8) - AT(u32, v, 0)) >> 4;
  if (n) ((void(THISCALL *)(void *, u32, u32))X(54f870))(v, AT(u32, v, 0), (u32)n << 4);
  AT(u32, self, 0) = 0x6b01dcu;
  if (flags & 1) ((Del)X(634273))(self, 0xa8);
  return self;
}

extern "C" void *THISCALL f15_4fbc30(u32 ecx) {
  void *a = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 8);
  u8 *o = vcall<u8 *>(a, 0x44, ecx);
  if (o) {
    ((void(THISCALL *)(void *))X(469870))(o);
    AT(u32, o, 4) |= 0x20;
    AT(u32, o, 0x44) = 0;
    AT(u32, o, 0) = 0x69c4b0u;
    ((void(THISCALL *)(void *))X(4ccba0))(o + 0x98);
    AT(u8, o, 0x69) = 0;
  }
  return o;
}

typedef u32(THISCALL *Get0)(void *);
extern "C" void THISCALL f15_57cd30(u8 *self, void *rd) {
  ((void(THISCALL *)(void *, void *))X(610100))(self, rd);
  AT(u32, self, 0x180) = ((Get0)X(4e5e60))(rd);
  AT(u32, self, 0x184) = ((Get0)X(4e5e60))(rd);
  u32 a = ((Get0)X(4e5e60))(rd);
  u32 b = ((Get0)X(4e5e60))(rd);
  AT(u32, self, 0x318) = vcall<u32>(db(), 0x58, a);
  AT(u32, self, 0x18c) = vcall<u32>(db(), 0x58, b);
  AT(u32, self, 0x188) = ((Get0)X(4e5e60))(rd);
}

static inline u32 cache_size(u32 name) {
  u32 ck = G(u32, 0x6f5630);
  u8 s[0x80];
  ((void(STDCALL *)(void *, u32))X(48c4b0))(s, name);
  void *f = G(void *, 0x700394);
  u32 str = ((Get0)X(4cc1d0))(s);
  u32 r = vcall<u32>(f, 0x30, str, 0u);
  ((void(THISCALL *)(void *))X(4cbec0))(s);
  ((void(FASTCALL *)(u32))X(633654))(ck);
  return r;
}
extern "C" u32 f15_4910b0() { return cache_size(0x68d844u); }
extern "C" u32 f15_491470() { return cache_size(0x68d858u); }

extern "C" void *THISCALL f15_522d30(void *self) {
  u8 *p = ((u8 * (*)(u32)) X(41e290))(0x20);
  if (!p) return 0;
  ((void(THISCALL *)(void *, void *))X(51a9f0))(p, self);
  AT(u32, p, 0) = 0x6a06f4u;
  AT(void *, p, 0x1c) = self;
  if (G(u32, 0x701a78) == 0) ((void(THISCALL *)(void *))X(522c50))(p);
  return p;
}

PCREG(5ab4f0, f15_5ab4f0);
PCREG(4fbc30, f15_4fbc30);
PCREG(57cd30, f15_57cd30);
PCREG(4910b0, f15_4910b0);
PCREG(491470, f15_491470);
PCREG(522d30, f15_522d30);
