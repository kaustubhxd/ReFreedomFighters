// batch308.cpp - ZGROUP::DrawDebugObjects, 0x43fe60 (area 43, 2026-10-12). Name map says with one argument
// (ZDrawDebugRender*); the exe code takes FOUR stack arguments (ret 0x10), so the names below are GUESS.
// thiscall (this = ECX): a1 = [ebp+8] (object, slot 0xd8 is called on it), a2 = [ebp+0xc] (unused), a3 = [ebp+0x10]
// (matrix, 9 floats), a4 = [ebp+0x14] (translation, 3 floats).
// Body: flags = this+0x14 (dword). If bit 0 clear: return. t1 = mat(a3) * this+8 +0x30 (vmmul), then t1 += a4.
// If flags & 0xc is zero: return. t2 = (1,1,1) + (this+8)+0x40. a1->slot 0xd8(a3, &t1, &t2).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void FASTCALL ext_441970(float *out, const float *vec, const float *mat);   // vmmul (ecx out, edx vec, stack mat)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                     // PSVECAdd

static void THISCALL zgroupDrawDebugObjects(u8 *self, u8 *a1, u32 a2, float *a3, float *a4) {
  (void)a2;
  u32 flags = U32(self, 0x14);
  if ((flags & 1) == 0)
    return;
  float t1[3];
  float t2[3];
  ext_441970(t1, (const float *)(unsigned long)(U32(self, 8) + 0x30), a3);
  ext_441940(t1, a4);
  if ((flags & 0xc) == 0)
    return;
  t2[0] = 1.0f;
  t2[1] = 1.0f;
  t2[2] = 1.0f;
  ext_441940(t2, (const float *)(unsigned long)(U32(self, 8) + 0x40));
  vcall<void>((void *)a1, 0xd8, (void *)a3, (void *)t1, (void *)t2);
}
PCREG(43fe60, zgroupDrawDebugObjects);
