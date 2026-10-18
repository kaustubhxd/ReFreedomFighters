#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);

extern "C" void THISCALL ext_563110(void *self, u32 a1, u32 a2);
extern "C" void THISCALL ext_56ad00(void *self, u32 a);
extern "C" void THISCALL ext_595440(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_4947c0(void *self, u32 a);
extern "C" void THISCALL ext_56ac30(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *eng() { return G(u8 *, 0x70039c); }
static inline u8 *tab() { return (u8 *)rd32u(eng() + 0x9b); }

// 0x56a900: thiscall(a1, a2) ret 8, always returns al = 0. After 0x563110(a1, a2): when (u8)a2 != 0 and the object-table flag lookups (slot 0x134 -> slot 0x90 for two keys) succeed and
// the name at this[0x44]+4 equals the fixed string 0x6a77bc, the global float markers [0x6ffa60] / [0x700324] are reset to 1.0 (with a console command each, engine slot 0xbc) and
// a few engine calls are made. Then it dispatches on this[0x1c5] (1: look up the entry, 3: 0x4947c0(5), 4: spawn through owner slot 0x34c, 6: scan four ids; others do nothing).
extern "C" u32 THISCALL fn_56a900(u8 *self, u32 a1, u32 a2) {
  u8 flag;
  ext_563110(self, a1, a2);
  if ((u8)a2 != 0) {
    u32 idx = rd32u(self + 0x1b4);
    if (idx != 0xffffffffu) {
      u8 *T = tab();
      u32 esi = (*(V1 *)(vt(T) + 0x58))(T, rd32u(self + idx * 4 + 0x19c));
      u8 *O = (u8 *)(*(V0 *)(vt(self) + 0x84))(self);
      (*(V1 *)(vt(O) + 0x2ec))(O, esi);
      if (rd32u(self + 0x1c5) == 4) ext_56ad00(self, rd32u(self + 0x1b4));
    }
    {
      u8 *T = tab();
      u8 *Y = (u8 *)(*(V0 *)(vt(T) + 0x134))(T);
      flag = 0;
      (*(V2 *)(vt(Y) + 0x90))(Y, 0x6a757c, (u32)&flag);
    }
    if (flag == 0) {
      u8 *T = tab();
      u8 *Y = (u8 *)(*(V0 *)(vt(T) + 0x134))(T);
      flag = 0;
      (*(V2 *)(vt(Y) + 0x90))(Y, 0x6a776c, (u32)&flag);
      if (flag == 0) goto dispatch;
    }
    {
      u8 *q = (u8 *)rd32u((u8 *)rd32u(self + 0x44) + 4);
      const u8 *s = q ? q : (const u8 *)0x67c8e8;
      const u8 *t = (const u8 *)0x6a77bc;
      int diff = 0;
      for (;;) {
        u8 c = *t;
        if (c != *s) { diff = 1; break; }
        if (c == 0) break;
        u8 c2 = t[1];
        if (c2 != s[1]) { diff = 1; break; }
        t += 2;
        s += 2;
        if (c2 == 0) break;
      }
      if (diff) goto dispatch;
    }
    ext_595440((void *)rd32u(self + 0x90), 1, 0x7fffffff);
    {
      float x = G(float, 0x6ffa60);
      if (!(x == G(float, 0x678858))) {
        u8 *E = eng();
        u8 *Z = (u8 *)(*(V0 *)(vt(E) + 0xbc))(E);
        (*(V2 *)(vt(Z) + 0x64))(Z, 0x6a77d4, 1);
        G(u32, 0x6ffa60) = 0x3f800000;
      }
    }
    {
      u8 *E = eng();
      u8 *K = (u8 *)rd32u((u8 *)rd32u(E + 0x9b) + 0xadc);
      u8 *Q = (u8 *)(*(V2 *)(vt(K) + 0x25c))(K, 0x685f44, 0);
      (*(V1 *)(vt(Q) + 0x100))(Q, 0x690428);
    }
    {
      float x = G(float, 0x700324);
      if (!(x == G(float, 0x678858))) {
        u8 *E = eng();
        u8 *Z = (u8 *)(*(V0 *)(vt(E) + 0xbc))(E);
        (*(V2 *)(vt(Z) + 0x64))(Z, 0x6a77e8, 1);
        G(u32, 0x700324) = 0x3f800000;
      }
    }
    {
      u8 *H = (u8 *)rd32u(eng() + 0x1a9f);
      if (H != 0) (*(V2 *)(vt(H) + 0xd4))(H, 5, 0x40800000);
    }
  }
dispatch:
  {
    u32 st = rd32u(self + 0x1c5);
    if (st == 1) {
      u8 *E = eng();
      u8 *G1 = (u8 *)rd32u(E + 0x1907);
      if (G1 != 0) (*(V3 *)(vt(G1) + 0xc))(G1, 0x6ec6f4, 0x6a77fc, 0);
      E = eng();
      G1 = (u8 *)rd32u(E + 0x1907);
      u32 r = (*(V1 *)(vt(G1) + 0x60))(G1, 0x6a77fc);
      wr32u(self + 0x1c9, r);
      ext_4947c0((void *)rd32u(eng() + 0x9b), 0);
      return 0;
    }
    if (st == 3) {
      ext_4947c0((void *)rd32u(eng() + 0x9b), 5);
      return 0;
    }
    if (st == 4) {
      u8 *O = (u8 *)(*(V0 *)(vt(self) + 0x84))(self);
      (*(V5 *)(vt(O) + 0x34c))(O, 0x100000, 0, rd32u(self + 0x44), 0x41200000, 0);
      return 0;
    }
    if (st == 6) {
      ext_56ac30(self);
      for (int i = 0; i < 4; i++) {
        u8 *T = tab();
        u8 *R = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(self + 0x19c + 4 * i));
        if (rd32u(R + 0x70) != 0x20) {
          u8 *O = (u8 *)(*(V0 *)(vt(self) + 0x84))(self);
          (*(V1 *)(vt(O) + 0x2ec))(O, (u32)R);
          return 0;
        }
      }
      return 0;
    }
  }
  return 0;
}
PCREG(56a900, fn_56a900);
