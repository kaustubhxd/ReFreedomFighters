// batch33102.cpp - h3 () batch 33102: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)
#define LOGOBJ (*(u8 **)0x700390)

typedef void (*hook_t)();
typedef void (*log3_t)(u8 *, u32, u32);

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 which);             // ret 4

// 0x486900: thiscall no args, returns true: o=[this+0xc]->slot 0x10(); o->slot 0x2d0(0, 0); vt=[this]; [this+0x34]=0; [this+0x30]=(float)([sys+0x40]+0x133)/1024; [this+0x2c] = vt slot 0x24(this, o->slot 0x350()); t=table slot 0x114(0x686794, 0, 0x68cdc4, 0x2b6, 0, 0); [this+8]->slot 0x128((u16)t)
static u8 THISCALL fn486900(u8 *self) {
  u8 *o = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  vcall<u32>(o, 0x2d0, 0u, 0u);
  u8 *vt = *(u8 **)self;
  s32 t = (s32)(*(u32 *)(SYS + 0x40) + 0x133u);
  *(u32 *)(self + 0x34) = 0;
  float f = (float)t * 0.0009765625f;
  *(float *)(self + 0x30) = f;
  u32 a = vcall<u32>(o, 0x350);
  typedef u32(THISCALL * fn_t)(u8 *, u32);
  u32 r = (*(fn_t *)(vt + 0x24))(self, a);
  *(u32 *)(self + 0x2c) = r;
  u8 *sub = *(u8 **)(self + 8);
  u8 *svt = *(u8 **)sub;
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u32 id = vcall<u32>(tab, 0x114, 0x686794u, 0u, 0x68cdc4u, 0x2b6u, 0u, 0u);
  typedef u32(THISCALL * fn2_t)(u8 *, u32);
  (*(fn2_t *)(svt + 0x128))(*(u8 **)(self + 8), (u32)(u16)id);
  return 1;
}
PCREG(486900, fn486900);

// 0x5198b0: thiscall(arg) ret 4: f = [this+0x14]->slot 0x304(*0x5003d0([arg+4],0)); p=0x5003d0([arg+8],0); state p[4] not in {0,2}: log (0x69c8e0, 0xd5)/(r,0x69c6b0,0x69c938) + assert hook, return; else p[0]=f; p[4]=2
static void THISCALL fn5198b0(u8 *self, u8 *arg) {
  u32 *p0 = (u32 *)ext_5003d0(*(u8 **)(arg + 4), 0);
  u32 a = *p0;
  float f = vcall<float>(*(u8 **)(self + 0x14), 0x304, a);
  u8 *p = ext_5003d0(*(u8 **)(arg + 8), 0);
  u8 st = p[4];
  if (st != 0 && st != 2) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x69c8e0u, 0xd5u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    return;
  }
  *(float *)p = f;
  p[4] = 2;
}
PCREG(5198b0, fn5198b0);

// 0x50acb0: thiscall(arg) ret 4: f = sys slot 0x1c0(0x69d350, 0xb0) (float); p=0x5003d0([arg+8],0); state p[4] not in {0,2}: log (0x69c8e0, 0x104) + assert hook; p[4]=2; p[0]=f
static void THISCALL fn50acb0(u8 *self, u8 *arg) {
  (void)self;
  float f = vcall<float>(SYS, 0x1c0, 0x69d350u, 0xb0u);
  u8 *p = ext_5003d0(*(u8 **)(arg + 8), 0);
  u8 b = p[4];
  if (b != 0 && b != 2) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x69c8e0u, 0x104u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  p[4] = 2;
  *(float *)p = f;
}
PCREG(50acb0, fn50acb0);
