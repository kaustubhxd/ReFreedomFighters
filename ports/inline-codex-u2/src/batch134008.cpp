#include "ff.h"
static s32 fn410000(const float* coef,s32 n,float* roots){
 double* work=(double*)__builtin_alloca((u32)n*8);
 for(s32 i=0;i<n;++i)work[i]=(double)roots[i];
 s32 iter=0;
 for(;;){
  long double sum=(long double)G(double,0x6be098);
  for(s32 i=0;i<n;++i){
   long double deriv=(long double)G(double,0x6be098),value=(long double)coef[n];
   long double x=(long double)work[i];
   for(s32 j=n-1;j>=0;--j){deriv=deriv*x+value;value=value*x+(long double)coef[j];}
   long double step=value/deriv;work[i]=(double)(x-step);sum=sum+step*step;
  }
  if(iter>40)return -1;
  ++iter;
  if(!(sum>(long double)G(double,0x6be130)))break;
 }
 for(s32 i=0;i<n;++i)roots[i]=(float)work[i];
 return 0;
}
PCREG(410000,fn410000);
