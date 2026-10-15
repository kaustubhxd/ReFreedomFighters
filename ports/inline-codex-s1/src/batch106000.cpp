#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" double VECTORCALL ext_634dbe(double);
static u8 STDCALL direction_angle(const float* a,const float* b,const float* axis,float limit) {
 float v[3]; ext_43e920(v,a,b);
 if(v[0]!=0.0f || v[1]!=0.0f || v[2]!=0.0f) {
  long double x=v[0], y=v[1], z=v[2];
  long double len=fsqrt_x87((x*x+y*y)+z*z);
  long double inv=1.0L/len;
  v[0]=(float)(x*inv); v[1]=(float)(y*inv); v[2]=(float)(z*inv);
 }
 float dot=(axis[0]*v[0]+axis[1]*v[1])+axis[2]*v[2];
 double angle=ext_634dbe((double)dot);
 return (double)limit > angle;
}
PCREG(5d6960,direction_angle);
