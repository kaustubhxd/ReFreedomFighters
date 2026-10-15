// batch32090.cpp - cascade h2 (Sonnet): eight tier C wrappers (tenth batch).
#include "ff.h"

extern "C" void THISCALL ext_45fd20(u8 *self, u32 a);                  // thunk, thiscall ret 4
extern "C" void THISCALL ext_45fc80(u8 *self, u32 a, u32 b);           // thunk, thiscall ret 8
extern "C" void THISCALL ext_4ad3a0(u8 *self, u8 *p);                  // thiscall ret 4
extern "C" void THISCALL ext_4e6330(u8 *self, u8 *p);                  // thiscall ret 4
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                          // thiscall, plain ret
extern "C" u32 THISCALL ext_4e5e40(u8 *self);                          // thiscall, plain ret
extern "C" void THISCALL ext_562440(u8 *self);                         // thiscall, plain ret
extern "C" u32 THISCALL ext_563510(u8 *self, u32 a);                   // thiscall ret 4
extern "C" void THISCALL ext_563610(u8 *self, u32 a);                  // thiscall ret 4
extern "C" void THISCALL ext_5d0f10(u8 *self);
extern "C" void THISCALL ext_5d2eb0(u8 *self);
extern "C" void THISCALL ext_5d2ab0(u8 *self);
extern "C" void THISCALL ext_5d1530(u8 *self);
extern "C" void THISCALL ext_5d2080(u8 *self);
extern "C" void THISCALL ext_5d2280(u8 *self);
extern "C" void THISCALL ext_5cd890(u8 *self);
extern "C" u32 THISCALL ext_5ce0b0(u8 *self);                          // thiscall, plain ret (tail jump target)
extern "C" void THISCALL ext_658140(u8 *self);                         // thiscall, plain ret
typedef u32 (STDCALL *s1_t)(u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x47fad0, thiscall(a) ret 4: 0x45fd20(this, a); o = engine table slot 0x58 with [this+0x18]; o != 0 -> tail jump to slot 0x70 of o with a; else 0.
static u32 THISCALL fn47fad0(u8 *self, u32 a) {
  ext_45fd20(self, a);
  void *o = vcall<void *>(engTable(), 0x58, *(u32 *)(self + 0x18));
  if (!o) return 0;
  return vcall<u32>(o, 0x70, a);
}
PCREG(47fad0, fn47fad0);

// 0x47fa90, thiscall(a, b) ret 8: 0x45fc80(this, a, b); o = engine table slot 0x58 with [this+0x18]; o != 0 -> tail jump to slot 0x74 of o with (a, b); else 0.
static u32 THISCALL fn47fa90(u8 *self, u32 a, u32 b) {
  ext_45fc80(self, a, b);
  void *o = vcall<void *>(engTable(), 0x58, *(u32 *)(self + 0x18));
  if (!o) return 0;
  return vcall<u32>(o, 0x74, a, b);
}
PCREG(47fa90, fn47fa90);

// 0x4abc00, thiscall no args: e = object embedded at this+0x6e; slot 0x14 of e != 0 -> 0x4ad3a0(this, e), then tail jump to slot 0xc of e; else 0.
static u32 THISCALL fn4abc00(u8 *self) {
  u8 *e = self + 0x6e;
  if (!vcall<u32>(e, 0x14)) return 0;
  ext_4ad3a0(self, e);
  return vcall<u32>(e, 0xc);
}
PCREG(4abc00, fn4abc00);

// 0x4b16e0, thiscall(a) ret 4: 0x4e6330(a, this+0x4a); [this+0xf6] = 0x4e5e60(a) (unaligned); word [this+0x48] = AX of 0x4e5e40(a).
static void THISCALL fn4b16e0(u8 *self, u8 *a) {
  ext_4e6330(a, self + 0x4a);
  wr32(self + 0xf6, ext_4e5e60(a));
  u32 w = ext_4e5e40(a);
  self[0x48] = w;
  self[0x49] = w >> 8;
}
PCREG(4b16e0, fn4b16e0);

// 0x4f70a0, thiscall no args: P = [this+0x93] (unaligned) != 0 -> byte [this+0xa7] = 0; slot 0xb8 of [[0x70039c]+0x190f] (unaligned) with P; r = slot 0x2c4 of this; slot 0x330 of r with [this+0x93].
static void THISCALL fn4f70a0(u8 *self) {
  u32 P = rd32(self + 0x93);
  if (!P) return;
  self[0xa7] = 0;
  u8 *eng = G(u8 *, 0x70039c);
  void *o = (void *)rd32(eng + 0x190f);
  vcall<void>(o, 0xb8, P);
  void *r = vcall<void *>(self, 0x2c4);
  vcall<void>(r, 0x330, rd32(self + 0x93));
}
PCREG(4f70a0, fn4f70a0);

// 0x567050, thiscall no args: 0x562440(this); 0x563510(this, 0x6a6f98); 0x563610(this, 0x6a6fa0); [this+0x194] = engine table slot 0x58 with [this+0x190]; returns 0x563510(this, 0x6a6f98).
static u32 THISCALL fn567050(u8 *self) {
  ext_562440(self);
  ext_563510(self, 0x6a6f98);
  ext_563610(self, 0x6a6fa0);
  *(u32 *)(self + 0x194) = vcall<u32>(engTable(), 0x58, *(u32 *)(self + 0x190));
  return ext_563510(self, 0x6a6f98);
}
PCREG(567050, fn567050);

// 0x5ceb70, thiscall no args: byte [this+0xb46] = 0; [this+0xa4c] = 2; seven plain thiscalls on this in order (0x5d0f10, 0x5d2eb0, 0x5d2ab0, 0x5d1530, 0x5d2080, 0x5d2280, 0x5cd890); tail jump to 0x5ce0b0(this).
static u32 THISCALL fn5ceb70(u8 *self) {
  self[0xb46] = 0;
  *(u32 *)(self + 0xa4c) = 2;
  ext_5d0f10(self);
  ext_5d2eb0(self);
  ext_5d2ab0(self);
  ext_5d1530(self);
  ext_5d2080(self);
  ext_5d2280(self);
  ext_5cd890(self);
  return ext_5ce0b0(self);
}
PCREG(5ceb70, fn5ceb70);

// 0x608d60, thiscall no args, bool: byte [0x724b34] != 0 -> false; 0x658140(this); o = [this+0x1377] (unaligned); r = slot 0x88 of o (stdcall, 1 arg o); r < 0 (signed) -> false;
// else byte [this+0x13ec] = 1; [0x724a00] = [this+0x1377]; true.
static bool THISCALL fn608d60(u8 *self) {
  if (G(u8, 0x724b34)) return false;
  ext_658140(self);
  u32 o = rd32(self + 0x1377);
  s32 r = (s32)(*(s1_t *)(*(u8 **)o + 0x88))(o);
  if (r < 0) return false;
  u32 o2 = rd32(self + 0x1377);
  self[0x13ec] = 1;
  G(u32, 0x724a00) = o2;
  return true;
}
PCREG(608d60, fn608d60);
