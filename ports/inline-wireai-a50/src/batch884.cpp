// batch884.cpp - area 50 (SEH row): 0x59e3d0 [~150 instr, thiscall, no stack args, void; GUESS "Walk59e3d0": refresh a flag on
// the manager's entry, then walk the list of nodes from this->X->B (vt +0x20 on each), and for each node whose vector is far
// enough (squared distance > a constant) log the pair of sub-objects and call their printf slot (vt +0x2c of the logger's sink)].
// SEH frame not reproduced (fs:[0] writes not compared). The stack cookie check (0x633654) is not reproduced.
// Stood in (hooked): 0x58b930, 0x477ff0, 0x59db90, 0x5a0290 (thiscall, no args), 0x4cbec0 (thiscall dtor, no args).
// Real exe code used: 0x4e0830 (squared distance, fastcall, ST0) and 0x4cc1d0 (mov eax,[ecx]; ret).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_58b930(void *self);
extern "C" void THISCALL ext_477ff0(void *self);
extern "C" void THISCALL ext_59db90(void *self);
extern "C" void THISCALL ext_5a0290(void *self);
extern "C" void THISCALL ext_4cbec0(void *local);                       // dtor (stood in)
extern "C" float FASTCALL ext_4e0830(const void *obj, const float *v);  // squared distance (exe; ST0)
extern "C" void *THISCALL ext_4cc1d0(void *obj);                        // mov eax,[ecx]; ret (exe)

// 0x59e3d0 (name GUESS).
static void THISCALL Walk59e3d0(u8 *self) {
  ext_58b930(self);
  ext_477ff0(self);
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u8 *M = (u8 *)FP(mgr, 0xadc);
  u8 *E = (u8 *)vcall<void *>(M, 0x25c, (void *)0x685f44u, 0u);
  if (E) {
    u32 r100 = vcall<u32>(E, 0x100, (void *)0x6a5cf0u);
    U32(self, 0x913) = r100;
    if (r100 == 0) {
      u8 *R2 = (u8 *)vcall<void *>(E, 0x10c, (void *)0x6ac98cu, 0xffffffffu);
      u8 *sv = R2;
      if (!(U8(R2, 4) & 1)) {
        vcall<void>(R2, 0x8);
        U32(R2, 4) |= 4;
      }
      if (U8(R2, 4) & 1) {
        vcall<void>(R2, 0x4c);
        u32 v30 = U32(R2, 0x30);
        U32(R2, 4) |= 0x100;
        vcall<void>(R2, 0x54, v30);
        sv = 0;
      }
      U32(self, 0x913) = (u32)sv;
    }
  }
  U16(self, 0x788) = 0xffffu;
  ext_59db90(self);

  u8 *X = (u8 *)vcall<void *>(self, 0x20);
  u8 *B = (u8 *)vcall<void *>(X, 0x20);
  float Lv[3] = {0.0f, 0.0f, 0.0f};    // [ebp-0x1c], [ebp-0x18], [ebp-0x14]
  u8 L1[0x80], L2[0x80];               // [ebp-0x11c], [ebp-0x9c]
  for (u8 *cur = B; cur; cur = (u8 *)vcall<void *>(cur, 0x20)) {
    if (cur == M) break;
    float d = ext_4e0830((u8 *)FP(cur, 8) + 0x24, Lv);
    if (!(d > G(float, 0x679540))) continue;
    u8 *logger = G(u8 *, 0x700390);
    u8 *sink = (u8 *)vcall<void *>(logger, 0x20, (void *)0x6ae6a0u, 0x18au);
    u8 *Q1 = (u8 *)vcall<void *>(cur, 0x1d8, (void *)L1, 1u);
    u8 *S2 = (u8 *)vcall<void *>(self, 0x1d8, (void *)L2, 1u);
    void *r1 = ext_4cc1d0(Q1);
    void *r2 = ext_4cc1d0(S2);
    typedef void (*printf4_t)(void *, const char *, u32, u32);
    (*(printf4_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x6ae778, (u32)r2, (u32)r1);
    ext_4cbec0(L2);
    ext_4cbec0(L1);
  }
  ext_5a0290(self);
}
PCREG(59e3d0, Walk59e3d0);
