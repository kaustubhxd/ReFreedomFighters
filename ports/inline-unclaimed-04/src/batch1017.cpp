// batch1017.cpp - unclaimed-04 batch 18 (docs/20-unclaimed-04.md): CEntityTracker::Init2 (0x5c0470, thiscall, ret 0).
// Runs the builder 0x5c0500 (original code here), then X = M->vt[0x134](), X->vt[0x90](0x68a9d4, &flag); when the flag is
// 0, Y = M->vt[0x138](), Y->vt[0x88](0x681320, &tmp) and this+0x64 = M->vt[0x58](tmp). M = (global 0x70039c)+0x9b.
#include "ff.h"

typedef u32(THISCALL *vf0_t)(void *self);
typedef u32(THISCALL *vf1_t)(void *self, u32 a);
typedef void(THISCALL *vf2_t)(void *self, u32 a, u32 b);

static inline u32 call0(void *o, u32 off) {
  return ((vf0_t)(*(u32 *)(*(u32 *)o + off)))(o);
}
static inline u32 call1(void *o, u32 off, u32 a) {
  return ((vf1_t)(*(u32 *)(*(u32 *)o + off)))(o, a);
}
static inline void call2(void *o, u32 off, u32 a, u32 b) {
  ((vf2_t)(*(u32 *)(*(u32 *)o + off)))(o, a, b);
}

extern "C" void THISCALL ext_5c0500(void *self);  // builder, original code

// 0x5c0470
static void THISCALL entityTrackerInit2(u8 *self) {
  ext_5c0500(self);

  u8 *m = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u32 x = call0(m, 0x134);
  u8 flag = 0;
  call2((void *)x, 0x90, 0x68a9d4, (u32)&flag);
  if (flag == 0) {
    m = *(u8 **)(*(u8 **)0x70039c + 0x9b);
    u32 y = call0(m, 0x138);
    u32 tmp = 0;
    call2((void *)y, 0x88, 0x681320, (u32)&tmp);
    m = *(u8 **)(*(u8 **)0x70039c + 0x9b);
    *(u32 *)(self + 0x64) = call1(m, 0x58, tmp);
  }
}
PCREG(5c0470, entityTrackerInit2);
