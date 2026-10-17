#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef u32(THISCALL *V4)(void *, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" double VECTORCALL ext_634d7c(double x);  // sqrt
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *table() { return (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b); }

// 0x5bd380: thiscall(code, b) ret 8, returns 0, /GS protected: when the table slot 0x114(0x6b2da8, 0, 0x6b334c, 0x2c) (a u16) equals code the embedded list this+0x4c is walked
// (slot 0x4c(&it) then slot 0x5c(&it) per item while it[0] != 0; a zero item is skipped): per item a counter is incremented, Y = table slot 0x58(item), Z = table slot 0x58(b[4])
// is stored in this[0x48], Z slot 0x80(&Q, &P), Y slot 0x80(&Q, &R), V = P - R (0x43e920) and len = float(sqrt(|V|^2)) (CRT wrapper 0x634d7c); when [0x67d164] > len the actor this[0x44]
// slot 0x12c(item, table slot 0x114(0x6a4e1c, 0, 0x6b334c, 0x47) as u16, 0) is called and the counter is logged (line 0x48, format 0x6b32f0). Finally Z' = this[0x48] slot 0x20() slot 0x2f0(0, 0, 1)
// and, when this[0x48] slot 0x20() is still nonzero, its slot 0x210(1).
extern "C" u32 THISCALL fn_5bd380(u8 *self, u32 code, u8 *b) {
  float P[3], Q[3], R[3], V[3];
  u32 it[3];
  u32 counter = 0;
  {
    u8 *T = table();
    u32 r = (*(V4 *)(vt(T) + 0x114))(T, 0x6b2da8, 0, 0x6b334c, 0x2c);
    if ((u16)code != (u16)r) {
      ext_633654(G(u32, 0x6f5630));
      return 0;
    }
  }
  u8 *L = self + 0x4c;
  bool walk = L != nullptr;
  if (walk) {
    (*(V1 *)(vt(L) + 0x4c))(L, (u32)it);
    u8 *item = (u8 *)(*(V1 *)(vt(L) + 0x5c))(L, (u32)it);
    while (it[0] != 0) {
      if (item) {
        counter++;
        u8 *T = table();
        u8 *Y = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, (u32)item);
        V[0] = V[1] = V[2] = 0.0f;
        T = table();
        u8 *Z = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(b + 4));
        wr32u(self + 0x48, (u32)Z);
        (*(V2 *)(vt(Z) + 0x80))(Z, (u32)Q, (u32)P);
        (*(V2 *)(vt(Y) + 0x80))(Y, (u32)Q, (u32)R);
        ext_43e920(V, P, R);
        float s = V[1] * V[1];
        float t = V[0] * V[0];
        s = s + t;
        float u = V[2] * V[2];
        s = s + u;
        float len = (float)ext_634d7c((double)s);
        if (G(float, 0x67d164) > len) {
          u8 *W = (u8 *)rd32u(self + 0x44);
          u8 *wv = vt(W);
          u8 *T2 = table();
          u32 res = (*(V4 *)(vt(T2) + 0x114))(T2, 0x6a4e1c, 0, 0x6b334c, 0x47);
          (*(V3 *)(wv + 0x12c))((void *)rd32u(self + 0x44), (u32)item, (u16)res, 0);
          void *Lg = G(void *, 0x700390);
          u8 *M = (u8 *)(*(V2 *)(vt(Lg) + 0x20))(Lg, 0x6b334c, 0x48);
          u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
          asm volatile(
              "pushl %[c]\n\t"
              "pushl %[f]\n\t"
              "pushl %[m]\n\t"
              "call *%%eax\n\t"
              "addl $12, %%esp"
              : "+a"(ra), "+c"(rc)
              : [c] "r"(counter), [f] "r"(0x6b32f0), [m] "r"(M)
              : "edx", "memory", "cc");
        }
      }
      item = (u8 *)(*(V1 *)(vt(L) + 0x5c))(L, (u32)it);
    }
  }
  {
    u8 *Zt = (u8 *)rd32u(self + 0x48);
    u8 *O = (u8 *)(*(V0 *)(vt(Zt) + 0x20))(Zt);
    (*(V3 *)(vt(O) + 0x2f0))(O, 0, 0, 1);
    Zt = (u8 *)rd32u(self + 0x48);
    u8 *O2 = (u8 *)(*(V0 *)(vt(Zt) + 0x20))(Zt);
    if (O2) (*(V1 *)(vt(O2) + 0x210))(O2, 1);
  }
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(5bd380, fn_5bd380);
