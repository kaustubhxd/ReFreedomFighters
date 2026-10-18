#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void THISCALL ext_562260(void *self);
extern "C" void THISCALL ext_57f960(void *m);
extern "C" void THISCALL ext_57f9b0(void *src, void *a, void *m);
extern "C" void THISCALL ext_565360(void *self, void *m);
extern "C" void THISCALL ext_565100(void *self, u32 a);
extern "C" void THISCALL ext_564600(void *self, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline int limit(u8 *self) {
  float f;
  __builtin_memcpy(&f, self + 0xca6, 4);
  f = f * G(float, 0x678620);
  return (int)f;
}
static inline int engtime() { return (int)rd32u(G(u8 *, 0x70039c) + 0x30); }

// 0x564700: per-tick state machine of a controller (thiscall(), void). self[0x18b]: flush mode (the owner's list at owner+0xcb is walked n times, calling owner slot 0x300 each
// time). Otherwise, while mode ebx = self[0xc9a] != 0xa and self[0xdc] == 2, a jump table over self[0x184] (2, 4, 8, 16, 32) picks one of five handlers that advance the step
// counter self[0xc96]; state 0xa (or not mode 2) polls the child object's slot 0x10 and calls 0x564600 on the rising edge.
extern "C" void THISCALL fn_564700(u8 *self) {
  u8 M[0x2c];
  u32 ebx, e;
  u8 *edi = self + 0x184;
  if (self[0x18b] != 0) {
    u8 *O = (u8 *)(*(V0 *)(vt(self) + 0x84))(self);
    u8 *sub = O + 0xcb;
    u32 n = (*(V0 *)(vt(sub) + 0x14))(sub);
    while (n != 0) {
      u8 *Z = (u8 *)(*(V0 *)(vt(self) + 0x84))(self);
      (*(V0 *)(vt(Z) + 0x300))(Z);
      n--;
    }
    self[0x18b] = 0;
    return;
  }
  ext_562260(self);
  ebx = rd32u(self + 0xc9a);
  if (ebx == 0xa || rd32u(self + 0xdc) != 2) goto alt;
  e = rd32u(self + 0x184) - 2;
  if (e > 0x1e) goto dflt;
  switch (e) {
  case 0: goto sA;
  case 2: goto sB;
  case 6: goto sC;
  case 14: goto sD;
  case 30: goto sE;
  default: goto dflt;
  }
sA:
  if (self[0x189] == 0) goto sA2;
  if (engtime() <= limit(self)) goto sA1;
  goto L5647c9;
sA1:
  if (rd32u(self + 0xc8a) == 1) goto dflt;
  {
    u8 *ch = (u8 *)rd32u(self + 0xc5e);
    u32 r = (*(V0 *)(vt(ch) + 0x10))(ch);
    if (r != 1) goto dflt;
    wr32u(self + 0xc96, rd32u(self + 0xc96) + 1);
    self[0x188] = 0;
    wr32u(self + 0xc8a, r);
    return;
  }
L5647c9:
  if (self[0x188] == 0) {
    ext_565100(self, rd32u(self + 0xc8a));
    wr32u(self + 0xc96, rd32u(self + 0xc96) + 1);
    return;
  }
  ext_57f960(M);
  ext_57f9b0(self + 0x5a6 + rd32u(self + 0xc9a) * 0xac, edi, M);
  if (rd32u(edi) != 0x20) ext_565360(self, M);
  wr32u(self + 0xc96, 0);
  wr32u(self + 0xc96, rd32u(self + 0xc96) + 1);
  self[0x189] = 0;
  return;
sA2:
  if (rd32u(self + 0xc96) != 2) goto dflt;
  {
    u8 *ch = (u8 *)rd32u(self + 0xc5e);
    wr32u(self + 0xc8a, 0x19);
    u8 al = (u8)(*(V2 *)(vt(ch) + 8))(ch, ebx, (u32)(self + 0xc8a));
    wr32u(self + 0xc96, rd32u(self + 0xc96) + 1);
    self[0x188] = al;
    self[0x189] = 1;
    return;
  }
sB:
  if (self[0x189] == 0) goto sB2;
  if (engtime() <= limit(self)) goto dflt;
  goto L5647c9;
sB2:
  if (rd32u(self + 0xc96) != 2) goto dflt;
  {
    u8 *ch = (u8 *)rd32u(self + 0xc5e);
    wr32u(self + 0xc8a, 0x19);
    u8 al = (u8)(*(V2 *)(vt(ch) + 0xc))(ch, ebx, (u32)(self + 0xc8a));
    wr32u(self + 0xc96, rd32u(self + 0xc96) + 1);
    self[0x188] = al;
    self[0x189] = 1;
    return;
  }
sC:
  if (self[0x189] != 0) goto L5647c9;
  if (rd32u(self + 0xc96) != 2) goto dflt;
  {
    u8 *T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    (*(V1 *)(vt(T) + 0x28))(T, (u32)(self + 0x180));
    wr32u(self + 0xc96, rd32u(self + 0xc96) + 1);
    return;
  }
sD:
  if (engtime() < limit(self)) goto dflt;
sE:
  wr32u(self + 0xc82, rd32u(self + ebx * 0xac + 0x64e));
  wr32u(self + 0xc9a, 0xa);
  (*(V1 *)(vt(self) + 0x100))(self, 0);
dflt:
  wr32u(self + 0xc96, rd32u(self + 0xc96) + 1);
  return;
alt:
  if (self[0x85] != 0) return;
  {
    u8 *ch = (u8 *)rd32u(self + 0xc5e);
    u32 r = (*(V0 *)(vt(ch) + 0x10))(ch);
    if (rd32u(self + 0xc8e) == 1 && r != 1) {
      u32 c = rd32u(self + 0xc9e);
      if (c != 0xa) ext_564600(self, c);
    }
    wr32u(self + 0xc8e, r);
  }
}
PCREG(564700, fn_564700);
