// batch6248 - ragdoll side (claim 41): CRagdoll2::FixParticle(int index, float *p) [0x641c90; thiscall, two stack arguments, ret 8].
// The SEH-style cookie check is not reproduced. If this+0x3f+4*index is not 1: it becomes 1 and the copy below runs with this+0x7f+4*index = 0.
// If it is 1: the particle at index is read (0x545c80, thiscall; GUESS stub by address) into out[3]; the engine object's slot 0x94 gives a pointer
// whose float at +0xc is compared with 0x67a284; if that does not exceed it, copy. Else d = |p - out| (0x4e0870, fastcall, real exe code); if d does
// not exceed 0x680a84, copy. Else the counter this+0x7f+4*index is incremented; below 20 copy (counter kept); otherwise the flag is cleared and 0 is
// returned. The copy writes p[0..2] to this+0xbf+12*index, +0xc3, +0xc7 and returns 1.
#include "ff.h"

extern "C" void THISCALL ext_545c80(void *self, s32 index, float *out);   // GUESS stub by address: GetParticlePos (thiscall, two args)
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);      // exe: |a - b| (lifted in batch48)

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

static u32 copyParticle(u8 *self, s32 index, const float *p) {
  wr32u(self + 0xbf + index * 12, rd32u((const u8 *)p));
  wr32u(self + 0xc3 + index * 12, rd32u((const u8 *)(p + 1)));
  wr32u(self + 0xc7 + index * 12, rd32u((const u8 *)(p + 2)));
  return 1;
}

static u32 THISCALL fn641c90(u8 *self, s32 index, float *p) {
  if (rd32u(self + 0x3f + index * 4) != 1) {
    wr32u(self + 0x3f + index * 4, 1);
    wr32u(self + 0x7f + index * 4, 0);
    return copyParticle(self, index, p);
  }
  float out[3];
  ext_545c80(rdp(self + 0x17f), index, out);
  u8 *obj = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
  float ka = rdf((const u8 *)0x67a284);
  if (!(ka > rdf(obj + 0xc))) {
    wr32u(self + 0x7f + index * 4, 0);
    return copyParticle(self, index, p);
  }
  float d = ext_4e0870(p, out);
  float kb = rdf((const u8 *)0x680a84);
  if (!(d > kb)) {
    wr32u(self + 0x7f + index * 4, 0);
    return copyParticle(self, index, p);
  }
  u32 count = rd32u(self + 0x7f + index * 4) + 1;
  wr32u(self + 0x7f + index * 4, count);
  if ((s32)count < 0x14) return copyParticle(self, index, p);
  wr32u(self + 0x3f + index * 4, 0);
  return 0;
}

PCREG(641c90, fn641c90);
