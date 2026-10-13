// batch6258 - ragdoll side: CRagdoll2::ComputeParticlePositionsSub() [0x641340; thiscall, no arguments, plain ret]. /GS cookie not reproduced.
// Locals shared by all blocks: R (ebp-0x58), Q (ebp-0x4c), M (3x3, ebp-0x40), Z = {0,0,0} (ebp-0x1c), P (ebp-0x10).
// Sixteen blocks, one per particle, in a fixed order. Each block: if GetLinkMatPos_global(this, bone, M, P, Q, R) (GUESS stub by address; bone is a
// dword of this) returns non-zero al, then the block transforms a vector by M (0x4419f0, exe) and calls, on ps = this+0x17f, SetParticlePos(i, P),
// SetParticleOldPos(i, P) and SetParticleVelocity(i, Z) (all three GUESS stubs by address). Kinds:
//   A (particles 0, 1): Q = 0; Q = Q*M; P += Q (0x441940, exe).
//   B (the other twelve): Q = Q*M only (Q as left by the query); P is used as returned.
//   C (particle 5, bone +0x187): v = R[1]; if 10.0 (0x680a70) > v then v = 10.0 and R[1] = v; Q = {0, 0 - v*0.8 (0x67c1a8), 0}; Q = Q*M; P += Q.
//   D (particle 6, bone +0x187 again, queried again): as C, but R[1] is not written back and the y term is v*0.8 + 0.
#include "ff.h"

extern "C" u8 THISCALL ext_641d90(void *self, u32 bone, float *m, float *p, float *q, float *r);  // CRagdoll2::GetLinkMatPos_global (GUESS stub by address)
extern "C" void THISCALL ext_547760(void *ps, s32 index, float *v);  // SetParticlePos (GUESS stub by address)
extern "C" void THISCALL ext_547730(void *ps, s32 index, float *v);  // SetParticleOldPos (GUESS stub by address)
extern "C" void THISCALL ext_547830(void *ps, s32 index, float *v);  // SetParticleVelocity (GUESS stub by address)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);       // v = v * M (3x3, x87; exe)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);   // PSVECAdd (exe)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

enum { KA, KB, KC, KD };
struct Block { u16 bone; u8 index; u8 kind; };
static const Block kBlocks[16] = {
    {0x193, 0, KA},  {0x18f, 1, KA},  {0x1ab, 2, KB},  {0x19b, 3, KB},  {0x1af, 4, KB},  {0x19f, 7, KB},
    {0x1b3, 10, KB}, {0x1a3, 11, KB}, {0x187, 5, KC},  {0x187, 6, KD},  {0x1c7, 8, KB},  {0x1b7, 9, KB},
    {0x1cb, 12, KB}, {0x1bb, 13, KB}, {0x1cf, 14, KB}, {0x1bf, 15, KB},
};

static void THISCALL fn641340(u8 *self) {
  float R[3], Q[3], M[9], P[3];
  float Z[3] = {0.0f, 0.0f, 0.0f};
  for (const Block &b : kBlocks) {
    if (!ext_641d90(self, rd32u(self + b.bone), M, P, Q, R)) continue;
    if (b.kind == KA) {
      Q[0] = 0.0f; Q[1] = 0.0f; Q[2] = 0.0f;
      ext_4419f0(Q, M);
      ext_441940(P, Q);
    } else if (b.kind == KB) {
      ext_4419f0(Q, M);
    } else {
      float v = R[1];
      float k = G(float, 0x680a70);
      if (k > v) {
        v = k;
        if (b.kind == KC) R[1] = v;
      }
      float s = v * G(float, 0x67c1a8);
      Q[0] = 0.0f;
      Q[2] = 0.0f;
      if (b.kind == KC) {
        Q[1] = 0.0f - s;
      } else {
        Q[1] = s + 0.0f;
      }
      ext_4419f0(Q, M);
      ext_441940(P, Q);
    }
    ext_547760(rdp(self + 0x17f), b.index, P);
    ext_547730(rdp(self + 0x17f), b.index, P);
    ext_547830(rdp(self + 0x17f), b.index, Z);
  }
}
PCREG(641340, fn641340);
