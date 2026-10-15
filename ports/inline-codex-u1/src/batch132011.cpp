// Port derived from inline-camera batch1072; strict verification by codex-u1.
// batch1072.cpp - ZCAMERA::CalcCenSize (0x445580, high confidence in the class map). Camera thread, 2026-10-12.
#include "ff.h"
template<class T> static T& at(void* p,u32 off){return *(T*)((u8*)p+off);}

extern "C" THISCALL void ext_4dc5d0(void *obj, float x, float y, float z);   // centre (+0x30..+0x38), flag 0x100000
extern "C" THISCALL void ext_4dc600(void *obj, const float *v);               // centre from a vector (flag 0x100000)
extern "C" THISCALL void ext_4dd060(void *obj, const float *v);               // size vector (+0x40..+0x48), clamped
extern "C" THISCALL void ext_4dce50(void *obj, float v);                       // +0x4c, flag 0x100000
extern "C" THISCALL void ext_4e0d00(float *v, float s);                       // v *= s
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b

// 0x445580 ZCAMERA::CalcCenSize(void) (thiscall). Flag bit 0 clear: the object at +8 gets a zero centre, a zero size and
// a zero +0x4c. Flag bit 0 set: the box is built from the field of view (+0x5c, through tan) and +0x60: t = tan(fov/2) *
// +0x60; L = (max(30, t)?, max(20, t)?, +0x60) and a second triple from -t (min with -30, -20) and -80, summed, halved, and
// set as the centre; the size is (sum - the centre), with the length plus 1.0 at +0x4c.
static THISCALL void ZCAMERA_CalcCenSize(u8 *self) {
  u8 *obj = at<u8 *>(self, 8);
  if (!(at<u8>(self, 0x14) & 1)) {
    ext_4dc5d0(obj, 0.0f, 0.0f, 0.0f);
    float zero[3] = {0.0f, 0.0f, 0.0f};
    ext_4dd060(obj, zero);
    ext_4dce50(obj, 0.0f);
    return;
  }
  float t = (float)crt::tan((double)(at<float>(self, 0x5c) * 0.5f)) * at<float>(self, 0x60);
  float Lc = at<float>(self, 0x60);
  float L4 = (30.0f > t) ? 30.0f : t;
  float L8 = (20.0f > t) ? 20.0f : t;
  float nt = -t;
  float L10 = (nt > -30.0f) ? -30.0f : nt;
  float L14 = (nt > -20.0f) ? -20.0f : nt;
  float L18 = -80.0f;
  float A[3] = {L4, L8, Lc};
  float B[3] = {L10, L14, L18};
  float D[3];
  ext_43e8e0(D, A, B);
  ext_4e0d00(D, 0.5f);
  ext_4dc600(obj, D);
  ext_43e920(D, A, (const float *)(obj + 0x30));
  ext_4dd060(obj, D);
  float s2 = at<float>(obj, 0x40) * at<float>(obj, 0x40);
  float s1 = at<float>(obj, 0x44) * at<float>(obj, 0x44);
  float s0 = at<float>(obj, 0x48) * at<float>(obj, 0x48);
  s2 = s2 + s1;
  s2 = s2 + s0;
  float r = (float)crt::sqrt((double)s2);
  ext_4dce50(obj, r + 1.0f);
}
PCREG(445580, ZCAMERA_CalcCenSize);
