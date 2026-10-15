#include "ff.h"
extern "C" u32 THISCALL ext_662c50(u8 *smoother, float *io);  // point smoother step (EaseInEaseOut, inference)
extern "C" u32 THISCALL ext_662f40(u8 *smoother, float *io);  // angle smoother step (inference)
extern "C" void FASTCALL ext_4de040(float *out, const float *fwd, const float *up);  // createmat [high]
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                   // mcpy [low]
static void THISCALL camFocusBlend(u8 *cam) {
  ext_662c50(cam + 0xd36, (float *)(cam + 0xd3a));
  u32 p0 = *(u32 *)(cam + 0xd3a), p1 = *(u32 *)(cam + 0xd3e), p2 = *(u32 *)(cam + 0xd42);
  ext_662f40(cam + 0xd87, (float *)(cam + 0xd8b));
  float ang[3];
  ((u32 *)ang)[0] = *(u32 *)(cam + 0xd8b);
  ((u32 *)ang)[1] = *(u32 *)(cam + 0xd8f);
  ((u32 *)ang)[2] = *(u32 *)(cam + 0xd93);
  float m[9];
  ext_4de040(m, ang, 0);
  ext_4de420((float *)(cam + 0xc89), m);
  *(u32 *)(cam + 0xc71) = p0;
  *(u32 *)(cam + 0xc75) = p1;
  *(u32 *)(cam + 0xc79) = p2;
  if (vcall<u8>(cam + 0xd36, 0x0) && vcall<u8>(cam + 0xd87, 0x0))
    cam[0xd35] = 0;
}
PCREG(5cebc0, camFocusBlend);
