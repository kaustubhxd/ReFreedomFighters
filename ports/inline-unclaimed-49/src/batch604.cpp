// batch604.cpp - area 49, batch 604: CCivilianPathList::SetCivilianOnPath(SCivInfo &info, int idx) (0x5bf340).
// thiscall, ret 8. The SEH frame is not reproduced (no effect on the result). Callees stay the exe's code (ext_ bindings):
// 0x41e290 (__builtin_new, cdecl, size), 0x5bdd30 (record constructor, thiscall, one argument), 0x47bf10 (this = record,
// two arguments). Virtual calls, in exe order: path object slot 0x30 (ONE argument, 0: the exe pushes 0 first);
// render manager slot 0x58 with three args (info[0], id word, &tmp); the object at this+0x44 slot 0x130 with one arg
// (the render result); render manager slot 0x58 with one arg (info[0]); sys slot 0x1c0 with (file, line), float in ST0.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vNone)(void *self);
typedef u32(THISCALL *vOneArg)(void *self, u32 a);
typedef u32(THISCALL *vRm3)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *vOne)(void *self, u32 a);
typedef long double(THISCALL *vRand)(void *self, u32 file, u32 line);
extern "C" void *ext_41e290(u32 size);                                   // __builtin_new (cdecl)
extern "C" u32 THISCALL ext_5bdd30(void *rec, u32 src);                  // record constructor
extern "C" void THISCALL ext_47bf10(void *self, u32 a, u32 b);           // (record, a, 1)

// 0x5bf340 SetCivilianOnPath(info, idx): thiscall, ret 8
static void THISCALL setCivilianOnPath(u8 *self, u32 *info, u32 idx) {
  ((u8 *)info)[4] = (u8)idx;                                             // info+4 = idx (low byte)
  u32 off = idx * 0x3a;
  u8 *blk = self + off;
  u8 *path = *(u8 **)(blk + 0x4c);
  u8 *pv = *(u8 **)(path + 0x18);
  u32 tmp = ((vOneArg)VT(pv, 0x30))(pv, 0);                              // path slot 0x30 with ONE argument (push 0)
  u8 *o = *(u8 **)(self + 0x44);                                         // object at this+0x44 (its vtable gives slot 0x130)
  u8 *sys = G(u8 *, 0x70039c);
  u8 *rm = *(u8 **)(sys + 0x9b);
  u32 x1 = ((vRm3)VT(rm, 0x58))(rm, info[0], (u32)*(u16 *)(self + 0x916), (u32)&tmp);
  ((vOne)VT(o, 0x130))(o, x1);
  u32 x2 = ((vOne)VT(rm, 0x58))(rm, info[0]);
  void *p = ext_41e290(0x18);
  u32 r = 0;
  if (p)
    r = ext_5bdd30(p, *(u32 *)(blk + 0x59));
  ext_47bf10((void *)x2, (u32)p ? r : 0, 1);
  blk[0x54] = (u8)(blk[0x54] + 1);                                       // inc byte [..+0x54]
  long double rv = ((vRand)VT(sys, 0x1c0))(sys, 0x6b35ec, 0x152);       // ST0 = rnd
  float t = (float)(rv + 1.0L);                                         // fadd 1.0 then fstp float
  u32 ticks = *(u32 *)(sys + 0x40);
  float v = *(float *)(blk + 0x55) * t;
  v = v * 1024.0f;
  s32 e = _mm_cvttss_si32(_mm_set_ss(v));
  u32 sum = ticks + (u32)e;
  *(float *)(blk + 0x81) = (float)(s32)sum * 0.0009765625f;
}
PCREG(5bf340, setCivilianOnPath);
