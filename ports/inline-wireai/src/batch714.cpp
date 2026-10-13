// batch714.cpp - soldier AI, batch 714 (2026-10-11): CFFCoverList::CreateSpotForArrow, the wrapper that makes an
// arrow-style cover spot from a geom's root matrix. CreateSpot itself (0x585a40) is left as exe code here and is hooked by
// the spec, so this batch checks only the wrapper's arithmetic and argument order.
#include "ff.h"

extern "C" void THISCALL ext_4e09b0(float *);                                       // vneg (3 floats in place)
extern "C" void THISCALL ext_585a40(void *self, float *a, float *b, float *c, float *d,
                                    u32 check, u32 type, u32 flags);                 // CFFCoverList::CreateSpot

// 0x585ed0 CFFCoverList::CreateSpotForArrow(ZGEOM* g, CCoverSpot::eType type, bool flag) [high].
// The geom's root TM (slot 0x80: 3x3 in M, root position in P) gives a flipped first row. Four vectors go to CreateSpot:
// the root position twice, C = (M[2], M[1], -M[0]) and D = (M[0], M[1], M[2]), where M is the TM after its first row is
// negated. CreateSpot is called with check = false and flags = 0. flag set: the geom's virtual 0x210 is called with 1.
static void THISCALL cover_CreateSpotForArrow(u8 *self, u8 *g, u32 type, u32 flag) {
  float M[12];
  float P[3];
  vcall<void>(g, 0x80, M, P);
  ext_4e09b0(M);
  float A[3] = {P[0], P[1], P[2]};
  float C[3] = {M[2], M[1], -M[0]};
  float D[3] = {M[0], M[1], M[2]};
  ext_585a40(self, A, P, C, D, 0, type, 0);
  if ((u8)flag)
    vcall<void>(g, 0x210, 1);
}
PCREG(585ed0, cover_CreateSpotForArrow);
