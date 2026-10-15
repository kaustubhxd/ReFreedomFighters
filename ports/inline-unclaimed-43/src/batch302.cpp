// batch302.cpp - ZBoneModifyBase::CalcCenSize(const ZBone *a, const SBoneDefinition *b) (area 43, 2026-10-12).
// 0x645660, thiscall (this = ECX), two stack arguments, ret 8. (name map, high). Frame is EBP-relative.
// Count = dword at this+0x11 (unaligned). Each loop step k: tmp1 = mat(a_k) * vec(b_k) + trans(a_k); vb = b_k+0x10;
// TransformBox(a_k, vb); tmp2 = tmp1 - vb; tmp1 += vb; then the min/max pair (max/min of the steps, copy at k == 0).
// After the loop: centre at this+0x275 = (max - min) * 0.5, and this+0x281 = max - centre.
// Quirk (not claimed): count == 0 skips the loop and then reads frame slots ebp-0x28 and ebp-0x40 that nothing wrote.
// The port reads its own uninitialised locals there, so it is only exact for count >= 1 (see harness/specs_s302.py).
#include "ff.h"

// Callees (original exe code). Register arguments come in ECX/EDX; the third argument of 0x441970 and 0x43e920 is
// on the stack (callee pops 4).
extern "C" void FASTCALL ext_441970(float *out, const float *vec, const float *mat);   // ecx out, edx vec, stack mat
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                     // PSVECAdd
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);      // PSVECSubtract (stack b)
extern "C" void FASTCALL ext_4e2c60(const float *box, float *vec);                     // TransformBox (in place)
extern "C" void FASTCALL ext_4e08d0(float *dst, const float *src);                     // vmax (ecx dst, edx src)
extern "C" void FASTCALL ext_4e0900(float *dst, const float *src);                     // vmin (ecx dst, edx src)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                // vscalar (ecx v, stack s)

// dword at +0x11 without an aligned load
static inline u32 rd32u(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

static void THISCALL boneModifyCalcCenSize(u8 *self, u8 *a, u8 *b) {
  float tmp1[3], tmp2[3], vb[3];
  float mx[3], mn[3];
  u32 k = 0;
  if (rd32u(self + 0x11) != 0) {
    do {
      u8 *ak = a + 0x30 * k;
      u8 *bk = b + 0x30 * k;
      ext_441970(tmp1, (const float *)bk, (const float *)ak);
      ext_441940(tmp1, (const float *)(ak + 0x24));
      const float *src = (const float *)(b + 0x10 + 0x30 * k);
      vb[0] = src[0];
      vb[1] = src[1];
      vb[2] = src[2];
      ext_4e2c60((const float *)ak, vb);
      ext_43e920(tmp2, tmp1, vb);
      ext_441940(tmp1, vb);
      if (k == 0) {
        mx[0] = tmp1[0];
        mx[1] = tmp1[1];
        mx[2] = tmp1[2];
        mn[0] = tmp2[0];
        mn[1] = tmp2[1];
        mn[2] = tmp2[2];
      } else {
        ext_4e08d0(mx, tmp1);
        ext_4e0900(mn, tmp2);
      }
      k++;
    } while (k != rd32u(self + 0x11));
  }
  float *centre = (float *)(self + 0x275);
  ext_43e920(centre, mx, mn);
  ext_4e0d00(centre, 0.5f);
  ext_43e920((float *)(self + 0x281), mx, centre);
}
PCREG(645660, boneModifyCalcCenSize);
