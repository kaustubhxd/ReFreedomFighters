// batch6252 - hit-reaction hand-off (ragdoll side, claim 45): CRagdoll2::Hit(const float *pos, const float *dir, float strength) [0x644400; thiscall,
// three stack arguments, ret 0xc]. The exe's try frame (fs:[0]) and cookie check are not reproduced.
//   this+0x14 = 1, this+0x15 = 1, this+0x16 = 1000, +0x1a = 0x43160000, +0x1e = 0x44bb8000, +0x22 = 0.
//   P = (dir.x, dir.y + sqrt((y*y + x*x) + z*z) * 0x67c198, dir.z).
//   force = strength * [engine+0x1aa3 .slot 0x94]+8 ; BlowDirBomb(ps = this+0x17f, pos, force, P)   (exe 0x5438f0; GUESS stub by address)
//   if [engine+0x1aa3 .slot 0x94]+0xc >= 0x67a284 (ordered):
//     V = normalise(dir) (exe 0x44e630, length discarded); V.y += 0x67c19c
//     Q = GetParticlePos(0) (exe 0x545c80 on ps; GUESS stub by address)
//     coli = COLI(exe 0x4e1b60); coli.pos = Q; coli.dir = V * 4000 (exe 0x4e0d40)
//     if message table's +0xadc object .slot 0x2e0 (coli, 0, 0x20, 0x200000, 1, 0) is non-zero:
//        Q = coli.hit + V * (-20) (exe 0x451890); FixParticle(10, Q) (exe 0x641c90; GUESS stub by address)
#include "ff.h"

extern "C" void THISCALL ext_5438f0(void *ps, const float *pos, float force, const float *dir);   // BlowDirBomb (GUESS stub)
extern "C" void THISCALL ext_545c80(void *ps, s32 index, float *out);                             // GetParticlePos (GUESS stub)
extern "C" void THISCALL ext_641c90(void *self, s32 index, float *p);                             // FixParticle (GUESS stub)
extern "C" void THISCALL ext_4e1b60(void *coli);                                                  // COLI::COLI (exe)
extern "C" float FASTCALL ext_44e630(float *dst, const float *src);                              // vnorm: dst = normalise(src), length in ST0 (exe)
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);                         // out = a * s (exe)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);                         // dst += v * s (exe)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn644400(u8 *self, const float *pos, const float *dir, float strength) {
  self[0x14] = 1;
  self[0x15] = 1;
  wr32u(self + 0x16, 0x3e8);
  wr32u(self + 0x1a, 0x43160000u);
  wr32u(self + 0x1e, 0x44bb8000u);
  wr32u(self + 0x22, 0);

  float x = dir[0];
  float y = dir[1];
  float z = dir[2];
  float yy = y * y;
  float xx = x * x;
  float zz = z * z;
  float s = yy + xx;
  s = s + zz;
  float len = (float)crt::sqrt((double)s);
  float P[3] = {x, len * G(float, 0x67c198) + y, z};

  u8 *eng = G(u8 *, 0x70039c);
  u8 *blk = (u8 *)vcall<u32>(rdp(eng + 0x1aa3), 0x94);
  float force = rdf(blk + 8) * strength;
  ext_5438f0(rdp(self + 0x17f), pos, force, P);

  blk = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
  float cval = rdf(blk + 0xc);
  if (!(cval >= G(float, 0x67a284))) return;

  float V[3];
  ext_44e630(V, dir);
  V[1] = V[1] + G(float, 0x67c19c);

  float Q[3];
  ext_545c80(rdp(self + 0x17f), 0, Q);

  u8 coli[0x80];   // COLI::COLI writes up to +0x6c
  ext_4e1b60(coli);
  wr32u(coli + 0, __builtin_bit_cast(u32, Q[0]));
  wr32u(coli + 4, __builtin_bit_cast(u32, Q[1]));
  wr32u(coli + 8, __builtin_bit_cast(u32, Q[2]));
  ext_4e0d40((float *)(coli + 0xc), V, 4000.0f);

  u8 *msg = rdp(G(u8 *, 0x70039c) + 0x9b);
  u8 *coll = rdp(msg + 0xadc);
  u32 hit = vcall<u32>(coll, 0x2e0, (u32)coli, (u32)0, (u32)0x20, (u32)0x200000, (u32)1, (u32)0);
  if ((hit & 0xff) == 0) return;

  Q[0] = rdf(coli + 0x28);
  Q[1] = rdf(coli + 0x2c);
  Q[2] = rdf(coli + 0x30);
  ext_451890(Q, V, -20.0f);
  ext_641c90(self, 10, Q);
}
PCREG(644400, fn644400);
