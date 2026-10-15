#include "ff.h"
extern "C" void FASTCALL ext_446ee0(void*,void*,void*);
static void normalize_basis(float* v){
 if(v[0]!=0.0f || v[1]!=0.0f || v[2]!=0.0f){
  long double x=v[0],y=v[1],z=v[2];
  long double magnitude=fsqrt_x87((x*x+y*y)+z*z);
  long double inv=1.0L/magnitude;
  v[0]=(float)(x*inv);v[1]=(float)(y*inv);v[2]=(float)(z*inv);
 }
}
extern "C" void THISCALL rebuild_basis(float* m){
 ext_446ee0(m,m+6,m+3);normalize_basis(m);
 ext_446ee0(m+6,m+3,m);normalize_basis(m+6);
 ext_446ee0(m+3,m,m+6);
}
PCREG(4e2aa0,rebuild_basis);
