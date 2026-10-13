// batch2616.cpp - wider batch 2616: sixteen unclaimed functions (GUESS names). Cookie checks / SEH frames that restore ESI are not reproduced; 0x4859c0 uses the naked frame of area 24 batch 2499.
#include "ff.h"

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])
typedef u32(THISCALL *vf0_t)(void *);
typedef u32(THISCALL *vf1_t)(void *, u32);
typedef u32(THISCALL *vf2_t)(void *, u32, u32);
typedef u32(THISCALL *vf2p_t)(void *, u32, void *);
static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline u8 *U8(u32 v) { return (u8 *)v; }

extern "C" void ext_634273(void *p, u32 n);
extern "C" void THISCALL ext_4dc5d0(void *self, u32 a, u32 b, u32 c);     // ret 0xc
extern "C" u32 THISCALL ext_4dd060(void *self, u32 *p);                    // ret 4
extern "C" void THISCALL ext_4dce50(void *self, u32 a);                    // ret 4
extern "C" void THISCALL ext_45c3a0(void *self, u32 a, u32 b, u32 c);      // ret 0xc
extern "C" void THISCALL ext_4609b0(void *self);
extern "C" void THISCALL ext_43de70(void *self);
extern "C" void ext_45c510(void *self);                                    // cdecl, 1 arg
extern "C" void ext_4690b0(void *self, u32 n);                             // bare ret
extern "C" void THISCALL ext_43ea20(void *self);
extern "C" void THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c);      // ret 0xc
extern "C" void THISCALL ext_451a00(void *self);
extern "C" void THISCALL ext_610100(void *self, void *obj);                // ret 4
extern "C" void THISCALL ext_4e12f0(void *self, void *p, u32 n);           // ret 8
extern "C" void THISCALL ext_4e1b30(void *self);
extern "C" u32 THISCALL ext_45f3c0(void *self, u32 a);                     // ret 4
extern "C" void THISCALL ext_469870(void *self);
extern "C" double VECTORCALL ext_634d7c(double);                           // sqrt through the IAT

// ---- 0x449730 / 0x449b50 / 0x449bc0 / 0x449c30: fill a local record through slot S1 of the object at [[engine+0x1aa3]+0x18], set one float, apply through slot S2.
static inline void *recObj() { return *(void **)(*(u8 **)(*(u8 **)(sysp() + 0x1aa3) + 0x18) + 0); }
static inline u8 *recTab() { return *(u8 **)(*(u8 **)(sysp() + 0x1aa3) + 0x18); }
static inline u32 recIdx(u8 *self) { return *(u32 *)(*(u8 **)(self + 8) + 0x6c); }

static void THISCALL fn449730(u8 *self, u32 f) {
  u8 buf[0x3c];
  VT(self, vf0_t, 0x238)(self);
  u8 *t = recTab();
  VT(t, vf2p_t, 0x88)(t, recIdx(self), buf);
  *(u32 *)(buf + 0x10) = f;
  t = recTab();
  VT(t, vf2p_t, 0xa8)(t, recIdx(self), buf);
}
PCREG(449730, fn449730);

static void THISCALL fn449b50(u8 *self, u32 f) {
  u8 buf[0x38];
  VT(self, vf0_t, 0x238)(self);
  u8 *t = recTab();
  VT(t, vf2p_t, 0x84)(t, recIdx(self), buf);
  *(u32 *)(buf + 0x14) = f;
  t = recTab();
  VT(t, vf2p_t, 0xa0)(t, recIdx(self), buf);
  VT(self, vf1_t, 0x220)(self, 1);
}
PCREG(449b50, fn449b50);

static void THISCALL fn449bc0(u8 *self, u32 f) {
  u8 buf[0x3c];
  VT(self, vf0_t, 0x238)(self);
  u8 *t = recTab();
  VT(t, vf2p_t, 0x88)(t, recIdx(self), buf);
  *(u32 *)(buf + 0x14) = f;
  t = recTab();
  VT(t, vf2p_t, 0xa8)(t, recIdx(self), buf);
  VT(self, vf1_t, 0x220)(self, 1);
}
PCREG(449bc0, fn449bc0);

static void THISCALL fn449c30(u8 *self, u32 f) {
  u8 buf[0x24];
  VT(self, vf0_t, 0x238)(self);
  u8 *t = recTab();
  VT(t, vf2p_t, 0x80)(t, recIdx(self), buf);
  *(u32 *)(buf + 0x18) = f;
  t = recTab();
  VT(t, vf2p_t, 0x98)(t, recIdx(self), buf);
}
PCREG(449c30, fn449c30);

// 0x44a0e0, thiscall no args, cookie not reproduced: obj = [this+8]; 0x4dc5d0(obj, 0, 0, 0); loc = {0,0,0}; 0x4dd060(obj, &loc); 0x4dce50(obj, 0).
static void THISCALL fn44a0e0(u8 *self) {
  u32 loc[3] = {0, 0, 0};
  ext_4dc5d0(*(void **)(self + 8), 0, 0, 0);
  ext_4dd060(*(void **)(self + 8), loc);
  ext_4dce50(*(void **)(self + 8), 0);
}
PCREG(44a0e0, fn44a0e0);

// 0x44a8c0, thiscall(a, b, c) ret 0xc, returns this, SEH frame (plain): base 0x45c3a0(this, a, b, c); vtable 0x67f874; 0x4609b0(this + 0x1c); +0x18 = 0.
static u8 *THISCALL fn44a8c0(u8 *self, u32 a, u32 b, u32 c) {
  ext_45c3a0(self, a, b, c);
  *(u32 *)self = 0x67f874;
  ext_4609b0(self + 0x1c);
  *(u32 *)(self + 0x18) = 0;
  return self;
}
PCREG(44a8c0, fn44a8c0);

// 0x44c180, thiscall(x, unused) ret 8: log object = [0x700390] slot 0x20 (0x67fe5c, 0x28e); name = [this+4] or "<NONAME>" (0x67c8e8); 0x4cc5a0 (ECX = x, four stack dwords, CALLER pops, plain ret)
// with ([[this+0xc]], name, [this+8] + 0x24, 0x67ff10) gives a string; log slot 0x2c (cdecl: log, 0x67ccc4, string).
typedef u32(THISCALL *vlg_t)(void *, u32, u32);
typedef void(__attribute__((cdecl)) * vlog_t)(void *, u32, u32);
static void THISCALL fn44c180(u8 *self, u32 x, u32) {
  void *lg = *(void **)0x700390;
  void *o = (void *)VT(lg, vlg_t, 0x20)(lg, 0x67fe5c, 0x28e);
  u32 edi = *(u32 *)(self + 8) + 0x24;
  u32 nm = *(u32 *)(self + 4);
  u32 name = nm ? nm : 0x67c8e8;
  u32 v = **(u32 **)(self + 0xc);
  u32 r;
  asm volatile("push %[a4]\n\tpush %[a3]\n\tpush %[a2]\n\tpush %[a1]\n\tcall ext_4cc5a0\n\tadd $16, %%esp"
               : "=a"(r)
               : "c"(x), [a1] "r"(v), [a2] "r"(name), [a3] "r"(edi), [a4] "i"(0x67ff10)
               : "edx", "memory", "cc");
  ((vlog_t)(*(u32 **)o)[0x2c / 4])(o, 0x67ccc4, r);
}
PCREG(44c180, fn44c180);

// 0x44d200, thiscall(a, b) ret 8, returns an index or -1: r = engine table slot 0x50(a); first i < [this+0x1c] with elem = [this+0x20][i], elem+0x10 == r and elem+0xc == b.
static u32 THISCALL fn44d200(u8 *self, u32 a, u32 b) {
  void *t = *(void **)(sysp() + 0x9b);
  u32 r = VT(t, vf1_t, 0x50)(t, a);
  u32 n = *(u32 *)(self + 0x1c);
  if (n) {
    u32 *tab = *(u32 **)(self + 0x20);
    for (u32 i = 0; i < n; i++) {
      u8 *e = (u8 *)tab[i];
      if (*(u32 *)(e + 0x10) == r && *(u32 *)(e + 0xc) == b) return i;
    }
  }
  return (u32)-1;
}
PCREG(44d200, fn44d200);

// ---- scalar deleting destructors with the common tail: bit 0 of flags -> bit 2 clear: 0x45c510(this) (cdecl), else 0x4690b0(this, size).
#define DTOR_TAIL(self, flags, size)               \
  if ((flags) & 1) {                               \
    if (!((flags) & 4))                            \
      ext_45c510(self);                            \
    else                                           \
      ext_4690b0(self, size);                      \
  }                                                \
  return self;

// 0x44ee60, thiscall(flags) ret 4, returns this: vtable 0x68110c; free([+0x8c], 2), free([+0xac], 4), free([+0xb0], 0x3c); base 0x43de70; tail (size 0xd1).
static u8 *THISCALL fn44ee60(u8 *self, u32 flags) {
  void *a = *(void **)(self + 0x8c);
  *(u32 *)self = 0x68110c;
  ext_634273(a, 2);
  ext_634273(*(void **)(self + 0xac), 4);
  ext_634273(*(void **)(self + 0xb0), 0x3c);
  ext_43de70(self);
  DTOR_TAIL(self, flags, 0xd1)
}
PCREG(44ee60, fn44ee60);

// 0x454b00, thiscall(flags) ret 4, returns this: vtable 0x6825c0; the object at +0x5c gets slot 0 with 1; base 0x43ea20; tail (size 0x60).
static u8 *THISCALL fn454b00(u8 *self, u32 flags) {
  void *o = *(void **)(self + 0x5c);
  *(u32 *)self = 0x6825c0;
  if (o) VT(o, vf1_t, 0)(o, 1);
  ext_43ea20(self);
  DTOR_TAIL(self, flags, 0x60)
}
PCREG(454b00, fn454b00);

// 0x4571f0, thiscall(a, b, c) ret 0xc, returns this: base 0x43de40(this, a, b, c); vtable 0x6832f8; field resets (+0x54 = -1.0f, +0x28..+0x30 = 100.0f, +0x20/+0x24 = -1).
static u8 *THISCALL fn4571f0(u8 *s, u32 a, u32 b, u32 c) {
  ext_43de40(s, a, b, c);
  *(u32 *)s = 0x6832f8;
  *(u32 *)(s + 0x44) = 0;
  *(u32 *)(s + 0x48) = 0;
  *(u32 *)(s + 0x4c) = 0;
  *(u32 *)(s + 0x50) = 0;
  *(u32 *)(s + 0x54) = 0xbf800000u;
  *(u32 *)(s + 0x58) = 0;
  *(u32 *)(s + 0x28) = 0x42c80000u;
  *(u32 *)(s + 0x2c) = 0x42c80000u;
  *(u32 *)(s + 0x30) = 0x42c80000u;
  *(u32 *)(s + 0x40) = 0;
  *(u32 *)(s + 0x34) = 0;
  *(u32 *)(s + 0xd0) = 0;
  *(u32 *)(s + 0xcc) = 0;
  *(u32 *)(s + 0x24) = 0xffffffffu;
  *(u32 *)(s + 0x20) = 0xffffffffu;
  *(u32 *)(s + 0x1c) = 0;
  return s;
}
PCREG(4571f0, fn4571f0);

// 0x457340, thiscall(flags) ret 4, returns this: block = [+0x4c]; vtable 0x683510; free(block, 0x70) when set; +0x50 = 0; base 0x451a00; tail (size 0xbc).
static u8 *THISCALL fn457340(u8 *self, u32 flags) {
  void *b = *(void **)(self + 0x4c);
  *(u32 *)self = 0x683510;
  if (b) ext_634273(b, 0x70);
  *(u32 *)(self + 0x50) = 0;
  ext_451a00(self);
  DTOR_TAIL(self, flags, 0xbc)
}
PCREG(457340, fn457340);

// 0x457610, thiscall no args: obj = [this+8]; 0x4dd060(obj, this + 0x28); v = [this+8]; len = sqrtf(v[0x40]^2 + v[0x44]^2 + v[0x48]^2) (CRT sqrt, in double); 0x4dce50(v, len + 1.0f).
static void THISCALL fn457610(u8 *self) {
  ext_4dd060(*(void **)(self + 8), (u32 *)(self + 0x28));
  u8 *v = *(u8 **)(self + 8);
  float a = *(float *)(v + 0x44), b = *(float *)(v + 0x40), c = *(float *)(v + 0x48);
  float s = b * b;
  a = a * a;
  c = c * c;
  s = s + a;
  s = s + c;
  float len = (float)ext_634d7c((double)s);
  len = len + G(float, 0x678858);
  ext_4dce50(v, fbits(len));
}
PCREG(457610, fn457610);

// 0x45b1c0, thiscall(obj) ret 4: 0x610100(this, obj) (ret 4 stub); 0x4e12f0(obj, this + 0x18 / 0x1c / 0x20, 1); 0x4e1b30(obj); slot 0xb4 of this with 1.
static void THISCALL fn45b1c0(u8 *self, u8 *obj) {
  ext_610100(self, obj);
  ext_4e12f0(obj, self + 0x18, 1);
  ext_4e12f0(obj, self + 0x1c, 1);
  ext_4e12f0(obj, self + 0x20, 1);
  ext_4e1b30(obj);
  VT(self, vf1_t, 0xb4)(self, 1);
}
PCREG(45b1c0, fn45b1c0);

// 0x45bf40, thiscall(a) ret 4, returns bool: log = engine table slot 0x138; the table's slot 0x4c(this, 4) value goes with 0x684cd4 to log slot 0x60; this slot 0x214; r = 0x45f3c0(this, a); returns r != 0 (SETNE: AL).
static u8 THISCALL fn45bf40(u8 *self, u32 a) {
  void *t = *(void **)(sysp() + 0x9b);
  void *lg = (void *)VT(t, vf0_t, 0x138)(t);
  u32 *vt = *(u32 **)lg;
  t = *(void **)(sysp() + 0x9b);
  u32 v = ((vf2_t)(*(u32 **)t)[0x4c / 4])(t, (u32)self, 4);
  ((vf2_t)vt[0x60 / 4])(lg, 0x684cd4, v);
  VT(self, vf0_t, 0x214)(self);
  u32 r = ext_45f3c0(self, a);
  return (u8)((r & 0xff) != 0);
}
PCREG(45bf40, fn45bf40);

// 0x4859c0: SEH allocate-and-construct wrapper, naked frame as in area 24 batch 2499 (ECX pushed after the cookie): block from [[[0x70039c]+0x9b]+8] slot 0x44; with a block 0x469870, +4 |= 0x20, +0x44 = 0, vtable 0x68c81c.
static inline u8 *allocFromEngine() {
  u8 *a = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  return vcall<u8 *>(a, 0x44);
}
extern "C" __attribute__((used)) u8 *w24_body_4859c0() {
  u8 *o = allocFromEngine();
  if (o) {
    ext_469870(o);
    *(u32 *)(o + 4) |= 0x20;
    *(u32 *)(o + 0x44) = 0;
    *(u32 *)o = 0x68c81c;
  }
  return o;
}
extern "C" __attribute__((naked)) void w24_seh_4859c0() {
  asm volatile("push %ebp\n\t"
               "mov %esp, %ebp\n\t"
               "push $-1\n\t"
               "push $0x66c831\n\t"
               "mov %fs:0, %eax\n\t"
               "push %eax\n\t"
               "sub $8, %esp\n\t"
               "push %esi\n\t"
               "mov 0x6f5630, %eax\n\t"
               "xor %ebp, %eax\n\t"
               "push %eax\n\t"
               "lea -0xc(%ebp), %eax\n\t"
               "mov %eax, %fs:0\n\t"
               "push %ecx\n\t"
               "call w24_body_4859c0\n\t"
               "mov %eax, %esi\n\t"
               "mov %esi, -0x10(%ebp)\n\t"
               "mov %esi, -0x14(%ebp)\n\t"
               "movl $0, -4(%ebp)\n\t"
               "mov %esi, %eax\n\t"
               "mov -0xc(%ebp), %ecx\n\t"
               "mov %ecx, %fs:0\n\t"
               "pop %ecx\n\t"
               "pop %esi\n\t"
               "mov %ebp, %esp\n\t"
               "pop %ebp\n\t"
               "ret\n\t");
}
PCREG(4859c0, w24_seh_4859c0);
