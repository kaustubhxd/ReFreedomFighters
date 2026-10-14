// batch33111.cpp - h3 () batch 33111: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)
#define LOGOBJ (*(u8 **)0x700390)

typedef void (*hook_t)();
typedef void (*log3_t)(u8 *, u32, u32);

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 which);            // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 v);                // ret 4
extern "C" void THISCALL ext_500360(u8 *self, u32 v);                // ret 4
extern "C" void THISCALL ext_45c3a0(u8 *self, u32 a, u32 b, u32 c);  // ret 0xc
extern "C" void *ext_634d10(void *p, int v, u32 n);                  // cdecl (memset)

// 0x50fb70: thiscall(arg) ret 4 (this unused): e = table slot 0x138(); p1,p0 = 0x5003d0([arg+4], 1/0); state p0[4]: 3 -> v = p0[0]; 4 -> v = (*p0)->slot 0x34(); else log (0x69c8e0, 0x111)/(r, 0x69c6b0, 0x69c9b0) + assert hook, v = 0; e->slot 0x58(v, *p1, 3)
static void THISCALL fn50fb70(u8 *self, u8 *arg) {
  (void)self;
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u8 *e = vcall<u8 *>(tab, 0x138);
  u32 *q1 = ext_5003d0(*(u8 **)(arg + 4), 1);
  u32 *q0 = ext_5003d0(*(u8 **)(arg + 4), 0);
  u8 st = ((u8 *)q0)[4];
  u32 v;
  if (st == 3) {
    v = *q0;
  } else if (st == 4) {
    u8 *o = *(u8 **)q0;
    v = vcall<u32>(o, 0x34);
  } else {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x69c8e0u, 0x111u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c9b0);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    v = 0;
  }
  vcall<u32>(e, 0x58, v, *q1, 3u);
}
PCREG(50fb70, fn50fb70);

// 0x511150: thiscall(arg) ret 4 (this unused): p=0x5003d0([arg+4],0); p[4] not in {0,1}: log (0x69c8e0,0x104)/(r,0x69c6b0,0x69c938) + assert hook; k=*p; 0x5002f0(0x5003d0([arg+8],0), 0); [sys+0x1a9f] && k: q = table slot 0x60(k); q: 0x500360(0x5003d0([arg+8],0), q[0x70])
static void THISCALL fn511150(u8 *self, u8 *arg) {
  (void)self;
  u32 *p = ext_5003d0(*(u8 **)(arg + 4), 0);
  u8 st = ((u8 *)p)[4];
  if (st != 0 && st != 1) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x69c8e0u, 0x104u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 k = *p;
  u32 *a = ext_5003d0(*(u8 **)(arg + 8), 0);
  ext_5002f0((u8 *)a, 0);
  if (*(u32 *)(SYS + 0x1a9f) != 0 && k != 0) {
    u8 *tab = *(u8 **)(SYS + 0x9b);
    u8 *q = vcall<u8 *>(tab, 0x60, k);
    if (q) {
      u32 f = *(u32 *)(q + 0x70);
      u32 *b = ext_5003d0(*(u8 **)(arg + 8), 0);
      ext_500360((u8 *)b, f);
    }
  }
}
PCREG(511150, fn511150);

// 0x4451d0: thiscall ctor(a, b, c) ret 0xc: base 0x45c3a0(a,b,c); vtable 0x67d748; memset(this+0x7c, 0, 0x34); many default fields; [0x18]=[[sys+0x9b]+0xadc]; [0x181]=1.0/[0x179]; returns this
static u8 *THISCALL fn4451d0(u8 *self, u32 a, u32 b, u32 c) {
  ext_45c3a0(self, a, b, c);
  W32(self, 0x67d748);
  W32(self + 0x78, 0);
  ext_634d10(self + 0x7c, 0, 0x34);
  W32(self + 0x2c, 0);
  W32(self + 0x192, 0);
  u8 *tab = *(u8 **)(SYS + 0x9b);
  W32(self + 0x18, R32(tab + 0xadc));
  W32(self + 0x48, 0);
  W32(self + 0x1c, 0);
  W32(self + 0x60, 0x43c80000);
  W32(self + 0x58, 0x3f800000);
  W32(self + 0x5c, 0x3f9c61ab);
  W32(self + 0x64, 0x40a00000);
  W32(self + 0x68, 0x469c4000);
  W32(self + 0x70, 0);
  W32(self + 0x74, 0);
  W32(self + 0x4c, 0);
  W32(self + 0x6c, 0);
  W32(self + 0x3c, 0x3f800000);
  W32(self + 0x40, 0x3f800000);
  W32(self + 0x44, 0x3f800000);
  W32(self + 0x50, 0);
  W32(self + 0x54, 0);
  W32(self + 0x30, 0);
  W32(self + 0x34, 0);
  W32(self + 0x38, 0);
  W32(self + 0x189, 0x3f800000);
  W32(self + 0x185, 0x3f800000);
  self[0x18d] = 0;
  W32(self + 0x18e, 0);
  self[0x170] = 0;
  W32(self + 0x171, 0);
  W32(self + 0x175, 0);
  W32(self + 0x179, 0x3f800000);
  W32(self + 0x17d, 0x3f800000);
  float q = 1.0f / bitsf(R32(self + 0x179));
  W32(self + 0x48, R32(self + 0x48) | 0x20);
  self[0x196] = 0;
  W32(self + 0x181, fbits(q));
  return self;
}
PCREG(4451d0, fn4451d0);
