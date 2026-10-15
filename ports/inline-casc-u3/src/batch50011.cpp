// batch50011.cpp - cascade u3, tier H, batch 50011: 0x4e1c90 (clip a convex polygon against a plane, keeping the side with distance >= 0).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(u8 *out, u8 *a, u8 *b);   // ret 4: out = a - b (vec3)
extern "C" void FASTCALL ext_441940(u8 *a, u8 *b);            // a += b
extern "C" void THISCALL ext_4e0d00(u8 *v, float s);          // ret 4: v *= s
extern "C" void FASTCALL ext_633654(u32 cookie);              // /GS check

static float dist(u8 *N, u8 *d) {
  float *n = (float *)N, *f = (float *)d;
  float a = n[0] * f[0];
  float b = f[1] * n[1];
  b = b + a;
  float c = f[2] * n[2];
  return b + c;
}

// 0x4e1c90, fastcall(out, P, N, verts, n) ret 0xc, /GS, returns the output vertex count: d = verts[i] - P (0x43e920), dist = N . d. Walks the n vertices (the last pairs with a copy of vertex 0):
// a vertex with dist >= 0 is copied to out; when the edge to the next vertex changes sign (dist_i >= 0 > dist_next or dist_i < 0 <= dist_next ... exactly as below) out gets
// (v_i - v_next) * (dist_next / (dist_next - dist_i)) + v_next (0x43e920, 0x4e0d00, 0x441940).
static s32 FASTCALL fn4e1c90(u8 *out, u8 *P, u8 *N, u8 *verts, s32 n) {
  float first[3];
  u8 *vf = verts;
  first[0] = *(float *)vf;
  first[1] = *(float *)(vf + 4);
  first[2] = *(float *)(vf + 8);
  s32 count = 0;
  float d[3];
  ext_43e920((u8 *)d, (u8 *)first, P);
  float di = dist(N, (u8 *)d);
  s32 total = n * 3;
  if (total != 0) {
    u8 *cur = verts;
    s32 idx = 0;
    do {
      if (di >= 0.0f) {
        *(u32 *)out = *(u32 *)cur;
        *(u32 *)(out + 4) = *(u32 *)(cur + 4);
        *(u32 *)(out + 8) = *(u32 *)(cur + 8);
        out += 0xc;
        count++;
      }
      s32 nidx = idx + 3;
      u8 *nx = (nidx == total) ? (u8 *)first : verts + 0xc + idx * 4;
      ext_43e920((u8 *)d, nx, P);
      float dn = dist(N, (u8 *)d);
      bool cross;
      if (di >= 0.0f && 0.0f > dn) cross = true;
      else cross = (0.0f > di) && dn >= 0.0f;
      if (cross) {
        ext_43e920(out, cur, nx);
        float t = dn / (dn - di);
        ext_4e0d00(out, t);
        ext_441940(out, nx);
        out += 0xc;
        count++;
      }
      di = dn;
      cur += 0xc;
      idx = nidx;
    } while (idx != total);
  }
  ext_633654(0);
  return count;
}
PCREG(4e1c90, fn4e1c90);
