#include "ff.h"
static double ciAtan2(double x,double y) {
  double angle;
  asm volatile("fldl %2; fldl %1; call *%3; fstpl %0" : "=m"(angle):"m"(y),"m"(x),"r"(0x634d6au):"eax","ecx","edx","memory","cc","st","st(1)");
  return angle;
}
static void THISCALL joystickDeadzone(u8 *self,float *a,float *b) {
  float by=*b;float ax=*a;
  float length=(float)crt::sqrt((double)(ax*ax+by*by));
  if (*(float *)(self+0x69)>length) {*a=0.0f;*b=0.0f;return;}
  double dx=(double)(*a/length),dy=(double)(*b/length);
  float angle=(float)ciAtan2(dx,dy);
  float capped=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f),_mm_set_ss(length)));
  float scale=(capped-*(float *)(self+0x69))* *(float *)(self+0x6d);
  *a=(float)(crt::sin((double)angle)*(double)scale);
  *b=(float)(crt::cos((double)angle)*(double)scale);
}
PCREG(4297a0,joystickDeadzone);
