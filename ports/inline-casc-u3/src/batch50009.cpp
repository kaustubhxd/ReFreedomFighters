// batch50009.cpp - cascade u3, tier H, batch 50009: 0x52e670 (snap a point to its grid cell centre through the cell query 0x530e80).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(u8 *out, u8 *a, u8 *b);   // ret 4: out = a - b (vec3, x87)
extern "C" u32 THISCALL ext_530e80(u8 *self, u8 *out, u8 *in, u32 a, u32 b, float f);   // ret 0x14

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static float rdf(const u8 *p) { return bitsf(rd32(p)); }
static void wf(u8 *p, float f) { u32 v = fbits(f); p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x52e670, thiscall(p, f1, f2, f3) ret 0x10, returns al. Unaligned fields: A = vec3 at this+6, B = vec3 at this+0x12, grid sizes sx = [+0x3c], sz = [+0x40], sy = [+0x44] (signed).
// ext = B - A (43e920); cell words in = ((u16)cvtt((p.x-A.x)/ext.x*sx), (u16)cvtt((p.z-A.z)/ext.z*sz), (u16)cvtt((p.y-A.y)/ext.y*sy)); r = ext_530e80(this, &out, &in, (u16)cvtt(f1), (u16)cvtt(f2), f3);
// r == 0 -> false. Else ext is recomputed and the point becomes x = ext.x*out0/sx + A.x, z = ext.z*out1/sz + A.z, y = ext.y*out2/sy + A.y; d = (x, y, z) - p_old (43e920, before p is overwritten);
// p = (x, y, z) and when out0 == (u16)ix: p.x = x - d.x; when out1 == (u16)iz: p.z = z - d.z. Returns true.
static u8 THISCALL fn52e670(u8 *self, u8 *p, float f1, float f2, float f3) {
  float ext[3];
  ext_43e920((u8 *)ext, self + 0x12, self + 6);
  float xs = (rdf(p) - rdf(self + 6)) / ext[0] * (float)(s32)rd32(self + 0x3c);
  float ys = (rdf(p + 4) - rdf(self + 0xa)) / ext[1] * (float)(s32)rd32(self + 0x44);
  float zs = (rdf(p + 8) - rdf(self + 0xe)) / ext[2] * (float)(s32)rd32(self + 0x40);
  s32 ix = _mm_cvttss_si32(_mm_set_ss(xs));
  u16 in[3];
  in[0] = (u16)ix;
  s32 iz = _mm_cvttss_si32(_mm_set_ss(zs));
  in[1] = (u16)iz;
  in[2] = (u16)_mm_cvttss_si32(_mm_set_ss(ys));
  u16 out[3];
  u32 r = ext_530e80(self, (u8 *)out, (u8 *)in, (u16)_mm_cvttss_si32(_mm_set_ss(f1)), (u16)_mm_cvttss_si32(_mm_set_ss(f2)), f3);
  if (!r) return 0;
  u32 ox = out[0], oz = out[1], oy = out[2];
  ext_43e920((u8 *)ext, self + 0x12, self + 6);
  float x = ext[0] * (float)(s32)ox / (float)(s32)rd32(self + 0x3c) + rdf(self + 6);
  float z = ext[2] * (float)(s32)oz / (float)(s32)rd32(self + 0x40) + rdf(self + 0xe);
  float y = ext[1] * (float)(s32)oy / (float)(s32)rd32(self + 0x44) + rdf(self + 0xa);
  float pos[3] = {x, y, z};
  float d[3];
  ext_43e920((u8 *)d, (u8 *)pos, p);
  wf(p + 4, y);
  wf(p, x);
  wf(p + 8, z);
  if (out[0] == (u16)ix) wf(p, x - d[0]);
  if (out[1] == (u16)iz) wf(p + 8, z - d[2]);
  return 1;
}
PCREG(52e670, fn52e670);
