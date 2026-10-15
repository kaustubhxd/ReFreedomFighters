#include "ff.h"
static void fn4043a0(float* dst,float** table,float a,s32 position,s32 limit,s32 stride,float b){
 long double t=(long double)a+(long double)b;t=t*(long double)G(float,0x6be08c);
 s32 bucket=(s32)t;if(bucket<=0)bucket=0;if(bucket>=10)bucket=10;
 float* shape=table[bucket];s32 end=(s32)(long double)shape[1];
 long double x=(long double)shape[0]-(long double)G(float,0x6bdfd0);x=x*(long double)stride;x=x+(long double)position;x=x-(long double)(stride>>1);
 s32 index=(s32)x;s32 j=(s32)(long double)shape[0];
 for(;j<end;++j){
  if(index>0){long double value=(long double)a+(long double)shape[j+2];if(value>(long double)dst[index])dst[index]=(float)value;}
  index+=stride;if(index>=limit)break;
 }
}
PCREG(4043a0,fn4043a0);
