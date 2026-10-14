// batch836.cpp - animation layer thread, batch 836: ZLNKOBJ::ExecuteCallBack and ZIKLNKOBJ::ForceFacing.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" s32 FASTCALL ext_4cc850(const char *a, const char *b);            // striwcmp (ecx = a, edx = b)
extern "C" void THISCALL ext_465330(void *ba, float now);                    // ZBoneAnim::UpdateCallBacks (batch 811)
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);   // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_4e09b0(float *v);                              // vneg (in place)
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, u32 zero);   // createmat (ret 4)

// ZLNKOBJ::ExecuteCallBack(const char* name) [medium]: for every bone-table entry whose flag bit 0 is set and whose
// bone anim's clip name matches (striwcmp == 0), the callbacks are fired with the "end of time" value 0x7e967699.
static void THISCALL ExecuteCallBack(u8 *self, const char *name) {
  u32 n = F32(self, 0x20);
  for (u32 i = 0; i != n; i++) {
    u8 *e = (u8 *)FP(self, 0x1c) + i * 0x18;
    if (!(F32(e, 4) & 1)) continue;
    void *ba = FP(e, 0x14);
    if (!ba) continue;
    if (ext_4cc850((const char *)ba + 0x4c, name) == 0) ext_465330(ba, bitsf(0x7e967699u));
  }
}
PCREG(462a70, ExecuteCallBack);

// ZIKLNKOBJ::ForceFacing(const float* dir) [medium]: the target (vt +0x84) minus dir, with y set to 0 and negated;
// the direction becomes a matrix (createmat), and the object's vt +0x370(matrix, target) is called.
static void THISCALL ForceFacing(u8 *self, const float *dir) {
  float tgt[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(self, 0x84, tgt);
  float d[3];
  ext_43e920(d, dir, tgt);
  d[1] = 0.0f;
  ext_4e09b0(d);
  float mat[9];
  ext_4de040(mat, d, 0u);
  vcall<void>(self, 0x370, mat, tgt);
}
PCREG(466640, ForceFacing);
