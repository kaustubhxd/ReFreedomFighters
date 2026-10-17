#include "ff.h"

extern "C" u32 THISCALL ext_591b20(void *body);
extern "C" void THISCALL ext_4e09b0(void *v);
extern "C" u32 FASTCALL ext_4e0130(void *self, void *edx_vec, void *v, float t);  // edx = this+0xa72 as well: left over from the caller's lea
extern "C" void STDCALL ext_5cf820(void *yaw, void *pitch, void *vec);
extern "C" void FASTCALL ext_633654(u32 cookie);

typedef void(THISCALL *V2)(void *, void *, void *);
typedef u32(THISCALL *V2u)(void *, u32, u32);
typedef u32(THISCALL *V1u)(void *, u32);

static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float cf(u32 addr) { return *(const float *)addr; }

// cdecl vararg vcall of slot `off` (M's vtable pointer in ecx) with a double after the format string
static void vt_log_double(void *M, u32 off, u32 fmt, double d) {
  u32 vtp = *(u32 *)M, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("subl $8, %%esp\n\tmovsd %[d], (%%esp)\n\tpushl %[f]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $16, %%esp"
               : "+a"(ra), "+c"(rc)
               : [d] "x"(d), [f] "r"(fmt), [o] "r"(M)
               : "edx", "memory", "cc");
}

// 0x5d1530: thiscall(), /GS. The aim controller of this (body B = this[0x44]): kind (0x591b20) must be 9, else this[0xb1a] = 1. B slot 0x80(this+0xcdd, &tmp) fills the aim vector this[0xcdd];
// in the "snap" state (this[0xb1a] != 0) the yaw / pitch pair (this+0xa54 / 0xa5c) is rebuilt by 0x4e0130(this+0xa72, &v, dt * [0x68aef8]) + 0x5cf820 and the state is left when
// 0x4e0130 reports done; otherwise the pitch follows the aim within [0x6a0bd0 .. 0x6b4fa4], the yaw difference is wrapped into (-pi .. pi) (assert log via [0x700390] when
// below [0x67af28]) and limited by the limit of the cached object this[0xbd1] (table slot 0x58(B[0x84a]) -> slot 0x100(0x6b48f8)).
static void body_5d1530(u8 *self) {
  u8 fr[0x40];
  __builtin_memset(fr, 0xcc, sizeof fr);
#define EBP (fr + 0x30)
#define P(off) (EBP - (off))
  u8 *B = (u8 *)R32(self + 0x44);
  if (ext_591b20(B) != 9) {
    self[0xb1a] = 1;
    return;
  }
  W32(P(0x28), 0);
  u8 *aim = self + 0xcdd;
  (*(V2 *)(*(u8 **)B + 0x80))(B, aim, P(0x1c));
  WF(P(0x10), RF(aim));
  WF(P(0xc), RF(aim + 4));
  WF(P(8), RF(aim + 8));
  ext_4e09b0(P(0x10));
  float two_pi = cf(0x68aef8);
  if (self[0xb1a]) {
    W32(self + 0xbd1, 0);
    u8 *E = G(u8 *, 0x70039c);
    float t = RF(E + 0x48) * two_pi;
    u8 done = (u8)ext_4e0130(self + 0xa72, self + 0xa72, P(0x10), t);
    ext_5cf820(self + 0xa54, self + 0xa5c, self + 0xa72);
    WF(self + 0xae9, RF(self + 0xa54));
    W32(self + 0xaed, R32(self + 0xa5c));
    if (done) self[0xb1a] = 0;
    return;
  }
  ext_5cf820(P(0x28), P(0x20), P(0x10));
  float pitch_cur = RF(self + 0xa5c);
  float out_pitch = RF(P(0x20));
  float d = pitch_cur - out_pitch;
  if (cf(0x6a0bd0) > d) {
    WF(self + 0xa5c, out_pitch - cf(0x6a0bc8));
  } else if (d > cf(0x6b4fa4)) {
    WF(self + 0xa5c, out_pitch + cf(0x6b4fa4));
  }
  float yaw_cur = RF(self + 0xa54);
  float yaw = RF(P(0x28));
  if (yaw > yaw_cur) yaw_cur = yaw_cur + two_pi;
  float e = yaw_cur - yaw;
  WF(P(0x20), e);
  if (cf(0x67af28) > e) {
    u8 *L = G(u8 *, 0x700390);
    u8 *M = (u8 *)(*(V2u *)(*(u8 **)L + 0x20))(L, 0x6b4d68, 0x8f);
    vt_log_double(M, 0x2c, 0x6b4db8, (double)RF(P(0x20)));
    e = RF(P(0x20));
  }
  float pi = cf(0x67da18);
  if (e > pi)
    e = e - two_pi;
  else if (cf(0x6ad238) > e)
    e = e + two_pi;
  WF(P(0x20), e);
  if (R32(self + 0xbd1) == 0) {
    u8 *E = G(u8 *, 0x70039c);
    u8 *T = (u8 *)R32(E + 0x9b);
    u8 *Q = (u8 *)(*(V1u *)(*(u8 **)T + 0x58))(T, R32(B + 0x84a));
    u32 r = (*(V1u *)(*(u8 **)Q + 0x100))(Q, 0x6b48f8);
    W32(self + 0xbd1, r);
  }
  u8 *obj = (u8 *)R32(self + 0xbd1);
  float lim;
  if (obj) {
    lim = RF(obj + 0x48);
    if (lim > cf(0x6ad1fc))
      lim = pi;
    else if (cf(0x6ad234) > lim)
      lim = pi;
  } else {
    lim = cf(0x6b4fa8);
  }
  float neg = -lim;
  e = RF(P(0x20));
  if (neg > e) {
    float v = yaw - lim;
    if (v > pi)
      v = v - two_pi;
    else if (cf(0x6ad238) > v)
      v = v + two_pi;
    WF(self + 0xa54, v);
    return;
  }
  if (e > lim) {
    float v = lim + yaw;
    if (v > pi)
      v = v - two_pi;
    else if (cf(0x6ad238) > v)
      v = v + two_pi;
    WF(self + 0xa54, v);
  }
}
extern "C" void THISCALL fn_5d1530(u8 *self);
extern "C" void THISCALL fn_5d1530(u8 *self) {
  body_5d1530(self);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5d1530, fn_5d1530);
