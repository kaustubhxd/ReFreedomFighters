// batch862.cpp - area 50 (residue-9 candidate): 0x5dcd10 [104 instr, stdcall (two stack args, ret 8); no name in the map
// (GUESS "add a rotated-offset sum of the object's 3x3 frame to the output vector")]. The object's vt +0x80 fills a 3x3 frame
// M and a vector B; out = B. Three engine samples (vt +0x1c0, file 0x6b6c28, lines 0x7a, 0x7b, 0x7c) each give (sample - 0.5)
// times one of the object's sub-object floats (+0x40, +0x44, +0x48): comp1..comp3. Then out += 2*comp1*row2, out += 2*comp2*row1,
// out += 2*comp3*row0 (0x451890, exe). The product of a sample and a float is formed exactly (double) and rounded once to float,
// as the exe's x87 store does.
#include "ff.h"

#define F32(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void FASTCALL ext_451890(float *out, const float *vec, float s);   // out += s * vec (exe)

static float Sample1c0(u32 line) {
  return vcall<float>(G(u8 *, 0x70039c), 0x1c0, (u32)0x6b6c28, line);
}

// 0x5dcd10 (name GUESS).
static void STDCALL Fn5dcd10(u8 *obj, float *out) {
  float M[9], B[3];
  vcall<void>(obj, 0x80, M, B);
  out[0] = B[0];
  out[1] = B[1];
  out[2] = B[2];
  u8 *x = (u8 *)FP(obj, 8);
  float f40 = F32(x, 0x40), f44 = F32(x, 0x44), f48 = F32(x, 0x48);
  float r0[3] = {M[0], M[1], M[2]};
  float r1[3] = {M[3], M[4], M[5]};
  float r2[3] = {M[6], M[7], M[8]};
  float s1 = Sample1c0(0x7a);
  float comp1 = (float)(((double)s1 - 0.5) * (double)f40);
  float s2 = Sample1c0(0x7b);
  float comp2 = (float)(((double)s2 - 0.5) * (double)f44);
  float s3 = Sample1c0(0x7c);
  float comp3 = (float)(((double)s3 - 0.5) * (double)f48);
  ext_451890(out, r2, comp1 + comp1);
  ext_451890(out, r1, comp2 + comp2);
  ext_451890(out, r0, comp3 + comp3);
}
PCREG(5dcd10, Fn5dcd10);
