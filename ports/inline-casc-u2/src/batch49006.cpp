// batch49006.cpp - cascade u2 batch 49006: 0x513d10 (look up resources through the engine table, spawn one entry per item of an iterator).
#include "ff.h"

typedef u32 __attribute__((aligned(1))) uu;
typedef float __attribute__((aligned(1))) uf;
#define U32(p, o) (*(uu *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4db7c0(u8 *self, float *out);   // ret 4: copy of 3 dwords from +0x40

typedef void *(THISCALL *c2_t)(void *, u32, u32);
typedef void *(THISCALL *c1_t)(void *, void *);
typedef u32(THISCALL *c4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *c3p_t)(void *, u32, u32, void *);
typedef float(THISCALL *cf_t)(void *);
#define VT(o, off, T) ((*(T **)(o))[(off) / 4])

// 0x513d10, thiscall, no args, /GS frame.
static void THISCALL fn513d10(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  void *o1 = *(void **)(*(u8 **)(eng + 0x9b) + 0xadc);
  void *b = VT(o1, 0x25c, c2_t)(o1, 0x685f44, 0);
  eng = G(u8 *, 0x70039c);
  void *t = *(void **)(eng + 0x9b);
  U32(self, 0xd2) = (u32)VT(t, 0x4c, c1_t)(t, b);
  U32(self, 0x13c) = (u32)VT(b, 0x100, c1_t)(b, (void *)0x690428);
  eng = G(u8 *, 0x70039c);
  t = *(void **)(eng + 0x9b);
  u32 l28 = (u16)(u32)VT(t, 0x114, c4_t)(t, 0x690438, 0, 0x69e4bc, 0x199);
  eng = G(u8 *, 0x70039c);
  t = *(void **)(eng + 0x9b);
  u32 l2c = (u16)(u32)VT(t, 0x114, c4_t)(t, 0x6904a4, 0, 0x69e4bc, 0x19a);
  eng = G(u8 *, 0x70039c);
  t = *(void **)(eng + 0x9b);
  u8 *c = (u8 *)VT(t, 0x58, c1_t)(t, (void *)U32(self, 0xd6));
  float v[3];
  ext_4db7c0(*(u8 **)(self + 8), v);
  v[0] = 0;
  v[2] = 0;
  float h = VT(self, 0x2f0, cf_t)(self);
  v[1] = (float)((double)h + (double)v[1]);
  eng = G(u8 *, 0x70039c);
  t = *(void **)(eng + 0x9b);
  u32 edi = (u32)VT(t, 0x4c, c1_t)(t, self);
  if (c && *(void **)(c + 0x18)) {
    u32 it = 0;
    void *d = *(void **)(c + 0x18);
    VT(d, 0x4c, c1_t)(d, &it);
    d = *(void **)(c + 0x18);
    u32 item = (u32)VT(d, 0x5c, c1_t)(d, &it);
    while (it != 0) {
      u32 l40[2] = {edi, item};
      VT(self, 0x130, c3p_t)(self, (u32)b, l28, l40);
      u32 l20[4] = {edi, fbits(v[0]), fbits(v[1]), fbits(v[2])};
      VT(self, 0x130, c3p_t)(self, (u32)b, l2c, l20);
      d = *(void **)(c + 0x18);
      item = (u32)VT(d, 0x5c, c1_t)(d, &it);
    }
  }
  void *k = *(void **)(self + 0x13c);
  U32(self, 0x140) = (u32)VT(k, 0x84, c1_t)(k, (void *)edi);
}
PCREG(513d10, fn513d10);
