#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_527d10(void *self, void *mat, void *out10, void *l1c, void *dir, u32 a24, u32 a28, u32 s2f0);
extern "C" void FASTCALL ext_4de040(void *mat, void *dir, void *up);
extern "C" void THISCALL ext_520450(void *self, void *p6c, void *p60, void *mat, void *out10);
extern "C" void FASTCALL ext_4de420(void *dst, void *src);
extern "C" void THISCALL ext_5233a0(void *a, void *out, u32 fbits);
extern "C" float FASTCALL ext_4e0030(void *a, void *b);
extern "C" void THISCALL ext_515930(void *self, u32 wbits, u32 b);
extern "C" void THISCALL ext_521930(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

static inline u32 cdecl2_ecx(u32 fn, u32 ecx_, u32 a, u32 b) {
  u32 r;
  __asm__ volatile("pushl %[b]; pushl %[a]; call *%%eax; addl $8,%%esp" : "=a"(r), "+c"(ecx_) : "0"(fn), [a] "r"(a), [b] "r"(b) : "edx", "memory", "cc");
  return r;
}
static inline u32 cdecl5_ecx(u32 fn, u32 ecx_, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u32 r;
  __asm__ volatile("pushl %[e]; pushl %[d]; pushl %[c]; pushl %[b]; pushl %[a]; call *%%eax; addl $20,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c), [d] "r"(d), [e] "r"(e) : "edx", "memory", "cc");
  return r;
}

// 0x521f90: thiscall(), void, /GS. Per-frame update of a projectile / effect: this slot 0x370, then the orientation matrix mat (0x24 bytes) and position out10 are built either by
// 0x527d10 (when the template flag word [[table slot 0x58(this[0x123])]+8][0x3c] has bit 0x1000) or by 0x4de040 with the position copied from this[0x5c][2..4]; an unset template id
// reports through the logger [0x700390]. 0x520450 / this slot 0x7c consume mat and out10, this+0x60/0x6c are copied to this+0x90/0x9c and replaced by out10 / mat. State this[0x2f4]
// == 1 prints a message (P slot 0x184) and, when 0x4e0030 on the 0x5233a0 result is below the image threshold [0x67da04], runs 0x515930 and switches to state 2; state 3 does the same
// check against [0x6a0674] and calls 0x521930.
extern "C" void THISCALL fn_521f90(u8 *self) {
  u8 mat[0x24];
  u8 o28[12];
  float l1c[3], out10[3];
  (*(V0 *)(vt(self) + 0x370))(self);
  u8 *A = (u8 *)rd32u(self + 0x5c);
  u32 id = rd32u(self + 0x123);
  l1c[0] = *(float *)(A + 8);
  l1c[1] = *(float *)(A + 0xc);
  l1c[2] = *(float *)(A + 0x10);
  if (id != 0) {
    u8 *E = G(u8 *, 0x70039c);
    u8 *T = (u8 *)rd32u(E + 0x9b);
    u8 *R = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, id);
    u8 *Q = (u8 *)rd32u(R + 8);
    if (rd32u(Q + 0x3c) & 0x1000) {
      u8 *A2 = (u8 *)rd32u(self + 0x5c);
      ext_527d10(self + 0x2fd, mat, out10, l1c, self + 0x2d8, rd32u(A2 + 0x24), rd32u(A2 + 0x28), rd32u(self + 0x2f0));
    } else {
      ext_4de040(mat, self + 0x2d8, 0);
      out10[0] = l1c[0];
      out10[1] = l1c[1];
      out10[2] = l1c[2];
    }
  } else {
    u8 *L = G(u8 *, 0x700390);
    u32 o = (*(V2 *)(vt(L) + 0x20))(L, 0x6a04a8, 0x21f);
    cdecl2_ecx(rd32u(vt((void *)o) + 0x30), rd32u((u8 *)o), o, 0x6a0614);
  }
  u8 *p60 = self + 0x60;
  u8 *p6c = self + 0x6c;
  ext_520450(self, p6c, p60, mat, out10);
  (*(V2 *)(vt(self) + 0x7c))(self, (u32)mat, (u32)out10);
  wr32u(self + 0x90, rd32u(p60));
  wr32u(self + 0x94, rd32u(p60 + 4));
  wr32u(self + 0x98, rd32u(p60 + 8));
  ext_4de420(self + 0x9c, p6c);
  ext_4de420(p6c, mat);
  *(float *)p60 = out10[0];
  *(float *)(p60 + 4) = out10[1];
  *(float *)(p60 + 8) = out10[2];
  u32 st = rd32u(self + 0x2f4);
  if (st == 1) {
    u8 *E = G(u8 *, 0x70039c);
    u8 *P = (u8 *)(*(V0 *)(vt(E) + 0x190))(E);
    cdecl5_ecx(rd32u(vt(P) + 0x184), (u32)(self + 0x2e4), (u32)P, 0xa, 0xb, 0x6a0644, (u32)(self + 0x2e4));
    ext_5233a0((void *)rd32u(self + 0x5c), o28, rd32u(self + 0x2f8));
    wr32u(o28 + 4, 0);
    float v = ext_4e0030(self + 0x2d8, o28);
    if (G(float, 0x67da04) > v) {
      ext_515930(self, rd32u(self + 0x2f8), self[0x2fc]);
      wr32u(self + 0x2f0, 0x3f800000);
      wr32u(self + 0x2f4, 2);
      wr32u(self + 0x216, 0);
      ext_633654(G(u32, 0x6f5630));
      return;
    }
  } else if (st == 3) {
    u8 *E = G(u8 *, 0x70039c);
    u8 *P = (u8 *)(*(V0 *)(vt(E) + 0x190))(E);
    cdecl5_ecx(rd32u(vt(P) + 0x184), (u32)(self + 0x2e4), (u32)P, 0xa, 0xb, 0x6a0658, (u32)(self + 0x2e4));
    ext_5233a0((void *)rd32u(self + 0x5c), o28, rd32u(self + 0x2f8));
    wr32u(o28 + 4, 0);
    float v = ext_4e0030(self + 0x2d8, o28);
    if (v > G(float, 0x6a0674)) ext_521930(self);
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(521f90, fn_521f90);
