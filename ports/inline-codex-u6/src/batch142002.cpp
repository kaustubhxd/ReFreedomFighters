#include "ff.h"
static long double cosine(long double v){asm("fcos":"+t"(v));return v;}
static long double exponential(long double v){
 asm("fldl2e; fmulp; fld %%st(0); frndint; fxch %%st(1); fsub %%st(1),%%st; f2xm1; fld1; faddp; fscale; fstp %%st(1)":"+t"(v)::"st(1)");return v;
}
static void filter(float* out,int* indexes,int n,int denom,float* roots,int count,float amplitude,float offset){
 float step=(long double)G(float,0x6be0cc)/(long double)denom;
 for(int i=0;i<count;i++)roots[i]=(float)(cosine((long double)roots[i])*2.0L);
 int i=0;
 while(i<n){
  int index=indexes[i]; float w=(float)(cosine((long double)index*(long double)step)*2.0L);
  long double p=0.5L,q=0.5L; int j=1;
  if(count>1){
   int pairs=(u32)count>>1; j=pairs*2+1;
   for(int k=0;k<pairs;k++){
    p=p*((long double)w-(long double)roots[2*k]);
    q=q*((long double)w-(long double)roots[2*k+1]);
   }
  }
  float qstore=(float)q; long double denom2;
  if(j==count){
   p=p*((long double)w-(long double)roots[j-1]);
   qstore=(float)((4.0L-(long double)w*(long double)w)*(long double)qstore*(long double)qstore);
   denom2=p*p;
  }else{
   qstore=(float)((2.0L-(long double)w)*q*q);
   denom2=((long double)w+2.0L)*p*p;
  }
  long double val=(long double)amplitude/fsqrt_x87(denom2+(long double)qstore);
  float gain=(float)exponential((val-(long double)offset)*(long double)G(double,0x6be100));
  out[i]=(float)((long double)gain*(long double)out[i]); ++i;
  while(indexes[i]==index){out[i]=(float)((long double)gain*(long double)out[i]);++i;}
 }
}
PCREG(40fa80,filter);
