// batch6520.cpp - unclaimed-68 batch 52 (claim 52, gap band). Name is a GUESS (ZGeomSpawn::FrameUpdate, from the working notes).
#include "ff.h"
#include <stdint.h>

typedef u32(THISCALL *VNoArgRet)(u8 *self);
typedef void(THISCALL *VNoArgVoid)(u8 *self);
typedef u32(THISCALL *VMgrSlot58)(u8 *mgr, u32 a);
typedef u8(THISCALL *VBool1)(u8 *self, u32 a);
typedef void(THISCALL *VOut2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *V1bc)(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

// original helpers, run as exe code (arities from the call sites and their ret forms)
extern "C" void THISCALL ext_4db2c0(u8 *self, u32 a1, u32 a2);       // ret 8
extern "C" u32 THISCALL ext_4db2f0(u8 *self, u32 a);                 // ret 4
extern "C" void THISCALL ext_4e0a10(void *self);                     // ret 0, ecx only
extern "C" void FASTCALL ext_4e0980(float *v, const float *src);     // ret 0
extern "C" void FASTCALL ext_4de7e0(float *v, const float *src);     // ret 0
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);       // vmmul
extern "C" void FASTCALL ext_441940(float *v, const float *b);       // PSVECAdd

// 0x4a7c30, ZGeomSpawn::FrameUpdate() (GUESS name): thiscall, no stack args (plain ret).
static void THISCALL geomSpawnFrameUpdate(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *mgr = *(u8 **)(eng + 0x9b);
  u32 r = ((VMgrSlot58)*(u32 *)(*(u8 **)mgr + 0x58))(mgr, *(u32 *)(self + 0x48));
  if (r == 0) {
    ((VNoArgVoid)*(u32 *)(*(u8 **)self + 0x58))(self);
    return;
  }
  int32_t thr = *(int32_t *)(G(u8 *, 0x70039c) + 0x40);
  if (*(int32_t *)(self + 0x72) < thr) {
    float l4c[3], l10[3], l28[3], l1c[3], l34[3], l40[3];
    do {
      float p = *(float *)(self + 0x52) * G(float, 0x678620);
      *(int32_t *)(self + 0x72) += (int32_t)p;
      u8 *P = *(u8 **)(self + 0x44);
      ext_4db2c0(*(u8 **)(P + 8), (u32)l4c, (u32)l10);
      if (self[0x7d]) {
        ext_4e0a10(l28);
        ext_4e0980(l28, (float *)(self + 0x5a));
        ext_4de7e0(l4c, l28);
      }
      if (self[0x7e]) {
        ext_4e0a10(l1c);
        ext_4e0980(l1c, (float *)(self + 0x66));
        ext_4419f0(l1c, l4c);
        ext_441940(l10, l1c);
      }
      u32 ob;
      if (*(u32 *)(self + 0x4c) == 0) {
        u8 *R = (u8 *)((VNoArgRet)*(u32 *)(*(u8 **)P + 0x20))(P);
        if (((VBool1)*(u32 *)(*(u8 **)R + 0x1e0))(R, 0x1000ca)) {
          u8 *vec = *(u8 **)(R + 8);
          ext_4419f0(l10, (float *)vec);
          ext_441940(l10, (float *)(vec + 0x24));
          ext_4419f0(l34, (float *)vec);
          ext_4419f0(l40, (float *)vec);
          ext_4419f0(l4c, (float *)vec);
          ob = ((VNoArgRet)*(u32 *)(*(u8 **)R + 0x20))(R);
        } else {
          ob = (u32)R;
        }
      } else {
        u8 *R = (u8 *)((VNoArgRet)*(u32 *)(*(u8 **)P + 0x20))(P);
        ((VOut2)*(u32 *)(*(u8 **)R + 0x98))(R, (u32)l4c, (u32)l10);
        if (*(u32 *)(self + 0x4c) == 1) {
          u8 *Q = (u8 *)ext_4db2f0(*(u8 **)(P + 8), 0);
          ob = (u32)Q;
          ((VOut2)*(u32 *)(*(u8 **)Q + 0x94))(Q, (u32)l4c, (u32)l10);
        } else {
          ob = *(u32 *)(*(u8 **)(eng + 0x9b) + 0xadc);
        }
      }
      u8 *X = (u8 *)r;
      u32 res = ((V1bc)*(u32 *)(*(u8 **)X + 0x1bc))(X, ob, (u32)l4c, (u32)l10, 0u, 0u, 0u, 1u);
      if (res) ((VNoArgVoid)*(u32 *)(*(u8 **)res + 0x2c))((u8 *)res);
    } while (*(int32_t *)(self + 0x72) < thr);
  }
  ((VNoArgVoid)*(u32 *)(*(u8 **)self + 0x84))(self);
}
PCREG(4a7c30, geomSpawnFrameUpdate);
