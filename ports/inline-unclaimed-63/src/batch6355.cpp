// batch6355.cpp - unclaimed-63 core residue 2, batch 55: 0x584aa0 CExplode::PlaySound_Explode(ZGROUP *a1, float *p1, float *p2),
//   thiscall (this in ECX is the CExplode, a1 is the first stack argument), ret 0xc.
//   o = 0x43ec00(a1, p1, p2, [this+0x4a], 0, 0, 0) (thiscall, six stack arguments, ret 0x18; other area's code, stubbed).
//   d = [0x70039c][+0x9b]; s = d->vtbl[+0x60](o) (thiscall, one argument). If s == 0 return.
//   [0x70039c]->vtbl[+0x1c0](0x6ab6d4, 0x23e) (thiscall, two arguments, ret 8; ECX = the engine object).
//   s[+0xc] = 1; s[+0x84] = 0.4f. The float v = (float)(int16)[this+0x4e] is stored over p2's slot; then the x87 multiply
//   st0 * v (st0 is whatever the x87 stack holds on entry: the port uses the same instructions) and fstp back to the slot;
//   n = (int)that value (cvttss2si); s[+0x60] = n - s[+0x64]; s[+0x64] = n; if byte [this+0x50] == 0: s[+0x40] &= ~4.
#include "ff.h"

extern "C" u32 THISCALL ext_43ec00(void *self, u32 p1, u32 p2, u32 x, u32 z1, u32 z2, u32 z3);   // six args, ret 0x18, stubbed
typedef u32(THISCALL * q60_fn)(void *, u32);
typedef void(THISCALL * log_fn)(void *, u32, u32);

// 0x584aa0 (CExplode::PlaySound_Explode).
static void THISCALL unnamed584aa0(u8 *self, u32 a1, u32 p1, u32 p2) {
  u32 o = ext_43ec00((void *)a1, p1, p2, *(u32 *)(self + 0x4a), 0u, 0u, 0u);
  u32 db = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 s = ((q60_fn)(*(u32 *)(*(u32 *)db + 0x60)))((void *)db, o);
  if (s == 0)
    return;
  u32 eng = G(u32, 0x70039c);
  ((log_fn)(*(u32 *)(*(u32 *)eng + 0x1c0)))((void *)eng, 0x6ab6d4u, 0x23eu);
  *(u32 *)(s + 0xc) = 1;
  *(u32 *)(s + 0x84) = 0x3ecccccdu;
  float v = (float)(int)(short)*(u16 *)(self + 0x4e);
  float out;
  asm volatile("fmuls %[v]\n\tfstps %[out]"
               : [out] "=m"(out)
               : [v] "m"(v)
               : "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)", "memory");
  int n = (int)out;
  *(u32 *)(s + 0x60) = (u32)n - *(u32 *)(s + 0x64);
  *(u32 *)(s + 0x64) = (u32)n;
  if (*(u8 *)(self + 0x50) == 0)
    *(u32 *)(s + 0x40) &= 0xfffffffbu;
}
PCREG(584aa0, unnamed584aa0);
