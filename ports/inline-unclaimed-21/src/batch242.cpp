// batch242.cpp - parked item, now ported. 0x574680 (name GUESS): stdcall(A, B, G, D, F) (ret 0x14), no this. The libm thunks
// 0x634dac (tan) and 0x634de2 (atan) and 0x634d7c (sqrt) are CRT imports: the harness stubs their IAT slots with Python math
// on both sides, and the port calls them through crt::tan / crt::atan (ff.h). Constants are read from the exe image.
#include "ff.h"

extern "C" u8 *THISCALL ext_4db7c0(u8 *self, u32 p);     // original, thiscall one stack word (stubbed: logs ecx and p)

typedef u32(THISCALL *SlotArgRet)(u8 *, u32);
typedef void(THISCALL *SlotFloat)(u8 *, float);
typedef void(THISCALL *SlotPtr)(u8 *, u32 *);

static u32 vslot23(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void STDCALL block_574680(u32 A, u8 *B, float gval, float *D, float F) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *child = *(u8 **)(rm + 0x9b);
  u8 *esi = (u8 *)(u32)((SlotArgRet)vslot23(child, 0x58))(child, A);
  u8 *bi = *(u8 **)(B + 8);
  ext_4db7c0(bi, (u32)D);
  if (F > G(float, 0x6785d0)) ((SlotFloat)vslot23(esi, 0x224))(esi, F);
  float xm1 = gval + gval;
  float xm0 = G(float, 0x678858) - xm1;
  float dn = *D / xm0;
  *D = dn;
  float s = *(float *)(esi + 0x5c) * G(float, 0x67a6ac);
  double t = crt::tan((double)s);
  double q = (double)dn / t;
  float xm2 = (float)q;
  float K2 = G(float, 0x6a2b00);
  if (xm2 > K2) {
    float t3 = dn / K2;
    double a = crt::atan((double)t3);
    double r = a * G(double, 0x697520);
    *(float *)(esi + 0x5c) = (float)r;
    xm2 = K2;
  }
  float ff = xm2 * G(float, 0x67a6ac);
  float C = G(float, 0x680a90);
  if (ff > C) {
    *(float *)(esi + 0x68) = xm2 + C;
    *(float *)(esi + 0x64) = xm2 - C;
  } else {
    *(float *)(esi + 0x68) = ff + xm2;
    *(float *)(esi + 0x64) = xm2 - ff;
  }
  u8 *M = *(u8 **)(B + 8);
  float V[3] = {*(float *)(M + 0x30), xm2, *(float *)(M + 0x38)};
  ((SlotPtr)vslot23(esi, 0x70))(esi, (u32 *)V);
}
PCREG(574680, block_574680);
