#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void FASTCALL ext_441940(void *a, void *b);
extern "C" void THISCALL ext_4e0d00(void *a, float f);
extern "C" void THISCALL ext_5be220(void *self, void *rec);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// cdecl log call M.vtable[0x2c](M, fmt) with ecx = the vtable pointer, caller cleans 8 bytes
static inline void logcall(u8 *M) {
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  asm volatile(
      "pushl %[f]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $8, %%esp"
      : "+a"(ra), "+c"(rc)
      : [f] "r"(0x6b3638), [m] "r"(M)
      : "edx", "memory", "cc");
}

// samples the bounding vector of a0's part number idx: V = (0, 0, 0); X = table slot 0x58(a0->[0x18] slot 0x30(idx)); X slot 0x84(&V)
static inline u8 *part(u8 *a0, u32 idx, float *v) {
  u8 *O = (u8 *)rd32u(a0 + 0x18);
  u32 id = (*(V1 *)(vt(O) + 0x30))(O, idx);
  u8 *T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
  u8 *X = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, id);
  (*(V1 *)(vt(X) + 0x84))(X, (u32)v);
  return X;
}

// 0x5bef80: thiscall(a0, b, f, c, d, e) ret 0x18, /GS protected, void. this[0x90c] is the record count: at 0x1e or more only a log line is written (log manager [0x700390] slot
// 0x20(0x6b35ec, 0x76), cdecl line 0x6b3638 with ecx = vtable). Otherwise record R = this + 0x4c + count * 0x3a is filled: R[0] = a0, R[4] = a0->[0x18] slot 0x14() (signed byte),
// R[5] = d, R[6] = c, R[7] = b, R[8] = 0, float f at R+9, R[0xd] = 0, R[0x39] = e; the part-0 vector (a0->[0x18] slot 0x30(0) -> table slot 0x58 -> slot 0x84) seeds R+0x11/0x15 (min/max x),
// 0x19/0x1d (y), 0x21/0x25 (z) and R+0x29/0x2d/0x31; for parts 1 .. R[4]-1 (signed) the vector is added into R+0x29 (0x441940) and widens the min/max boxes. Then 0x4e0d00(R+0x29, 1.0f /
// (float)R[4]), R_f[0x35] = tick * 2^-10 ([[0x70039c]+0x40]), 0x5be220(this, R) and this[0x90c]++.
extern "C" void THISCALL fn_5bef80(u8 *self, u8 *a0, u32 b, float f, u32 c, u32 d, u32 e) {
  s32 cnt = (s32)rd32u(self + 0x90c);
  if (cnt >= 0x1e) {
    void *Lg = G(void *, 0x700390);
    u8 *M = (u8 *)(*(V2 *)(vt(Lg) + 0x20))(Lg, 0x6b35ec, 0x76);
    logcall(M);
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  u8 *R = self + 0x4c + (u32)cnt * 0x3a;
  wr32u(R, (u32)a0);
  u8 *O = (u8 *)rd32u(a0 + 0x18);
  R[4] = (u8)(*(V0 *)(vt(O) + 0x14))(O);
  R[5] = (u8)d;
  R[6] = (u8)c;
  R[7] = (u8)b;
  wrf(R + 9, f);
  R[0x39] = (u8)e;
  R[8] = 0;
  wr32u(R + 0xd, 0);
  float L[3] = {0.0f, 0.0f, 0.0f};
  part(a0, 0, L);
  wrf(R + 0x15, L[0]);
  wrf(R + 0x11, L[0]);
  wrf(R + 0x1d, L[1]);
  wrf(R + 0x19, L[1]);
  wrf(R + 0x25, L[2]);
  wrf(R + 0x21, L[2]);
  wrf(R + 0x29, L[0]);
  wrf(R + 0x2d, L[1]);
  wrf(R + 0x31, L[2]);
  s32 idx = 1;
  if ((s8)R[4] > 1) {
    do {
      float M3[3] = {0.0f, 0.0f, 0.0f};
      part(a0, (u32)idx, M3);
      ext_441940(R + 0x29, M3);
      if (rdf(R + 0x11) > M3[0])
        wrf(R + 0x11, M3[0]);
      else if (M3[0] > rdf(R + 0x15))
        wrf(R + 0x15, M3[0]);
      if (rdf(R + 0x19) > M3[1])
        wrf(R + 0x19, M3[1]);
      else if (M3[1] > rdf(R + 0x1d))
        wrf(R + 0x1d, M3[1]);
      if (rdf(R + 0x21) > M3[2])
        wrf(R + 0x21, M3[2]);
      else if (M3[2] > rdf(R + 0x25))
        wrf(R + 0x25, M3[2]);
      idx++;
    } while (idx < (s32)(s8)R[4]);
  }
  float inv = G(float, 0x678858) / (float)(s32)(s8)R[4];
  ext_4e0d00(R + 0x29, inv);
  u8 *eng = G(u8 *, 0x70039c);
  wrf(R + 0x35, (float)(s32)rd32u(eng + 0x40) * G(float, 0x6785e4));
  ext_5be220(self, R);
  wr32u(self + 0x90c, rd32u(self + 0x90c) + 1);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5bef80, fn_5bef80);
