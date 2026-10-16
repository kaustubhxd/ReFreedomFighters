// batch210033.cpp - Sonnet-w3a: small BLOCKED rows (callback teardown, null-check report, record serializer loop)
#include "ff.h"

extern "C" u32 ext_633170(u32 a, u32 b);
extern "C" u32 THISCALL ext_439670(u8 *self);
extern "C" u32 THISCALL ext_438e30(u8 *self);

struct Tear {
  u32 kind;
};

static u32 fn6321a0(u8 *a, u8 *b) {
  typedef u32 (*CB2)(u32, u32);
  typedef u32 (STDCALL *CB3)(u32, u32, u32);
  u32 kind = *(u32 *)a;
  if (kind == 4 || kind == 5) (*(CB2 *)(b + 0x24))(*(u32 *)(b + 0x28), *(u32 *)(a + 0xc));  // @6321a0_a
  if (*(u32 *)a == 6) ext_633170(*(u32 *)(a + 4), (u32)b);  // @6321a0_b
  u32 v = *(u32 *)(a + 0x28);
  *(u32 *)(a + 0x34) = v;  // @6321a0_c
  *(u32 *)(a + 0x30) = v;
  u32 fp = *(u32 *)(a + 0x38);
  *(u32 *)a = 0;
  *(u32 *)(a + 0x1c) = 0;
  *(u32 *)(a + 0x20) = 0;
  if (fp) {
    u32 r = (*(CB3 *)&fp)(0, 0, 0);  // @6321a0_d
    *(u32 *)(a + 0x3c) = r;
    *(u32 *)(b + 0x30) = r;  // @6321a0_e
  }
  (*(CB2 *)(b + 0x24))(*(u32 *)(b + 0x28), *(u32 *)(a + 0x28));  // @6321a0_f
  (*(CB2 *)(b + 0x24))(*(u32 *)(b + 0x28), *(u32 *)(a + 0x24));  // @6321a0_g
  (*(CB2 *)(b + 0x24))(*(u32 *)(b + 0x28), (u32)a);  // @6321a0_h
  return 0;
}
PCREG(6321a0, fn6321a0);

static u8 STDCALL fn438d90(u8 *a) {
  if (!a) {  // @438d90_a
    u8 *g = G(u8 *, 0x700390);
    u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x67a850, 0xb14);  // @438d90_b
    typedef u32 (*F)(u8 *, u32);
    F f = *(F *)(*(u8 **)o + 0x2c);
    f(o, 0x67a8f8);  // @438d90_c
    return 0;
  }
  u8 bl = a[0xc];
  if (!bl) return 0;
  u32 edi = *(u32 *)a;
  if (edi != 3) bl &= (u8)ext_439670(*(u8 **)(a + 8));  // @438d90_d
  if (!bl) return 0;
  if (edi == 0) return a[0x2d];  // @438d90_e
  if (edi == 1) return (u8)ext_438e30(a);  // @438d90_f
  return 0;
}
PCREG(438d90, fn438d90);

static u8 THISCALL fn5c4f80(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5c4f80_a
  for (int i = 0; i < *(int *)(self + 0x50); i++) {  // @5c4f80_b
    u8 *p = *(u8 **)(self + 0x4c) + i * 0x19;
    vcall<u32, u32>(a, 0x54, *(u32 *)p);  // @5c4f80_c
    vcall<u32, u32>(a, 0x64, *(u32 *)(p + 4));  // @5c4f80_d
    vcall<u32, u32>(a, 0x44, *(u32 *)(p + 8));  // @5c4f80_e
    vcall<u32, u8 *>(a, 0x68, p + 0xc);  // @5c4f80_f
    vcall<u32, u32>(a, 0x60, p[0x18]);  // @5c4f80_g
  }
  return 1;
}
PCREG(5c4f80, fn5c4f80);
