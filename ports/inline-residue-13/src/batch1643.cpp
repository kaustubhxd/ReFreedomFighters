// batch1643.cpp - ZMovementGuide::CalcNewSpeed(const float* a, const float* b, float* out, float speed) (0x487e50,
// residue 13, 2026-10-12). Vector helpers run as exe code: 0x451890 vaddscalar (FASTCALL: dst in ECX, a in EDX, scalar on
// the stack; dst += a * scalar), 0x4e09b0 vneg (dst in ECX), 0x4e0d80 vsetlen (dst in ECX, length on the stack). The base
// call is 0x487c70 ZMovementBaseMove::CalcNewSpeed (THISCALL, four stack arguments). The labels follow the original's jumps.
// `eax` is kept as in the original: it starts as the object's +0x417 dword and is overwritten with 1 or 5 on some paths,
// and the later test uses its low byte. The second added vector is the first argument plus 12 bytes (ebx = [ebp+8]).
// GUESS: the flag meanings are from the code only.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_487c70[];
extern "C" char ext_451890[];
extern "C" char ext_4e09b0[];
extern "C" char ext_4e0d80[];

typedef void(THISCALL *BaseFn)(void *self, const float *a, const float *b, float *out, float speed);
typedef void(FASTCALL *AddScalarFn)(float *dst, const float *a, float s);
typedef void(THISCALL *NegFn)(float *v);
typedef void(THISCALL *SetLenFn)(float *v, float len);

void THISCALL ZMovementGuide_CalcNewSpeed(u8 *self, const float *a, const float *b, float *out, float speed) {
  float spd;
  u32 eax;
  ((BaseFn)(void *)ext_487c70)(self, a, b, out, speed);
  u8 *o = AT(u8 *, self, 4);
  eax = AT(u32, o, 0x417);
  u8 al = (u8)eax;
  out[0] = 0.0f;
  out[1] = 0.0f;
  out[2] = 0.0f;
  if (!(al & 0x18)) AT(u16, self, 0x3bb) = 0;
  if (al & 3) goto L_ed0;
  if (AT(u8, self, 0x3ad) != 0) goto L_ef4;
  if (AT(u8, self, 0x3bb) != 0) goto L_ebd;
  if (AT(u8, self, 0x3bc) != 0) goto L_ebd;
  if (AT(u8, self, 0x3be) == 0) goto L_ed0;
L_ebd:
  eax = (AT(u8, self, 0x3be) != 0) ? 1u : 5u;
  goto L_ed0;
L_ef4:
  if (AT(u8, self, 0x3bb) == 0) goto L_f01;
  if (al & 8) goto L_ecb;
L_f01:
  if (AT(u8, self, 0x3bc) == 0) goto L_f0e;
  if (al & 0x10) goto L_ecb;
L_f0e:
  if (AT(u8, self, 0x3be) == 0) return;   // 487fab epilogue
  ((NegFn)(void *)ext_4e09b0)((float *)(self + 0x3af));
  AT(u8, self, 0x3be) = 0;
  return;
L_ecb:
  eax = 5;
L_ed0:
  if (AT(u8, self, 0x3ad) != 0) goto L_f34;
  {
    float *pv = AT(float *, self, 0x21);
    if (!pv) goto L_f41_default;
    spd = AT(float, pv, 4);
    goto L_f41;
  }
L_f41_default:
  spd = 1.0f;
  goto L_f41;
L_f34:
  spd = 6.66666650772f;
  goto L_f41;
L_f41:
  {
    float *a3af = (float *)(self + 0x3af);
    if (!(eax & 4)) goto L_f72;
    ((AddScalarFn)(void *)ext_451890)(out, a3af, 1.0f);
    {
      float s2 = (AT(u8, self, 0x3be) != 0) ? 1.0f : -1.0f;
      ((AddScalarFn)(void *)ext_451890)(out, (float *)((u8 *)a + 0xc), s2);
    }
    goto L_f9b;
  }
L_f72:
  {
    float *a3af = (float *)(self + 0x3af);
    ((AddScalarFn)(void *)ext_451890)(out, a3af, -1.0f);
    float s2 = (AT(u8, self, 0x3be) != 0) ? -1.0f : 1.0f;
    ((AddScalarFn)(void *)ext_451890)(out, (float *)((u8 *)a + 0xc), s2);
  }
L_f9b:
  ((SetLenFn)(void *)ext_4e0d80)(out, spd);
  (void)spd;
}
PCREG(487e50, ZMovementGuide_CalcNewSpeed);
