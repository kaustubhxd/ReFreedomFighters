// batch1070.cpp - ZCAMERA::SetCam6ClipPlanes (0x446790, high confidence in the class map). Camera thread, 2026-10-12.
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" FASTCALL void ext_446ee0(float *out, const float *a, const float *b);   // out = a x b
extern "C" THISCALL void ext_4453c0(void *self, float *plane, u32 index);            // clip-plane builder (batch 1069)
extern "C" CDECL void *ext_634d10(void *p, int c, u32 n);                            // CRT memset

// 0x446790 ZCAMERA::SetCam6ClipPlanes(float p1, float p2, float p3, int p4, int p5, float p6) (thiscall, six stack args):
// the focal and the depth of the view come from p1 (field of view), p3 (depth), p4 / p5 (ints, the viewport size) and
// p6; flag bit 0 (orthographic) picks between two frusta. Six clip planes are built from the frame's vectors:
// near (0,0,1,-p2), far (0,0,-1,p3), and four side planes; the planes go to the object at +0x78 (count at +0), and
// +0x44 is set to 1.0.
static THISCALL void ZCAMERA_SetCam6ClipPlanes(u8 *self, float p1, float p2, float p3, s32 p4, s32 p5, float p6) {
  at<u32>(self, 0x48) = at<u32>(self, 0x48) & ~2u;
  float f5 = (float)p5;
  float f4 = (float)p4;
  at<float>(self, 0x54) = f5;
  at<float>(self, 0x50) = f4;
  float val = (f5 * p6) / f4;
  float asp = at<float>(self, 0x181);

  float vC[4], vD[4], vE[4], vF[4];   // the four side planes (normal x, y, z, then w)
  if (at<u32>(self, 0x48) & 1) {
    // orthographic: the focal from tan(p1 / 2) when the aspect field is 1.0
    at<float>(self, 0x5c) = p1;
    float t = p1 * 0.5f;
    if (at<float>(self, 0x3c) == 1.0f) {
      float tf = (float)crt::tan((double)t);
      float den = tf * at<float>(self, 0x60);
      den = den * 4.0f;
      at<float>(self, 0x3c) = 1.0f / den;
    }
    at<float>(self, 0x40) = at<float>(self, 0x3c) / val;
    at<u32>(self, 0x58) = 0x39000000u;
    float h = 0.5f / at<float>(self, 0x3c);
    float h2 = 0.5f / at<float>(self, 0x40);
    vC[0] = -1.0f; vC[1] = 0.0f; vC[2] = 0.0f; vC[3] = h;
    vD[0] = 1.0f;  vD[1] = 0.0f; vD[2] = 0.0f; vD[3] = h;
    vE[0] = 0.0f;  vE[1] = -1.0f; vE[2] = 0.0f; vE[3] = h2;
    vF[0] = 0.0f;  vF[1] = 1.0f;  vF[2] = 0.0f; vF[3] = h2;
  } else {
    at<float>(self, 0x40) = 1.0f / val;
    at<float>(self, 0x3c) = 1.0f;
    at<float>(self, 0x5c) = p1;
    float tn = (float)crt::tan((double)(p1 * 0.5f));
    float pz = p3;
    float ta = tn * pz;
    float q = (pz / ta) * 0.5f;
    at<float>(self, 0x58) = q;
    float Z = 1.0f / q;
    float s = Z * -0.5f;
    float Q = s;   // [ebp+0x18] now holds this value
    u8 *sys = G(u8 *, 0x70039c);
    u8 *head = at<u8 *>(sys, 0x190f);
    if (head && at<u8>(head, 0x81)) s = s * bitsf(0x3faaaaabu);   // 4/3 (0x67da14)
    float a1[3] = {0.0f, 1.0f, 0.0f};
    float b1[3] = {s, 0.0f, 1.0f};
    float c1[3];
    ext_446ee0(c1, a1, b1);                   // (1, 0, -s')
    float s2 = Z * 0.5f;
    float s2b = s2;
    if (head && at<u8>(head, 0x81)) s2b = s2 * bitsf(0x3faaaaabu);
    float b2[3] = {0.0f, 1.0f, 0.0f};
    float a2[3] = {s2b, 0.0f, 1.0f};
    float c2[3];
    ext_446ee0(c2, a2, b2);                   // (-1, 0, s2b)
    float t = s2 * asp;
    float xv = t / at<float>(self, 0x40);
    float a3[3] = {1.0f, 0.0f, 0.0f};
    float b3[3] = {0.0f, xv, 1.0f};
    float c3[3];
    ext_446ee0(c3, a3, b3);                   // (0, -1, xv)
    float yt = Q * asp;
    float yv = yt / at<float>(self, 0x40);
    float a4[3] = {0.0f, yv, 1.0f};
    float b4[3] = {1.0f, 0.0f, 0.0f};
    float c4[3];
    ext_446ee0(c4, a4, b4);                   // (0, 1, -yv)
    vC[0] = c2[0]; vC[1] = c2[1]; vC[2] = c2[2]; vC[3] = 0.0f;
    vD[0] = c1[0]; vD[1] = c1[1]; vD[2] = c1[2]; vD[3] = 0.0f;
    vE[0] = c3[0]; vE[1] = c3[1]; vE[2] = c3[2]; vE[3] = 0.0f;
    vF[0] = c4[0]; vF[1] = c4[1]; vF[2] = c4[2]; vF[3] = 0.0f;
  }
  at<u32>(self, 0x78) = 0;
  ext_634d10(self + 0x7c, 0, 0x34);
  float p1plane[4] = {0.0f, 0.0f, 1.0f, -p2};
  ext_4453c0(self + 0x78, p1plane, 0);
  float p2plane[4] = {0.0f, 0.0f, -1.0f, p3};
  ext_4453c0(self + 0x78, p2plane, 1);
  ext_4453c0(self + 0x78, vC, 2);
  ext_4453c0(self + 0x78, vD, 3);
  ext_4453c0(self + 0x78, vE, 4);
  ext_4453c0(self + 0x78, vF, 5);
  at<float>(self, 0x44) = 1.0f;
}
PCREG(446790, ZCAMERA_SetCam6ClipPlanes);
