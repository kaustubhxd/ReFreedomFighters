// batch8823.cpp - wire-hit-parts (2026-10-15): inline-frameupdate batch412 (0x4e9280 list box test, 0x4e9200 probe wrapper) copied
// unchanged and re-verified with this harness (its result JSON was not on disk).
// batch412.cpp - 0x4e9200 and 0x4e9280: a matrix-transformed ray / box list test used by ZPlayer's ground probe.
// Names: not in the name map. Both are ZPlayer-side helpers (called from the probe chain); no GC match, so these are
// labelled by what they do. Callees: 0x4de4b0 mmtmul, 0x43e920 PSVECSubtract, 0x441a60 vmtmul, 0x459fc0 vmtmul,
// 0x4e0d40 vscalar and the box test 0x4dddf0 (425 insns) all run as exe code (bound by ext_ names).
#include "ff.h"

extern "C" void FASTCALL ext_4de4b0(float *dst, const float *a, const float *m);      // mmtmul (batch 70)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);      // out = a - b (PSVECSubtract)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                        // vmtmul in place [high]
extern "C" void FASTCALL ext_459fc0(float *out, const float *v, const float *m);      // vmtmul [high]
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);             // vscalar (batch 29)
// box test: fastcall(B in ECX, t3 in EDX), three stack pointers (entry, entry+0xc, entry+0x18), ret 0xc
extern "C" u8 FASTCALL ext_4dddf0(const float *b, const float *t3, const float *e0, const float *e1, const float *e2);

// ---------------------------------------------------------------- 0x4e9280 (no name) [medium]
// thiscall (list in ECX), ret 0xc: (A, B, S). A is a 3x3 matrix; t1 = (A+0x18) / S[0], t2 = (A+0xc) / S[1],
// t3 = A / S[2] (vscalar with the reciprocals). The list at +0xc is a chain of groups: each group N has a count n at
// +0 (n >= 2) and n-2 entries at N+0x18 stepping 0xc; the box test runs on (entry, entry+0xc, entry+0x18) with
// B and t3. Groups are counted by list+8. The first hit returns 1; otherwise 0.
static u8 THISCALL listBoxTest(u8 *list, const float *A, const float *B, const float *S) {
  float t1[3], t2[3], t3[3];
  float inv0 = 1.0f / S[0];
  ext_4e0d40(t1, (const float *)(A + 6), inv0);  // A+0x18
  float inv1 = 1.0f / S[1];
  ext_4e0d40(t2, (const float *)(A + 3), inv1);  // A+0xc
  float inv2 = 1.0f / S[2];
  ext_4e0d40(t3, A, inv2);
  (void)t1;
  (void)t2;
  u32 groups = *(u32 *)(list + 8);
  if (!groups)
    return 0;
  u8 *node = *(u8 **)(list + 0xc);
  for (u32 c = 0; c != groups; c++) {
    u8 *ent = node + 0x18;
    u32 n = *(u32 *)node;
    s32 m = (s32)n - 2;
    if (m != 0) {
      for (s32 k = 0; k != m; k++) {
        if (ext_4dddf0(B, t3, (const float *)ent, (const float *)(ent + 0xc), (const float *)(ent + 0x18)))
          return 1;
        ent += 0xc;
      }
    }
    node = ent + 0x18;  // next group starts 0x18 past where the entries stopped
  }
  return 0;
}
PCREG(4e9280, listBoxTest);

// ---------------------------------------------------------------- 0x4e9200 (no name) [medium]
// thiscall (this in ECX), ret 0xc: (a, b, c). tmp = a * this+0x18 (mmtmul), v = b - (this+0x3c), v *= this+0x18
// (vmtmul), w = c * this+0x18 (vmtmul); returns the list test 0x4e9280(this, tmp, v, w).
static u8 THISCALL probeListBoxTest(u8 *self, const float *a, const float *b, const float *c) {
  float tmp[9], v[3], w[3];
  ext_4de4b0(tmp, a, (const float *)(self + 0x18));
  ext_43e920(v, b, (const float *)(self + 0x3c));
  ext_441a60(v, (const float *)(self + 0x18));
  ext_459fc0(w, c, (const float *)(self + 0x18));
  return listBoxTest(self, tmp, v, w);
}
PCREG(4e9200, probeListBoxTest);
