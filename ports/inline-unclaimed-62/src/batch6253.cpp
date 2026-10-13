// batch6253 - ragdoll side (claim 46): CRagdoll2::Move(float *a1, float *a2, float dt) [0x644af0; thiscall, three stack arguments, ret 0xc].
// SEH frame not reproduced. If this+0x15 is 0: return 0. Else for 16 particles (offset 0x34*i in the element array at ps+0xf, ps = this+0x17f):
//   flag = this+0x3f+4i. flag == 1: element+0x30 = 10000; p = GetParticlePos(i) (GUESS stub); D = target_i - p (target_i = this+0xbf+12i);
//   d = |D| (sqrt); c = (0x67a284 <= eng.slot94().+0xc) ? 0x680a84 : 0x680a70; if d > c: D *= c/d; p += D; SetParticlePos(i, p) (GUESS stub).
//   otherwise element+0x30 = 1.0.
// Then dt2 = clamp(dt, 0x69c69c..0x69f9cc); this+0x16 decremented while positive; blk = eng.slot94(): if (blk.+0x29)'s byte +0x15 is set: f = blk2.+0x11,
// flag = blk3.+0x10 (byte), value = blk4.+4 * dt2; else value = blk5.+4 * dt2, f = 0, flag = 0; r = ps.Move(value, flag, f) (GUESS stub; returns float);
// this+0x1e = this+0x1e * 0x683768 + r; c = this+0x1a * 0x680a70; this+0x22 = (c > this+0x1e) ? this+0x22 + 1 : 0; this+0x1a = this+0x1a * 0x6c289c,
// clamped to 0x43960000 when above 0x68af1c; if this+0x22 > 20 or this+0x16 == 0 and this+0x14 is set: this+0x15 = 0 and blk.+0x10 = 0.
// If this+0x15 still set: CalcGroundOffset(a1, a2) (GUESS stub) and return 1, else return 0.
#include "ff.h"

extern "C" void THISCALL ext_545c80(void *ps, s32 index, float *out);        // GetParticlePos (GUESS stub by address)
extern "C" void THISCALL ext_547760(void *ps, s32 index, float *v);          // SetParticlePos (GUESS stub by address)
extern "C" float THISCALL ext_546320(void *ps, float value, u32 flag, float f); // ConstrainedParticleSystem::Move (GUESS stub; float in ST0)
extern "C" void THISCALL ext_641010(void *self, float *a1, float *a2);        // CalcGroundOffset (GUESS stub by address)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract (exe)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                // PSVECAdd (exe)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                           // vscalar in place (exe)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

static u8 THISCALL fn644af0(u8 *self, float *a1, float *a2, float dt) {
  if (self[0x15] == 0) return 0;
  s32 i = 0;
  u32 off = 0;
  for (;;) {
    float *tgt = (float *)(self + 0xbf + (u32)i * 12);
    u8 *base = rdp(rdp(self + 0x17f) + 0xf);
    if (rd32u(self + 0x3f + (u32)i * 4) == 1) {
      wr32u(base + off + 0x30, 0x461c4000u);
      float V[3];
      ext_545c80(rdp(self + 0x17f), i, V);
      float D[3];
      ext_43e920(D, tgt, V);
      float x = D[0], y = D[1], z = D[2];
      float s2 = x * x;
      float yy = y * y;
      s2 = s2 + yy;
      float zz = z * z;
      s2 = s2 + zz;
      float d = (float)crt::sqrt((double)s2);
      u8 *blk = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
      float k1 = G(float, 0x67a284);
      float cK = (!(k1 > rdf(blk + 0xc))) ? G(float, 0x680a84) : G(float, 0x680a70);
      if (d > cK) ext_4e0d00(D, cK / d);
      ext_441940(V, D);
      ext_547760(rdp(self + 0x17f), i, V);
    } else {
      wr32u(base + off + 0x30, 0x3f800000u);
    }
    off += 0x34;
    i++;
    if (off >= 0x340) break;
  }

  float k1 = G(float, 0x69f9cc);
  float m1 = (k1 < dt) ? k1 : dt;
  float k2 = G(float, 0x69c69c);
  float dt2 = (k2 > m1) ? k2 : m1;
  s32 cnt = (s32)rd32u(self + 0x16);
  if (cnt > 0) wr32u(self + 0x16, (u32)(cnt - 1));

  u8 *eng_obj = rdp(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *blk = (u8 *)vcall<u32>(eng_obj, 0x94);
  u8 *q = rdp(blk + 0x29);
  float value, f;
  u32 flag;
  if (q[0x15] != 0) {
    u8 *b2 = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
    f = rdf(b2 + 0x11);
    u8 *b3 = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
    flag = b3[0x10];
    u8 *b4 = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
    value = rdf(b4 + 4) * dt2;
  } else {
    u8 *b5 = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
    value = rdf(b5 + 4) * dt2;
    f = 0.0f;
    flag = 0;
  }
  float r = ext_546320(rdp(self + 0x17f), value, flag, f);

  float e0 = rdf(self + 0x1e);
  float e1 = e0 * G(float, 0x683768) + r;
  wrf(self + 0x1e, e1);
  float av = rdf(self + 0x1a);
  float c = av * G(float, 0x680a70);
  if (c > e1) wr32u(self + 0x22, rd32u(self + 0x22) + 1);
  else wr32u(self + 0x22, 0);
  float av2 = av * G(float, 0x6c289c);
  wrf(self + 0x1a, av2);
  if (av2 > G(float, 0x68af1c)) wr32u(self + 0x1a, 0x43960000u);

  s32 c22 = (s32)rd32u(self + 0x22);
  if (c22 > 0x14 || rd32u(self + 0x16) == 0) {
    if (self[0x14] != 0) {
      self[0x15] = 0;
      u8 *b6 = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x1aa3), 0x94);
      b6[0x10] = 0;
    }
  }
  if (self[0x15] == 0) return 0;
  ext_641010(self, a1, a2);
  return 1;
}
PCREG(644af0, fn644af0);
