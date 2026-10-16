#include "ff.h"

typedef u32(THISCALL *V2)(void *, void *, void *);
extern "C" u32 THISCALL ext_5257a0(void *self, u32 b);
extern "C" u32 THISCALL ext_5266e0(void *self, float x);
extern "C" u32 THISCALL ext_526540(void *self, float x);
extern "C" u32 THISCALL ext_5267b0(void *self, float x);
extern "C" u32 THISCALL ext_526610(void *self, float x);
extern "C" u32 THISCALL ext_5254c0(void *self);

// 0x5253b0: thiscall(this, a, sel, float x, b, c) ret 0x14: attaches object a (stored at +0x88, its slot 0x80 fills this+0xc), loads with
// 0x5257a0(b), starts one of four effects by sel with x, then stamps the engine clock into +0x48 (scaled) and +0x84 (+0x1c00); returns al = 1
u32 THISCALL fn_5253b0(u8 *self, u8 *a, u32 sel, float x, u32 b, u32 c) {
  *(u8 **)(self + 0x88) = a;
  self[0xbc] = (u8)c;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x30) = 0;
  u8 *a2 = *(u8 **)(self + 0x88);
  (*(V2 *)(*(u8 **)a2 + 0x80))(a2, self + 0xc, self);
  u32 r = ext_5257a0(self, b);
  if (!(u8)r) return r;
  switch (sel) {
    case 0: ext_5266e0(self, x); break;
    case 1: ext_526540(self, x); break;
    case 2: ext_5267b0(self, x); break;
    case 3: ext_526610(self, x); break;
    default: break;
  }
  ext_5254c0(self);
  u8 *eng = G(u8 *, 0x70039c);
  *(float *)(self + 0x48) = (float)*(s32 *)(eng + 0x40) * G(float, 0x6785e4);
  u32 clk = *(u32 *)(G(u8 *, 0x70039c) + 0x40) + 0x1c00;
  *(u32 *)(self + 0x84) = clk;
  return (clk & ~0xffu) | 1;
}
PCREG(5253b0, fn_5253b0);
