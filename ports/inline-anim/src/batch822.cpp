// batch822.cpp - animation layer thread, batch 822: ZLNKOBJ::CalcCenSize (the object's bounding sphere from its
// base geometry's size).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_43df70(void *self);                       // ZSHAPE::CalcCenSize (empty body)
extern "C" void THISCALL ext_4db7c0(void *geom, float *out);           // ZBaseGeom::GetSize(float*) const
extern "C" void THISCALL ext_4dce50(void *geom, float radius);         // ZBaseGeom::SetRadius(float)
extern "C" void THISCALL ext_4dd060(void *geom, const float *size);    // ZBaseGeom::SetSize (clamps to 2^-13)

// ZLNKOBJ::CalcCenSize() [high]. thiscall, no args. m = max of the three sizes (max with the first one
// taken as x, then y, then z); the size becomes (m, m, m) and the radius sqrt(3 m^2) + 1.
static void THISCALL CalcCenSize(u8 *self) {
  ext_43df70(self);
  float s[3];
  void *geom = FP(self, 8);
  ext_4db7c0(geom, s);
  float m = s[1] > s[0] ? s[1] : s[0];
  m = s[2] > m ? s[2] : m;
  s[0] = m;
  s[1] = m;
  s[2] = m;
  float sq = m * m;
  float r = (float)crt::sqrt((double)(sq + sq + sq));
  ext_4dce50(geom, r + G(float, 0x678858));
  ext_4dd060(geom, s);
}
PCREG(4616c0, CalcCenSize);
