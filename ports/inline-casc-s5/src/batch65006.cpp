#include "ff.h"
extern "C" void FASTCALL ext_43e960(float *dst, float *src);
extern "C" void THISCALL ext_4e09b0(float *v);
extern "C" double VECTORCALL ext_634dbe(double);
typedef void (THISCALL *p1_65006)(void *,float *);
typedef void (THISCALL *p2_65006)(void *,float *,float *);
static long double THISCALL f45eb30(u8 *self, float *arg) {
  float A[3]; u8 *o=*(u8 **)(self+8);
  A[0]=*(float *)(o+0x30); A[1]=*(float *)(o+0x34); A[2]=*(float *)(o+0x38);
  (*(p1_65006 **)self)[0x84/4](self,A);
  float *B=arg;
  ext_43e960(B,A); B[1]=0.0f;
  if (B[0]!=0.0f || B[2]!=0.0f) {
    long double x=B[0],y=B[1],z=B[2]; long double sq=x*x; sq=sq+y*y; sq=sq+z*z;
    long double len=fsqrt_x87(sq); long double r=1.0L/len;
    B[0]=(float)((long double)B[0]*r); B[1]=(float)((long double)B[1]*r); B[2]=(float)(r*(long double)B[2]);
  }
  float P[9]; (*(p2_65006 **)self)[0x80/4](self,P,A);
  A[0]=P[0]; A[1]=P[1]; A[2]=P[2]; ext_4e09b0(A);
  float t0=P[6]*B[0]; float sgn=1.0f; float t1=P[7]*B[1]; t1=t1+t0; float t2=P[8]*B[2]; t1=t1+t2;
  float k1=G(float,0x67af2c); if(t1>0.0f) sgn=-1.0f;
  float d=B[1]*A[1]; float d3=B[0]*A[0]; float d4=B[2]*A[2]; d=d+d3; d=d+d4;
  float angle;
  if(d>G(float,0x678858)) angle=0.0f; else if(k1>d) angle=bitsf(0x40490fdb); else angle=(float)ext_634dbe((double)d);
  long double res=(long double)angle*(long double)G(float,0x685274); res=res*(long double)sgn; return res;
}
PCREG(45eb30,f45eb30);
